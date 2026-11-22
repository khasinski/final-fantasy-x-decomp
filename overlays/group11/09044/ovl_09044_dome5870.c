#include "p1_overlay.h"

double func_002E9290(double x);
void op_unit_m_scale(void *m, float s);
int op1_md_draw(void *md, void *req);

typedef struct DomeMdHdr {
    u32 flags;
    u32 prim_off;
    u32 vtx_off;
    u32 norm_off;
    s16 nprim;
    s16 nvtx;
    s16 nnorm;
    s16 h16;
    u8 pad18[8];
} DomeMdHdr;

typedef struct DomePrimHdr {
    u8 b0;
    u8 b1;
    u16 nprim;
    u32 w4;
    unsigned long tex0;
} DomePrimHdr;

typedef struct DomeQuad {
    u32 rgba[4];
    s16 idx[4];
    s16 u0, v0;
    s16 u1, v1;
    s16 u2, v2;
    s16 u3, v3;
} DomeQuad;

typedef struct DomeReq {
    u32 w0;
    void *p4;
    u16 h8;
    u16 hA;
    u32 wC;
    unsigned long q10;
    u32 w18;
    u32 w1C;
    void *p20;
    void *p24;
    void *p28;
    void *p2C;
    u32 w30;
    u32 w34;
    unsigned long q38;
    u32 w40;
    void *w44;
} DomeReq;

void func_01B05870(P1Th *th, P1Sub *sub)
{
    void *vtx_end;
    P1Obj300 *obj300 = &th->obj300;
    u8 *md = obj300->model;
    DomeMdHdr *mh = (DomeMdHdr *)md;
    DomePrimHdr *ph = (DomePrimHdr *)(md + 0x20);
    DomeQuad *q = (DomeQuad *)(md + 0x30);
    s16 *vtx = (s16 *)(md + 0x5040);
    DomeReq *req = (DomeReq *)((u8 *)th + 0x100);
    int y, x;
    float z0, z0sq, scale;

    vtx_end = (u8 *)vtx + 0x8000;
    mh->prim_off = (u8 *)ph - md;
    mh->vtx_off = (u8 *)vtx - md;
    mh->nprim = 0x200;
    mh->nvtx = 0x800;
    mh->h16 = 0x88;
    mh->nnorm = 0;
    mh->flags = 0;
    mh->norm_off = 0;

    ph->b0 = 0;
    ph->b1 = 6;
    ph->tex0 = 0x4000000664A21A00ULL;
    ph->nprim = mh->nprim;

    for (y = 0; y < 16; y++) {
        int v0 = y * 208;
        int v1 = v0 + 208;

        for (x = 0; x < 32; x++, q++) {
            q->idx[0] = y * 33 + x;
            q->idx[1] = y * 33 + x + 1;
            q->idx[2] = (y + 1) * 33 + x;
            q->idx[3] = (y + 1) * 33 + x + 1;
            q->u0 = x * 128;
            q->v0 = v0;
            q->u1 = (x + 1) * 128;
            q->v1 = v0;
            q->u2 = x * 128;
            q->v2 = v1;
            q->u3 = (x + 1) * 128;
            q->v3 = v1;
            q->rgba[0] = 0x80808080;
            q->rgba[1] = 0x80808080;
            q->rgba[2] = 0x80808080;
            q->rgba[3] = 0x80808080;
        }
    }
    ((s8 *)q)[1] = -1;

    z0 = sub->pos[0];
    z0sq = z0 * z0;
    scale = sub->pos[1] * 0.00390625f;
    for (y = 0; y < 17; y++) {
        float fy = (float)y * 13.0f - 104.0f;
        float fy2 = fy * fy;

        for (x = 0; x < 33; x++, vtx += 3) {
            float fx = (float)x * 8.0f - 128.0f;
            float d = (float)func_002E9290((double)(fx * fx + fy2 + z0sq));
            float k = (d - (d - sub->pos[0]) * scale) / d;

            vtx[0] = (s16)(fx * k * 128.0f);
            vtx[1] = (s16)(fy * k * 128.0f);
            vtx[2] = -(s16)(z0 * k * 128.0f);
        }
    }

    req->w18 = *(u32 *)&sub->color;
    *(u32 *)((u8 *)th + 0x100) = 0x90;
    req->wC = 0;
    req->w1C = 0;
    req->q10 = 0;
    req->p4 = vtx_end;
    req->q38 = 0;
    req->p20 = th->mC0;
    req->h8 = *(u16 *)((u8 *)sub + 0xC2);
    req->w44 = 0;
    req->w40 = *(u32 *)((u8 *)sub + 0xC4);

    op_unit_m_scale(th->m80, sub->f3C * (1.0f / 2097152.0f));
    func_002B5318(th->m80, th->m80, sub->rot);
    func_002B56D8(th->m80, opus_local_get(th, sub), th->m80);
    func_002B56D8(th->mC0, th->m2C0, th->m80);
    req->w34 = *(u32 *)((u8 *)obj300 + 0x54);
    *(u32 *)((u8 *)obj300 + 0x54) = op1_md_draw(md, req);
}
