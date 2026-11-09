/* tu_027 0x119f30-0x11a428: medium; unk_119F30 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

int func_00119F30(R0Sort *a, R0Sort *b)
{
    int kb = 1;
    int ka = 1;

    if (a->b0C == 2 || a->b0C == 0x12) {
        ka = 0;
    }
    if (b->b0C == 2 || b->b0C == 0x12) {
        kb = 0;
    }
    if (ka != kb) {
        return ka - kb;
    }
    return b->w04 - a->w04;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_119F30", func_00119F90);

typedef struct {
    s32 w0;
    u32 w4;
    s32 w8;
    s32 wC;
} Rec16_119F30;

extern char D_00569AC0[];
extern s32 D_005804D4;
extern s32 D_005804D8;
extern Rec16_119F30 *D_005804DC;
extern char *D_005804E0;

char *func_0011A330(u32 a)
{
    Rec16_119F30 *p;
    s32 n;

    D_005804E8 = 0;
    if (D_005804E4 == 0) {
        return D_00569AC0;
    }
    p = &D_005804DC[D_005804D4];
    n = D_005804D8;
    for (n--; n != -1; n--, p++) {
        if (a >= p->w4) {
            D_005804E8 = (Triple *)p;
            return D_005804E0 + p->w0;
        }
    }
    return D_00569AC0;
}

s32 func_0011A3C8(void)
{
    if (D_005804E8 == 0) {
        return 0;
    }
    if (D_005804E4 == 0) {
        return 0;
    }
    return D_005804E8->w4;
}

s32 func_0011A3F8(void)
{
    if (D_005804E8 == 0) {
        return 0;
    }
    if (D_005804E4 == 0) {
        return 0;
    }
    return D_005804E8->w8;
}
