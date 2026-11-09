/* tu_196 0x1ccc10-0x1ce8e0: low; ~Ms (config/tu_map.tsv) */
#define func_001CE050 _hdr_func_001CE050
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/g2.h"
#include "ffx/s3.h"
#undef func_001CE050

u32 MsGetEffID(int id, int lo, int hi) {
    PackedCmd c;
    c.hi = hi;
    c.lo = lo;
    c.id = id & 0xFFF;
    return *(u32 *)&c; /* DEBT(CAST): type-pun the 4 byte record to a word (union and struct-return forms change the codegen) */
}

void func_001CCC30(void) {
    D_0066261C = 0;
}

void func_001CCC40(void) {
    if (D_0066261C != 0) {
        func_0011D590(D_0066261C, 5);
        D_0066261C = 0;
    }
}

void func_001CCC78(int a, int b) {
    MsGetChr(b)->f35 = 1;
    op_et_weapon_init(a, b);
}

void MsEffectWeaponFree(int id) {
    BtlChr *c = MsGetChr(id);
    if (c->f4C != 0) {
        if (c->f35 != 0) {
            op_et_weapon_free(c->f4C);
            c->f4C = 0;
            c->f35 = 0;
        }
    }
}

void func_001CCD10(Q4ObjC *o) {
    MsGetChr(o->fC)->fABD = 0;
    D_003193F8 = 0;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_001CCD38(s32 a, s32 b) {
    s32 temp_6;
    s32 var_7;
    u16 *temp_4;
    u16 temp_2;

    var_7 = -1;
    if (a < 0x400) {
        register u16 *base __asm__("$5") = D_00317370;
        temp_6 = b + 1;
        temp_4 = (u16 *)((u8 *)(a * 2) + (u32)base);
        __asm__ volatile("" : : : "$2");
        temp_2 = (*(u16 *)((u8 *)(temp_4) + (0)));
        if (temp_6 < ((*(u16 *)((u8 *)(temp_4) + (2))) - temp_2)) {
            var_7 = temp_2 + temp_6;
        }
        __asm__ volatile("" : "+r"(temp_6));
    }
    return var_7;
}

void op_ovl_effect_init(void);
extern char D_0056E8A0[];
extern char D_0056E8F0[];
extern s8 D_00576479;
int MsStoneEffectCheck(void);
int func_204E8D0(int a);

typedef struct {
    u8 pad0[0x20];
    s32 f20;
    u8 pad24[0x30 - 0x24];
    s8 f30;
    u8 pad31;
    s8 f32;
    u8 pad33[0x55 - 0x33];
    s8 f55;
    u8 pad56[0x1754 - 0x56];
    s32 f1754;
    u8 pad1758[0x2018 - 0x1758];
    s32 f2018;
    s32 f201C;
    u8 pad2020[0x2028 - 0x2020];
    s32 f2028;
    u8 pad202C[0x2107 - 0x202C];
    s8 f2107;
    s8 f2108;
    u8 pad2109[0x213C - 0x2109];
    s8 f213C;
} GameStateEffRead;
extern GameStateEffRead _gs_eff_read __asm__("D_003172F0");

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CCC10", MsEffectRead);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CCC10", MsEffectStart);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1CCC10/rodata", jtbl_0056E8B0);

int func_001CD480(int unused, BtlChr *c) {
    int r = 1;
    int id = c->fB0;
    if (c->f1C8 != 0 || c->fF6 != 0) {
        r = 0;
    } else if (id == ms_motion_trans(c, 12) || id == ms_motion_trans(c, 13) || id == ms_motion_trans(c, 2)
        || id == ms_motion_trans(c, 3) || id == ms_motion_trans(c, 4) || id == ms_motion_trans(c, 5)) {
        r = 0;
    }
    return r;
}

