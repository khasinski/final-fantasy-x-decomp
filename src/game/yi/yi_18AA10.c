/* tu_136 0x18aa10-0x18b680: low; ~yiClutAlloc (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/v2.h"

INCLUDE_ASM("build/ee_asm/game/yi/yi_18AA10", func_0018AA10);

int func_0018AAB8(void) {
    return D_0065FD28;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_18AA10", func_0018AAC8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18AA10", func_0018ABA8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18AA10", func_0018ADB8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18AA10", func_0018AFE8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18AA10", yiClutAlloc_makepacket);

void func_0018B558(R2Sys460 *o, R2Quad *src, int idx) {
    R2Quad *d = o->rec[idx].q;
    int i;

    for (i = 0; i < 64; i++) {
        d[i].a = src[i].a;
        d[i].b = src[i].b;
        d[i].c = src[i].c;
        d[i].d = src[i].d;
    }
}

void func_0018B5A8(R2Sys460 *o, R2Quad *src, int idx, int sub) {
    R2Quad *d = &o->rec[idx].q[(sub / 2) * 8 + (sub % 2) * 2];

    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
    src++;
    d++;
    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
    src++;
    d += 3;
    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
    src++;
    d++;
    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
}
