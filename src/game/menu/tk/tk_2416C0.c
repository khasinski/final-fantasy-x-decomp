/* tu_268 0x2416c0-0x242040: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2416C0", func_002416C0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2416C0", func_002417D8);

u64 *func_00241EE8(u64 *p, int x, int y, int w, u32 c0, u32 c1)
{
    int x1;

    x = x * 16 + 0x7000;
    x1 = x + w * 16;
    y = y * 16 + 0x7300;
    p[0] = 0x6400000000008001;
    p[1] = 0xF51510;
    p[2] = 0x1C9;
    p[3] = c0;
    p[4] = x | ((long)y << 16);
    p[5] = c1;
    p[6] = x1 | ((long)y << 16);
    p[7] = 0;
    return p + 8;
}

void *func_00241F60(void) {
    return D_00572FD0;
}

void func_00241F70(int v) {
    D_0069BB84 = v;
}

int TkMn2GetMenuMode(void) {
    return D_0069A87C;
}

int TkMenuGetDrawShadeRatio(void) {
    return D_0069A7FC;
}

void func_00241FA0(int v) {
    D_0069A7FC = v;
}

void func_00241FB0(int v) {
    D_0069A800 = v;
}

SysIf * func_00241FC0(void) {
    return D_0069A7F4;
}

void func_00241FD0(int v) {
    D_0069A7F0 = v;
}

int func_00241FE0(void) {
    return D_0069A7F0;
}

void TkMenuFullDaiji(void) {
    int i;

    for (i = 0; i < TkMenuImportantListMax(); i++) {
        TkMsImportantSet(i + 0xA000);
    }
}
