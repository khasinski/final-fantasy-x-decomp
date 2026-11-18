/* tu_231 0x209460-0x20cc98: low; ~TOSetExeWindowArea (config/tu_map.tsv) */
#define TODrawMessageWindowForMenu _hdr_TODrawMessageWindowForMenu
#define TODrawMessageWindow _hdr_TODrawMessageWindow
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/s4.h"
#undef TODrawMessageWindow
#undef TODrawMessageWindowForMenu

int TOGetSaveChrName(int i)
{
    if (i >= 20) {
        return (int)func_001BB190(i); /* DEBT(CAST) */
    }
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        func_0014D718((u8 *)MsGetSaveChrName(i), D_0068F1A0[i]);
        return (int)D_0068F1A0[i]; /* DEBT(CAST): returns the record address */
    }
    return (int)MsGetSaveChrName(i); /* DEBT(CAST) */
}

void TOInitPadData(void)
{
    func_002EF0D0(&D_003238D0, 0, 0x40);
    D_003238D0.b1E = 0x80;
    D_003238D0.b1F = 0x80;
    D_003238D0.b20 = 0x80;
    D_003238D0.b21 = 0x80;
}

/* DEBT(TYPE): buffer addresses are stored in the s32 members of R4Rec16 */
INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", TOFTCTransfer);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_209460/rodata", jtbl_00570960);

void TOTransImageHL(u32 addr, int dbp, int psm, int x, int y, int w, int h)
{
    Qword tag[2];
    u32 *ch = func_002DB6D8(2);
    int size;
    int qwc;
    int bw;

    tag[0].ul128 = 0;
    tag[0].ui32[0] = 0x30000006;
    tag[0].ui32[1] = (u32)D_0068F0D0;
    switch (psm) {
    case 0:
        size = w * (h << 2);
        break;
    case 1:
        size = w * ((h << 1) + h); /* DEBT(ORDER): h scaled first (as shifts) so it is not folded into w * h */
        break;
    case 2:
    case 10:
        size = w * (h << 1);
        break;
    case 19:
    case 27:
        size = w * h;
        break;
    case 20:
    case 36:
    case 44:
        size = w / 2 * h;
        break;
    }
    bw = w / 64;
    qwc = size / 16;
    if (bw == 0) {
        bw = 1;
    }
    tag[1].ul128 = 0;
    tag[1].ui32[1] = addr;
    D_0068F0D0[0] = 0x1000000000000004;
    D_0068F0D0[1] = 0xE;
    D_0068F0D0[2] = ((u64)dbp << 32) | ((u64)bw << 48) | ((u64)psm << 56);
    D_0068F0D0[3] = 0x50;
    D_0068F0D0[4] = ((u64)x << 32) | ((u64)y << 48);
    D_0068F0D0[5] = 0x51;
    D_0068F0D0[6] = w | ((u64)h << 32);
    D_0068F0D0[7] = 0x52;
    D_0068F0D0[8] = 0;
    D_0068F0D0[9] = 0x53;
    D_0068F0D0[10] = qwc | 0x8000 | ((u64)0x8000 << 44);
    D_0068F0D0[11] = 0x54;
    tag[1].ui32[0] = qwc;
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DBA28(ch, (int)tag); /* DEBT(CAST): chain address passed as int */
    func_002DA610(0, 0);
}

void func_0020C660(int dst, int a, int b, int c, int d, int e, int f)
{
    u8 ctx[0x70];

    func_002DAB10_s(ctx, a, e / 64, b, c, d, e, f);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DADD0(ctx, dst);
    func_002DA610(0, 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_209460", func_0020C700);

void TOTransTexture(void)
{
    R4Rec16 *temp_2;

    temp_2 = &D_0066B530[TOGetInternationalBaseDicType()];
    TOTransImageHL((u32) temp_2->w0, 0x3C00, 0x14, 0, 0, (s32) temp_2->hC, (s32) temp_2->hE);
    if (MsBattleGetStatus() != 0)
    {
        if (func_001AF320() != 0)
        {
            TOTransImageHL((u32) D_0066B530[2].w0, 0x3D00, 0x14, 0, 0, (s32) D_0066B530[2].hC, (s32) D_0066B530[2].hE);
        }
        if (func_0020B850() == 0)
        {
            TOTransImageHL((u32) D_0066B530[4].w0, 0x3D40, 0x14, 0, 0, (s32) D_0066B530[4].hC, (s32) D_0066B530[4].hE);
        }
    }
    else if (func_0014D7C0() != 0)
    {
        TOTransImageHL((u32) D_0066B530[1].w0, 0x3D00, 0x14, 0, 0, (s32) D_0066B530[1].hC, (s32) D_0066B530[1].hE);
    }
    TOTransImageHL(D_0066B584, 0x3D80, 0x14, 0, 0, 0x80, 0x100);
    TOTransImageHL((u32) D_0066B588, 0x3DC0, 0x14, 0, 0, 0x100, 0x80);
    TOTransImageHL((u32) D_0066B590, 0x3E00, 0x13, 0, 0, 0x100, 0x100);
    TOTransImageHL(func_0020B8C0(), 0x3F00, 0x13, 0, 0, 0x100, 0x100);
    TOTransImageHL((u32) D_0066B598, 0x2EA0, 0, 0, 0, 0x40, 0x40);
}

void func_0020CA38(void)
{
    int type = TOGetInternationalBaseDicType();

    if (func_0020B850() == 0) {
        TOTransImageHL((u32)D_0066B530[0].w0, 0x3C00, 0x14, 0, 0, D_0066B530[0].hC, D_0066B530[0].hE);
        TOTransImageHL((u32)D_0066B530[4].w0, 0x3D40, 0x14, 0, 0, D_0066B530[4].hC, D_0066B530[4].hE);
    } else {
        TOTransImageHL((u32)D_0066B530[type].w0, 0x3C00, 0x14, 0, 0, D_0066B530[type].hC, D_0066B530[type].hE);
    }
    if (func_0016C318() != 0) {
        TOTransImageHL((u32)D_0066B530[3].w0, 0x3D00, 0x14, 0, 0, D_0066B530[3].hC, D_0066B530[3].hE);
    }
    TOTransImageHL(D_0066B584, 0x3D80, 0x14, 0, 0, 0x80, 0x100);
    TOTransImageHL((u32)D_0066B588, 0x3DC0, 0x14, 0, 0, 0x100, 0x80);
    TOTransImageHL(D_0066B58C, 0x3F00, 0x14, 0, 0, 0x200, 0x80);
    if (func_0020BED0() == 0) {
        TOTransImageHL((u32)D_0066B590, 0x3E00, 0x13, 0, 0, 0x100, 0x100);
        TOTransImageHL((u32)D_0066B598, 0x2EA0, 0, 0, 0, 0x40, 0x40);
    }
}

void func_0020CBE8(void)
{
    TOTransImageHL(func_0020B8C0(), 0x3F00, 0x13, 0, 0, 0x100, 0x100);
}

void func_0020CC20(const char *name, int id, void *buf)
{
    SysVt *vt = GetCD();

    vt->f10(name);
    vt->f0(id, buf, 0, 0);
    vt->f8(0);
}
