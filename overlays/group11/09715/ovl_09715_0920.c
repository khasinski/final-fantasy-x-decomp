/* 09715/09757 GS scratchpad fade/sprite draw callback (512 B). */

#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} SprQword;

extern SprQword D_006F2D40;
extern u8 g_ovl_mgr[];
extern void *g_ovl_ptr_6b94;

extern int func_002DA610(int, int);
extern void *func_002DB6D8(int);
extern void func_002DBA28(void *, void *);
extern void fn_ovl_3a88(void *, void *);

void ovl_09715_0920(void)
{
    void *ch;
    SprQword *p;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (SprQword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000003;
    p++;
    p->q = 0;
    p->d[0] = 0x1000000000008002ULL;
    p->d[1] = 0x0EULL;
    p++;
    p->d[0] = 0x0003000DULL;
    p->d[1] = 0x47ULL;
    p++;
    p->d[0] = 0x0000008000000044ULL;
    p->d[1] = 0x42ULL;
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    p = (SprQword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000004;
    p++;
    p->q = 0;
    p->d[0] = 0x3023400000008001ULL;
    p->d[1] = 0x551ULL;
    p++;
    p->w[0] = 255;
    p->w[1] = 255;
    p->w[2] = 255;
    p->w[3] = 128;
    p++;
    p->w[0] = 28664;
    p->w[1] = 29432;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;
    p->w[0] = 0x8FF8;
    p->w[1] = 0x8CF8;
    p->w[2] = 0;
    p->w[3] = 0;
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    p = (SprQword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;
    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0x0EULL;
    p++;
    p->d[0] = D_006F2D40.d[0];
    p->d[1] = 0x47ULL;
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    fn_ovl_3a88(g_ovl_mgr, g_ovl_ptr_6b94);
}
