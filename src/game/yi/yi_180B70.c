/* tu_132 0x180b70-0x184ea0: medium; ~yi (config/tu_map.tsv) */
#define func_001812C0 _hdr_func_001812C0
#include "common.h"
#include "vu0.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#undef func_001812C0

void func_00180B70(R2Big4000 *o) {
    int i;
    int *p = &o->q[0].a;
    for (i = 0; i < 0x400; i++) {
        p[0] = p[1] = p[2] = p[3] = 0;
        p += 4;
    }
    o->w4000 = 0;
    o->w4008 = 0;
    o->a4050[0] = o->a4050[1] = o->a4050[2] = o->a4050[3] = 0;
    o->a4060[0] = o->a4060[1] = o->a4060[2] = o->a4060[3] = 0;
    o->w407C = 0;
    o->w4080 = 0;
    o->w4074 = 0;
    o->w4078 = 0;
    o->w4084 = 0;
    o->w4088 = 0;
    o->b408C = 0;
    o->b408D = 0;
}

void func_00180BE8(void *unused) {
    int i;
    int j;

    for (i = 0; i < 0x400; i++) {
        for (j = 0; j < 4; j++) {
        }
        if ((i & 0xF) == 0) {
            func_002DA578(0);
        }
    }
}

typedef union {
    u32 w;
    struct {
        u16 imm;
        u8 num;
        u8 cmd;
    } s;
    struct {
        u8 cl;
        u8 wl;
        u8 num;
        u8 cmd;
    } c;
    struct {
        u16 imm;
        u8 num;
        struct {
            u8 vl : 2;
            u8 vn : 2;
            u8 pad : 4;
        } b;
    } b;
} YiVifCode;

typedef struct {
    u32 w[4];
} YiVuQ;

typedef struct {
    YiVuQ vu[0x400];
    union {
        struct {
            u32 b0 : 7;
            u32 dbf : 1;
        } f;
        u64 q;
    } stat;
    u8 pad4008[0x48];
    u32 row[4];
    u32 col[4];
    u32 mask;
    u32 top;
    u32 tops;
    u32 base;
    u32 offset;
    u32 mode;
    u32 mark;
    u8 wl;
    u8 cl;
} YiVifCtx;

s32 func_00180C58(YiVifCtx *ctx, u32 *packet, YiVifCode *code);
INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00180C58);

s32 yiExecVIFpacket(YiVifCtx *ctx, u32 *packet, u32 len)
{
    u32 *p = packet;
    YiVifCode code;
    u32 cmd;
    int i;

    while ((u32)(p - packet) < len) {
        code.w = *p++;
        cmd = code.s.cmd;
        cmd &= 0x7F;
        if ((cmd & 0x60) == 0x60) {
            cmd = 0x60;
        }
        switch (cmd) {
        case 0x00:
        case 0x06:
        case 0x10:
        case 0x11:
        case 0x13:
            break;
        case 0x01:
            ctx->wl = code.s.imm >> 8;
            ctx->cl = code.c.cl;
            break;
        case 0x02:
            ctx->offset = code.s.imm & 0x3FF;
            ctx->stat.f.dbf = 0;
            ctx->tops = ctx->base;
            break;
        case 0x03:
            {
                u32 v = code.s.imm & 0x3FF;
                ctx->base = v;
                ctx->stat.f.dbf = 0;
                ctx->tops = v;
            }
            break;
        case 0x04:
            ctx->tops = code.s.imm & 0x3FF;
            break;
        case 0x05:
            ctx->mode = code.s.imm & 3;
            break;
        case 0x07:
            ctx->mark = code.s.imm;
            break;
        case 0x14:
        case 0x15:
        case 0x17:
            ctx->top = ctx->tops;
            if (ctx->stat.f.dbf != 0) {
                ctx->tops = ctx->base;
                ctx->stat.f.dbf = 0;
            } else {
                ctx->tops = ctx->base + ctx->offset;
                ctx->stat.f.dbf = 1;
            }
            goto end;
        case 0x20:
            ctx->mask = *p++;
            break;
        case 0x30:
            for (i = 0; i < 4; i++) {
                ctx->row[i] = *p++;
            }
            break;
        case 0x31:
            for (i = 0; i < 4; i++) {
                ctx->col[i] = *p++;
            }
            break;
        case 0x4A:
            for (i = 0; i < code.s.num; i++) {
                p += 2;
            }
            break;
        case 0x50:
        case 0x51:
            p += code.s.imm * 4;
            break;
        case 0x60:
            p += func_00180C58(ctx, p, &code);
            break;
        default:
            BREAK();
            break;
        }
    }
end:
    return p - packet;
}

void func_001812C0(void)
{
}

typedef struct {
    u64 nloop : 15;
    u64 pad : 45;
    u64 nreg : 4;
} YiGifTag;

int func_001812C8(void *unused, int *arg1, u32 arg2) {
    int *p = arg1;
    int i;
    int j;
    YiGifTag *tag;

    while ((u32)(p - arg1) < arg2) {
        tag = (YiGifTag *)p;
        p++;
        for (i = 0; i < (int)tag->nloop; i++) {
            for (j = 0; j < (int)tag->nreg; j++) {
            }
        }
    }
}

