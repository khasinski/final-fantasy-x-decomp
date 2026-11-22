#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

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
} ObjF30;

typedef struct {
    u8 pad00[0x20];
    u8 sub20[0x100];
    u8 sub120[0x100];
    u8 sub220[0x100];
    u8 sub320[0x20];
    Vec4 pos340;
    u8 sub350[0x20];
    Vec4 pos370;
    u8 sub380[0x20];
    Vec4 pos3A0;
    u8 sub3B0[0x20];
    Vec4 scale3D0;
    u8 sub3E0[0x20];
    Vec4 scale400;
    u8 sub410[0x20];
    Vec4 scale430;
    u8 sub440[0x150];
    u8 sub590[0x150];
    u8 sub6E0[0x150];
    float f830;
    u16 state;
} Work9139;

typedef struct {
    void *w00;
    Work9139 *work;
} Task9139;

extern s32 D_01B007D0;
extern s32 D_01B007D8;
extern u8 D_01B007E8;
extern u8 D_01B00900[];
extern u8 D_01B00990[];
extern u8 D_01B00BA0[];
extern u8 D_01B00BB8[];
extern u8 D_01B00BD8[];
extern u8 D_01B00C40[];
extern u8 D_01B00E20[];
extern u8 D_01B00E90[];
extern ObjF30 D_01B00F30;
extern u8 D_01B0E2C0[];
extern s32 D_01B0E2EC;

extern int func_001C5E90(s32, s32, s32);

extern void func_01B03960(void *);
extern void func_01B03C00(void *);
extern void func_01B069A0(void *);
extern void func_01B06AD0(void *);
extern void func_01B06BB0(void *);
extern void func_01B07658(void *);
extern void func_01B09DC8(void *);
extern void func_01B0B680(void *);
extern void func_01B0B6B8(void *);
extern void func_01B0BF28(void *);
extern void func_01B0CED8(void *);
extern void func_01B0CF80(void *);
extern void func_01B0D2E0(void *);

void ovl_09139_1ec8(Task9139 *a0)
{
    Work9139 *w = a0->work;
    float t;
    void *p[13];

    t = w->f830 + (1.0f / 30.0f);
    w->f830 = t;
    switch (w->state) {
    case 0:
        if (t >= 1.35f) {
            /* DEBT(FAKE): pin s2/s1 to match ee-gcc register assignment for work sub-objects */
            register u8 *sub350 __asm__("$18") = w->sub350;
            register u8 *sub3E0 __asm__("$17");

            p[0] = sub350;
            p[1] = D_01B00BB8;
            func_01B07658(p);

            sub3E0 = w->sub3E0;
            p[0] = D_01B00E90;
            p[1] = &w->pos370;
            p[2] = 0;
            func_01B03960(p);
            w->pos370.y += 10.0f;

            p[0] = sub3E0;
            p[1] = D_01B00BB8;
            func_01B07658(p);

            {
                void **m16;
                {
                    /* DEBT(FAKE): pin f0/f1/v0/v1/a1 and volatile stores for 9dc8 message at 16(sp) */
                    register float f0 __asm__("$f0") = 1.0f;
                    register void *p990 __asm__("$3") = D_01B00990;
                    register float f1 __asm__("$f1") = 0.8f;
                    register void **v0 __asm__("$2");
                    __asm__("" : "+f"(f1) : "f"(f0));
                    v0 = &p[4];
                    *(void *volatile *)&p[4] = w->sub590;
                    *(volatile float *)&w->scale400.z = f0;
                    {
                        register void *pc40 __asm__("$5") = D_01B00C40;
                        __asm__("" : "+r"(p990), "+f"(f1) : "r"(v0));
                        *(volatile float *)&w->scale400.w = f1;
                        __asm__("" : "+r"(pc40) : : "memory");
                        *(void *volatile *)&v0[1] = D_01B00BB8;
                        __asm__("" : "+r"(v0) : : "memory");
                        {
                            register void **a0_ __asm__("$4") = v0;
                            __asm__("" : "+r"(a0_) : : "memory");
                            *(void *volatile *)&v0[2] = p990;
                            *(void *volatile *)&p[7] = sub350;
                            *(void *volatile *)&v0[4] = pc40;
                            m16 = a0_;
                        }
                    }
                    *(void *volatile *)&p[9] = sub3E0;
                    *(volatile float *)&w->scale400.x = f0;
                    __asm__("" : : "f"(f0) : "memory");
                    w->scale400.y = f0;
                }
                func_01B09DC8(m16);
            }

            p[0] = w->sub120;
            p[1] = D_01B00BD8;
            p[2] = w->sub590;
            p[3] = (void *)D_01B0E2EC;
            p[4] = D_01B0E2C0;
            p[5] = 0;
            func_01B0BF28(p);

            func_001C5E90(D_01B007D8, -5, 0);
            w->state = 1;
        }
        break;
    case 1:
        if (t >= 1.9f) {
            p[0] = w->sub320;
            p[1] = D_01B00BB8;
            func_01B07658(p);

            p[0] = D_01B00E90;
            p[1] = &w->pos340;
            p[2] = 0;
            func_01B03960(p);
            w->pos340.y -= 50.0f;

            p[0] = w->sub410;
            p[1] = D_01B00BB8;
            func_01B07658(p);

            w->scale430.x = 1.0f;
            w->scale430.y = 1.0f;
            w->scale430.z = 1.0f;
            w->scale430.w = 0.8f;

            p[0] = w->sub6E0;
            p[1] = D_01B00BB8;
            p[2] = D_01B00990;
            p[3] = w->sub320;
            p[4] = D_01B00C40;
            p[5] = w->sub410;
            func_01B09DC8(p);

            p[0] = w->sub220;
            p[1] = D_01B00BD8;
            p[2] = w->sub6E0;
            p[3] = (void *)D_01B0E2EC;
            p[4] = D_01B0E2C0;
            p[5] = (void *)2;
            func_01B0BF28(p);

            w->state++;
        }
        break;
    case 2:
        if (t >= 2.0f) {
            D_01B00F30.f6C = 1.0f;
            D_01B00F30.f68 = 1.0f;
            D_01B00F30.f64 = 1.0f;
            D_01B00F30.f60 = 1.0f;
            D_01B00F30.f38 = 1.0f;
            D_01B00F30.f34 = 1.0f;
            D_01B00F30.f30 = 1.0f;

            p[0] = &D_01B00F30;
            p[1] = 0;
            *(float *)&p[2] = 0.05f;
            *(float *)&p[3] = 1.0f;
            func_01B06BB0(p);

            p[12] = a0->w00;
            func_01B0CF80(&p[12]);
        }
        break;
    }
}

