/* tu_354 0x2e06d0-0x2e2220: medium; libcdvd (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"

void func_002E06D0(u16 ms)
{
    SemaParam sema;
    int id;

    sema.maxCount = 1;
    sema.initCount = 0;
    sema.option = 0;
    id = func_002F83E0(&sema);
    func_002F8160(ms, func_002E06A8, id);
    func_002F8420(id);
    func_002F83F0(id);
}

int func_002E0738(int cb)
{
    int old;

    if (func_002E11A0(1) != 0) {
        return 0;
    }
    func_00300280();
    old = D_0078D600;
    D_0078D600 = cb;
    func_003002C8();
    return old;
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E0790);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E0830);

int func_002E08F0(int prio, void *stack, int size)
{
    int ret = 1;

    if (D_005663D4 == 0) {
        D_0078D610 = func_002F82D0();
        func_002F82E0(D_0078D610, &D_0078D618);
        D_0078D648.stackSize = size;
        D_0078D648.gpReg = D_00584670;
        D_0078D648.entry = func_002E0830;
        D_0078D648.stack = stack;
        D_0078D648.initPriority = prio;
        D_005663D4 = func_002F81E0(&D_0078D648);
        func_002F8200(D_005663D4, 0);
    } else {
        func_002F8270(D_005663D4, prio);
        ret = 0;
    }
    return ret;
}

void func_002E09C8(void *data)
{
    McReadEnd *u = UNCACHED(data);
    u8 *dst;
    int i;

    if (u->size1 > 0) {
        dst = u->dest1;
        for (i = 0; i < u->size1; i++) {
            dst[i] = u->buf1[i];
        }
    }
    if (u->size2 > 0) {
        dst = u->dest2;
        for (i = 0; i < u->size2; i++) {
            dst[i] = u->buf2[i];
        }
    }
    func_002E0790(&D_00566414);
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E0A68);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E0B00);

void *func_002E0B80(void (*func)(int), int arg)
{
    void (*old)(int);

    if (D_005663FC < 0) {
        func_002E0C30();
    }
    func_00300280();
    old = D_0078D604;
    D_0078D608 = arg;
    D_0078D604 = func;
    func_003002C8();
    return old;
}

void func_002E0BF0(void)
{
    if (D_0078D604 != 0 && D_005663E4 == 0) {
        D_0078D604(D_0078D608);
    }
}

s32 func_002E0C30(void)
{
    D_005663E4 = 1;
    func_00300280();
    func_002FA8A0(0x80000012U, func_002E0BF0, 0);
    CALL_func_003002C8_INT();
    D_005663E4 = 0;
    D_005663FC = 1;
    return 1;
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E0C98);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E0F98);

int func_002E1108(void)
{
    int ret;

    if (func_002E0F98(2) == 0) {
        return 0;
    }
    if (func_002FB4C8(D_00567590, 0xE, 0, 0, 0, &D_00566440, 4, 0, 0) < 0) {
        func_002F8400(D_005663E8);
        return 0;
    }
    ret = *(int *)UNCACHED(&D_00566440);
    func_002F8400(D_005663E8);
    return ret;
}

int func_002E11A0(int mode)
{
    if (mode == 0) {
        if (D_005663D0 > 0) {
            func_002FA4E0(D_00576CA0);
        }
        while (D_005663F0 != 0 || func_002FB6B8(D_00567590) != 0) {
            func_002E06D0(0x3C);
        }
        return 0;
    }
    if (D_005663F0 != 0 || func_002FB6B8(D_00567590) != 0) {
        return 1;
    }
    return 0;
}

int func_002E1240(int mode)
{
    if (mode == 0) {
        if (D_005663D0 > 0) {
            func_002FA4E0(D_00576CB0);
        }
        while (func_002FB6B8(D_00567E08) != 0) {
            func_002E06D0(0x3C);
        }
        return 0;
    }
    return func_002FB6B8(D_00567E08);
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E12B0);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E1420);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E1700);

int func_002E18F8(int a)
{
    int *buf = &D_00567A00;
    int *recv;
    int r;

    if (func_002E12B0(0x22) == 0) {
        return 0;
    }
    *buf = a;
    func_002FABD8(buf, 4);
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 0x22, 0, buf, 4, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E19C0);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E1BA0);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E1C70);

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E1D20);

int func_002E1DD0(void)
{
    int *recv;
    int r;

    if (func_002E12B0(1) == 0) {
        return 0;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 3, 0, 0, 0, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

int func_002E1E68(void)
{
    int *recv;
    int r;

    if (func_002E12B0(3) == 0) {
        return -1;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 4, 0, 0, 0, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return -1;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

int func_002E1F00(void)
{
    int *recv;
    int r;

    if (func_002E12B0(2) == 0) {
        return -1;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 0xC, 0, 0, 0, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return -1;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    if (D_005663D0 >= 2) {
        func_002FA4E0(D_00576DA0);
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E1FB8);

int func_002E2070(int *out)
{
    int *recv;
    int r;

    if (func_002E12B0(0x21) == 0) {
        return 0;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 0x21, 0, 0, 0, recv, 8, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    *out = *(int *)UNCACHED(recv + 1);
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

int func_002E2128(R7Pair *out)
{
    int *recv;
    int r;

    if (func_002E12B0(0xF) == 0) {
        return 0;
    }
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576DB0);
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 1, 0, 0, 0, recv, 0x10, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    *out = *(R7Pair *)UNCACHED(recv + 1);
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576DD0);
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}
