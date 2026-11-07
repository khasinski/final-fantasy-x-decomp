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
#define func_002FC8E8 _hdr_func_002FC8E8
#define func_002FCB20 _hdr_func_002FCB20
#define func_002FCD90 _hdr_func_002FCD90
#define func_002FD050 _hdr_func_002FD050
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
#define func_002FEA60 _hdr_func_002FEA60
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
#undef func_002FC8E8
#undef func_002FCB20
#undef func_002FCD90
#undef func_002FD050
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
#undef func_002FEA60
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

typedef struct {
    s32 sema;
    s32 cmd;
    void *res;
    s32 size;
} IntrHdr;

typedef struct {
    s32 len1;
    s32 len2;
    u8 *dst1;
    u8 *dst2;
    u8 buf1[0x40];
    u8 buf2[0x40];
} IntrRead;

void func_002FBD40(void) {
    IntrHdr *p = (IntrHdr *)&D_00794A40;
    IntrHdr hdr;
    void *dst;
    u32 len;
    s32 i;
    u8 *p1;
    s32 sema;

    __builtin_memcpy(&hdr.sema, (void *)((s32)&p->sema | 0x20000000), 4);
    __builtin_memcpy(&hdr.cmd, (void *)((s32)&p->cmd | 0x20000000), 4);
    __builtin_memcpy(&hdr.res, (void *)((s32)&p->res | 0x20000000), 4);
    __builtin_memcpy(&hdr.size, (void *)((s32)&p->size | 0x20000000), 4);
    if (hdr.sema >= 0) {
        func_002EEF1C(hdr.res, (void *)((s32)(p + 1) | 0x20000000), hdr.size);
    }
    switch (hdr.cmd) {
    case 2: {
        IntrRead *rd = (IntrRead *)((s32)&D_00794A54 | 0x20000000);
        if (rd->len1 > 0) {
            p1 = rd->dst1;
            for (i = 0; i < rd->len1; i++) {
                p1[i] = rd->buf1[i];
            }
        }
        if (rd->len2 > 0) {
            p1 = rd->dst2;
            for (i = 0; i < rd->len2; i++) {
                p1[i] = rd->buf2[i];
            }
        }
        break;
    }
    case 11: {
        u32 *d = (u32 *)&D_00794A54;
        __builtin_memcpy(&dst, (void *)((s32)&d[0] | 0x20000000), 4);
        __builtin_memcpy(dst, (void *)((s32)&d[1] | 0x20000000), 0x144);
        break;
    }
    case 12: {
        u32 *d = (u32 *)&D_00794A54;
        __builtin_memcpy(&dst, (void *)((s32)&d[0] | 0x20000000), 4);
        __builtin_memcpy(dst, (void *)((s32)&d[1] | 0x20000000), 0x40);
        break;
    }
    case 23:
    case 25:
    case 26: {
        u32 *d = (u32 *)&D_00794A54;
        __builtin_memcpy(&dst, (void *)((s32)&d[0] | 0x20000000), 4);
        __builtin_memcpy(&len, (void *)((s32)&d[1] | 0x20000000), 4);
        if (len > 0x400) {
            len = 0x400;
        }
        func_002EEF1C(dst, (void *)((s32)&d[2] | 0x20000000), len);
        break;
    }
    }
    if (hdr.sema < 0) {
        hdr.sema = -hdr.sema;
        sema = hdr.sema;
        for (i = 0; i < 0x20; i++) {
            if (D_00568DF8[i] == sema) {
                D_00568DF8[i] = -1;
                __asm__("");
                break;
            }
            __asm__("" : "+r"(sema));
        }
    } else {
        func_002F8410(hdr.sema);
    }
}

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

