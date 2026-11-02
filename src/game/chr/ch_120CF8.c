/* tu_039 0x120cf8-0x1229d0: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

float func_00120CF8(void)
{
    return D_00580B30;
}

s32 Sg_IdGetPtr(void)
{
    return D_00580B34;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00120D18);

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00120DE8);

int func_00120EB8(int a, int i)
{
    s16 *t = D_00308900;
    s16 *e;
    int pad[2]; /* DEBT(PADDING): unused 16-byte frame slot in the original */

    if (t == 0) {
        return -1;
    }
    if (i == -1) {
        return -1;
    }
    e = &t[i * 8];
    func_00120DE8(D_00580B2C + e[0] * 8, D_00580B2C + e[1] * 8, D_00580B2C + e[2] * 8, a);
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00120F28);

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00121038);

float func_001212E0(float x, float y, float z)
{
    float v[3];

    v[0] = x;
    v[1] = y;
    v[2] = z;
    return func_00121038(v) / D_00580B30;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00121328);

void func_00121418(float v)
{
    D_00308904 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00121428);

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_001218B0);

s32 func_00121A58(Chr *chr)
{
    return chr->w830 & 0x7F;
}

s32 Ch_IdGetMap(Chr *chr)
{
    s32 v = chr->w830 & 0x7F;

    if (v >= 0x30 && v < 0x40) {
        return D_00580B38[v - 0x30];
    }
    return v;
}

s32 func_00121AA0(Chr *chr)
{
    return (chr->w830 >> 15) & 0x3;
}

s32 func_00121AB0(Chr *chr)
{
    return (chr->w830 >> 11) & 0x3;
}

s32 Ch_IdGetEncount(Chr *chr)
{
    return (chr->w830 >> 7) & 0x3;
}

s32 func_00121AD0(Chr *chr)
{
    return (chr->w830 >> 13) & 0x3;
}

u32 Ch_IdGetShade0(Chr *chr)
{
    u32 v = chr->w830; /* DEBT(TYPE): w830 is read unsigned here */
    u16 c;

    if (Sg_IdExistShade()) {
        c = v >> 17;
    } else {
        c = 0x4210;
    }
    return c & 0x1F;
}

u32 Ch_IdGetShade1(Chr *chr)
{
    u32 v = chr->w830; /* DEBT(TYPE): w830 is read unsigned here */
    s16 c;

    if (Sg_IdExistShade()) {
        c = v >> 17;
    } else {
        c = 0x4210;
    }
    return (c >> 5) & 0x1F;
}

u32 Ch_IdGetShade2(Chr *chr)
{
    u32 v = chr->w830; /* DEBT(TYPE): w830 is read unsigned here */
    u16 c;

    if (Sg_IdExistShade()) {
        c = v >> 17;
    } else {
        c = 0x4210;
    }
    return c >> 10;
}

void func_00121B88(s32 i, s32 v)
{
    D_00580B38[i - 0x30] = v;
}

s32 func_00121BA8(s32 i)
{
    return D_00580B38[i - 0x30];
}

void func_00121BC8(void)
{
    s32 remaining;

    remaining = 0xF;
    do
    {
        remaining -= 1;
    } while (remaining >= 0);
}

void func_00121BF8(Chr *chr)
{
    chr->w830 = 0xFFFE0000;
}

s32 func_00121C08(Chr *chr)
{
    return (chr->w830 >> 9) & 0x3;
}

void Sg_IdSetEffectTableIndex(s8 v)
{
    D_00580BA0 = v;
}

void func_00121C28(s32 i, u8 v)
{
    D_00580B98[i + D_00580BA0 * 4] = v;
}

int Ch_IdGetEffectTable(Chr *chr)
{
    if (chr->b192 == 2) {
        return (((int)(chr->flags >> 29) & 1) == 0) ? 9 : 8;
    }
    return D_00580B98[func_00121C08(chr) + D_00580BA0 * 4];
}

void func_00121CC0(void)
{
    int i;

    for (i = 19; i >= 0; i--) {
        D_00580B38[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        D_00580B98[i] = 0;
        D_00580B98[i + 4] = 0;
    }
    Sg_IdSetEffectTableIndex(0);
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00121D20);

float func_00121FE8(float *a, float *b)
{
    float d[3];

    d[0] = b[0] - a[0];
    d[2] = b[2] - a[2];
    return sqrtf(d[0] * d[0] + d[2] * d[2]);
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00122050);

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00122380);

void func_00122430(s32 a, s32 b)
{
    if (a == 0x1113) {
        D_00308908 = b;
    } else {
        func_002EA328(0);
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00122450);
