#include "iopsound.h"

typedef struct {
    u8 pad00[0x358];
    s32 unk358;
    u8 pad35C[0x14];
    u32 unk370;
    u32 pad374;
    s32 unk378;
    u8 pad37C[0xC];
    s16 unk388;
    s16 unk38A;
    u8 pad38C[0x4];
} S000CD0_A; /* size 0x390 = 912 */

typedef struct {
    u8 pad00[0x137];
    u8 unk137;
} S000CD0_B;

typedef struct {
    u8 pad00[0x1C];
    s32 unk1C;
    u8 pad20[0x50];
    S000CD0_B *unk70;
    u8 pad74[0xC];
    s32 unk80;
    u8 pad84[0x8];
    s32 unk8C;
} S000CD0_C;

typedef struct {
    u8 pad00[0x4C];
    u32 unk4C;
    u8 pad50[0x24];
} S000CD0_D; /* size 0x74 = 116 */

extern s32 D_016CB0;
extern s32 D_016CB4;
extern s32 D_018700;
extern volatile s32 D_018720;
extern s32 D_018724;
extern s32 D_01874C;
extern S000CD0_C *D_018754;
extern s8 *D_018758;
extern S000CD0_D *D_0192F0;
extern void *D_019314;
extern u32 D_01931C[];
extern S000CD0_A *D_01936C;
extern S000CD0_A *D_019374;
extern s32 D_019380;
extern s32 D_122450;

extern void func_0003E0(void);
extern void func_000824(void);
extern void func_0025E8(void);
extern void func_002BEC(void);
extern void func_006954(S000CD0_A *, void *, s32, s32);
extern void func_0093C8(void *, s32, s32);
extern void func_00DAC4(void);
extern void func_00E394(s32, s32);
extern void func_00EFEC(void);
extern void func_013D8C(void);

void func_000CD0(void) {
    S000CD0_A *p;
    S000CD0_C *c;

    if (D_018724 != 0) {
        func_002BEC();
        func_0025E8();
    }
    if (D_01874C != 0) {
        func_0093C8(D_019314, 1152, 0);
        D_01874C = 0;
    }

    {
        S000CD0_A *q = D_01936C;
        s32 arg2 = *(s32 *)&q[2];
        s32 arg3;
        q += 2;
        arg3 = q->unk378;
        D_019374 = q;
        func_006954(q, D_019314, arg2, arg3);
    }

    {
        S000CD0_A *r = D_01936C;
        D_019374 = r;
        if (r->unk38A != 0 && !(r->unk370 & 0x10)) {
            s32 tempo = r->unk358;
            s32 rate = D_122450;
            s32 mul = (rate >> 12) & 0xFFFF;
            s32 step = tempo >> 12;
            if (mul != 0) {
                if (rate < 0) {
                    step *= mul;
                    step >>= 16;
                } else {
                    step *= (mul + 1);
                    step >>= 15;
                    step += tempo >> 12;
                }
            }
            D_019374->unk388 -= step;
            while (D_019374->unk388 <= 0) {
                D_019374->unk388 += 300;
                func_000824();
            }
        }
    }

    p = D_01936C;
    if (p[1].unk38A != 0) {
        p = &p[1];
        D_019374 = p;
        p->unk388 -= (p->unk358 >> 12);
        if (p->unk388 <= 0) {
            do {
                D_019374->unk388 += 300;
                func_000824();
            } while (D_019374->unk388 <= 0);
        }
        D_019374 = D_01936C;
    }

    D_016CB0++;
    if ((D_016CB0 & 3) == 0) {
        func_0003E0();
    }
    func_013D8C();

    c = D_018754;
    if (c->unk1C != 0 || c->unk8C != 0) {
        func_00DAC4();
    }
    func_00EFEC();

    if (D_018700 == 0 && *D_018758 == 0) {
        c = D_018754;
        if (c->unk8C != 0 && c->unk80 == 0 && !(D_0192F0[c->unk70->unk137].unk4C & 8)) {
            D_016CB4 = 1;
        } else {
            D_016CB4 = 0;
        }
        if (D_016CB4 != 0) {
            if ((u32)imp_cdvdman_28() < 2U) {
                c = D_018754;
                if (c->unk8C != 0 && c->unk80 == 0 && !(D_0192F0[c->unk70->unk137].unk4C & 8)) {
                    func_00E394(1, 1);
                    D_018720 = 1;
                }
            } else if (D_018720 != 0) {
                if (imp_cdvdman_13(1) == 2 &&
                    imp_cdvdman_12() == D_019380 &&
                    imp_cdvdman_28() == 10 &&
                    imp_cdvdman_8() == 0) {
                    D_018720 = 0;
                    func_00E394(1, 0);
                    D_01931C[0] |= 1;
                }
            }
        }
    }
}