int func_002FC250(void) {
    U5Callback *cb = &D_00795100;
    U5FioSlot *p;
    int i;

    func_002FAC88(0);
    cb->func = NULL;
    __asm__("" : "+r"(cb));
    cb->arg = NULL;
    func_00300280();
    func_002FA8A0(0x80000011, func_002FBD40, &D_007950C0);
    func_002FA8A0(0x80000013, func_002FC220_, cb);
    func_003002C8();
    while (1) {
        if (func_002FB2F8(&D_00795080, 0x80000001, 0) < 0) {
            return -1;
        }
        if (D_00795080.serve != 0) {
            break;
        }
        i = 0x100000;
        while (i-- != 0)
            ;
    }
    func_002FBBE8();
    func_002F8420(D_00568E80);
    for (p = D_00794E80; p < &D_00794E80[0x20]; p++) {
        p->busy = 0;
    }
    ((s32 (*)(s32))func_002F8400)(D_00568E80);
    D_00793D80 = &D_00794A40;
    if (func_002FB4C8(&D_00795080, 0xFF, 0, &D_00793D80, 4, &D_00794A00, 4, NULL, NULL) < 0) {
        return -0x10001;
    }
    __builtin_memcpy(D_007950A8, (void *)((s32)&D_00794A00 | 0x20000000), 4);
    D_00568E78 = 1;
    return 0;
}

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

typedef struct {
    s32 sema;
    s32 *res;
    s32 size;
    s32 flags;
    s32 mode;
    char name[0x400];
    s32 slot;
} PktOpen;

s32 func_002FC4E0(const char *name, s32 flags, ...) {
    PktOpen *pkt = (PktOpen *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    U5FioSlot *slot;
    s32 i;
    s32 mode;
    s32 idx;
    s32 sema;
    s32 res2;
    s32 *ap;

    func_002FC150(0);
    if (D_00568E78 == 0) {
        __asm__("" :: "r"(name));
        func_002FC250();
    }
    if (func_002FC418() != 0) {
        func_002FC180();
        return -0x10004;
    }
    slot = func_002FBC48();
    if (slot == NULL) {
        func_002FC180();
        return -0x13;
    }
    R7_VA_START(ap, flags, 6);
    mode = *ap;
    for (i = 0; i < 0x400; i++) {
        if ((pkt->name[i] = name[i]) == 0) {
            break;
        }
    }
    if (i == 0x400) {
        pkt->name[0x3FF] = 0;
    }
    idx = slot - D_00794E80;
    pkt->flags = flags & 0x6FFFFFFF;
    pkt->mode = mode;
    pkt->slot = idx;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    sema = func_002F83E0(&sp10);
    pkt->sema = sema;
    pkt->res = &sp30;
    pkt->size = 4;
    if (func_002FB4C8(&D_00795080, 0, 0, &D_00793DC0, 0x418, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(sema);
        func_002FC180();
        return -0xB;
    }
    res2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (res2 == 0) {
        func_002F83F0(sema);
        return -0xB;
    }
    func_002F8420(sema);
    ((s32 (*)(s32))func_002F83F0)(sema);
    if (sp30 < 0) {
        func_002F8420(D_00568E80);
        slot->busy = 0;
        func_002F8400(D_00568E80);
        return sp30;
    }
    res2 = idx;
    func_002F8420(D_00568E80);
    slot->w0 = sp30;
    slot->busy |= flags;
    func_002F8400(D_00568E80);
    return res2;
}

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

s32 func_002FC8E8(s32 fd, s32 b, s32 c) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16_2;
    s32 temp_18;
    s32 temp_19;
    s32 var_6;
    U5FioSlot *temp_16;

    temp_16 = func_002FBCD0(fd);
    func_002FC150(4);
    if (D_00568E78 == 0) {
        func_002FC180();
        return -1;
    }
    if ((temp_16 == NULL) || ((temp_19 = temp_16->busy) == 0)) {
        func_002FC180();
        return -9;
    }
    M2C_FIELD(pkt, s32 *, 0xC) = temp_16->w0;
    M2C_FIELD(pkt, s32 *, 0x10) = b;
    M2C_FIELD(pkt, s32 *, 0x14) = c;
    M2C_FIELD(pkt, s32 *, 0x18) = temp_16 - D_00794E80;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_18 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 *, 0) = temp_18;
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (temp_19 & 0x8000) {
        func_002F8420(D_00568E84);
        var_6 = 0;
        __asm__ volatile("" :: "r"(var_6), "m"(D_00568DF8[0]));
        for (; var_6 < 0x20; var_6++) {
            if (D_00568DF8[var_6] == -1) {
                D_00568DF8[var_6] = M2C_FIELD(pkt, s32 *, 0);
                M2C_FIELD(pkt, s32 *, 0) = -M2C_FIELD(pkt, s32 *, 0);
                break;
            }
        }
        func_002F8400(D_00568E84);
    }
    if (func_002FB4C8(&D_00795080, 4, 0, &D_00793DC0, 0x1C, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_18);
        func_002FC180();
        return -0xB;
    }
    __asm__("" : "+r"(temp_19));
    temp_16_2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_2 == 0) {
        func_002F83F0(temp_18);
        return -0xB;
    }
    if (temp_19 & 0x8000) {
        func_002F83F0(temp_18);
        return 0;
    }
    func_002F8420(temp_18);
    func_002F83F0(temp_18);
    return sp30;
}

