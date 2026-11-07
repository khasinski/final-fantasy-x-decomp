/* tu_284 0x260a70-0x265f78: low; ~ei (config/tu_map.tsv) */
#define func_00260A70 _hdr_func_00260A70
#define func_00264248 _hdr_func_00264248
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/r6.h"
#undef func_00264248
#undef func_00260A70

void func_00264248(void);



#define LPA(type, off) (*(type *)((char *)lpamng + (off)))
extern u_long128 D_00327790[];

/* local view of the float/byte members touched near the end of lpamng */
typedef struct LpaView {
    u8 pad0[0x114D8];
    float f114D8;
    float f114DC;
    u8 pad114E0[0x11550 - 0x114E0];
    float f11550;
    u8 pad11554[0x1156C - 0x11554];
    u8 f1156C;
    u8 pad1156D[0x11608 - 0x1156D];
    int f11608;
    int f1160C;
    int f11610;
    int f11614;
    s16 f11618;
    s16 f1161A;
} LpaView;
#define LPV ((LpaView *)lpamng)

s32 _m2c_func_00260A70__pppRunPart(void *, s32) __asm__("_pppRunPart");
void _m2c_func_00260A70_func_002DCE38(u8 *, u8 *, u8 *) __asm__("func_002DCE38");
void _m2c_func_00260A70_func_002DD0C0(u8 *, u8 *) __asm__("func_002DD0C0");
void _m2c_func_00260A70_pppSetMatrix(void *) __asm__("pppSetMatrix");
void func_00260A70(void *arg0) __attribute__((register_precision(s3, 128)));
/* DEBT(CAST) */
void func_00260A70(void *arg0) {
    if ((*(u16 *)((u8 *)(arg0) + (0x1E))) != 0) {
        _m2c_func_00260A70_func_002DD0C0(D_006A3A70, &lpamng->ents3[8].pad2[0x3A]);
        _m2c_func_00260A70_func_002DD0C0(D_006A3970, lpamng->ents3[7].pad4C);
        (*(float *)((u8 *)(D_006A3A70) + (0x38))) = (float) ((*(float *)((u8 *)(D_006A3A70) + (0x38))) + 29184.0f);
        _m2c_func_00260A70_pppSetMatrix(arg0);
        _m2c_func_00260A70_func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        _m2c_func_00260A70_func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = (HeapMgr *) D_006A3690;
        if (_m2c_func_00260A70__pppRunPart(arg0, 0x30) != 0) {
            (*(u16 *)((u8 *)(arg0) + (0x1E))) = 0U;
        }
    }
}

float func_00260B68(void)
{
    switch (lpamng->f1157C) {
    case 0:
        return 1.0f;
    case 1:
        return 0.5f;
    case 2:
        return 0.25f;
    case 3:
        return 0.125f;
    default:
        return 1.0f;
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00260C08);

float func_00260D50(void)
{
    switch (lpamng->f1157B) {
    case 0:
        return 0.0f;
    case 1:
        return -3640.0f;
    case 2:
        return -7281.0f;
    default:
        return 0.0f;
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00260DD8);

void func_00260F60(void)
{
    u_long128 *src = (u_long128 *)((char *)lpamng + 0x112C0);
    LPA(u_long128, 0x11310) = *src;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00260F88);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00261130);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00261288);

/* header prototypes say (void); the real signature is (int, float) */
void func_002613B8_impl(int a, float f) __asm__("func_002613B8");
void func_002613B8_impl(int a, float f)
{
    GlobalWork *w;
    float v;

    LPA(u_long128, 0x115F0) = LPA(u_long128, 0x112C0);
    lpamng->f115D4 = f;
    lpamng->f115D8 = LPA(float, 0x112FC);
    lpamng->f115D0 = 0.0f;
    v = func_002596D8(a);
    w = lpamng;
    w->f115E4 = a;
    *(u16 *)((char *)w + 0x11304) = a;
    w->f115DC = v;
}

