/* tu_351 0x2dce38-0x2ddb48: low; ~FFXVu0InnerProduct (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCE38);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCE80);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCEA0);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCEC8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCF00);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCF48);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCFB8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCFD8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DCFF8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD020);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD038);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD050);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD068);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD080);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD0B0);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD0C0);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD0E8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD0F8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD108);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD118);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD128);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD150);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD1C8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD270);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD318);

void func_002DD3C0(void *m, int unused, float *v)
{
    func_002DD1C8(m, v[2]);
    func_002DD318(m, m, v[1]);
    func_002DD270(m, m, v[0]);
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD410);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD438);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD4E8);

void func_002DD5A8(Vec4 *m, void *r0, void *r1, void *r2, void *r3)
{
    func_002DD0B0(&m[0], r0);
    func_002DD0B0(&m[1], r1);
    func_002DD0B0(&m[2], r2);
    func_002DD0B0(&m[3], r3);
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD610);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD718);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD8A8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD900);

void func_002DD948(void *dst, float *src)
{
    float *d = dst;

    d[0] = src[0];
    d[1] = src[1];
    d[2] = src[2];
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD968);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD998);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD9B0);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DD9F8);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DDA58);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DCE38", func_002DDAE8);
