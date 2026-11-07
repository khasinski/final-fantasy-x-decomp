/* tu_155 0x198860-0x198cd8: medium; unk_198860 (config/tu_map.tsv) */
#define func_00198AE8 _hdr_func_00198AE8
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#undef func_00198AE8

int func_00198860(int *p) {
    return p[5] + 0x20;
}

void func_00198870(void *p)
{
    func_002EF0D0(p, 0, 0x10);
}

void func_00198880(void *p)
{
}

void func_00198888(W3Blk *b, int n)
{
    b->img = func_00199ED8();
    func_00199FD8(b->img, 0x2E00, 1, 0, 0, 0, 0x10, 0x10, n + 1);
}

int func_001988E8(int *p) {
    return func_0019A408(p[3]);
}

void func_00198908(W3Blk *n) {
    if (n->flags & 1) {
        func_00198A68(n);
        return;
    }
    switch (n->b0A) {
    case 1:
        func_00198AE8(n);
        break;
    case 2:
        func_00198BC8(n);
        break;
    default:
        func_00198978(n);
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/rc_198860", func_00198978);

INCLUDE_ASM("build/ee_asm/game/rc/rc_198860", func_00198A68);

s32 _m2c_func_00198AE8_func_001988E8() __asm__("func_001988E8");
s32 _m2c_func_00198AE8_func_00198CB0(void *) __asm__("func_00198CB0");
void _m2c_func_00198AE8_func_0019A1A0(void *, s32) __asm__("func_0019A1A0");
void _m2c_func_00198AE8_func_002EEF1C(s32, s32, s32) __asm__("func_002EEF1C");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_00198AE8(void *arg0) {
    register s16 temp_3 __asm__("$3");
    register u32 temp_3_2 __asm__("$3");
    register s16 sub __asm__("$2");
    s16 temp_5;
    s32 temp_16;
    s32 temp_18;
    s32 temp_2;
    void *temp_4;

    temp_18 = _m2c_func_00198AE8_func_001988E8(arg0, (*(s16 *)((u8 *)(arg0) + (8))));
    temp_2 = _m2c_func_00198AE8_func_00198CB0(arg0);
    temp_5 = (*(s16 *)((u8 *)(arg0) + (6)));
    temp_16 = (0x100 - temp_5) * 4;
    _m2c_func_00198AE8_func_002EEF1C(temp_2, (temp_5 * 4) + temp_18, temp_16);
    _m2c_func_00198AE8_func_002EEF1C(temp_16 + temp_2, temp_18, (*(s16 *)((u8 *)(arg0) + (6))) * 4);
    temp_4 = (*(void **)((u8 *)(arg0) + (0xC)));
    _m2c_func_00198AE8_func_0019A1A0(temp_4, (*(s32 *)((u8 *)(temp_4) + (0x30))) - 1);
    temp_3 = (*(u16 *)((u8 *)(arg0) + (4))) + 1;
    (*(u16 *)((u8 *)(arg0) + (4))) = (u16) temp_3;
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0xB))) < temp_3) {
        temp_3_2 = (u16) (*(s16 *)((u8 *)(arg0) + (6))) + 1;
        (*(s16 *)((u8 *)(arg0) + (6))) = temp_3_2;
        if ((s16)temp_3_2 >= 0x100) {
            sub = temp_3_2 - 0x100;
            __asm__("" : "+r"(sub));
            (*(s16 *)((u8 *)(arg0) + (6))) = sub;
        }
        (*(u16 *)((u8 *)(arg0) + (4))) = 0U;
    }
}

s32 _m2c_func_00198BC8_func_001988E8() __asm__("func_001988E8");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_00198BC8(W3Blk *n) {
    W3Img *temp_4;
    register s16 temp_3 __asm__("$3");
    register u32 temp_3_2 __asm__("$3");
    register s16 sub __asm__("$2");
    s16 temp_5;
    s32 temp_16;
    s32 temp_18;
    void *temp_2;

    temp_18 = _m2c_func_00198BC8_func_001988E8(n, (*(s16 *)((u8 *)(n) + (8))));
    temp_2 = func_00198CB0(n);
    temp_5 = (*(s16 *)((u8 *)(n) + (6)));
    temp_16 = (0x100 - temp_5) * 4;
    func_002EEF1C(temp_2, (temp_5 * 4) + temp_18, temp_16);
    func_002EF0D0(temp_2 + temp_16, 0, (*(s16 *)((u8 *)(n) + (6))) * 4);
    temp_4 = n->img;
    func_0019A1A0(temp_4, temp_4->i30 - 1);
    temp_3 = (*(u16 *)((u8 *)(n) + (4))) + 1;
    (*(u16 *)((u8 *)(n) + (4))) = (u16) temp_3;
    if ((s32) n->b0B < temp_3) {
        temp_3_2 = (u16) (*(s16 *)((u8 *)(n) + (6))) + 1;
        (*(s16 *)((u8 *)(n) + (6))) = temp_3_2;
        if ((s16)temp_3_2 >= 0x100) {
            sub = temp_3_2 - 0x100;
            __asm__("" : "+r"(sub));
            (*(s16 *)((u8 *)(n) + (6))) = sub;
        }
        (*(u16 *)((u8 *)(n) + (4))) = 0U;
    }
}

void func_00198CA8(W3Blk *blk, int v) {
    ((short *)blk)[4] = v; /* DEBT(CAST): W3Blk is opaque */
}

int func_00198CB0(Q3Ctx *c) {
    Q3Ctx2 *s = c->sub;

    return func_0019A408(s, s->w30 - 1);
}
