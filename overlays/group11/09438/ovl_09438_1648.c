/* EE Battle-Effect Overlay: group 0x11, file 09438 (0x01B01648..0x01B01D98)
 * .text: 9 functions (1,872 bytes)
 */
#include "common.h"
#include "vu0.h"

extern void *D_01B00764;
extern u8 *D_01B09058;
extern void *D_01B09060;
extern u8 *D_01B08FD4;
extern int D_01B08F88;
extern int D_01B0904C;
extern u8 D_01B08F90[];
extern u8 D_01B08FD8[];
extern u8 D_01B09038[];
extern u8 D_01B0F660[];
extern u8 D_01B00428[];

void func_01B063F0(void);
int func_01B08618(void *a0);
int func_0011ABB8(void);
int func_01B041E8(void *a0);
void func_01B04D88(void *a0);
int func_01B05148(void *a0, void *a1);
void func_001CDDD8(int a0);
void func_01B02748(int a0, void *a1, int a2);
float func_01B02620(int a0);
float func_01B02AB8(int a0);
void func_01B05EA0(void *a0, void *a1, void *a2);
void func_01B00A38(void);
void func_0011ABA8(int a0);
int func_01B02590(int a0);
int func_00297C28(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_00297CE8(int a0);
void func_01B02878(int a0, void *a1);
float func_01B05F80(void *a0, void *a1);
void func_01B08E20(void *a0, void *a1, void *a2, int a3);
void **func_01B055F8(void *a0, int a1);
u8 *func_01B08920(void);
void func_01B06430(void *a0, void *a1);
float func_002B3DB0(float f0);
float func_002B3DF8(float f0);
void *func_002B49A0(void *a0, int a1, int a2);
float func_01B05BE0(float f0, float f1, float f2, float f3, float f4, float f5);

void func_01B01828(void);

void func_01B01648(void *a0)
{
    u8 *w = D_01B09058;
    int r;

    func_01B063F0();
    D_01B00764 = D_01B09060;
    r = func_01B08618(D_01B08FD8);
    if (func_0011ABB8() == 0) {
        int r2 = func_01B041E8(D_01B09038);
        if (r != 0 && r2 != 0) {
            *(int *)(w + 0xCB0) = 1;
            func_01B01828();
            func_01B04D88(a0);
        }
    }
}

void func_01B016F0(void)
{
    u8 *w = D_01B09058;
    int r;

    if (func_0011ABB8() == 0) {
        r = func_01B05148(D_01B08F90, D_01B08FD4);
    } else {
        r = 0;
    }
    if (r == 1 && *(int *)(w + 0xCB0) == 1) {
        func_001CDDD8(D_01B08F88);
    }
}

void func_01B01760(void)
{
    float rot[4];
    float ofs[4];
    u8 *w = D_01B09058;
    u8 *p;

    func_01B02748(-1, w + 0xB30, 0);
    p = w + 0xB40;
    *(float *)(w + 0xCA0) = func_01B02620(-1);
    func_01B02748(0, p, 0);
    rot[0] = 0.0f;
    rot[1] = *(float *)(w + 0xCA0);
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    ofs[0] = 0.0f;
    ofs[1] = 0.0f;
    ofs[2] = func_01B02AB8(0) + 10.0f;
    ofs[3] = 1.0f;
    func_01B05EA0(rot, p, ofs);
    *(int *)(w + 0xCB0) = 0;
    *(int *)(w + 0xCA8) = -1;
    D_01B0904C = 1;
    func_01B00A38();
}

void func_01B01828(void)
{
    func_0011ABA8(0);
}

void func_01B01830(void)
{
    u8 *w = D_01B09058;

    *(int *)(w + 0xCA8) = func_00297C28(func_01B02590(-1), 0, 0, 0, 0, 0, 0);
}

void func_01B01880(void)
{
    u8 *w = D_01B09058;

    func_00297CE8(*(int *)(w + 0xCA8));
    *(int *)(w + 0xCA8) = -1;
}

void func_01B018B8(u8 *a0)
{
    float pos[4];
    float rot[4];
    float ofs[4];
    u8 *w = D_01B09058;

    func_01B02748(-1, pos, 0);
    rot[0] = 0.0f;
    rot[1] = *(float *)(w + 0xCA0);
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    ofs[0] = 0.0f;
    ofs[1] = 0.0f;
    ofs[2] = -3.0f;
    ofs[3] = 1.0f;
    func_01B05EA0(rot, pos, ofs);
    func_01B02878(-1, pos);
    if (func_01B05F80(pos, w + 0xB40) < 30.0f) {
        u8 *dst = w + 0xB50;
        u8 *s0;
        MMI_COPY_LQ_A3(dst, pos);
        MMI_COPY_SQ_A3(dst);
        *(int *)(w + 0xCA4) = 0x15;
        s0 = w + 0xC00;
        func_01B08E20(s0, D_01B0F660, D_01B00428, 1);
        *(int *)(s0 + 0x54) = -1;
        a0[0x56] = 1;
    }
}

void func_01B019B8(void)
{
    float pos[4];
    void *s1;
    u8 *s0;
    int i;

    func_01B02748(-1, pos, 3);
    pos[1] -= 2.0f;
    s1 = *func_01B055F8(D_01B08F90, 4);
    for (i = 0; i < 2; i++) {
        s0 = func_01B08920();
        if (s0 == 0) {
            return;
        }
        func_01B06430(s0 + 0x30, s1);
        *(float *)(s0 + 0x00) = pos[0] + func_002B3DB0(5.0f);
        *(float *)(s0 + 0x04) = pos[1];
        *(float *)(s0 + 0x08) = pos[2] + func_002B3DB0(5.0f);
        *(float *)(s0 + 0x0C) = 1.0f;
        *(float *)(s0 + 0x10) = func_002B3DB0(0.25f);
        *(float *)(s0 + 0x14) = -func_002B3DF8(0.25f);
        *(float *)(s0 + 0x18) = func_002B3DB0(0.25f);
        *(float *)(s0 + 0x1C) = func_002B3DB0(3.1415927f);
        *(float *)(s0 + 0x20) = 0.0f;
        *(float *)(s0 + 0x24) = 0.01f;
        *(float *)(s0 + 0x28) = 0.0f;
        *(float *)(s0 + 0x2C) = 1.0f;
        *(float *)(s0 + 0x3C) = (func_002B3DB0(0.2f) + 1.0f) * 0.4f;
        *(int *)(s0 + 0x4C) = 0x20;
        *(int *)(s0 + 0x50) = 0x10;
        *(int *)(s0 + 0x54) = -0x10;
        s0[0x6B] = 0;
    }
    s1 = func_002B49A0(D_01B0F660, 9, 0);
    s0 = func_01B08920();
    if (s0 != 0) {
        func_01B06430(s0 + 0x30, s1);
        *(float *)(s0 + 0x00) = pos[0] + func_002B3DB0(5.0f);
        *(float *)(s0 + 0x04) = pos[1];
        *(float *)(s0 + 0x08) = pos[2] + func_002B3DB0(5.0f);
        *(float *)(s0 + 0x0C) = 1.0f;
        *(float *)(s0 + 0x10) = func_002B3DB0(1.0f);
        *(float *)(s0 + 0x14) = -(func_002B3DF8(0.5f) + 1.0f);
        *(float *)(s0 + 0x18) = func_002B3DB0(1.0f);
        *(float *)(s0 + 0x1C) = func_002B3DB0(3.1415927f);
        *(float *)(s0 + 0x20) = 0.0f;
        *(float *)(s0 + 0x24) = 0.1f;
        *(float *)(s0 + 0x28) = 0.0f;
        *(float *)(s0 + 0x2C) = 1.0f;
        *(float *)(s0 + 0x3C) = (func_002B3DF8(0.2f) + 1.0f) * 0.012f;
        *(int *)(s0 + 0x4C) = 0x14;
        *(int *)(s0 + 0x50) = 0x14;
        s0[0x6B] = 0;
    }
}

void func_01B01C60(u8 *a0)
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
    t = (float)*(int *)(w + 0xCA4) / 21.0f;
    p1 = (float *)(w + 0xB40);
    p0 = (float *)(w + 0xB50);
    for (i = 0; i < 3; i++) {
        float d = p1[i] - p0[i];
        pos[i] = p0[i] + func_01B05BE0(d, d, d * 1.2f, d * 0.5f, 0.0f, t);
    }
    func_01B02878(-1, pos);
    if (*(int *)(w + 0xCA4) < 0xF) {
        func_01B019B8();
    }
    if (*(int *)(w + 0xCA4) <= 0) {
        a0[0x56] = 1;
    }
}
