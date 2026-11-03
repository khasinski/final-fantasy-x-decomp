/* TU rank 12 (docs/overlay-tus.tsv): func_01B03C28, 2124 B, byte-identical in 130 containers
 * (file09044..file09756). Builds a 33x33 ring/disc mesh (vertex + normal grids, 32x32 quads).
 * STATUS: NOT MATCHING (WIP draft, ~50 diff blocks; built .text 0x850 vs 0x84C).
 * Needs two non-policy asm intrinsics: VU0_SQRT (qmtc2/vsqrt/vwaitq/vaddq.x/qmfc2; result
 * dead but moved to $f12, so the output must be a float var that also lives in an FPR) and
 * SQ_ZERO (`sq $zero`), plus:
 *  - quad loop: the original keeps a dead computation
 *      ((0x80 - j*4) & 0xFF) << 24 | 0x808080   (dsll 24, 64-bit)
 *    right before storing the constant 0x80808080 to rgba[0..3]; every form tried (plain
 *    overwrite, (c & 0xFFFFFF) | 0x80000000, union partial write) is deleted by gcc. Find
 *    the construct that leaves it (probably something combine folds after flow).
 *  - quad loop scheduling: original does all idx/rgba stores first, then 8 uv values; uv for
 *    the outer radius use t after `r += dr; t += r;`; mine still differs there.
 *  - original keeps `pr` (out+0x30) spilled at sp+0x6C and the scr/vec pointers in fp/s6;
 *    callee-saved order: wv=s5, rg=s4, out=s3, tbl=s7.
 * Loops 1-4 are structurally right. */
#include "p2_overlay.h"

typedef unsigned long u_long64;

typedef struct P2Vtx {
    float x, y, z, w;
} P2Vtx;

typedef struct P2Prim {
    u32 rgba[4];       /* 0x00 */
    s16 idx[4];        /* 0x10 */
    s16 uv[4][2];      /* 0x18 */
    s16 idx2[4];       /* 0x28 */
} P2Prim;

typedef struct P2PrimHdr {
    u8 b0;
    u8 term;           /* 0x1 */
    u16 count;         /* 0x2 */
    u8 pad4[4];
    u_long64 tex;      /* 0x8 */
} P2PrimHdr;

typedef struct P2Mesh {
    int w0;            /* 0x00 */
    int w4;            /* 0x04 */
    int vtx_ofs;       /* 0x08 */
    int nrm_ofs;       /* 0x0C */
    u16 nvtx;          /* 0x10 */
    s16 h12;           /* 0x12 */
    s16 h14;           /* 0x14 */
    u8 pad16[0xA];
    P2PrimHdr hdr;     /* 0x20 */
    P2Prim prim[1];    /* 0x30 */
} P2Mesh;

typedef struct P2Wave {
    u8 pad00[0x30];
    float r;           /* 0x30 */
    float dr;          /* 0x34 */
} P2Wave;

typedef struct P2Ring {
    u8 pad00[0x30];
    float a;           /* 0x30 */
    float da;          /* 0x34 */
    float dda;         /* 0x38 */
    float scale;       /* 0x3C */
    float r;           /* 0x40 */
    float dr;          /* 0x44 */
    float ddr;         /* 0x48 */
    float step;        /* 0x4C */
} P2Ring;

extern float D_004F4610[];

void func_002B56D8(void *dst, void *a, void *b);
void func_002B58B0(int *dst, void *m, float *v);
float op_deg_get(float *v, float x0, float z0, float x1, float z1);

#define SINI(i) D_004F4610[(i)]

