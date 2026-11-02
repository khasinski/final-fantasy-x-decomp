/* tu_032 0x11d750-0x11e2c8: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/w6.h"
#include "ffx/v0.h"

void Sg_GsSetPacket(Cmd16 *buf)
{
    if (buf) {
        D_00580928 = buf;
    } else {
        D_00580928 = (Cmd16 *)Sg_PacketGetPtr(); /* DEBT(CAST): getter returns s32; the int-to-pointer form is what matches */
    }
    D_00580920 = 1;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsStart);

void func_0011D800(void)
{
    D_00580920 = 0x3;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsEnd2);

void func_0011D888(void)
{
    func_002DBF78(dmaGif, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsEnd);

void Sg_GsPRIM(s64 v)
{
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->q.raw = v; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = 0;
    D_00580920 = i + 1;
}

void func_0011D998(int r, int g, int b, int a)
{
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = SCE_GS_SET_RGBAQ(r, g, b, a, 0); /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_RGBAQ;
    D_00580920 = i + 1;
}

void func_0011D9E0(int r, int g, int b, int a, int q)
{
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = SCE_GS_SET_RGBAQ(r, g, b, a, q); /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_RGBAQ;
    D_00580920 = i + 1;
}

void Sg_GsZBUF(int zmsk)
{
    int zbp = Sg_VramGetAddrZ() / 2048;
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = SCE_GS_SET_ZBUF(zbp, SCE_GS_PSMZ24, zmsk); /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_ZBUF_1;
    D_00580920 = i + 1;
}

void func_0011DAA8(int zmsk)
{
    int zbp = Sg_VramGetAddrZ() / 2048;
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = SCE_GS_SET_ZBUF(zbp, SCE_GS_PSMZ24, zmsk); /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_ZBUF_2;
    D_00580920 = i + 1;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsFRAME);

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsFRAME2);

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsFRAME_16);

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsFRAME2_16);

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsSCISSOR2);

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsSCISSOR);

void Sg_GsXYOFFSET2(int x, int y)
{
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
        SCE_GS_SET_XYOFFSET(0x8000 - ((D_00307F40 / 2 + x) << 4), 0x8000 - ((D_00307F44 / 2 + y) << 4));
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_XYOFFSET_2;
    D_00580920 = i + 1;
}

void Sg_GsXYOFFSET(int x, int y)
{
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
        SCE_GS_SET_XYOFFSET(0x8000 - ((D_00307F40 / 2 + x) << 4), 0x8000 - ((D_00307F44 / 2 + y) << 4));
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_XYOFFSET_1;
    D_00580920 = i + 1;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", func_0011DEB0);

void func_0011DF08(s64 v)
{
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->q.raw = v; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = 0x45;
    D_00580920 = i + 1;
}

void func_0011DF38(void)
{
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->q.raw = -4; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = 0x44;
    D_00580920 = i + 1;
}

void func_0011DF70(int ate, int atst, int aref, int afail, int date, int datm, int zte, int ztst)
{
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
        SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst);
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_TEST_1;
    D_00580920 = i + 1;
}

void func_0011DFD8(int ate, int atst, int aref, int afail, int date, int datm, int zte, int ztst)
{
    s32 i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
        SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst);
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_TEST_2;
    D_00580920 = i + 1;
}

void func_0011E040(int a, int b, int c, int d, int fix)
{
    s32 i;

    *(u_long128 *)&D_00580928[D_00580920] = 0; /* DEBT(CAST): whole 16-byte record cleared at once */
    i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = SCE_GS_SET_ALPHA(a, b, c, d, fix); /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_ALPHA_1;
    D_00580920 = i + 1;
}

void Sg_GsTexHokan(int on)
{
    if (on) {
        D_00580928[D_00580920].a = 0x25;
    } else {
        D_00580928[D_00580920].a = 5;
    }
    D_00580928[D_00580920++].b = GS_REG_TEX1_1;
}

void Sg_GsXYZF2(int x, int y)
{
    s32 ox = (0x1000 - D_00307F40) / 2;
    s32 oy = (0x1000 - D_00307F44) / 2;
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->id.d = 4;
    ((GsPt *)&D_00580928[i])->q.v.x = (x + ox) << 4;
    ((GsPt *)&D_00580928[i])->q.v.y = (y + oy) << 4;
    ((GsPt *)&D_00580928[i])->q.v.z = 0;
    D_00580920 = i + 1;
}

void func_0011E180(int x, int y, int z)
{
    s32 ox = (0x1000 - D_00307F40) / 2;
    s32 oy = (0x1000 - D_00307F44) / 2;
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->q.v.x = (x + ox) << 4; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->q.v.y = (y + oy) << 4;
    ((GsPt *)&D_00580928[i])->q.v.z = z;
    ((GsPt *)&D_00580928[i])->id.d = 4;
    D_00580920 = i + 1;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11D750", Sg_GsXYZF2L);

void Sg_GsXYZF2V(int x, int y, int z)
{
    s32 ox = (0x1000 - D_00307F40) / 2;
    s32 oy = (0x1000 - D_00307F44) / 2;
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->q.v.x = (x + ox) << 4; /* DEBT(CAST): GsPt view as in Sg_GsXYZF2 */
    ((GsPt *)&D_00580928[i])->q.v.y = (y + oy) << 4;
    ((GsPt *)&D_00580928[i])->q.v.z = z;
    ((GsPt *)&D_00580928[i])->id.d = 4;
    D_00580920 = i + 1;
}
