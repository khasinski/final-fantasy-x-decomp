/* tu_008 0x1074a8-0x10ad70: low; ~Ch (config/tu_map.tsv) */
#define Ch_ElemCalcQuaternion _hdr_Ch_ElemCalcQuaternion
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/g0.h"
#include "ffx/v0.h"
#undef Ch_ElemCalcQuaternion

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

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_00107D80);

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

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_OptposGet);

void func_00108990(Chr *chr, V128 *dst)
{
    *dst = chr->v6C0;
}

void func_001089A8(int a, int b)
{
    Ch_OptposGet(a, 0, b);
}

s32 Ch_OptposGetElement(s32 a, s32 b, s32 c)
{
    s32 out;

    Ch_ElemGetAttr(a, b, &out, c);
    return out;
}

s32 func_001089E0(s32 a, s32 b, s32 c, s32 d)
{
    s32 out;

    Ch_ElemGetAttr(a, b, &out, c);
    return func_001072F8(a, out, d);
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

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_IdShadeCalc);

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

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_MotEvent);

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

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_MoveChrBlk);

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_ClothResetRelation);

void func_00109430(void)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            Ch_ClothReset(p);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", MoveChrBlk_);

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

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_NeckSetEnable);

void Ch_NeckSetTarget(Chr *chr, s32 v)
{
    CHR_S32(chr, 0x4D0) = v; /* DEBT(CAST) */
    chr->b411 = 2;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A1F8(Chr *chr, Cmd16 *src)
{
    chr->b411 = 3;
    *(Cmd16 *)((u8 *)chr + 0x4D0) = *src; /* DEBT(CAST) */
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
    chr->f4D0 = a;
    chr->f4D4 = b;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A250(Chr *chr, float v)
{
    if (v == 0.0f) {
        v = 6.0f;
    }
    CHR_F32(chr, 0x424) = v; /* DEBT(CAST) */
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