void func_00261430(void)
{
    GlobalWork *w;

    func_002613B8();
    w = lpamng;
    if (w->next_a == 0) {
        w->next_a = w->cb_a;
        w->cb_a = func_00261288;
    }
}

void func_00261478(void)
{
    if (D_006A362E == 0) {
        lpamng->cb_a = lpamng->next_a;
        lpamng->cb_b = lpamng->next_b;
        lpamng->next_a = 0;
        lpamng->next_b = 0;
    }
}

void func_002614B8(void)
{
    func_00257288(0);
    func_00260A70(D_006A3610);
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_002614E0);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00261728);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_002618E0);

void func_00261C08(void)
{
    u8 state = lpamng->f11600;

    if (state == 0 || state == 2) {
        func_002614B8();
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00261C40);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00261DC8);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00261E98);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", abmap_cheng_panel);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262258);

void func_002622D0(void)
{
    u_long128 *src;

    LPV->f11550 = 256.0f;
    src = (u_long128 *)((char *)lpamng + (LPV->f1156C * 0x50 + 0x11090));
    LPA(u_long128, 0x114D0) = *src;
    LPV->f114D8 = ((float *)src)[2] - 32.0f;
    LPA(u_long128, 0x11510) = D_00327790[LPV->f1156C];
    LPV->f114DC = LPV->f11550 + LPV->f11550;
    func_00262258();
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262360);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_002626D0);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262740);

void func_00262880(void)
{
    lpamng->f115D8 = lpamng->ents3[6].f48;
    lpamng->f115D0 = 0.0f;
    lpamng->f115DC = func_002596D8(lpamng->ents3[7].h0);
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_00262740;
    }
}

void func_002628F0(void)
{
    lpamng->f11574 = 0;
    lpamng->cb_a = func_00263DE8;
    lpamng->cb_b = func_0025C2B0;
    lpamng->f11573 = 0;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262930);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262A40);

void func_00262B28(ChrWork *w)
{
    int t;
    s16 r[4]; /* DEBT(PADDING): unused, only reproduces the 16-byte frame */
    int d;

    if (++w->f32 >= 4) {
        w->rect1[0] = w->rect2[0];
        w->rect1[1] = w->rect2[1];
        w->rect1[2] = w->rect2[2];
        w->rect1[3] = w->rect2[3];
        w->f34 = 0;
    } else {
        t = w->f32 << 14;
        d = (s16)w->rect2[0] - (s16)w->a.rect[0];
        w->rect1[0] = w->a.rect[0] + ((d * t) >> 16);
        d = (s16)w->rect2[1] - (s16)w->a.rect[1];
        w->rect1[1] = w->a.rect[1] + ((d * t) >> 16);
        d = (s16)w->rect2[2] - (s16)w->a.rect[2];
        w->rect1[2] = w->a.rect[2] + ((d * t) >> 16);
        d = (s16)w->rect2[3] - (s16)w->a.rect[3];
        w->rect1[3] = w->a.rect[3] + ((d * t) >> 16);
    }
    w->f14 = ((s16)w->rect1[2] + 15) / 16;
    w->f16 = ((s16)w->rect1[3] + 15) / 20;
}

void func_00262C40(int i, int a, int b, int c, int d) {
    ChrWork *w = D_006A391C + i;

    a += 0x20;
    c = (c << 4) + 0x20;
    d *= 0x14;
    w->f34 = func_00262B28;
    w->rect2[0] = a;
    w->rect2[1] = b;
    w->rect2[2] = c;
    w->rect2[3] = d;
    w->f32 = 0;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262C90);

void func_00262DC8(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    chr->f34 = func_00262C90;
    chr->rect2[0] = chr->rect1[0];
    chr->rect2[1] = chr->rect1[1];
    chr->rect2[2] = chr->rect1[2];
    chr->rect2[3] = chr->rect1[3];
    chr->f32 = 0;
}

void func_00262E10(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    chr->rect1[0] = chr->a.rect[0];
    chr->rect1[1] = chr->a.rect[1];
    chr->rect1[2] = chr->a.rect[2];
    chr->rect1[3] = chr->a.rect[3];
    chr->f14 = chr->f10;
    chr->f16 = chr->f12;
}

