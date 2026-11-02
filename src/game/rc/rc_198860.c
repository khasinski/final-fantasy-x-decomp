/* tu_155 0x198860-0x198cd8: medium; unk_198860 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

int func_00198860(int *p) {
    return p[5] + 0x20;
}

void func_00198870(void *p)
{
    func_002EF0D0(p, 0, 0x10);
}

void func_00198880(void *p)
{
}

void func_00198888(W3Blk *b, int n)
{
    b->img = func_00199ED8();
    func_00199FD8(b->img, 0x2E00, 1, 0, 0, 0, 0x10, 0x10, n + 1);
}

int func_001988E8(int *p) {
    return func_0019A408(p[3]);
}

void func_00198908(W3Blk *n) {
    if (n->flags & 1) {
        func_00198A68(n);
        return;
    }
    switch (n->b0A) {
    case 1:
        func_00198AE8(n);
        break;
    case 2:
        func_00198BC8(n);
        break;
    default:
        func_00198978(n);
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/rc_198860", func_00198978);

INCLUDE_ASM("build/ee_asm/game/rc/rc_198860", func_00198A68);

INCLUDE_ASM("build/ee_asm/game/rc/rc_198860", func_00198AE8);

INCLUDE_ASM("build/ee_asm/game/rc/rc_198860", func_00198BC8);

void func_00198CA8(W3Blk *blk, int v) {
    ((short *)blk)[4] = v; /* DEBT(CAST): W3Blk is opaque */
}

int func_00198CB0(Q3Ctx *c) {
    Q3Ctx2 *s = c->sub;

    return func_0019A408(s, s->w30 - 1);
}