extern s32 _m2c_func_00181378_D_0030EE00 __asm__("D_0030EE00");
/* DEBT(CAST) */
void func_00181378(void *arg0) {
    u8 sp[0x4090];
    s32 *var_17;
    s32 temp_2_2;
    s32 temp_3;
    s32 var_16;
    void *temp_2;
    void *var_18;

    func_00180B70(sp);
    yiExecVIFpacket(sp, &_m2c_func_00181378_D_0030EE00, 4);
    temp_2 = (*(void **)((u8 *)(arg0) + (0x68868)));
    if (temp_2 != 0) {
        var_18 = temp_2;
        do {
            var_17 = (*(s32 *)((u8 *)(var_18) + (0x44))) + 0x10;
            var_16 = (*(s32 *)((u8 *)(var_18) + (0x48))) * 4;
            if (var_16 != 0) {
                do {
                    temp_2_2 = yiExecVIFpacket(sp, var_17, var_16);
                    temp_3 = temp_2_2 * 4;
                    var_16 -= temp_2_2;
                    var_17 = (s32 *)((u8 *)var_17 + (temp_3));
                } while (var_16 != 0);
            }
            var_18 = (*(void **)((u8 *)(var_18) + (0x4C)));
        } while (var_18 != 0);
    }
    func_00180BE8(sp);
}

typedef struct {
    u8 b00;
    s8 b01;
    u16 h02;
    u32 w04;
    u32 w08;
    u32 w0C;
    u32 w10;
    u32 w14;
} YiOmdSub;

typedef struct {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0C;
    u16 h10;
    u16 h12;
    u16 h14;
    u8 b16;
    u8 b17;
    u32 w18;
    u32 w1C;
} YiOmdHdr;

void func_00181428(YiOmdHdr *o) {
    u8 *p;
    YiOmdSub *s;

    p = (u8 *)o + 0x20;
    o->w00 = 0;
    o->w1C = 0;
    o->w04 = p - (u8 *)o;
    o->w08 = 0x100;
    o->w0C = 0x100;
    o->h14 = 0;
    o->h12 = 0;
    o->b16 = 0;
    o->b17 = 0;
    o->h10 = 0;

    s = (YiOmdSub *)p;
    p += 0x20;
    s->b01 = -1;
    s->h02 = 0;
    s->w08 = 0;
    s->w0C = 0;
    s->w10 = 0;
    s->w14 = 0;
    o->h10++;

    s = (YiOmdSub *)p;
    p += 0x40;
    s->b01 = 0x22;
    s->h02 = 0;
    s->w08 = 0;
    s->w0C = 0;
    s->w10 = 0;
    s->w14 = 0;
    o->h10++;
    s->h02++;

    s = (YiOmdSub *)p;
    p += 0x20;
    s->w08 = 0;
    o->h10++;
    s->b01 = -1;
    s->h02 = 0;
    s->w0C = 0;
    s->w10 = 0;
    s->w14 = 0;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", yiPacketConvToOMD);

void func_00181B48(float *p, int n)
{
    if (n > 0) do {
        VU0_LQC2(5, 0x0, p);
        VU0_LQC2(6, 0x10, p);
        VU0_LQC2(7, 0x20, p);
        VU0_OP("vaddx.w $vf5, $vf0, $vf0x");
        VU0_OP("vaddx.w $vf6, $vf0, $vf0x");
        VU0_OP("vaddx.w $vf7, $vf0, $vf0x");
        VU0_OP("vmulax.xyzw ACC, $vf1, $vf5x");
        VU0_OP("vmadday.xyzw ACC, $vf2, $vf5y");
        VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf5z");
        VU0_OP("vmaddw.xyzw $vf5, $vf4, $vf5w");
        VU0_OP("vmulax.xyzw ACC, $vf1, $vf6x");
        VU0_OP("vmadday.xyzw ACC, $vf2, $vf6y");
        VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf6z");
        VU0_OP("vmaddw.xyzw $vf6, $vf4, $vf6w");
        VU0_OP("vmulax.xyzw ACC, $vf1, $vf7x");
        VU0_OP("vmadday.xyzw ACC, $vf2, $vf7y");
        VU0_OP("vmaddaz.xyzw ACC, $vf3, $vf7z");
        VU0_OP("vmaddw.xyzw $vf7, $vf4, $vf7w");
        VU0_SQC2(5, 0x0, p);
        VU0_SQC2(6, 0x10, p);
        VU0_SQC2(7, 0x20, p);
        p += 12;
        n--;
        VU0_OP("nop");
        VU0_OP("nop");
        VU0_OP("nop");
    } while (n != 0);
}

void func_00181BC8(float *m, float *v, int cnt)
{
    int n;

    VU0_LQC2(26, 0x0, m);
    VU0_LQC2(27, 0x10, m);
    VU0_LQC2(28, 0x20, m);
    VU0_LQC2(29, 0x30, m);
    n = cnt * 3;
    if (n > 0) do {
        VU0_LQC2(30, 0x0, v);
        VU0_OP("vaddx.w $vf30, $vf0, $vf0x");
        VU0_OP("vmulax.xyzw ACC, $vf26, $vf30x");
        VU0_OP("vmadday.xyzw ACC, $vf27, $vf30y");
        VU0_OP("vmaddaz.xyzw ACC, $vf28, $vf30z");
        VU0_OP("vmaddw.xyzw $vf30, $vf29, $vf30w");
        VU0_SQC2(30, 0x0, v);
        v += 4;
        n--;
        VU0_OP("nop");
        VU0_OP("nop");
        VU0_OP("nop");
    } while (n != 0);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00181C28);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_001836E0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180B70", func_00184AA8);
