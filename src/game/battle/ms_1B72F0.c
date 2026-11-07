/* tu_186 0x1b72f0-0x1b89d8: low; ~Ms (config/tu_map.tsv) */
#define MsGetChrBtlPosHeight _hdr_MsGetChrBtlPosHeight
#define MsGetChrBtlPos _hdr_MsGetChrBtlPos
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/t2.h"
#include "ffx/u2.h"
#undef MsGetChrBtlPos
#undef MsGetChrBtlPosHeight

s32 _m2c_MsGetChrBtlPos_MsBtlChrNumCheck(s32) __asm__("MsBtlChrNumCheck");
void _m2c_MsGetChrBtlPos_MsBtlGetPos(s32, void *, s8, s8, s8, void *) __asm__("MsBtlGetPos");
void *_m2c_MsGetChrBtlPos_MsGetChr(s32) __asm__("MsGetChr");
void _m2c_MsGetChrBtlPos_func_001B6790(s32, void *) __asm__("func_001B6790");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 MsGetChrBtlPos(s32 arg0, void *arg1) {
    float temp_f20;
    s32 temp_18;
    register s32 var_2 __asm__("$2");
    register s32 c2c8 __asm__("$3");
    void *temp_2;

    temp_18 = arg0 & 0xFF;
    if (_m2c_MsGetChrBtlPos_MsBtlChrNumCheck(temp_18) != 0) {
        temp_2 = _m2c_MsGetChrBtlPos_MsGetChr(temp_18);
        _m2c_MsGetChrBtlPos_MsBtlGetPos(0, temp_2, (*(s8 *)((u8 *)(temp_2) + (0x1BC))), (*(s8 *)((u8 *)(temp_2) + (0x1BD))), (*(s8 *)((u8 *)(temp_2) + (0x1BE))), arg1);
        c2c8 = (*(u8 *)((u8 *)(temp_2) + (0x2C8)));
        __asm__("" : "+r"(c2c8));
        if (((c2c8 == 0) && (((*(s8 *)((u8 *)(temp_2) + (0xA8C))) == 0) || ((*(u8 *)((u8 *)(temp_2) + (0xAA7))) != 0))) || ((*(s8 *)((u8 *)(temp_2) + (0x1CD))) != 0)) {
            (*(float *)((u8 *)(arg1) + (4))) = (float) ((*(float *)((u8 *)(arg1) + (4))) + (*(float *)((u8 *)(temp_2) + (0x1F4))));
        }
        if ((*(u8 *)((u8 *)(temp_2) + (0x39D))) != 0) {
            temp_f20 = (*(float *)((u8 *)(arg1) + (4)));
            _m2c_MsGetChrBtlPos_func_001B6790(temp_18, arg1);
            (*(float *)((u8 *)(arg1) + (4))) = temp_f20;
        }
        var_2 = -1;
    } else {
        var_2 = 0;
    }
    __asm__ volatile("" : "+r"(var_2));
    return var_2;
}

s32 _m2c_MsGetChrBtlPosHeight_MsBtlChrNumCheck(s32) __asm__("MsBtlChrNumCheck");
void *_m2c_MsGetChrBtlPosHeight_MsGetChr(s32) __asm__("MsGetChr");
/* DEBT(CAST) */
float MsGetChrBtlPosHeight(s32 arg0) {
    float var_f0;
    s32 temp_16;
    void *temp_2;

    temp_16 = arg0 & 0xFF;
    var_f0 = 0.0f;
    if ((_m2c_MsGetChrBtlPosHeight_MsBtlChrNumCheck(temp_16) != 0) && (((temp_2 = _m2c_MsGetChrBtlPosHeight_MsGetChr(temp_16), ((*(u8 *)((u8 *)(temp_2) + (0x2C8))) == 0)) && (((*(s8 *)((u8 *)(temp_2) + (0xA8C))) == 0) || ((*(u8 *)((u8 *)(temp_2) + (0xAA7))) != 0))) || (var_f0 = 0.0f, ((*(s8 *)((u8 *)(temp_2) + (0x1CD))) != 0)))) {
        var_f0 = (*(float *)((u8 *)(temp_2) + (0x1F4)));
    }
    return var_f0;
}

float func_001B7448(int id) {
    u8 i = id;
    float r = 0.0f;
    if (MsBtlChrNumCheck(i) != 0) {
        r = MsGetChr(i)->f1F4;
    }
    return r;
}

void func_001B7498(u8 id, int dir) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        Chr *p = c->chr;
        if (p != 0) {
            float f;
            if (dir > 0) {
                f = c->f19C;
            } else if (dir < 0) {
                f = -1.0f;
            } else {
                f = 0.0f;
            }
            Ch_SetWeight(p, f);
        }
    }
}

void func_001B7518(Chr **p, float v) {
    if (*p != 0) {
        Ch_SetWeight(*p, v);
    }
}

int MsGetChrEscapePos(int id, int v) {
    BtlChr *c;
    S2ChrB *b;

    id &= 0xFF;
    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        b = (S2ChrB *)c;
        MsBtlGetPos(0, c, b->a1BC, b->a1BD + 3, b->a1BE, v);
        return -1;
    }
    return 0;
}

