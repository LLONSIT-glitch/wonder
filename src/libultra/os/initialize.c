#include <PR/os_internal.h>
#include <PR/rcp.h>

#define LEO_STATUS 0x05000508
#define LEO_STATUS_PRESENCE_MASK 0xFFFF

typedef struct {
    u32 inst1;
    u32 inst2;
    u32 inst3;
    u32 inst4;
} __osExceptionVector;

typedef struct {
    u32 value;
    u8 padding[12];
} Initialize_Bss;

extern __osExceptionVector __osExceptionPreamble[];
extern s32 __osLeoInterrupt(void);
extern s32 osPiRawReadIo(u32 dev_addr, u32* data);
extern u32 D_8000030C;
extern u8 D_8000031C[];

u64 osClockRate = OS_CLOCK_RATE;
u32 D_800ECC48 = 0;
u32 __OSGlobalIntMask = OS_IM_ALL;
u32 D_800ECC50 = 0;
u32 D_800ECC54[3] = { 0 };

Initialize_Bss __osFinalrom;

void osInitialize(void) {
    u32 pif_data;
    u32 clock = 0;
    u32 leo_status;
    u32 pi_status;

    __osFinalrom.value = 1;

    __osSetSR(__osGetSR() | SR_CU1);
    __osSetFpcCsr(FPCSR_FS | FPCSR_EV | FPCSR_RM_RN);

    while (__osSiRawReadIo(PIF_RAM_END - 3, &pif_data)) {}

    while (__osSiRawWriteIo(PIF_RAM_END - 3, pif_data | 8)) {}

    *(__osExceptionVector*) UT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector*) XUT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector*) ECC_VEC = *__osExceptionPreamble;
    *(__osExceptionVector*) E_VEC = *__osExceptionPreamble;

    osWritebackDCache((void*) UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osInvalICache((void*) UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));

    osMapTLBRdb();
    osPiRawReadIo(4, &clock);
    clock &= ~0xF;
    if (clock != 0) {
        osClockRate = clock;
    }

    osClockRate = osClockRate * 3 / 4;

    if (D_8000030C == 0) {
        bzero(D_8000031C, OS_APP_NMI_BUFSIZE);
    }

    pi_status = IO_READ(PI_STATUS_REG);
    while (pi_status & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {
        pi_status = IO_READ(PI_STATUS_REG);
    }

    leo_status = IO_READ(LEO_STATUS);
    if ((leo_status & LEO_STATUS_PRESENCE_MASK) == 0) {
        D_800ECC50 = 1;
        __osSetHWIntrRoutine(1, __osLeoInterrupt);
    } else {
        D_800ECC50 = 0;
    }
}
