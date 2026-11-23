/* EE Battle-Effect Overlay: group 0x11, file 09526 (0x01B0B708..0x01B0B9EC, -O0, shared across 21 containers)
 * Load base: 0x01B00000, .text: 0x01B0B708..0x01B0B9EC (2 functions)
 */
#include "common.h"

extern float D_004F4610[];

#define P6_SIN(a) D_004F4610[((a) & 0xFFFF) >> 4]
#define P6_COS(a) D_004F4610[((a) + 0x4000 & 0xFFFF) >> 4]

void func_01B08A70(void *m);
void func_01B0CA70(float (*dst)[4], float (*a)[4], float (*b)[4]);

void func_01B0B708(register void *a0, register unsigned char a1)
{
    struct {
        void *p;
        unsigned char f4;
        unsigned char f5;
    } m;

    m.p = a0;
    m.f5 = a1;
    func_01B08A70(&m);
}

void func_01B0B768(register float (*out)[4], register int *ang)
{
    float m0[4][4];
    float m1[4][4];
    float s;
    float c;

    s = P6_SIN(ang[2]);
    c = P6_COS(ang[2]);
    m0[0][0] = c;
    m0[0][1] = s;
    m0[0][2] = 0.0f;
    m0[0][3] = 0.0f;
    m0[1][0] = -s;
    m0[1][1] = c;
    m0[1][2] = 0.0f;
    m0[1][3] = 0.0f;
    m0[2][0] = 0.0f;
    m0[2][1] = 0.0f;
    m0[2][2] = 1.0f;
    m0[2][3] = 0.0f;
    m0[3][0] = 0.0f;
    m0[3][1] = 0.0f;
    m0[3][2] = 0.0f;
    m0[3][3] = 1.0f;
    s = P6_SIN(ang[1]);
    c = P6_COS(ang[1]);
    m1[0][0] = c;
    m1[0][1] = 0.0f;
    m1[0][2] = -s;
    m1[0][3] = 0.0f;
    m1[1][0] = 0.0f;
    m1[1][1] = 1.0f;
    m1[1][2] = 0.0f;
    m1[1][3] = 0.0f;
    m1[2][0] = s;
    m1[2][1] = 0.0f;
    m1[2][2] = c;
    m1[2][3] = 0.0f;
    m1[3][0] = 0.0f;
    m1[3][1] = 0.0f;
    m1[3][2] = 0.0f;
    m1[3][3] = 1.0f;
    func_01B0CA70(m1, m1, m0);
    s = P6_SIN(ang[0]);
    c = P6_COS(ang[0]);
    m0[0][0] = 1.0f;
    m0[0][1] = 0.0f;
    m0[0][2] = 0.0f;
    m0[0][3] = 0.0f;
    m0[1][0] = 0.0f;
    m0[1][1] = c;
    m0[1][2] = s;
    m0[1][3] = 0.0f;
    m0[2][0] = 0.0f;
    m0[2][1] = -s;
    m0[2][2] = c;
    m0[2][3] = 0.0f;
    func_01B0CA70(out, m0, m1);
}
