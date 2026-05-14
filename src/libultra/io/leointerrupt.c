#include "common.h"
#include <PRinternal/osint.h>

#define LEO_BM_CTL (0x05000510)
#define LEO_STATUS (0x05000508)
#define LEO_BM_STATUS (0x05000510)
#define LEO_SECTOR_BUFF (0x05000400)
#define LEO_C2_BUFF (0x05000000)
#define LEO_BM_CTL_RESET 0x10000000
#define LEO_BM_CTL_CLR_MECHANIC_INTR 0x01000000
#define LEO_STATUS_DATA_REQUEST 0x40000000
#define LEO_STATUS_C2_TRANSFER 0x10000000
#define LEO_STATUS_BUFFER_MANAGER_ERROR 0x08000000
#define LEO_STATUS_MECHANIC_INTERRUPT 0x02000000
#define LEO_BM_STATUS_MICRO 0x02000000
#define LEO_BM_STATUS_C1DOUBLE 0x00400000
#define LEO_BM_STATUS_C1SINGLE 0x00200000
#define LEO_CMD_TYPE_0 0
#define LEO_CMD_TYPE_1 1
#define LEO_CMD_TYPE_2 2
#define LEO_TRACK_MODE 2
#define LEO_SECTOR_MODE 3

extern OSPiHandle* __osCurrentHandle;
extern u32 D_800ECC50;
extern s32 osEPiRawStartDma(OSPiHandle* handle, s32 direction, u32 device_address, void* dram_address, u32 size);

void __osLeoResume(void);
void __osLeoAbnormalResume(void);

typedef struct Old_Leo_Block_Info {
    void* dramAddr;
    void* C2Addr;
    u32 sectorSize;
    u32 C1ErrNum;
    u32 C1ErrSector[4];
} Old_Leo_Block_Info;

typedef struct Old_Leo_Transfer_Info {
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 unused;
    u32 errStatus;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    Old_Leo_Block_Info block[2];
} Old_Leo_Transfer_Info;

#define WAIT_ON_IO_BUSY(stat)              \
    {                                      \
        stat = IO_READ(PI_STATUS_REG);     \
        while (stat & PI_STATUS_IO_BUSY) { \
            stat = IO_READ(PI_STATUS_REG); \
        }                                  \
    }                                      \
    (void) 0

