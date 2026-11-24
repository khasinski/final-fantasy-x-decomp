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

void func_01B02E18(s32 x, s32 y, s32 w, s32 h, s32 c1, s32 c2, s32 a) {
    void *ch;
    Qword *p;
    s32 bx, by;
    s32 x0, y0, x1, y1;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x7000000D;
    p++;

    p->q = 0;
    p->d[0] = 0x6021400000008002ULL;
    p->d[1] = 0x00555551ULL;
    p++;

    bx = x + 0x700;
    by = y + 0x730;
    x0 = (bx << 4) - 8;
    y0 = (by << 4) - 8;
    x1 = ((x + w) << 4) + 0x6FF8;
    y1 = ((y + h) << 4) + 0x72F8;

    p->w[0] = c1;
    p->w[1] = c1;
    p->w[2] = c1;
    p->w[3] = a;
    p++;

    p->w[0] = x0;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x1;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x1;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x0;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x0;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    w--;
    h--;
    x0 = (x << 4) + 0x7008;
    y0 = (y << 4) + 0x7308;
    x1 = ((bx + w) << 4) - 8;
    y1 = ((by + h) << 4) - 8;

    p->w[0] = c2;
    p->w[1] = c2;
    p->w[2] = c2;
    p->w[3] = a;
    p++;

    p->w[0] = x0;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x1;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x1;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x0;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = x0;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