s32 func_002FCB20(s32 fd, void *buf, s32 size) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16_2;
    s32 temp_18;
    s32 temp_19;
    s32 var_6;
    U5FioSlot *temp_16;

    temp_16 = func_002FBCD0(fd);
    func_002FC150(2);
    if (D_00568E78 == 0) {
        func_002FC180();
        return -1;
    }
    if ((temp_16 == NULL) || ((temp_19 = temp_16->busy) == 0)) {
        func_002FC180();
        return -9;
    }
    M2C_FIELD(pkt, s32 *, 0xC) = temp_16->w0;
    M2C_FIELD(pkt, s32 *, 0x1C) = temp_16 - D_00794E80;
    sp10.maxCount = 1;
    M2C_FIELD(pkt, void **, 0x10) = buf;
    M2C_FIELD(pkt, s32 *, 0x14) = size;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_18 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 *, 0) = temp_18;
    M2C_FIELD(pkt, s32 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 4;
    if (temp_19 & 0x8000) {
        func_002F8420(D_00568E84);
        var_6 = 0;
        __asm__ volatile("" :: "r"(var_6), "m"(D_00568DF8[0]));
        for (; var_6 < 0x20; var_6++) {
            if (D_00568DF8[var_6] == -1) {
                D_00568DF8[var_6] = M2C_FIELD(pkt, s32 *, 0);
                M2C_FIELD(pkt, s32 *, 0) = -M2C_FIELD(pkt, s32 *, 0);
                break;
            }
        }
        func_002F8400(D_00568E84);
    }
    if (!(temp_19 & 0x20000000)) {
        func_002FABD8(buf, size);
    }
    func_002FABD8(&D_00794A40, 0xA4);
    func_002FABD8(pkt, 0x20);
    if (func_002FB4C8(&D_00795080, 2, 0, &D_00793DC0, 0x20, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_18);
        func_002FC180();
        return -0xB;
    }
    __asm__("" : "+r"(temp_19));
    temp_16_2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_2 == 0) {
        func_002F83F0(temp_18);
        return -0xB;
    }
    if (temp_19 & 0x8000) {
        func_002F83F0(temp_18);
        return 0;
    }
    func_002F8420(temp_18);
    func_002F83F0(temp_18);
    return sp30;
}

typedef struct {
    s32 sema;
    s32 *res;
    s32 size;
    s32 fd;
    void *buf;
    s32 len;
    s32 mis;
    u8 data[16];
    s32 slot;
} PktWrite;

