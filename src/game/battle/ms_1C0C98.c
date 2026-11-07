/* tu_193 0x1c0c98-0x1c5e90: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

struct Obj436Slot *func_001C0C98(Obj436 *o) {
    struct Obj436Slot *p = 0;
    int i;

    for (i = 0; i < 2; i++) {
        if (o->slot[i].v == 0xFF) {
            p = &o->slot[i];
            MsStructClear(p, sizeof(struct Obj436Slot));
            break;
        }
    }
    return p;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C0D00);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsCalcCommand);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsCalcDamage);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C1368);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C14F0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C1908);

int func_001C2500(int unused, BtlChr *c, Q4Act *act, int *q, int force) {
    int r = 0;
    if ((act->h20 >> 4) & 1) {
        if (q[0] < 0 || q[1] < 0 || q[2] < 0) r = 1;
    } else {
        if (q[0] > 0 || q[1] > 0 || q[2] > 0) r = 1;
    }
    if (force) r = 1;
    if (r) c->f3D5 = 1;
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsCalcMagic);

void MsUseChrMpLimit(int id) {
    BtlChr *c = MsGetChr(id);
    c->f294 = MsCheckRange(c->f294 - c->f38C, 0, 9999);
    c->f27C = MsCheckRange(c->f27C - c->f38D, 0, c->f27D);
    if (c->f38D != 0) {
        MsSummonLimitLoad(c);
        func_001E2560(id);
    }
    c->f38C = 0;
    c->f38D = 0;
}

int func_001C2758(BtlChr *c, u32 *flags, int dmg) {
    u16 f = c->f2D6;
    if ((f >> 6) & 1) {
        c->f39A = 1;
        dmg /= 4;
        *flags |= 0x8000;
    }
    if ((f >> 7) & 1) {
        dmg = dmg * 3 / 2;
    }
    return dmg;
}

int func_001C27C0(BtlChr *c, int v) {
    if (((c->f2C6 >> 9) & 1) && c->fC1C == c->f386) {
        v = v * 3 / 2;
    }
    return v;
}

int func_001C2800(BtlChr *c, OfsTbl *t, int kind, int *dmg) {
    int r = 0;
    if (kind == 0x311F) {
        if (c->f28A != 0) {
            c->f28A = 0;
            if (dmg != 0) {
                *dmg = *dmg * 3 / 2;
            }
        }
    } else if (((c->f37C >> 6) & 1) && (u32)(t->b17 - 1) < 2) {
        if (dmg != 0) {
            *dmg = *dmg * 3 / 2;
        }
        r = -1;
    }
    return r;
}

int func_001C2898(BtlChr *c, Q4Act *act, int b, int kind, int dmg) {
    if (((c->f37C >> 9) & 1) && (b >> 12) == 2 && ((act->h20 >> 4) & 1)) {
        if (kind == 6 || kind == 8) {
            dmg <<= 1;
        }
    }
    return dmg;
}

int MsCheckUseCommand(int id, OfsTbl *t, int add) {
    BtlChr *c;
    int v;

    if (t != 0) {
        c = MsGetChr(id);
        if (t->b26 != 0 && (c->f27C < c->f27D || ((c->f2D6 >> 10) & 1)) && D_0031732C == 0) {
            return -1;
        }
        if (((t->flags >> 17) & 1) && c->f2C9 != 0) {
            return -1;
        }
        v = MsGetCommandMP(id, t);
        if (MsGetRamChrMonster(id) == 1 || D_00317321 != 0) {
            v = 0;
            add = 0;
        }
        return (c->f294 < v + add) ? -1 : v;
    }
    return -1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsGetCommandMP);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsGetCommand);

/* DEBT(CAST) */
s32 func_001C2C98(s32 id, s32 a, s32 b) {
    BtlChr *temp_4;
    OfsTbl *temp_2;
    s32 var_17;
    s32 var_5;
    s32 var_6;

    temp_2 = MsGetComData(a, 0);
    var_17 = 0;
    if (temp_2 != 0) {
        temp_4 = MsGetChr(id);
        if (!(!(((u32) temp_2->flags >> 0x12) & 1))) {
            var_6 = temp_4->f281;
            var_5 = temp_2->b2D | temp_4->f299;
        } else {
            var_6 = temp_2->b28;
            var_5 = temp_2->b2D;
        }
        switch (b) {
        case 0:
            var_17 = var_6;
            break;
        case 1:
            var_17 = (*(u16 *)((u8 *)(temp_2) + (0x20))) & 3;
            break;
        case 10:
            var_17 = ((u16) temp_2->h1A >> 2) & 3;
            break;
        case 2:
            var_17 = temp_2->pad23 & 1;
            break;
        case 3:
            var_17 = temp_2->pad23 & 2;
            break;
        case 4:
            var_17 = temp_2->pad23 & 4;
            break;
        case 5:
            var_17 = ((s32) var_5 >> 4) & 1;
            break;
        case 6:
            var_17 = ((s32) var_5 >> 3) & 1;
            break;
        case 7:
            var_17 = ((s32) var_5 >> 2) & 1;
            break;
        case 8:
            var_17 = ((s32) var_5 >> 1) & 1;
            break;
        case 9:
            var_17 = var_5 & 1;
            break;
        }
    }
    return (s32) var_17;
}