void MsGetChrTargetPos(u8 id, s32 *a, s32 *b) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        if (a != 0) {
            *a = c->fBFC;
        }
        if (b != 0) {
            *b = c->fC00;
        }
    }
}

void MsGetChrGroundPos(u8 id, s32 *a, s32 *b) {
    if (MsBtlChrNumCheck(id) != 0) {
        BtlChr *c = MsGetChr(id);
        if (a != 0) {
            *a = c->fC14;
        }
        if (b != 0) {
            *b = c->fC18;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B72F0", MsGetChrCenter);

void MsCalcChrDirAll(void) {
    int i;
    for (i = 0; i < 31; i++) {
        BtlChr *c = MsGetChr(i);
        float f = MsCalcChrDir(i, c);
        c->f1D4[0] = f;
        c->f1D4[1] = f;
        c->f15C = f;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B72F0", MsCalcChrDir);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B72F0", func_001B78B0);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1B72F0/rodata", jtbl_0056E380);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B72F0", MsGetChrInfo);

int MsGetChrBit(int id, int kind, int dead, int all) {
    int mask = 0;
    int i;
    BtlChr *c;
    int sel;

    if ((kind >> 12) == 1) {
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (c->fA88 != 0 && c->fA8D == 0 && c->fE == kind) {
                mask |= 1 << i;
            }
        }
        return mask;
    }
    switch (kind) {
    case -5:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if ((c->fA88 != 0 && c->fA8D == 0) || dead) {
                mask |= 1 << i;
            }
        }
        break;
    case -21:
        for (i = 0; i < 31; i++) {
            mask |= 1 << i;
        }
        break;
    case -22:
        c = MsGetChr(id);
        if (MsBtlChrNumCheck(c->f14)) {
            mask = 1 << c->f14;
        }
        break;
    case -3:
        i = D_00319400;
        sel = 0;
        if (i != 0xFF && MsGetChr(i)->fAB0 != 0) {
            GsEnt48 *e = MsGetChrCommand(i);
            sel = e->f8[e->f2].targets;
        }
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if ((sel >> i) & 1) {
                if ((c->fA88 != 0 && c->fA8D == 0) || all) {
                    mask |= 1 << i;
                }
            }
        }
        break;
    case -4:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (((u32)D_003172F0.f1FF8 >> i) & 1) {
                if ((c->fA88 != 0 && c->fA8D == 0) || all) {
                    mask |= 1 << i;
                }
            }
        }
        break;
    case -2:
        i = D_00319400;
        if (i != 0xFF) {
            if (MsGetChr(i)->fAB0 != 0) {
                mask = 1 << i;
            }
        }
        break;
    case -14:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (c->fA88 != 0 && c->fA8D == 0 && !MsGetRamChrMonster(i)) {
                mask |= 1 << i;
            }
        }
        break;
    case -19:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (c->fA88 != 0 && c->fA8D == 0 && !MsGetRamChrMonster(i) && !MsGetRamChrSummon(i)) {
                mask |= 1 << i;
            }
        }
        break;
    case -25:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (c->fA88 != 0 && c->fA8D == 0 && !MsGetRamChrMonster(i) && !MsGetChrStatDeath(i) && !MsGetChrStatStone(i)) {
                mask |= 1 << i;
            }
        }
        break;
    case -23:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (!MsGetRamChrMonster(i)) {
                mask |= 1 << i;
            }
        }
        break;
    case -24:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (!MsGetRamChrMonster(i) && !MsGetRamChrSummon(i)) {
                mask |= 1 << i;
            }
        }
        break;
    case -20:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (c->fA88 != 0 && c->fA8D == 0 && MsGetRamChrSummon(i)) {
                mask |= 1 << i;
            }
        }
        break;
    case -15:
        for (i = 0; i < 31; i++) {
            c = MsGetChr(i);
            if (c->fA88 != 0 && c->fA8D == 0 && MsGetRamChrMonster(i) == 1) {
                mask |= 1 << i;
            }
        }
        break;
    case -12:
    case -11:
    case -10:
    case -9:
    case -8:
    case -7:
    case -6:
        i = D_003172F0.f1FC5[-6 - kind];
        if (MsBtlChrNumCheck(i)) {
            mask = 1 << i;
        }
        break;
    case -16:
        mask = MsGetChr(id)->fA80;
        break;
    case -26:
        mask = MsGetChr(id)->fA84;
        break;
    case -17:
        mask = 1 << MsGetChr(id)->fAAD;
        break;
    case -18:
        if (MsBtlChrNumCheck(D_003172F0.f210F)) {
            mask = 1 << D_003172F0.f210F;
        }
        break;
    case -13:
        kind = id;
    default:
        if (MsBtlChrNumCheck(kind)) {
            mask = 1 << kind;
        }
        break;
    }
    return mask;
}

int func_001B8198(int a, int b, int c, int d) {
    int bits = MsGetChrBit(a, b, c, d);
    int i;
    for (i = 0; i < 31; i++) {
        if ((bits >> i) & 1) {
            return i;
        }
    }
    return -1;
}

