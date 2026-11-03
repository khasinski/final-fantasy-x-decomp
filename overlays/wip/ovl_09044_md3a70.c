/* WIP (p3, TU rank 47, file09044 0x01B03A70..0x01B03C28, 131 containers). NOT MATCHING.
 * Remaining diff (4 insns): after func_002B0178 the constants 0x44C / 0x01F80000 get v0/v1 swapped
 * (target: li v1,0x44C; lui v0,0x1F8). Tried every order of the w00/w04/w1C stores and int/ptr/union
 * field types; local-alloc priority still prefers 0x44C. The P3Req.rect union is required: it
 * makes the s16 stores alias the ScriptSub float load like the target schedule. */
#include "p3_overlay.h"

void func_01B03C28(ScriptSub *sub, ScriptSub *o, int *buf, int *md, void *mtx, void *m0, void *m1);

void func_01B03A70(P3Obj300 *obj, ScriptSub *sub, ScriptSub *o, int *buf, s16 *pc, void *mtx, void *m0, void *m1)
{
    P3Thread *w = func_002B3888(0x400);
    int *md = obj->md;
    P3Req *req;

    func_01B03C28(sub, o, buf, md, mtx, m0, m1);
    req = &w->req;
    func_002B0178(req, w, obj, sub, -1);
    w->req.w00 = 0x44C;
    req->w04 = 0x01F80000;
    req->w1C = 0;
    func_002B0400(req, w, obj, sub, pc);
    req->b4C = sub->f3C * 0.5f;
    req->b4D = sub->f4C * 0.5f;
    req->rect.s.x0 = 1;
    req->rect.s.y0 = 0x1FF;
    req->rect.s.x1 = 1;
    req->rect.s.y1 = 0x19F;
    if ((*buf & 0x3FFF) >= 0x3400) {
        *md = (*md & ~0x10) | 4;
    } else {
        *md = (*md | 0x10) & ~4;
    }
    op_m_copy(w->m80, mtx);
    func_002B56D8(w->mC0, m0, w->m80);
    func_002B56D8(w->mC0, m1, w->mC0);
    op1_md_draw(md, req);
    func_002B39C0(0x400);
}
