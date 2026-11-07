/* tu_372 0x2fbbe8-0x2ff270: medium; ~sce (config/tu_map.tsv) */
#define D_00793DC0 _hdr_D_00793DC0
#define D_00794A00 _hdr_D_00794A00
#define D_00794A40 _hdr_D_00794A40
#define D_00794A50 _hdr_D_00794A50
#define D_00794A54 _hdr_D_00794A54
#define D_00795080 _hdr_D_00795080
#define D_007950C0 _hdr_D_007950C0
#define D_00793D80 _hdr_D_00793D80
#define D_00793D84 _hdr_D_00793D84
#define D_00568DF8 _hdr_D_00568DF8
#define func_002FB4C8 _hdr_func_002FB4C8
#define func_002FABD8 _hdr_func_002FABD8
#define func_002FAC88 _hdr_func_002FAC88
#define func_002FB2F8 _hdr_func_002FB2F8
#define func_002EEF1C _hdr_func_002EEF1C
#define func_002FD578 _hdr_func_002FD578
#define func_002FBD40 _hdr_func_002FBD40
#define func_002FC768 _hdr_func_002FC768
#define func_002FD3A0 _hdr_func_002FD3A0
#define func_002FD740 _hdr_func_002FD740
#define func_002FD910 _hdr_func_002FD910
#define func_002FDB80 _hdr_func_002FDB80
#define func_002FDCC0 _hdr_func_002FDCC0
#define func_002FDD88 _hdr_func_002FDD88
#define func_002FDEF0 _hdr_func_002FDEF0
#define func_002FE048 _hdr_func_002FE048
#define func_002FE1E8 _hdr_func_002FE1E8
#define func_002FE428 _hdr_func_002FE428
#define func_002FE638 _hdr_func_002FE638
#define func_002FE7D0 _hdr_func_002FE7D0
#define func_002FEC98 _hdr_func_002FEC98
#define func_002FEEC8 _hdr_func_002FEEC8
#define func_002FF0A8 _hdr_func_002FF0A8
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/u5.h"
#include "ffx/v7.h"
#include "ffx/g4.h"
#undef D_00793DC0
#undef D_00794A00
#undef D_00794A40
#undef D_00794A50
#undef D_00794A54
#undef D_00795080
#undef D_007950C0
#undef D_00793D80
#undef D_00793D84
#undef D_00568DF8
#undef func_002FB4C8
#undef func_002FABD8
#undef func_002FAC88
#undef func_002FB2F8
#undef func_002EEF1C
#undef func_002FD578
#undef func_002FBD40
#undef func_002FC768
#undef func_002FD3A0
#undef func_002FD740
#undef func_002FD910
#undef func_002FDB80
#undef func_002FDCC0
#undef func_002FDD88
#undef func_002FDEF0
#undef func_002FE048
#undef func_002FE1E8
#undef func_002FE428
#undef func_002FE638
#undef func_002FE7D0
#undef func_002FEC98
#undef func_002FEEC8
#undef func_002FF0A8

#ifndef NULL
#define NULL ((void *)0)
#endif
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))

extern s32 D_00793DC0;
extern s32 D_00794A00;
extern s32 D_00794A40;
extern s32 D_00794A50;
extern s32 D_00794A54;
extern SifClientData D_00795080;
extern s32 D_007950C0;
extern void *D_00793D80;
extern s32 *D_00793D84;
extern s32 D_00568DF8[];
s32 func_002FB4C8(void *, s32, s32, void *, s32, void *, s32, void *, void *);
void func_002FABD8(void *, s32);
void func_002FAC88(s32);
s32 func_002FB2F8(void *, u32, s32);
void *func_002EEF1C(void *, const void *, s32);
int func_002FD578(int a, int b);
void func_002FBD40(void);

typedef struct {
    s32 sema;
    s32 *res;
    s32 size;
    char s1[0x400];
    char s2[0x400];
} Pkt2Str;

