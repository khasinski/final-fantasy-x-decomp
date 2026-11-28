#include "common.h"

extern void *D_01B009C0;
extern u8 D_01B00FA0[];
extern int D_01B01318;
extern int D_01B0131C;
extern int D_01B01320;
extern int D_01B01324;
extern void *D_01B009A8;
extern void *D_01B00978;

extern void *func_002B49A0(void *, int, int);
extern void func_002DD128(void *);
extern void func_002EF0D0(void *, int, int);
extern void func_002B7CE8(void *, void *, void *, int, int, void *, void *, float);

void func_01B01410(float f20)
{
    float mat0[4][4];
    float mat1[4][4];
    u8 param[0x70];
    void *s1;
    u8 alpha;

    s1 = func_002B49A0(D_01B009C0, 2, 5);
    func_002DD128(mat0);
    func_002DD128(mat1);
    mat0[0][0] = 0.0010000001f;
    mat0[1][1] = 0.0010000001f;
    mat0[2][2] = 0.0010000001f;
    func_002EF0D0(param, 0, 0x70);

    *(int *)(param + 0x00) = 0x1C;
    *(u8 *)(param + 0x18) = 0xC8;
    *(u8 *)(param + 0x19) = 0x1E;
    *(u8 *)(param + 0x1A) = 0x32;
    alpha = (u8)(u32)(f20 * 128.0f);
    *(u8 *)(param + 0x1B) = alpha;

    *(void **)(param + 0x28) = mat1;
    *(void **)(param + 0x24) = mat1;
    *(u8 *)(param + 0x4C) = 0x80;
    *(u8 *)(param + 0x08) = 0x44;
    *(u8 *)(param + 0x1F) = 0;
    *(u8 *)(param + 0x1E) = 0;
    *(u8 *)(param + 0x1D) = 0;
    *(u8 *)(param + 0x1C) = 0;
    *(u8 *)(param + 0x4D) = 0;
    *(u8 *)(param + 0x09) = 0;
    *(void **)(param + 0x04) = D_01B009A8;
    *(int *)(param + 0x14) = D_01B0131C;
    *(int *)(param + 0x10) = D_01B01318;
    D_01B01318 = D_01B01318 + D_01B01320 + D_01B01324;

    func_002B7CE8(D_01B00978, param, D_01B00FA0, 0, 0, s1, mat0, 0.0f);
}