P2Prim *func_01B03C28(P2Wave *wv, P2Ring *rg, u_long64 *tex, P2Mesh *out, void *m0, void *m1, void *m2)
{
    float m[4][4];
    int scr[4];
    float v[4];
    P2Prim *pr;
    P2PrimHdr *hdr;
    P2Vtx *vp;
    P2Vtx *np;
    int i;
    int j;
    int a;
    int c;
    int h;
    int prev;
    union {
        u_long64 l;
        u32 w[2];
    } col;
    int cur;
    float r;
    float dr;
    float ang;
    float t;
    float rEnd;
    float aEnd;
    float r0;
    float dr0;
    float a0;
    float da0;
    float sn;
    float cs;
    float deg;
    float R;
    float ox;
    float oy;
    float x0;
    float x1;
    float y0;
    float y1;
    float kx;
    float ky;
    float sc;
    float s0;
    float c0;
    float s1;
    float c1;

    pr = out->prim;
    hdr = &out->hdr;
    out->nvtx = 0x400;
    out->vtx_ofs = 0xC040;
    out->nrm_ofs = 0x10450;
    out->h14 = 0x441;
    out->h12 = 0x441;
    out->w0 = 0x10;
    out->w4 = 0x20;
    hdr->term = 7;
    hdr->tex = *tex;
    hdr->count = out->nvtx;
    np = (P2Vtx *)((u8 *)out + out->nrm_ofs);
    vp = (P2Vtx *)((u8 *)out + out->vtx_ofs);
    for (i = 0; i < 33; i++) {
        r = wv->r;
        t = 0.0f;
        ang = t;
        for (j = 0; j < 33; j++) {
            a = (int)(i * 128.0f + ang) & 0xFFF;
            c = (a + 0x400) & 0xFFF;
            np->x = SINI(c);
            np->y = SINI(a);
            np++;
            sn = SINI(a) * t;
            cs = SINI(c) * t;
            vp->y = sn;
            vp->x = cs;
            vp++;
            r += wv->dr;
            ang += rg->step;
            t += r;
        }
    }

    r = rg->r;
    dr = rg->dr;
    ang = rg->a;
    t = rg->da;
    r0 = r;
    dr0 = dr;
    a0 = ang;
    da0 = t;
    for (j = 0; j < 33; j++) {
        dr += rg->ddr;
        t += rg->dda;
        r += dr;
        ang += t;
    }
    rEnd = r;
    aEnd = ang;
    r = r0;
    dr = dr0;
    ang = a0;
    t = da0;
    for (i = 0; i < 33; i++) {
        P2Vtx *p = (P2Vtx *)((u8 *)out + out->vtx_ofs) + i;

        a = (int)(aEnd - ang) & 0xFFF;
        sn = SINI(a) * (rEnd - r);
        if (a < 0x800) {
            h = a / 2;
        } else {
            h = (a - 0x800) / 2;
        }
        cs = SINI(h + 0x200);
        VU0_SQRT(cs, cs * cs);
        for (j = 0; j < 33; j++) {
            p->z = sn;
            p->w = 1.0f;
            p += 33;
        }
        dr += rg->ddr;
        t += rg->dda;
        r += dr;
        ang += t;
    }

    {
        P2Vtx *p = (P2Vtx *)((u8 *)out + out->vtx_ofs);

        deg = op_deg_get(0, p[0].x, p[0].z, p[1].x, p[1].z);
    }
    prev = ((int)deg - 0x400) & 0xFFF;
    for (i = 0; i < 33; i++) {
        P2Vtx *p;

        if (i == 0) {
            cur = prev;
        } else if (i == 32) {
            cur = ((int)deg - 0x400) & 0xFFF;
        } else {
            p = (P2Vtx *)((u8 *)out + out->vtx_ofs) + i;
            deg = op_deg_get(0, p[1].x, p[1].z, p[0].x, p[0].z);
            cur = ((int)deg - 0x400) & 0xFFF;
        }
        if (prev >= 0x800) {
            prev -= 0x1000;
        }
        if (cur >= 0x800) {
            cur -= 0x1000;
        }
        prev = ((cur + prev) / 2) & 0xFFF;
        p = (P2Vtx *)((u8 *)out + out->nrm_ofs) + i;
        sn = SINI(prev);
        cs = SINI((prev + 0x400) & 0xFFF);
        for (j = 0; j < 33; j++) {
            p->z = cs;
            p->x = p->x * sn;
            p->y = p->y * sn;
            p += 33;
        }
    }

    R = 0.0f;
    r = wv->r;
    for (j = 0; j < 33; j++) {
        r += wv->dr;
        R += r;
    }
    func_002B56D8(m, m1, m0);
    func_002B56D8(m, m2, m);
    SQ_ZERO(v);
    func_002B58B0(scr, m, v);
    v[0] = R;
    ox = (scr[0] - 0x7000) * (1.0f / 8192.0f);
    oy = (scr[1] - 0x7300) * (1.0f / 8192.0f);
    func_002B58B0(scr, m, v);
    x0 = (scr[0] - 0x7000) * (1.0f / 8192.0f);
    v[0] = -R;
    func_002B58B0(scr, m, v);
    x1 = (scr[0] - 0x7000) * (1.0f / 8192.0f);
    SQ_ZERO(v);
    v[1] = R;
    func_002B58B0(scr, m, v);
    y0 = (scr[1] - 0x7300) * (1.0f / 8192.0f);
    v[1] = -R;
    func_002B58B0(scr, m, v);
    y1 = (scr[1] - 0x7300) * (1.0f / 8192.0f);
    x0 = x0 - ox;
    if (x0 < 0.0f) {
        x0 = 0.0f - x0;
    }
    x1 = x1 - ox;
    if (x1 < 0.0f) {
        x1 = 0.0f - x1;
    }
    y0 = y0 - oy;
    if (y0 < 0.0f) {
        y0 = 0.0f - y0;
    }
    y1 = y1 - oy;
    if (y1 < 0.0f) {
        y1 = 0.0f - y1;
    }
    ky = (y0 + y1) / (R + R);
    kx = (x0 + x1) / (R + R);
    sc = rg->scale * (1.0f / 256.0f);

    for (i = 0; i < 32; i++) {
        a = i * 128;
        c = (a + 0x400) & 0xFFF;
        s0 = SINI(a);
        c0 = SINI(c);
        s1 = SINI((a + 0x80) & 0xFFF);
        c1 = SINI((c + 0x80) & 0xFFF);
        t = 0.0f;
        r = wv->r;
        for (j = 0; j < 32; j++) {
            int k = i * 33 + j;

            pr->idx2[0] = k;
            pr->idx[0] = k;
            pr->idx[1] = k + 1;
            pr->idx[2] = k + 33;
            pr->idx[3] = k + 34;
            pr->idx2[1] = k + 1;
            pr->idx2[2] = k + 33;
            pr->idx2[3] = k + 34;
            col.l = ((u_long64)((0x80 - j * 4) & 0xFF) << 24) | 0x808080;
            col.w[0] = 0x80808080;
            pr->rgba[0] = col.w[0];
            pr->rgba[1] = col.w[0];
            pr->rgba[2] = col.w[0];
            pr->rgba[3] = col.w[0];
            pr->uv[0][0] = (int)((c0 * t * kx * sc + ox) * 4096.0f);
            pr->uv[0][1] = (int)((s0 * t * ky * sc + oy) * 4096.0f);
            pr->uv[2][0] = (int)((c1 * t * kx * sc + ox) * 4096.0f);
            pr->uv[2][1] = (int)((s1 * t * ky * sc + oy) * 4096.0f);
            r += wv->dr;
            t += r;
            pr->uv[1][0] = (int)((c0 * t * kx * sc + ox) * 4096.0f);
            pr->uv[1][1] = (int)((s0 * t * ky * sc + oy) * 4096.0f);
            pr->uv[3][0] = (int)((c1 * t * kx * sc + ox) * 4096.0f);
            pr->uv[3][1] = (int)((s1 * t * ky * sc + oy) * 4096.0f);
            pr++;
        }
    }
    ((P2PrimHdr *)pr)->term = -1;
    return (P2Prim *)((u8 *)out + out->nrm_ofs + out->h14 * 16);
}
