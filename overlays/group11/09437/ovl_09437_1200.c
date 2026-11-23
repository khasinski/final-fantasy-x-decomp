#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

typedef struct {
    u8 pad0[0x60];
} GsLoadImage;

extern u64 D_006F2CE0[];
extern void *D_01B0A5F4;

extern void func_002DA610(s32, s32);
extern void func_002DA928(GsLoadImage *, s32, s32, s32, s32, s32, s32, s32);
extern void func_002DAC50(GsLoadImage *, void *);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);
extern void func_002F8660(s32);

void func_01B01200(void) {
    GsLoadImage img;
    void *ch;
    Qword *p;

    func_002DA610(0, 0);
    func_002DA928(&img, 0x1A00, 8, 10, 0, 0, 0x200, 0x1A0);
    func_002F8660(0);
    func_002DAC50(&img, D_01B0A5F4);
    func_002DA610(0, 0);

    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = 0;
    p->d[1] = 0x3FULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000005;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008004ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = 0x0003000DULL;
    p->d[1] = 0x47ULL;
    p++;

    p->d[0] = 0x067C007FC00AULL;
    p->d[1] = 0x8ULL;
    p++;

    p->d[0] = 0x000664A21A00ULL;
    p->d[1] = 0x6ULL;
    p++;

    p->d[0] = 0x0000008000008080ULL;
    p->d[1] = 0x3BULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000007;
    p++;

    p->q = 0;
    p->d[0] = 0x608B400000008001ULL;
    p->d[1] = 0x00E53531ULL;
    p++;

    p->w[0] = 0x80;
    p->w[1] = 0x80;
    p->w[2] = 0x80;
    p->w[3] = 0x80;
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p++;

    p->w[0] = 0x6FF8;
    p->w[1] = 0x72F8;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0x2000;
    p->w[1] = 0x1A00;
    p++;

    p->w[0] = 0x8FF8;
    p->w[1] = 0x8CF8;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->d[0] = D_006F2CE0[12];
    p->d[1] = 0x47ULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
