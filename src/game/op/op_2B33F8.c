/* tu_328 0x2b33f8-0x2b4630: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: EE kernel thread/semaphore wrappers (SDK) (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/g4.h"
#include "ffx/r7.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", op_spline_draw_path3);

void func_002B3708(void)
{
    func_002DD610(D_004F4050, 512.0f, 0.8f, 0.87285f, 2048.0f, 2048.0f, 1.0f, 16777215.0f, 1.0f, 65536.0f);
}

void func_002B3778(void)
{
    if (GIF_CHCR & 0x100) {
        func_002B3778();
    }
}

void func_002B37A0(void) {
}

void func_002B37A8(void) {
}

void func_002B37B0(void) {
}

void func_002B37B8(void) {
}

void func_002B37C0(void)
{
    D_00703F20 = 0x70000000;
    D_00764130 = 0x70004000;
    D_004F3F80 = 0;
    D_004F4110 = 0;
}

void func_002B37F0(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", op_pad_set);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3888);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3938);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B39C0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3A48);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3AC8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3B08);

void func_002B3B48(const char *path, void *buffer)
{
    s8 saved;
    saved = D_00764990.mode15;
    D_00764990.mode15 = 1;
    op_file_read(path, buffer);
    D_00764990.mode15 = saved;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", op_file_read);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3C88);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3D10);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3D68);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3DB0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3DF8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3E38);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3EA8);

void func_002B3ED0(ObjH4 *o, int q, u16 r)
{
    int i;

    for (i = 0; i < o->n; i++) {
        op_mfifo_set(o, q, 0, r);
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", op_mfifo_set);

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B40E8);

void func_002B4190(s32 a, s32 b) {
    func_002B40E8(a, b, 0x100);
}

void func_002B4198(s32 a, s32 b) {
    func_002B40E8(a, b, 0x80);
}

void func_002B41A0(s32 a, s32 b) {
    func_002B40E8(a, b, 0x40);
}

void func_002B41A8(s32 a, s32 b) {
    func_002B40E8(a, b, 0x20);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B41B0);

void func_002B4220(s32 a) {
    if (D_00764990.primary) {
        func_20662E8(a);
    }
    if (D_00764990.mirror) {
        func_20662E8(a);
    }
}

void func_002B4280(s32 a) {
    if (D_00764990.primary) {
        func_20663D0(a);
    }
    if (D_00764990.mirror) {
        func_20663D0(a);
    }
}

void func_002B42E0(s32 a) {
    if (D_00764990.primary) {
        func_2066450(a);
    }
    if (D_00764990.mirror) {
        func_2066450(a);
    }
}

void func_002B4340(void) {
    if (D_00764990.primary) {
        func_2066460();
    }
    if (D_00764990.mirror) {
        func_2066460();
    }
}

void func_002B4390(s32 a, s32 b) {
    if (D_00764990.primary) {
        func_20675D8(a, b);
    }
    if (D_00764990.mirror) {
        func_20675D8(a, b);
    }
}

void func_002B4400(s32 a) {
    if (D_00764990.primary) {
        func_2067610(a);
    }
    if (D_00764990.mirror) {
        func_2067610(a);
    }
}

void func_002B4460(s32 a) {
    if (D_00764990.primary) {
        func_2067700(a);
    }
    if (D_00764990.mirror) {
        func_2067700(a);
    }
}

void func_002B44C0(s32 a) {
    if (D_00764990.primary) {
        func_2067808(a);
    }
    if (D_00764990.mirror) {
        func_2067808(a);
    }
}

void func_002B4520(s32 a) {
    if (D_00764990.primary) {
        func_20679D8(a);
    }
    if (D_00764990.mirror) {
        func_20679D8(a);
    }
}

void func_002B4580(s8 a) {
    if (D_00764990.primary) {
        func_20675F0(a);
    }
    if (D_00764990.mirror) {
        func_20675F0(a);
    }
}

void func_002B45E0(void)
{
    if (D_00764990.primary) {
        func_2067600();
    }
    if (D_00764990.mirror) {
        func_2067600();
    }
}
