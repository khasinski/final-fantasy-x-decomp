/* tu_032 0x11d750-0x11e2c8: low; ~Sg (config/tu_map.tsv) */
#define Sg_GsXYZF2L _hdr_Sg_GsXYZF2L
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/w6.h"
#include "ffx/v0.h"
#undef Sg_GsXYZF2L

#define GS_REG_XYOFFSET_2 0x19
#define GS_REG_SCISSOR_2  0x41
#define GS_REG_FRAME_2    0x4D

typedef struct {
    u64 nloop : 15;
    u64 pad : 49;
} GifTag15;

typedef union {
    u_long128 q;
    u32 w[4];
    u64 d[2];
} GsDmaPkt;

void Sg_GsSetPacket(Cmd16 *buf)
{
    if (buf) {
        D_00580928 = buf;
    } else {
        D_00580928 = (Cmd16 *)Sg_PacketGetPtr(); /* DEBT(CAST): getter returns s32; the int-to-pointer form is what matches */
    }
    D_00580920 = 1;
}

void Sg_GsStart(void)
{
    s32 i;

    *(u_long128 *)&D_00580928[D_00580920] = 0;
    i = D_00580920;
    D_0058092C = &D_00580928[i];
    D_00580924 = i;
    ((GsPt *)&D_00580928[i])->q.raw = 0x10000000000004D2L;
    ((GsPt *)&D_00580928[i])->id.d = 0xE;
    D_00580920 = i + 1;
}

void func_0011D800(void)
{
    D_00580920 = 0x3;
}

Cmd16 *Sg_GsEnd2(void)
{
    ((GsDmaPkt *)&D_00580928[0])->q = 0;
    ((GsDmaPkt *)&D_00580928[0])->w[0] = (D_00580920 - 1) | 0x10000000;
    ((GsDmaPkt *)&D_00580928[1])->d[0] = 0;
    ((GsDmaPkt *)&D_00580928[1])->w[2] = 0x10000000;
    ((GsDmaPkt *)&D_00580928[1])->w[3] = (D_00580920 - 2) | 0x50000000;
    ((GsDmaPkt *)&D_00580928[2])->d[0] = ((u64)(u32)((D_00580920 - 3) | 0x8000)) | (1UL << 60);
    ((GsDmaPkt *)&D_00580928[2])->d[1] = 0xE;
    return &D_00580928[D_00580920];
}

void func_0011D888(void)
{
    func_002DBF78(dmaGif, 0, 0);
}

void Sg_GsEnd(void)
{
    s32 i;

    ((GifTag15 *)D_0058092C)->nloop = (D_00580920 - D_00580924) - 1;
    i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = 0x1000000000008001L;
    ((GsPt *)&D_00580928[i])->id.d = 0xF;
    D_00580920 = i + 1;
    ((GsDmaPkt *)D_00580928)->q = 0;
    ((GsDmaPkt *)D_00580928)->w[0] = D_00580920 | 0x70000000;
    func_002F8660(0);
    func_002DBF78(dmaGif, 0, 0);
    func_002DBA28(dmaGif, D_00580928);
}

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

void Sg_GsSCISSOR2(int x0, int x1, int y0, int y1)
{
    s32 i;

    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 > D_00307F40 - 1) {
        x1 = D_00307F40 - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (y1 > D_00307F44 - 1) {
        y1 = D_00307F44 - 1;
    }
    i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = SCE_GS_SET_SCISSOR(x0, x1, y0, y1);
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_SCISSOR_2;
    D_00580920 = i + 1;
}

void Sg_GsSCISSOR(int x0, int x1, int y0, int y1)
{
    s32 i;

    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 > D_00307F40 - 1) {
        x1 = D_00307F40 - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (y1 > D_00307F44 - 1) {
        y1 = D_00307F44 - 1;
    }
    i = D_00580920;
    ((GsPt *)&D_00580928[i])->q.raw = SCE_GS_SET_SCISSOR(x0, x1, y0, y1);
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_SCISSOR_1;
    D_00580920 = i + 1;
}

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

void func_0011DEB0(int x, int y, int w)
{
    s32 i = D_00580920;

    ((GsPt *)&D_00580928[i])->q.raw =
        SCE_GS_SET_XYOFFSET(0x8000 - ((x + 0x100) << 4), 0x8000 - ((y + 0xD0) << 4) + w);
    ((GsPt *)&D_00580928[i])->id.d = GS_REG_XYOFFSET_2;
    D_00580920 = i + 1;
}

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

extern s32 _m2c_Sg_GsXYZF2L_D_00580920 __asm__("D_00580920");
extern s32 _m2c_Sg_GsXYZF2L_D_00580928 __asm__("D_00580928");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void Sg_GsXYZF2L(s16 arg0, s16 arg1, s32 arg2) {
    s64 var_2;
    register void * temp_3 __asm__("$3");

    temp_3 = (_m2c_Sg_GsXYZF2L_D_00580920 * 0x10) + _m2c_Sg_GsXYZF2L_D_00580928;
    (*(s16 *)((u8 *)(temp_3) + (0))) = arg0;
    (*(s16 *)((u8 *)(temp_3) + (2))) = arg1;
    (*(s32 *)((u8 *)(temp_3) + (4))) = 0;
    if (arg2 < 0) {
        var_2 = 0xC;
    } else {
    __asm__ volatile("" : : : "$2");
        var_2 = 4;
    }
    (*(s64 *)((u8 *)(temp_3) + (8))) = var_2;
    _m2c_Sg_GsXYZF2L_D_00580920 += 1;
}

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
