/* tu_008 0x1074a8-0x10ad70: low; ~Ch (config/tu_map.tsv) */
#define Ch_ElemCalcQuaternion _hdr_Ch_ElemCalcQuaternion
#define tex_anim_no_set _hdr_tex_anim_no_set
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/g0.h"
#include "ffx/v0.h"
#undef Ch_ElemCalcQuaternion
#undef tex_anim_no_set

s32 func_001074A8(s32 i)
{
    return D_0057E9B0[i];
}

void func_001074C0(s32 i, s32 v)
{
    D_0057E9B0[i] = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_001074D8);

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_00107600);

void func_00107888(float v)
{
    D_0057E9D0 = v;
    D_0057E9D4 = v;
}

float Sg_GetSuimen(void)
{
    return D_0057E9D0;
}

void func_001078B0(float v)
{
    D_0057E9D4 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_001078C0);

s8 func_00107B18(Chr *chr)
{
    return chr->b192;
}

void JobSchedule_Ch_CalcMiddle_Batch(FloatTween *t)
{
    if (t->cur != t->dst) {
        if (t->frames != 0) {
            t->cur = t->cur + (t->dst - t->cur) / (float)t->frames;
        } else {
            t->cur = t->dst;
        }
    }
    if (t->frames != 0) {
        t->frames--;
    }
}

void func_00107B78(s32 v)
{
    D_0057E9D8 = v & 0x1;
}

s32 func_00107B88(void)
{
    return D_0057E9D8;
}

void func_00107B98(Chr *chr)
{
    if (!((s32)chr->flags & 1)) {
        chr->flags |= 8;
    }
}

void Ch_ReserveCalcNorm2(Chr *chr)
{
    if (!((s32)chr->flags & 1)) {
        chr->flags |= 0x10;
    }
}

s32 Ch_SetCalcNorm(Chr *chr, s32 v)
{
    s32 old = (s32)chr->flags & 1;

    FLAGS_SET(chr, 0, v);
    return old;
}

s32 func_00107C10(Chr *chr)
{
    return (s32)chr->flags & 0x1;
}

void func_00107C20(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 2, v);
}

int func_00107C40(int v) /* DEBT(TYPE): declared int in q2.h, returns nothing */
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            Ch_SetCalcNorm(p, v);
        }
    }
}

void Ch_AllReserveCalcNorm(void)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            func_00107B98(p);
        }
    }
}

void func_00107D60(void)
{
    D_0057E9DC = 0x1;
}

void Ch_CalcNormalAutoInit(void)
{
    D_0057E9E0 = 0;
}

s32 Sg_GetFuka(s32 a);

void func_00107D80(void)
{
    s32 n = 500 - Sg_GetFuka(0);
    Chr *p;

    if (n < 39) {
        return;
    }
    n /= 40;
    if (D_0057E9E0 == 0) {
        D_0057E9E0 = (s32)D_00300664;
    }
    p = (Chr *)D_0057E9E0;
    while (n != 0) {
        p++;
        if (p >= D_00300664 + D_00300668) {
            p = D_00300664;
        }
        if (p == (Chr *)D_0057E9E0) {
            break;
        }
        if (p->active && (p->flags & 6) && ((s32)((u64)p->flags >> 38) & 1)) {
            Ch_ReserveCalcNorm2(p);
            n--;
            D_0057E9E0 = (s32)p;
        }
    }
    if (n != 0) {
        D_0057E9E0 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_00107EC8);

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_00108178);

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_CalcElement);