typedef struct {
    s32 sema;
    s32 *res;
    s32 size;
    char s1[0x400];
    u8 buf[0x400];
    s32 cmd;
    s32 arglen;
    void *outbuf;
    s32 buflen;
} PktDevctl;

typedef struct {
    s32 sema;
    s32 *res;
    s32 size;
    char s1[0x400];
    char s2[0x400];
    u8 buf[0x400];
    s32 flag;
    s32 len;
} PktMount;

typedef struct {
    u8 b[0x40];
} Blk64;

typedef struct {
    s32 sema;
    s32 *res;
    s32 size;
    s32 mask;
    Blk64 stat;
    u8 name[0x400];
} PktChstat;

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

void func_002FC220_(void *a, U5Callback *cb) __asm__("func_002FC220");
void func_002FC220_(void *a, U5Callback *cb)
{
    void (*fn)(void *) = (void (*)(void *))cb->func;
    if (fn) {
        fn(cb->arg);
    }
    SYNC();
    EI();
}

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

s32 func_002FC768(s32 fd) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16_2;
    s32 temp_2;
    U5FioSlot *temp_16;

    temp_16 = func_002FBCD0(fd);
    func_002FC150(1);
    if (D_00568E78 == 0) {
        func_002FC180();
        return -1;
    }
    if ((temp_16 == NULL) || (temp_16->busy == 0)) {
        func_002FC180();
        return -9;
    }
    M2C_FIELD(pkt, s32 *, 0xC) = temp_16->w0;
    sp10.maxCount = 1;
    M2C_FIELD(pkt, s32 *, 0x10) = temp_16 - D_00794E80;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_2 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 *, 0) = temp_2;
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 1, 0, &D_00793DC0, 0x14, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_2);
        func_002FC180();
        return -0xB;
    }
    temp_16->busy = 0;
    temp_16_2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_2 == 0) {
        func_002F83F0(temp_2);
        return -0xB;
    }
    func_002F8420(temp_2);
    func_002F83F0(temp_2);
    if (sp30 < 0) {
        return sp30;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FC8E8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FCB20);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FCD90);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FD050);

s32 func_002FD3A0(s32 fd, s32 arg1, void *arg2, u32 arg3, s32 arg4, u32 arg5) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_18_2;
    U5FioSlot *temp_18;

    temp_18 = func_002FBCD0(fd);
    func_002FC150(0x1A);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    if ((temp_18 == NULL) || (temp_18->busy == 0)) {
        func_002FC180();
        return -9;
    }
    if ((arg3 >= 0x401U) || (arg5 >= 0x401U)) {
        return -0x16;
    }
    if (arg2 == NULL) {
        M2C_FIELD(pkt, u32 *, 0x41C) = 0U;
    } else {
        func_002EEF1C((u8 *)pkt + 0x14, arg2, arg3);
    }
    M2C_FIELD(pkt, s32 *, 0xC) = temp_18->w0;
    M2C_FIELD(pkt, s32 *, 0x10) = arg1;
    M2C_FIELD(pkt, u32 *, 0x41C) = arg3;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_18_2 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, u32 *, 0x418) = arg5;
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    M2C_FIELD(pkt, s32 *, 0x414) = arg4;
    M2C_FIELD(pkt, s32 *, 0) = temp_18_2;
    func_002FABD8(&D_00793DC0, 0x420);
    if (func_002FB4C8(&D_00795080, 0x1A, 0, &D_00793DC0, 0x420, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_18_2);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_18_2);
        return -0xB;
    }
    func_002F8420(temp_18_2);
    func_002F83F0(temp_18_2);
    return sp30;
}

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

int func_002FD578(int a, int b) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_16;

    func_002FC150(b);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_16 = 0; var_16 < 0x400; var_16++) {
        if ((M2C_FIELD((u8 *)pkt + var_16, s8 *, 0xC) = ((s8 *)a)[var_16]) == 0) {
            break;
        }
    }
    if (var_16 == 0x400) {
        M2C_FIELD(pkt, s8 *, 0x40B) = 0;
        var_16 = 0x3FF;
    }
    sp10.initCount = 0;
    sp10.maxCount = 1;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 0) = temp_17;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, b, 0, &D_00793DC0, var_16 + 0xD, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

