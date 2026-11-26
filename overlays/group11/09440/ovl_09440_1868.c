/* EE Battle-Effect Overlay: group 0x11, file 09440 (0x01B01868..0x01B0227C)
 * .text: 15 functions (2,580 bytes)
 */
#include "common.h"
#include "vu0.h"

extern void *D_01B00974;
extern u8 *D_01B0A2C0;
extern void *D_01B0A2C8;
extern u8 *D_01B0A23C;
extern int D_01B0A1F0;
extern int D_01B0A2B4;
extern int D_01B0A2D8;
extern u8 D_01B0A1F8[];
extern u8 D_01B0A240[];
extern u8 D_01B0A2A0[];
extern u8 D_01B10910[];
extern u8 D_01B00658[];
extern u8 D_01B06750[];

void func_01B07538(void);
int func_01B09760(void *a0);
int func_0011ABB8(void);
int func_01B05330(void *a0);
void func_01B05ED0(void *a0);
int func_01B06290(void *a0, void *a1);
void func_001CDDD8(int a0);
void func_01B03890(int a0, void *a1, int a2);
float func_01B03768(int a0);
void func_01B00C58(void);
void func_0011ABA8(int a0);
int func_01B036D8(int a0);
int func_00297C28(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_00297CE8(int a0);
void func_01B05B40(void *a0, int a1, int a2);
void func_01B05858(void *a0, int a1, int a2, int a3);
void func_01B061B0(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B05938(void *a0, void *a1, void *a2);
void *func_01B03710(int a0, int a1);
void func_001072F8(void *a0, int a1, void *a2);
float func_00110AF0(void *a0);
void func_002DD998(void *a0, void *a1, float f0);
void func_002DD128(void *a0);
void func_002DD1C8(void *a0, void *a1, float f0);
void func_002DCE38(void *a0, void *a1, void *a2);
void func_00108910(void *a0, int a1, void *a2);
void func_01B09A18(void *a0, float f0, float f1, int a1, int a2);
void func_01B09860(void *a0, int a1);
float func_01B06D28(float f0, float f1, float f2, float f3, float f4, float f5);
float func_01B06D90(float f0, void *a0, int a1, int a2);
float func_01B07088(void *a0, void *a1);
void func_01B06EE0(void *a0, void *a1, void *a2);
void func_01B077D8(void *a0, void *a1, void *a2);
void func_01B06620(void *a0, void *a1);

void func_01B019D8(void);

void func_01B01868(void *a0)
{
    u8 *w = D_01B0A2C0;
    int r;

    func_01B07538();
    D_01B00974 = D_01B0A2C8;
    r = func_01B09760(D_01B0A240);
    if (func_0011ABB8() == 0) {
        int r2 = func_01B05330(D_01B0A2A0);
        if (r != 0 && r2 != 0) {
            *(int *)(w + 0x2488) = 1;
            func_01B019D8();
            func_01B05ED0(a0);
        }
    }
}

void func_01B01910(void)
{
    u8 *w = D_01B0A2C0;
    int r;

    if (func_0011ABB8() == 0) {
        r = func_01B06290(D_01B0A1F8, D_01B0A23C);
    } else {
        r = 0;
    }
    if (r == 1 && *(int *)(w + 0x2488) == 1) {
        func_001CDDD8(D_01B0A1F0);
    }
}

void func_01B01980(void)
{
    u8 *w = D_01B0A2C0;

    func_01B03890(-1, w + 0xBE0, 0);
    *(float *)(w + 0x2480) = func_01B03768(-1);
    *(int *)(w + 0x2488) = 0;
    *(int *)(w + 0x2484) = -1;
    D_01B0A2B4 = 1;
    func_01B00C58();
}

void func_01B019D8(void)
{
    func_0011ABA8(0);
}

void func_01B019E0(void)
{
    u8 *w = D_01B0A2C0;

    *(int *)(w + 0x2484) = func_00297C28(func_01B036D8(-1), 0, 0, 0, 0, 0, 0);
}

void func_01B01A30(void)
{
    u8 *w = D_01B0A2C0;

    func_00297CE8(*(int *)(w + 0x2484));
    *(int *)(w + 0x2484) = -1;
}

void func_01B01A68(void)
{
    int a1;

    if (D_01B0A2D8 != 0) {
        func_01B05B40(D_01B10910, 0, 1);
        a1 = 3;
    } else {
        func_01B05B40(D_01B10910, 0, 2);
        a1 = 1;
    }
    func_01B05858(D_01B10910, a1, 0x40, 0x100);
}

void func_01B01AD0(void)
{
    int a1;

    if (D_01B0A2D8 != 0) {
        a1 = 4;
    } else {
        a1 = 2;
    }
    func_01B05858(D_01B10910, a1, 0x40, 0x100);
}

void func_01B01AF8(void)
{
    u8 *w = D_01B0A2C0;

    if (D_01B0A2D8 != 0) {
        u8 *s1 = w + 0x720;
        float ang;
        u8 *s0;

        func_01B061B0(D_01B0A1F8, s1, 6, 0, 0, 0, 0.2f);
        {
            u8 *dst = w + 0x7F0;
            u8 *src = w + 0xBE0;
            MMI_COPY_LQ_A3(dst, src);
            MMI_COPY_SQ_A3(dst);
        }
        *(float *)(s1 + 0xD4) -= 14.8f;
        *(float *)(s1 + 0xE0) = 0.5f;
        *(float *)(s1 + 0xE8) = -4.8f;
        *(float *)(s1 + 0xC0) = -0.47123894f;
        ang = *(float *)(w + 0x2480) + 0.3455752f;
        if (ang > 3.1415927f) {
            ang -= 6.2831855f;
        } else if (ang < -3.1415927f) {
            ang += 6.2831855f;
        }
        *(float *)(s1 + 0xC4) = ang;
        s0 = w + 0xF40;
        func_01B05938(s0, D_01B10910, D_01B00658);
        *(u8 **)(s1 + 0x110) = s0;
    }
}

void func_01B01C48(u8 *a0)
{
    float m0[4][4];
    float m1[4][4];
    void *s1;
    float sc;

    s1 = func_01B03710(-1, 0);
    func_001072F8(s1, 1, m0);
    sc = 1000.0f / func_00110AF0(s1);
    func_002DD998(m0[0], m0[0], sc);
    func_002DD998(m0[1], m0[1], sc);
    func_002DD998(m0[2], m0[2], sc);
    func_002DD128(m1);
    func_002DD1C8(m1, m1, 1.5707964f);
    func_002DCE38(a0 + 0x80, m0, m1);
    func_00108910(s1, 0xE, a0 + 0xD0);
}

void func_01B01D30(u8 *a0)
{
    int c = *(int *)(a0 + 0x120) - 1;
    int v;

    *(int *)(a0 + 0x120) = c;
    v = (c << 12) / 30;
    *(s16 *)(a0 + 0x76) = v;
    *(s16 *)(a0 + 0x74) = v;
    *(s16 *)(a0 + 0x72) = v;
    *(s16 *)(a0 + 0x70) = v;
    if (c == 0) {
        *(void **)(a0 + 0x104) = 0;
    }
}

void func_01B01D78(u8 *a0)
{
    *(int *)(a0 + 0x120) = 0x1E;
    *(void **)(a0 + 0x104) = (void *)func_01B01D30;
}

void func_01B01D90(void)
{
    u8 *w = D_01B0A2C0;
    int idx;
    u8 *s0;

    if (D_01B0A2D8 != 0) {
        idx = 8;
        func_01B09A18(w + 0xE20, 1.0f, 0.7f, 0x28, 0);
    } else {
        idx = 7;
    }
    s0 = w + idx * 0x130;
    func_01B061B0(D_01B0A1F8, s0, idx, 0, 0x9B, (void *)func_01B01D78, 0.02f);
    *(float *)(s0 + 0xC4) = *(float *)(w + 0x2480);
    *(void **)(s0 + 0x104) = (void *)func_01B01C48;
    s0[0x126] = 2;
}

void func_01B01E60(void)
{
    u8 *w = D_01B0A2C0;
    u8 *s0 = w + 0xAB0;
    float ang;
    u8 *v0;

    func_01B061B0(D_01B0A1F8, s0, 9, 0, 0, 0, 0.08f);
    {
        u8 *dst = w + 0xB80;
        u8 *src = w + 0xBE0;
        MMI_COPY_LQ_A3(dst, src);
        MMI_COPY_SQ_A3(dst);
    }
    *(float *)(s0 + 0xD4) -= 0.5f;
    *(float *)(s0 + 0xE8) = -20.0f;
    ang = *(float *)(w + 0x2480) - 0.31415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(s0 + 0xC4) = ang;
    v0 = w + 0xC00;
    v0[0x80] = 0x80;
    v0[0x81] = 0x40;
    v0[0x82] = 0x40;
    v0[0x83] = 0x80;
    v0[0x84] = 0x80;
    v0[0x85] = 0x40;
    v0[0x86] = 0x40;
    v0[0x87] = 0;
    *(int *)(v0 + 0x88) = 0;
    v0[0x98] = 0x48;
    v0[0x99] = 0;
    func_01B09860(v0, 0x14);
    if (D_01B0A2D8 != 0) {
        u8 *q = w + 0xE60;
        func_01B09A18(q, 0.7f, 0.6f, 0x28, 0);
        *(float *)(q + 0x10) = 0.7f;
    }
}

void func_01B01FF0(u8 *a0_arg)
{
    float m[4][4];
    float pos[4];
    register u8 *a0 __asm__("$19") = a0_arg;
    u8 *s1 = *(u8 **)(a0 + 0x14);

    if (*(int *)(s1 + 0x530) > 0) {
        (*(int *)(s1 + 0x530))--;
        return;
    }
    if (*(int *)(s1 + 0x534) > 0) {
        (*(int *)(s1 + 0x534))--;
    }
    if (*(int *)(s1 + 0x534) >= 0) {
        float t = func_01B06D28(6.0f, 2.0f, 1.5f, 4.0f, 0.0f, (float)*(int *)(s1 + 0x534) / 50.0f);
        pos[0] = func_01B06D90(t, s1 + 0x490, 7, 4);
        pos[1] = func_01B06D90(t, s1 + 0x494, 7, 4);
        pos[2] = func_01B06D90(t, s1 + 0x498, 7, 4);
        if (*(int *)(s1 + 0x538) == 2) {
            if (func_01B07088(s1 + 0xD0, pos) > 0.0f) {
                func_01B06EE0(s1 + 0xC0, s1 + 0xD0, pos);
            }
        }
        MMI_COPY_LQ_A3(s1 + 0xD0, pos);
        MMI_COPY_SQ_A3(s1 + 0xD0);
    } else {
        if (*(int *)(s1 + 0x488) < 2) {
            goto kill;
        }
        *(int *)(s1 + 0x488) -= 2;
        MMI_COPY_LQ_A3(pos, s1 + 0xD0);
        MMI_COPY_SQ_A3(pos);
    }
    if (*(int *)(s1 + 0x538) == 2) {
        func_002DD128(m);
        m[0][0] = m[1][1] = m[2][2] = 0.1f;
        func_01B077D8(s1 + 0x260, m, pos);
    }
    if (*(int *)(s1 + 0x534) == 0) {
        int a2;
        void *cb;
        u8 *s0;

        func_01B06620(D_01B0A1F8, s1);
        switch (*(int *)(s1 + 0x538)) {
        case 0:
            a2 = 4;
            break;
        case 1:
            a2 = 5;
            break;
        default:
            a2 = 3;
            break;
        }
        cb = (*(int *)(s1 + 0x53C) == 1) ? D_01B06750 : 0;
        s0 = s1 + 0x130;
        func_01B061B0(D_01B0A1F8, s0, a2, 0, 0, cb, 0.05f);
        *(float *)(s0 + 0xC4) = *(float *)(s1 + 0xC4);
        {
            u8 *dst = s1 + 0x200;
            MMI_COPY_LQ_A3(dst, pos);
            MMI_COPY_SQ_A3(dst);
        }
        if (*(int *)(s1 + 0x538) != 2) {
        kill:
            func_01B05ED0(a0);
        } else {
            *(int *)(s1 + 0x534) = -1;
        }
    }
}
