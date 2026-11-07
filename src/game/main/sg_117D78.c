/* tu_025 0x117d78-0x1194e0: low; ~Sg (config/tu_map.tsv) */
#define D_00580449 _hdr_D_00580449
#define D_0058044A _hdr_D_0058044A
#define D_0058044B _hdr_D_0058044B
#define D_0058044C _hdr_D_0058044C
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/v0.h"
#undef D_00580449
#undef D_0058044A
#undef D_0058044B
#undef D_0058044C

typedef struct {
    u8 kind;
    u8 b1;
    u8 b2;
    u8 b3;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s32 wC;
} FxSlotSigned;

typedef struct {
    u64 tbp0 : 14; u64 tbw : 6; u64 psm : 6; u64 tw : 4; u64 th : 4; u64 tcc : 1; u64 tfx : 2;
    u64 cbp : 14; u64 cpsm : 4; u64 csm : 1; u64 csa : 5; u64 cld : 3;
} GsTex0;

typedef u32 u128 __attribute__((mode(TI)));

typedef union {
    u128 q;
    struct {
        union {
            GsTex0 tex0;
            u64 raw;
        } u;
        s64 addr;
    } s;
} GsTex0Pkt;

Cmd16 *Sg_GsGet(void);
void func_0011E3C8(void);
void Sg_GsTexHokan(int a);
void func_0011E040(int a, int b, int c, int d, int e);
void Sg_GsUV(int x, int y);
void Sg_GsUV2(int x, int y);
void Sg_GsTEXFLUSH(void);
void Sg_GsXYZF2V(int x, int y, int z);
void func_0011DF70(int a, int b, int c, int d, int e, int f, int g, int h);
void func_001181B8(int a);
void yiGetBackColor(int *v);
extern s32 D_00307EB0;
extern s8 D_00580448;
extern s8 D_00580449;
extern s8 D_0058044A;
extern s8 D_0058044B;
extern s8 D_0058044C;

void Sg_Flash(int a, int b, int c, int d)
{
    D_005803F8.b0 = 6;
    D_00580428 |= 4;
    D_005803F8.h4 = a;
    D_005803F8.h6 = a;
    D_005803F8.b1 = b;
    D_005803F8.b2 = c;
    D_005803F8.b3 = d;
}

void func_00117DB0(int a, int b, int c)
{
    FxSlot *s = &((FxSlot *)D_005803D8)[4]; /* DEBT(CAST): D_005803D8 is declared as bytes */

    D_00580428 |= 0x10;
    if (b) {
        s->kind = c ? 4 : 2;
    } else {
        s->kind = c ? 5 : 3;
    }
    s->h4 = a;
    s->h6 = a;
    s->b3 = 0xFF;
    s->b2 = 0xFF;
    s->b1 = 0xFF;
}

void func_00117E08(int v)
{
    func_00117DB0(v, 0, 1);
}

void func_00117E18(int v)
{
    func_00117DB0(v, 0, 0);
}

void func_00117E28(int v)
{
    func_00117DB0(v, 1, 1);
}

void func_00117E38(int v)
{
    func_00117DB0(v, 1, 0);
}

s16 func_00117E48(void)
{
    return D_005803EE;
}

void Sg_Blur(int a)
{
    D_005803E8.b0 = 1;
    D_00580428 |= 2;
    if (a) {
        D_005803E8.h6 = a;
        D_005803E8.h4 = 1;
    } else {
        D_005803E8.h4 = 0;
        D_005803E8.h6 = 0;
    }
}

s16 func_00117E98(void)
{
    return D_005803DE;
}

