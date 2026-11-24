/* tu_355 0x2e2220-0x2e4250: medium; unk_2E2220 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"

void func_002E2220(u32 chcr)
{
    func_00300280();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D8_CHCR = chcr;
    DMAC_ENABLEW = DMAC_ENABLER & 0xFFFEFFFF;
    func_003002C8();
}

void func_002E2288(u32 chcr)
{
    func_00300280();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D9_CHCR = chcr;
    DMAC_ENABLEW = DMAC_ENABLER & 0xFFFEFFFF;
    func_003002C8();
}

typedef struct {
    u32 d9_madr;
    u32 d9_tadr;
    u32 d9_qwc;
    u32 d9_chcr;
    u32 d8_madr;
    u32 d8_qwc;
    u32 d8_chcr;
    u32 bp;
    u32 ctrl;
} IpuDmaEnv;

void func_002E22F0(IpuDmaEnv *env)
{
    func_002E2288(1);
    env->d9_madr = *(volatile u32 *)0x1000B410;
    env->d9_tadr = *(volatile u32 *)0x1000B430;
    env->d9_qwc = *(volatile u32 *)0x1000B420;
    env->d9_chcr = *(volatile u32 *)0x1000B400;
    while ((*(volatile u32 *)0x10002010 & 0xF0) != 0) {
    }
    func_002E2220(0);
    env->d8_madr = *(volatile u32 *)0x1000B010;
    env->d8_qwc = *(volatile u32 *)0x1000B020;
    env->d8_chcr = *(volatile u32 *)0x1000B000;
    env->bp = *(volatile u32 *)0x10002020;
    env->ctrl = *(volatile u32 *)0x10002010;
}

void func_002E23D8(IpuDmaEnv *env)
{
    u32 bp = env->bp;
    u32 ifc = (bp >> 8) & 0xF;
    u32 fp = (bp >> 16) & 3;
    u32 fp_ifc = fp + ifc;
    u32 madr = env->d9_madr - (fp_ifc << 4);
    u32 qwc = env->d9_qwc + fp_ifc;
    u32 bit = bp & 0x7F;

    if (env->d8_madr != 0 && env->d8_qwc != 0) {
        *(volatile u32 *)0x1000B010 = env->d8_madr;
        *(volatile u32 *)0x1000B020 = env->d8_qwc;
        func_002E2220(env->d8_chcr | 0x100);
    }
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002000 = bit;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    if (madr != 0 && qwc != 0) {
        *(volatile u32 *)0x1000B410 = madr;
        *(volatile u32 *)0x1000B430 = env->d9_tadr;
        *(volatile u32 *)0x1000B420 = qwc;
        func_002E2288(env->d9_chcr | 0x100);
    }
}

u32 func_002E2528(int mode)
{
    u32 ret = 0;

    switch (mode) {
    case 0:
        while (*(volatile s32 *)0x10002010 < 0) {
        }
        ret = 0;
        break;
    case 1:
        ret = *(volatile u32 *)0x10002010 >> 31;
        break;
    default:
        break;
    }
    return ret;
}

void func_002E2590(u32 chcr)
{
    func_00300280();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D9_CHCR = chcr;
    DMAC_ENABLEW = DMAC_ENABLER & 0xFFFEFFFF;
    func_003002C8();
}

extern volatile u_long128 D_00567E40[];
extern u_long128 D_00567E90[];

void func_002E25F8(void)
{
    func_002E2590(1);
    *(volatile u32 *)0x10002010 = 0x40000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002000 = 0;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u_long128 *)0x10007010 = D_00567E40[0];
    *(volatile u_long128 *)0x10007010 = D_00567E40[1];
    *(volatile u_long128 *)0x10007010 = D_00567E40[2];
    *(volatile u_long128 *)0x10007010 = D_00567E40[3];
    *(volatile u_long128 *)0x10007010 = D_00567E40[4];
    *(volatile u_long128 *)0x10007010 = D_00567E40[4];
    *(volatile u_long128 *)0x10007010 = D_00567E40[4];
    *(volatile u_long128 *)0x10007010 = D_00567E40[4];
    *(volatile u32 *)0x10002000 = 0x50000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002000 = 0x58000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u_long128 *)0x10007010 = D_00567E90[0];
    *(volatile u_long128 *)0x10007010 = D_00567E90[1];
    *(volatile u32 *)0x10002000 = 0x60000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002000 = 0x90000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002010 = 0x40000000;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002000 = 0;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
}
