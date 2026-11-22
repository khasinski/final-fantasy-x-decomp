/* tu_018 0x111b50-0x1132b8: medium; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/v0.h"
#include "ffx/u0.h"

s32 func_00111B50(Chr *chr)
{
    return chr->w74C;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", func_00111B58);
INCLUDE_RODATA("build/ee_asm/game/chr/ch_111B50/rodata", jtbl_00569720);

typedef struct ChrUpdateLinkView {
    struct ChrUpdateLinkView *next;
    s8 b04;
    s8 b05;
    u16 h06;
    s8 *value08;
    s8 *previous0C;
    s32 w10;
    s16 h14;
    s16 flags16;
    s16 previous18;
    s16 saved1A;
    s16 h1C;
    s16 h1E;
    u8 pad20[4];
    s8 b24;
    u8 pad25[3];
} ChrUpdateLinkView;

void func_00112100(Chr *chr, int mode)
{
    ChrUpdateLinkView *link = (ChrUpdateLinkView *)chr->w758;
    s32 i;

    while (link != 0) {
        for (i = 0; i < mode; i++) {
            if (link->h06 != 0) {
                link->h06--;
            } else {
                s8 c = *link->previous0C++;

                if (c & 0x80) {
                    s32 v = c & 0x3F;

                    if (c & 0x40) {
                        v |= *link->previous0C++ << 6;
                        link->h14 = v;
                    } else {
                        link->h06 = v;
                    }
                } else {
                    c = (c << 25) >> 25;
                    link->h14 = c;
                }
            }
            link->previous18 = link->flags16;
            link->flags16 += link->h14;
        }
        link = link->next;
    }
}

void func_001121C8(Chr *chr)
{
    ChrUpdateLink *link;

    /* DEBT(CAST): relocated integer offset is a list pointer at this point. */
    link = (ChrUpdateLink *)chr->w758;
    if (link != 0)
    {
        do
        {
            link->saved1A = (u16) link->flags16;
            link->previous0C = (s32) link->value08;
            link->h06 = 0;
            link->flags16 = 0U;
            link->h14 = 0;
            link = link->next;
        } while (link != 0);
    }
    func_00112100(chr, 1);
    link = (ChrUpdateLink *)chr->w758;
    if (link != 0)
    {
        do
        {
            link->previous18 = (u16) link->saved1A;
            link = link->next;
        } while (link != 0);
    }
    chr->w7E8 = 1;
}

void Ch_MotionRemappingFcurve(Chr *chr, int d)
{
    int i;
    s32 *p;

    if (chr->w758 != 0) {
        chr->w758 += d;
        p = chr->p754;
        for (i = 0; i < chr->hdr->h0A * 9; i++, p += 10) {
            if (*p != 0) {
                *p += d;
            }
        }
    }
}

typedef struct MotionFcurveHdr {
    s16 h00;
    s16 h02;
    s16 h04;
    s16 h06;
    s32 w08;
    s32 w0C;
    s32 w10;
} MotionFcurveHdr;

typedef struct ChrMotionExt {
    u16 h00;
    u8 pad002[0x19E];
    s64 flags;
    struct ChrMotionExt *p1A8;
    u8 pad1AC[0x20];
    ChrHdr *hdr;
    struct {
        u8 pad00[0x38];
        float f38;
    } *p1D0;
    u8 pad1D4[0x14C];
    struct {
        u8 pad00[0xF0];
        float fF0;
        float fF4;
        float fF8;
        float fFC;
        float f100;
        float f104;
        float f108;
        float f10C;
        float f110;
        float f114;
        float f118;
        u8 pad11C[0x24];
    } *p320;
    u8 pad324[0x3FC];
    s32 w720;
    s32 w724;
    s32 w728;
    s32 w72C;
    s16 h730;
    s16 h732;
    s16 h734;
    u8 pad736[0x16];
    s32 w74C;
    s32 w750;
    ChrUpdateLinkView *p754;
    ChrUpdateLinkView *p758;
    s16 h75C;
    s16 h75E;
    s16 h760;
    s16 h762;
    u16 *p764;
    u8 pad768[0x80];
    s32 w7E8;
    s32 w7EC;
    u8 pad7F0[0xC];
    u16 h7FC;
    u16 pad7FE;
    void *p800;
    u8 pad804[8];
    struct {
        s16 h00;
        s16 pad02;
        void *p04;
    } *p80C;
} ChrMotionExt;

void Ch_MotionSetupFcurve(Chr *chr, void *arg)
{
    ChrMotionExt *ce = (ChrMotionExt *)chr;
    MotionFcurveHdr *hdr = (MotionFcurveHdr *)arg;
    u64 *bits;
    register u16 *data __asm__("$7");
    u64 cur_bits;
    s32 bits_left;
    ChrUpdateLinkView *head;
    ChrUpdateLinkView *p;
    s32 bones;
    s32 i;

    if (hdr == 0) {
        return;
    }
    {
        register s32 fps __asm__("$4") = hdr->h04;
        register s32 data_off __asm__("$3");
        bits = (u64 *)((u8 *)hdr + hdr->w08);
        data_off = hdr->w0C;
        bones = hdr->h02;
        ce->w7EC = fps;
        data = (u16 *)((u8 *)hdr + data_off);
    }
    bits_left = 0;
    cur_bits = 0;
    head = 0;
    p = ce->p754;
    if (hdr->h06 != 0) {
        ce->h7FC = hdr->h06;
        ce->p800 = (u8 *)hdr + hdr->w10;
    } else {
        ce->p800 = 0;
    }
    if (ce->hdr->h0A < bones) {
        bones = ce->hdr->h0A;
    }
    for (i = 0; i < bones * 9; i++, p++) {
        if (bits_left == 0) {
            cur_bits = *bits++;
            bits_left = 32;
        }
        p->b04 = cur_bits & 3;
        switch (p->b04) {
        case 0:
            p->h1C = 0;
            break;
        case 1:
            p->h1C = 0x1000;
            break;
        case 2:
            p->h1C = *data++;
            break;
        case 3:
            p->b05 = (i % 9) < 3;
            p->h06 = 0;
            p->flags16 = 0;
            p->h14 = 0;
            p->value08 = (s8 *)(data + 1);
            p->previous0C = (s8 *)(data + 1);
            p->next = head;
            head = p;
            data += (s16)*data / 2;
            break;
        }
        p->b24 = 1;
        cur_bits >>= 2;
        bits_left--;
    }
    ce->p758 = head;
    func_00112100(chr, 1);
    p = ce->p758;
    while (p != 0) {
        p->previous18 = p->flags16;
        p = p->next;
    }
    ce->w7E8 = 1;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_MotionCalcHokan);