int func_002FD720(int a)
{
    return func_002FD578(a, 6);
}

s32 func_002FD740(s8 *arg0, s32 arg1) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_16;

    func_002FC150(7);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_16 = 0; var_16 < 0x400; var_16++) {
        if ((M2C_FIELD((u8 *)pkt + var_16, s8 *, 0x10) = arg0[var_16]) == 0) {
            break;
        }
    }
    if (var_16 == 0x400) {
        M2C_FIELD(pkt, s8 *, 0x40F) = 0;
        var_16 = 0x3FF;
    }
    M2C_FIELD(pkt, s32 *, 0xC) = arg1;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 0) = temp_17;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 7, 0, &D_00793DC0, var_16 + 0x11, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

int func_002FD8F0(int a)
{
    return func_002FD578(a, 8);
}

s32 func_002FD910(s8 *dev, s8 *a, u8 *b, s32 c) {
    PktMount *pkt = (PktMount *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_5;

    func_002FC150(0xE);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s1[var_5] = dev[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s1[0x3FF] = 0;
    }
    if (a == NULL) {
        pkt->s2[0] = 0;
    } else {
        for (var_5 = 0; var_5 < 0x400; var_5++) {
            if ((pkt->s2[var_5] = a[var_5]) == 0) {
                break;
            }
        }
        if (var_5 == 0x400) {
            pkt->s2[0x3FF] = 0;
        }
    }
    if (c > 0x400) {
        func_002FC180();
        return -7;
    }
    for (var_5 = 0; var_5 < c; var_5++) {
        pkt->buf[var_5] = b[var_5];
    }
    pkt->flag = c;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    pkt->sema = temp_17;
    pkt->res = &sp30;
    pkt->size = 4;
    func_002FABD8(&D_00793DC0, 0xC10);
    if (func_002FB4C8(&D_00795080, 0xE, 0, &D_00793DC0, 0xC10, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

s32 func_002FDB80(s32 arg0) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_2;

    func_002FC150(0xF);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    M2C_FIELD(pkt, s32 *, 0xC) = arg0;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_2 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 *, 0) = temp_2;
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 0xF, 0, &D_00793DC0, 0x10, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_2);
        func_002FC180();
        return -1;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_2);
        return -1;
    }
    func_002F8420(temp_2);
    func_002F83F0(temp_2);
    return sp30;
}

int func_002FDCA0(int a)
{
    return func_002FD578(a, 0x10);
}

s32 func_002FDCC0(s8 *path) {
    s32 var_17;
    U5FioSlot *temp_2;

    func_002FC150(9);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    func_002FC180();
    temp_2 = func_002FBC48();
    if (temp_2 == NULL) {
        return -0x13;
    }
    var_17 = func_002FD578((s32)path, 9);
    if (var_17 < 0) {
        func_002F8420(D_00568E80);
        temp_2->busy = 0;
        func_002F8400(D_00568E80);
        return var_17;
    }
    func_002F8420(D_00568E80);
    temp_2->w0 = var_17;
    var_17 = temp_2 - D_00794E80;
    func_002F8400(D_00568E80);
    return var_17;
}

s32 func_002FDD88(s32 fd) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16_2;
    s32 temp_2;
    U5FioSlot *temp_16;

    temp_16 = func_002FBCD0(fd);
    func_002FC150(0xA);
    if (D_00568E78 == 0) {
        func_002FC180();
        return -1;
    }
    if ((temp_16 == NULL) || (temp_16->busy == 0)) {
        func_002FC180();
        return -9;
    }
    M2C_FIELD(pkt, s32 *, 0xC) = temp_16->w0;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_2 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 *, 0) = temp_2;
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 0xA, 0, &D_00793DC0, 0x14, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_2);
        func_002FC180();
        return -0xB;
    }
    temp_16->busy = 0;
    temp_16_2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_2 == 0) {
        func_002F83F0(temp_2);
        return -0xB;
    }
    func_002F8420(temp_2);
    func_002F83F0(temp_2);
    if (sp30 < 0) {
        return sp30;
    }
    return 0;
}

