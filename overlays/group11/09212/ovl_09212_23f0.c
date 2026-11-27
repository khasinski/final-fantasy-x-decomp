#include "common.h"

extern u8 *D_01B0A8E8;
extern int D_01B00838[];

void func_01B01AC8(void *a0, int a1);
void func_002DD128(void *a0);
void func_01B04038(int a0, int a1, int a2, void *a3);
void func_01B01E38(void *a0, void *a1, void *a2);

void func_01B023F0(u8 *a0)
{
    int c[4];

    c[0] = *(int *)(a0 + 0x2C);
    c[1] = *(int *)(a0 + 0x30);
    c[2] = *(int *)(a0 + 0x34);
    c[3] = 0x80;
    func_01B01AC8(c, *(int *)(a0 + 0x38));
}

void func_01B02438(void)
{
    float m[4][4];
    float pos[4];
    u8 *s3 = D_01B0A8E8;
    u8 *s0;
    int i;

    func_002DD128(m);
    s0 = s3 + 0xF00;
    m[0][0] = m[1][1] = m[2][2] = 0.3f;
    for (i = 0; i < 4; i++) {
        func_01B04038(-1, D_01B00838[i], 0, pos);
        if (*(int *)(s3 + 0x31D4) == 0) {
            if (s0[0x813] >= 2) {
                s0[0x813]--;
            } else {
                s0[0x813] = 0;
            }
        }
        func_01B01E38(s0, m, pos);
        s0 += 0x8B0;
    }
}
