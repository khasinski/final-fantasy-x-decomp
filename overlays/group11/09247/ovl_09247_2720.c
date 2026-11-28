#include "common.h"

extern u32 D_01B00848;
extern u8 D_01B009B0[];
extern u8 D_01B00A10[];
extern u8 D_01B00C34;
extern u8 D_01B00C38[];
extern void *D_01B0F780;

extern u32 *func_002B49A0(u32, s32, s32);
extern void func_01B0A0C8(void *);
extern void func_002DD068(void *, void *, float);
extern void func_01B0B250(void *);
extern void func_01B0B2D8(void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DCF48(void *, void *);
extern void func_00173B90(void *, u32, s32, s32, void *, void *, void *, s32);
extern void func_00173CD8(void *, void *, void *, s32, u32, unsigned long, float);

typedef struct {
    void *f0;
    union {
        void *f4;
        struct {
            u8 b4;
            u8 b5;
        } b;
    } u;
    u32 pad[2];
} Param1;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fc;
    void *f10;
    void *f14;
    u32 pad[2];
} Param2;

void func_01B02720(u8 *a0, u8 *a1, void *a2) {
    float mat[16];
    float v0[4];
    float v1[4];
    Param1 p1;
    Param2 p2;
    u32 *tex;
    register u8 *p_a1 __asm__("$21") = a1;
    register u8 *p_e0 __asm__("$20") = a0 + 0xE0;
    register u8 *p_50 __asm__("$19") = a0 + 0x50;
    Param1 *pp1;

    tex = func_002B49A0(D_01B00848, 2, 5);

    pp1 = &p1;
    p1.f0 = p_50;
    pp1->u.f4 = D_01B00C38;
    func_01B0A0C8(pp1);

    func_002DD068(a0 + 0x70, p_a1 + 0x20, 0.1f);

    {
        register u8 *d_a10 __asm__("$3") = D_01B00A10;
        register Param2 *pp2 __asm__("$2");
        register u8 *d_9b0 __asm__("$5");
        p2.fc = p_50;
        p2.f0 = p_e0;
        pp2 = &p2;
        __asm__("" : "+r"(pp2));
        __asm__("" : "+r"(d_a10));
        *(volatile float *)(a0 + 0x7C) = 1.0f;
        ((volatile Param2 *)pp2)->f4 = D_01B00C38;
        d_9b0 = D_01B009B0;
        pp2->f8 = d_a10;
        p2.f10 = a2;
        pp2->f14 = d_9b0;
        func_01B0B250(pp2);
    }

    p1.f0 = p_e0;
    p1.u.b.b5 = D_01B00C34;
    func_01B0B2D8(pp1);

    v0[0] = -8.0f;
    v0[1] = 0.0f;
    v0[2] = -8.0f;
    v0[3] = 1.0f;

    v1[0] = 8.0f;
    v1[1] = 0.0f;
    v1[2] = 8.0f;
    v1[3] = 1.0f;

    func_002DD0C0(mat, a0 + 0x180);
    func_002DCF48(mat, mat);

    func_00173B90(D_01B0F780, 0x40000, 0, 0, mat, v0, v1, 1);
    func_00173CD8(
        D_01B0F780,
        v0,
        v1,
        0x80,
        ((*tex & 0x3FFF) >> 5) | 0x01020000,
        0x007F0000007F0000ULL,
        1.0f
    );

    *(s32 *)(a0 + 0x18) = 0;
}
