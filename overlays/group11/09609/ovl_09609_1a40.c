#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

extern s32 D_01B0E19C;
extern s32 D_01B0E1A4;
extern s32 D_01B0E1A8;
extern u64 D_006F2D40;

extern void func_01B01560(void);
extern void func_01B01780(void);
extern void func_0011ABA8(s32);
extern void func_0021BCC0(void);
extern void func_002DA610(s32, s32);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);

void func_01B01A40(void) {
    void *ch;
    Qword *p;
    s32 a;
    s32 x0, x1, y0;

    if (D_01B0E1A4 == 0) {
        func_01B01560();
        func_0011ABA8(1);
        D_01B0E1A4 = 1;
    }

    func_01B01780();
    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000003;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008002ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = 0x3000DULL;
    p->d[1] = 0x47ULL;
    p++;

    p->d[0] = 0x0000008000000044ULL;
    p->d[1] = 0x42ULL;
    p++;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    {
        s32 d = 10;
        a = ((d - D_01B0E19C) * 64) / d;
    }
    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000004;
    p++;

    p->q = 0;
    p->d[0] = 0x3023400000008001ULL;
    p->d[1] = 0x551ULL;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = a;
    p++;

    x0 = 0x6FF8;
    y0 = 0x72F8;
    x1 = 0x8FF8;

    p->w[0] = x0;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    {
        register s32 y2 __asm__("$8") = 0x8CF8;
        p->w[0] = x1;
        p->w[1] = y2;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;
    }

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    {
        s32 d = 10;
        a = ((d - D_01B0E19C) * 128) / d;
    }
    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000011;
    p++;

    p->q = 0;
    p->d[0] = 0x8026400000008002ULL;
    p->d[1] = 0x51515151ULL;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = a;
    p++;

    p->w[0] = x0;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = a;
    p++;

    p->w[0] = x1;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    {
        register s32 yt __asm__("$8") = 0x77F8;
        p->w[0] = x0;
        p->w[1] = yt;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        p->w[0] = 0;
        p->w[1] = 0;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        p->w[0] = x1;
        p->w[1] = yt;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        yt = 0x8CF8;

        p->w[0] = 0;
        p->w[1] = 0;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        y0 = 0x87F8;
        p->w[0] = x0;
        p->w[1] = y0;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        p->w[0] = 0;
        p->w[1] = 0;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        p->w[0] = x1;
        p->w[1] = y0;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        p->w[0] = 0;
        p->w[1] = 0;
        p->w[2] = 0;
        p->w[3] = a;
        p++;

        p->w[0] = x0;
        p->w[1] = yt;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;

        p->w[0] = 0;
        p->w[1] = 0;
        p->w[2] = 0;
        p->w[3] = a;
        p++;

        p->w[0] = x1;
        p->w[1] = yt;
        p->w[2] = 0;
        p->w[3] = 0;
        p++;
    }

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = *(volatile u64 *)&D_006F2D40;
    p->d[1] = 0x47ULL;
    p++;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    if (D_01B0E1A8 == 1) {
        func_0021BCC0();
        func_002DA610(0, 0);
    }
}
