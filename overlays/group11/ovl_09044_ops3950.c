#include "p3_overlay.h"

extern float D_004F4050[];

s8 func_001CE960(void);
void func_002D07A0(int res, int id, void *out);
void op_unit_m_scale(void *m, float scale);

s16 *func_01B03950(P3Thread *th, s16 *pc)
{
    int buf[8];
    ScriptSub *sub = th->sub;
    int res = th->res[sub->b1E];
    ScriptSub *o;
    void *loc;

    switch ((s16)th->flags & 0xF000) {
    case 0x1000:
        o = opus_no_get(&th->obj300, sub, pc[1]);
        func_002D07A0(res, pc[2], buf);
        op_unit_m_scale(th->m00, 1.0f / 16);
        loc = opus_local_get(th, sub);
        func_01B03A70(&th->obj300, sub, o, buf, pc + 3, th->m00, loc, D_004F4050);
        pc += 8;
        break;
    case 0x2000:
        if (func_001CE960()) {
            pc += 2;
        } else {
            pc = (s16 *)((u8 *)pc + pc[1]);
        }
        break;
    }
    return pc;
}
