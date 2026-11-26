#include "common.h"

typedef struct {
    unsigned long q[2];
    unsigned long gif0;
    unsigned long gif1;
    unsigned long w20;
    unsigned long w28;
    unsigned long w30;
    unsigned long w38;
    unsigned long w40;
    unsigned long w48;
    unsigned long w50;
    unsigned long w58;
    unsigned long w60;
    unsigned long w68;
    u32 rgba[4];
    float stq0[4];
    u32 xyz0[4];
    float stq1[4];
    u32 xyz1[4];
    float stq2[4];
    u32 xyz2[4];
    float stq3[4];
    u32 xyz3[4];
} Pkt1930;

extern Pkt1930 D_01B01930;
extern u8 *func_0011A538(s32 *);
extern void func_002B2A80(void *, s32, s32, s32);
extern void func_01B004F8(void);

void ovl_09229_0568(u32 alpha)
{
    s32 idx;
    u8 *p = func_0011A538(&idx);
    u8 *buf;
    unsigned long tex;

    D_01B01930.gif0 = 0xE02A400000008001ULL;
    D_01B01930.gif1 = 0x005252525216EEEEULL;
    D_01B01930.w20 = 0x0000008000000080ULL;
    D_01B01930.w28 = 0x3B;
    D_01B01930.w30 = 0x44;
    D_01B01930.w38 = 0x42;

    buf = ((idx & 1) == 0) ? (p + 0x1D0) : (p + 0x60);
    D_01B01930.w40 = *(unsigned long *)(buf + 0x20);
    D_01B01930.w48 = 0x18;
    D_01B01930.w50 = 0x067C007FC00AULL;
    D_01B01930.w58 = 8;

    tex = *(unsigned long *)buf;
    D_01B01930.w60 = (unsigned long)(((s32)(tex & 0x1FF) << 5) | 0x24020000) | 0x0000000240000000ULL;
    D_01B01930.w68 = 0;

    D_01B01930.rgba[2] = 0x80;
    D_01B01930.rgba[1] = 0x80;
    D_01B01930.rgba[0] = 0x80;
    D_01B01930.rgba[3] = alpha;

    D_01B01930.stq0[0] = 0.0f;
    D_01B01930.stq0[1] = 0.0f;
    D_01B01930.stq0[2] = 1.0f;
    D_01B01930.stq0[3] = 0.0f;

    D_01B01930.xyz0[0] = 0x7000;
    D_01B01930.xyz0[1] = 0x7300;
    D_01B01930.xyz0[2] = 0x00FFFFFF;
    D_01B01930.xyz0[3] = 0;

    D_01B01930.stq1[0] = 1.0f;
    D_01B01930.stq1[1] = 0.0f;
    D_01B01930.stq1[2] = 1.0f;
    D_01B01930.stq1[3] = 0.0f;

    D_01B01930.xyz1[0] = 0x8FF0;
    D_01B01930.xyz1[1] = 0x7300;
    D_01B01930.xyz1[2] = 0x00FFFFFF;
    D_01B01930.xyz1[3] = 0;

    D_01B01930.stq2[0] = 0.0f;
    D_01B01930.stq2[1] = 0.8125f;
    D_01B01930.stq2[2] = 1.0f;
    D_01B01930.stq2[3] = 0.0f;

    D_01B01930.xyz2[0] = 0x7000;
    D_01B01930.xyz2[1] = 0x8CF0;
    D_01B01930.xyz2[2] = 0x00FFFFFF;
    D_01B01930.xyz2[3] = 0;

    D_01B01930.stq3[0] = 1.0f;
    D_01B01930.stq3[1] = 0.8125f;
    D_01B01930.stq3[2] = 1.0f;
    D_01B01930.stq3[3] = 0.0f;

    D_01B01930.xyz3[0] = 0x8FF0;
    D_01B01930.xyz3[1] = 0x8CF0;
    D_01B01930.xyz3[2] = 0x00FFFFFF;
    D_01B01930.xyz3[3] = 0;

    func_002B2A80(&D_01B01930, 16, 1, 0);
    func_01B004F8();
}
