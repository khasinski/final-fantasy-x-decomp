/* tu_293 0x26cce0-0x26dad8: low; unk_26CCE0 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"

void func_0026CCE0(void) {
}

void func_0026CCE8(char *base, int a, ScriptCtx *ctx)
{
    WkMtx10 *w = (WkMtx10 *)base;
    float *trans = SLOT_WORK(float, base, ctx, 0);
    float *scale = SLOT_WORK(float, base, ctx, 1);

    func_002DD128(w->m);
    w->m[0][0] = scale[0];
    w->m[1][1] = scale[1];
    w->m[2][2] = scale[2];
    w->m[3][0] = trans[0];
    w->m[3][1] = trans[1];
    w->m[3][2] = trans[2];
}

void func_0026CD70(char *a0, int *a1) {
    char *v;
    char *m;

    if ((u32)a1[1] != 0xFFFFFFFF) {
        v = a0 + 0x40;
        m = *(char **)(a0 + 4) + 0x10;
        VU0_LQC2(27, 0, v);
        VU0_LQC2(28, 0, m);
        VU0_LQC2(29, 0x10, m);
        VU0_LQC2(30, 0x20, m);
        VU0_LQC2(31, 0x30, m);
        VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
        VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
        VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
        VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf0w");
        VU0_SQC2(26, 0, v);
    }
}

void func_0026CDC0(R6Mtx40 *o, void *unused, ScriptCtx *ctx) {
    Wkf0f4f8 *w = SLOT_WORK(Wkf0f4f8, o, ctx, 0);

    func_002DD128(o->m);
    o->f40 = w->f0;
    o->f44 = w->f4;
    o->f48 = w->f8;
}

void func_0026CE18(WkMtx10 *o, float *k)
{
    float m[4][4];

    func_002DD128(m);
    m[0][0] = D_006A3BB0[0] + D_006A3BB0[0] * k[1];
    if (k[2] < m[0][0]) {
        m[0][0] = k[2];
    }
    m[2][2] = m[0][0];
    m[1][1] = D_006A3BB0[1] + D_006A3BB0[1] * k[1];
    if (k[2] < m[1][1]) {
        m[1][1] = k[2];
    }
    func_002DCE38(o->m, m, o->m);
}

void func_0026CEB8(WkMtx10 *o, float *k)
{
    float m[4][4];

    func_002DD128(m);
    m[0][0] = D_006A3BB0[0] + D_006A3BB0[0] * k[1];
    if (k[2] < m[0][0]) {
        m[0][0] = k[2];
    }
    m[2][2] = m[0][0];
    func_002DCE38(o->m, m, o->m);
}

extern float D_006A3BB4;

void func_0026CF30(WkMtx10 *o, float *k)
{
    float m[4][4];

    func_002DD128(m);
    m[1][1] = D_006A3BB4 + D_006A3BB4 * k[1];
    if (k[2] < m[1][1]) {
        m[1][1] = k[2];
    }
    func_002DCE38(o->m, m, o->m);
}

void func_0026CFA0(WkMtx10 *o, float *k)
{
    float m[4][4];

    func_002DD128(m);
    m[1][1] = D_006A3BB4 + D_006A3BB4 * k[1];
    if (k[2] < m[1][1]) {
        m[1][1] = k[2];
    }
    m[0][0] = m[1][1] = m[2][2];
    func_002DCE38(o->m, m, o->m);
}

void func_0026D020(WkMtx10 *o, float *k)
{
    float m[4][4];

    func_002DD128(m);
    m[0][0] = D_006A3BB0[0] + D_006A3BB0[0] * k[1];
    if (k[2] < m[0][0]) {
        m[0][0] = k[2];
    }
    m[1][1] = m[2][2] = m[0][0];
    func_002DCE38(o->m, m, o->m);
}

void func_0026D0A0(u8 *p) {
    func_002DCE38(p + 0x50, &D_006A3AB0, p + 0x10);
}

void func_0026D0B8(U4Xform *o)
{
    T6_ColMgr *mgr = ppvMng;

    func_002DD068(o->m[0], o->axis[0], mgr->m60[0]);
    func_002DD068(o->m[1], o->axis[1], mgr->m60[1]);
    func_002DD068(o->m[2], o->axis[2], mgr->m60[2]);
    func_002DCE08(o->m[3], D_006A39B0, o->axis[3]);
    func_002DCE38(o->m, D_006A3A70, o->m);
}

extern void func_002DD050(void *dst, void *a, void *b);

void func_0026D148(U4Xform *o)
{
    T6_ColMgr *mgr = ppvMng;

    func_002DD068(o->m[0], o->axis[0], mgr->m60[0]);
    func_002DD068(o->m[1], o->axis[1], mgr->m60[1]);
    func_002DD068(o->m[2], o->axis[2], mgr->m60[2]);
    func_002DD050(o->m[3], o->axis[3], mgr->m60);
    o->m[3][0] += ((T6_LtCam *)D_006A39B0)->x;
    o->m[3][1] += ((T6_LtCam *)D_006A39B0)->y;
    o->m[3][2] += ((T6_LtCam *)D_006A39B0)->z;
    func_002DCE38(o->m, D_006A3A70, o->m);
}

extern char D_006A3A00[];
extern void func_002DCE80(void *d, void *a, void *b);

void func_0026D210(void) {
    float b[4];
    float a[4];
    float c[4];
    float *base = (float *)D_006A39B0;
    u_long128 *o;
    u_long128 *q;

    a[3] = 0;
    a[0] = base[4];
    a[1] = base[5];
    a[2] = base[6];
    func_002DCEC8(a, a);
    o = (u_long128 *)D_006A3A00;
    *o = *(u_long128 *)a;
    b[0] = a[1];
    b[1] = -a[0];
    b[2] = 0;
    b[3] = 0;
    func_002DCEC8(b, b);
    q = o - 1;
    q[0] = *(u_long128 *)b;
    func_002DCE80(c, b, a);
    func_002DCEC8(c, c);
    q[3] = *(u_long128 *)(D_006A39B0 + 0x30);
    q[2] = *(u_long128 *)c;
    func_002DCE38(D_006A3AF0, D_006A3A70, q);
}

void func_0026D310(ScriptTransformWork *work)
{
    T6_ColMgr *manager = ppvMng;
    u_long128 *output = work->output;

    func_002DD068(output, &work->input[0], manager->m60[0]);
    func_002DD068(&work->output[1], &work->input[1], manager->m60[1]);
    func_002DD068(&work->output[2], &work->input[2], manager->m60[2]);
    work->output[3] = work->input[3];
    func_002DCE38(output, D_006A3AF0, output);
    func_002DCE08(&work->output[3], D_006A3AB0, &work->input[3]);
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26CCE0", func_0026D3A8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26CCE0", func_0026D500);

void func_0026D640(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8fCf10f14 *w = SLOT_WORK(Wkf0f4f8fCf10f14, base, ctx, 2);

    w->f0 = w->f4 = w->f8 = w->fC = w->f10 = w->f14 = 0.0f;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26CCE0", func_0026D670);

void func_0026D890(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h0 = w->h2 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26CCE0", func_0026D8B0);

typedef struct P26Node {
    struct P26Node *next;
    u8 pad4[8];
    int wC;
} P26Node;

typedef struct P26List {
    u8 pad0[4];
    P26Node *head;
    u8 pad8[4];
    u16 count;
} P26List;

typedef struct P26Arg1 {
    u8 pad0[0xC];
    int b0 : 1;
    u8 pad10[0x10];
    int ofs20;
} P26Arg1;

typedef struct P26Arg2 {
    u8 pad0[4];
    u16 step4;
} P26Arg2;

extern void func_0026D8B0(P26Node *a, int *b, P26Arg2 *c);

void func_0026DA30(P26List *a0, P26Arg1 *a1, P26Arg2 *a2, int a3)
{
    P26Node *s0;
    int s1;
    int **slot;
    int *p;
    int *next;

    s0 = a0->head;
    switch (a1->b0) {
    case 0:
        s1 = a0->count;
        do {
            slot = (int **)((char *)s0 + a1->ofs20 + a3 * 4);
            p = *slot;
            next = (int *)((char *)p + a2->step4);
            if (*next == s0->wC) {
                p = next;
                *slot = p;
            }
            func_0026D8B0(s0, p, a2);
            s1--;
            s0 = s0->next;
        } while (s1 != 0);
        break;
    }
}
