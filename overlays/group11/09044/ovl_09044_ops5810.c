#include "p3_overlay.h"

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
