/* WIP (package p4, TU rank 8 second function, file09065 0x01B01EB8, 1232 B x 129 containers).
 * Build with -O2 -Btools/cc/ee-as-delay/ -Wa,-mips4 (see overlays/units/p4.py P4_CFLAGS).
 * Remaining diff (2 insns): before `jal op_deg_get` the original schedules the argument moves as
 * f12, f14, f15, f13(=f12), a0=sp with `move a0,sp` in the delay slot; this C gives
 * ..., f15, a0, f13 and puts `mov.s f13,f12` in the slot (sched1 tie on INSN_LUID).
 * Tried: tmp array/scalar, &dist, inline helpers, zero variable, arg memory forms. The first
 * function of the TU (0x01B01890) is VU0 inline asm (lqc2/vmula/pextlh) and is not C. */
#include "p4_overlay.h"

static inline float p4_rand_add(float base, float range)
{
    return base + func_002B3DB0(range);
}

void func_01B01EB8(P4SrcModel *src, P4Shards *dst, P4Param *prm)
{
    P4SrcTri *t = src->tri;
    P4Shard *e = dst->shard;
    s16 *vtx;
    s16 *v;
    int n;
    float x0, y0, z0, x1, y1, z1, x2, y2, z2;
    float cx, cy, cz;
    float scale;
    float dist;
    float f;

    n = src->count;
    dst->count = n;
    dst->d08 = src->d28;
    dst->w00 = src->w00;
    dst->h10 = src->h16;
    vtx = (s16 *)(src->vtx_ofs + (int)src);
    for (; n > 0; n--) {
        e->uv[0] = t->uv[0];
        e->uv[1] = t->uv[1];
        e->uv[2] = t->uv[2];
        e->col[0] = t->col[0];
        e->col[1] = t->col[1];
        e->col[2] = t->col[2];
        v = vtx + t->vtx[0] * 3;
        x0 = v[0];
        y0 = v[1];
        z0 = v[2];
        v = vtx + t->vtx[1] * 3;
        x1 = v[0];
        y1 = v[1];
        z1 = v[2];
        v = vtx + t->vtx[2] * 3;
        x2 = v[0];
        y2 = v[1];
        z2 = v[2];
        cx = (x0 + x1 + x2) / 3.0f;
        cy = (y0 + y1 + y2) / 3.0f;
        cz = (z0 + z1 + z2) / 3.0f;
        e->pos[0] = cx;
        e->pos[1] = cy;
        e->pos[2] = cz;
        e->rel[0][0] = x0 - cx;
        e->rel[0][1] = y0 - cy;
        e->rel[0][2] = z0 - cz;
        e->rel[1][0] = x1 - cx;
        e->rel[1][1] = y1 - cy;
        e->rel[1][2] = z1 - cz;
        e->rel[2][0] = x2 - cx;
        e->rel[2][1] = y2 - cy;
        e->rel[2][2] = z2 - cz;
        f = prm->vel[0];
        e->vel[0] = f + func_002B3DB0(prm->vel_rnd[0]);
        f = prm->vel[1];
        e->vel[1] = f + func_002B3DB0(prm->vel_rnd[1]);
        f = prm->vel[2];
        e->vel[2] = f + func_002B3DB0(prm->vel_rnd[2]);
        f = prm->acc[0];
        e->acc[0] = f + func_002B3DB0(prm->acc_rnd[0]);
        f = prm->acc[1];
        e->acc[1] = f + func_002B3DB0(prm->acc_rnd[1]);
        f = prm->acc[2];
        e->acc[2] = f + func_002B3DB0(prm->acc_rnd[2]);
        e->rot[0] = e->rot[1] = e->rot[2] = 0.0f;
        f = prm->rvel[0];
        e->rvel[0] = f + func_002B3DB0(prm->rvel_rnd[0]);
        f = prm->rvel[1];
        e->rvel[1] = f + func_002B3DB0(prm->rvel_rnd[1]);
        f = prm->rvel[2];
        e->rvel[2] = f + func_002B3DB0(prm->rvel_rnd[2]);
        f = prm->racc[0];
        e->racc[0] = f + func_002B3DB0(prm->racc_rnd[0]);
        f = prm->racc[1];
        e->racc[1] = f + func_002B3DB0(prm->racc_rnd[1]);
        f = prm->racc[2];
        e->racc[2] = f + func_002B3DB0(prm->racc_rnd[2]);
        e->life = prm->life;
        e->wait = func_002B3D10(prm->wait_rnd) + prm->wait;
        if (dst->mode == 1) {
            e->pos[2] = op_deg_get(&dist, 0.0f, 0.0f, cx, cz);
            e->pos[0] = dist;
        }
        scale = prm->scale;
        scale *= 1.0f / 4096;
        if (dst->mode == 0) {
            e->vel[0] *= scale;
            e->vel[1] *= scale;
            e->vel[2] *= scale;
            e->acc[0] *= scale;
            e->acc[1] *= scale;
            e->acc[2] *= scale;
        }
        if (dst->mode == 1) {
            e->vel[0] *= scale;
            e->vel[1] *= scale;
            e->acc[0] *= scale;
            e->acc[1] *= scale;
        }
        t++;
        e++;
    }
}
