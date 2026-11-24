/* tu_182 0x1b3388-0x1b4100: medium; ~Ms (config/tu_map.tsv) */
#define func_001B34B8 _hdr_func_001B34B8
#define MsBtlGetPos _hdr_MsBtlGetPos
#include "common.h"
#include "vu0.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#undef MsBtlGetPos
#undef func_001B34B8

void func_001B39A8(u8 *src_base, u8 *dst_base, int idx);
void MsGetSummonerPos(BtlChr *chr, int id, int mode, float *out);
void func_001AC3D0(float *dst, float *a, float *b);
void func_001ACB28(float *v, float s);
float func_002E8648(float x);
float func_002E89C0(float x);

void func_001B3388(void) {
    GsTbl *t = D_003172F0.pF4;

    D_003172F0.h100 = (u32)(t->off8 - t->off4) / sizeof(GsEnt14);
    D_003172F0.pF8 = (GsEnt14 *)((u8 *)t + t->off4);
    D_003172F0.pFC = (u8 *)t + t->off8;
}

Unk33D0 *MsBtlListField(int i) {
    if (i < 0 || i >= D_003172F0.h100) {
        i = 0;
    }
    return (Unk33D0 *)(D_003172F0.pF8 + i); /* DEBT(CAST): the record is viewed as Unk33D0 by its caller */
}

int MsBtlListEncount(void) {
    return D_003173EC + ((Unk33D0 *(*)(void))MsBtlListField)()->f2; /* DEBT(CAST): the original caller passes no index */
}

u8 *func_001B3448(int a, int n) {
    u8 *p = (u8 *)MsBtlListEncount(); /* DEBT(CAST): returns a record pointer as int */
    int i;
    int len;

    if (n < 0 || n >= p[1]) {
        n = 0;
    }
    p += 2;
    for (i = 0; i < n; i++) {
        len = p[0];
        p += 5;
        p += len * 2;
    }
    return p;
}

void *_m2c_func_001B34B8_MsBtlListEncount(s32) __asm__("MsBtlListEncount");
void *_m2c_func_001B34B8_MsBtlListField() __asm__("MsBtlListField");
u8 *_m2c_func_001B34B8_func_001B3448(s32, s32) __asm__("func_001B3448");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_001B34B8(s32 arg0, s32 *arg1, s32 *arg2) {
    register s32 _cond __asm__("$2");
    register s32 var_16 __asm__("$16");
    register s32 var_17 __asm__("$17");
    s32 var_3;
    s32 var_3_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    register void * temp_21 __asm__("$21");
    void *temp_2;

    temp_21 = _m2c_func_001B34B8_MsBtlListField(arg0);
    temp_2 = _m2c_func_001B34B8_MsBtlListEncount(arg0);
    var_3_2 = *arg1;
    if ((var_3_2 < 0) || (var_16 = 0, ((var_3_2 < (s32) (*(u8 *)((u8 *)(temp_2) + (1)))) == 0))) {
        *arg1 = 0;
        var_3_2 = 0;
        var_16 = 0;
    }
    var_17 = 0;
    if (var_3_2 > 0) {
        do {
            temp_2_2 = _m2c_func_001B34B8_func_001B3448(arg0, var_16);
            var_16 += 1;
            var_17 += *temp_2_2;
        } while ((_cond = (var_16 < *arg1)) != 0);
    }
    temp_2_3 = _m2c_func_001B34B8_func_001B3448(arg0, *arg1);
    var_3 = *arg2;
    if ((var_3 < 0) || (var_3 >= (s32) *temp_2_3)) {
        *arg2 = 0;
        var_3 = 0;
    }
    return (*(s16 *)((u8 *)(temp_21) + (4))) + var_17 + var_3;
}

int MsBtlListFieldNum(int id) {
    int r = -1;
    int i;
    for (i = 0; i < D_003172F0.h100; i++) {
        if (D_003172F0.pF8[i].h0 == id && id > 0) {
            r = i;
            break;
        }
    }
    return r;
}

