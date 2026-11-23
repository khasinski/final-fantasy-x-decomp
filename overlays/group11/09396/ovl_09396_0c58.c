/* EE Battle-Effect Overlay: group 0x11, file 09396 (0x01B00C58..0x01B00FBC)
 * .text: 8 functions (856 bytes)
 */
#include "common.h"

typedef unsigned long u64;

extern u8 *D_01B07AE4;
extern u8 *D_01B07B68;
extern int D_01B07A98;
extern int D_01B07B5C;
extern u8 D_01B07AA0[];
extern u8 D_01B07AE8[];
extern u8 D_01B07B48[];

int func_01B07388(void *a0);
int func_01B03608(void *a0);
void func_01B041A8(void *a0);
int func_01B04568(void *a0, void *a1);
void func_001CDDD8(int a0);
float func_01B01A40(int a0);
void func_01B01B68(int a0, void *a1, int a2);
u8 *func_01B04A08(void *a0, int a1);
void func_002B6E70(int a0, u64 a1);
void func_01B04488(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B02008(int a0, int a1, void *a2, void *a3);
float func_001AA038(void);
void func_01B03238(void *a0, void *a1);
void func_002DCF48(void *dst, void *src);
void func_002DCE08(void *dst, void *m, void *v);

void func_01B00E18(void);
void func_01B00F20(void *a0, float *a1);

void func_01B00C58(void *a0)
{
    u8 *w = D_01B07B68;
    int r0 = func_01B07388(D_01B07AE8);
    int r1 = func_01B03608(D_01B07B48);

    if (r0 == 1 && r1 == 1) {
        *(int *)(w + 0xC00) = 1;
        func_01B00E18();
        func_01B041A8(a0);
    }
}

void func_01B00CE8(void)
{
    u8 *w = D_01B07B68;
    int r = func_01B04568(D_01B07AA0, D_01B07AE4);

    if (r == 1 && *(int *)(w + 0xC00) == 1) {
        func_001CDDD8(D_01B07A98);
    }
}

void func_01B00D50(void)
{
    u8 *w = D_01B07B68;

    *(float *)(w + 0x980) = 0.0f;
    *(float *)(w + 0x984) = func_01B01A40(-1);
    *(float *)(w + 0x988) = 0.0f;
    *(float *)(w + 0x98C) = 0.0f;
    func_01B01B68(-1, w + 0x990, 3);
    *(int *)(w + 0xC00) = 0;
    D_01B07B5C = 1;
}

void func_01B00DB0(void)
{
    int i;

    for (i = 3; i < 0x36; i++) {
        u8 *p = func_01B04A08(D_01B07AA0, i);
        func_002B6E70(*(int *)(p + 0x1C), 0x000664A21A00ULL);
    }
}

void func_01B00E18(void)
{
}

void func_01B00E20(void)
{
    u8 *w = D_01B07B68;
    u8 *s0 = D_01B07AA0;
    u8 *s2 = w + 0x720;

    func_01B04488(s0, s2, 0, 0, 0, 0, 0.35f);
    func_01B02008(-1, 0x17, 0, w + 0x7F0);
    *(float *)(s2 + 0xC4) = *(float *)(w + 0x984);

    s2 = w + 0x850;
    func_01B04488(s0, s2, 0, 0, 0, 0, 0.35f);
    func_01B02008(-1, 0x1A, 0, w + 0x920);
    *(float *)(s2 + 0xC4) = *(float *)(w + 0x984);
}

float func_01B00EF0(void)
{
    return 1024.0f / func_001AA038();
}

void func_01B00F20(void *a0, float *a1)
{
    float m0[16];
    float m1[16];

    func_01B03238(m0, m1);
    func_002DCF48(a0, m1);
    a1[0] = 0.0f;
    a1[1] = 0.0f;
    a1[2] = 5.0f;
    a1[3] = 1.0f;
    func_002DCE08(a1, a0, a1);
    a1[3] = 1.0f;
}

void func_01B00FB0(u8 *a0)
{
    func_01B00F20(a0 + 0x80, (float *)(a0 + 0xD0));
}
