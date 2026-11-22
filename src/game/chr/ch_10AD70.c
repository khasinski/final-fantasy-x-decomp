/* tu_009 0x10ad70-0x10d0a0: low; ~Ch (config/tu_map.tsv) */
#define func_0010B358 _hdr_func_0010B358
#define func_0010B558 _hdr_func_0010B558
#define func_0010BE38 _hdr_func_0010BE38
#define func_0010BFA0 _hdr_func_0010BFA0
#define Sg_GsloadSetBase _hdr_Sg_GsloadSetBase
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_0010B358
#undef func_0010B558
#undef func_0010BE38
#undef func_0010BFA0
#undef Sg_GsloadSetBase

s32 Sg_GsloadSetBase(V0TexUpload *t);

extern char D_00308100[];
extern char D_00569600[];

void Ch_Check(s32 a, s32 b)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active && p->hdr->h06 == 0) {
            func_002F0008(D_00308100, D_00569600, p->w04, a, b);
        }
    }
}

void func_0010AE48(void) {
}

s32 func_0010AE50(s32 v)
{
    s8 old = D_0057EA08;

    D_0057EA08 = v & 1;
    if (v != old && ffx_debugmode) {
        func_2035A80();
    }
    return old;
}

s8 func_0010AEA0(void)
{
    return D_0057EA08;
}

s8 func_0010AEB0(s32 v)
{
    s8 old = D_00303690;

    D_00303690 = v & 1;
    return old;
}

void func_0010AEC8(void)
{
    D_00303690 = ((u8)D_00303690 + 1) & 1; /* DEBT(TYPE): read as unsigned here, signed elsewhere */
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010AEE0);

void func_0010AF88(Chr *chr, float v)
{
    chr->f188 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010AF90);

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010B230);

void func_0010B318(s32 v)
{
    D_0057EABC = v & 0x1;
}

s8 func_0010B328(void)
{
    return D_0057EABC;
}

void func_0010B338(s32 v)
{
    D_0057EABD = v & 0x1;
}

s8 func_0010B348(void)
{
    return D_0057EABD;
}

extern s8 D_00303698[];
extern void Ch_OptposGet(Chr *, int, void *);
extern void func_002DD900(void *, void *, void *, int);

s32 func_0010B358(Chr *chr, void *m)
{
    s32 pts[6][4];
    s32 tmp[4];
    register s32 min_y __asm__("$21") = 0x11C80; /* DEBT(REG): GCC swaps s4/s5 with &pts[0][1] */
    s32 min_x = 0x12320;
    u32 min_z = 0x7FFFFFFF;
    s32 max_x = (s32)0xFFFF2320;
    s32 max_y = (s32)0xFFFF1C80;
    u32 i;
    s8 *idx = D_00303698;
    int dx, dy, d;
    u64 vis;

    for (i = 0; i < 6; i++) {
        Ch_OptposGet(chr, *idx, tmp);
        func_002DD900(pts[i], m, tmp, 0);
        idx++;
        if (pts[i][0] < min_x) {
            min_x = pts[i][0];
        }
        if (pts[i][0] > max_x) {
            max_x = pts[i][0];
        }
        if (pts[i][1] < min_y) {
            min_y = pts[i][1];
        }
        if (pts[i][1] > max_y) {
            max_y = pts[i][1];
        }
        if ((u32)pts[i][2] < min_z) {
            min_z = pts[i][2];
        }
    }

    dx = max_x - min_x;
    dy = max_y - min_y;
    if (dy < dx) {
        dy = dx;
    }
    d = dy;
    *(u32 *)((u8 *)chr + 0x6E0) = min_z;
    *(float *)((u8 *)chr + 0x524) = (float)d;

    vis = 0;
    if (max_x <= 0x918F && min_x >= 0x6E71 && max_y <= 0x8E3F && min_y >= 0x71C1) {
        vis = 1;
    }
    *(u64 *)((u8 *)chr + 0x1A0) = (*(u64 *)((u8 *)chr + 0x1A0) & 0xFFFFFFFFEFFFFFFFULL) | (vis << 28);

    if (max_x < 0x6E70) {
        return 6;
    }
    if (min_x > 0x9190) {
        return 5;
    }
    if (max_y < 0x71C0) {
        return 4;
    }
    if (min_y > 0x8E40) {
        return 3;
    }
    return (min_z > 0x8000000U) ? 2 : 0;
}

s32 func_0010B358(Chr *chr, void *m);
void func_002DD900(void *out, void *m, void *v, s32 w);
extern float D_0057EA10[4][4];

