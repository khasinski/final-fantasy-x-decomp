/* tu_082 0x14c3a8-0x14ce18: low; ~Atel (config/tu_map.tsv) */
#define func_0014C3A8 _hdr_func_0014C3A8
#include "common.h"
#include "ffx/g0.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u0.h"
#undef func_0014C3A8

s32 _m2c_func_0014C3A8_MsBattleCheck(s32) __asm__("MsBattleCheck");
extern s32 _m2c_func_0014C3A8_D_0058F7E8 __asm__("D_0058F7E8");
extern s32 _m2c_func_0014C3A8_D_0058F7F4 __asm__("D_0058F7F4");
extern s32 _m2c_func_0014C3A8_IsAtelTextureLoaded __asm__("IsAtelTextureLoaded");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0014C3A8(void) {
    s32 *var_16;
    s32 var_3;
    s32 var_4;
    s32 var_7;
    u16 temp_4;
    register void *temp_5 __asm__("$5");
    void *temp_6;

    var_16 = &_m2c_func_0014C3A8_IsAtelTextureLoaded;
    if (_m2c_func_0014C3A8_D_0058F7E8 != 0) {
        if ((_m2c_func_0014C3A8_MsBattleCheck(_m2c_func_0014C3A8_D_0058F7E8) == 0) && (_m2c_func_0014C3A8_D_0058F7F4 != 0)) {
            var_7 = 0x7F;
            do {
                if ((*(u8 *)((u8 *)(var_16) + (0))) != 0) {
                    temp_4 = (*(u16 *)((u8 *)(var_16) + (0xC)));
                    temp_5 = (*(void **)((u8 *)(var_16) + (0x14)));
                    temp_6 = temp_5 + ((temp_4 * 8) + 0x10);
                    var_3 = (*(s32 *)((u8 *)(var_16) + (0x18))) + 0x100;
                    if (var_3 >= (*(s16 *)((u8 *)(temp_6) + (2)))) {
                        var_4 = temp_4 + 1;
                        var_3 = 0;
                        if (var_4 >= (*(s16 *)((u8 *)(temp_5) + (4)))) {
                            var_4 = 0;
                            if (!((*(s8 *)((u8 *)(temp_6) + (4))) & 0x80)) {
                                (*(u8 *)((u8 *)(var_16) + (0))) = 0U;
                            }
                        }
                        (*(u16 *)((u8 *)(var_16) + (0xC))) = (u16) var_4;
                    }
                    (*(s32 *)((u8 *)(var_16) + (0x18))) = var_3;
                }
                var_7 -= 1;
                var_16 = (s32 *)((u8 *)var_16 + (0x1C));
            } while (var_7 >= 0);
        }
    }
}

extern u64 D_006F2CE0[];

u64 *func_0014C478(int a, u64 *p)
{
    u64 *next;

    p[2] = 0x1000000000000001ULL;
    p[3] = 0xE;
    next = p + 6;
    p[4] = 1;
    p[5] = D_006F2CE0[15];
    func_002B2B30((int)p, 3, a, 0);
    return next;
}

u64 *func_0014C4E0(int a, u64 *p)
{
    u64 *next;

    p[2] = 0x1000000000000001ULL;
    p[3] = 0xE;
    next = p + 6;
    p[4] = D_006F2CE0[14];
    p[5] = D_006F2CE0[15];
    func_002B2B30((int)p, 3, a, 0);
    return next;
}

typedef struct {
    float m[4][4];
} __attribute__((aligned(8))) ShapeMat;

typedef struct {
    s16 h00;
    s16 h02;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s16 h08;
    s16 h0A;
    s16 h0C;
    s16 h0E;
    void *p10;
    void *p14;
    u8 b18;
    u8 pad19[3];
    s32 w1C;
    u8 pad20[0x10];
} ShapeCtx;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s16 h4;
    s16 h6;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 *p14;
    s32 w18;
} ShapeEnt;

extern ShapeMat _ds_D_0030BA40 __asm__("D_0030BA40");
extern ShapeEnt _ds_IsAtelTextureLoaded[] __asm__("IsAtelTextureLoaded");
extern volatile u32 _ds_D_0058F7EC __asm__("D_0058F7EC");
extern u64 *_ds_func_002CFC70(u64 *, int, int, int, int) __asm__("func_002CFC70");
extern int _ds_func_002CEF70(void *) __asm__("func_002CEF70");
extern u64 *_ds_func_002CD590(void *, ShapeCtx *) __asm__("func_002CD590");