s32 func_002FCD90(s32 fd, u8 *buf, s32 size) {
    PktWrite *pkt = (PktWrite *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_20;
    s32 temp_22;
    s32 var_5;
    s32 var_6;
    s32 tmp;
    U5FioSlot *temp_16;

    temp_16 = func_002FBCD0(fd);
    func_002FC150(3);
    if (D_00568E78 == 0) {
        func_002FC180();
        return -1;
    }
    if ((temp_16 == NULL) || ((temp_22 = temp_16->busy) == 0)) {
        func_002FC180();
        return -9;
    }
    pkt->fd = temp_16->w0;
    pkt->slot = temp_16 - D_00794E80;
    sp10.maxCount = 1;
    pkt->len = size;
    pkt->buf = buf;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_20 = func_002F83E0(&sp10);
    pkt->sema = temp_20;
    pkt->res = &sp30;
    pkt->size = 4;
    if (temp_22 & 0x8000) {
        func_002F8420(D_00568E84);
        var_6 = 0;
        __asm__ volatile("" :: "r"(var_6), "m"(D_00568DF8[0]));
        for (; var_6 < 0x20; var_6++) {
            if (D_00568DF8[var_6] == -1) {
                D_00568DF8[var_6] = pkt->sema;
                pkt->sema = -pkt->sema;
                break;
            }
        }
        func_002F8400(D_00568E84);
    }
    if (((u32)buf & 0xF) == 0) {
        temp_16_2 = 0;
    } else {
        u32 sh = (u32)buf >> 4;
        tmp = (s32)buf - 0x10;
        __asm__("" : "+r"(sh), "+r"(tmp));
        sh <<= 4;
        temp_16_2 = sh - tmp;
    }
    temp_16_2 = (size < temp_16_2) ? size : temp_16_2;
    if (!(temp_22 & 0x20000000)) {
        __asm__("" :: "r"(size));
        func_002FABD8(buf, size);
    }
    buf = (u8 *)((s32)buf | 0x20000000);
    pkt->mis = temp_16_2;
    for (var_5 = 0; var_5 < temp_16_2; var_5++) {
        pkt->data[var_5] = buf[var_5];
    }
    if (func_002FB4C8(&D_00795080, 3, 0, &D_00793DC0, 0x30, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_20);
        func_002FC180();
        return -0xB;
    }
    __asm__("" : "+r"(temp_22));
    temp_16_3 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_3 == 0) {
        func_002F83F0(temp_20);
        return -0xB;
    }
    if (temp_22 & 0x8000) {
        func_002F83F0(temp_20);
        return 0;
    }
    func_002F8420(temp_20);
    func_002F83F0(temp_20);
    return sp30;
}

typedef struct {
    s32 sema;
    s32 *res;
    s32 size;
    s32 fd;
    s32 cmd;
    u8 arg[0x400];
    s32 f414;
    s32 f418;
    s32 len;
} PktIoctl;