s32 func_002FDEF0(s32 fd, void *ent) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16_2;
    s32 temp_2;
    U5FioSlot *temp_16;

    temp_16 = func_002FBCD0(fd);
    func_002FC150(0xB);
    if (D_00568E78 == 0) {
        func_002FC180();
        return -1;
    }
    if ((temp_16 == NULL) || (temp_16->busy == 0)) {
        func_002FC180();
        return -9;
    }
    M2C_FIELD(pkt, void **, 0x10) = ent;
    M2C_FIELD(pkt, s32 *, 0xC) = temp_16->w0;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_2 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 *, 0) = temp_2;
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 0xB, 0, &D_00793DC0, 0x20, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F8420(temp_2);
        func_002FC180();
        return -0xB;
    }
    temp_16_2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_2 == 0) {
        func_002F83F0(temp_2);
        return -0xB;
    }
    func_002F8420(temp_2);
    func_002F83F0(temp_2);
    return sp30;
}

s32 func_002FE048(u8 *a, void *buf) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_16;

    func_002FC150(0xC);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_16 = 0; var_16 < 0x400; var_16++) {
        if ((M2C_FIELD((u8 *)pkt + var_16, u8 *, 0x10) = a[var_16]) == 0) {
            break;
        }
    }
    if (var_16 == 0x400) {
        M2C_FIELD(pkt, s8 *, 0x40F) = 0;
        var_16 = 0x3FF;
    }
    M2C_FIELD(pkt, void **, 0xC) = buf;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 0) = temp_17;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 0xC, 0, &D_00793DC0, var_16 + 0x11, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

s32 func_002FE1E8(u8 *arg0, Blk64 *arg1, s32 arg2) {
    PktChstat *pkt = (PktChstat *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_18;
    s32 var_17;

    func_002FC150(0xD);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_17 = 0; var_17 < 0x400; var_17++) {
        if ((pkt->name[var_17] = arg0[var_17]) == 0) {
            break;
        }
    }
    if (var_17 == 0x400) {
        pkt->name[0x3FF] = 0;
        var_17 = 0x3FF;
    }
    pkt->stat = *arg1;
    pkt->mask = arg2;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_18 = func_002F83E0(&sp10);
    pkt->sema = temp_18;
    pkt->res = &sp30;
    pkt->size = 4;
    func_002FABD8(&D_00793DC0, 0x450);
    if (func_002FB4C8(&D_00795080, 0xD, 0, &D_00793DC0, var_17 + 0x51, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_18);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_18);
        return -0xB;
    }
    func_002F8420(temp_18);
    func_002F83F0(temp_18);
    return sp30;
}

