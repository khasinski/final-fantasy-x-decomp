#include "vu0.h"

typedef struct {
    u8 pad00[0xA0];
    float mtx[16];      /* 0xA0 */
    u8 padE0[0x50];
    float vec130[3];    /* 0x130 */
    float f13C;         /* 0x13C */
} Ovl9468Owner;

typedef struct Ovl9468Node {
    u8 pad00[0x20];
    float pos20[4];     /* 0x20 */
    float col30[4];     /* 0x30 */
    float dst40[4];     /* 0x40 */
    Ovl9468Owner *w50;  /* 0x50 */
    void *mgr;          /* 0x54 */
    u8 pad58[8];        /* 0x58 */
    u8 pobj[0x60];      /* 0x60 */
    float pC0[4];       /* 0xC0 */
    u16 hD0;            /* 0xD0 */
    u16 hD2;            /* 0xD2 */
    u16 hD4;            /* 0xD4 */
    u16 hD6;            /* 0xD6 */
    u8 padD8[8];        /* 0xD8 */
    void *wE0;          /* 0xE0 */
    s16 hE4;            /* 0xE4 */
    s16 hE6;            /* 0xE6 */
    u32 flags;          /* 0xE8 */
    int delay;          /* 0xEC */
    void *wF0;          /* 0xF0 */
    int wF4;            /* 0xF4 */
    void *wF8;          /* 0xF8 */
} Ovl9468Node;

extern void *D_006A3924;
extern float D_006A3930[16];
extern float D_006A3970[16];
extern float D_006A39B0[16];
extern float D_006A3A70[16];
extern float D_006A3AB0[16];
extern float D_006A3BB0[4];
extern int D_006A3BC4;
extern int D_006A3BCC;
extern int g_ovl_w_48;

extern void func_002B2730(int);
extern void func_002DD0B0(float *, float *);
extern void func_002DD0C0(float *, float *);
extern void func_002DD068(float *, float *, float);
extern void func_002DD050(float *, float *, float *);
extern void func_002DCE38(float *, float *, float *);
extern int func_00267FA0(void *, int);
extern void func_00267530(void *);
extern void fn_ovl_2ce0(void *);
extern void func_00268610(void *, void *, void *);

void ovl_09468_2728(Ovl9468Node *o)
{
    float scale[4];
    int tmp[4];
    u8 *pobj = o->pobj;
    Ovl9468Node *msg[1];

    if (o->flags & 2) {
        return;
    }
    if (o->delay > 0) {
        if (D_006A3BC4 == 0) {
            o->delay--;
        }
        return;
    }
    func_002B2730(0);
    if (D_006A3BC4 == 0) {
        u32 flags = o->flags;
        if (flags & 1) {
        int a2 = o->hE4;
        /* DEBT(FAKE): pin p_dst/e6 to v0/v1 to match VU0 interp setup */
        register float *p_dst __asm__("$2") = o->dst40;
        int *p_tmp = tmp;
        register int e6 __asm__("$3") = o->hE6;
        float *p_col = o->col30;
        u16 t0 = (u16)o->hE4;
        /* DEBT(ORDER): preserve addiu/lh interleaving before VU0 block */
        __asm__("" : "+r"(p_tmp) : "r"(a2));
        __asm__("" : "+r"(p_col) : "r"(e6));
        tmp[1] = e6;
        tmp[0] = a2;
        VU0_LQC2_INPUTS(31, p_tmp, p_col, p_dst);
        VU0_OP("vitof0.xyzw $vf31xyzw, $vf31xyzw");
        VU0_OP("vdiv Q, $vf31x, $vf31y");
        VU0_LQC2(30, 0, p_col);
        VU0_LQC2(29, 0, p_dst);
        VU0_OP("vsub.xyzw $vf30xyzw, $vf30xyzw, $vf29xyzw");
        VU0_OP("vwaitq");
        VU0_OP("vmulq.xyzw $vf30xyzw, $vf30xyzw, Q");
        VU0_OP("vadd.xyzw $vf29xyzw, $vf29xyzw, $vf30xyzw");
        VU0_OP("vftoi12.xyzw $vf29xyzw, $vf29xyzw");
        VU0_SQC2(29, 0, p_tmp);
        /* DEBT(FAKE): pin d0/d1 to v1/v0 for lhu/sh pair */
        { register u16 d0 __asm__("$3") = (u16)tmp[0];
          register u16 d1 __asm__("$2") = (u16)tmp[1];
          o->hD0 = d0;
          o->hD2 = d1; }
        o->hD4 = (u16)tmp[2];
        o->hD6 = (u16)tmp[3];
        if (a2 == 0) {
            o->flags = flags & ~1U;
        }
        o->hE4 = t0 - 1;
        }
    }
    D_006A3BB0[0] = 1.0f;
    D_006A3BB0[1] = 1.0f;
    D_006A3BB0[2] = 1.0f;
    D_006A3BB0[3] = 1.0f;
    func_002DD0B0(scale, o->pos20);
    func_002DD0C0(D_006A3930, o->w50->mtx);
    func_002DD068(&D_006A3930[0], &D_006A3930[0], scale[0]);
    func_002DD068(&D_006A3930[4], &D_006A3930[4], scale[1]);
    func_002DD068(&D_006A3930[8], &D_006A3930[8], scale[2]);
    {
        Ovl9468Owner *w50 = o->w50;
        float f = w50->f13C;
        int bits;
        VU0_LQC2(31, 0, scale);
        VU0_LQC2(29, 0, scale);
        MIPS_MFC1(bits, f);
        VU0_QMTC2(30, bits);
        VU0_OP("vmulx.xyz $vf29xyz, $vf31xyz, $vf30x");
        VU0_SQC2(29, 0, scale);
        func_002DD050(scale, scale, w50->vec130);
    }
    scale[3] = 1.0f;
    func_002DD0B0(o->pC0, scale);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3BCC = g_ovl_w_48;
    D_006A3924 = o->mgr;
    if (func_00267FA0(pobj, 48) != 0) {
        D_006A3924 = o->mgr;
        func_00267530(pobj);
        msg[0] = o;
        fn_ovl_2ce0(msg);
        o->flags |= 4U;
    }
    g_ovl_w_48 = D_006A3BCC;
    if (D_006A3BC4 == 0 && o->wE0 != 0) {
        func_00268610(pobj, o->wE0, o->wF8);
    }
}