s32 func_0010B558(Chr *chr)
{
    u8 pad0[0x10];
    U0Vec v;
    U0Vec cam;
    u8 unused[0x80];
    s32 out[4];
    float d;
    s32 r;

    chr->b18C &= 0xD7;
    chr->flags &= ~0x10000000L;
    v = *(U0Vec *)&chr->v6A0;
    MsCameraGetPosNow(1, &cam.x);
    v.x -= cam.x;
    v.y -= cam.y;
    v.z -= cam.z;
    d = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    *(float *)((u8 *)chr + 0x184) = d;
    if (chr->b18C != 0) {
        return 1;
    }
    r = func_0010B358(chr, D_0057EA10);
    func_002DD900(out, D_0057EA10, &chr->v6A0, 0);
    chr->w6E0 = out[2];
    if (FLAGS_BIT(chr, 11)) {
        if (r != 0) {
            chr->b18C |= 0x8;
            return 1;
        }
        if (chr->f180 < d) {
            chr->b18C |= 0x20;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010B6D0);

void Ch_DrawEnEffect(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 13, v);
}

void func_0010B7A8(Chr *chr, s32 i, void *dst)
{
    if (dst) {
        ChrSlotData *d = chr->ents[i].data;

        func_002DCE38(dst, chr->u1F0, chr->slots[d->h0].u90);
    }
}

void *Ch_ModelGetBaseMatrix(Chr *chr, s32 i, void *dst)
{
    ChrSlotData *d = chr->ents[i].data;
    u8 *p = chr->slots[d->h0].u90;

    if (dst) {
        func_002DD0C0(dst, p);
    }
    return p;
}

s32 Ch_ModelCalcSizeEffectPacket(Chr *chr, int i)
{
    ChrEnt *e = &chr->ents[i];

    D_003036A8 = 0;
    Ch_EffectPacketSetPtr(0);
    Ch_EffectPacketCreateMain(e);
    return Ch_EffectPacketGetSize();
}

void Ch_ModelCreateEffectPacket(Chr *chr, s32 index, s32 value)
{
    ChrEnt *entry;

    entry = &chr->ents[index];
    CALL_func_00123878_INT(entry->w08, entry->w04);
    D_003036A8 = D_0057EA08 ? chr->w6EC : 0;
    func_0010B6D0(chr);
    Ch_EffectPacketSetPtr(value);
    Ch_EffectPacketCreateMain(entry);
}

s32 Ch_GetNbModel(Chr *chr)
{
    ChrHdr *hdr = chr->hdr;

    if (hdr->h04 >= 0x831) {
        return hdr->h06;
    }
    return 0;
}

u16 func_0010B948(Chr *chr)
{
    return chr->hdr->h0A;
}

s32 *func_0010B958(void)
{
    return &D_003036B0;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_0010B968(s32 v)
{
    D_003036A0 = v;
}

R0Pkt *func_0010B978(int unused, R0Pkt *p)
{
    p->w0 = 0x30000008;
    p->w4 = (u32)func_0010EBB0(); /* DEBT(TYPE): getter returns s32 * */
    p->q8 = 0;
    return p + 1;
}

void func_0010B9B8(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 40, v);
}

void func_0010B9E8(s8 v)
{
    D_0057EAE8 = v;
}

s8 Sg_GuiGetTextureAnim(void)
{
    return D_0057EAE8;
}

s32 func_0010BA08(s32 a, s32 b, s32 c, s32 d)
{
    if (a == b) {
        return 1;
    }
    if (a < b) {
        if (c >= a && c < b) {
            return 2;
        }
        if (d >= a && d < b) {
            return 4;
        }
    } else {
        if (c >= a || c < b) {
            return 3;
        }
        if (d >= a || d < b) {
            return 5;
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010BA90);

s8 func_0010BE28(void)
{
    return D_0057EAE9;
}

typedef struct {
    u8 pad[0x7FEC];
    u32 vif1;
    u32 gif;
} TexDataHdr;

typedef union {
    struct {
        u32 w0;
        u32 w4;
        u64 q8;
    } s;
    s16 h[8];
} Pkt16;

Pkt16 *func_0010BE38(Chr *chr, Pkt16 *pkt)
{
    V0TexUpload *t;
    s32 i;

    if (!D_0057EA08) {
        D_003036A8 = 0;
        return pkt;
    }
    D_003036A8 = chr->w6EC;
    if (D_003036A8 != 0) {
        Ch_TextureSetImageBase(chr, 1, 0x3400);
        D_0057EAE9 = 1;
        t = (V0TexUpload *)chr->w6F8;
        for (i = 0; i < chr->h6FC; i++, t++) {
            if ((s16)t->h68 != -1) {
                t->tbp = t->h68;
                Sg_GsloadSetBase(t);
                if (t->data != 0) {
                    TexDataHdr *h;

                    pkt->s.w0 = 0x30000006;
                    pkt->s.w4 = (u32)t;
                    pkt->s.q8 = 0;
                    pkt++;
                    h = (TexDataHdr *)(t->data - 0x8000);
                    h->vif1 = (u16)h->vif1 | 0x51000000;
                    pkt->s.w0 = ((h->gif & 0x7FFF) + 2) | 0x30000000;
                    pkt->s.w4 = t->data - 0x20;
                    pkt->s.q8 = 0;
                    pkt++;
                }
            }
        }
        func_002F8660(0);
    }
    return pkt;
}

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
} ChrSlotDataH4;

void func_0010BFA0(Chr *chr)
{
    s32 i, j;
    register float max_y __asm__("$f1") = 0.0f;

    for (i = 0; i < chr->hdr->h06; i++) {
        ChrEnt *e = &chr->ents[i];

        for (j = 0; j < ((ChrSlotDataH4 *)e->data)->h4; j++) {
            float y = ((Vec4 *)e->w08)[j].y;

            max_y = (max_y < y) ? y : max_y;
        }
    }
    max_y /= 1000.0f;
    max_y = -max_y;
    chr->f74 = max_y;
}

void Ch_DrawSetCull(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 19, v);
}

void func_0010C078(s8 v)
{
    EnableClothSystem = v;
}

s8 func_0010C088(void)
{
    return EnableClothSystem;
}

void func_0010C098(void) {
}

void func_0010C0A0(s8 v)
{
    D_003036A5 = v;
}

s8 func_0010C0B0(void)
{
    return D_003036A5;
}

void func_0010C0C0(s8 v)
{
    D_003036A6 = v;
}

s8 func_0010C0D0(void)
{
    return D_003036A6;
}

void func_0010C0E0(s8 v)
{
    D_003036A7 = v;
}

s8 func_0010C0F0(void)
{
    return D_003036A7;
}

u8 func_0010C100(void)
{
    return D_0057EAEA;
}

u8 func_0010C110(void)
{
    return D_0057EAEB;
}

void Ch_DrawSetShadowMode(u8 v)
{
    D_0057EAEA = v;
}

void func_0010C130(u8 v)
{
    D_0057EAEB = v;
}

void func_0010C140(s8 a, s8 b, s8 c)
{
    D_0057EAEC = a;
    D_0057EAED = b;
    D_0057EAEE = c;
}

void func_0010C160(s32 *a, s32 *b, s32 *c)
{
    if (a) {
        *a = D_0057EAEC;
    }
    if (b) {
        *b = D_0057EAED;
    }
    if (c) {
        *c = D_0057EAEE;
    }
}

void func_0010C198(s32 a, s32 b)
{
    D_0057EAF0 = a;
    D_0057EAF4 = b;
}

void func_0010C1B0(s32 *a, s32 *b)
{
    if (a != 0) {
        *a = D_0057EAF0;
    }
    if (b != 0) {
        *b = D_0057EAF4;
    }
}

void func_0010C1D8(Chr *chr, s32 v)
{
    chr->w6E4 = v;
}

s32 func_0010C1E0(Chr *chr)
{
    return chr->w6E4;
}

void Ch_DrawCalcShade(Chr *chr, float *x, float *y, float *z)
{
    float s;

    if (EnableClothSystem) {
        s = chr->t358.cur * chr->t364.cur;
    } else {
        s = chr->t358.cur;
    }
    *x = chr->t328.cur * s * chr->fC0;
    *y = chr->t334.cur * s * chr->fC4;
    *z = chr->t340.cur * s * chr->fC8;
}

float Ch_DrawGetModelAlpha(Chr *chr, s32 i)
{
    if (i == -1) {
        return chr->t34C.cur;
    }
    return chr->ents[i].f14 * chr->t34C.cur;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010C278);

void func_0011EA68(s32 a);
void func_0011E490(void *a);
void func_0011E788(void *a, float b);

typedef struct ChrDrawView {
    u8 pad000[0x178];
    float f178;
    u8 pad17C[0x378];
    float f4F4;
    u8 pad4F8[0x1A8];
    U0Vec v6A0;
    U0Vec v6B0;
} ChrDrawView;

void func_0010C6B0(Chr *chr)
{
    ChrDrawView *c = (ChrDrawView *)chr;
    U0Vec tmp;

    if (D_0057EABC != 0) {
        func_0011EA68(4);
        func_0011E420();
        func_0011E490(&c->v6B0);
        func_0011E490(&c->v6A0);
        func_0011EA68(6);
        func_0011E788(&c->v6B0, c->f4F4);
        tmp = c->v6A0;
        tmp.y = c->f178;
        func_0011E788(&tmp, c->f4F4);
    }
}

void Ch_DrawInitAll(void)
{
    func_0010AE50(1);
    func_00107B78(0);
    func_0010AEE0();
}

s32 func_0010C768(Chr **a, Chr **b)
{
    return (*a)->w6E0 - (*b)->w6E0;
}

void func_0010C780(s8 v)
{
    D_0057EAF8 = v;
}

void Ch_DrawSetSituation(Chr *chr, s8 v)
{
    chr->b193 = v;
}

typedef union {
    struct {
        u64 q0;
        u64 q8;
    } q;
    struct {
        u32 w0, w4, w8, wC;
    } w;
} DmaQword;

s32 func_0010D648(Chr *chr);
void *func_0010B230(Chr *chr, void *mat, void *pkt);

void func_0010C798(s32 use_spad)
{
    DmaQword *base;
    DmaQword *pkt;
    Chr *p;
    s32 qwc;

    if (use_spad != 0) {
        base = (DmaQword *)Sg_GetSpadPtr();
        pkt = base + 5;
    } else {
        base = (DmaQword *)Sg_PacketGetPtr();
        pkt = base + 4;
    }
    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (!p->active) {
            continue;
        }
        if (!(((u64)p->flags >> 36) & 1)) {
            continue;
        }
        if (func_0010D648(p) != 0) {
            continue;
        }
        {
            s32 v = ((s8 *)p)[0x192];
            if (v == 2) {
                continue;
            }
            if (v != 3) {
                s32 mode;

                if (D_0057EAEA != 0) {
                    mode = D_0057EAEA - 1;
                } else {
                    mode = ((s8 *)p)[0x18F];
                }
                if (mode == 3) {
                    continue;
                }
                if (mode == 1) {
                    pkt = (DmaQword *)func_0010B230(p, (u8 *)p + 0x120, pkt);
                }
            }
        }
    }
    qwc = (s32)((u8 *)pkt - (u8 *)base) / 16;
    if (use_spad != 0) {
        if (qwc >= 6) {
            base->q.q8 = 0;
            base->q.q0 = (qwc - 1) | 0x10000000;
            base++;
            base->q.q0 = 0;
            base->w.w8 = 0x11000000;
            base->w.wC = (qwc - 2) | 0x50000000;
            base++;
            base->q.q0 = 0x2000000000008001ULL;
            base->q.q8 = 0xEEEE;
            base++;
            base->q.q0 = 0x46;
            base->q.q8 = 0x43;
            base++;
            base->q.q0 = 0x51001;
            base->q.q8 = 0x48;
            func_0010E028((s32)pkt);
        }
    } else {
        if (qwc >= 5) {
            base->q.q8 = 0;
            base->q.q0 = (qwc - 1) | 0x70000000;
            base++;
            base->q.q0 = 0x2000000000008001ULL;
            base->q.q8 = 0xEEEE;
            base++;
            base->q.q0 = 0x46;
            base->q.q8 = 0x43;
            base++;
            base->q.q0 = 0x51001;
            base->q.q8 = 0x48;
            base++;
            func_002F8660(0);
            func_002DBF78(dmaGif, 0, 0);
            func_002DBA28((void *)dmaGif, (void *)(base - 4));
            func_002DBF78(dmaGif, 0, 0);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_10AD70", func_0010CA88);

extern char D_00569618[];
extern void func_0011EDA8(int addr, int size, void *p);
extern void func_00123C6C(void);

int func_0010D008(void)
{
    func_0011EDA8(0x1100C000, 0x4000, D_00569618);
    SYNC();
    EI();
    func_00123C6C();
    return 0;
}

extern volatile int D_003036F4;
extern void func_0011ACD8(void);

int func_0010D048(void)
{
    if ((*(volatile u32 *)0x10009000 & 0xFFFF0000) == 0xF0000000) {
        D_003036F4++;
        func_0011ACD8();
    }
    SYNC();
    EI();
    return 0;
}
