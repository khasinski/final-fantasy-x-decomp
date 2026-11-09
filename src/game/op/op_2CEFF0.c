/* tu_333 0x2ceff0-0x2d0af0: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: bitfield/size helpers and wrappers (see w10.h). */
#define func_002CF8D0 _hdr_func_002CF8D0
#define func_002D0940 _hdr_func_002D0940
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r7.h"
#undef func_002D0940
#undef func_002CF8D0

void func_002CEFF0(void)
{
    int i;

    for (i = 0; i < 64; i++) {
        D_00764430.c[i] = 0;
        D_00764430.a[i] = 0;
        D_00764430.b[i] = 0;
        D_00764740.w10[i] = 0;
    }
    D_00764740.h00 = 0;
    D_00764430.h300 = 0;
    D_00764430.h302 = 0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF040);

void func_002CF1D0(s16 *values, int destination)
{
    func_002DAB10(D_006F2EE0, values[0], values[1], values[2], values[3], values[4], values[5], values[6]);
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DADD0(D_006F2EE0, destination);
    func_002DA610(0, 0);
    func_002F8660(0);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF258);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF388);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", op_oef2_texture_load);

typedef struct Oef2Clut {
    u16 h0;
    u8 pad2[2];
    int w4;
    u8 b8;
    u8 b9;
} Oef2Clut;

extern char D_00575FB0[];
void func_002EA328(int) __attribute__((noreturn));
void func_002CF388(int, int, int, int);

void op_oef2_clut_load(Oef2Clut *p, int a)
{
    if (p->w4 == 0) {
        func_00120108(D_00575FB0);
        func_002EA328(1);
    }
    func_002CF388(p->w4, p->b9, p->h0, a);
}

int func_002CF850(W10SoundVoice *voice, int value)
{
    u32 word;
    int previous;
    word = voice->header.word;
    previous = voice->header.half[0] & 0x3FFF;
    voice->active = 1;
    voice->header.word = (word & 0xFFFFC000) | (value & 0x3FFF);
    return previous;
}

int func_002CF880(W10SoundVoice *voice, int value)
{
    int v = (value & 0x3FFF) + (voice->header.half[0] & 0xFC);

    voice->active = 1;
    voice->header.word = (voice->header.word & 0xFFFFC000) | v;
    return v;
}

/* DEBT(CAST) */
u16 func_002CF8B8(void *arg0, s32 arg1) {
    u16 temp_2;

    temp_2 = (*(u16 *)((u8 *)(arg0) + (0)));
    (*(u16 *)((u8 *)(arg0) + (0))) = (u16) (arg1 & 0x3FFF);
    (*(s8 *)((u8 *)(arg0) + (0xF))) = 1;
    return temp_2;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_002CF8D0(void *arg0, s32 arg1) {
    register s32 _ret_v0 __asm__("$2");
    register u16 temp_5 __asm__("$5");

    __asm__ volatile("" : : : "memory");
    (*(s8 *)((u8 *)(arg0) + (0xF))) = 1;
    temp_5 = (arg1 & 0x3FFF) + ((*(u16 *)((u8 *)(arg0) + (0))) & 0x3C);
    _ret_v0 = temp_5;
    __asm__ volatile("" : "+r"(_ret_v0));
    (*(u16 *)((u8 *)(arg0) + (0))) = temp_5;
    return _ret_v0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF8F8);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CFA20);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CFC70);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CFE38);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0180);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0238);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D02E8);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0408);

int func_002D0570(int mask)
{
    EvQueue *q = &D_00764430;
    u16 cnt = q->h302;
    u16 base = q->h300;
    u16 i;

    for (i = 0; i < cnt; i++) {
        if (q->c[(u16)((base + i) % 64)] & mask) {
            return -1;
        }
    }
    return 0;
}

typedef struct EvSlotsFull {
    u16 h00;
    u8 pad02[0xE];
    u32 w10[64];
    u8 b110[64];
    void *p150[64];
} EvSlotsFull;

void op_oef2_texture_load(void *p, int a);

void func_002D05F0(int a)
{
    EvQueue *q = &D_00764430;
    int i;
    u32 *pb = q->b;
    u32 *pa = q->a;
    u32 *pc = q->c;

    for (i = 0; i < 64; i++, pa++, pb++, pc++) {
        u32 va = *pa;
        u32 vb = *pb;

        if (va != 0) {
            op_oef2_texture_load((void *)va, 1);
        }
        if (vb != 0) {
            op_oef2_clut_load((Oef2Clut *)vb, 1);
        }
        *pa = 0;
        *pb = 0;
        *pc = 0;
    }
    q->h300 = 0;
    q->h302 = 0;
}

void func_002D0698(u32 mask)
{
    if (D_00703FF6 != 0) {
        EvSlotsFull *d = (EvSlotsFull *)&D_00764740;
        int i;

        if (d->h00 != 0) {
            for (i = 0; i < d->h00; i++) {
                if (d->w10[i] & mask) {
                    if (d->b110[i] == 0) {
                        op_oef2_texture_load(d->p150[i], 1);
                    } else {
                        op_oef2_clut_load((Oef2Clut *)d->p150[i], 1);
                    }
                }
            }
        }
    }
}

void op_oef2_tex_clut_ovl_clear(u32 mask)
{
    EvSlots *d = &D_00764740;
    int last = -1;
    int i;

    for (i = 0; i < 64; i++) {
        if (d->w10[i] != 0) {
            if (d->w10[i] & mask) {
                d->w10[i] = 0;
            } else {
                last = i;
            }
        }
    }
    d->h00 = last + 1;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D07A0);

void func_002D0910(u_long128 *d, u_long128 *s)
{
    d[0] = s[0];
    d[1] = s[1];
}

void func_002D0928(u_long128 *d, u_long128 *s)
{
    d[0] = s[0];
}

void func_002D0938(void) {
}

void _m2c_func_002D0940_op_oef2_clut_load(int *p, int a) __asm__("op_oef2_clut_load");
void _m2c_func_002D0940_op_oef2_texture_load(int *p, int a) __asm__("op_oef2_texture_load");
extern s32 _m2c_func_002D0940_D_00518D40 __asm__("D_00518D40");
extern s32 _m2c_func_002D0940_D_00703FF3 __asm__("D_00703FF3");
void func_002D0940(void) {
    s32 var_16;
    s32 base;

    if ((u8) _m2c_func_002D0940_D_00703FF3 != 0) {
        var_16 = 0;
        base = (s32) &_m2c_func_002D0940_D_00518D40;
        op_oef2_set2((void *)base);
        do {
            _m2c_func_002D0940_op_oef2_texture_load(op_oef2_a_get(base, 2, var_16), 1);
            _m2c_func_002D0940_op_oef2_clut_load(op_oef2_a_get(base, 3, var_16), 1);
            var_16 += 1;
        } while (var_16 < 6);
    }
}

void func_002D09D0(u8 a) {
    D_00703FF6 = a;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D09E0);

void func_002D0AD0(void)
{
    op_gs1_transfer();
    func_002D05F0(0xFFFF);
}