void AtelExecDrawShape(void) {
    ShapeMat mat;
    ShapeCtx ctx;
    u64 *ptr;
    ShapeEnt *e;
    int mode;
    int i;

    if (D_0058F7E8 == 0) {
        return;
    }
    if (MsBattleCheck() != 0) {
        return;
    }
    if (D_0058F7F4 == 0) {
        return;
    }
    e = _ds_IsAtelTextureLoaded;
    ptr = (u64 *)D_0058F7E8;
    ctx.h02 = 0x70;
    mode = 1;
    ctx.h00 = 0;
    ctx.p10 = &mat;
    ctx.w1C = 0;
    ctx.h08 = 0;
    ctx.h0A = 0;
    ctx.b18 = 0;
    ctx.h0E = 0;
    if (D_0058F7F0 != 0) {
        ptr = _ds_func_002CFC70(ptr, 8, D_0058F7F0, 0x1A00, 0x1B00);
    }
    for (i = 0; i < 0x80; i++, e++) {
        if (e->b0 != 0 && e->p14 != 0) {
            u8 *base = e->p14;
            u8 *shape;
            mat = _ds_D_0030BA40;
            mat.m[0][0] = (float)e->h8 * (1.0f / 256.0f);
            mat.m[1][1] = (float)e->hA * (1.0f / 256.0f);
            mat.m[3][0] += (float)e->h4;
            mat.m[3][1] += (float)e->h6;
            shape = base + *(s16 *)(base + e->hC * 8 + 0x10);
            ctx.r = (u32)(e->b1 * e->b10) / 0xFFU;
            ctx.g = (u32)(e->b1 * e->b11) / 0xFFU;
            ctx.b = (u32)(e->b1 * e->b12) / 0xFFU;
            ctx.a = e->b13;
            ctx.h0C = 0x1030;
            if (e->b3 != mode) {
                if (e->b3 != 0) {
                    ptr = func_0014C4E0(0x1030, ptr);
                } else {
                    ptr = func_0014C478(0x1030, ptr);
                }
                mode = e->b3;
            }
            ctx.p14 = ptr;
            if (_ds_D_0058F7EC > (u32)ptr + _ds_func_002CEF70(shape)) {
                ptr = _ds_func_002CD590(shape, &ctx);
            } else {
                break;
            }
        }
    }
    if (mode == 0) {
        func_0014C4E0(ctx.h0C, ptr);
    }
}

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

extern s32 _m2c_func_0014CB90_D_0030BA90 __asm__("D_0030BA90");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0014CB90(u32 arg0, s8 *arg1, s32 arg2) {
    register s32 var_7 __asm__("$7");
    s8 *var_5;
    s8 *var_8;
    u32 *var_10;
    u32 *var_9;
    u32 var_3;
    u32 var_4;

    var_4 = arg0;
    var_5 = arg1;
    var_10 = (u32 *)&_m2c_func_0014CB90_D_0030BA90;
    __asm__ volatile("" : "+r"(var_10));
    var_3 = _m2c_func_0014CB90_D_0030BA90;
    if (var_3 != 0) {
        var_10 += 1;
        do {
            var_7 = 0;
            if (var_4 >= var_3) {
                var_9 = ((u32 *)((u8 *)var_10 + (4)));
                var_8 = var_5 + 1;
                do {
                    var_4 -= var_3;
                    var_7 += 1;
                } while (var_4 >= var_3);
            } else {
                var_9 = ((u32 *)((u8 *)var_10 + (4)));
                var_8 = var_5 + 1;
            }
            *var_5 = var_7 + arg2;
            var_5 = var_8;
            var_3 = *var_10;
            var_10 = var_9;
        } while (var_3 != 0);
    }
    *var_5 = 0;
}

extern u32 D_0030BAC0[];

void func_0014CC10(s64 val, char *dst, int base_char)
{
    u32 *tbl = D_0030BAC0;
    u32 d = *tbl++;

    while (d != 0) {
        register s32 digit __asm__("$3") = 0;
        while (val >= (s64)d) {
            val -= d;
            digit++;
        }
        *dst++ = digit + base_char;
        d = *tbl++;
    }
    *dst = 0;
}

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
