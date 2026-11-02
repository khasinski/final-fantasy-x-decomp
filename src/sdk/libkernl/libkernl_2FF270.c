/* tu_373 0x2ff270-0x2fffd0: medium; unk_2FF270 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"
#include "ffx/g4.h"
#include "ffx/r7.h"
#include "ffx/u5.h"

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FF270", func_002FF270);

int func_002FF370(void)
{
    u8 *p = D_0056862C;
    int ret = 0;

    if (func_002EEE88(&D_795368, p, 4) != 0) {
        if (func_002EEE88(&D_795368, D_00568E90, 4) != 0) {
            ret = func_002EEE88(p, D_00568E90, 4) != 0;
        }
    }
    return ret;
}

int func_002FF400(void)
{
    D_00568E8C = -1;
    func_002EF0D0(&D_795368, 0, 4);
    return 0;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FF270", func_002FF438);

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FF270", func_002FF640);

int func_002FF848(int id)
{
    if (func_002FF270() < 0) {
        return -0x10000;
    }
    if (func_002FF370() != 0) {
        return -0x10004;
    }
    D_00795140.r.i = id;
    if (func_002FB4C8(&D_795340, 8, 0, &D_00795140, 4, &D_00795140, 4, 0, 0) < 0) {
        return -0x10001;
    }
    return D_00795140.r.i;
}

int func_002FF8D8(const char *path)
{
    if (func_002FF270() < 0) {
        return -0x10000;
    }
    if (func_002FF370() != 0) {
        return -0x10004;
    }
    func_002F0C10(D_00795140.u.path, path, 0xFC);
    D_00795140.u.path[0xFB] = 0;
    if (func_002FB4C8(&D_795340, 9, 0, &D_00795140, 0x200, &D_00795140, 4, 0, 0) < 0) {
        return -0x10001;
    }
    return D_00795140.r.i;
}

int func_002FF978(int id)
{
    if (func_002FF270() < 0) {
        return -0x10000;
    }
    if (func_002FF370() != 0) {
        return -0x10004;
    }
    D_00795140.r.i = id;
    if (func_002FB4C8(&D_795340, 0xA, 0, &D_00795140, 4, &D_00795140, 4, 0, 0) < 0) {
        return -0x10001;
    }
    return D_00795140.r.i;
}

int func_002FFA08(int a, int b, int c)
{
    int out;

    return func_002FF438(a, b, c, &out);
}

int func_002FFA28(int a, int b, int c, int *d)
{
    return func_002FF438(a, b, c, d);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FF270", func_002FFA48);

int func_002FFC70(int a, int b, int c)
{
    int out;

    return func_002FFA48(a, b, c, &out, 0);
}

int func_002FFC90(int a, int b, int c, int *d)
{
    return func_002FFA48(a, b, c, d, 0);
}

int func_002FFCB0(const char *path, const char *arg, int result, int rpc)
{
    int *res = (int *)result; /* DEBT(TYPE): shared prototype passes the result pointer as int */

    if (func_002FF270() < 0) {
        return -0x10000;
    }
    if (func_002FF370() != 0) {
        return -0x10004;
    }
    func_002F0C10(D_00795140.u.path, path, 0xFC);
    D_00795140.u.path[0xFB] = 0;
    func_002F0C10(D_00795140.arg, arg, 0xFC);
    D_00795140.arg[0xFB] = 0;
    if (func_002FB4C8(&D_795340, rpc, 0, &D_00795140, 0x200, &D_00795140, 0x10, 0, 0) < 0) {
        return -0x10001;
    }
    if (D_00795140.r.i == 0) {
        return -0x10003;
    }
    res[0] = D_00795140.r.i;
    res[1] = D_00795140.w4;
    return 0;
}

int func_002FFDB8(const char *a, const char *b, int c)
{
    return func_002FFCB0(a, b, c, 1);
}

int func_002FFDD8(const char *a, int c)
{
    return func_002FFCB0(a, D_00578D68, c, 1);
}

int func_002FFE00(int addr, void *out, u32 type)
{
    if (func_002FF270() < 0) {
        return -0x10000;
    }
    if (type >= 3) {
        return -0x10002;
    }
    D_00795140.r.i = addr;
    D_00795140.w4 = type;
    if (func_002FB4C8(&D_795340, 3, 0, &D_00795140, 0x20, &D_00795140, 0x20, 0, 0) < 0) {
        return -0x10001;
    }
    if (type == 0) {
        *(u8 *)out = D_00795140.r.b;
    } else if (type == 1) {
        *(u16 *)out = D_00795140.r.h;
    } else if (type == 2) {
        *(u32 *)out = D_00795140.r.i;
    } else {
        return -0x10002;
    }
    return 0;
}

int func_002FFEF0(int addr, void *data, int type)
{
    if (func_002FF270() < 0) {
        return -0x10000;
    }
    D_00795140.r.i = addr;
    D_00795140.w4 = type;
    if (type == 0) {
        D_00795140.u.b = *(u8 *)data;
    } else if (type == 1) {
        D_00795140.u.h = *(u16 *)data;
    } else if (type == 2) {
        D_00795140.u.w = *(u32 *)data;
    } else {
        return -0x10002;
    }
    if (func_002FB4C8(&D_795340, 2, 0, &D_00795140, 0x20, &D_00795140, 0x10, 0, 0) < 0) {
        return -0x10001;
    }
    return 0;
}
