/* tu_033 0x11e2c8-0x11eda0: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void Sg_GsUV(int x, int y)
{
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->id.d = 3; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->q.v.x = x << 4;
    ((GsPt *)&D_00580928[i])->q.v.y = y << 4;
    ((GsPt *)&D_00580928[i])->q.v.z = 0;
    D_00580920 = i + 1;
}

void Sg_GsUV2(int x, int y)
{
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->id.d = 3; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->q.v.x = (x << 4) + 0xF;
    ((GsPt *)&D_00580928[i])->q.v.y = (y << 4) + 0xF;
    ((GsPt *)&D_00580928[i])->q.v.z = 0;
    D_00580920 = i + 1;
}

void Sg_GsTEXFLUSH(void)
{
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->id.d = 0x3F; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    D_00580920 = i + 1;
}

void func_0011E380(void)
{
    *(Quad *)&D_00580928[D_00580920] = 0; /* DEBT(CAST) */
}

Cmd16 *Sg_GsGet(void)
{
    return &D_00580928[D_00580920];
}

void func_0011E3C8(void)
{
    D_00580920++;
}

void func_0011E3E0(s32 a, s32 b, s32 c)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        p[0] = 2;
        p[1] = a;
        p[2] = b;
        p[3] = c;
        D_00580934 += 4;
    }
}

void func_0011E420(void)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        *(s16 *)(p + 2) = 1; /* DEBT(CAST): s16 stores through the byte cursor (a union/s16 member does not reload the cursor like the original); DEBT(ORDER): scheduler flips these two stores */
        *(s16 *)p = 1;
        D_00580934 += 4;
    }
}

void func_0011E458(void)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        *(s16 *)(p + 2) = 2; /* DEBT(CAST), DEBT(ORDER): see func_0011E420 */
        *(s16 *)p = 1;
        D_00580934 += 4;
    }
}

void func_0011E490(float *v)
{
    s32 *p = (s32 *)D_00580934;

    if (ffx_debugmode) {
        p[0] = 3;
        ((float *)p)[1] = v[0];
        ((float *)p)[2] = v[1];
        ((float *)p)[3] = v[2];
        D_00580934 += 0x10;
    }
}

void func_0011E4D8(s32 a, s32 b)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        *(s16 *)p = 4; /* DEBT(CAST): see func_0011E420 */
        *(s16 *)(p + 2) = a;
        *(s16 *)(p + 4) = b;
        D_00580934 += 8;
    }
}

void func_0011E510(s32 x, s32 y, s32 width, s32 height)
{
    s32 right;
    s32 bottom;

    func_0011E458();
    right = x + width;
    func_0011E4D8(x, y);
    bottom = y + height;
    func_0011E4D8(right, y);
    func_0011E4D8(right, bottom);
    func_0011E4D8(x, bottom);
    func_0011E4D8(x, y);
}

void func_0011E598(s32 left, s32 top, s32 right, s32 bottom)
{
    func_0011E458();
    func_0011E4D8(left, top);
    func_0011E4D8(right, top);
    func_0011E4D8(right, bottom);
    func_0011E4D8(left, bottom);
    func_0011E4D8(left, top);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E618);

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E6C0);

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E788);

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E830);

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E8D8);

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E980);

void func_0011EA68(s32 f)
{
    func_0011E3E0((f & 2) ? 0xFF : 0, (f & 4) ? 0xFF : 0, (f & 1) ? 0xFF : 0);
}

void func_0011EA98(void)
{
    if (ffx_debugmode) {
        D_00580930 = D_00580934 = func_0011D420(0x10000, 6, D_00569D50, 0x209);
        func_0011E618();
    }
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", Sg_DbDraw);

void func_0011ECC8(void) {
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", Sg_Test);
