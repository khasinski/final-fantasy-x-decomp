/* tu_330 0x2b4ff8-0x2b6b50: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: resource loader wrappers (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B4FF8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B50E0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_rot_m_z);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B52C0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5318);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5348);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B53D0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5458);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_rt_m_yxz);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5568);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B55F0);

void op_rt_m_6(int a, int b, int c, int d, int sel)
{
    switch (sel) {
    case 0:
        func_002B5348(a, b, c, d);
        break;
    case 1:
        func_002B53D0(a, b, c, d);
        break;
    case 2:
        func_002B5458(a, b, c, d);
        break;
    case 3:
        op_rt_m_yxz(a, b, c, d);
        break;
    case 4:
        func_002B5568(a, b, c, d);
        break;
    case 5:
        func_002B55F0(a, b, c, d);
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B56D8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5750);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_unit_m);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_unit_m_scale);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_unit_m_scale2);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_m_copy);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5858);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5880);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B58B0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B58F0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5978);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B59A0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B59B8);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_spline_xyz_table);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B5EC0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_spline_xyz);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_deg_get);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6278);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6358);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_deg_in_check);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_length_get);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6440);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B64B0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", op_point_get_line_circle);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B6768);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B68D0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B4FF8", func_002B69A8);
