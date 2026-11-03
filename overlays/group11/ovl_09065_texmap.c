/* TU rank 22 (docs/overlay-tus.tsv): func_01B026A8, 1132 B, byte-identical in 129 containers
 * (file09065..file09756, start per container in overlays/wip/p2_units.py).
 * STATUS: MATCHES all 129 containers (verified with verify_overlays.py --unit, .text 0x46C).
 * PARKED only because it needs VU0_STORE_VF0 (`sqc2 $vf0, 0(reg)`, two vectors set to
 * (0,0,0,1)), which docs/ASM_POLICY.md does not allow yet. To register: add the intrinsic
 * to the policy/common.h, move this file to overlays/group11/ and overlays/wip/p2_units.py to
 * overlays/units/p2.py.
 * Matching facts: func_00173B90 must be declared as returning int (v0 liveness steers the
 * register of the tw/64 compare); args t0/t1 of func_00173CD8 are GS BITBLTBUF/SCISSOR-style
 * 64-bit words; arg0+0 is a GS TEX0 u64. */
#include "p2_overlay.h"

typedef unsigned long u_long64;

typedef struct P2Upload {
    u16 tbp;    /* 0x0 */
    s16 tbw;    /* 0x2 */
    u16 psm;    /* 0x4 */
    s16 x;      /* 0x6 */
    s16 y;      /* 0x8 */
    s16 w;      /* 0xA */
    s16 h;      /* 0xC */
} P2Upload;

typedef struct P2Param {
    u8 pad00[0x30];
    float v30[3];      /* 0x30 */
    float scale;       /* 0x3C */
    float sx;          /* 0x40 */
    float sy;          /* 0x44 */
    float sz;          /* 0x48 */
    u8 pad4C[0x44];
    float v90[4];      /* 0x90 */
    u8 padA0[0x1C];
    void *buf;         /* 0xBC */
} P2Param;

typedef struct P2TexObj {
    union {
        u16 h[4];
        u_long64 tex0;
    } t;                       /* 0x000 */
    u8 pad008[0x78];
    float m80[4][4];           /* 0x080 */
    float mC0[4][4];           /* 0x0C0 */
    u8 pad100[0x11A];
    s16 h21A;                  /* 0x21A */
    u8 pad21C[4];
    P2Param *prm;              /* 0x220 */
    u8 pad224[0x9C];
    float m2C0[4][4];          /* 0x2C0 */
    u8 pad300[0xA8];
    void *heap;                /* 0x3A8 */
} P2TexObj;

int yiDObjToOMD(int a, int b);
int func_00173B90(void *buf, int size, int a, int b, float *m, float *vmin, float *vmax, int c);
void func_00173CD8(void *buf, float *vmin, float *vmax, int h, u_long64 tex0, u_long64 size, float s);
void func_001AF2E8(float *v);
int func_002967E8(P2TexObj *th, s16 *pc);
void *op_malloc(void *heap, int size);
void op_free(void *heap, void *p);
void func_002B5318(void *dst, void *src, float *v);
void func_002B5348(void *dst, void *src, void *a, void *b);
void func_002B56D8(void *dst, void *a, void *b);
void func_002B5978(float *dst, float *src, float s);
void op_unit_m_scale(void *m, float s);
void op_md_draw_map_test(int a, void *m, int c);
void func_002CF040(P2Upload *u, void *buf);
void func_002CF1D0(P2Upload *u, void *buf);
void *opus_local_get(P2TexObj *th, P2Param *sub);

s16 *func_01B026A8(P2TexObj *th, s16 *pc)
{
    P2Param *prm;
    s16 *src;
    u_long64 tex0;
    int tw;
    int th_;
    int tbw;

    P2Upload up;
    float v10[4];
    float vmin[4];
    float vmax[4];
    float m40[4][4];
    float m80[2][4][4]; /* DEBT(PADDING): unused frame space */

    prm = th->prm;
    switch (th->h21A & 0xF000) {
    case 0:
        yiDObjToOMD(0x06800000, 0);
        pc++;
        break;
    case 0x1000:
        pc++;
        op_unit_m_scale(th->m80, prm->scale * (1.0f / 1024.0f));
        func_002B5348(th->m80, th->m80, prm->v30, prm->v90);
        func_002B56D8(th->m80, opus_local_get(th, prm), th->m80);
        func_002B56D8(th->mC0, th->m2C0, th->m80);
        op_md_draw_map_test(0x06800000, th->mC0, 0x01F00000);
        break;
    case 0x2000:
        func_002967E8(th, pc);
        op_free(th->heap, prm->buf);
        prm->buf = op_malloc(th->heap, 0x40000);
        src = (s16 *)((u8 *)pc + pc[1]);
        th->t.h[0] = src[0];
        th->t.h[1] = src[1];
        th->t.h[2] = src[2];
        th->t.h[3] = src[3];
        tex0 = th->t.tex0;
        tw = 1 << (int)((tex0 >> 26) & 0xF);
        th_ = 1 << (int)((tex0 >> 30) & 0xF);
        op_unit_m_scale(m40, prm->scale * (1.0f / 256.0f) / 10.0f);
        func_001AF2E8(v10);
        func_002B5978(v10, v10, 0.1f);
        func_002B5318(m40, m40, v10);
        VU0_STORE_VF0(vmin);
        VU0_STORE_VF0(vmax);
        pc += 2;
        src = prm->buf;
        vmin[0] = -(prm->sx * (1.0f / 256.0f) / 10.0f);
        vmin[2] = -(prm->sz * (1.0f / 256.0f) / 10.0f);
        vmax[0] = prm->sx * (1.0f / 256.0f) / 10.0f;
        vmax[2] = prm->sz * (1.0f / 256.0f) / 10.0f;
        func_00173B90(src, 0x40000, 0, 0, (float *)m40, vmin, vmax, 1);
        tbw = tw / 64;
        func_00173CD8(src, vmin, vmax, th_,
                      ((tex0 & 0x3FFF) >> 5) | ((u_long64)tbw << 16) | (((tex0 >> 20) & 0x3F) << 24),
                      ((u_long64)(tw - 1) << 16) | ((u_long64)(th_ - 1) << 48), 1.0f);
        op_free(th->heap, src);
        up.tbp = tex0 & 0x3FFF;
        up.tbw = tbw;
        up.psm = (tex0 >> 20) & 0x3F;
        up.x = 0;
        up.y = 0;
        up.w = 0x100;
        up.h = 0x100;
        func_002CF1D0(&up, op_malloc(th->heap, 0x40000));
        break;
    case 0x3000:
        func_002967E8(th, pc);
        src = (s16 *)((u8 *)pc + pc[1]);
        pc += 2;
        th->t.h[0] = src[0];
        th->t.h[1] = src[1];
        th->t.h[2] = src[2];
        th->t.h[3] = src[3];
        tex0 = th->t.tex0;
        tw = 1 << (int)((tex0 >> 26) & 0xF);
        up.tbp = tex0 & 0x3FFF;
        up.tbw = tw / 64;
        up.psm = (tex0 >> 20) & 0x3F;
        up.x = 0;
        up.y = 0;
        up.w = 0x100;
        up.h = 0x100;
        func_002CF040(&up, prm->buf);
        break;
    }
    return pc;
}
