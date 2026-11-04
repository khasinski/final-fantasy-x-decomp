/* tu_331 0x2b6b50-0x2cec08: medium; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: misc wrappers (see w10.h). */
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r7.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op_md_size_get);

extern char D_00575CC8[];
extern void func_00120108(char *fmt, ...);
extern void func_002EA328(s32 status) __attribute__((noreturn));

void op_md_copy(u_long128 *src, u_long128 *dst)
{
    s32 n = op_md_size_get(src);
    u_long128 *s;
    u_long128 *d;

    if (n == 0)
    {
        func_00120108(D_00575CC8);
        func_002EA328(1);
    }
    s = src;
    d = dst;
    n /= 16;
    while (n > 0)
    {
        *d++ = *s++;
        n--;
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op_md_tex0_change_limit);

void op_md_tex0_change(s32 a, u64 b) {
    op_md_tex0_change_limit(a, b, 0, 0x4000);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B6E20);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B6E40);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op_md_tex0_reset);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B6EC8);

s32 op_md_packet_size_check(void) {
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op_md_vn_index);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B7128);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B7208);

/* ambient light colour packed to RGBA8 */
u32 func_002B7320(void)
{
    float col[4] __attribute__((aligned(16)));
    u32 t;
    u32 k;
    u32 res;

    Sg_LightGetColor(3, col);
    __asm__ volatile("" : : "r"(0x70003F00)); /* DEBT(FAKE): the original loads the scratchpad base here and never uses it */
    t = 0xFFFFFFFF;
    MMI_OP2Z("pextlb", t, t);
    MMI_OP2Z("pextlh", t, t);
    VU0_QMTC2_NI(30, t);
    VU0_OP("vitof0.xyzw $vf30, $vf30");
    k = 0x43800000;
    VU0_QMTC2_NI(29, k);
    VU0_LQC2(31, 0, col);
    VU0_OP("vsub.w $vf31, $vf0, $vf0");
    VU0_OP("vmulx.xyzw $vf31, $vf31, $vf29x");
    VU0_OP("vmini.xyzw $vf31, $vf31, $vf30");
    VU0_OP("vftoi0.xyzw $vf31, $vf31");
    VU0_QMFC2_NI(t, 31);
    MMI_OP2Z("ppach", t, t);
    MMI_OP2Z("ppacb", res, t);
    return res;
}

void *func_002B7388(W10PackedResource *resource, int index)
{
    u32 entryAddress;
    s32 value;

    entryAddress = resource->entries;
    if (entryAddress > 0xFFFFF)
    {
        /* DEBT(ORDER): advance the cursor separately on the absolute and relative paths. */
        entryAddress += index * sizeof(W10PackedResourceEntry);
        /* DEBT(CAST): packed resources store target addresses as 32-bit words. */
        value = ((W10PackedResourceEntry *)entryAddress)->value;
        if (value == (s32)resource)
        {
            value = 0;
        }
        return (void *)value;
    }

    entryAddress += index * sizeof(W10PackedResourceEntry);
    /* DEBT(CAST): unresolved table and target words are relative to this resource. */
    entryAddress += (u32)resource;
    value = ((W10PackedResourceEntry *)entryAddress)->value;
    if (value == 0)
    {
        return 0;
    }
    return (void *)(value + (s32)resource);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B73D8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B7590);

void op_md_draw_map_test(int a, int b, int c)
{
    R7Req req;

    req.w20 = b;
    req.w4 = c;
    req.h8 = 0x88;
    req.w18 = 0x80808080;
    req.w0 = 0x41C;
    req.wC = 0;
    req.q10 = 0;
    req.w1C = 0;
    req.w44 = 0;
    req.w34 = 0;
    req.q38 = 0;
    req.w40 = 0;
    func_002BCB60(a, &req);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op1_md_draw);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op1_mdc_draw);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B7CE8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B7E18);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B7EA0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002B7FB0);
INCLUDE_RODATA("build/ee_asm/game/op/op_2B6B50/rodata", jtbl_00575D30);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002BAF68);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002BCB60);
INCLUDE_RODATA("build/ee_asm/game/op/op_2B6B50/rodata", jtbl_00575D50);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002C0068);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002C19A0);
INCLUDE_RODATA("build/ee_asm/game/op/op_2B6B50/rodata", jtbl_00575DE0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op_md_one8);
INCLUDE_RODATA("build/ee_asm/game/op/op_2B6B50/rodata", jtbl_00575E50);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", op_md_one8_fog);
INCLUDE_RODATA("build/ee_asm/game/op/op_2B6B50/rodata", jtbl_00575EA0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002C9B78);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002CA930);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002CBCC0);
INCLUDE_RODATA("build/ee_asm/game/op/op_2B6B50/rodata", jtbl_00575F20);

INCLUDE_ASM("build/ee_asm/game/op/op_2B6B50", func_002CD590);