s32 func_00108750(Chr *chr, s32 key)
{
    ParamTbl *t = chr->param->tbl6C;
    ParamEntry *e;
    s32 n = t->count;

    n--;
    e = t->ents;
    while (n != -1) {
        if ((e->key & 0x3FFF) == key) {
            return e->val;
        }
        e++;
        n--;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_ElemGetAttr);

s32 func_001088E0(Chr *chr, s32 i)
{
    return chr->fx[i].f != 0;
}

typedef union {
    V128 q;
    Vec4 v;
} OptVec;

typedef struct {
    u8 pad000[0x220];
    Vec4 pos220;
    u8 pad230[0x300];
    OptVec opt530[1];
} ChrOptView;

void Ch_OptposGet(int a, int i, int b)
{
    ChrOptView *chr = (ChrOptView *)a;
    OptVec *dst = (OptVec *)b;

    if (chr->opt530[i].v.w == 0.0f) {
        if (chr->opt530[0].v.w == 0.0f) {
            dst->v.x = chr->pos220.x;
            dst->v.y = chr->pos220.y;
            dst->v.z = chr->pos220.z;
            dst->v.w = 1.0f;
        } else {
            dst->q = chr->opt530[0].q;
        }
    } else {
        dst->q = chr->opt530[i].q;
    }
}

void func_00108990(Chr *chr, V128 *dst)
{
    *dst = chr->v6C0;
}

void func_001089A8(int a, int b)
{
    Ch_OptposGet(a, 0, b);
}

s32 Ch_OptposGetElement(Chr *a, s32 b, s32 c)
{
    s32 out;

    Ch_ElemGetAttr(a, b, &out, (void *)c);
    return out;
}

void func_001089E0(Chr *a, s32 b, s32 c, void *d)
{
    s32 out;

    Ch_ElemGetAttr(a, b, &out, (void *)c);
    func_001072F8(a, out, d);
}

void func_00108A28(Chr *chr, V128 *dst)
{
    *dst = chr->v6A0;
}

void func_00108A40(Chr *chr, V128 *dst)
{
    *dst = chr->v6B0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_OptposCalc);

void func_00108DA0(Chr *chr, s32 i, s32 v)
{
    chr->slots[i].wD0 = v;
}

void func_00108DB8(Chr *chr, s32 i, float f, s32 v)
{
    /* DEBT(ORDER): sw before swc1 in source, scheduler swaps them */
    chr->slots[i].wD4 = v;
    chr->slots[i].fE8 = f;
}

float func_00108DD8(float *a, float *b)
{
    float d[3];

    d[0] = b[0] - a[0];
    d[1] = b[1] - a[1];
    d[2] = b[2] - a[2];
    return sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
}

float func_00108E50(float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

void Ch_IdEnableShade(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 18, v);
}

typedef struct {
    u8 pad00[0x40];
    float pos40[4];
    u8 pad50[0x40];
    float pos90[4];
    float posA0[4];
    float posB0[4];
} ChrShadeView;

s32 Ch_IdGetShade0(Chr *chr);
s32 Ch_IdGetShade1(Chr *chr);
s32 Ch_IdGetShade2(Chr *chr);
void func_00110478(Chr *chr, float v, s32 frames);

void Ch_IdShadeCalc(Chr *chr)
{
    ChrShadeView *sv = (ChrShadeView *)chr;
    float v[4];

    if (Sg_IdExistShade() == 0) {
        return;
    }
    if (!FLAGS_BIT(chr, 18)) {
        return;
    }
    v[0] = func_00108DD8(sv->pos40, sv->pos90);
    v[1] = func_00108DD8(sv->pos40, sv->posA0);
    v[2] = func_00108DD8(sv->pos40, sv->posB0);
    func_002DCEC8(v, v);
    v[0] = 1.0f - v[0];
    v[1] = 1.0f - v[1];
    v[2] = 1.0f - v[2];
    func_002DCEC8(v, v);
    v[0] *= Ch_IdGetShade0(chr) / 31.0f;
    v[1] *= Ch_IdGetShade1(chr) / 31.0f;
    v[2] *= Ch_IdGetShade2(chr) / 31.0f;
    func_00110478(chr, func_00108E50(v), 3);
}

void func_00109030(Chr *chr, s32 a, s32 b)
{
    chr->w804 = a;
    chr->w808 = b;
}

void func_00109040(s8 v)
{
    D_00303634 = v;
}

s8 Ch_GetDumpMotEv(void)
{
    return D_00303634;
}

typedef struct {
    s8 b00;
    s8 b01;
    s16 h02;
    s16 h04;
    s16 h06;
} MotEv;

typedef struct {
    u8 pad000[0x198];
    s32 w198;
    u8 pad19C[0x56C];
    s32 w708;
    s32 w70C;
    u8 pad710[0x40];
    s32 w750;
    u8 pad754[0xA8];
    s16 h7FC;
    s16 h7FE;
    MotEv *p800;
    void (*p804)(s32, s32);
    s32 w808;
} ChrMotEvView;

s32 func_001E1020(s32 id, s32 a, s32 b);
void func_00106E58(Chr *chr, s32 a);
void tex_anim_no_set(s32 a, s32 b, s32 c);

void Ch_MotEvent(Chr *chr)
{
    ChrMotEvView *mv = (ChrMotEvView *)chr;
    MotEv *ev;
    s32 cur;
    s32 prev;
    s32 i;

    if (mv->p800 == 0) {
        return;
    }
    cur = mv->w750 >> 8;
    prev = mv->h7FE;
    if (prev < cur) {
        for (i = 0, ev = mv->p800; i < mv->h7FC; i++) {
            s32 step;
            if (prev < ev->h04 && cur >= ev->h02) {
                switch (ev->b00) {
                case 5:
                    func_001E1020(mv->w198, ev->h06, 0);
                    break;
                case 1:
                    func_00106E58(chr, ev->h06);
                    break;
                case 3:
                    if (mv->w708 != 0) {
                        tex_anim_no_set(mv->w70C, (u16)ev->h06 >> 8, (u16)ev->h06 & 0xFF);
                    }
                    break;
                case 2:
                    if (mv->p804 != 0) {
                        mv->p804(mv->w808, ev->h06);
                    }
                    break;
                }
            }
            step = ev->b01 * 4 + 8;
            ev = (MotEv *)((u8 *)ev + step);
        }
    }
    mv->h7FE = cur;
}

void func_001091C8(void)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            p->flags &= ~(1L << 24);
            p->flags &= ~(1L << 25);
            p->flags &= ~(1L << 26);
        }
    }
}