int MsGetRndChr(int id, int kind) {
    int off = 0;
    int v;
    switch (kind) {
    case 1: off = 0x10; break;
    case 2: off = 0x20; break;
    }
    if (MsGetRamChrMonster(id) == 0) {
        if (MsGetRamChrSummon(id) != 0) {
            v = 0x1B;
        } else {
            v = id + 0x14;
        }
    } else {
        v = id + 8;
    }
    return v + off;
}

int MsSetChrImageDamageAttack(BtlChr *c) {
    int a = MsCalcDamageCommand(c, c, 0, 0xE, 0x10, 0, 1, 0, 0, 0, 0);
    int b = MsCalcDamageCommand(c, c, 0, 0x14, 0x10, 0, 1, 0, 0, 0, 0);
    if (b < a) b = a;
    return c->f3B4 = b;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsCalcDamageCommand);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C0C98/rodata", jtbl_0056E5E0);

int func_001C3578(int a, int mask, Q4Flags *f) {
    int r = 0;
    int e = 0;
    int g = 0;
    int h = 0;
    int d = 0;
    int have = 0;
    int need = 0;

    if (mask & 1) {
        need++;
        if (f->b0E != 0) {
            e = f->b0E;
            have++;
        }
    }
    if ((mask >> 2) & 1) {
        need++;
        if (f->b0F != 0) {
            g = f->b0F;
            have++;
        }
    }
    if ((mask >> 1) & 1) {
        need++;
        if (f->b10 != 0) {
            h = f->b10;
            have++;
        }
    }
    if ((mask >> 3) & 1) {
        need++;
        if (f->b0D != 0) {
            d = f->b0D;
            have++;
        }
    }
    if (have > 0 && have >= need) {
        if (e != 0 && e < 0xFE) {
            e--;
            f->b0E = e;
        }
        if (g != 0 && g < 0xFE) {
            g--;
            f->b0F = g;
        }
        if (h != 0 && h < 0xFE) {
            h--;
            f->b10 = h;
        }
        if (d != 0 && d < 0xFE) {
            d--;
            f->b0D = d;
        }
        r = -1;
    }
    return r;
}

int func_001C3688(int flag, int a, BtlChr *c, int b, BtlChr *c2, Q4Act *act) {
    int r = 0;
    int mode = act->h20 & 3;
    if (((act->h1A >> 2) & 3) == 0) {
        if (c->fAB1 != 0) goto end; /* DEBT(GOTO): an early return r gets folded to return 0 */
        if (a != b && *(s8 *)&D_00319432 != 0 /* DEBT(TYPE): read as signed here */) {
            if (mode == 1) {
                if ((c2->f37C >> 4) & 1) {
                    r = 2;
                } else if ((c2->f37C >> 3) & 1) {
                    r = 1;
                }
            } else if (mode == 2) {
                if ((c2->f37C >> 5) & 1) r = 1;
            }
            if (flag != 0 && r != 0 && MsCheckWrongStatus(act) != 0) {
                c2->f39C = 1;
            }
        }
    }
end:
    return r;
}

int func_001C3758(int id, BtlChr *c, int x, BtlChr *c2) {
    int r = 0;
    if (MsAutoCommandStatusCheck(c2, 1, 1, 1) != 0) {
        GsEnt48 e;
        r = 1;
        if (c->f106 == 1) {
            c->f39D = 1;
        } else {
            c->f39D = 0;
        }
        MsStructClear(&e, 0x48);
        e.id = x;
        e.f3 = 1;
        e.f8[0].h0 = c2->f386;
        e.f8[0].h2 = 0xFF;
        e.f8[0].targets = 1 << id;
        MsInsertBtlCommand(&e, 0, 1, id);
    }
    c2->f39C = 0;
    return r;
}

void func_001C3828(int unused, BtlChr *c, Q4Act *act, int unused2, int *cnt, Q4Act *b) {
    if ((act->h20 & 3) == 1) {
        if (((b->h14 >> 8) & 1) && !((c->f2EA >> 8) & 1)) {
            b->h14 &= ~0x100;
            cnt[1]++;
        }
        if ((u32)(b->b07 - 1) < 0xFE) {
            c->f1CF = 1;
            b->b07 = 0;
            cnt[2]++;
        }
    }
}