s32 __osLeoInterrupt(void) {
    u32 stat;
    volatile u32 pi_stat;
    u32 bm_stat;
    Old_Leo_Transfer_Info* info;
    Old_Leo_Block_Info* block_info;
    u32 err_num;
    Old_Leo_Block_Info* first_block_info;

    if (D_800ECC50 == 0) {
        return 0;
    }

    info = (Old_Leo_Transfer_Info*) ((u8*) __osCurrentHandle + 0x14);
    block_info = &info->block[info->blockNum];

    pi_stat = IO_READ(PI_STATUS_REG);
    if (pi_stat & PI_STATUS_DMA_BUSY) {
        IO_WRITE(PI_STATUS_REG, PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY);
        WAIT_ON_IO_BUSY(pi_stat);
        stat = IO_READ(LEO_STATUS);
        if (stat & LEO_STATUS_MECHANIC_INTERRUPT) {
            WAIT_ON_IO_BUSY(pi_stat);
            IO_WRITE(LEO_BM_CTL, info->bmCtlShadow | LEO_BM_CTL_CLR_MECHANIC_INTR);
        }
        info->errStatus = 0x4B;
        __osLeoAbnormalResume();
        return 1;
    }

    WAIT_ON_IO_BUSY(pi_stat);
    stat = IO_READ(LEO_STATUS);
    if (stat & LEO_STATUS_MECHANIC_INTERRUPT) {
        WAIT_ON_IO_BUSY(pi_stat);
        IO_WRITE(LEO_BM_CTL, info->bmCtlShadow | LEO_BM_CTL_CLR_MECHANIC_INTR);
        info->errStatus = 0;
        return 0;
    }

    if (stat & LEO_STATUS_BUFFER_MANAGER_ERROR) {
        info->errStatus = 3;
        __osLeoAbnormalResume();
        return 1;
    }

    if (info->cmdType == LEO_CMD_TYPE_1) {
        if (!(stat & LEO_STATUS_DATA_REQUEST)) {
            if (info->sectorNum + 1 != info->transferMode * 85) {
                info->errStatus = 6;
                __osLeoAbnormalResume();
                return 1;
            }

            IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
            __OSGlobalIntMask |= OS_IM_PI;
            info->errStatus = 0;
            __osLeoResume();
            return 1;
        } else {
            block_info->dramAddr = (void*) ((u32) block_info->dramAddr + block_info->sectorSize);
            info->sectorNum++;
            osEPiRawStartDma(__osCurrentHandle, OS_WRITE, LEO_SECTOR_BUFF, block_info->dramAddr,
                             block_info->sectorSize);
            return 1;
        }
    } else if (info->cmdType == LEO_CMD_TYPE_0) {
        if (info->transferMode == LEO_SECTOR_MODE) {
            if (info->sectorNum > (s32) (block_info->C1ErrNum + 17)) {
                info->errStatus = 0;
                __osLeoAbnormalResume();
                return 1;
            }

            if (!(stat & LEO_STATUS_DATA_REQUEST)) {
                info->errStatus = 0x11;
                __osLeoAbnormalResume();
                return 1;
            }
        } else {
            block_info->dramAddr = (void*) ((u32) block_info->dramAddr + block_info->sectorSize);
        }

        bm_stat = IO_READ(LEO_BM_STATUS);
        if (((bm_stat & LEO_BM_STATUS_C1SINGLE) && (bm_stat & LEO_BM_STATUS_C1DOUBLE)) ||
            (bm_stat & LEO_BM_STATUS_MICRO)) {
            if (block_info->C1ErrNum >= 4) {
                if ((info->transferMode != LEO_SECTOR_MODE) || (info->sectorNum >= 0x53)) {
                    info->errStatus = 0x11;
                    __osLeoAbnormalResume();
                    return 1;
                }
            } else {
                err_num = block_info->C1ErrNum;
                block_info->C1ErrSector[err_num] = info->sectorNum + 1;
            }

            block_info->C1ErrNum++;
        }

        if (stat & LEO_STATUS_C2_TRANSFER) {
            if (info->sectorNum + 1 != 88) {
                info->errStatus = 6;
                __osLeoAbnormalResume();
            }

            if ((info->transferMode == LEO_TRACK_MODE) && (info->blockNum == 0)) {
                info->blockNum = 1;
                info->sectorNum = -1;
                info->block[1].dramAddr = (void*) ((u32) info->block[1].dramAddr - info->block[1].sectorSize);
            } else {
                IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
                __OSGlobalIntMask |= OS_IM_PI;
            }

            osEPiRawStartDma(__osCurrentHandle, OS_READ, LEO_C2_BUFF, block_info->C2Addr, block_info->sectorSize * 4);
            info->errStatus = 0;
            return 1;
        }

        if ((info->sectorNum == -1) && (info->transferMode == LEO_TRACK_MODE) && (info->blockNum == 1)) {
            first_block_info = &info->block[0];

            if (first_block_info->C1ErrNum == 0) {
                if (((u32*) first_block_info->C2Addr)[0] | ((u32*) first_block_info->C2Addr)[1] |
                    ((u32*) first_block_info->C2Addr)[2] | ((u32*) first_block_info->C2Addr)[3]) {
                    info->errStatus = 6;
                    __osLeoAbnormalResume();
                    return 1;
                }
            }

            info->errStatus = 0;
            __osLeoResume();
        }

        info->sectorNum++;
        if (stat & LEO_STATUS_DATA_REQUEST) {
            if (info->sectorNum >= 0x55) {
                info->errStatus = 6;
                __osLeoAbnormalResume();
                return 1;
            }

            osEPiRawStartDma(__osCurrentHandle, OS_READ, LEO_SECTOR_BUFF, block_info->dramAddr, block_info->sectorSize);
            info->errStatus = 0;
            return 1;
        } else if (info->sectorNum < 0x55) {
            info->errStatus = 6;
            __osLeoAbnormalResume();
            return 1;
        }

        return 1;
    } else {
        info->errStatus = 0x4B;
        __osLeoAbnormalResume();
        return 1;
    }
}

void __osLeoAbnormalResume(void) {
    __OSTranxInfo* info;
    volatile u32 pi_stat;

    info = &__osCurrentHandle->transferInfo;

    WAIT_ON_IO_BUSY(pi_stat);
    IO_WRITE(LEO_BM_CTL, info->seqCtlShadow | LEO_BM_CTL_RESET);
    WAIT_ON_IO_BUSY(pi_stat);
    IO_WRITE(LEO_BM_CTL, info->seqCtlShadow);
    __osLeoResume();
    IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
    __OSGlobalIntMask |= OS_IM_PI;
}

void __osLeoResume(void) {
    __OSEventState* event_state;
    OSMesgQueue* message_queue;
    s32 last;

    event_state = &__osEventStateTab[OS_EVENT_PI];
    message_queue = event_state->messageQueue;

    if (message_queue == NULL || MQ_IS_FULL(message_queue)) {
        return;
    }

    last = (message_queue->first + message_queue->validCount) % message_queue->msgCount;
    message_queue->msg[last] = event_state->message;
    message_queue->validCount++;

    if (message_queue->mtqueue->next != NULL) {
        __osEnqueueThread(&__osRunQueue, __osPopThread(&message_queue->mtqueue));
    }
}
