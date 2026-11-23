/* 09138 effect init (828 B). */

#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x20];
    u8 sub20[0x360];
    u8 sub380[0x20];
    Vec4 pos3A0;
    u8 sub3B0[0x20];
    Vec4 scale3D0;
    u8 pad3E0[0x60];
    u8 sub440[0x3F0];
    s32 w830;
    float f834;
    s16 h838;
} Work9138;

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
    u8 pad3C[0x24];
    float f60;
    float f64;
    float f68;
    float f6C;
} ObjF80;

extern void *D_01B00820;
extern u8 D_01B00838;
extern u8 D_01B00950[];
extern u8 D_01B009E0[];
extern u8 D_01B00BF0[];
extern u8 D_01B00C08[];
extern u8 D_01B00C28[];
extern u8 D_01B00C90[];
extern u8 D_01B00E70[];
extern u8 D_01B00EE0[];
extern ObjF80 D_01B00F80;
extern u8 D_01B0E3D0[];
extern void *D_01B0E3FC;

extern void func_01B01F18(void);
extern void func_01B0CFE0(void *);
extern void func_01B0D3E8(void *);
extern void func_01B03D08(void *);
extern void func_01B07760(void *);
extern void func_01B09ED0(void *);
extern void func_01B0B7C0(void *);
extern void func_01B0B788(void *);
extern s32 func_01B01BC8(u32);
extern void func_01B03A68(void *);
extern void func_01B0C030(void *);
extern void func_01B06AA8(void *);
extern void func_01B06BD8(void *);

void ovl_09138_2278(Work9138 *w)
{
    void *p[10];
    u8 *sub380 = w->sub380;
    u8 *sub3B0 = w->sub3B0;
    u8 *sub440 = w->sub440;
    u8 *pc08;
    u8 *pee0;
    u8 *pe70;
    u8 *pe70_38;
    ObjF80 *pf80;
    float f1 = 1.0f;

    p[0] = w;
    p[1] = (void *)func_01B01F18;
    p[2] = w;
    func_01B0CFE0(p);

    p[0] = D_01B00BF0;
    p[1] = w;
    func_01B0D3E8(p);

    w->w830 = 0;
    w->h838 = 0;

    pee0 = D_01B00EE0;
    pc08 = D_01B00C08;
    p[0] = pee0;
    p[1] = pc08;
    p[2] = (void *)(u32)D_01B00838;
    ((u8 *)&p[3])[0] = 0;
    func_01B03D08(p);

    p[0] = sub380;
    p[1] = pc08;
    func_01B07760(p);

    p[0] = sub3B0;
    p[1] = pc08;
    func_01B07760(p);

    {
        register void *p9e0 __asm__("$3") = D_01B009E0;
        register void **v0 __asm__("$2");
        *(void *volatile *)&p[4] = sub440;
        v0 = &p[4];
        __asm__("" : "+f"(f1) : "r"(v0) : "memory");
        *(volatile float *)&w->scale3D0.x = f1;
        __asm__("" : "+r"(p9e0));
        __asm__("" : "+r"(p9e0));
        __asm__("" : "+f"(f1) : "r"(p9e0) : "memory");
        {
            register void *pc90 __asm__("$5") = D_01B00C90;
            *(volatile float *)&w->scale3D0.y = f1;
            __asm__("" : "+f"(f1) : : "memory");
            *(volatile float *)&w->scale3D0.z = f1;
            __asm__("" : "+r"(v0) : "f"(f1) : "memory");
            {
                register void **a0_ __asm__("$4") = v0;
                __asm__("" : "+r"(a0_) : : "memory");
                *(void *volatile *)&v0[2] = p9e0;
                *(void *volatile *)&p[7] = sub380;
                *(void *volatile *)&v0[4] = pc90;
                *(void *volatile *)&p[9] = sub3B0;
                v0[1] = pc08;
                func_01B09ED0(a0_);
            }
        }
    }

    pe70 = D_01B00E70;
    pe70_38 = pe70 + 0x38;
    p[0] = pe70;
    p[1] = pc08;
    p[2] = sub440;
    p[3] = D_01B00950;
    p[4] = D_01B00820;
    p[5] = 0;
    func_01B0B7C0(p);

    p[0] = pe70;
    p[1] = 0;
    func_01B0B788(p);

    p[0] = pe70_38;
    p[1] = pc08;
    p[2] = sub440;
    p[3] = D_01B00950;
    p[4] = D_01B00820;
    p[5] = (void *)1;
    func_01B0B7C0(p);

    p[0] = pe70_38;
    p[1] = 0;
    func_01B0B788(p);

    if (func_01B01BC8(D_01B00838) != 0) {
        p[0] = pee0;
        p[1] = &w->pos3A0;
        p[2] = 0;
        func_01B03A68(p);

        w->scale3D0.w = 0.96000004f;
        w->f834 = 1.3f;

        p[0] = w->sub20;
        p[1] = D_01B00C28;
        p[2] = sub440;
        p[3] = D_01B0E3FC;
        p[4] = D_01B0E3D0;
        p[5] = (void *)3;
        func_01B0C030(p);
    } else {
        p[0] = pee0;
        p[1] = &w->pos3A0;
        p[2] = (void *)1;
        func_01B03A68(p);

        w->pos3A0.y -= 0.2f;
        w->f834 = f1;
        w->scale3D0.w = 0.24000001f;

        p[0] = w->sub20;
        p[1] = D_01B00C28;
        p[2] = sub440;
        p[3] = D_01B0E3FC;
        p[4] = D_01B0E3D0;
        p[5] = 0;
        func_01B0C030(p);
    }

    pf80 = &D_01B00F80;
    p[0] = pf80;
    p[1] = D_01B00C28;
    func_01B06AA8(p);

    {
        float third = 1.0f / 3.0f;
        float f01 = 0.1f;
        *(volatile float *)&pf80->f30 = third;
        *(void *volatile *)&p[0] = pf80;
        *(volatile float *)&p[2] = f01;
        *(volatile float *)&pf80->f6C = third;
        *(volatile float *)&pf80->f68 = third;
        *(volatile float *)&pf80->f64 = third;
        *(volatile float *)&pf80->f60 = third;
        *(volatile float *)&pf80->f38 = third;
        *(volatile float *)&pf80->f34 = third;
    }
    p[1] = 0;
    func_01B06BD8(p);
}
