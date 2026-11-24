#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

extern void func_002DA610(s32, s32);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);
extern void func_01B02E18(s32, s32, s32, s32, s32, s32, s32);

void func_01B03068(s32 x, s32 y) {
    void *ch;
    Qword *p;
    s32 x0, x1;
    s32 y0, y1;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000013;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = 0x0000008000000044ULL;
    p->d[1] = 0x42ULL;
    p++;

    y0 = ((y + 0x730) << 4) - 8;

    p->q = 0;
    p->d[0] = 0x8026400000008002ULL;
    p->d[1] = 0x51515151ULL;
    p++;

    x0 = (x << 4) + 0x6FF8;
    x1 = ((x + 0x37) << 4) + 0x6FF8;
    y1 = ((y + 0x3C) << 4) + 0x72F8;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0x70;
    p++;

    p->w[1] = y0;
    p->w[0] = x0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0x70;
    p++;

    p->w[1] = y0;
    p->w[0] = x1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[1] = y1;
    p->w[0] = x0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[1] = y1;
    p->w[0] = x1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    y0 = (y << 4) + 0x75D8;
    y1 = ((y + 0x6A) << 4) + 0x72F8;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

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
    p->w[3] = 0x70;
    p++;

    p->w[0] = x0;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0x70;
    p++;

    p->w[0] = x1;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
    func_01B02E18(x, y, 0x37, 0x69, 0xC0, 0x50, 0x80);
}
