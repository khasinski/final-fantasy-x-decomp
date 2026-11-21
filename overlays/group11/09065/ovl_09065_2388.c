/* EE Battle-Effect Overlay: group 0x11, file 09065 (shared by ~131 p4 overlays)
 * .text: 0x01B02388..0x01B025E0 (1 function, 600B).
 */
#include "p4_overlay.h"

extern P4Env D_01B006A0;

u16 *func_01B02388(P4Thread *th, u16 *pc)
{
    P4List *list;
    P4Prm *prm;
    P4Xform *xf;
    u16 o1;
    u16 o2;
    u16 o3;
    float *p1;
    float *p2;
    float *p3;
    P4Prm *sub;

    list = &th->draw_list;
    o1 = pc[1];
    prm = th->prm;
    o2 = pc[2];
    o3 = pc[3];
    p1 = (float *)((u8 *)prm + o1);
    p2 = (float *)((u8 *)prm + o2);
    p3 = (float *)((u8 *)prm + o3);
    xf = D_01B006A0.xf;

    switch (th->h21A & 0xF000) {
    case 0x0000:
        sub = opus_no_get(list, prm, (s16)o1);
        if (sub->state == 3) {
            list->vt->draw(list, sub->shards, o2, o3);
        }
        pc += 4;
        break;
    case 0x1000:
        op_unit_m_scale2(th->mtx, xf->scale);
        pc += 1;
        func_002B55F0(th->mtx, th->mtx, xf->rot, xf->pos);
        th->pos[0] = D_01B006A0.pos[0];
        th->pos[1] = D_01B006A0.pos[1];
        th->pos[2] = D_01B006A0.pos[2];
        func_002B5880((float *)((u8 *)prm + 0x90), th->mtx, th->pos);
        func_002B5978((float *)((u8 *)prm + 0x40), (float *)((u8 *)prm + 0x90), 16.0f);
        break;
    case 0x2000:
    {
        /* DEBT(FAKE): pin tex pointer to v0 to match ee-gcc v0/v1 choice */
        register s32 *tex __asm__("$2");
        op_unit_m(th->mtx);
        func_002B55F0(th->mtx, th->mtx, xf->rot, xf->pos);
        tex = D_01B006A0.tex;
        if (o1 != 0) {
            *p1 = (float)((tex[0] >> 4) & 0xFFF);
        }
        if (o2 != 0) {
            *p2 = (float)((tex[1] >> 4) & 0xFFF);
        }
        if (o3 != 0) {
            *p3 = (float)((tex[2] >> 4) & 0xFFF);
        }
        pc += 4;
        break;
    }
    case 0x3000:
        pc += 2;
        *p1 = xf->scale[0] * (*D_01B006A0.fscale) * 2097152.0f;
        break;
    }
    return pc;
}
