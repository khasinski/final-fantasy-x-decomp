/* tu_023 0x116cb8-0x117d38: medium; ~Ch (config/tu_map.tsv) */
#define Ch_ClutCreate _hdr_Ch_ClutCreate
#define Ch_TexDataMapping _hdr_Ch_TexDataMapping
#define func_00117140 _hdr_func_00117140
#define func_00117700 _hdr_func_00117700
#define Ch_ClutMapping _hdr_Ch_ClutMapping
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/v0.h"
#undef Ch_ClutCreate
#undef Ch_TexDataMapping
#undef func_00117140
#undef func_00117700
#undef Ch_ClutMapping

void func_00117140(void *arg0, void *arg1);

typedef struct {
    s32 w00;
    u16 h04;
    u16 pad06;
    u16 h08;
    u16 pad0A;
    u16 h0C;
    u16 pad0E;
    u16 h10;
    u16 pad12;
    s32 w14;
    ChrAnimPair *pairs;
    V0TexHdr *ents;
    s32 w20;
} TexSubHdr;

void Ch_TexDataMapping(TexSubHdr *s)
{
    s32 diff;
    s32 i;

    if (s == 0 || s->h10 < 0x1029) {
        return;
    }
    diff = (s32)s - s->w00;
    if (diff == 0) {
        return;
    }
    s->w14 += diff;
    s->pairs = (ChrAnimPair *)((s32)s->pairs + diff);
    s->ents = (V0TexHdr *)((s32)s->ents + diff);
    s->w00 = (s32)s;
    if (s->h10 >= 0x1126 && s->w20 != 0) {
        s->w20 += diff;
    }
    for (i = 0; i < s->h08; i++) {
        s->pairs[i].b += diff;
        if (((u8 *)s->pairs[i].b)[0] == 0 && ((u8 *)s->pairs[i].b)[1] == 0xFF && ((u8 *)s->pairs[i].b)[2] == 0) {
            u8 *p = (u8 *)s->pairs[i].b;
            p[0] = p[1] = p[2] = p[3] = 0;
        }
        if (((u8 *)s->pairs[i].b)[0] == 0xFF && ((u8 *)s->pairs[i].b)[1] == 0 && ((u8 *)s->pairs[i].b)[2] == 0) {
            u8 *p = (u8 *)s->pairs[i].b;
            p[0] = p[1] = p[2] = p[3] = 0;
        }
    }
    for (i = 0; i < s->h0C; i++) {
        if (s->ents[i].data != 0) {
            s->ents[i].data += diff;
        }
    }
}

void Sg_GsloadSetBase(V0TexUpload *t)
{
    t->pk.bitbltbuf.DBP = t->tbp;
}

R0Pkt *func_00116E50(R0Pkt *pkt, V0TexUpload *t)
{
    R0Pkt *ret;

    pkt->w4 = 0;
    pkt->q8 = 0;
    pkt->w0 = 0x10000006;
    pkt++;
    ret = pkt + 6;
    *(V0GsLoadPk *)pkt = t->pk;
    return ret;
}

void func_00116EB0(V0GsLoadPk *p, int dbw, int dpsm, int dsax, int dsay, int rrw, int rrh)
{
    func_002EF0D0(p, 0, sizeof(V0GsLoadPk));
    p->vif1 = 0x51000005;
    p->giftag.NLOOP = 4;
    p->giftag.EOP = 1;
    p->giftag.FLG = 0;
    p->giftag.NREG = 1;
    p->giftag.REGS0 = 0xE;
    p->bitbltbufaddr = 0x50;
    p->bitbltbuf.DBW = dbw;
    p->bitbltbuf.DPSM = dpsm;
    p->trxposaddr = 0x51;
    p->trxpos.DSAX = dsax;
    p->trxpos.DSAY = dsay;
    p->trxregaddr = 0x52;
    p->trxreg.RRW = rrw;
    p->trxreg.RRH = rrh;
    p->trxdiraddr = 0x53;
}

void func_001170A8(V0TexHdr *h, V0TexUpload *t)
{
    t->tbw = h->w >> 6;
    t->data = h->data;
    t->h66 = h->h2;
    func_00116EB0(&t->pk, t->tbw, h->psm, h->x, h->y, h->w, h->h);
}