void func_001CD538(int a, BtlChr *c) {
    u8 k;
    MsActionRequest(a, 0xFF, 7, 0, 2, 0);
    MsPopBtlPos(c);
    ((void (*)(int, int))MsMenuOpenTitleWindow)(D_003192F8, 0x3C); /* DEBT(TYPE): this caller passes the id as int */
    k = c->fAC0;
    c->fB2 = 0xFF;
    MsSetMotion(a, k, 1, 1, 1, 0, 0);
    MsAtelRequestMagicCamera(0, a, c->fC1C, c->fAC4, c->fAC8, 1, 1, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1CCC10", MsEffectProcess);

void MsEffectFree(int id) {
    BtlChr *c;
    GameState *g;

    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        if (c->fABB == 6) {
            g = &D_003172F0;
            g->f2111 = 0xFF;
            g->f201C = -1;
            if (c->fABE == 2) {
                MsAtelRequestCancel(2, 0, 0);
                MsAtelRequestCancel(2, 0, 1);
                MsAtelRequestCancel(2, 0, 2);
                c->fABE = 0;
            }
            MsAtelCamFree();
            if (D_0066261C != 0) {
                func_0011D590(D_0066261C, 5);
                D_0066261C = 0;
            }
            if (c->fC4C != 0) {
                g->f2C = g->f2D;
                func_002F8660(0);
                ((U2Fx *)c->fC4C)->f4(0); /* DEBT(CAST): fC4C holds an object pointer */
                func_002F8660(0);
                op_ovl_effect_free();
                SndStopBattleStream();
                c->fC4C = 0;
            }
            c->fABB = 0;
        }
    }
}

void func_001CD860(Obj1CD860 *o) {
    Sub1C *p = o->fC4C;
    if (D_0066261C != 0) {
        func_001B3278(D_0066261C);
    } else if (p != 0 && p->f1C != 0) {
        func_001B3278(p->f1C);
    }
}

void func_001CD8A0(int a, BtlChr *c) {
    if (c->fC4C != 0) {
        c->fABE = MsAtelRequestMagicCamera(0, a, c->fC1C, c->fAC6, c->fACA, 1, 1, 0, 0);
    }
    MsEffectCameraCall(-1, 1);
}

void MsLimitTypeStatusCheck(int id, BtlChr *c, int tid, BtlChr *t, int a, int b);
void MsStatusEffectReflect(int tid);

typedef struct {
    u8 id, sub, f2, f3, f4;
    u8 pad5[2];
    u8 f7;
    struct {
        u16 h0, h2;
        u8 pad4[4];
        s32 targets;
        s32 fC;
    } f8[4];
} GsEnt48_View;

void func_001CD900(int id, BtlChr *c) {
    if (c->fACD == 0) {
        GsEnt48_View *cmd = (GsEnt48_View *)MsGetChrCommand(id);
        s32 mask = cmd->f8[cmd->f2].fC;
        int flag = 0;
        int i;

        if (c->fF2 == 0 || c->fE9 != 0) {
            flag = 1;
        }
        if (flag != 0) {
            if (mask != 0) {
                switch (cmd->pad5[0]) {
                case 0:
                    for (i = 0; i < 0x1F; i++) {
                        if ((mask >> i) & 1) {
                            BtlChr *t = MsGetChr(i);
                            msResetHeadTarget(t);
                            MsLimitTypeStatusCheck(id, c, i, t, 0, 2);
                            MsStatusEffectReflect(i);
                            MsRegSEplay2(i, 0x3B);
                        }
                    }
                    cmd->pad5[0] = 1;
                    break;
                case 1: {
                    int count = 0;
                    for (i = 0; i < 0x1F; i++) {
                        if ((mask >> i) & 1) {
                            if (MsGetChr(i)->fB64 != 0) {
                                count++;
                            }
                        }
                    }
                    if (count == 0) {
                        cmd->pad5[0] = 2;
                        c->fACD = 1;
                        if (c->padAD4 == 0) {
                            func_001CD8A0(id, c);
                        }
                    }
                    break;
                }
                }
            } else {
                c->fACD = 1;
                if (c->padAD4 == 0) {
                    func_001CD8A0(id, c);
                }
            }
        }
    }
}

int MsEffectMotionLevel(int arg) {
    int r = 0;
    u8 *p = (u8 *)&arg; /* DEBT(CAST): 4-byte id/kind pair passed as int */
    u8 id = p[0];

    switch (p[1]) {
    case 0x80:
        r = 1;
        break;
    case 2:
    case 4:
    case 7:
        r = MsGetChr(id)->fACD;
        break;
    }
    return r;
}

void func_001CDB68(BtlChr *c, s32 target, s32 mode, s32 flag)
{
    u8 id;
    u8 command;

    id = c->f0C;
    MsPopBtlPos(c);
    command = c->fAC1;
    c->fC5 = (u8) flag;
    if (mode == 1)
    {
        if (command != 0xFF)
        {
            MsSetMotion((s32) id, (s32) command, 1, target, 1, 0, 0);
        }
    }
    else
    {
        MsSetMotion((s32) id, 0x33, 1, target, 1, 0, 0);
    }
    func_001CD900(id, c);
    if (c->fD3 == 0)
    {
        c->fD4 = 1;
    }
    if (c->padAD4 != 0)
    {
        func_001CD8A0(id, c);
    }
    MsRegSEfade((s32) id, (u32) c->fC36, 0x14);
}

void MsEffectReady(int arg, int v) {
    u8 *p = (u8 *)&arg; /* DEBT(CAST): 4-byte id/kind pair passed as int */
    u8 id = p[0];
    switch (p[1]) {
    case 2: {
        BtlChr *c = MsGetChr(id);
        if (c->fABB == 4) {
            func_001CDB68(c, c->fD3 == 0, v, 0);
            MsEffectCameraCall(arg, 0);
            c->fABB = 5;
        }
        break;
    }
    case 4:
    case 7:
        break;
    case 0x80:
        if (D_00662618 == 4) {
            D_00662618 = 5;
        }
        break;
    }
}

void func_001CDD38(int arg) {
    u8 *p = (u8 *)&arg; /* DEBT(CAST): 4-byte id/kind pair passed as int */
    u8 id = p[0];
    if (p[1] == 2) {
        BtlChr *c = MsGetChr(id);
        u8 k;
        c->fC5 = 0;
        k = c->fAC1;
        MsEffectResetMotionDisable(c);
        if (k != 0xFF) {
            u8 s = c->fDB;
            c->fDB = 1;
            MsSetMotion(id, k, 1, 0, 1, 0, 0);
            c->fDB = s;
        }
    }
}

void MsEffectTerminate(int arg) {
    u8 *p = (u8 *)&arg;
    u8 id = p[0];
    BtlChr *c;

    if (MsGetChrTop() != 0) {
        c = MsGetChr(id);
    } else {
        c = 0;
    }
    switch (p[1]) {
    case 2:
        if (c->fABB != 5) {
            MsBattleError(D_0056E8F0);
        } else {
            c->fABB = 6;
        }
        break;
    case 0x80:
        D_00662618 = 6;
        break;
    case 4:
        if (c->fB7 != 0 && c->fF6 != 0) {
            c->fB7 = 0;
            c->fF6 = 0;
        }
        break;
    case 7:
        if (c->fAD2 != 0) {
            c->fAD2--;
        }
        break;
    case 8:
        if (c->fAD3 != 0) {
            c->fAD3--;
        }
        break;
    case 9:
        if (arg == c->fB64) {
            c->fB64 = 0;
        }
        break;
    case 10:
        if (_gs_eff_read.f1754 != 0) {
            _gs_eff_read.f1754 = 0;
        }
        break;
    case 14:
        if (_gs_eff_read.f2028 != 0) {
            _gs_eff_read.f2028--;
        }
        break;
    case 15:
        if (c->fB7 != 0 && c->fF6 != 0) {
            if (_gs_eff_read.f213C != 0) {
                _gs_eff_read.f213C--;
            }
            c->fB7 = 0;
            c->fAD7 = 1;
            c->fF6 = 0;
        }
        break;
    }
    if (_gs_eff_read.f2107 != 0 && _gs_eff_read.f20 == arg) {
        _gs_eff_read.f2107 = 0;
    }
}

int MsEffectCheck(void) {
    int i;
    int n = 0;
    for (i = 0; i < 0x1F; i++) {
        if (MsGetChr(i)->fABB != 0) {
            n++;
        }
    }
    return n;
}

u8 MsGetEff2Chr(u8 x) {
    return x;
}

int func_001E1C70(int id, BtlChr *c, int b, int b0);
int Ch_MotionSetHokan(Chr *chr, int v);
int Ch_GetSeqFrame(Chr *chr);

int func_001CE050(int id, int b) {
    int res = 0;
    BtlChr *c;
    Chr *chr;

    id &= 0xFF;
    c = MsGetChr(id);
    chr = c->chr;
    if (chr != 0 && c->f38 != 0 && c->fA8E == 0) {
        int flag = b & 0x8000;
        b &= 0xFFFF7FFF;
        c->f10F = 0;
        c->fB3 = 1;
        c->fF2 = 1;
        c->f1CD = 0;
        c->fCA = 0;
        c->f108 = 0;
        c->fE9 = 0;
        if (c->fC4 == 0) {
            MsEffectSetSpeed(id, c->fBC);
        }
        Ch_ResetMotion(chr);
        Ch_SetSysMotion((int)chr, c->f20, b);
        if (flag != 0) {
            Ch_MotionSetNextHokan(chr, 0);
            Ch_MotionSetHokan(chr, 0);
        } else {
            if ((c->flags & 0x80) == 0) {
                Ch_MotionSetNextHokan(chr, 0);
            }
            Ch_MotionSetHokan(chr, func_001E1C70(id, c, b, c->fB0));
        }
        c->fB0 = b;
        res = Ch_GetSeqFrame(chr);
        if (res <= 0) {
            c->fF4 = 1;
        } else {
            c->fF4 = 0;
        }
    }
    return res;
}

int MsEffectCheckMotion(int arg) {
    u8 id = arg;
    BtlChr *c = MsGetChr(id);
    if (c->chr == 0 || c->fC0 == 0) return -1;
    if (Ch_GetWaitMotion(c->chr) != 0) {
        D_003172F0.f2138 = id;
        D_003172F0.f2139 = c->fB0;
        return 0;
    }
    return -1;
}

int MsEffectCheckMotion2(int arg) {
    u8 id = arg;
    BtlChr *c = MsGetChr(id);
    if (c->chr == 0 || c->fC0 == 0 || Ch_GetWaitMotion(c->chr) == 0 || c->fF4 != 0) return -1;
    D_003172F0.f2138 = id;
    D_003172F0.f2139 = c->fB0;
    return 0;
}

int MsEffectResetMotionDisable(BtlChr *c) {
    if (c->fB3 != 0) {
        c->fB2 = 0xFF;
        c->fB3 = 0;
        c->fC1E &= 0xFD;
        c->fAB2 = 0;
        MsTerminateMotion(c);
        return 1;
    }
    return 0;
}

void MsEffectEndMotion(int id, int a) {
    int ch = id & 0xFF;
    BtlChr *c = MsGetChr(ch);
    int run;
    int arg;

    if (MsEffectResetMotionDisable(c) != 0) {
        if (a != 3) {
            MsSetChrMoveFlag(ch, 0);
        }
        run = 0;
        arg = 0;
        switch (a) {
        case 5:
            run = 1;
            c->f10F = 3;
            break;
        case 4:
            if (MsGetRamChrSummon(ch) != 0) {
                c->f10F = 1;
            } else {
                c->f10F = 2;
            }
        case 0:
        case 3:
            run = 1;
            break;
        case 1:
        case 6:
            c->f109 = a;
            c->fDC = 0;
            break;
        }
        c->f110 = 0;
        if (c->fF6 != 0) {
            run = 1;
            arg = 8;
        }
        MsSetChrWeak(ch, -1);
        if (run != 0) {
            MsSetMotion(ch, arg, 0, 0, 1, 0, 0);
        }
    }
}

void MsEffectSetSpeed(int id, int v) {
    BtlChr *c = MsGetChr((u8)id);
    if (v < 0) {
        c->fC4 = 0;
    } else {
        c->fC2 = v;
        c->fC4 = 1;
    }
    MsCalcMotionSpeed(c);
}

void MsResetBindEffect(int id) {
    BtlChr *c = MsGetChr((u8)id);
    Chr *p = c->chr;
    if (p != 0) {
        c->f1F = 0;
        Ch_EffectSetEffectLevel(p, 0);
        func_00299218(p);
    }
}

void MsResetAfterImage(BtlChr *p) {
    if (p->fB68 != 0) {
        func_00297CE8(p->fB68);
        p->fB68 = 0;
    }
}

void func_001CE4F8(u8 id) {
    BtlChr *c;
    if (MsBtlChrNumCheck(id)) {
        c = MsGetChr(id);
        c->fB3 = 1;
        c->fB0 = 0xFF;
    }
}

void MsSetChrMoveFlagAll(int flag) {
    int i;
    for (i = 0; i < 0x1F; i++) {
        BtlChr *c = MsGetChr(i);
        c->fD2 = flag;
        c->fC4 = 0;
        MsSetChrSpecular(i, 0x1E, 0.0f);
        if (flag != 0) {
            msSetChrBodyHit(c, 2, 0);
        }
    }
}

void MsEffectWaitFlag(int flag) {
    D_003193F6 = flag & 1;
}

void MsEventEffectInit(void) {
    D_00662618 = 0;
    D_00662614 = 0;
    D_00662620 = 0;
}

void func_001CE5F0(void) {
    if (D_00662614 != 0 && D_00662618 == 1) {
        D_00662618 = 3;
    }
}

int MsEventEffectRead(int a) {
    if (D_00662618 == 0) {
        D_003172F0.f2018 = a;
        if (D_003172F0.f33 != 0) {
            a = 0;
        }
        GetCD()->f10(0x11);
        a = func_001CCD38(a, -1);
        if (GetCD()->f14(a) > 0) {
            int addr = 0x1B00000;
            D_00662618 = 1;
            D_00662614 = addr;
            op_ovl_effect_init();
            GetCD()->f0(a, 0x1B00000, func_001CE5F0, 0);
        }
    } else {
        MsBattleError(D_0056E8A0);
    }
    return D_00662618;
}

/* DEBT(CAST): D_00662614 remains declared as an integer callback-object handle. */
void MsEventEffectProcess(void)
{
    if (D_00662618 == 6) {
        if (D_00662614 != 0) {
            func_002F8660(0);
            ((CbObj *)D_00662614)->f4(0);
            func_002F8660(0);
            MsEffectCameraEnd(1);
            op_ovl_effect_free();
            D_00662618 = 0;
            D_00662614 = 0;
            Sg_SetKeepFps(D_00319419);
        }
    }
}

int MsEventEffectFree(void) {
    if (D_00662618 != 0) {
        yiAssert(1, D_0056E930, D_0056E948, D_00662620);
        D_00662618 = 6;
        MsEventEffectProcess();
        return 1;
    }
    return 0;
}

s8 MsEventEffectGetStat(void) {
    return D_00662618;
}

typedef struct {
    int (*f0)(int);
} Unk1CE800Cb;

int MsEventEffectStart(int a) {
    if (D_00662618 == 3) {
        int id;
        Unk1CE800Cb *cb;
        D_00319419 = Sg_SetKeepFps(0);
        id = MsGetEffID(D_0031FA14, 0x80, a);
        D_00662620 = id;
        D_00662618 = 4;
        cb = (Unk1CE800Cb *)D_00662614;
        func_002F8660(0);
        func_002F8660(2);
        cb->f0(id);
        D_0031FA14++;
    }
    return D_00662618;
}

void MsEffectCameraCall(int v, int b) {
    if (v >= 0) {
        D_003172F0.f20 = v;
    }
    D_003172F0.f2107 = b;
}
