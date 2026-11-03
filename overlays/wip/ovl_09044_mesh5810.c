/* WIP (p3, TU rank 25, file09044 0x01B05810..0x01B05C44, 131 containers). NOT MATCHING.
 * func_01B05810 matches on its own (overlays/group11/ovl_09044_ops5810.c). func_01B05870 (sphere grid
 * mesh) has the right structure, but gcc hoists the loop float constants (13, 104, 8, 128) into
 * f27..f29, while the target rematerializes them inside the loops. The loop shapes probably differ. */
#include "p3_overlay.h"

void func_002B5318(void *dst, void *m, float *pos);
void op_unit_m_scale(void *m, float scale);
double func_002E9290(double x);   /* sqrt */

void func_01B05870(P3Thread *th, ScriptSub *sub);

s16 *func_01B05810(P3Thread *th, s16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0:
        sub->hC0 = 0;
        pc += 1;
        break;
    case 0x1000:
        func_01B05870(th, sub);
        pc += 1;
        break;
    }
    return pc;
}

void func_01B05870(P3Thread *th, ScriptSub *sub)
{
    P3Mesh *md = (P3Mesh *)th->obj300.md;
    P3Req *req = &th->req;
    P3MeshPrim *prim = &md->prim;
    P3MeshQuad *q;
    s16 *v;
    int i;
    int j;
    float r;
    float k;
    float fy;
    float fx;
    float d;
    float s;

    md->w00 = 0;
    md->ofs_prim = (u8 *)prim - (u8 *)md;
    md->ofs_vtx = (u8 *)md->vtx - (u8 *)md;
    md->w0C = 0;
    md->nquad = 0x200;
    md->h12 = 0x800;
    md->h14 = 0;
    md->h16 = 0x88;
    prim->b0 = 0;
    prim->type = 6;
    prim->n = md->nquad;
    prim->tag = 0x4000000664A21A00LL;
    q = md->quad;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 32; j++) {
            q->col[0] = 0x80808080;
            q->col[1] = 0x80808080;
            q->col[2] = 0x80808080;
            q->col[3] = 0x80808080;
            q->vi[0] = i * 33 + j;
            q->vi[1] = i * 33 + j + 1;
            q->vi[2] = (i + 1) * 33 + j;
            q->vi[3] = (i + 1) * 33 + j + 1;
            q->uv[0][0] = j << 7;
            q->uv[0][1] = i * 0xD0;
            q->uv[1][0] = (j + 1) << 7;
            q->uv[1][1] = i * 0xD0;
            q->uv[2][0] = j << 7;
            q->uv[2][1] = (i + 1) * 0xD0;
            q->uv[3][0] = (j + 1) << 7;
            q->uv[3][1] = (i + 1) * 0xD0;
            q++;
        }
    }
    ((P3MeshPrim *)q)->type = -1;

    v = md->vtx;
    r = sub->v30[0];
    k = sub->v30[1] / 256;
    for (i = 0; i <= 16; i++) {
        fy = i * 13.0f - 104.0f;
        for (j = 0; j <= 32; j++) {
            fx = j * 8.0f - 128.0f;
            d = func_002E9290(fx * fx + fy * fy + r * r);
            s = (d - (d - sub->v30[0]) * k) / d;
            v[2] = -(int)(r * s * 128.0f);
            v[0] = fx * s * 128.0f;
            v[1] = fy * s * 128.0f;
            v += 3;
        }
    }

    req->rgba.w = sub->wC8;
    th->req.w00 = 0x90;
    req->w0C = 0;
    req->w1C = 0;
    req->w04 = (int)md->vtx + 0x8000;
    req->ofs.d = 0;
    req->d38 = 0;
    req->h08 = sub->hC2;
    req->p20 = th->mC0;
    req->w44 = 0;
    req->w40 = *(int *)&sub->hC4; /* DEBT(CAST): ScriptSub 0xC4 read as one word */
    op_unit_m_scale(th->m80, sub->f3C * (1.0f / 0x200000));
    func_002B5318(th->m80, th->m80, &sub->f90);
    func_002B56D8(th->m80, opus_local_get(th, sub), th->m80);
    func_002B56D8(th->mC0, th->m2C0, th->m80);
    req->w34 = th->obj300.w54;
    th->obj300.w54 = op1_md_draw(md, req);
}
