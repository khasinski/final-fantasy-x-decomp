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

void Ch_OptposGet(Chr *chr, int i, void *dst);
void func_00299860(Chr *chr, void *pos, int a, int b);

void func_00106DD0(Chr *chr)
{
    float a[4];
    float b[4];

    Ch_OptposGet(chr, 8, a);
    Ch_OptposGet(chr, 7, b);
    if (a[1] > b[1]) {
        func_00299860(chr, a, 0, 0);
    } else {
        func_00299860(chr, b, 0, 0);
    }
}

typedef struct ChrSeView {
    u8 pad000[0x190];
    s8 b190;
    u8 pad191[7];
    s32 w198;
    u8 pad19C[4];
    struct {
        u64 pad0 : 29;
        u32 bit29 : 1;
    } f1A0;
    u8 pad1A8[0x830 - 0x1A8];
    struct {
        u64 pad0 : 32;
        u32 bf32 : 2;
        u32 bf34 : 1;
        u32 bf35 : 2;
    } f830;
} ChrSeView;

void func_002D6E48(int a, int b, int c, int d);
int MsChrSEplayMotion(s32 a, s32 b);

void func_00106E58(Chr *chr, s32 arg1)
{
    ChrSeView *v = (ChrSeView *)chr;
    s32 lo = arg1 & 0xFF;
    s32 hi = (arg1 >> 8) & 0xFF;
    s32 cnt = 0;

    if (hi == 0) {
        switch (lo) {
        case 1:
            func_002D6E48(1, v->b190, func_00121AA0(chr), v->f830.bf32++);
            func_00106DD0(chr);
            break;
        case 2:
            func_002D6E48(0, v->b190, func_00121AA0(chr), v->f830.bf32++);
            func_00106DD0(chr);
            break;
        case 10:
        case 11:
            func_002D6E48(0, v->b190, func_00121AA0(chr), v->f830.bf32++);
            break;
        case 3:
            func_002D6E48(4, v->b190, func_00121AA0(chr), v->f830.bf34++);
            break;
        case 4:
            Ch_GetDumpMotEv();
            if (v->f1A0.bit29 != 0) {
                func_002D6E48(3, v->b190, func_00121AA0(chr), v->f830.bf35++);
            } else {
                func_002D6E48(2, v->b190, func_00121AA0(chr), v->f830.bf35++);
            }
            break;
        case 5:
            func_002D6E48(5, v->b190, func_00121AA0(chr), 0);
            break;
        case 17:
            cnt++;
        case 16:
            cnt++;
        case 15:
            cnt++;
        case 14:
            cnt++;
        case 13:
            cnt++;
        case 12:
            cnt += 2;
            Ch_GetDumpMotEv();
            func_002D6E48(0xFF, v->b190, 0, cnt);
            break;
        }
    } else if (hi == 1) {
        MsChrSEplayMotion(v->w198, lo);
        if (lo == 6) {
            func_00106DD0(chr);
        }
    }
}

void func_00107210(Chr *chr, Chr *other, s32 v)
{
    float *p;

    chr->p1A8 = other;
    if (other) {
        chr->w1C4 = other->w19C;
    } else {
        chr->w1C4 = -1;
    }
    chr->w1AC = v;
    p = chr->v1B0;
    p[0] = p[1] = p[2] = 0.0f;
    chr->v1B0[3] = 1.0f;
}

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
        Ch_ElemGetAttr(target, v, &chr->w1AC, chr->v1B0);
    } else {
        chr->w1C4 = -1;
    }
}

void func_001072F8(Chr *chr, int i, void *dst)
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
