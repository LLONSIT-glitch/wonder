#include "PR/os_internal.h"
#include "PRinternal/piint.h"

typedef struct {
    void* dramAddr;
    void* C2Addr;
    u32 sectorSize;
    u32 C1ErrNum;
    u32 C1ErrSector[4];
} Old_OSBlockInfo;

typedef struct {
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 devAddr;
    u32 errStatus;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    Old_OSBlockInfo block[2];
} Old_OSTranxInfo;

#define OLD_TRANSFER_INFO(handle) ((Old_OSTranxInfo*) ((u8*) (handle) + 0x14))

void __osDevMgrMain(void* args) {
    OSIoMesg* message_block;
    OSMesg event_mesg;
    OSMesg dummy_mesg;
    s32 result;
    OSDevMgr* device_manager;
    s32 send_result;
    s32 send_message;

    device_manager = (OSDevMgr*) args;
    send_result = 0;
    send_message = 0;
    message_block = NULL;
    result = 0;

    while (TRUE) {
        osRecvMesg(device_manager->cmdQueue, (OSMesg) &message_block, OS_MESG_BLOCK);

        if ((message_block->piHandle != NULL) && (message_block->piHandle->type == DEVICE_TYPE_64DD) &&
            ((OLD_TRANSFER_INFO(message_block->piHandle)->cmdType == LEO_CMD_TYPE_0) ||
             (OLD_TRANSFER_INFO(message_block->piHandle)->cmdType == LEO_CMD_TYPE_1))) {
            Old_OSBlockInfo* block_info;
            Old_OSTranxInfo* transfer_info;

            transfer_info = OLD_TRANSFER_INFO(message_block->piHandle);
            block_info = &transfer_info->block[transfer_info->blockNum];
            transfer_info->sectorNum = -1;

            if (transfer_info->transferMode != LEO_SECTOR_MODE) {
                block_info->dramAddr = (void*) ((u32) block_info->dramAddr - block_info->sectorSize);
            }

            if ((transfer_info->transferMode == LEO_TRACK_MODE) &&
                (OLD_TRANSFER_INFO(message_block->piHandle)->cmdType == LEO_CMD_TYPE_0)) {
                send_message = 1;
            } else {
                send_message = 0;
            }

            osRecvMesg(device_manager->acsQueue, &dummy_mesg, OS_MESG_BLOCK);
            __osResetGlobalIntMask(OS_IM_PI);
            __osEPiRawWriteIo(message_block->piHandle, LEO_BM_CTL, transfer_info->bmCtlShadow | 0x80000000);

        read_block:
            osRecvMesg(device_manager->evtQueue, &event_mesg, OS_MESG_BLOCK);
            send_result = osSendMesg(message_block->hdr.retQueue, message_block, OS_MESG_NOBLOCK);

            if ((send_message == 1) && (OLD_TRANSFER_INFO(message_block->piHandle)->errStatus == 0)) {
                send_message = 0;
                goto read_block;
            }

            osSendMesg(device_manager->acsQueue, NULL, OS_MESG_NOBLOCK);
            if (OLD_TRANSFER_INFO(message_block->piHandle)->blockNum == 1) {
                osYieldThread();
            }
        } else {
            switch (message_block->hdr.type) {
                case OS_MESG_TYPE_DMAREAD:
                    osRecvMesg(device_manager->acsQueue, &dummy_mesg, OS_MESG_BLOCK);
                    result = device_manager->dma(OS_READ, message_block->devAddr, message_block->dramAddr,
                                                 message_block->size);
                    break;

                case OS_MESG_TYPE_DMAWRITE:
                    osRecvMesg(device_manager->acsQueue, &dummy_mesg, OS_MESG_BLOCK);
                    result = device_manager->dma(OS_WRITE, message_block->devAddr, message_block->dramAddr,
                                                 message_block->size);
                    break;

                case OS_MESG_TYPE_EDMAREAD:
                    osRecvMesg(device_manager->acsQueue, &dummy_mesg, OS_MESG_BLOCK);
                    result = device_manager->edma(message_block->piHandle, OS_READ, message_block->devAddr,
                                                  message_block->dramAddr, message_block->size);
                    break;

                case OS_MESG_TYPE_EDMAWRITE:
                    osRecvMesg(device_manager->acsQueue, &dummy_mesg, OS_MESG_BLOCK);
                    result = device_manager->edma(message_block->piHandle, OS_WRITE, message_block->devAddr,
                                                  message_block->dramAddr, message_block->size);
                    break;

                case OS_MESG_TYPE_LOOPBACK:
                    osSendMesg(message_block->hdr.retQueue, message_block, OS_MESG_NOBLOCK);
                    result = -1;
                    break;

                default:
                    result = -1;
                    break;
            }

            if (result == 0) {
                osRecvMesg(device_manager->evtQueue, &event_mesg, OS_MESG_BLOCK);
                send_result = osSendMesg(message_block->hdr.retQueue, message_block, OS_MESG_NOBLOCK);
                osSendMesg(device_manager->acsQueue, NULL, OS_MESG_NOBLOCK);
            }
        }
    }
}