void func_00262E58(int a, V6Arg8 *b, int c, int d)
{
    if (d != 0) {
        func_0025AFA0(8);
        func_00262C40(8, 10, 0x174, 0xC, 1);
        func_00262930(lpamng->f1156C, lpamng->ents3[lpamng->f1156C].h0, b->h8);
    } else {
        func_00264210();
    }
}

void func_00262ED8(int a, int b, int sel, int ok) /* DEBT(NAME): argument meaning guessed (menu callback) */
{
    if (ok != 0) {
        if (sel == 0) {
            SndSepPlaySimple(0x80000051);
            func_00262A40();
            func_0025AFA0(7);
            if (D_006A3600 != 0) {
                func_00262C40(7, 10, 0x174, 4, 1);
            } else {
                func_00262C40(7, 10, 0x174, 2, 1);
            }
        } else if (sel == 1) {
            SndSepPlaySimple(0x80000001);
            func_00264248();
        }
    } else {
        func_002628F0();
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262F88);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_002632D8);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00263580);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_002636B8);

void func_00263840(void)
{
    ChrWork *chr;

    func_0025AFC0(7);
    func_0025AFA0(9);
    chr = func_0025B010(0xB, func_002636B8);
    chr->f18 = 0;
    chr->f24 |= 0xC;
}

void func_00263888(void)
{
    GlobalWork *w = lpamng;

    w->cb_a = func_00263840;
    w->cb_b = 0;
    w->f11573 = 0;
}

int func_002638B0(u8 *p)
{
    return p[0x22] & 1; /* DEBT(CAST): record type unknown, raw byte offset */
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_002638C0);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_002639B8);

void func_00263B30(ChrWork *w)
{
    w->f29++;
    if (w->f29 >= 3) {
        w->f23 = 0;
        w->f34 = 0;
        return;
    }
    w->rect1[1] = w->a.rect[1] + (w->f29 * (s16)w->a.rect[3]) / 3 + (s16)w->a.rect[3] / 6; /* DEBT(TYPE): rect read signed */
}

void func_00263B98(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    if (chr->f23 != 0 || chr->f34 != 0) {
        chr->f29 = 0;
        chr->f34 = func_00263B30;
    }
}

void func_00263BD8(int a) /* DEBT(TYPE): header says int, argument is a ChrWork * */
{
    ChrWork *w = (ChrWork *)a;

    w->f23 = 1;
    w->f29++;
    if (w->f29 >= 3) {
        w->f34 = 0;
        w->rect1[1] = w->a.rect[1];
        return;
    }
    w->rect1[1] = w->a.rect[1] + ((3 - w->f29) * (s16)w->a.rect[3]) / 3 + (s16)w->a.rect[3] / 6;
}

void func_00263C58(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    if (chr->f23 == 0 || chr->f34 != 0) {
        chr->f29 = 0;
        chr->f34 = func_00263BD8;
    }
}

void func_00263C98(void) {
    func_00261288();
    if (lpamng->f115D0 >= 1.0f) {
        func_00264210();
    }
}

void func_00263CE8(int id, float f)
{
    if (id == lpamng->ents3[7].h0) {
        func_00264210();
        return;
    }
    func_002613B8();
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_00263C98;
    }
}

void func_00263D68(ChrWork *chr, ChrSub *sub, int cancel, int ok) /* DEBT(NAME): argument meaning guessed */
{
    func_0025AFC0(10);
    if (ok == 0 || cancel != 0) {
        SndSepPlaySimple(0x80000004);
        func_00263C58(6);
        return;
    }
    func_00258780();
    TOMenuTermAbilityMap2();
    D_00327910 = 0;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00263DE8);
INCLUDE_RODATA("build/ee_asm/game/abm/ei_260A70/rodata", jtbl_00573A40);