typedef struct {
    u8 pad0[0x1D1];
    s8 b1D1;
    u8 pad1D2[2];
    float f1D4[4];
} ChrDirView;

typedef struct {
    float x, y, z, w;
} MsPosQuad;

int MsBtlGetPos(int mode, BtlChr *chr, int a2, int type, int idx, float *out) {
    u8 *p = (u8 *)D_003173D0;
    register u8 *base __asm__("$12") = p;
    int ret = 0;
    float *vptr = 0;
    float *fptr = 0;

    if (a2 < 0 || a2 >= *(s8 *)(p + 1)) {
        return -1;
    }
    if (*(s8 *)p != 0) {
        p += a2 * 0x20;
        if (type != 3) {
            return -1;
        }
    } else {
        p += a2 * 0x60;
    }
    if (chr != 0 && out != 0 && ((u8 *)chr)[0x394] != 0xFF) {
        register u_long128 *src __asm__("$2") = (u_long128 *)((u8 *)chr + 0x70);
        register u_long128 tmp __asm__("$8");
        __asm__("" : "+r"(src));
        tmp = *src;
        *(u_long128 *)out = tmp;
        __asm__("" : : "m"(*(u_long128 *)out));
        return 0;
    }
    switch (type) {
    case 3:
        if (idx >= 0 && idx < *(s8 *)(p + 4)) {
            vptr = (float *)(base + *(s32 *)(p + 0x10));
            vptr += idx * 4;
        }
        break;
    case 6:
        if (idx >= 0 && idx < *(s8 *)(p + 4)) {
            vptr = (float *)(base + *(s32 *)(p + 0x14));
            vptr += idx * 4;
        }
        break;
    case 5:
        if (idx >= 0 && idx < *(s8 *)(p + 6)) {
            vptr = (float *)(base + *(s32 *)(p + 0x20));
            vptr += idx * 4;
        }
        break;
    case 8:
        if (idx >= 0 && idx < *(s8 *)(p + 6)) {
            vptr = (float *)(base + *(s32 *)(p + 0x24));
            vptr += idx * 4;
        }
        break;
    case 4:
        if (idx >= 0 && idx < *(s8 *)(p + 5)) {
            vptr = (float *)(base + *(s32 *)(p + 0x18));
            vptr += idx * 4;
        }
        break;
    case 7:
        if (idx >= 0 && idx < *(s8 *)(p + 5)) {
            vptr = (float *)(base + *(s32 *)(p + 0x1C));
            vptr += idx * 4;
        }
        break;
    case 9:
        vptr = (float *)(p + 0x40);
        ret = *(s8 *)(p + 2);
        break;
    case 10:
        vptr = (float *)(p + 0x50);
        ret = *(s8 *)(p + 3);
        break;
    case 2:
        vptr = (float *)(p + 0x30);
        break;
    case 11:
        if (idx >= 0 && idx < *(s8 *)(p + 9)) {
            fptr = (float *)(base + *(s32 *)(p + 0x2C));
            fptr += idx;
        }
        break;
    case 12:
        if (out == 0) {
            return 0;
        }
        MsGetSummonerPos(chr, idx, 0, out);
        __asm__("");
        return 0;
    case 13:
        if (out == 0) {
            return 0;
        }
        MsGetSummonerPos(chr, idx, 1, out);
        __asm__("");
        return 0;
    case 14:
        if (out == 0) {
            return 0;
        }
        MsGetSummonerPos(chr, idx, 2, out);
        return 0;
    }
    __asm__("" : : "r"(base));
    if (vptr != 0) {
        if (out != 0) {
            if (mode != 0) {
                vptr[0] = out[0];
                vptr[1] = out[1];
                vptr[2] = out[2];
                vptr[3] = out[3];
            } else {
                out[0] = vptr[0];
                out[1] = vptr[1];
                out[2] = vptr[2];
                out[3] = vptr[3];
            }
        }
    } else if (fptr != 0) {
        if (out != 0) {
            if (mode != 0) {
                *fptr = out[0];
            } else {
                out[0] = *fptr;
            }
        }
    } else {
        ret = -1;
    }
    return ret;
}

