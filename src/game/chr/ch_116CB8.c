/* tu_023 0x116cb8-0x117d38: medium; ~Ch (config/tu_map.tsv) */
#define Ch_ClutCreate _hdr_Ch_ClutCreate
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/v0.h"
#undef Ch_ClutCreate

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", Ch_TexDataMapping);

void Sg_GsloadSetBase(V0TexUpload *t)
{
    t->pk.bitbltbuf.DBP = t->tbp;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", func_00116E50);

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

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", func_00117608);

s32 *func_001176F0(void)
{
    return &D_0057F7B0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", func_00117700);

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
            d[i].w60 = v ? p[i].w0 : p[i].w4;
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

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", Ch_ClutMapping);

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
    Quad4 *tbl = CHR_PTR(chr, 0x710, Quad4); /* DEBT(CAST) */

    if (tbl == 0) {
        return 0;
    }
    return tbl[i].w0;
}

void *func_00117C18(s32 a, s32 i)
{
    Quad4 *tbl = CHR_PTR((Chr *)a, 0x710, Quad4); /* DEBT(CAST)/DEBT(TYPE): arg is a Chr */

    if (tbl == 0) {
        return 0;
    }
    return tbl[i].w4;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_116CB8", rcefChgChrClut);
