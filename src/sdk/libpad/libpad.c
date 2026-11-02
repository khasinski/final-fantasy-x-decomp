/* tu_352 0x2ddb48-0x2deef0: low; libpad (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DDB48);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DDC78);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DDDB8);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DDE58);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DDED8);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE0C0);

SndHalf *func_002DE178(int a, int b)
{
    SndVoice *v = D_0078BC90[a][b].v;
    int i;

    func_002F8C30(v, v + 1);
    i = v->h[0].w58 < v->h[1].w58;
    return &v->h[i];
}

int func_002DE1D8(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DE178(a, b)->w58;
}

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE228);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE2A8);

void func_002DE320(unsigned int i, char *dst)
{
    if (i < 8) {
        func_002F072C(dst, D_00566348[i]);
    } else {
        *dst = D_00576B28;
    }
}

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE358);

int func_002DE3C0(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DE178(a, b)->b71;
}

void func_002DE410(unsigned int i, char *dst)
{
    if (i < 4) {
        func_002F072C(dst, D_00566368[i]);
    } else {
        *dst = D_00576B28;
    }
}

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE448);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE568);

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE688);

int func_002DE7C0(int a, int b, int c, int d)
{
    D_0078BF80[3] = c;
    D_0078BF80[4] = d;
    D_0078BF80[0] = 6;
    D_0078BF80[1] = a;
    D_0078BF80[2] = b;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (D_0078BF80[5] == 1) {
        func_002DE358(a, b, 2);
    }
    return D_0078BF80[5];
}

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DE878);

int func_002DE930(int a, int b, u8 *src)
{
    int *buf = D_0078BF80;
    u8 *dst;
    int i;

    buf[0] = 8;
    buf[1] = a;
    buf[2] = b;
    dst = (u8 *)&buf[3]; /* DEBT(CAST): request words 3.. hold a 6-byte block */
    for (i = 0; i < 6; i++) {
        dst[i] = src[i];
    }
    if (func_002FB4C8(D_0078BC40, 1, 0, buf, 0x80, buf, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (buf[5] == 1) {
        func_002DE358(a, b, 2);
    }
    return buf[5];
}

INCLUDE_ASM("build/ee_asm/sdk/libpad/libpad", func_002DEA08);

int func_002DEAC0(int a, int b, int c)
{
    D_0078BF80[3] = c;
    D_0078BF80[0] = 0xA;
    D_0078BF80[1] = a;
    D_0078BF80[2] = b;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (D_0078BF80[4] == 1) {
        func_002DE358(a, b, 2);
    }
    return D_0078BF80[4];
}

int func_002DEB70(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DEA08(a, b) == 0x3FFFF;
}

int func_002DEBD0(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DEAC0(a, b, 0xFFF);
}

int func_002DEC28(int a, int b)
{
    if (D_0078BC90[a][b].w10 == 0) {
        return 0;
    }
    return func_002DEAC0(a, b, 0);
}

int func_002DEC80(int a, int b, U5Blk12 *src)
{
    D_0078BF80[1] = a;
    D_0078BF80[0] = 0xB;
    D_0078BF80[2] = b;
    *(U5Blk12 *)&D_0078BF80[3] = *src; /* DEBT(CAST): request words 3..5 hold a 12-byte block */
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (D_0078BF80[7] == 1) {
        func_002DE358(a, b, 2);
    }
    return D_0078BF80[7];
}

int func_002DED50(void)
{
    D_0078BF80[0] = 0xC;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[3];
}

int func_002DEDB8(int a)
{
    D_0078BF80[1] = a;
    D_0078BF80[0] = 0xD;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[3];
}

int func_002DEE20(void)
{
    D_0078BF80[0] = 0x12;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[3];
}

int func_002DEE88(int a)
{
    D_0078BF80[1] = a;
    D_0078BF80[0] = 0x14;
    if (func_002FB4C8(D_0078BC40, 1, 0, D_0078BF80, 0x80, D_0078BF80, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0078BF80[2];
}