typedef struct Bw1B38E8 {
    u8 pad00[0xC0];
    u8 *pC0;
    u8 padC4[0x1C];
    void *pE0;
    u8 padE4[0x143A];
    u8 b151E;
} Bw1B38E8;

void func_001B38E8(int arg0)
{
    u8 *p = ((Bw1B38E8 *)&D_003172F0)->pC0; /* DEBT(CAST): D_003172F0 fields at +0xC0, +0xE0, +0x151E */
    register int n __asm__("$5") = *(s8 *)(p + 1); /* DEBT(REG): a1/a2 swap between n and i */
    int first = -1;
    int last = -1;
    int i;
    int idx;

    for (i = 0; i < n; i++, p += 0x20) {
        if (*(s8 *)(p + 4) == arg0) {
            if (first < 0) {
                first = i;
            }
        } else {
            if (first >= 0) {
                last = i;
            }
        }
    }
    if (first < 0) {
        first = 0;
    }
    if (last < 0) {
        last = i;
    }
    idx = first + func_001ACEA0() % (last - first);
    ((Bw1B38E8 *)&D_003172F0)->b151E = idx + 1;
    func_001B39A8(((Bw1B38E8 *)&D_003172F0)->pC0, ((Bw1B38E8 *)&D_003172F0)->pE0, idx);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B3388", func_001B39A8);

void func_001B3A80(void) {
    s8 *p;
    int r;
    func_001B38E8(3);
    p = D_003173D0;
    if (p[9] > 0) {
        r = func_001ACEA0() % p[9];
    }
}

s8 func_001B3AD0(void) {
    return D_003173D0[1];
}

void MsPushBtlPosAll(void) {
    int i;
    for (i = 0; i < 31; i++) {
        MsPushBtlPos(MsGetChr(i));
    }
}

void MsPushBtlPos(BtlChr *chr) {
    chr->f1C9.a = chr->f1BC.a;
    chr->f1C9.b = chr->f1BC.b;
    chr->f1C9.c = chr->f1BC.c;
}

void func_001B3B40(void) {
    int i;
    for (i = 0; i < 31; i++) {
        MsPopBtlPos(MsGetChr(i));
    }
}

void MsPopBtlPos(BtlChr *chr) {
    chr->f1BC.a = chr->f1C9.a;
    chr->f1BC.b = chr->f1C9.b;
    chr->f1BC.c = chr->f1C9.c;
}

void MsGetSummonerPos(BtlChr *chr, int id, int mode, float *out)
{
    float dist;
    BtlChr *c;
    float dir;

    MMI_SQ_ZERO(0, out);
    dist = 0.0f;
    c = MsGetChr(id);
    MsBtlGetPos(0, c, (s8)c->f1BC.a, (s8)c->f1BC.b, (s8)c->f1BC.c, out);
    dir = ((ChrDirView *)c)->f1D4[((ChrDirView *)c)->b1D1] - 0.7853981852531433f;
    switch (c->f04) {
    case 0x3001:
        if (mode != 0) {
            dir += 2.4434611797332764f;
            dist = 10.0f;
        }
        break;
    case 0x3002:
        if (mode != 0) {
            dir -= 2.268928050994873f;
            dist = 16.0f;
        }
        break;
    case 0x3003:
        if (mode != 0) {
            dir += 2.1293017864227295f;
            dist = 13.0f;
        }
        break;
    case 0x3004:
        if (mode != 0) {
            dir += 2.3038346767425537f;
            dist = 14.0f;
        }
        break;
    case 0x3006:
        if (mode != 0) {
            dir -= 2.286381244659424f;
            dist = 17.0f;
        }
        break;
    case 0x3007:
        if (mode != 0) {
            dir += 2.356194496154785f;
            dist = 24.0f;
        }
        break;
    case 0x3008:
        switch (mode) {
        case 1:
            dir -= 2.094395160675049f;
            dist = 18.6f;
            break;
        case 2:
            dir += 1.3962634801864624f;
            dist = 14.2f;
            break;
        case 3:
            dir += 2.4434611797332764f;
            dist = 9.8f;
            break;
        }
        break;
    case 0x3009:
    case 0x300A:
    case 0x300B:
        {
            int first;
            int i;
            float base_dir;
            float pos[4];
            MMI_SQ_ZERO(0, out);
            dir = 0.0f;
            first = 1;
            base_dir = dir;
            for (i = 0; i < 3; i++) {
                float d;
                c = MsGetChr(i + 15);
                MsBtlGetPos(0, c, (s8)c->f1BC.a, (s8)c->f1BC.b, (s8)c->f1BC.c, pos);
                func_001AC3D0(out, out, pos);
                d = ((ChrDirView *)c)->f1D4[((ChrDirView *)c)->b1D1];
                if (first != 0) {
                    first = 0;
                    dir = MsNearRag(0.0f, d);
                    base_dir = dir;
                } else {
                    dir += MsNearRag(base_dir, d);
                }
            }
            dir /= 3.0f;
            func_001ACB28(out, 3.0f);
            *(float *)((u8 *)chr + 0x1D8) = dir;
            dir -= 3.9269909858703613f;
            if (mode != 0) {
                dist = 10.0f;
            }
        }
        break;
    }
    if (dist != 0.0f) {
        out[0] += (func_002E8648(dir) - func_002E89C0(dir)) * dist;
        out[2] += (func_002E89C0(dir) + func_002E8648(dir)) * dist;
    }
}

extern u8 D_003192B5[];
void MsSetChrDirF(int id, float dir);

void MsSetChrPosAfterSummon(int summoner)
{
    float pos[4];
    int flag = 1;
    int i;
    BtlChr *chr;

    for (i = 0; i < 7; i++) {
        u8 id = D_003192B5[i];
        s32 w4;

        if (id == 0xFF) {
            continue;
        }
        chr = MsGetChr(id);
        msSetEndDir(chr);
        w4 = *(s32 *)((u8 *)chr + 4); /* DEBT(CAST): chr id field */
        switch (w4) {
        case 0x3001:
        case 0x3002:
        case 0x3003:
        case 0x3004:
        case 0x3006:
        case 0x3007:
        case 0x3008:
        case 0x3009:
        case 0x300A:
        case 0x300B:
            flag = 0;
            break;
        }
        ((u8 *)chr)[0x1C8] = 0;
        ((u8 *)chr)[0x39F] = 0;
        ((u8 *)chr)[0xEE] = 0;
        ((u8 *)chr)[0xD5] = 0;
        MsGetChrBtlPos(id, pos);
        MsSetChrPosReset(id, pos);
        MsSetChrDirF(id, ((ChrDirView *)chr)->f1D4[((ChrDirView *)chr)->b1D1]);
        func_001B57F0(id, 1);
        MsStatusEffectCheck(id);
    }
    chr = MsGetChr(summoner);
    msSetChrBodyHit(chr, 3, 0);
    msSetEndDir(chr);
    ((u8 *)chr)[0x1BD] = 0xD;
    MsPushBtlPos(chr);
    MsRegSEfade(summoner, *(u16 *)((u8 *)chr + 0xC36), 0x14);
    func_001B7498(summoner, 1);
    if (flag != 0) {
        MsSetMotion(summoner, 1, 1, 0, 1, 0, 0);
    } else {
        ((u8 *)chr)[0xDC] = 1;
        MsGetChrBtlPos(summoner, pos);
        MsSetChrPosReset(summoner, pos);
        MsSetMotion(summoner, 0, 1, 0, 1, 0, 0);
    }
}