int func_001B81E8(u8 id, int mask) {
    if (MsBtlChrNumCheck(id) != 0) {
        int i;
        int n;
        MsGetChr(id)->fA80 = mask;
        n = 0;
        for (i = 0; i < 0x1F; i++) {
            n += (mask >> i) & 1;
        }
        return n;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B72F0", MsSetTargetDir);

int msCheckSameTarget(int id, BtlChr *c, int mask) {
    int bit = 1 << id;
    int r = -1;
    int n;
    int i;

    if (mask == bit || mask == 0) {
        r = 0;
    } else if ((mask & bit) && c->fB8 != 0) {
        n = 0;
        for (i = 0; i < 31; i++) {
            if ((mask >> i) & 1) {
                n++;
                if (n >= 3) {
                    r = 0;
                    break;
                }
            }
        }
    }
    return r;
}

void MsGetChrHeadPos(int id, float *v) {
    Chr *c = MsGetChrHandle(id);

    if (c != 0) {
        Ch_OptposGet(c, 1, v);
        v[1] -= 2.0;
    }
}

u8 func_001B84B8(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->fB4;
    }
    return 0;
}

u16 func_001B84F8(u8 id) {
    u16 r = 0;
    if (MsBtlChrNumCheck(id)) {
        r = MsGetChr(id)->fC0;
    }
    return r;
}

int func_001B8548(int id) {
    int r = 0;
    BtlChr *c;

    id &= 0xFF;
    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        if (c->fDE != 0 || c->fA8E != 0) {
            r = 1;
        }
    }
    return r;
}

u8 func_001B85B0(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->fDF;
    }
    return 0;
}

int func_001B85F0(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->fB5;
    }
    return -1;
}

s8 func_001B8630(u8 id) {
    if (MsBtlChrNumCheck(id)) {
        return MsGetChr(id)->f1C8;
    }
    return 0;
}

int func_001B8670(int id, int on, float f) {
    BtlChr *c;

    id &= 0xFF;
    if (!MsBtlChrNumCheck(id)) {
        return 0;
    }
    c = MsGetChr(id);
    c->f1D0 = on & 1;
    c->f1FC = f;
    return -1;
}

void func_001B86D8(int on) {
    int v = on & 1;
    int i;
    for (i = 0; i < 31; i++) {
        MsGetChr(i)->f1D0 = v;
    }
}

void func_001B8720(void) {
}

void func_001B8728(void) {
    int i;
    for (i = 0; i < 31; i++) {
        MsGetChr(i)->f5C = 0;
    }
}

/* DEBT(CAST): explicit width views follow the existing shared interfaces. */
void MsCommandReturnChrStatusAll(s32 reset)
{
    BtlChr *chr;
    Chr *model;
    s32 id;

    id = 0;
    do
    {
        chr = MsGetChr(id);
        chr->f2E[2] = 1;
        chr->f26[2] = -1;
        if (id < 0x1F)
        {
            if (reset != 0)
            {
                msResetHeadTarget(chr);
                CALL_MsEffectEndMotion_INT(id, 0);
                model = chr->chr;
                chr->f1D0 = 0;
                if (model != 0)
                {
                    Ch_SetCalcNorm(model, (s32) chr->f33);
                    Ch_SetOrgMatrix(model, 0);
                }
                chr->f3D9 = 1;
                chr->fD1 = 0;
                chr->fCF = 1;
                chr->fE5 = 0;
                chr->fD2 = 0;
                chr->fD4 = 0;
                chr->fC4 = 0;
                chr->fC5 = 0;
                MsSetChrSpecular(id, 0x1E, chr->f44);
                func_001B5860(id, 2, 1);
            }
            if ((chr->fA8E != 0) && (chr->fA8F == 0) && (D_003172F0.f2117 == 0) && (MsCheckBtlPos(id, chr, (s32) chr->f34) != 0))
            {
                CALL_MsStoneMove_CHR(id, chr);
            }
        }
        id += 1;
    } while (id < 0x5D);
}

int MsSetDirThetaMode(BtlChr *c)
{
    int state;

    if ((((u16)c->f2C6 >> 11) & 1) != 0)
    {
        state = 2;
    }
    else if (c->f394 != 0xFF)
    {
        state = 3;
    }
    else
    {
        state = D_00319407 != 0;
    }
    c->f1D1 = state;
    return state;
}

/* DEBT(CAST): the packed flags at fA88 are also read as one 32-bit word by the original. */
void MsChangeMonsterDir(void)
{
    BtlChr *chr;
    int i = 0x14;
    s8 enabled = D_00319407;

    do {
        chr = MsGetChr(i);
        if (chr->f10 != 0 && chr->fA8D == 0 && (*(u32 *)&chr->fA88 & 0xFF00FF) && chr->fA8C == 0 && chr->f1D2 == 0) {
            MsSetDirThetaMode(chr);
            chr->fDC = 1;
            if (enabled != 0) {
                chr->f1D4[1] = MsCalcChrDir(i, chr);
            }
            MsSetMotion(i, 0, 0, 0, 1, 0, 0);
        }
        i++;
    } while (i < 0x1C);
}