void func_001127E0(Chr *chr, s16 v)
{
    chr->h732 = v;
}

s16 func_001127E8(Chr *chr)
{
    return chr->h730;
}

s8 Ch_GetWaitMotion(Chr *chr)
{
    return chr->b742;
}

typedef struct ChrFrameView {
    u8 pad000[0x1A0];
    union {
        s64 flags;
        s16 h;
    } u1A0;
    u8 pad1A8[0x57C];
    s32 w724;
    s32 w728;
    s32 w72C;
    s16 h730;
    s16 h732;
    s16 h734;
    u8 pad736[0x16];
    s32 w74C;
    s32 w750;
    s32 w754;
    s32 w758;
    s16 h75C;
    s16 h75E;
    s16 h760;
    s16 h762;
    u8 pad764[0x84];
    s32 w7E8;
    s32 w7EC;
} ChrFrameView;

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_IncrementFrame);

void Ch_MotionApply(Chr *chr)
{
    ChrFrameView *fv = (ChrFrameView *)chr;
    s32 f74C = fv->w74C;
    s32 frame = (f74C + 0x1FF) >> 8;
    s32 end = (fv->w728 + 1) >> 8;
    s32 diff;
    ChrUpdateLinkView *link;

    fv->w750 = f74C;
    if (frame > end) {
        if (fv->h730 == 1) {
            frame = end;
        } else {
            frame -= fv->w72C >> 8;
        }
    }
    diff = frame - fv->w7E8;
    if (diff < 0) {
        func_001121C8(chr);
        diff = frame - 1;
    }
    if (fv->w7E8 < frame) {
        func_00112100(chr, diff);
        fv->w7E8 += diff;
    }
    f74C &= 0xFF;
    link = (ChrUpdateLinkView *)fv->w758;
    if (f74C != 0) {
        while (link != 0) {
            if (link->b05 != 0) {
                s32 a = link->previous18;
                s32 b = link->flags16;
                s32 d;

                a &= 0xFFF;
                b &= 0xFFF;
                d = b - a;
                if (d >= 0x800) {
                    a += 0x1000;
                    d = b - a;
                }
                if (d < -0x7FF) {
                    b += 0x1000;
                    d = b - a;
                }
                link->h1C = a + ((d * f74C) >> 8);
            } else {
                link->h1C = link->previous18 + (((link->flags16 - link->previous18) * f74C) >> 8);
            }
            link = link->next;
        }
    } else {
        while (link != 0) {
            link->h1C = link->flags16;
            link = link->next;
        }
    }
}

typedef struct ChrVmSetupView {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
    s32 w10;
    s32 w14;
    s16 h18;
    s16 h1A;
    s16 h1C;
    u8 pad1E[0x10];
    s16 h2E;
} ChrVmSetupView;

void Ch_MotionSetupFcurve(Chr *chr, void *arg);

s32 func_00112A70(Chr *chr, void *arg, s32 id, s32 x, s32 y)
{
    ChrFrameView *fv = (ChrFrameView *)chr;
    ChrVmSetupView *vm = (ChrVmSetupView *)((u8 *)chr + 0x718);

    fv->w7EC = 0x1E00;
    Ch_MotionSetupFcurve(chr, arg);
    vm->w0C = x;
    if (y < 0) {
        y = *(s16 *)arg << 8;
    }
    vm->w14 = y - x;
    vm->w10 = y - 1;
    if (vm->h1A == -1) {
        vm->h18 = id;
    } else {
        vm->h18 = vm->h1A;
    }
    vm->h1A = -1;
    fv->h760 = 0x100;
    fv->w74C = vm->w0C;
    fv->h75E = vm->h2E;
    if (fv->h75E == 0) {
        fv->h75E = 1;
    }
    fv->u1A0.flags &= ~0x10000L;
    vm->h1C = 1;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_AnimCopy2);

s8 func_00112EE8(void)
{
    return Sg_GetKeepFps();
}

void func_00112F08(int a)
{
    Sg_SetKeepFps(a);
}

s32 func_00112F10(Chr *chr, s32 v)
{
    s32 old = FLAGS_BIT(chr, 20);

    FLAGS_SET(chr, 20, v);
    return old;
}

s32 func_00112F40(Chr *chr)
{
    return FLAGS_BIT(chr, 20);
}

void func_00112F58(s32 v)
{
    D_003038B8 = v;
}

s32 func_00112F68(void)
{
    return D_003038B8;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", func_00112F78);
