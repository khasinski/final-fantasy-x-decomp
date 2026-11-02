/* tu_007 0x106dc8-0x1074a8: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

void Ch_SoundSetId(Chr *chr, s8 v)
{
    chr->b190 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_106DC8", func_00106DD0);

INCLUDE_ASM("build/ee_asm/game/chr/ch_106DC8", func_00106E58);
INCLUDE_RODATA("build/ee_asm/game/chr/ch_106DC8/rodata", jtbl_00569570);

INCLUDE_ASM("build/ee_asm/game/chr/ch_106DC8", func_00107210);

void func_00107250(Chr *chr, Chr *other, s32 v, float x, float y, float z)
{
    chr->p1A8 = other;
    if (other) {
        chr->w1C4 = other->w19C;
    } else {
        chr->w1C4 = -1;
    }
    chr->w1AC = v;
    chr->v1B0[0] = x * 100.0f * chr->param->f38;
    chr->v1B0[1] = y * 100.0f * chr->param->f38;
    chr->v1B0[2] = z * 100.0f * chr->param->f38;
    chr->v1B0[3] = 1.0f;
}

void Ch_BindSetScale(Chr *chr, float v)
{
    chr->f1C0 = v;
}

void Ch_BindToElem(Chr *chr, Chr *target, s32 v)
{
    chr->p1A8 = target;
    if (target) {
        chr->w1C4 = target->w19C;
        Ch_ElemGetAttr((int)target, v, &chr->w1AC, (int)chr->v1B0); /* DEBT(TYPE): prototype takes ints */
    } else {
        chr->w1C4 = -1;
    }
}

/* DEBT(TYPE): declared with a return type (shared header) but no value is returned; callers ignore it */
s32 func_001072F8(Chr *chr, int i, void *dst)
{
    ChrSlot *s = &chr->slots[i];

    if (dst) {
        func_002DCE38(dst, chr->u1F0, s->u90);
    }
}

void *Ch_ElemGetBaseMatrix(Chr *chr, s32 i, void *src)
{
    ChrSlot *slot = &chr->slots[i];
    void *dst;

    if (src) {
        dst = &slot->u90;
        func_002DD0C0(src, dst);
    } else {
        dst = &slot->u90;
    }
    return dst;
}

void *Ch_GetRootGlobalMatrix(Chr *chr, void *src)
{
    void *dst;

    if (src) {
        dst = &chr->u1F0;
        func_002DD0C0(src, dst);
    } else {
        dst = &chr->u1F0;
    }
    return dst;
}

void *func_001073C0(Chr *chr, void *src)
{
    void *dst;

    if (src) {
        dst = &chr->u230;
        func_002DD0C0(src, dst);
    } else {
        dst = &chr->u230;
    }
    return dst;
}

s32 Ch_ElemGetParent(Chr *chr, s32 i)
{
    return chr->slots[i].data->w4;
}

/* DEBT(TYPE): legacy callers declare an integer result; no return value is consumed here. */
int func_00107428(Chr *chr, int bone, Vec4 *in, Vec4 *out)
{
    float matrix[4][4];
    func_002DCE38(matrix, chr->u1F0, chr->slots[bone].u90);
    if (in != 0) {
        func_002DCE08(out, matrix, in);
    } else {
        out->x = matrix[3][0];
        out->y = matrix[3][1];
        out->z = matrix[3][2];
    }
}