int func_001C38A8(Q4Act *act, u32 *flags, int *mode, Q4Flags *f, int dmg) {
    int m = act->h20 & 3;
    if (m == 2 && f->b0A != 0) {
        *mode = m;
        dmg /= 2;
        *flags |= 0x20;
    }
    return dmg;
}

int func_001C38E8(Q4Act *act, u32 *flags, int *mode, Q4Flags *f, int dmg) {
    if ((act->h20 & 3) == 1 && f->b0B != 0) {
        *mode = 2;
        dmg /= 2;
        *flags |= 0x40;
    }
    return dmg;
}

int func_001C3930(BtlChr *c, BtlChr *c2, Q4Act *act, u32 *flags, int dmg) {
    int r;
    int v;

    if ((act->h20 >> 2) & 1) {
        r = brnd(MsGetRndChr(c->f0C, 0)) % 101;
        v = c->f26D + c->f322 - c2->f26D + c2->f323;
        if ((act->h20 >> 3) & 1) {
            v += c->f298;
        } else {
            v += act->b27;
        }
        if (r < v || ((c->f300 >> 4) & 1) || D_0031732D != 0) {
            dmg *= 2;
            *flags |= 0x100;
        }
    }
    return dmg;
}

int func_001C3A38(BtlChr *c, int kind, u32 *flags, u32 mask, int *cnt, int ret) {
    if (kind == 8 || kind == 5) {
        if ((c->flags278 >> 1) & 1) {
            *flags &= ~mask;
            ret = 0;
            (*cnt)++;
        }
    }
    return ret;
}

int func_001C3A88(BtlChr *c, Q4Act *a, Q4Act *b, int dmg) {
    int s = ((c->f2C6 >> 1) & 1) + ((b->h14 >> 1) & 1);
    if ((a->w1C >> 8) & 1) {
        if (s == 1) {
            dmg = -dmg;
        }
    }
    return dmg;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C3AD0);

int func_001C3C90(BtlChr *c, BtlChr *c2, Q4ActB *a2, Q4Act *a3, int *out, int dmg) {
    if ((a2->h1E & 1) == 0 && (c2->flags278 & 1) != 0) {
        if (((c->f37C >> 13) & 1) == 0 && ((a3->h14 >> 6) & 1) == 0) {
            dmg /= 3;
            *out = 1;
        }
    }
    return dmg;
}

int func_001C3D00(BtlChr *c, Q4Act *a, u32 *flags, Q4Act *b, int dmg) {
    if ((a->h20 & 3) == 1 && (((b->h16 >> 11) & 1) || ((b->h16 >> 13) & 1))) {
        c->f39A = 1;
        dmg /= 2;
        if ((b->h16 >> 11) & 1) {
            *flags |= 8;
        } else {
            *flags |= 0x10;
        }
    }
    return dmg;
}

int func_001C3D78(Q4Act *a, Q4Act *b, int dmg) {
    if ((a->h20 & 3) != 1 && ((b->h16 >> 7) & 1) != 0) {
        dmg /= 5;
    }
    return dmg;
}

int func_001C3DC0(BtlChr *c, Q4Act *act, int dmg) {
    int m = act->h20 & 3;
    if (m == 1) {
        if ((c->f2C6 >> 4) & 1) {
            dmg /= 2;
        }
    }
    if (m == 2) {
        if ((c->f2C6 >> 5) & 1) {
            dmg /= 2;
        }
    }
    return dmg;
}

int func_001C3E20(BtlChr *c, Q4Act *act, u32 *flags, u32 mask, int *cnt, int ret) {
    int r = 0;
    int m = act->h20 & 3;
    if (m == 1 && ((c->flags278 >> 5) & 1)) r = 1;
    if (m == 2 && ((c->flags278 >> 6) & 1)) r = 1;
    if ((c->flags278 >> 7) & 1) r = 1;
    if (r) {
        *flags &= ~mask;
        ret = 0;
        (*cnt)++;
    }
    return ret;
}

int func_001C3EA0(BtlChr *c, int v) {
    if (c->f9E6 != 0) {
        float d = c->f9F0 + c->f9F0;
        v = v * (d + c->f9EC) / d;
    }
    return v;
}

void func_001C3EE8(int unused, Q4Act *a, int b, int *p, int *cnt, int *arr) {
    int i;
    if (((a->h14 >> 2) & 1) != 0 && ((b >> 2) & 1) != 0 && ((a->h16 >> 8) & 1) == 0) {
        *p = 0;
        for (i = 2; i >= 0; i--) {
            arr[i] = 0;
        }
        cnt[6]++;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C3F58);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C4008);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C0C98/rodata", jtbl_0056E640);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1C0C98/rodata", jtbl_0056E660);

