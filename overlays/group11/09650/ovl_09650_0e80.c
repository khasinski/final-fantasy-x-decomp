#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

extern void func_002DA610(s32, s32);
extern void func_01B05798(s32 *, s32 *);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);

void func_01B00E80(void) {
    s32 a[4];
    s32 b[4];
    void *ch;
    Qword *p;

    func_002DA610(0, 0);
    func_01B05798(a, b);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000006;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008005ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = 0x5000DULL;
    p->d[1] = 0x47ULL;
    p++;

    p->d[0] = 0x21ULL;
    p->d[1] = 0x14ULL;
    p++;

    p->d[0] = 0x0000000131000108ULL;
    p->d[1] = 0x4EULL;
    p++;

    p->d[0] = 0ULL;
    p->d[1] = 0x08ULL;
    p++;

    p->d[0] = (u64)b[0] | ((u64)b[1] << 8) | ((u64)b[2] << 16);
    p->d[1] = 0x3DULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