void ovl_09139_2230(Work9139 *w)
{
    void *p[10];

    p[0] = w;
    p[1] = (void *)ovl_09139_1ec8;
    p[2] = w;
    func_01B0CED8(p);

    p[0] = D_01B00BA0;
    p[1] = w;
    func_01B0D2E0(p);

    w->f830 = 0.0f;
    w->state = 0;

    p[0] = D_01B00E90;
    p[1] = D_01B00BB8;
    p[2] = (void *)(u32)D_01B007E8;
    *(u8 *)&p[3] = 0;
    func_01B03C00(p);

    p[0] = w->sub380;
    p[1] = D_01B00BB8;
    func_01B07658(p);

    p[0] = D_01B00E90;
    p[1] = &w->pos3A0;
    p[2] = 0;
    func_01B03960(p);

    p[0] = w->sub3B0;
    p[1] = D_01B00BB8;
    func_01B07658(p);

    {
        /* DEBT(FAKE): pin f0/f1/v0/v1/a1 and volatile stores for 9dc8 message at 16(sp) */
        register float f0 __asm__("$f0") = 1.0f;
        register void *p990 __asm__("$3") = D_01B00990;
        register float f1 __asm__("$f1") = 0.8f;
        register void **v0 __asm__("$2");
        void **m16;
        __asm__("" : "+f"(f1) : "f"(f0));
        v0 = &p[4];
        *(void *volatile *)&p[4] = w->sub440;
        *(volatile float *)&w->scale3D0.z = f0;
        {
            register void *pc40 __asm__("$5") = D_01B00C40;
            __asm__("" : "+r"(p990), "+f"(f1) : "r"(v0));
            *(volatile float *)&w->scale3D0.w = f1;
            v0[2] = p990;
            *(void *volatile *)&p[7] = w->sub380;
            v0[4] = pc40;
        }
        *(void *volatile *)&p[9] = w->sub3B0;
        *(volatile float *)&w->scale3D0.x = f0;
        *(volatile float *)&w->scale3D0.y = f0;
        v0[1] = D_01B00BB8;
        m16 = v0;
        func_01B09DC8(m16);
    }

    p[0] = w->sub20;
    p[1] = D_01B00BD8;
    p[2] = w->sub440;
    p[3] = (void *)D_01B0E2EC;
    p[4] = D_01B0E2C0;
    p[5] = (void *)1;
    func_01B0BF28(p);

    p[0] = D_01B00E20;
    p[1] = D_01B00BB8;
    p[2] = w->sub440;
    p[3] = D_01B00900;
    p[4] = (void *)D_01B007D0;
    p[5] = 0;
    func_01B0B6B8(p);

    p[0] = D_01B00E20;
    p[1] = 0;
    func_01B0B680(p);

    p[0] = D_01B00E20 + 0x38;
    p[1] = D_01B00BB8;
    p[2] = w->sub440;
    p[3] = D_01B00900;
    p[4] = (void *)D_01B007D0;
    p[5] = (void *)1;
    func_01B0B6B8(p);

    p[0] = D_01B00E20 + 0x38;
    p[1] = 0;
    func_01B0B680(p);

    p[0] = &D_01B00F30;
    p[1] = D_01B00BD8;
    func_01B069A0(p);

    D_01B00F30.f6C = 1.0f / 3.0f;
    D_01B00F30.f68 = 1.0f / 3.0f;
    D_01B00F30.f64 = 1.0f / 3.0f;
    D_01B00F30.f60 = 1.0f / 3.0f;
    D_01B00F30.f38 = 1.0f / 3.0f;
    D_01B00F30.f34 = 1.0f / 3.0f;
    D_01B00F30.f30 = 1.0f / 3.0f;

    p[0] = &D_01B00F30;
    p[1] = 0;
    *(float *)&p[2] = 0.1f;
    func_01B06AD0(p);
}
