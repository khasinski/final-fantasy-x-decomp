/* EE Battle-Effect Overlay: group 0x11, file 09438 (0x01B01F80..0x01B02384)
 * .text: 2 functions (1,028 bytes)
 */
#include "common.h"
#include "vu0.h"

extern u8 *D_01B09058;
extern u8 D_01B08F90[];
extern u8 D_01B0F660[];
extern u8 D_01B00440[];
extern int D_01B09070;
extern u8 D_01B01D98[];

void func_01B05068(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B047F0(void *a0, void *a1, void *a2);
void func_01B03AA8(int a0, int a1);
void func_01B034B0(int a0, int a1);
void func_01B039B8(int a0, void *a1);
float func_01B02620(int a0);
void func_01B02748(int a0, void *a1, int a2);
void func_01B05EA0(void *a0, void *a1, void *a2);
void func_01B037B0(int a0, int a1);
u8 *func_01B04D08(void *a0);
void func_01B04ED0(void *a0);
void func_01B08718(void *a0, int a1);
void func_01B02920(int a0, void *a1);
void func_01B049F8(void *a0, int a1, int a2);
float func_01B05BE0(float f0, float f1, float f2, float f3, float f4, float f5);
void func_01B02878(int a0, void *a1);

void func_01B01F80(void)
{
    u8 *w = D_01B09058;
    float ang;
    u8 *s0;
    u8 *v0;

    func_01B05068(D_01B08F90, w, 0, 0, 0, 0, 0.35f);
    {
        u8 *dst = w + 0xD0;
        u8 *src = w + 0xB40;
        MMI_COPY_LQ_A3(dst, src);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(w + 0xD4) = *(float *)(w + 0xB34) - 10.0f;
    *(float *)(w + 0xE8) = 8.0f;
    *(float *)(w + 0xC0) = 0.25132743f;
    ang = *(float *)(w + 0xCA0) + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(w + 0xC4) = ang;
    s0 = w + 0xC60;
    func_01B047F0(s0, D_01B0F660, D_01B00440);
    *(u8 **)(w + 0x110) = s0;
    func_01B03AA8(-5, 0);
    if (D_01B09070 == 1) {
        float rot[4];
        float ofs[4];
        u8 *t;

        func_01B034B0(0, 1);
        func_01B039B8(0, w + 0xAB0);
        *(float *)(w + 0xAF0) = 0.0f;
        *(float *)(w + 0xAF4) = func_01B02620(0);
        *(float *)(w + 0xAF8) = 0.0f;
        *(float *)(w + 0xAFC) = 0.0f;
        func_01B02748(0, w + 0xB00, 0);
        *(float *)(w + 0xB10) = 0.0f;
        *(float *)(w + 0xB14) = -4.0f;
        *(float *)(w + 0xB18) = 0.0f;
        *(float *)(w + 0xB1C) = 0.0f;
        rot[0] = 0.0f;
        rot[1] = *(float *)(w + 0xCA0);
        rot[2] = 0.0f;
        rot[3] = 0.0f;
        ofs[0] = 0.0f;
        ofs[1] = 0.0f;
        ofs[2] = -10.0f;
        ofs[3] = 1.0f;
        func_01B05EA0(rot, w + 0xB10, ofs);
        *(float *)(w + 0xB20) = *(float *)(w + 0xB10) * 0.015f;
        *(float *)(w + 0xB24) = 0.1f;
        *(float *)(w + 0xB28) = *(float *)(w + 0xB18) * 0.015f;
        *(float *)(w + 0xB2C) = 0.0f;
        *(int *)(w + 0xCAC) = 0x41;
        func_01B037B0(0, 0);
        t = func_01B04D08(D_01B01D98);
        t[0x18] = 1;
        func_01B04ED0(t);
    }
    v0 = w + 0xB60;
    v0[0x98] = 0x48;
    v0[0x83] = 0x80;
    v0[0x82] = 0x80;
    v0[0x81] = 0x80;
    v0[0x80] = 0x80;
    v0[0x84] = 0x80;
    v0[0x85] = 0x80;
    v0[0x86] = 0x80;
    v0[0x87] = 0;
    *(int *)(v0 + 0x88) = 0;
    v0[0x99] = 0;
    func_01B08718(v0, 0x14);
    func_01B02920(-1, w + 0xB50);
    {
        int flag = D_01B09070;
        *(int *)(w + 0xCA4) = 0xE;
        if (flag != 0) {
            func_01B049F8(D_01B0F660, 1, 1);
        } else {
            func_01B049F8(D_01B0F660, 1, 2);
        }
    }
}

void func_01B02258(u8 *a0)
{
    float pos[4];
    u8 *w = D_01B09058;
    float *p1;
    float *p0;
    float t;
    int i;

    if (*(int *)(w + 0xCA4) > 0) {
        (*(int *)(w + 0xCA4))--;
    }
    t = (float)*(int *)(w + 0xCA4) / 14.0f;
    p1 = (float *)(w + 0xB50);
    p0 = (float *)(w + 0xB40);
    for (i = 0; i < 3; i++) {
        float d = p1[i] - p0[i];
        pos[i] = p0[i] + func_01B05BE0(d, d * 1.05f, d * 0.5f, d * 0.1f, 0.0f, t);
    }
    func_01B02878(-1, pos);
    if (*(int *)(w + 0xCA4) <= 0) {
        a0[0x56] = 1;
    }
}
