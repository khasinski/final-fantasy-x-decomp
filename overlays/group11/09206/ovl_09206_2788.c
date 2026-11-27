#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

extern u64 D_006F2CE0[];

extern void func_0011A538(s32 *);
extern void func_002DA610(s32, s32);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);

void func_01B02788(void) {
    s32 info;
    void *ch;
    Qword *p;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x7000000C;
    p++;

    func_0011A538(&info);
    {
        s32 field = info;
        s32 tbp;

        p->q = 0;
        p->d[0] = 0xB08B400000008001ULL;
        p->d[1] = 0x0EEE535136EEULL;
        p++;

        p->d[0] = 0x0A0800D0ULL;
        p->d[1] = 0x4CULL;
        p++;

        p->d[0] = 0x0003000DULL;
        p->d[1] = 0x47ULL;
        p++;

        if (field & 1) {
            tbp = 0;
        } else {
            tbp = 0xD00;
        }
        p->d[0] = (u64)(tbp | (8 << 14) | (9 << 26)) | ((u64)9 << 30);
        p++;
    }

    p->w[0] = 0;
    p->w[1] = 0;
    p++;

    p->w[0] = 0x80;
    p->w[1] = 0x80;
    p->w[2] = 0x80;
    p->w[3] = 0x80;
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

    p->d[0] = 0;
    p->d[1] = 0x3FULL;
    p++;

    p->d[0] = D_006F2CE0[4];
    p->d[1] = 0x4CULL;
    p++;

    p->d[0] = D_006F2CE0[12];
    p->d[1] = 0x47ULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
