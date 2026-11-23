#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct S6CD8Param {
    s32 s00;
    s32 s04;
    u8 b08;
    u8 b09;
    u8 b0A;
    u8 pad0B;
    s16 h0C;
    s16 h0E;
    s32 s10;
    s32 s14;
    u8 b18;
    u8 b19;
    u8 b1A;
    u8 b1B;
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 b1F;
    void *p20;
    void *p24;
    void *p28;
    void *p2C;
    u8 pad30[4];
    s32 s34;
    s32 s38;
    s32 s3C;
    s16 h40;
    s16 h42;
    s32 s44;
    s32 s48;
    u8 b4C;
    u8 b4D;
    u8 pad4E[0x22];
} S6CD8Param; /* size 0x70 */

extern void *D_01B0DCAC;

extern s32 func_001038F8(void);
extern void *func_01B06578(void);
extern void func_002DD128(float (*m)[4]);
extern float func_00110AF0(void *a0);
extern float func_001107C0(void *a0);
extern float func_001107C8(void *a0);
extern float func_001107D0(void *a0);
extern void func_01B0AD18(float (*m)[4], void *a1);
extern void func_01B089F8(float (*m1)[4], float (*m2)[4]);
extern void func_002DCE38(float (*dst)[4], float (*m1)[4], float (*m2)[4]);
extern void func_01B08BD8(float (*m)[4]);
extern void func_01B08BA8(float (*m)[4]);
extern void func_0010D380(void *a0, s32 a1, s32 a2);
extern void func_0010D3A8(void *a0, s32 a1, s32 a2);
extern void func_0010D4A0(void *a0, s32 a1);
extern void func_0010D4D8(void *a0, s32 a1);
extern void func_002B7BE8(void *a0, S6CD8Param *a1, float (*m1)[4], float (*m2)[4], float (*m3)[4]);

void func_01B06CD8(void *a0, float *a1, s32 a2)
{
    S6CD8Param p00;
    float m70[4][4];
    float mB0[4][4];
    float mF0[4][4];
    float m130[4][4];
    float m170[4][4];
    float m1B0[4][4];
    void *chr;
    float sc;

    p00.s00 = 0x21C;
    p00.s04 = func_001038F8();
    p00.b08 = 0x44;
    p00.b1B = a2;
    p00.b09 = 0x80;
    p00.b18 = 0x80;
    p00.b19 = 0x80;
    p00.b1A = 0x80;
    p00.b4C = 0x80;
    p00.b0A = 0;
    p00.h0C = 0;
    p00.h0E = 0;
    p00.s10 = 0;
    p00.s14 = 0;
    p00.b1C = 0;
    p00.b1D = 0;
    p00.b1E = 0;
    p00.b1F = 0;
    p00.s34 = 0;
    p00.s38 = 0;
    p00.s3C = 0;
    p00.h40 = 0;
    p00.h42 = 0;
    p00.s44 = 0;
    p00.s48 = 0;
    p00.b4D = 0;

    chr = func_01B06578();
    func_002DD128(m70);
    sc = func_00110AF0(chr) * 0.001f;
    m70[2][2] = sc;
    m70[1][1] = sc;
    m70[0][0] = sc;
    m70[0][0] *= func_001107C0(chr);
    m70[1][1] *= func_001107C8(chr);
    m70[2][2] *= func_001107D0(chr);
    func_01B0AD18(m70, a0);
    copy_vec(m70[3], a1);
    func_01B089F8(mF0, m130);
    func_002DCE38(mB0, m130, m70);
    func_002DCE38(mB0, mF0, mB0);
    func_01B08BD8(m170);
    func_01B08BA8(m1B0);
    p00.p20 = mB0;
    p00.p24 = m170;
    p00.p28 = m1B0;
    p00.p2C = m70;
    func_0010D380(chr, -1, 0x3C00);
    func_0010D3A8(chr, -1, 0x2EE0);
    func_0010D4A0(chr, -1);
    func_0010D4D8(chr, -1);
    func_002B7BE8(D_01B0DCAC, &p00, m70, m130, mF0);
    func_0010D380(chr, -1, -1);
    func_0010D3A8(chr, -1, -1);
}
