/* tu_372 0x2fbbe8-0x2ff270: medium; ~sce (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/u5.h"
#include "ffx/v7.h"
#include "ffx/g4.h"

void func_002FBBE8(void)
{
    SemaParam sema;

    if (D_00568E80 == -1) {
        sema.initCount = 1;
        sema.maxCount = 1;
        sema.option = 0;
        D_00568E80 = func_002F83E0(&sema);
        D_00568E84 = func_002F83E0(&sema);
    }
}

U5FioSlot *func_002FBC48(void)
{
    U5FioSlot *p;

    func_002FBBE8();
    func_002F8420(D_00568E80);
    for (p = D_00794E80; p < D_00794E80 + 32; p++) {
        if (p->busy == 0) {
            p->busy = 0x10000000;
            func_002F8400(D_00568E80);
            return p;
        }
    }
    func_002F8400(D_00568E80);
    return 0;
}

U5FioSlot *func_002FBCD0(u32 i)
{
    U5FioSlot *p;

    func_002FBBE8();
    func_002F8420(D_00568E80);
    if (i >= 32) {
        func_002F8400(D_00568E80);
        return 0;
    }
    p = &D_00794E80[i];
    func_002F8400(D_00568E80);
    return p;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FBD40);
INCLUDE_RODATA("build/ee_asm/sdk/libkernl/libkernl_2FBBE8/rodata", jtbl_00578CF0);

void func_002FC100(void)
{
    SemaParam sema;

    if (D_00568E7C == -1) {
        sema.initCount = 1;
        sema.maxCount = 1;
        sema.option = 0;
        D_00568E7C = func_002F83E0(&sema);
    }
}

int func_002FC150(int id)
{
    func_002FC100();
    func_002F8420(D_00568E7C);
    return 0;
}

void func_002FC180(void)
{
    func_002F8400(D_00568E7C);
}

void *func_002FC190(void *func, void *arg)
{
    U5Callback *cb = &D_00795100;
    void *old;

    func_002FC150(0x1B);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    func_00300280();
    old = cb->func;
    cb->arg = arg;
    cb->func = func;
    func_003002C8();
    func_002FC180();
    return old;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FC220);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FC250);

int func_002FC418(void)
{
    u8 *ver = D_0056862C;
    u8 *cur = D_007950A8;
    int ret = 0;

    if (func_002EEE88(cur, ver, 4) != 0 && func_002EEE88(cur, D_00568E88, 4) != 0) {
        ret = func_002EEE88(ver, D_00568E88, 4) != 0;
    }
    return ret;
}

int func_002FC4A8(void)
{
    D_00568E78 = 0;
    func_002EF0D0(D_007950A8, 0, 4);
    return 0;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FC4E0);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FC768);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FC8E8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FCB20);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FCD90);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FD050);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FD3A0);

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FD578);

int func_002FD720(int a)
{
    return func_002FD578(a, 6);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FD740);

int func_002FD8F0(int a)
{
    return func_002FD578(a, 8);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FD910);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FDB80);

int func_002FDCA0(int a)
{
    return func_002FD578(a, 0x10);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FDCC0);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FDD88);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FDEF0);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FE048);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FE1E8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FE428);

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

int func_002FE618(int a)
{
    return func_002FD578(a, 0x12);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FE638);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FE7D0);

int func_002FEA40(int a)
{
    return func_002FD578(a, 0x15);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FEA60);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FEC98);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FEEC8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FF0A8);