void Ch_CbArcMapping(Rec12C *blk, s32 a);
void func_00102AF8(Chr *chr, Rec12C *blk);
void func_001603E0(s32 a, s32 b);

void Ch_MoveChrBlk(s32 a, s32 b)
{
    Rec12C *blk = 0;
    s32 i;
    Chr *chr;
    s32 diff;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 != -1 && chrblk[i].w6C == b) {
            blk = &chrblk[i];
        }
    }
    if (blk != 0) {
        Ch_CbArcMapping(blk, a);
        diff = a - b;
        for (chr = D_00300664; chr != D_00300664 + D_00300668; chr++) {
            if (chr->active && (Rec12C *)chr->param == blk) {
                func_00102AF8(chr, blk);
                ((s32 (*)(Chr *))Ch_TextureReMapping)(chr);
                if (chr->w708 != 0) {
                    func_001603E0(((Rec12C *)chr->param)->w14, chr->w70C);
                }
                if (*(s32 *)&chr->pad75E[6] != 0) {
                    *(s32 *)&chr->pad75E[6] += diff;
                }
            }
        }
    }
}

void Ch_ClothResetRelation(Chr *chr)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active && !FLAGS_BIT(p, 23) && p != chr && p->p1A8 == chr) {
            Ch_ClothReset(p);
        }
    }
}

void func_00109430(void)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            Ch_ClothReset(p);
        }
    }
}

s32 Sg_MemGetSize(s32 a);
void func_0011D590(s32 a, s32 b);
extern char D_005695F8[];

void MoveChrBlk_(void)
{
    s32 i;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 != -1) {
            s32 old = chrblk[i].w6C;
            s32 size = Sg_MemGetSize(old);
            s32 mem;

            func_0011C348(0x80);
            mem = (s32)user_malloc(size, 6, D_005695F8, 0x4B8);
            func_002EEF1C(mem, old, size);
            func_0011D590(old, 6);
            Ch_MoveChrBlk(mem, old);
        }
    }
}

void func_00109590(Chr *chr, float *out)
{
    out[0] = chr->f20 - chr->f10;
    out[1] = chr->f24 - chr->f14;
    out[2] = chr->f28 - chr->f18;
}

void func_001095C8(Chr *chr, float *out)
{
    out[0] = chr->f30 - chr->f10;
    out[1] = chr->f34 - chr->f14;
    out[2] = chr->f38 - chr->f18;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_CalcMain);

void func_00109B80(void) {
}

void func_00109B88(Chr *chr, s8 v)
{
    chr->b4E0 = v;
}

s8 func_00109B90(Chr *chr)
{
    return chr->b4E0;
}

void func_00109B98(s32 v)
{
    if (v < 0) {
        v = 0;
    }
    if (v > 200) {
        v = 200;
    }
    D_00303638 = v;
}

s16 func_00109BC0(void)
{
    return D_00303638;
}