s32 func_002FE428(s8 *arg0, s8 *arg1) {
    Pkt2Str *pkt = (Pkt2Str *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_5;

    func_002FC150(0x11);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s1[var_5] = arg0[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s1[0x3FF] = 0;
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s2[var_5] = arg1[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s2[0x3FF] = 0;
    }
    sp10.initCount = 0;
    sp10.maxCount = 1;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    pkt->sema = temp_17;
    pkt->res = &sp30;
    pkt->size = 4;
    func_002FABD8(&D_00793DC0, 0x80C);
    if (func_002FB4C8(&D_00795080, 0x11, 0, &D_00793DC0, 0x80C, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

int func_002FE618(int a)
{
    return func_002FD578(a, 0x12);
}

s32 func_002FE638(s8 *arg0, s32 arg1) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_5;

    func_002FC150(0x13);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((M2C_FIELD((u8 *)pkt + var_5, s8 *, 0x14) = arg0[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        M2C_FIELD(pkt, s8 *, 0x413) = 0;
    }
    M2C_FIELD(pkt, s32 *, 0x10) = arg1;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 0) = temp_17;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 0x13, 0, &D_00793DC0, 0x414, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

s32 func_002FE7D0(s8 *dev, s8 *path, s32 flag, u8 *arg, s32 len) {
    PktMount *pkt = (PktMount *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_5;

    func_002FC150(0x14);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s1[var_5] = dev[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s1[0x3FF] = 0;
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s2[var_5] = path[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s2[0x3FF] = 0;
    }
    if (len > 0x400) {
        func_002FC180();
        return -7;
    }
    for (var_5 = 0; var_5 < len; var_5++) {
        pkt->buf[var_5] = arg[var_5];
    }
    pkt->flag = flag;
    pkt->len = len;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    pkt->sema = temp_17;
    pkt->res = &sp30;
    pkt->size = 4;
    func_002FABD8(&D_00793DC0, 0xC14);
    if (func_002FB4C8(&D_00795080, 0x14, 0, &D_00793DC0, 0xC14, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

int func_002FEA40(int a)
{
    return func_002FD578(a, 0x15);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FBBE8", func_002FEA60);

s32 func_002FEC98(s8 *dev, s32 cmd, u8 *arg, s32 arglen, void *buf, s32 buflen) {
    PktDevctl *pkt = (PktDevctl *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_5;
    u32 var_5_2;

    func_002FC150(0x17);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s1[var_5] = dev[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s1[0x3FF] = 0;
    }
    if (((u32)arglen > 0x400U) || ((u32)buflen > 0x400U)) {
        return -0x16;
    }
    for (var_5_2 = 0; var_5_2 < (u32)arglen; var_5_2++) {
        pkt->buf[var_5_2] = arg[var_5_2];
    }
    pkt->cmd = cmd;
    pkt->arglen = arglen;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    pkt->sema = temp_17;
    pkt->res = &sp30;
    pkt->size = 4;
    pkt->outbuf = buf;
    pkt->buflen = buflen;
    func_002FABD8(&D_00793DC0, 0x81C);
    if (func_002FB4C8(&D_00795080, 0x17, 0, &D_00793DC0, 0x81C, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

s32 func_002FEEC8(s8 *arg0, s8 *arg1) {
    Pkt2Str *pkt = (Pkt2Str *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16;
    s32 temp_17;
    s32 var_5;

    func_002FC150(0x11);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s1[var_5] = arg0[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s1[0x3FF] = 0;
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((pkt->s2[var_5] = arg1[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        pkt->s2[0x3FF] = 0;
    }
    sp10.initCount = 0;
    sp10.maxCount = 1;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    pkt->res = &sp30;
    pkt->sema = temp_17;
    pkt->size = 4;
    if (func_002FB4C8(&D_00795080, 0x18, 0, &D_00793DC0, 0x80C, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}

s32 func_002FF0A8(s8 *arg0, void *arg1, u32 arg2) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16_2;
    s32 temp_17;
    s32 var_5;

    func_002FC150(0x11);
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    for (var_5 = 0; var_5 < 0x400; var_5++) {
        if ((M2C_FIELD((u8 *)pkt + var_5, s8 *, 0x14) = arg0[var_5]) == 0) {
            break;
        }
    }
    if (var_5 == 0x400) {
        M2C_FIELD(pkt, s8 *, 0x413) = 0;
    }
    if (arg2 >= 0x400U) {
        arg2 = 0x3FFU;
    }
    M2C_FIELD(pkt, void **, 0x10) = arg1;
    M2C_FIELD(pkt, u32 *, 0xC) = arg2;
    func_002FABD8(arg1, arg2);
    sp10.initCount = 0;
    sp10.maxCount = 1;
    sp10.option = 0;
    temp_17 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 0) = temp_17;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (func_002FB4C8(&D_00795080, 0x19, 0, &D_00793DC0, 0x80C, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_17);
        func_002FC180();
        return -0xB;
    }
    temp_16_2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_2 == 0) {
        func_002F83F0(temp_17);
        return -0xB;
    }
    func_002F8420(temp_17);
    func_002F83F0(temp_17);
    return sp30;
}
