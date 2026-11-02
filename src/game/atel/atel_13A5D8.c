/* tu_070 0x13a5d8-0x13a7e0: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A5D8", AtelGetActorBufferSize);

ActorState *AtelGetPosWorkAdrs(Actor *a) {
    switch (a->hdr->type) {
    case 5:
    case 6:
        return (ActorState *)((u8 *)a + 0x284); /* DEBT(CAST): state block offsets inside Actor padding */
    case 4:
        return 0;
    default:
        return (ActorState *)((u8 *)a + 0x558); /* DEBT(CAST) */
    }
}

void func_0013A6D8(int id) {
    Effect *e = AtelGetMesWinWork(id);
    int kind = e->kind;

    e->b1E = -1;
    e->b1F = -1;
    if (kind != 0) {
        if (kind != 3) {
            e->kind = 3;
            TOCloseMessageWindow(id);
        }
    }
}

int AtelSetUpMesWin(Effect *e, int flags) {
    EffectQ *q = (EffectQ *)e; /* DEBT(CAST): see EffectQ */
    int lo;
    int hi;

    if (flags & 2) {
        lo = q->h16 & 0xF;
        hi = q->h16 >> 8;
        if (lo == 0) {
            q->b22 = 0;
            flags &= ~0x40;
            q->b23 = 0;
        } else {
            if (q->b22 >= lo) {
                q->b22 = lo - 1;
            }
            if (q->b23 >= lo) {
                q->b23 = lo - 1;
            }
        }
        if (hi == 0) {
            q->b1E = 0;
            flags &= ~2;
            q->b1F = 0;
        } else {
            if (q->b1E >= hi) {
                q->b1E = hi - 1;
            }
            if (q->b1F >= hi) {
                q->b1F = hi - 1;
            }
        }
    }
    return flags;
}
