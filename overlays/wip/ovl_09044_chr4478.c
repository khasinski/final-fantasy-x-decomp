/* WIP (p3, TU rank 30, file09044 0x01B04478..0x01B04818, 131 containers). NOT MATCHING.
 * Structure matches; remaining diff is register allocation in case 0x1000: the target keeps
 * pc + 8 in a separate pseudo (s3, copied to s7 on both loop exits), spills th->mC0 / th->m80 /
 * list / res / ml to 0xE0..0xF0 and keeps mr in fp. Shared alpha/loop counter `i` and the separate
 * opus_local_get statement were needed to get this close. */
#include "p3_overlay.h"

void func_01B04818(int id, P3Req *req, ScriptSub *sub, ScriptSub *o, void *buf);

s16 *func_01B04478(P3Thread *th, s16 *pc)
{
    int buf[8];
    float mw[4][4];
    float ml[4][4];
    float mr[4][4];
    ScriptSub *sub = th->sub;
    float scale = 256.0f;
    int res = th->res[sub->b1E];
    ScriptSub *o = opus_no_get(&th->obj300, sub, pc[1]);
    P3Req *req;
    P3PartList *list;
    P3PartEnt *e;
    int i;
    float *pos;
    void *loc;

    if (th->flags & 0x800) {
        scale = o->f3C;
    }
    switch (th->flags & 0xF000) {
    case 0x1000:
        req = &th->req;
        list = rcefChrDraw(req, th, &th->obj300, sub, pc[3]);
        pos = &sub->f90;
        func_002B0DC8(req, th, &th->obj300, sub, pc + 3);
        loc = opus_local_get(th, sub);
        func_002B56D8(ml, th->m2C0, loc);
        e = list->ent;
        req->ofs.s.x = (int)o->f90 << 16;
        req->ofs.s.y = (int)o->f94 << 16;
        i = o->f4C;
        if (i >= 0xFF) {
            i = 0xFF;
        }
        if (i < 0) {
            i = 0;
        }
        req->rgba.w = o->wC8;
        req->rgba.b[3] = i;
        opus_rt_m_chara(mr, sub->b18, sub->v30, pos, th->b21E, scale);
        opus_rt_m_chara(th->m80, sub->b18, o->v30, pos, th->b21E, scale);
        func_002A4318(res, pc[2], buf);
        req->p2C = mw;
        pc += 8;
        for (i = list->n; i > 0; i--) {
            func_002B56D8(mw, mr, e->mtx);
            func_002B56D8(th->mC0, ml, mw);
            func_002B56D8(mw, th->m80, e->mtx);
            func_01B04818(e->id, req, sub, o, buf);
            e++;
        }
        break;
    case 0x2000:
        req = &th->req;
        list = rcefChrDraw(req, th, &th->obj300, sub, pc[3]);
        pos = &sub->f90;
        loc = opus_local_get(th, sub);
        func_002B56D8(ml, th->m2C0, loc);
        req->ofs.s.x = (int)o->f90 << 16;
        req->ofs.s.y = (int)o->f94 << 16;
        i = o->f4C;
        if (i >= 0xFF) {
            i = 0xFF;
        }
        if (i < 0) {
            i = 0;
        }
        req->rgba.w = o->wC8;
        req->rgba.b[3] = i;
        req->w1C = sub->wC8;
        opus_rt_m_chara(mr, sub->b18, sub->v30, pos, th->b21E, scale);
        opus_rt_m_chara(th->m80, sub->b18, o->v30, pos, th->b21E, scale);
        func_002A4318(res, pc[2], buf);
        pc += 4;
        func_002B7CE8(list, req, mr, 0, 0, buf, th->m80, sub->f3C * 16.0f);
        break;
    }
    return pc;
}
