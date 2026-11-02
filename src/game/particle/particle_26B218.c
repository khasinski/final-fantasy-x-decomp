/* tu_291 0x26b218-0x26bde0: low; unk_26B218 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/t6.h"

INCLUDE_ASM("build/ee_asm/game/particle/particle_26B218", func_0026B218);

void func_0026B318(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h2 = w->h0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26B218", func_0026B338);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26B218", func_0026B430);

void func_0026B648(void) {
}

void func_0026B650(void) {
}

void func_0026B658(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h2 = w->h0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26B218", func_0026B678);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26B218", func_0026B730);

void func_0026B948(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h2 = w->h0 = 0;
}

void func_0026B968(ScriptWork *base, V6EvRefC *ev, u16 h)
{
    T6_MemEnt *e;
    T6_Mem *m;

    if (ev->idx != 0xFFFFFFFF) {
        e = &ppvMng->p3C[ev->idx];
        if (e == 0) {
            m = 0;
        } else {
            m = func_00267320(ppvMng, e);
            if (m == 0) {
                return;
            }
            m->user = base;
        }
        *(u16 *)((char *)m + (ev->ofs + 0xA0)) = h; /* DEBT(CAST): work field of the other memory */
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26B218", func_0026B9F8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26B218", func_0026BB78);

void func_0026BD48(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8 *w = SLOT_WORK(Wkf0f4f8, base, ctx, 0);

    w->f0 = w->f4 = w->f8 = 0.0f;
}

void func_0026BD70(char *base, ScriptCtx *ctx)
{
    Wkf0f4f8wC *w = SLOT_WORK(Wkf0f4f8wC, base, ctx, 0);

    w->f0 = w->f4 = w->f8 = 0.0f;
    w->wC = 0;
}

void func_0026BD98(char *base, ScriptCtx *ctx) {
    R6HeapRef1 *w = SLOT_WORK(R6HeapRef1, base, ctx, 0);

    if (w->pC != 0) {
        func_00267028(D_006A3924, D_006A3924->sub, w->pC);
        w->pC = 0;
    }
}
