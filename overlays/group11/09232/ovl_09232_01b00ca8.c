#include "common.h"

extern void *D_01B007F4;
extern u8 D_01B00A00[];
extern int D_01B00BD8;
extern int D_01B00BDC;
extern int D_01B00BE0;
extern int D_01B00BE4;
extern void *D_01B007E8;
extern void *D_01B007B8;

extern void *func_002B49A0(void *, int, int);
extern void func_002DD128(void *);
extern void func_002EF0D0(void *, int, int);
extern void func_002B7CE8(void *, void *, void *, int, int, void *, void *, float);

void func_01B00CA8(float f20)
{
    float mat0[4][4];
    float mat1[4][4];
    u8 param[0x70];
    void *s1;
    u8 alpha;

    s1 = func_002B49A0(D_01B007F4, 2, 3);
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
    *(void **)(param + 0x04) = D_01B007E8;
    *(int *)(param + 0x14) = D_01B00BDC;
    *(int *)(param + 0x10) = D_01B00BD8;
    D_01B00BD8 = D_01B00BD8 + D_01B00BE0 + D_01B00BE4;

    func_002B7CE8(D_01B007B8, param, D_01B00A00, 0, 0, s1, mat0, 0.0f);
}