u32 func_001C4290(BtlChr *c, Q4Act *act, u32 flags, Triple *t) {
    int k;
    if ((act->w1C >> 14) & 1) {
        k = 2;
    } else {
        k = (act->w1C >> 13) & 1;
    }
    if (k != 0) {
        int v;
        flags |= 4;
        v = MsGetRomCTBcount(c->f26C) * 3;
        t->w8 += v * k / 2;
    }
    return flags;
}

int func_001C4320(int a, Q4Act *act, u32 *flags, u32 mask, int t0, Triple *cnt, Triple *t2) {
    if ((t0 & 4) && ((act->h14 >> 11) & 1)) {
        t2->w8 = 0;
        *flags &= ~mask;
        cnt->w4 += 1;
    }
    return t0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C4368);

int func_001C4EF0(int x) {
    if (((x >> 1) & 1) || ((x >> 2) & 1) || ((x >> 3) & 1) || ((x >> 4) & 1) || ((x >> 5) & 1)) {
        return -1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C4F40);

/* DEBT(CAST) */
s32 func_001C5340(s32 arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    s32 temp_19;
    s32 temp_3;
    s32 var_22;

    var_22 = 0;
    if ((*(s32 *)((u8 *)(arg2) + (0x1C))) < 0) {
        temp_19 = ((u32) ((u32) ((D_003172F0.f15C0 + (*(s32 *)((u8 *)(arg1) + (0x3C4)))) << 8) / (u32) (*(u32 *)((u8 *)(arg1) + (0x254)))) / 20U) - 0x40;
        temp_3 = brnd(MsGetRndChr(arg0, 2)) & 0xFF;
        if ((((u16) (*(u16 *)((u8 *)(arg1) + (0x278))) >> 0xA) & 1) || ((*(u8 *)((u8 *)(arg4) + (7))) != 0)) {
            (*(s32 *)((u8 *)(arg3) + (0x14))) = (s32) ((*(s32 *)((u8 *)(arg3) + (0x14))) + 1);
        } else if (((temp_3 < temp_19) && (D_003172F0.f15C0 > 0)) || ((s8) D_003172F0.pad34[6] != 0)) {
            (*(s32 *)((u8 *)(arg1) + (0x3C8))) = temp_19;
            (*(s8 *)((u8 *)(arg1) + (0x3C1))) = 2;
            var_22 = 1;
            (*(u16 *)((u8 *)(arg4) + (0x16))) = (u16) ((*(u16 *)((u8 *)(arg4) + (0x16))) | 0x100);
            (*(s32 *)((u8 *)(arg3) + (0x10))) = (s32) ((*(s32 *)((u8 *)(arg3) + (0x10))) + 1);
        } else {
            (*(s32 *)((u8 *)(arg3) + (0x18))) = (s32) ((*(s32 *)((u8 *)(arg3) + (0x18))) + 1);
        }
        (*(s32 *)((u8 *)(arg1) + (0x3C4))) = MsCheckRange((*(s32 *)((u8 *)(arg1) + (0x3C4))) + D_003172F0.f15C0, 0, 0x3B9AC9FF);
    }
    return var_22;
}

int func_001C54A0(BtlChr *c, Triple *t, Q4Cnt *n, int unused, int t0, int t1) {
    if (t0 & 4) {
        if (((c->flags278 >> 8) & 1) && t1 == 0) {
            n->w14++;
            t->w8 = 0;
        } else if (t->w8 != 0) {
            n->w10++;
        }
    }
    return t0;
}

u32 func_001C54F8(int unused, Q4Act *a, int b, u32 flags, int *out) {
    if ((b & 1) == 0 && (a->h14 & 1) != 0) {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        flags &= ~7;
    }
    return flags;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C5538);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C55D0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C5798);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", MsCalcDrainResult);

int func_001C5A80(int a, int b) {
    int n = 0;
    if (MsBtlChrNumCheck(a) != 0) {
        int m = MsGetChrBit(a, b, 1, 1);
        int i;
        for (i = 0; i < 0x1F; i++) {
            if ((m >> i) & 1) {
                n++;
                MsGetChr(i)->fE5 = 0;
            }
        }
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0C98", func_001C5B10);

int func_001C5E60(int a, int *p) {
    int r = 0;
    if (a == 0) {
        r = p[1] != 0;
    }
    if (p[1] == 0) {
        if (p[0] != 0) {
            r = 2;
        }
    }
    return r;
}
