/* WIP (package p4, TU rank 32 func_01B01F60, file09044, 600 B x 131 containers; layout:
 * docs/overlay-tus.tsv rank 32, needs D_01B00260 per container). Build with P4_CFLAGS.
 * Remaining diff (5 blocks, case 0x2000 only): the original allocates `tex` (env->tex) to v0 and
 * the extracted values to v1; this C gives tex v1 / values v0 (local-alloc grabs v0 for the
 * block-local values first). The next function func_01B021B8 uses `sq $zero` (not emitted by
 * ee-gcc 2.9-991111-01, which gives por+sq). */
#include "p4_overlay.h"

extern P4Env D_01B00260;

u16 *func_01B01F60(P4Thread *th, u16 *pc)
{
    P4Env *env = &D_01B00260;
    P4List *list = &th->draw_list;
    u16 a = pc[1];
    P4Prm *prm = th->prm;
    u16 b = pc[2];
    u16 c = pc[3];
    float *dst0;
    float *dst1;
    float *dst2;
    P4Xform *xf;
    P4Prm *o;
    s32 *tex;

    dst0 = (float *)((u8 *)prm + a);
    dst1 = (float *)((u8 *)prm + b);
    dst2 = (float *)((u8 *)prm + c);
    xf = env->xf;
    switch (th->h21A & 0xF000) {
    case 0:
        o = opus_no_get(list, prm, a);
        if (o->state == 3) {
            list->vt->draw(list, o->shards, b, c);
        }
        pc += 4;
        break;
    case 0x1000:
        op_unit_m_scale2(th->mtx, xf->scale);
        pc += 1;
        func_002B55F0(th->mtx, th->mtx, xf->rot, xf->pos);
        th->pos[0] = env->pos[0];
        th->pos[1] = env->pos[1];
        th->pos[2] = env->pos[2];
        func_002B5880((float *)((u8 *)prm + 0x90), th->mtx, th->pos);
        func_002B5978((float *)((u8 *)prm + 0x40), (float *)((u8 *)prm + 0x90), 16.0f);
        break;
    case 0x2000:
        op_unit_m(th->mtx);
        func_002B55F0(th->mtx, th->mtx, xf->rot, xf->pos);
        tex = env->tex;
        if (a != 0) {
            *dst0 = (tex[0] >> 4) & 0xFFF;
        }
        if (b != 0) {
            *dst1 = (tex[1] >> 4) & 0xFFF;
        }
        if (c != 0) {
            *dst2 = (tex[2] >> 4) & 0xFFF;
        }
        pc += 4;
        break;
    case 0x3000:
        pc += 2;
        *dst0 = xf->scale[0] * *env->fscale * 2097152.0f;
        break;
    }
    return pc;
}
