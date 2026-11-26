/* EE Battle-Effect Overlay: group 0x11, file 09643 (0x01B01D50..0x01B02324)
 * .text: 7 functions (1,492 bytes)
 */
#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_M(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_M(dst) __asm__ volatile("sq $7, 0($3)" : "=m"(*(dst)) : : "memory")

extern u8 *D_01B094A8;
extern u8 D_01B09360[];
extern int D_01B00838[];

void func_002DD128(void *a0);
void func_01B03090(int a0, int a1, int a2, void *a3);
void func_01B01908(void *a0, void *a1, void *a2);
void func_00293F10(int a0);
void func_001CF840(int a0);
void func_0029A878(void);
void func_00118098(int a0, int a1);
void func_01B08BC0(void *a0, int a1);
void **func_01B05AA0(void *a0, int a1);
void func_01B01898(void *a0, void *a1);
void *func_01B051B0(void *a0);
void func_01B05378(void *a0);
void func_01B01598(void *a0, int a1);
void func_01B016D0(void);
void func_01B05980(void *a0, void *a1);
void func_01B05510(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B043E0(int a0, void *a1, void *a2);

void func_01B01D50(void)
{
    float m[4][4];
    float pos[4];
    u8 *s3 = D_01B094A8;
    u8 *s0;
    int i;

    func_002DD128(m);
    s0 = s3 + 0xF00;
    m[0][0] = m[1][1] = m[2][2] = 0.3f;
    for (i = 0; i < 4; i++) {
        func_01B03090(-1, D_01B00838[i], 0, pos);
        if (*(int *)(s3 + 0x31D4) == 0) {
            if (s0[0x813] >= 2) {
                s0[0x813]--;
            } else {
                s0[0x813] = 0;
            }
        }
        func_01B01908(s0, m, pos);
        s0 += 0x8B0;
    }
}

void func_01B01E28(void)
{
    func_00293F10(0);
    func_001CF840(0);
    func_0029A878();
}

void func_01B01E50(void)
{
    u8 *s3;
    u8 *v0;
    void *s1;
    u8 *s0;
    int i;

    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    s3 = D_01B094A8;
    v0 = s3 + 0xB00;
    v0[0x83] = 0x80;
    v0[0x80] = 0xFF;
    v0[0x81] = 0xFF;
    v0[0x82] = 0xFF;
    v0[0x84] = 0xFF;
    v0[0x85] = 0xFF;
    v0[0x86] = 0xFF;
    v0[0x98] = 0x48;
    v0[0x87] = 0;
    *(int *)(v0 + 0x88) = 0;
    v0[0x99] = 0;
    func_01B08BC0(v0, 0x14);
    s1 = *func_01B05AA0(D_01B09360, 8);
    s0 = s3 + 0xF00;
    for (i = 0; i < 4; i++) {
        func_01B01898(s0, s1);
        *(int *)(s0 + 0x828) = 0x96;
        *(float *)(s0 + 0x820) = 4.0f;
        s0[0x813] = 0x18;
        s0 += 0x8B0;
    }
    *(int *)(s3 + 0x31D4) = 1;
    if (*(void **)(s3 + 0x31C0) == 0) {
        void *t = func_01B051B0((void *)func_01B01D50);
        func_01B05378(t);
        *(void **)(s3 + 0x31C0) = t;
    }
}

void func_01B01F80(u8 *a0)
{
    int c[4];

    c[0] = *(int *)(a0 + 0x2C);
    c[1] = *(int *)(a0 + 0x30);
    c[2] = *(int *)(a0 + 0x34);
    c[3] = 0x80;
    func_01B01598(c, *(int *)(a0 + 0x38));
}

void func_01B01FC8(void)
{
    *(int *)(D_01B094A8 + 0x31D4) = 0;
}

void func_01B01FD8(void)
{
    u8 *w = D_01B094A8;

    if (*(int *)(w + 0x31D0) > 0) {
        (*(int *)(w + 0x31D0))--;
    }
    func_01B016D0();
}

void func_01B01FF8(void)
{
    u8 *s1 = D_01B094A8;
    void *s4;
    u8 *s0;
    u8 *s3;
    u8 *s5;
    float ang;
    void *t;
    int i;

    s4 = *func_01B05AA0(D_01B09360, 8);
    s0 = s1 + 0xF00;
    for (i = 0; i < 4; i++) {
        func_01B01898(s0, s4);
        *(int *)(s0 + 0x828) = 0x96;
        *(float *)(s0 + 0x820) = 2.0f;
        s0[0x813] = 0x18;
        s0 += 0x8B0;
    }
    *(int *)(s1 + 0x31D4) = 1;
    func_01B05980(D_01B09360, s1 + 0x130);
    s3 = s1 + 0x720;
    func_01B05510(D_01B09360, s3, 6, 0, 0, 0, 0.3f);
    {
        u8 *dst = s1 + 0x7F0;
        u8 *src = s1 + 0xAC0;
        MMI_COPY_LQ_A3_M(src, dst);
        MMI_COPY_SQ_A3_M(dst);
    }
    *(float *)(s3 + 0xD4) += -850.0f;
    *(float *)(s3 + 0xC4) = *(float *)(s1 + 0x31C8);
    *(float *)(s3 + 0x64) *= 1.5f;
    s5 = s1 + 0x850;
    func_01B05510(D_01B09360, s5, 7, 0, 0, 0, 0.075f);
    {
        u8 *dst = s1 + 0x920;
        u8 *src = s1 + 0xAC0;
        MMI_COPY_LQ_A3_M(src, dst);
        MMI_COPY_SQ_A3_M(dst);
    }
    *(float *)(s5 + 0xD4) += -1070.0f;
    *(float *)(s5 + 0xC4) = *(float *)(s1 + 0x31C8);
    *(float *)(s1 + 0xAB4) = *(float *)(s1 + 0xAC4) - 1100.0f;
    ang = *(float *)(s1 + 0x31C8) + 2.8274333f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(s1 + 0xAA4) = ang;
    func_01B043E0(-1, s1 + 0x9C0, s1 + 0xAA0);
    *(float *)(s1 + 0xA00) = 2.0f;
    *(float *)(s1 + 0xA04) = 2.0f;
    *(float *)(s1 + 0xA08) = 2.0f;
    *(float *)(s1 + 0xA0C) = 1.0f;
    *(float *)(s1 + 0xA10) = 0.0f;
    *(float *)(s1 + 0xA14) = 0.0f;
    *(float *)(s1 + 0xA18) = 0.0f;
    *(float *)(s1 + 0xA1C) = 1.0f;
    *(float *)(s1 + 0xA20) = 0.0f;
    *(float *)(s1 + 0xA24) = 0.0f;
    *(float *)(s1 + 0xA28) = 0.0f;
    *(float *)(s1 + 0xA2C) = 1.0f;
    *(float *)(s1 + 0xA30) = 0.0f;
    *(float *)(s1 + 0xA34) = 0.0f;
    *(float *)(s1 + 0xA38) = 0.0f;
    *(float *)(s1 + 0xA3C) = 1.0f;
    *(float *)(s1 + 0xA40) = 0.0f;
    *(float *)(s1 + 0xA44) = 0.0f;
    *(float *)(s1 + 0xA48) = -20.0f;
    *(float *)(s1 + 0xA4C) = 20.0f;
    *(float *)(s1 + 0xA50) = 0.0f;
    *(float *)(s1 + 0xA54) = 0.0f;
    *(float *)(s1 + 0xA58) = 0.0f;
    *(float *)(s1 + 0xA5C) = 1.0f;
    *(float *)(s1 + 0xA60) = 0.0f;
    *(float *)(s1 + 0xA64) = 0.0f;
    *(float *)(s1 + 0xA68) = 0.0f;
    *(float *)(s1 + 0xA6C) = 1.0f;
    *(float *)(s1 + 0xA70) = 0.0f;
    *(float *)(s1 + 0xA74) = 0.0f;
    *(float *)(s1 + 0xA78) = 0.0f;
    *(float *)(s1 + 0xA7C) = 1.0f;
    *(int *)(s1 + 0x31CC) = 1;
    *(int *)(s1 + 0x31D0) = 100;
    t = func_01B051B0((void *)func_01B01FD8);
    *(void **)(s1 + 0x31C4) = t;
    func_01B05378(t);
}