/* DEBT(CAST): screen-fade slot at D_005803D8 accessed through byte pointer */
void Sg_AccSetAlpha(int a, int b)
{
    FxSlotSigned *s = (FxSlotSigned *)D_005803D8;

    s->kind = 0;
    D_00580428 |= 1;
    s->h4 = b;
    if (b != 0) {
        s16 a16 = a;
        s32 diff;
        register s32 var_lo __asm__("$2");

        s->h8 = a;
        diff = s->h6 - a16;
        a = s->h6;
        if (diff >= 0) {
            var_lo = diff / b;
        } else {
            __asm__("" : "+r"(a));
            var_lo = (a16 - s->h6) / b;
        }
        __asm__("");
        b = var_lo;
        s->hA = b;
        if ((s16)b == 0) {
            s->hA = 1;
        }
    } else {
        s->h6 = a;
    }
    if ((s16)a != 0) {
        if (s->h4 == 0) {
            s->h4 = 1;
        }
    }
}

void Sg_FilterAdd(int a, int b, int c, int d)
{
    FxSlot *s = (FxSlot *)&D_00580408;

    s->kind = 7;
    D_00580428 |= 8;
    if (d != 0) {
        s->b1 = a;
        s->h4 = 1;
        s->b2 = b;
        s->b3 = c;
        __asm__("");
        s->h6 = d;
    } else {
        s->h4 = 0;
    }
}