void func_00109BD0(s8 a, s8 b)
{
    D_00303636 = a;
    D_00303637 = b;
}

s8 func_00109BE8(void)
{
    return D_00303636;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_00109BF8(void *arg0) {
    register u8 *saved_reg_gp __asm__("$28");
    (*(float *)((u8 *)(arg0) + (0x4E4))) = (float) (*(float *)((u8 *)(saved_reg_gp) + (-0x7E90)));
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_Mouth);

void _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion(void *, s32 *) __asm__("Sg_MatrixToQuaternion");
void _m2c_Ch_ElemCalcQuaternion_Sg_QuaternionSlerp(s32 *, s32 *, s32 *, float) __asm__("Sg_QuaternionSlerp");
void _m2c_Ch_ElemCalcQuaternion_func_00120958(s32 *, void *) __asm__("func_00120958");
void _m2c_Ch_ElemCalcQuaternion_func_002DD0C0(void *, void *) __asm__("func_002DD0C0");
/* DEBT(CAST) */
void Ch_ElemCalcQuaternion(void *arg0) {
    u8 sp[0x10];
    u8 sp10[0x10];
    float temp_f1;
    float temp_f20;
    float temp_f21;
    float temp_f22;
    void *temp_17;

    temp_f1 = (*(float *)((u8 *)(arg0) + (0xE8)));
    if (temp_f1 != 0.0f) {
        temp_f22 = (*(float *)((u8 *)(arg0) + (0xC0)));
        temp_f21 = (*(float *)((u8 *)(arg0) + (0xC4)));
        temp_f20 = (*(float *)((u8 *)(arg0) + (0xC8)));
        if (temp_f1 == 1.0f) {
            _m2c_Ch_ElemCalcQuaternion_func_002DD0C0(arg0 + 0x90, (*(void **)((u8 *)(arg0) + (0xD4))));
        } else if (temp_f1 != 0.0f) {
            temp_17 = arg0 + 0x90;
            _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion(temp_17, sp10);
            _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion((*(void **)((u8 *)(arg0) + (0xD4))), sp);
            _m2c_Ch_ElemCalcQuaternion_Sg_QuaternionSlerp(sp10, sp, sp, (*(float *)((u8 *)(arg0) + (0xE8))));
            _m2c_Ch_ElemCalcQuaternion_func_00120958(sp, temp_17);
        }
        (*(float *)((u8 *)(arg0) + (0xC0))) = temp_f22;
        (*(float *)((u8 *)(arg0) + (0xC4))) = temp_f21;
        (*(float *)((u8 *)(arg0) + (0xC8))) = temp_f20;
    }
}

typedef struct {
    s8 b00;
    s8 b01;
    s8 b02;
    u8 pad03[5];
    float f08;
    u8 pad0C[4];
    float f10;
    float f14;
    float f18;
    float f1C;
    float m20[4][4];
    float m60[4][4];
    float qA0[4];
    float fB0;
} ChrNeck;

void Ch_NeckSetEnable(void *a, int v)
{
    ChrNeck *n = (ChrNeck *)((u8 *)a + 0x410);

    n->b00 = v;
    if (v != 0) {
        n->f08 = 1.0f;
        if (n->b02 != n->b01) {
            _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion(n->m60, (s32 *)n->qA0);
            n->fB0 = 1.0f;
        }
    } else {
        n->f08 = 0.0f;
    }
    n->b02 = n->b01;
}

void Ch_NeckSetTarget(Chr *chr, s32 v)
{
    chr->u4D0.w4D0 = v;
    chr->b411 = 2;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A1F8(Chr *chr, Cmd16 *src)
{
    chr->b411 = 3;
    chr->u4D0.cmd = *src;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A220(Chr *chr)
{
    chr->b411 = 1;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A230(Chr *chr, float a, float b)
{
    chr->b411 = 4;
    chr->u4D0.f.f4D0 = a;
    chr->u4D0.f.f4D4 = b;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A250(Chr *chr, float v)
{
    if (v == 0.0f) {
        v = 6.0f;
    }
    chr->f424 = v;
}

void func_0010A270(Chr *chr, float x, float y)
{
    chr->f428 = x;
    chr->f42C = y;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_NeckInit);

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_Neck);

Chr *Ch_TextureAnimGetHandle(s32 v)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active && p->w70C == v) {
            return p;
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_CalcMiddle_Batch);
