#include "common.h"

typedef struct {
    void *f00;
    void *f04;
    void *f08;
} ListBB60;

typedef struct {
    u8 pad00[0x20];
    u8 *f20;
    s32 *f24;
    u8 pad28[0x8];
    ListBB60 list;
    u8 pad3C[0xE4];
    s32 f120;
    u16 f124;
} ObjBB60;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
} PoolNodeBC80;

extern void *D_006A3924;
extern PoolNodeBC80 g_pool_bc80[1023];
extern u16 g_bc80_free;
extern u16 g_bc80_used;

extern void fn_00267530(ObjBB60 *);
extern void fn_01b0bed0(ListBB60 *, ObjBB60 *);
extern ObjBB60 *fn_01b0c060(ListBB60 *);
extern void fn_01b0c000(ListBB60 *);
extern void fn_01b0a0d0(s32, s32);

s32 ovl_09478_01b0bb60(ObjBB60 *a0) {
    s32 cnt = 0;
    ListBB60 *s1 = &a0->list;
    ObjBB60 *s0;

    s1->f08 = s1->f00;
    while ((s0 = fn_01b0c060(s1)) != 0) {
        D_006A3924 = a0;
        fn_00267530(s0);
        cnt++;
        s0->f124 &= 0x7FFF;
        fn_01b0bed0(s1, s0);
        if (s0 == fn_01b0c060(s1)) {
            fn_01b0c000(s1);
        }
    }
    return cnt;
}

u8 *ovl_09478_01b0bc10(ObjBB60 *a0, s32 a1) {
    return a0->f20 + a1 * 32;
}

s32 *ovl_09478_01b0bc20(ObjBB60 *a0, s32 a1) {
    return a0->f24 + a1;
}

void ovl_09478_01b0bc30(void) {
    fn_01b0a0d0(-5, 0);
}

void ovl_09478_01b0bc40(void) {
    fn_01b0a0d0(-5, 2);
}

void ovl_09478_01b0bc50(ObjBB60 *a0) {
    fn_01b0a0d0(a0->f120, 0);
}

void ovl_09478_01b0bc60(ObjBB60 *a0) {
    fn_01b0a0d0(a0->f120, 8);
}

void ovl_09478_01b0bc70(ObjBB60 *a0) {
    fn_01b0a0d0(a0->f120, 2);
}

void ovl_09478_01b0bc80(void) {
    PoolNodeBC80 *p = g_pool_bc80;
    s32 i;
    for (i = 0; i < 1023; i++) {
        p->f08 = 0;
        p++;
    }
    g_bc80_used = 0;
    g_bc80_free = 1023;
}

u16 ovl_09478_01b0bcc8(void) {
    return g_bc80_free;
}

void ovl_09478_01b0bcd8(u32 *a0) {
    a0[2] = 0;
    a0[1] = 0;
    a0[0] = 0;
    a0[3] = 0;
}