void func_00264108(void)
{
    if (lpamng->cb_a != 0) {
        lpamng->cb_a();
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00264140);

void func_00264210(void)
{
    ChrWork *chr;

    func_00264140();
    chr = func_0025B010(7, func_00262ED8);
    chr->f24 |= 8;
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
extern s32 _m2c_func_00264248_D_006A391C __asm__("D_006A391C");
s32 _m2c_func_00264248_func_00257FB0(u8, u16, u16) __asm__("func_00257FB0");
void _m2c_func_00264248_func_00262E58() __asm__("func_00262E58");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void ATTR_REG_PREC_S3 func_00264248(void) {
    register s32 _cond __asm__("$2");
    ChrWork *temp_18;
    register s32 var_17 __asm__("$17");
    u16 temp_19;
    void *var_16;

    var_17 = 0;
    temp_18 = _m2c_func_00264248_D_006A391C + 0x1A00;
    var_16 = _m2c_func_00264248_D_006A391C + 0x1A40;
    temp_19 = lpamng->ents3[lpamng->f1156C].h0;
    if (temp_18->f1E > 0) {
        do {
            if (_m2c_func_00264248_func_00257FB0(lpamng->f1156C, temp_19, (*(u16 *)((u8 *)(var_16) + (8)))) != 0) {
                (*(s8 *)((u8 *)(var_16) + (4))) = 0;
            } else {
                (*(s8 *)((u8 *)(var_16) + (4))) = 1;
            }
            var_17 += 1;
            var_16 += 0xC;
        } while ((_cond = (var_17 < temp_18->f1E)) != 0);
    }
    func_0025B010(8, _m2c_func_00264248_func_00262E58);
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
/* DEBT(FAKE) */
void ATTR_REG_PREC_S3 func_00264330(s32 a, s32 b) {
    register u8 *saved_reg_s1 __asm__("$17");
    u8 sp[0x10];
    s32 temp_2;
    s32 temp_2_2;
    s32 var_17;
    register s32 _v0 __asm__("$2");
    s32 var_18;

    var_17 = (s32)saved_reg_s1;
    var_18 = 0;
    func_0024CB58(b);
    temp_2 = MsGetSaveSP();
    if (temp_2 > 0) {
        do {
            temp_2_2 = TOAmapGetItemType(var_18);
            if ((func_001BFE30(temp_2_2) > 0) && (MsGetRomItem(temp_2_2, (s32 *)sp)->b5D != 0xFF)) {
                _v0 = temp_2_2 & 0xFFFF;
                __asm__ volatile("" : "+r"(var_17), "+r"(_v0));
                var_17 &= 0xFFFF0000;
                __asm__ volatile("" : "+r"(var_17), "+r"(_v0));
                var_17 |= _v0;
                func_0025B050(a, 0, var_17);
            }
            var_18 += 1;
        } while (var_18 < temp_2);
    }
}

void func_00264400(void)
{
    D_006A391C[8].f1E = 0;
    func_00264330(8, 3);
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
/* DEBT(CAST) */
void ATTR_REG_PREC_S3 func_00264418(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    OfsTbl *temp_2_2;
    s32 temp_2;
    s32 var_17;
    s32 var_4;
    u16 temp_5;

    var_17 = 0;
    temp_2 = func_001DC0D8();
    if (temp_2 > 0) {
        __asm__ volatile("" : "+r"(var_17));
        var_4 = var_17;
        do {
            temp_2_2 = MsMenuStatusNum(var_4, 0);
            if ((*(u8 *)((u8 *)(temp_2_2) + (0))) == arg1) {
                MsGetRomPlyCommand((s32) temp_2_2->a[0].y, sp);
                temp_5 = temp_2_2->a[0].y;
                func_0025B050(arg0, temp_5, temp_5 - 0x3000);
            }
            var_17 += 1;
            var_4 = var_17;
        } while (var_17 < temp_2);
    }
}

void func_002644C0(int slot)
{
    ChrWork *w = &D_006A391C[slot];
    T6_MenuEnt *e = (T6_MenuEnt *)w->sub; /* DEBT(CAST): see T6_MenuEnt */
    T6_SlotBits *p = (T6_SlotBits *)MsGetSavePlayerPtr(lpamng->f1156C); /* DEBT(CAST): see T6_SlotBits */
    int i;

    for (i = 0; i < w->f1E; i++, e++) {
        if ((p->bits[e->arg >> 4] >> (e->arg & 0xF)) & 1) {
            e->off = 0;
        } else {
            e->off = 1;
        }
    }
}

void func_00264578(void)
{
    func_002644C0(3);
    func_002644C0(2);
    func_002644C0(4);
    func_002644C0(5);
}

void func_002645A8(int a, EvtObj *p, int c, int d, int e)
{
    d += 0xE;
    if (p->b4 != 0) {
        func_00257490(p->f0, d, e, 1);
    } else {
        func_00257108(p->f0, d);
    }
}

void func_002645D8(int a, int *b) /* DEBT(TYPE) */
{
    func_00257288(func_00256FD8(b[2]));
}

void _m2c_func_002645F8_func_00257810(s32, s32, s32, s32) __asm__("func_00257810");
/* DEBT(CAST) */
void func_002645F8(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_20;
    u16 temp_17;

    temp_17 = (*(u16 *)((u8 *)(arg1) + (8)));
    temp_20 = func_001BFE30((s32) temp_17);
    if ((*(u8 *)((u8 *)(arg1) + (4))) != 0) {
        func_002576B8((s32) temp_17, arg3, arg4, 1);
        _m2c_func_002645F8_func_00257810(temp_20, (arg3 + (*(s16 *)((u8 *)(arg0) + (0xC)))) - 0x11, arg4, 1);
        return;
    }
    func_002576B8((s32) temp_17, arg3, arg4, 0);
    _m2c_func_002645F8_func_00257810(temp_20, (arg3 + (*(s16 *)((u8 *)(arg0) + (0xC)))) - 0x11, arg4, 0);
}

void func_002646E0(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 != 0) {
        func_00257490(p->f0, d, e, 1);
    } else {
        func_00257108(p->f0, d);
    }
}

void func_00264708(int a, EvtObj *p)
{
    int arg;
    Pt16 *tbl = func_00257E18(p->h8, &arg);

    if (tbl != 0) {
        func_00257288(func_00256F58(arg, tbl));
    }
}

void func_00264748(int a, EvtObj *p, int c, int d, int e)
{
    func_002571B8(p->f0, d + 4, e - 4, 0, 0x80, 0x80, 0x80, lpamng->f11569);
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
void _m2c_func_00264780_func_00257810(s32, s32, s32, s32) __asm__("func_00257810");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void ATTR_REG_PREC_S3 func_00264780(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    register u8 *saved_reg_s2 __asm__("$18");
    register PartySlot *temp_17 __asm__("$17");
    register s32 temp_19 __asm__("$19");
    register s32 var_18 __asm__("$18");
    u32 temp_3;

    var_18 = saved_reg_s2;
    temp_19 = arg4 - 4;
    temp_17 = MsGetSavePlayerPtr((s32) lpamng->f1156C);
    func_00257108((*(s32 *)((u8 *)(arg1) + (0))), arg3, temp_19);
    temp_3 = (*(u32 *)((u8 *)(arg1) + (8)));
    switch (temp_3) {
    case 0:
        var_18 = temp_17->v24;
        break;
    case 1:
        var_18 = temp_17->v28;
        break;
    case 2:
        var_18 = (s32) temp_17->pad2F[0];
        break;
    case 3:
        var_18 = (s32) temp_17->pad32[1];
        break;
    case 4:
        var_18 = (s32) temp_17->pad2F[1];
        break;
    case 5:
        var_18 = (s32) temp_17->pad32[2];
        break;
    case 6:
        var_18 = (s32) temp_17->b31;
        break;
    case 7:
        var_18 = (s32) temp_17->pad32[3];
        break;
    case 8:
        var_18 = (s32) temp_17->pad32[0];
        break;
    case 9:
        var_18 = (s32) temp_17->pad32[4];
        break;
    }
    if ((FFXGetLang() == 0) && (func_001BD360() == 0)) {
        _m2c_func_00264780_func_00257810(var_18, arg3 + 0x80, temp_19, 0);
        return;
    }
    _m2c_func_00264780_func_00257810(var_18, arg3 + 0xA0, temp_19, 0);
}

void func_002648C0(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 == 0) {
        func_00257720(p->f0, d - 0x1C, e - 4, 0);
    }
}

void func_002648E8(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 == 0) {
        d -= 0x1C;
        if ((c & 3) == 3) {
            d -= 0x14;
            func_00257720(p->f0, d, e - 4, 0);
        } else {
            func_00257720(p->f0, d, e - 4, 0);
        }
    }
}

void func_00264938(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 == 0) {
        d -= 0x1C;
        if ((c & 3) >= 2) {
            d += 0x10;
            func_00257720(p->f0, d, e - 4, 0);
        } else {
            func_00257720(p->f0, d, e - 4, 0);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00264988);

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00264B20);

void func_002653D8(void) {
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", eiAbmCalc);

int func_002659F8(void) /* DEBT(TYPE): funcs.h says int; nothing is returned */
{
    T6_GsSrc *src;

    if (lpamng->f1156A == 0) {
        func_00293570();
        op_loop_ffx_after();
        src = (T6_GsSrc *)func_00245470(&D_006A36BC); /* DEBT(TYPE): funcs.h returns int */
        D_006A36C0.a = src->a;
        D_006A36C0.b = src->b;
        /* DEBT(TYPE): funcs.h types func_002B21E0 with one argument; it forwards two to func_002B1F90 */
        ((void (*)(void *, int))func_002B21E0)(&D_006A36C0, D_006A36BC & 1);
        op_gs1_transfer();
        func_002D0408();
        func_002D0698(0xFFFFFFFF);
        func_002B2730(0);
        func_002B2FF0(0x01000000, 0x88, 0);
        func_00260980();
        func_002B2810();
        func_00293740();
        lpamng->f1156B = 0;
    }
}

void func_00265B50(void) {
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00265B58);

void eiAbmSetLang(void)
{
    if (func_001BD360() == 0) {
        T6_VT->f10(0xD);
    } else {
        T6_VT->f10(7);
    }
    T6_VT->f00(0x12, D_006A38F4, 0, 0);
    T6_VT->f00(0x11, D_006A38F0, 0, 0);
    T6_VT->f08(0);
    func_002F8660(0);
}

int _m2c_func_00265E00_func_0011D678(int size) __asm__("func_0011D678");
void func_00265E00(void) {
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_19;
    s32 temp_2;

    D_0078E498.f10(0xD);
    temp_19 = D_0078E498.f14(0x12);
    temp_17 = D_0078E498.f14(0x11);
    D_0078E498.f10(7);
    temp_18 = D_0078E498.f14(0x12);
    temp_2 = D_0078E498.f14(0x11);
    temp_17_2 = (temp_17 < temp_2) ? temp_2 : temp_17;
    D_006A38F4 = _m2c_func_00265E00_func_0011D678((temp_19 >= temp_18) ? temp_19 : temp_18);
    D_006A38F0 = _m2c_func_00265E00_func_0011D678(temp_17_2);
    eiAbmSetLang();
}

int func_00265ED0(void)
{
    return D_00327910;
}

int func_00265EE0(void)
{
    return 2;
}

void func_00265EE8(void)
{
    func_00258780();
    TOMenuTermAbilityMap2();
    D_00327910 = 0;
}

void *func_00265F18(void) {
    return D_00573A90;
}

int func_00265F28(void)
{
    return 0x8B;
}

float func_00265F30(int i) {
    return D_0036E688[i];
}

u8 *func_00265F48(int i)
{
    return D_0036E698[i];
}

float func_00265F60(int i) {
    return D_0036E718[i];
}
