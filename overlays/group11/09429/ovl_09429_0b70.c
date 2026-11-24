#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x4];
    float pos[4];
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x18];
    int w120;
    u8 pad124[0x2];
    u8 b126;
    u8 pad127[0x9];
} OvlObj;

typedef struct {
    u8 pad00[0x10];
    u8 sub10[0xC];
    float f1C;
    int w20;
    u8 pad24[0x4];
    int w28;
    int w2C;
    int w30;
    int w34;
    int w38;
    int w3C;
    u8 pad40[0x4];
    int w44;
    int w48;
    int w4C;
    int w50;
    int w54;
} OvlNode;

typedef struct {
    int w00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    u8 pad1C[0x8];
    int w24;
    u8 pad28[0x4];
    u16 h2C;
} OvlS1;

typedef struct {
    float f00;
    float f04;
    float f08;
    u8 pad0C[0xC];
    int w18;
    int w1C;
    int w20;
    int w24;
    int w28;
} OvlA1;

extern u8 g_heap_base[];
extern u8 *g_ptr_6920;
extern u8 *g_ptr_6924;
extern u8 *g_ptr_68dc;
extern u8 g_mgr_68e0[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern struct { int w00; int w04; } g_738;
extern int g_tbl_0688[];
extern u8 g_0630[];
extern u8 g_0658[];
extern u8 g_06e0[];
extern u8 g_68a8[];
extern int g_68c8;
extern int g_68cc;
extern int g_68d0;
extern int g_68d4;
extern void *g_68d8;
extern u8 fn_10f0[];
extern u8 fn_1120[];
extern u8 fn_11d8[];
extern u8 fn_1400[];
extern u8 fn_4730[];
extern u8 fn_4740[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_4098(void *, void *, void *, int);
extern void fn_1728(int);
extern void fn_4170(void *, void *, int, float, int, int, void *);
extern void fn_1850(int, void *, int);
extern int func_002EFD78(void);
extern float func_002B3DB0(float);
extern int fn_1600(int);
extern void fn_5f48(void *, int);
extern void fn_6148(void *, int);
extern OvlNode *fn_61e0(void);
extern void **fn_4700(void *, int);
extern void fn_5538(void *, void *);
extern void fn_5ba8(void *, int);
extern void fn_5cb0(void *, int);
extern void fn_6020(void *);
extern void fn_6738(void *, void *, void *, int);
extern void fn_3238(int, void *, void *);
extern u8 *fn_3e10(void *);
extern void fn_3fd8(void *);

int ovl_09429_0b70(void)
{
    float v00[4];
    u8 *heap = g_heap_base;
    int i;
    int j;
    int t;
    OvlObj *obj;
    int *s0;
    OvlS1 *s1;
    OvlA1 *a1;
    u8 *p;
    u8 *q;

    g_ptr_6920 = heap;
    g_ptr_6924 = heap + 0x40000;
    g_ptr_68dc = heap + 0x140000;
    {
        u8 *mgr = g_mgr_68e0;
        register int k0 __asm__("$22") = 0;
        register int k1 __asm__("$20") = 1;
        OvlObj *o1;

        *(void **)(mgr + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
        fn_4098(mgr, g_hdr_40, g_ptr_6920, 0x40000);
        fn_1728(-1);

        t = 40;
        obj = (OvlObj *)(heap + 0x165000);
        o1 = obj + 1;
        for (i = 0; i < 11; i++) {
            fn_4170(mgr, obj, 1, 0.15f, t, 0, 0);
            obj->w120 = k0;
            obj->p104 = fn_1400;
            obj->b126 = 2;
            fn_4170(mgr, o1, 1, 0.15f, t, 0, 0);
            o1->w120 = k1;
            o1->p104 = fn_1400;
            o1->b126 = 2;
            obj += 2;
            o1 += 2;
            k0 += 2;
            k1 += 2;
            t += 4;
        }
    }

    for (i = 0; i < g_738.w04; i++) {
        register int c912 __asm__("$2") = 912;
        register int off __asm__("$3") = i * c912;
        register int c6a20 __asm__("$2") = 0x166A20;
        off += c6a20;
        obj = (OvlObj *)(heap + off);
        fn_1850(i, v00, 0);
        t = 140;
        for (j = 0; j < 3; j++) {
            void *cb;
            t += func_002EFD78() % 8 + 13;
            cb = (j == 2) ? fn_4730 : fn_4740;
            fn_4170(g_mgr_68e0, obj, 0, 0.2f, t, 0, cb);
            obj->fC0 = func_002B3DB0(0.17453293f);
            obj->fC4 = func_002B3DB0(6.2831855f);
            obj->fC8 = func_002B3DB0(0.17453293f);
            copy_vec(obj->pos, v00);
            obj->w120 = fn_1600(i);
            obj++;
        }
    }

    fn_5f48(heap + 0x160000, 64);
    fn_6148(heap + 0x168720, 32);

    t = 0;
    i = 0;
    {
        register int _blk4 __asm__("$20");
        int cm1 = -1;
        register int c40 __asm__("$23") = 40;
        register int c15 __asm__("$21") = 15;
        __asm__("" : "=r"(_blk4));
        for (; i < 22; i++) {
            OvlNode *n = fn_61e0();
            if (n == 0) {
                break;
            }
            fn_5538(n->sub10, *fn_4700(g_mgr_68e0, 3));
            __asm__("" : : "r"(_blk4));
            n->w30 = cm1;
            n->f1C = 0.2f;
            {
                int v = g_tbl_0688[i];
                *(volatile int *)&n->w54 = t;
                *(volatile int *)&n->w34 = v;
            }
            if (i & 1) {
                t += 2;
            }
            *(volatile int *)&n->w28 = 0;
            *(volatile int *)&n->w2C = 0;
            *(volatile int *)&n->w38 = c40;
            *(volatile int *)&n->w3C = 0;
            *(volatile int *)&n->w20 = 0;
            *(volatile int *)&n->w44 = c15;
            *(volatile int *)&n->w48 = 10;
            *(volatile int *)&n->w4C = c15;
            *(volatile int *)&n->w50 = 0;
        }
    }

    s0 = (int *)(heap + 0x1686A0);
    s0[0] = 0;
    s0[1] = 80;
    s0[2] = 0;
    s0[3] = 144;
    fn_5ba8(s0, 76);
    g_68d4 = (int)s0;

    s1 = (OvlS1 *)(heap + 0x1686BC);
    fn_5cb0(s1, 76);
    s1->w24 = 144;
    s1->f04 = 1.0f;
    s1->f08 = 1.0f;
    s1->f0C = 0.0f;
    s1->f10 = 4.0f;
    s1->f14 = 4.0f;
    s1->f18 = 0.0f;
    s1->h2C |= 3;
    g_68d8 = s1;
    g_68cc = 140;
    g_68d0 = 64;
    g_68c8 = 0;

    a1 = (OvlA1 *)(heap + 0x1686EC);
    a1->f00 = 2.0f;
    a1->f04 = 2.0f;
    a1->f08 = 2.0f;
    a1->w18 = 32;
    a1->w1C = 0;
    a1->w20 = 16;
    a1->w24 = 110;
    a1->w28 = -1;
    fn_6020(a1);

    p = heap + 0x169520;
    fn_6738(p, g_res_data, g_0630, 1);
    *(int *)(p + 0x54) = -1;
    fn_6738(p + 0x60, g_res_data, g_0658, 2);

    fn_3238(-1, g_68a8, g_06e0);
    q = fn_3e10(fn_10f0);
    q[0x18] = 1;
    fn_3fd8(q);
    fn_3fd8(fn_3e10(fn_11d8));
    q = fn_3e10(fn_1120);
    q[0x18] = 2;
    fn_3fd8(q);
    return 0;
}
