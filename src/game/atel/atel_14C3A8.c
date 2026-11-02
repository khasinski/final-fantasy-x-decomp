/* tu_082 0x14c3a8-0x14ce18: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g0.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u0.h"

INCLUDE_ASM("build/ee_asm/game/atel/atel_14C3A8", func_0014C3A8);

INCLUDE_ASM("build/ee_asm/game/atel/atel_14C3A8", func_0014C478);

INCLUDE_ASM("build/ee_asm/game/atel/atel_14C3A8", func_0014C4E0);

INCLUDE_ASM("build/ee_asm/game/atel/atel_14C3A8", AtelExecDrawShape);

void func_0014C7F8(s32 a, s32 b, s32 c)
{
    D_0058F7E8 = a;
    D_0058F7EC = a + b - 0xA0;
    D_0058F7F0 = c;
    D_0058F7F4 = 1;
}

void func_0014C828(s32 v)
{
    D_0058F7F4 = v;
}

void AtelRegistShape(int i, int v)
{
    Ent1C *e;

    i = Ent1CIdx(i);
    func_002CEEC0(v, 0x1A00, 0x1B00);
    e = &IsAtelTextureLoaded[i];
    e->w14 = v;
    e->b0 = 1;
    e->b1 = 0xFF;
    e->b10 = 0x80;
    e->b11 = 0x80;
    e->b12 = 0x80;
    e->b13 = 0x80;
    e->b3 = 1;
    e->w18 = 0;
    e->hC = 0;
}

static inline int ClampU8(int i)
{
    if (i >= 0) {
        if (i >= 0x100) {
            return 0xFF;
        }
        return i;
    }
    return 0;
}

void func_0014C8D8(int i, int v)
{
    i = Ent1CIdx(i);
    v = ClampU8(v);
    IsAtelTextureLoaded[i].b1 = v;
}

void func_0014C928(int i, int r, int g, int b)
{
    int max;
    int b0;
    Ent1C *e;

    i = Ent1CIdx(i);
    if (r >= 0) {
        max = 0xFF;
        if (r >= 0x100) {
            r = max;
        }
    } else {
        r = 0;
    }
    if (g >= 0) {
        max = 0xFF;
        if (g >= 0x100) {
            g = max;
        }
    } else {
        g = 0;
    }
    if (b >= 0) {
        if (b >= 0x100) {
            b0 = 0xFF;
        } else {
            b0 = b;
        }
    } else {
        b0 = 0;
    }
    e = &IsAtelTextureLoaded[i];
    e->b10 = r;
    e->b11 = g;
    e->b12 = b0;
}

void func_0014C9B0(int i, int v)
{
    ENT1C(i)->b13 = v;
}

void func_0014C9E8(int i, int a, int b)
{
    Ent1C *e = ENT1C(i);

    e->h4 = a;
    e->h6 = b;
}

void func_0014CA20(s32 a, float x, float y)
{
    s32 n;

    if (a >= 0) {
        if (a > 0x7F) {
            n = 0x7F;
        } else {
            n = a;
        }
    } else {
        n = 0;
    }
    IsAtelTextureLoaded[n].h8 = x * 256.0f;
    IsAtelTextureLoaded[n].hA = y * 256.0f;
}

void func_0014CA78(s32 a, s32 b)
{
    s32 n;

    if (a >= 0) {
        if (a > 0x7F) {
            n = 0x7F;
        } else {
            n = a;
        }
    } else {
        n = 0;
    }
    if (b) {
        b = 1;
    }
    IsAtelTextureLoaded[n].b3 = b;
}

void func_0014CAB8(int i)
{
    ENT1C(i)->b0 = 0;
}

Ent1C *func_0014CAF0(int i)
{
    return ENT1C(i);
}

void func_0014CB20(void)
{
    Ent1C *e = IsAtelTextureLoaded;
    int i;

    for (i = 0; i < 128; i++, e++) {
        e->b0 = 0;
        e->b2 = 0;
        e->b1 = 0x80;
        e->h4 = 0;
        e->h6 = 0;
        e->h8 = 0x100;
        e->hA = 0x100;
        e->b13 = 0x80;
        e->b10 = 0x80;
        e->b11 = 0x80;
        e->b12 = 0x80;
        e->w14 = 0;
    }
    func_0014C7F8(0, 0, 0);
}

void func_0014CB88(void)
{
    func_0014CB20();
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14C3A8", func_0014CB90);

INCLUDE_ASM("build/ee_asm/game/atel/atel_14C3A8", func_0014CC10);

void func_0014CC98(char *p, int n, int from, int to)
{
    int i = 0;

    if (n > 0) {
        do {
            if (*p != from) {
                break;
            }
            i++;
            *p = to;
            p++;
        } while (i < n);
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14C3A8", func_0014CCC8);

int func_0014CD50(char *s)
{
    int v = 0;
    int more;
    u8 c;

    if (*s == '0' && s[1] == 'x') {
        s += 2;
    } else if (*s == '$') {
        s++;
    }
    more = 1;
    do {
        c = *s;
        switch ((char)c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            v <<= 4;
            v += (char)c - '0';
            s++;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            v <<= 4;
            v += (c & 0xDF) - 'A' + 10;
            s++;
            break;
        default:
            more = 0;
            break;
        }
    } while (more);
    return v;
}
