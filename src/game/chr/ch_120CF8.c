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

extern s32 D_00580B28;
/* DEBT(CAST) */
void func_00120D18(s32 a) {
    Chr *var_3;
    void *temp_4;

    D_00580B34 = a;
    if (a != 0) {
        temp_4 = (*(void **)((u8 *)(a) + (0x1C)));
        D_00580B28 = (s32) (*(s16 *)((u8 *)(temp_4) + (8)));
        D_00308900 = (*(s16 **)((u8 *)(temp_4) + (0xC)));
        D_00580B2C = (*(u8 **)((u8 *)(a) + (0x18)));
        D_00580B30 = (*(float *)((u8 *)(a) + (0xC))) / 10.0f;
    } else {
        D_00580B28 = 0;
        D_00308900 = 0;
        D_00580B2C = 0;
        D_00580B30 = 1.0f;
    }
    for (var_3 = D_00300664; var_3 != D_00300664 + D_00300668; var_3++) {
        if (var_3->active != 0) {
            var_3->u828.s.h82E = -1;
        }
    }
}

void func_002DCE80(void *a, void *b, void *c);

void func_00120DE8(u8 *a, u8 *b, u8 *c, int d)
{
    s16 *v0 = (s16 *)a;
    s16 *v1 = (s16 *)b;
    s16 *v2 = (s16 *)c;
    float d1[4];
    float d2[4];
    float n[4];

    d1[0] = v1[0] - v0[0];
    d1[1] = v1[1] - v0[1];
    d1[2] = v1[2] - v0[2];
    d2[0] = v2[0] - v0[0];
    d2[1] = v2[1] - v0[1];
    d2[2] = v2[2] - v0[2];
    func_002DCE80(n, d2, d1);
    func_002DCEC8((void *)d, n);
}

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

float func_00120F28(float *a, int i)
{
    s16 *t = D_00308900;
    s16 *e;
    s16 *p;
    float v[4];
    float n[4];

    if (t == 0) {
        return 0.0f;
    }
    if (i == -1) {
        return 0.0f;
    }
    e = &t[i * 8];
    func_00120DE8(D_00580B2C + e[0] * 8, D_00580B2C + e[1] * 8, D_00580B2C + e[2] * 8, (int)n);
    p = (s16 *)(e[0] * 8 + (s32)D_00580B2C);
    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];
    return ((v[0] * n[0] + v[1] * n[1] + v[2] * n[2]) - (a[0] * n[0] + a[2] * n[2])) / n[1];
}

typedef struct {
    s16 v[6];
    s32 w0C;
} MapPoly16;

s32 func_00121038(float *pos)
{
    MapPoly16 *poly;
    u8 *verts;
    s32 best;
    s32 last;
    s32 best_y;
    s32 i;
    s16 *v[3];

    if (D_00308900 == 0) {
        return -1;
    }
    verts = D_00580B2C;
    poly = (MapPoly16 *)D_00308900;
    best = -1;
    last = -1;
    best_y = 0;
    for (i = 0; i < D_00580B28; i++, poly++) {
        v[0] = (s16 *)(verts + poly->v[0] * 8);
        v[1] = (s16 *)(verts + poly->v[1] * 8);
        v[2] = (s16 *)(verts + poly->v[2] * 8);
        if ((float)(v[0][2] - v[1][2]) * pos[0] + (float)(v[1][0] - v[0][0]) * pos[2] + (float)(v[0][0] * v[1][2]) - (float)(v[1][0] * v[0][2]) > 0.0f) {
            continue;
        }
        if ((float)(v[1][2] - v[2][2]) * pos[0] + (float)(v[2][0] - v[1][0]) * pos[2] + (float)(v[1][0] * v[2][2]) - (float)(v[2][0] * v[1][2]) > 0.0f) {
            continue;
        }
        if ((float)(v[2][2] - v[0][2]) * pos[0] + (float)(v[0][0] - v[2][0]) * pos[2] + (float)(v[2][0] * v[0][2]) - (float)(v[0][0] * v[2][2]) > 0.0f) {
            continue;
        }
        last = i;
        {
            s32 y = (s32)func_00120F28(pos, last);
            if ((float)y < pos[1]) {
                continue;
            }
            if (best == -1 || y < best_y) {
                best_y = y;
                best = last;
            }
        }
    }
    if (best == -1) {
        if (last == -1) {
            return -1;
        }
        best = last;
    }
    poly = &((MapPoly16 *)D_00308900)[best];
    v[0] = (s16 *)(verts + poly->v[0] * 8);
    v[1] = (s16 *)(verts + poly->v[1] * 8);
    v[2] = (s16 *)(verts + poly->v[2] * 8);
    return best;
}

float func_001212E0(float x, float y, float z)
{
    float v[3];

    v[0] = x;
    v[1] = y;
    v[2] = z;
    return func_00121038(v) / D_00580B30;
}

int func_00121328(Chr *chr, int i)
{
    u32 v = ((MapPoly16 *)D_00308900)[i].w0C & 0x7F;

again:
    switch (v) {
    case 1:
        return 1;
    case 2:
        if (chr == (Chr *)Sg_GetPlayer()) {
            return 0;
        }
        return 1;
    case 14:
        return chr == (Chr *)Sg_GetPlayer();
    case 13:
        return (u32)((u64)chr->flags >> 34) & 1;
    case 0x30: case 0x31: case 0x32: case 0x33:
    case 0x34: case 0x35: case 0x36: case 0x37:
    case 0x38: case 0x39: case 0x3A: case 0x3B:
    case 0x3C: case 0x3D: case 0x3E: case 0x3F:
        v = D_00580B38[v - 0x30];
        goto again;
    default:
        return 0;
    }
}

