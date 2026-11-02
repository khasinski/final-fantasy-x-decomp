/* tu_333 0x2ceff0-0x2d0af0: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: bitfield/size helpers and wrappers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r7.h"

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

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", op_oef2_clut_load);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF880);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF8B8);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002CF8D0);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D05F0);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0698);

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

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D0940);

void func_002D09D0(u8 a) {
    D_00703FF6 = a;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEFF0", func_002D09E0);

void func_002D0AD0(void)
{
    op_gs1_transfer();
    func_002D05F0(0xFFFF);
}
