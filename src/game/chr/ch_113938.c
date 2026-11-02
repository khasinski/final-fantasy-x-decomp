/* tu_020 0x113938-0x113ff8: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

void func_00113938(s16 v)
{
    D_0057F620 = v;
}

void func_00113948(s16 v)
{
    D_0057F624 = v;
}

void func_00113958(s16 v)
{
    D_0057F628 = v;
}

void func_00113968(s16 v)
{
    D_0057F62C = v;
}

typedef struct G0Slot16 {
    s8 b0;
    s8 b1;
    s16 h2;
    s32 w4;
    void *p8;
    s32 wC;
} G0Slot16; /* DEBT(NAME) */

void func_00113978(void)
{
    G0Slot16 *s = (G0Slot16 *)D_0057F60C; /* DEBT(CAST) */

    if (s != 0) {
        s->b0 = 0;
        s->b1 = -1;
        s->wC = 0;
        s->p8 = 0;
        s->h2 = 0;
        D_0057F60C += 0x10;
    } else {
        D_0057F610 += 0x10;
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113938", Ch_EffectPacketStorePoly);

s32 func_00113EE8(void)
{
    return D_0057F60C;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113938", Ch_EffectPacketSetPtr);

s32 Ch_EffectPacketGetSize(void)
{
    return D_0057F610;
}