void func_00121418(float v)
{
    D_00308904 = v;
}

typedef struct ChrColView {
    u8 pad00[0x10];
    float f10;
    float f14;
    float f18;
    u8 pad1C[0x4];
    float f20;
    float f24;
    float f28;
    u8 pad2C[0x14];
    float f40;
    float f44;
    float f48;
    u8 pad4C[0x4];
    float f50;
    float f54;
    float f58;
    u8 pad5C[0x4];
    float f60;
    float f64;
    float f68;
    u8 pad6C[0x14];
    float f80;
    float f84;
    float f88;
    u8 pad8C[0x4];
    float f90;
    float f94;
    float f98;
    u8 pad9C[0x4];
    float fA0;
    float fA4;
    float fA8;
    u8 padAC[0x4];
    float fB0;
    float fB4;
    float fB8;
    u8 padBC[0xA4];
    float f160;
    u8 pad164[0x14];
    float f178;
    u8 pad17C[0x24];
    union {
        s64 raw;
        struct {
            u32 pad0 : 5;
            u32 b5 : 1;
        } bf;
    } flg;
    u8 pad1A8[0x348];
    float f4F0;
    float f4F4;
    u8 pad4F8[0x14];
    float f50C;
    u8 pad510[0x18];
    float f528;
    float f52C;
    u8 pad530[0x174];
    float f6A4;
    u8 pad6A8[0xC];
    float f6B4;
    u8 pad6B8[0x176];
    s16 h82E;
    s32 w830;
} ChrColView;

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

s32 func_00122050(Chr *chrA, Chr *chrB, float r, float d)
{
    ChrColView *a = (ChrColView *)chrA;
    ChrColView *b = (ChrColView *)chrB;
    s32 mode = 0;
    float w1 = 1.0f;
    float w0 = 1.0f;
    float pad00[4]; /* DEBT(PADDING): unused 16-byte frame slot in the original */
    float diff[4];
    register float p1 __asm__("$f12");

    if (b->f50C < 0.0f) {
        w0 = 0.0f;
        if (a->f50C < 0.0f) {
            w0 = func_00121FE8(&a->f20, &a->f10);
            mode = 1;
            w1 = func_00121FE8(&b->f20, &b->f10);
            if (w0 == w1) {
                return 0;
            }
            p1 = (w0 < w1) ? w1 : w0;
            w0 /= p1;
            w1 /= p1;
        }
    } else {
        if (a->f50C < 0.0f) {
            w1 = 0.0f;
        } else {
            w0 = a->f50C;
            w1 = b->f50C;
            if (w0 == 0.0f && w1 == 0.0f) {
                w1 = 1.0f;
                w0 = 1.0f;
            }
        }
    }
    r -= d;
    diff[0] = a->f10 - b->f10;
    diff[1] = 0.0f;
    diff[2] = a->f18 - b->f18;
    func_002DCEC8(diff, diff);
    d = (w0 * r) / (w0 + w1);
    if (d < 0.0f) {
        return 0;
    }
    p1 = r - d;
    if (mode != 0) {
        if (d != 0.0f) {
            a->f50 += diff[0] * d;
            a->f58 += diff[2] * d;
            if (a->f50 != 0.0f || a->f58 != 0.0f) {
                a->flg.raw |= 0x20;
            }
        }
        if (p1 != 0.0f) {
            b->f50 -= diff[0] * p1;
            b->f58 -= diff[2] * p1;
            if (b->f50 != 0.0f || b->f58 != 0.0f) {
                b->flg.raw |= 0x20;
            }
        }
    } else {
        if (p1 != 0.0f) {
            a->f50 += diff[0] * p1;
            a->f58 += diff[2] * p1;
            if (a->f50 != 0.0f || a->f58 != 0.0f) {
                a->flg.raw |= 0x20;
            }
        }
        if (d != 0.0f) {
            b->f50 -= diff[0] * d;
            b->f58 -= diff[2] * d;
            if (b->f50 != 0.0f || b->f58 != 0.0f) {
                b->flg.raw |= 0x20;
            }
        }
    }
    return a->flg.bf.b5 | b->flg.bf.b5;
}

typedef struct SortEnt22380 {
    s32 pad00[6];
    float f18;
} SortEnt22380;

extern SortEnt22380 *D_00580BA8[];

void func_00122380(s32 n)
{
    s32 i, j, k;
    SortEnt22380 *tmp;

    for (i = 0; i < n; i++) {
        k = i;
        for (j = i; j < n; j++) {
            if (D_00580BA8[k]->f18 >= D_00580BA8[j]->f18) {
                k = j;
            }
        }
        tmp = D_00580BA8[i];
        D_00580BA8[i] = D_00580BA8[k];
        D_00580BA8[k] = tmp;
    }
}

void func_00122430(s32 a, s32 b)
{
    if (a == 0x1113) {
        D_00308908 = b;
    } else {
        func_002EA328(0);
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_120CF8", func_00122450);
