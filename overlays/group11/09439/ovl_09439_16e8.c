/* EE Battle-Effect Overlay: group 0x11, file 09439 (0x01B016E8..0x01B01D5C)
 * .text: 9 functions (1,644 bytes)
 */
#include "common.h"
#include "vu0.h"

extern u8 *D_01B0811C;
extern u8 *D_01B081A0;
extern int D_01B080D0;
extern int D_01B08194;
extern int D_01B081B4;
extern u8 D_01B080D8[];
extern u8 D_01B08120[];
extern u8 D_01B08180[];
extern u8 D_01B0DF70[];
extern u8 D_01B00540[];
extern u8 D_01B00558[];
extern u8 D_01B00570[];
extern u8 D_01B00600[];
extern u8 D_01B00610[];
extern int D_01B00658[];
extern u8 D_01B05000[];

int func_01B07940(void *a0);
int func_0011ABB8(void);
int func_01B03BC0(void *a0);
void func_01B04760(void *a0);
int func_01B04B20(void *a0, void *a1);
void func_001CDDD8(int a0);
void func_01B02120(int a0, void *a1, int a2);
float func_01B01FF8(int a0);
void func_01B00B08(void);
void func_0011ABA8(int a0);
int func_01B01F68(int a0);
int func_00297C28(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_01B04A40(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B041C8(void *a0, void *a1, void *a2);
void func_01B07A40(void *a0, int a1);
void func_01B03B08(int a0, void *a1, void *a2);
void func_01B07E90(void *a0, int a1, int a2, float f0, float f1);
void func_01B043D0(void *a0, int a1, int a2);
void func_01B03510(u8 *buf);
int func_01B02A60(int a0);
int func_01B01ED0(int a0);
void func_01B07BB0(void *a0, int a1);
int func_002EFD78(void);
void func_00297CE8(int a0);

void func_01B01848(void);

void func_01B016E8(void *a0)
{
    u8 *w = D_01B081A0;
    int r = func_01B07940(D_01B08120);

    if (func_0011ABB8() == 0) {
        int r2 = func_01B03BC0(D_01B08180);
        if (r != 0 && r2 != 0) {
            *(int *)(w + 0x15AC) = 1;
            func_01B01848();
            func_01B04760(a0);
        }
    }
}

void func_01B01780(void)
{
    u8 *w = D_01B081A0;
    int r;

    if (func_0011ABB8() == 0) {
        r = func_01B04B20(D_01B080D8, D_01B0811C);
    } else {
        r = 0;
    }
    if (r == 1 && *(int *)(w + 0x15AC) == 1) {
        func_001CDDD8(D_01B080D0);
    }
}

void func_01B017F0(void)
{
    u8 *w = D_01B081A0;

    func_01B02120(-1, w + 0x10A0, 0);
    *(float *)(w + 0x15A0) = func_01B01FF8(-1);
    *(int *)(w + 0x15AC) = 0;
    *(int *)(w + 0x15A8) = -1;
    D_01B08194 = 1;
    func_01B00B08();
}

void func_01B01848(void)
{
    func_0011ABA8(0);
}

void func_01B01850(void)
{
    u8 *w = D_01B081A0;

    *(int *)(w + 0x15A8) = func_00297C28(func_01B01F68(-1), 0, 0, 0, 0, 0, 0);
}

void func_01B018A0(void)
{
    u8 *w = D_01B081A0;
    u8 *p = w + 0x4C0;
    u8 *s1;
    u8 *v0;

    func_01B04A40(D_01B080D8, p, 4, 8, 0, 0, 0.05f);
    {
        u8 *dst = w + 0x590;
        u8 *src = w + 0x10A0;
        MMI_COPY_LQ_A3(dst, src);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(p + 0xC4) = *(float *)(w + 0x15A0);
    *(float *)(p + 0xD4) -= 0.5f;
    *(float *)(p + 0xE0) = -1.7f;
    *(float *)(p + 0xE8) = -10.0f;
    s1 = w + 0x1360;
    func_01B041C8(s1, D_01B0DF70, D_01B00540);
    *(u8 **)(p + 0x110) = s1;
    v0 = w + 0x10C0;
    *(int *)(v0 + 0x88) = 8;
    v0[0x98] = 0x48;
    v0[0x83] = 0x80;
    v0[0x82] = 0x80;
    v0[0x81] = 0x80;
    v0[0x80] = 0x80;
    v0[0x84] = 0x80;
    v0[0x85] = 0x80;
    v0[0x86] = 0x80;
    v0[0x87] = 0;
    v0[0x99] = 0;
    func_01B07A40(v0, 0x14);
    if (D_01B081B4 == 0) {
        func_01B03B08(-1, D_01B08180, D_01B00610);
    } else {
        u8 *q;
        func_01B03B08(-1, D_01B08180, D_01B00600);
        q = w + 0x12E0;
        func_01B07E90(q, 0x14, 8, 1.0f, 0.5f);
        *(float *)(q + 0x10) = 0.6f;
    }
}

void func_01B01A40(void)
{
    if (D_01B081B4 != 0) {
        func_01B043D0(D_01B0DF70, 0, 0);
    } else {
        func_01B043D0(D_01B0DF70, 0, 1);
    }
}

void func_01B01A70(void)
{
    u8 buf[16];
    u8 *tbl;
    u8 *w = D_01B081A0;
    u8 *s2 = w + 0x720;
    u8 *s1 = w + 0x1160;
    int s5 = 0;
    int i;

    func_01B03510(buf);
    tbl = (D_01B081B4 != 0) ? D_01B00558 : D_01B00570;
    for (i = 0; i < D_01B00658[1]; i++) {
        u8 id = buf[i];
        u8 *s0;
        if (func_01B02A60(id) == 0) {
            int a2;
            float f0;
            if (D_01B081B4 != 0) {
                a2 = 2;
                f0 = 0.14f;
            } else {
                a2 = 3;
                f0 = 0.09f;
            }
            func_01B04A40(D_01B080D8, s2, a2, s5, 0, D_01B05000, f0);
            func_01B02120(id, s2 + 0xD0, 6);
            *(float *)(s2 + 0xD4) -= 0.5f;
        } else {
            func_01B04A40(D_01B080D8, s2, D_01B081B4 == 0, s5, 0, D_01B05000, 0.09f);
            func_01B02120(id, s2 + 0xD0, 4);
        }
        *(float *)(s2 + 0xC4) = *(float *)(w + 0x15A0);
        *(int *)(s2 + 0x120) = func_01B01ED0(id);
        s0 = w + 0x13A0 + (i << 6);
        func_01B041C8(s0, D_01B0DF70, tbl);
        *(u8 **)(s2 + 0x110) = s0;
        s2 += 0x130;
        if (D_01B081B4 != 0) {
            func_01B07BB0(s1, 0x1E);
            *(float *)(s1 + 0x04) = 1.0f;
            *(float *)(s1 + 0x08) = 0.5f;
            *(float *)(s1 + 0x10) = 4.0f;
            *(float *)(s1 + 0x14) = 2.0f;
        } else {
            func_01B07BB0(s1, 0x14);
            *(float *)(s1 + 0x04) = 0.5f;
            *(float *)(s1 + 0x08) = 0.25f;
            *(float *)(s1 + 0x10) = 2.0f;
            *(float *)(s1 + 0x14) = 1.0f;
        }
        *(int *)(s1 + 0x24) = s5;
        *(float *)(s1 + 0x0C) = 0.0f;
        *(float *)(s1 + 0x18) = 0.0f;
        *(u16 *)(s1 + 0x2C) |= 3;
        s5 += 8 + (func_002EFD78() % 3);
        s1 += 0x30;
    }
    if (D_01B081B4 != 0) {
        func_01B07E90(w + 0x1320, 0x1E, 0x3C, 0.5f, 1.0f);
        *(float *)(w + 0x1320) = 0.6f;
    }
}

void func_01B01D28(void)
{
    u8 *w = D_01B081A0;

    func_00297CE8(*(int *)(w + 0x15A8));
    *(int *)(w + 0x15A8) = -1;
}