s32 func_002FD050(s32 fd, s32 cmd, void *arg) {
    PktIoctl *pkt = (PktIoctl *)&D_00793DC0;
    SemaParam sp10;
    s32 sp30;
    U5FioSlot *slot;
    s32 i;
    s32 sema;
    s32 res2;
    s32 one = 1;

    slot = func_002FBCD0(fd);
    func_002FC150(one + 4);
    D_00793D84 = (s32 *)arg;
    if (D_00568E78 == 0) {
        func_002FC250();
    }
    if (slot == NULL || slot->busy == 0) {
        func_002FC180();
        return -9;
    }
    pkt->f414 = 0;
    pkt->f418 = 0;
    switch (cmd) {
    case 1: {
        s32 *p, *q;
        func_002F8420(D_00568E84);
        p = D_00568DF8;
        q = D_00568DF8;
        i = p - q;
        __asm__ volatile("" :: "r"(i));
        for (; i < 0x20; i++) {
            if (D_00568DF8[i] != -1) {
                break;
            }
        }
        if (i == 0x20) {
            *D_00793D84 = 0;
        } else {
            *D_00793D84 = 1;
        }
        func_002F8400(D_00568E84);
        func_002FC180();
        return 0;
    }
    case 2:
        *(s32 *)arg = *(s32 *)((s32)&D_00794A50 | 0x20000000);
        func_002FC180();
        return 0;
    case 3:
        *(u64 *)arg = *(u64 *)((s32)&D_00794A50 | 0x20000000);
        func_002FC180();
        return 0;
    }
    pkt->fd = slot->w0;
    pkt->cmd = cmd;
    if (arg == NULL) {
        pkt->len = 0;
    } else {
        pkt->len = 0x400;
        __builtin_memcpy(pkt->arg, arg, 0x400);
    }
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    sema = func_002F83E0(&sp10);
    pkt->sema = sema;
    pkt->res = &sp30;
    pkt->size = 4;
    func_002FABD8(&D_00793DC0, 0x420);
    if (func_002FB4C8(&D_00795080, 5, 0, &D_00793DC0, 0x420, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(sema);
        func_002FC180();
        return -0xB;
    }
    res2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (res2 == 0) {
        func_002F83F0(sema);
        return -0xB;
    }
    func_002F8420(sema);
    func_002F83F0(sema);
    return sp30;
}

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

s64 func_002FEA60(s32 fd, s64 b, s32 c) {
    void *pkt = &D_00793DC0;
    SemaParam sp10;
    s64 sp30;
    s32 temp_16_2;
    s32 temp_18;
    s32 temp_19;
    s32 var_6;
    U5FioSlot *temp_16;

    temp_16 = func_002FBCD0(fd);
    func_002FC150(0x16);
    if (D_00568E78 == 0) {
        func_002FC180();
        return -1;
    }
    if ((temp_16 == NULL) || ((temp_19 = temp_16->busy) == 0)) {
        func_002FC180();
        return -9;
    }
    M2C_FIELD(pkt, s32 *, 0xC) = temp_16->w0;
    M2C_FIELD(pkt, s64 *, 0x10) = b;
    M2C_FIELD(pkt, s32 *, 0x18) = c;
    M2C_FIELD(pkt, s32 *, 0x1C) = temp_16 - D_00794E80;
    sp10.maxCount = 1;
    sp10.initCount = 0;
    sp10.option = 0;
    temp_18 = func_002F83E0(&sp10);
    M2C_FIELD(pkt, s32 *, 0) = temp_18;
    M2C_FIELD(pkt, s64 **, 4) = &sp30;
    M2C_FIELD(pkt, s32 *, 8) = 8;
    if (temp_19 & 0x8000) {
        func_002F8420(D_00568E84);
        var_6 = 0;
        __asm__ volatile("" :: "r"(var_6), "m"(D_00568DF8[0]));
        for (; var_6 < 0x20; var_6++) {
            if (D_00568DF8[var_6] == -1) {
                D_00568DF8[var_6] = M2C_FIELD(pkt, s32 *, 0);
                M2C_FIELD(pkt, s32 *, 0) = -M2C_FIELD(pkt, s32 *, 0);
                break;
            }
        }
        func_002F8400(D_00568E84);
    }
    if (func_002FB4C8(&D_00795080, 0x16, 0, &D_00793DC0, 0x20, &D_00794A00, 4, NULL, NULL) < 0) {
        func_002F83F0(temp_18);
        func_002FC180();
        return -0xB;
    }
    __asm__("" : "+r"(temp_19));
    temp_16_2 = *(s32 *)((s32)&D_00794A00 | 0x20000000);
    func_002FC180();
    if (temp_16_2 == 0) {
        func_002F83F0(temp_18);
        return -0xB;
    }
    if (temp_19 & 0x8000) {
        func_002F83F0(temp_18);
        return 0;
    }
    func_002F8420(temp_18);
    func_002F83F0(temp_18);
    return sp30;
}

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
