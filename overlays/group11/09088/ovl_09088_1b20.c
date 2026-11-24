#include "common.h"

typedef struct {
    s32 op;
    s32 arg;
} Cmd8;

typedef struct {
    void *w00;
    Cmd8 *cmds;
    s32 idx;
    s32 wait;
    u16 flags;
} Seq1B20;

extern void func_01B01AD8(void *, s32);

s32 ovl_09088_1b20(Seq1B20 *s0)
{
    s32 running;

    if (s0->wait > 0) {
        s0->wait--;
    }
    if (s0->wait != 0) {
        return 0;
    }

    running = 1;
    do {
        s32 idx = s0->idx;
        Cmd8 *c;
        s0->idx = idx + 1;
        c = &s0->cmds[idx];
        switch (c->op) {
        default:
            func_01B01AD8(s0->w00, c->arg);
            break;
        case 2:
            running = 0;
            s0->idx = idx;
            s0->flags |= 0x8000;
            break;
        case 1:
            running = 0;
            s0->wait = c->arg;
            break;
        }
    } while (running != 0);

    return s0->flags >> 15;
}