void Sg_FilterSub(int a, int b, int c, int d)
{
    Sg_FilterAdd(a, b, c, d);
    D_00580408 = 8;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_00117FC8(void)
{
    D_005803FC = 0;
}

/* DEBT(TYPE): global type guessed from the access width only */
void Sg_FilterReset(void)
{
    D_0058040C = 0;
}

void Sg_FadeReset(void)
{
    D_0058041C = 0;
}

s16 func_00117FF8(void)
{
    return D_0058041C;
}

void graphicAddScreenFadeTask(FxSlot *s, int v)
{
    func_0011D998(s->b1, s->b2, s->b3, v);
    Sg_GsPRIM(0x46);
    Sg_GsXYZF2(0, 0);
    Sg_GsXYZF2(D_00307F40, D_00307F44);
}

s32 Sg_EnFocus(s32 v)
{
    s32 old = D_00580444;

    D_00580444 = v & 1;
    return old;
}

s32 func_00118070(void)
{
    return D_00580444 & 0x1;
}

s32 Sg_GetFocus(s32 i)
{
    return D_00580430[i];
}

void Sg_SetFocus(s32 i, s32 v)
{
    D_00580430[i] = v;
    if (v != 0) {
        D_00580440 |= 1 << v;
        Sg_EnFocus(1);
    } else {
        D_00580440 &= ~1;
    }
}

void func_001180F0(void)
{
    D_00580444 = (D_00580444 + 1) & 1;
    if (D_00580444) {
        Sg_SetFocus(0, Sg_GetFocus(0));
        Sg_SetFocus(1, Sg_GetFocus(1));
    }
}

void func_00118150(void)
{
    Sg_SetFocus(0, 0x10000);
    Sg_SetFocus(1, 0x20000);
    Sg_EnFocus(0);
}

void Sg_InitFilter(void)
{
    CALL_func_002ED0E0_INT(D_005803D8, 0x50U);
    D_00580428 = 0;
    D_00580440 = 0;
    func_00118150();
}

void func_001181B8(int a)
{
    GsTex0Pkt *p = (GsTex0Pkt *)Sg_GsGet();

    p->q = 0;
    p->s.u.tex0.tbp0 = (u32)D_005803D4 >> 6;
    p->s.u.tex0.tbw = 8;
    p->s.u.tex0.psm = 1;
    p->s.u.tex0.tw = 9;
    p->s.u.tex0.th = 9;
    p->s.u.tex0.tcc = 0;
    p->s.u.tex0.tfx = 1;
    p->s.addr = 6;
    func_0011E3C8();
    Sg_GsTexHokan(0);
    func_0011E040(0, 1, 2, 1, a);
    Sg_GsPRIM(0x156);
    Sg_GsUV(0, 0);
    Sg_GsXYZF2(0, 0);
    Sg_GsUV2(0x200, 0x1A0);
    Sg_GsXYZF2(0x200, 0x1A0);
}

void func_00118308(int a)
{
    GsTex0Pkt *p;

    Sg_GsTEXFLUSH();
    p = (GsTex0Pkt *)Sg_GsGet();
    p->s.u.tex0.tbp0 = (u32)D_005803D0 >> 6;
    p->s.u.tex0.tbw = 8;
    p->s.u.tex0.psm = 1;
    p->s.u.tex0.tw = 9;
    p->s.u.tex0.th = 9;
    p->s.u.tex0.tcc = 0;
    p->s.u.tex0.tfx = 1;
    p->s.addr = 6;
    func_0011E3C8();
    Sg_GsTexHokan(1);
    func_0011E040(0, 1, 2, 1, 0x40);
    func_0011D998(0xFF, 0, 0, 0);
    Sg_GsPRIM(0x156);
    Sg_GsUV(2, 2);
    Sg_GsXYZF2V(0, 0, a);
    Sg_GsUV2(0x200, 0x1A0);
    Sg_GsXYZF2V(0x1FE, 0x19E, a);
}

void func_00118470(void)
{
    s32 i;

    if (D_00580428 == 0 && D_00580440 == 0) {
        return;
    }
    Sg_GsSetPacket((Cmd16 *)D_0057F7D0);
    Sg_GsStart();
    if (D_00580444 != 0 && D_00580440 != 0) {
        func_0011DF70(1, 1, 0, 0, 0, 0, 1, 2);
        if (D_00580430[0] != 0) {
            func_00118308(D_00580430[0]);
        }
        if (D_00580430[1] != 0) {
            func_00118308(D_00580430[1]);
        }
    }
    func_0011DF70(1, 1, 0, 0, 0, 0, 1, 1);
    for (i = 0; i < 5; i++) {
        FxSlotSigned *s = &((FxSlotSigned *)D_005803D8)[i];
        s32 v;

        if (s->h4 == 0) {
            D_00580428 &= ~(1 << i);
            continue;
        }
        switch (s->kind) {
        case 6:
            v = (s->h4 * 127) / s->h6;
            func_0011E040(0, 1, 2, 1, v);
            graphicAddScreenFadeTask((FxSlot *)s, v);
            s->h4--;
            break;
        case 4:
            v = (s->h4 * 255) / s->h6;
            func_0011E040(0, 1, 2, 1, v);
            graphicAddScreenFadeTask((FxSlot *)s, v);
            s->h4--;
            break;
        case 5:
            s->h4--;
            if (s->h4 == 0) {
                s->h4 = 1;
                v = 0xFF;
            } else {
                v = 0xFF - (s->h4 * 255) / s->h6;
            }
            func_0011E040(0, 1, 2, 1, v);
            graphicAddScreenFadeTask((FxSlot *)s, v);
            break;
        case 2:
            s->h4--;
            v = 0x7F - (s->h4 * 127) / s->h6;
            func_0011E040(1, 2, 2, 2, v);
            graphicAddScreenFadeTask((FxSlot *)s, v);
            break;
        case 3:
            s->h4--;
            if (s->h4 == 0) {
                s->h4 = 1;
                v = 0;
            } else {
                v = (s->h4 * 127) / s->h6;
            }
            func_0011E040(1, 2, 2, 2, v);
            graphicAddScreenFadeTask((FxSlot *)s, v);
            break;
        case 1:
            if (D_00307F40 == 0x200) {
                func_001181B8(s->h6);
            }
            break;
        case 0:
            s->h4--;
            if (s->h8 != s->h6) {
                if (s->h6 < s->h8) {
                    s->h6 += s->hA;
                    if (s->h8 < s->h6) {
                        s->h6 = s->h8;
                    }
                } else {
                    s->h6 -= s->hA;
                    if (s->h6 < s->h8) {
                        s->h6 = s->h8;
                    }
                }
            }
            if (s->h6 != 0 && s->h4 == 0) {
                s->h4 = 1;
            }
            if (D_00307EAC == 0 && D_00307F40 == 0x200) {
                func_00118A80(s->h6);
            }
            break;
        case 7:
            func_0011E040(0, 1, 2, 1, s->h6);
            graphicAddScreenFadeTask((FxSlot *)s, 0);
            break;
        case 8:
            func_0011E040(1, 0, 2, 2, s->h6);
            graphicAddScreenFadeTask((FxSlot *)s, 0);
            break;
        }
    }
    Sg_GsEnd();
}

void Sg_DebugFill(s32 a)
{
    s32 temp_2;

    Sg_GsSetPacket((Cmd16 *)0);
    Sg_GsStart();
    Sg_GsFRAME(0, 0);
    Sg_GsSCISSOR(0, 0x200, 0, 0x340);
    func_0011DF70(1, 1, 0, 0, 0, 0, 1, 1);
    Sg_GsPRIM(6);
    if (a == -1) {
        func_0011D998(0, 0, 0, 0);
        Sg_GsXYZF2(0, 0);
        Sg_GsXYZF2(0x200, 0x340);
    } else {
        func_0011D998((a & 2) ? 0xFF : 0, (a & 4) ? 0xFF : 0, (a & 1) ? 0xFF : 0, 0);
        Sg_GsXYZF2(0, D_00307EB0);
        Sg_GsXYZF2(0x200, D_00307EB0 + 4);
        if (a & 0xF0) {
            a >>= 4;
            func_0011D998((a & 2) ? 0xFF : 0, (a & 4) ? 0xFF : 0, (a & 1) ? 0xFF : 0, 0);
            Sg_GsXYZF2(0, D_00307EB0);
            Sg_GsXYZF2(0x100, D_00307EB0 + 4);
        }
    }
    temp_2 = D_00307EB0 + 6;
    D_00307EB0 = temp_2;
    if (temp_2 >= 0xDD) {
        D_00307EB0 = 0;
    }
    Sg_GsEnd();
}

/* old-style definition: callers in this file pass other argument counts (DEBT(TYPE)) */
void func_00118A40()
{
    D_00307EAC = 0x1;
}

void func_00118A50(s8 v)
{
    D_0058044E = v;
}

void func_00118A60(s8 v)
{
    D_0058044F = v;
}

void func_00118A70(s8 v)
{
    D_00580450 = v;
}

void func_00118A80(int a)
{
    GsTex0Pkt *p;

    Sg_GsTEXFLUSH();
    p = (GsTex0Pkt *)Sg_GsGet();
    p->s.u.tex0.tbp0 = 0x1A00;
    p->s.u.tex0.tbw = 8;
    p->s.u.tex0.psm = 0xA;
    p->s.u.tex0.tw = 9;
    p->s.u.tex0.th = 9;
    p->s.u.tex0.tcc = 0;
    p->s.u.tex0.tfx = 1;
    p->s.addr = 6;
    func_0011E3C8();
    Sg_GsTexHokan(0);
    func_0011E040(0, 1, 2, 1, a);
    Sg_GsPRIM(0x156);
    Sg_GsUV(0, 0);
    Sg_GsXYZF2(0, 0);
    Sg_GsUV2(0x200, 0x1A0);
    Sg_GsXYZF2(0x200, 0x1A0);
}

void sg_AccSetCurrent(void)
{
    if (D_00307EAC != 0) {
        GsTex0Pkt *p;

        Sg_GsSetPacket((Cmd16 *)D_0057F7D0);
        Sg_GsStart();
        Sg_GsFRAME_16(0xD0, 0);
        Sg_GsTEXFLUSH();
        p = (GsTex0Pkt *)Sg_GsGet();
        p->s.u.raw = 0;
        p->s.u.tex0.tbp0 = (u32)D_005803D0 >> 6;
        p->s.u.tex0.tbw = 8;
        p->s.u.tex0.psm = 1;
        p->s.u.tex0.tw = 9;
        p->s.u.tex0.th = 9;
        p->s.u.tex0.tcc = 0;
        p->s.u.tex0.tfx = 1;
        p->s.addr = 6;
        func_0011E3C8();
        Sg_GsTexHokan(0);
        Sg_GsPRIM(0x116);
        Sg_GsUV(0, 0);
        Sg_GsXYZF2(0, 0);
        Sg_GsUV2(0x200, 0x1A0);
        Sg_GsXYZF2(0x200, 0x1A0);
        Sg_GsFRAME((u32)D_005803D0 >> 11, 0);
        D_00307EAC = 0;
        Sg_GsEnd();
    }
}

void func_00118CD8(void)
{
    switch (D_0058044D) {
    case 0:
        Sg_GsFRAME((s32)((u32)D_005803D0 >> 0xB), 0);
        Sg_GsFRAME2((s32)((u32)D_005803D0 >> 0xB), 0);
        break;
    case 1:
        Sg_GsFRAME_16(0xD0, 0);
        Sg_GsFRAME2_16(0xD0, 0);
        break;
    case 2:
        ((s32 (*)(s32, s32))Sg_GsFRAME_16)(((s32)D_00580454 / 2048), 0);
        Sg_GsFRAME2_16(((s32)D_00580454 / 2048), 0);
        break;
    }
}

/* DEBT(CAST): shared declarations retain untyped handles or buffers at these calls. */
void func_00118DE0(void)
{
    s32 buffer;

    buffer = Sg_GetSpadPtr();
    if (D_0058044F != 0)
    {
        Sg_GsSetPacket((Cmd16 *) buffer);
        func_0011D800();
        if (D_0058044F != 0)
        {
            Sg_GsFRAME_16(0xD0, 0);
            Sg_GsFRAME2_16(0xD0, 0);
        }
        else
        {
            func_00118CD8();
        }
        func_0010E028(Sg_GsEnd2());
    }
}

void func_00118E70(void)
{
    Sg_GsSetPacket((Cmd16 *)Sg_GetSpadPtr()); /* DEBT(CAST): getter returns s32 */
    func_0011D800();
    if (D_00580450) {
        Sg_GsFRAME_16(0xD0, 0);
        Sg_GsFRAME2_16(0xD0, 0);
    } else {
        func_00118CD8();
    }
    func_0010E028((int)Sg_GsEnd2()); /* DEBT(CAST) */
}

/* DEBT(CAST): shared declarations retain untyped handles or buffers at these calls. */
void func_00118EE0(void)
{
    s32 buffer;

    buffer = Sg_GetSpadPtr();
    if (D_0058044E != 0)
    {
        Sg_GsSetPacket((Cmd16 *) buffer);
        func_0011D800();
        func_0011DF70(0, 0, 0, 0, 0, 0, 1, 1);
        Sg_GsZBUF(1);
        func_00118A80(0x80);
        Sg_GsZBUF(0);
        func_0010E028(Sg_GsEnd2());
    }
}

void Sg_AccSetClear(u8 a, u8 b, u8 c, u8 d)
{
    D_00580449 = a;
    D_0058044A = b;
    D_0058044B = c;
    D_0058044C = d;
}

void func_00118F98(void)
{
    Sg_AccSetAlpha(0, 0);
    func_00118A50(0);
    func_00118A40(0);
    func_00118A60(0);
    func_00118A70(0);
    Sg_AccSetClear(0, 0, 0, 0);
}

s32 func_00118FE8(void)
{
    return D_005803D0;
}

s32 Sg_VramGetAddrZ(void)
{
    return 0x84000;
}

s32 func_00119008(void)
{
    return D_005803D4;
}

s32 func_00119018(void)
{
    return D_005803D0;
}

void func_00119028(s8 v)
{
    D_00307EB4 = v;
}

void func_00119038(s8 v)
{
    D_00307EB5 = v;
}

void Sg_DrawSetEnvironmentInit(void)
{
    s32 col[4];

    D_005803D0 = (D_00307F2C & 1) ? 0 : 0x34000;
    D_005803D4 = (D_00307F2C & 1) ? 0x34000 : 0;
    if (D_00307EB5 != 0) {
        D_00580448 = -1;
        D_00307EB5 = 0;
    } else {
        D_00580448 = 0;
    }
    yiGetBackColor(col);
    Sg_GsSetPacket((Cmd16 *)D_0057F7D0);
    Sg_GsStart();
    func_0011DF38();
    func_0011DF08(0);
    Sg_GsFRAME((s32)((u32)D_005803D0 >> 0xB), 0);
    Sg_GsXYOFFSET(0, 0);
    Sg_GsSCISSOR(0, D_00307F40, 0, D_00307F44);
    Sg_GsZBUF(0);
    Sg_GsFRAME2((s32)((u32)D_005803D0 >> 0xB), 0);
    Sg_GsXYOFFSET2(0, 0);
    Sg_GsSCISSOR2(0, D_00307F40, 0, D_00307F44);
    func_0011DAA8(0);
    if (D_00307EB4 == 0) {
        func_0011DFD8(0, 0, 0, 0, 0, 0, 1, 1);
        Sg_GsPRIM(0x206);
        func_0011D998(col[0], col[1], col[2], 0);
        Sg_GsXYZF2(0, 0);
        Sg_GsXYZF2(D_00307F40, D_00307F44);
        if (D_00580449 != 0) {
            if (D_00580449 == 2) {
                func_0011D998(D_0058044A, D_0058044B, D_0058044C, 0);
            }
            Sg_GsFRAME2_16(0xD0, 0);
            Sg_GsXYZF2(0, 0);
            Sg_GsXYZF2(D_00307F40, D_00307F44);
        }
    } else {
        D_00307EB4 = D_00307EB4 - 1;
    }
    Sg_GsEnd();
    func_0011D888();
    func_002DA610(0, 0);
}

s32 Sg_DrawSetEnvironmentInitMovie(void)
{
    s32 pad[4];

    D_005803D0 = (D_00307F2C & 1) ? 0 : (D_00307F40 * D_00307F44);
    Sg_GsSetPacket((Cmd16 *)D_0057F7D0);
    Sg_GsStart();
    Sg_GsFRAME((u32)D_005803D0 >> 0xB, 0);
    Sg_GsXYOFFSET(0, 0);
    Sg_GsSCISSOR(0, D_00307F40, 0, D_00307F44);
    Sg_GsZBUF(1);
    Sg_GsFRAME2((u32)D_005803D0 >> 0xB, 0);
    Sg_GsXYOFFSET2(0, 0);
    Sg_GsSCISSOR2(0, D_00307F40, 0, D_00307F44);
    func_0011DAA8(1);
    Sg_GsEnd();
    func_0011D888();
    return func_002DA610(0, 0);
}

void Sg_DrawSetEnvironment(void)
{
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 pad[4];
    s32 temp_16;
    s8 temp_16_2;

    temp_16 = Sg_GetSpadPtr();
    D_0058044D = MsGetScreenData(&sp10, &sp14, &sp18, &sp1C, &D_00580454);
    sp18 += 1;
    sp1C += 1;
    Sg_GsSetPacket((Cmd16 *)temp_16);
    func_0011D800();
    temp_16_2 = D_0058044D;
    func_00118CD8();
    if (temp_16_2 != D_00580448) {
        Sg_GsXYOFFSET2(0, 0);
        Sg_GsSCISSOR2(0, 0x200, 0, 0x1A1);
        func_0011DFD8(1, 0, 0, 2, 0, 0, 1, 1);
        Sg_GsPRIM(0x206);
        Sg_GsXYZF2(sp10, sp14);
        Sg_GsXYZF2(sp10 + sp18, sp14 + sp1C);
    }
    D_00580448 = temp_16_2;
    Sg_GsXYOFFSET2(sp10, sp14);
    Sg_GsSCISSOR2(sp10, sp10 + sp18, sp14, sp14 + sp1C);
    Sg_GsXYOFFSET(sp10, sp14);
    Sg_GsSCISSOR(sp10, sp10 + sp18, sp14, sp14 + sp1C);
    func_0010E028(Sg_GsEnd2());
}
