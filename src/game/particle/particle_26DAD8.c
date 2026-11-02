/* tu_294 0x26dad8-0x26f218: low; unk_26DAD8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/q6.h"

void func_0026DAD8(char *base, u32 *k, ScriptCtx *ctx)
{
    U4VecSrc *w;

    if (D_006A3BC4 == 0) {
        w = SLOT_WORK(U4VecSrc, base, ctx, 0);
        if (k[0] == ((u32 *)base)[3]) { /* DEBT(CAST): owner id at 0xC of the script object */
            if (k[1] != 0xFFFFFFFF) {
                w->src = (float *)(ppvMng->p3C[k[1]].base + (k[2] + 0xA0));
            } else {
                w->src = (float *)D_006EA450;
            }
        }
        w->v[0] = w->src[0];
        w->v[1] = w->src[1];
        w->v[2] = w->src[2];
    }
}

void func_0026DB70(int base, ScriptCtx *ctx)
{
    ScriptWorkFlags *w = (ScriptWorkFlags *)(ctx->info->slot[1] + base); /* DEBT(CAST): script memory base arrives as an int */

    w->bA1 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026DB88);

void func_0026DC70(int base, ScriptCtx *ctx)
{
    ScriptWorkFlags *w = (ScriptWorkFlags *)(ctx->info->slot[1] + base); /* DEBT(CAST): see func_0026DB70 */

    w->bA1 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026DC88);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026DE80);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026DF60);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E048);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E130);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E220);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E318);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E410);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E500);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E5F8);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E6F0);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E838);

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026E958);

float func_0026EA78(float a, float b) {
    return a * b - a;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026EA88);

float func_0026EBB8(float a, float b) {
    return a * b;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026EBC0);

float func_0026ED00(float a, float b) {
    return a * b;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026ED08);

int func_0026EE48(int a, float s) {
    return a * s - a;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026EE68);

int func_0026EF88(int a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026EFA8);

int func_0026F0D0(int a, float s) {
    return a * s;
}

INCLUDE_ASM("build/ee_asm/game/particle/particle_26DAD8", func_0026F0F0);
