#include "common.h"

extern u8 *D_01B0A480;
extern void *D_01B0A488;

extern void func_01B05140(s32, s32, s32);
extern void *func_01B035F8(s32);
extern void func_0010D4A0(void *, s32);
extern void func_0010D4D8(void *, s32);
extern void *func_001038F8(void);
extern void func_01B04E80(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002B7BE8(void *, void *, void *, void *, void *);
extern void func_002DA610(s32, s32);

typedef struct {
    int w00;
    void *w04;
    u8 b08;
    u8 b09;
    u8 b0A;
    u8 b0B;
    s16 h0C;
    s16 h0E;
    int w10;
    int w14;
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
    int w30;
    float w34;
    float w38;
    float w3C;
    s16 h40;
    s16 h42;
    float w44;
    float w48;
    u8 b4C;
    u8 b4D;
    u8 pad4E[0x22];
} DrawParams;

void func_01B02C88(void) {
    DrawParams desc;
    float m0[16];
    float m1[16];
    float m2[16];
    u8 *ctx = D_01B0A480;
    void *h;
    u8 *mat_ptr;

    func_01B05140(0, 0x3C00, 0x2EE0);
    h = func_01B035F8(0);
    func_0010D4A0(h, -1);
    func_0010D4D8(h, -1);

    if (*(s32 *)(ctx + 0xED8) > 0) {
        *(s32 *)(ctx + 0xED8) -= 1;
    }

    mat_ptr = ctx + 0xAD0;
    desc.w00 = 0x5C;
    desc.w04 = func_001038F8();
    desc.b08 = 0x44;
    desc.b09 = 0x80;
    desc.b0A = 0;
    desc.h0C = 0;
    desc.h0E = 0;
    desc.w10 = 0;
    desc.w14 = 0;
    desc.b18 = 0x80;
    desc.b19 = 0x80;
    desc.b1A = 0x80;
    desc.b1B = 0x80;
    desc.b1C = 0;
    desc.b1D = 0;
    desc.b1E = 0;
    desc.b1F = 0;
    desc.w34 = 0;
    desc.w38 = 0;
    desc.w3C = 0;
    desc.h40 = 0;
    desc.h42 = 0;
    desc.w44 = 0;
    desc.w48 = 0;
    {
        int d = 100;
        desc.b4C = (*(s32 *)(ctx + 0xED8) * 64 + (d - *(s32 *)(ctx + 0xED8)) * 128) / d;
        desc.b4D = (*(s32 *)(ctx + 0xED8) * 64) / 100;
    }

    func_01B04E80(m1, m2);
    func_002DCE38(m0, m2, mat_ptr);
    func_002DCE38(m0, m1, m0);

    desc.p20 = m0;
    desc.p24 = ctx + 0xC10;
    desc.p28 = ctx + 0xBD0;
    desc.p2C = mat_ptr;

    func_002B7BE8(D_01B0A488, &desc, mat_ptr, m2, m1);
    func_002DA610(0, 0);
    func_01B05140(0, -1, -1);
}