void func_001170E8(int *in, V0TexUpload *t)
{
    int rrh;

    if (in[0] <= 16) {
        t->n.i = 1;
        rrh = 2;
    } else {
        t->n.i = 4;
        rrh = 16;
    }
    t->data = in[1];
    t->h66 = t->n.h;
    func_00116EB0(&t->pk, 1, 0, 0, 0, 16, rrh);
}

typedef struct {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long TCC : 1;
    unsigned long TFX : 2;
    unsigned long CBP : 14;
    unsigned long CPSM : 4;
    unsigned long CSM : 1;
    unsigned long CSA : 5;
    unsigned long CLD : 3;
} GsTex0Bits;

typedef struct {
    u8 pad00[0x18];
    GsTex0Bits tex0;
} TexInfo7B0;

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", func_00117140);

s32 func_00117330(void)
{
    return D_0057F6B4;
}

s32 func_00117340(void)
{
    return D_0057F6BC;
}

s32 func_00117350(void)
{
    return D_0057F6B0;
}

s32 func_00117360(void)
{
    return D_0057F6B8;
}

s32 func_00117370(void)
{
    return D_0057F6C0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", Ch_TextureReMapping);

u16 Ch_TextureGetNbImage(Chr *chr)
{
    ChrParamSub *s = chr->param->sub14;

    if (s == 0) {
        return 0;
    }
    return s->h0C;
}

u16 func_00117580(Chr *chr)
{
    ChrParamSub *s = chr->param->sub14;

    if (s == 0) {
        return 0;
    }
    return s->h08;
}

s32 Ch_TextureGetImagePtr(Chr *chr, s32 i, s32 *out1, s32 *out2)
{
    ChrParamSub *s = chr->param->sub14;
    ChrAnimEnt *e;

    if (s == 0) {
        return 0;
    }
    e = &s->ents[i];
    *out1 = e->h08;
    *out2 = e->h0A;
    return e->w0C;
}

s32 func_001175D8(Chr *chr, int i, s32 *out)
{
    ChrParamSub *sub = chr->param->sub14;
    ChrAnimPair *p;
    s32 a, b;

    if (sub == 0) {
        return 0;
    }
    p = &sub->pairs[i];
    a = p->a;
    b = p->b;
    *out = a;
    return b;
}

typedef struct {
    u8 pad00[0x14];
    void *p14;
    int *p18;
    V0TexHdr *p1C;
} TexResourceSet;

extern TexResourceSet *D_00307EA8;
extern V0TexUpload D_0057F6D0;
extern V0TexUpload D_0057F740;

void func_00117608(void)
{
    TexResourceSet *s = D_00307EA8;

    Ch_TexDataMapping((TexSubHdr *)s);
    func_001170E8(s->p18, &D_0057F740);
    func_001170A8(s->p1C, &D_0057F6D0);
    func_00117140(s->p14, &D_0057F7B0);
    D_0057F6D0.tbp = 0x2EA0;
    D_0057F740.tbp = 0x2EF8;
    Sg_GsloadSetBase(&D_0057F6D0);
    Sg_GsloadSetBase(&D_0057F740);
    ((TexInfo7B0 *)&D_0057F7B0)->tex0.TBP0 = D_0057F6D0.tbp;
    ((TexInfo7B0 *)&D_0057F7B0)->tex0.CBP = D_0057F740.tbp;
}

s32 *func_001176F0(void)
{
    return &D_0057F7B0;
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

Pkt16 *func_00117700(Pkt16 *pkt)
{
    V0TexUpload *t;
    s32 d;

    t = &D_0057F6D0;
    pkt->s.w0 = 0x30000006;
    pkt->s.w4 = (u32)t;
    pkt->s.q8 = 0;
    pkt++;
    {
        TexDataHdr *h;
        d = t->data;
        h = (TexDataHdr *)(d - 0x8000);
        h->vif1 = (u16)h->vif1 | 0x51000000;
        pkt->s.w0 = ((h->gif & 0x7FFF) + 2) | 0x30000000;
    }
    pkt->s.w4 = t->data - 0x20;
    pkt->s.q8 = 0;
    pkt++;
    t = &D_0057F740;
    pkt->s.w0 = 0x30000006;
    pkt->s.w4 = (u32)t;
    pkt->s.q8 = 0;
    pkt++;
    {
        TexDataHdr *h;
        d = t->data;
        h = (TexDataHdr *)(d - 0x8000);
        h->vif1 = (u16)h->vif1 | 0x51000000;
        pkt->s.w0 = ((h->gif & 0x7FFF) + 2) | 0x30000000;
    }
    pkt->s.w4 = t->data - 0x20;
    pkt->s.q8 = 0;
    return pkt + 1;
}

/* DEBT(CAST): integer-width views follow the existing shared interfaces. */
void Ch_TextureSetup(Chr *chr)
{
    ChrParamSub *parameters;
    u8 *work;

    parameters = chr->param->sub14;
    if ((parameters != 0) && ((u16) parameters->h10 >= 0x1029U))
    {
        work = user_malloc((parameters->h04 << 5) + (parameters->h08 * 0x70) + (parameters->h0C * 0x70), 6, D_005699E8, 0x170);
        func_002EF0D0(work, 0, Sg_MemGetSize(work));
        func_0011BB08(work, D_005699F0, -1);
        chr->work6E8 = work;
        Ch_TextureReMapping(chr);
        if (chr->w708 != 0)
        {
            chr->w70C = chr_texanim_set(chr->param->sub14, chr);
        }
    }
}

void Ch_ClutEnable(Chr *chr, int v)
{
    R0Rec16 *p = chr->p710;
    U0Rec70 *d = (U0Rec70 *)chr->w6F0; /* DEBT(CAST): w6F0 points at 0x70-byte records */
    int i;

    if (p) {
        for (i = 0, chr->b714 = v; i < chr->h6F4; i++) {
            d[i].w60 = v ? p[i].w0 : p[i].u4.w4;
        }
    }
}

void Ch_ClutDispose(void *p)
{
    Chr *chr = p;

    if (chr->p710 && op_get_chr_status_stone(chr) == 0) {
        Ch_ClutEnable(chr, 0);
        func_0011D590((s32)chr->p710, 6); /* DEBT(CAST): handle */
        chr->p710 = 0;
    }
}

typedef struct {
    void *p0;
    s32 w4;
    s32 w8;
    s32 wC;
} ClutRec16;

void Ch_ClutMapping(Chr *chr, s32 copy)
{
    u8 unused[0x20];
    ChrParamSub *sub = chr->param->sub14;
    ClutRec16 *tbl = (ClutRec16 *)chr->p710;
    s32 i, off, off20;

    if (tbl != 0) {
        off = chr->h6F4 * sizeof(ClutRec16);
        for (i = 0; i < chr->h6F4; i++) {
            ClutRec16 *r;
            ChrAnimPair *p;
            u32 src;

            for (off20 = off + 0x20; off20 & 0x7F; off20 = off + 0x20) {
                off++;
            }
            p = (ChrAnimPair *)(i * 8 + (s32)sub->pairs);
            src = p->b;
            r = (ClutRec16 *)(i * 16 + (s32)tbl);
            r->p0 = (u8 *)tbl + off20;
            r->w8 = ((*(u32 *)(src - 0x10) & 0x7FFF) + 2) << 4;
            r->w4 = src;
            r->wC = p->a;
            if (copy != 0) {
                func_002EEF1C((u8 *)r->p0 - 0x20, (void *)(src - 0x20), r->w8);
            }
            off = off20 + r->w8;
        }
    }
}

s32 _m2c_Ch_ClutCreate_Ch_ClutDispose(void *) __asm__("Ch_ClutDispose");
s32 _m2c_Ch_ClutCreate_Ch_ClutEnable(void *, s32) __asm__("Ch_ClutEnable");
s32 _m2c_Ch_ClutCreate_Ch_ClutMapping(void *, s32) __asm__("Ch_ClutMapping");
s32 _m2c_Ch_ClutCreate_func_0011BB08(s32, void *, s32) __asm__("func_0011BB08");
s32 _m2c_Ch_ClutCreate_func_0011C348(s32, s32) __asm__("func_0011C348");
s32 _m2c_Ch_ClutCreate_func_002F0008(void *, s32 *, s32) __asm__("func_002F0008");
s32 _m2c_Ch_ClutCreate_op_get_chr_status_stone() __asm__("op_get_chr_status_stone");
s32 _m2c_Ch_ClutCreate_user_malloc(s32, s32, s8 *, s32) __asm__("user_malloc");
extern s32 _m2c_Ch_ClutCreate_D_005699F8 __asm__("D_005699F8");
/* DEBT(CAST) */
void Ch_ClutCreate(void *arg0) {
    u8 sp[0x20];
    s16 temp_2;
    s32 var_16;
    s32 var_3;
    s32 var_5;
    s32 var_6;
    void *temp_18;

    temp_18 = (*(void **)((u8 *)((*(void **)((u8 *)(arg0) + (0x1D0)))) + (0x14)));
    if (_m2c_Ch_ClutCreate_op_get_chr_status_stone() == 0) {
        _m2c_Ch_ClutCreate_Ch_ClutDispose(arg0);
        temp_2 = (*(s16 *)((u8 *)(arg0) + (0x6F4)));
        var_5 = 0;
        var_16 = temp_2 * 0x10;
        if (temp_2 > 0) {
            do {
                var_6 = var_16 + 0x20;
                if (var_6 & 0x7F) {
                    var_3 = var_5 * 8;
                    do {
                        var_16 += 1;
                        var_6 = var_16 + 0x20;
                    } while (var_6 & 0x7F);
                } else {
                    var_3 = var_5 * 8;
                }
                var_5 += 1;
                var_16 = var_6 + ((((*(s32 *)((u8 *)((*(void **)((u8 *)((var_3 + (*(s32 *)((u8 *)(temp_18) + (0x18))))) + (4)))) + (-0x10))) & 0x7FFF) + 2) * 0x10);
            } while (var_5 < (s16) (u16) (*(s16 *)((u8 *)(arg0) + (0x6F4))));
        }
        _m2c_Ch_ClutCreate_func_0011C348(0x40, var_5);
        (*(s32 *)((u8 *)(arg0) + (0x710))) = _m2c_Ch_ClutCreate_user_malloc(var_16, 6, D_005699E8, 0x1CA);
        _m2c_Ch_ClutCreate_func_002F0008(sp, &_m2c_Ch_ClutCreate_D_005699F8, (*(s32 *)((u8 *)(arg0) + (4))));
        _m2c_Ch_ClutCreate_func_0011BB08((*(s32 *)((u8 *)(arg0) + (0x710))), sp, -1);
        _m2c_Ch_ClutCreate_Ch_ClutMapping(arg0, 1);
        _m2c_Ch_ClutCreate_Ch_ClutEnable(arg0, 1);
    }
}

s16 func_00117BB8(Chr *chr)
{
    return chr->h6F4;
}

s32 Ch_ClutGetSize(Chr *chr, s32 i)
{
    if (chr->p710 == 0) {
        return 0;
    }
    return (chr->p710[i].w8 - 32) / 4;
}

s32 Ch_ClutGetPtr(Chr *chr, s32 i)
{
    R0Rec16 *tbl = chr->p710;

    if (tbl == 0) {
        return 0;
    }
    return tbl[i].w0;
}

void *func_00117C18(Chr *chr, s32 i)
{
    R0Rec16 *tbl = chr->p710;

    if (tbl == 0) {
        return 0;
    }
    return tbl[i].u4.p4;
}

void rcefChgChrClut(Chr *chr)
{
    int i, j;
    int n = func_00117BB8(chr);

    for (i = 0; i < n; i++) {
        int size = Ch_ClutGetSize(chr, i);
        u8 *dst = (u8 *)Ch_ClutGetPtr(chr, i);
        u8 *src = (u8 *)func_00117C18(chr, i);

        for (j = 0; j < size; j++) {
            int v = (src[0] + src[1] + src[2]) / 3;

            src += 4;
            dst[2] = v;
            dst[1] = v;
            dst[0] = v;
            dst += 4;
        }
    }
}
