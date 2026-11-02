/* tu_347 0x2d98a8-0x2dba00: low; libgraph; split at 0x2d98a8: library split: 0x2D9730-0x2D98A8 is FFX platform glue (FFXIsPC, FFXGetLang, FFXSetVideoMode: Switch-port names), 0x2D98A8 is sceGsResetGraph (libgraph); tu_map's low boundary 0x2D9730 put both in one TU (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/g4.h"
#include "ffx/r7.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D98A8);

u8 *func_002D9A38(void)
{
    return D_00566210;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9A48);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9AB0);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9D20);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9DE0);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9EA8);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA090);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA198);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA280);

/* Module: sound/vu glue */

int func_002DA518(u8 *base, int side)
{
    int ret;

    side &= 1;
    func_002D9D20(base + side * 0x28);
    if (side != 0) {
        ret = func_002DA198(base + 0x140);
    } else {
        ret = func_002DA198(base + 0x50);
    }
    return ret;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA578);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA610);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA928);
INCLUDE_RODATA("build/ee_asm/sdk/libgraph/libgraph/rodata", jtbl_005766B0);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DAB10);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DAC50);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DADD0);
INCLUDE_RODATA("build/ee_asm/sdk/libgraph/libgraph/rodata", jtbl_005768C0);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DB460);

/* Module: sound/misc glue, VU0 helpers */

int func_002DB640(u8 *base, int side)
{
    int ret;

    side &= 1;
    func_002D9D20(base + side * 0x28);
    if (side != 0) {
        ret = func_002DA198(base + 0x1C0);
    } else {
        ret = func_002DA198(base + 0x50);
    }
    return ret;
}

void func_002DB6A0(u8 *p, int n)
{
    while (n-- != 0) {
        *p++ = 0;
    }
}

u32 *func_002DB6D8(int id)
{
    if ((u32)id < 10) {
        return (u32 *)D_00566250[id]; /* DEBT(TYPE): callers take the channel as u32 * */
    }
    return 0;
}

int func_002DB700(int mode)
{
    u32 env[5];
    int old = V7_D_CTRL & 1;
    int i;

    for (i = 0; i < 10; i++) {
        if (D_00566290[i] != 0) {
            volatile V7DmaChan *ch = D_00566250[i];
            ch->sadr = 0;
            ch->chcr = 0;
            ch->tadr = 0;
            ch->madr = 0;
            ch->asr1 = 0;
            ch->asr0 = 0;
        }
    }
    V7_D_STAT = 0xFF1F;
    V7_D_STAT_W = V7_D_STAT & 0xFF1F0000;
    func_002DB6A0((u8 *)env, sizeof(env));
    func_002DB7F0(env);
    if (mode == 1) {
        V7_D_CTRL |= 1;
    }
    return old;
}

int func_002DB7E0(int v)
{
    int old = D_00566278;

    D_00566278 = v;
    return old;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DB7F0);

R7Blk20 *func_002DB9C8(R7Blk20 *d)
{
    *d = D_005662E8;
    return d;
}
