/* Battle-effect overlay 09345: 0x01B00BA8..0x01B00D28 */
#include "rcef_overlay.h"

void func_001A4288(int a0);
void func_001A2F50(int chr, int bone, float *in_off, float *out_pos);
void func_001A2148(W3Task *t);
W3Task *func_0019FF90_t(RcefMainCtx *ctx, W3TaskFn fn) __asm__("func_0019FF90");

void func_01B00D28(W3Task *t);
void func_01B01328(W3Task *t);
void func_01B016C8(W3Task *t);

void func_01B00BA8(W3Task *t)
{
    float off[4];
    float pos[4];
    RcefMainCtx *c = &D_00313CB0;
    int caster = c->caster;
    RcefObj *o;

    func_001A4288(0);
    o = (RcefObj *)func_0019FF90_t(c, func_01B01328);
    o->task.frame[o->task.sp].count = 0;
    off[0] = 0.0f;
    off[1] = 23.0f;
    off[2] = 0.0f;
    off[3] = 0.0f;
    func_001A2F50(caster, 0x18, off, pos);
    o->pos[0] = pos[0];
    o->pos[1] = pos[1];
    o->pos[2] = pos[2];
    ((float *)&o->pos_w)[0] = 0.0f;

    o = (RcefObj *)func_0019FF90_t(c, func_01B01328);
    o->task.frame[o->task.sp].count = 1;
    off[0] = 0.0f;
    off[1] = -23.0f;
    off[2] = 0.0f;
    off[3] = 0.0f;
    func_001A2F50(caster, 0x25, off, pos);
    o->pos[0] = pos[0];
    o->pos[1] = pos[1];
    o->pos[2] = pos[2];
    ((float *)&o->pos_w)[0] = 0.0f;

    func_0019FF90(c, func_01B016C8);
    func_001A1D08(t, func_01B00D28);
    func_001A1D50(t, func_001A2148);
    t->frame[t->sp].count = caster;
}
