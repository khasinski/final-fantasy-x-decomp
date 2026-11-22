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
} ObjF80;

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
    float f834;
    u16 state;
} Work9138;

typedef struct {
    void *w00;
    Work9138 *work;
} Task9138;

extern s32 D_01B00820;
extern s32 D_01B00828;
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
extern s32 D_01B0E3FC;

extern int func_001C5E90(s32, s32, s32);
extern void func_002DD0B0(Vec4 *, Vec4 *);

extern int func_01B01BC8(u32);
extern void func_01B03A68(void *);
extern void func_01B03D08(void *);
extern void func_01B06AA8(void *);
extern void func_01B06BD8(void *);
extern void func_01B06CB8(void *);
extern void func_01B07760(void *);
extern void func_01B09ED0(void *);
extern void func_01B0B788(void *);
extern void func_01B0B7C0(void *);
extern void func_01B0C030(void *);
extern void func_01B0CFE0(void *);
extern void func_01B0D088(void *);
extern void func_01B0D3E8(void *);

void ovl_09138_1f18(Task9138 *a0)
{
    Work9138 *w = a0->work;
    float t;
    void *p[13];

    t = w->f830 + (1.0f / 30.0f);
    w->f830 = t;
    switch (w->state) {
    case 0:
        if (t >= w->f834) {
            register u8 *sub350 __asm__("$19") = w->sub350;
            register u8 *sub3E0 __asm__("$17");

            p[0] = sub350;
            p[1] = D_01B00C08;
            func_01B07760(p);

            func_002DD0B0(&w->pos370, &w->pos3A0);
            if (func_01B01BC8(D_01B00838) != 0) {
                w->pos370.y += 20.0f;
            } else {
                w->pos370.y += 4.0f;
            }

            sub3E0 = w->sub3E0;
            p[0] = sub3E0;
            p[1] = D_01B00C08;
            func_01B07760(p);

            {
                void **m16;
                {
                    register float f0 __asm__("$f0") = 1.0f;
                    register void *p9e0 __asm__("$3") = D_01B009E0;
                    register float f1 __asm__("$f1") = 0.8f * 0.36f;
                    register void **v0 __asm__("$2");
                    __asm__("" : "+f"(f1) : "f"(f0));
                    v0 = &p[4];
                    *(void *volatile *)&p[4] = w->sub590;
                    *(volatile float *)&w->scale400.z = f0;
                    {
                        register void *pc90 __asm__("$5") = D_01B00C90;
                        __asm__("" : "+r"(p9e0), "+f"(f1) : "r"(v0));
                        *(volatile float *)&w->scale400.w = f1;
                        __asm__("" : "+r"(pc90) : : "memory");
                        *(void *volatile *)&v0[1] = D_01B00C08;
                        __asm__("" : "+r"(v0) : : "memory");
                        {
                            register void **a0_ __asm__("$4") = v0;
                            __asm__("" : "+r"(a0_) : : "memory");
                            *(void *volatile *)&v0[2] = p9e0;
                            *(void *volatile *)&p[7] = sub350;
                            *(void *volatile *)&v0[4] = pc90;
                            m16 = a0_;
                        }
                    }
                    *(void *volatile *)&p[9] = sub3E0;
                    *(volatile float *)&w->scale400.x = f0;
                    __asm__("" : : "f"(f0) : "memory");
                    w->scale400.y = f0;
                }
                func_01B09ED0(m16);
            }

            p[0] = w->sub120;
            p[1] = D_01B00C28;
            p[2] = w->sub590;
            p[3] = (void *)D_01B0E3FC;
            p[4] = D_01B0E3D0;
            p[5] = (void *)2;
            func_01B0C030(p);

            func_001C5E90(D_01B00828, -5, 0);
            w->state = 1;
        }
        break;
    case 1:
        if (t >= 1.9f) {
            p[0] = w->sub320;
            p[1] = D_01B00C08;
            func_01B07760(p);

            func_002DD0B0(&w->pos340, &w->pos3A0);
            w->pos340.y -= 50.0f;

            p[0] = w->sub410;
            p[1] = D_01B00C08;
            func_01B07760(p);

            w->scale430.x = 1.0f;
            w->scale430.y = 1.0f;
            w->scale430.z = 1.0f;
            w->scale430.w = 0.8f * 0.2f;

            p[0] = w->sub6E0;
            p[1] = D_01B00C08;
            p[2] = D_01B009E0;
            p[3] = w->sub320;
            p[4] = D_01B00C90;
            p[5] = w->sub410;
            func_01B09ED0(p);

            p[0] = w->sub220;
            p[1] = D_01B00C28;
            p[2] = w->sub6E0;
            p[3] = (void *)D_01B0E3FC;
            p[4] = D_01B0E3D0;
            p[5] = (void *)1;
            func_01B0C030(p);

            w->state++;
        }
        break;
    case 2:
        if (t >= 2.0f) {
            D_01B00F80.f6C = 1.0f;
            D_01B00F80.f68 = 1.0f;
            D_01B00F80.f64 = 1.0f;
            D_01B00F80.f60 = 1.0f;
            D_01B00F80.f38 = 1.0f;
            D_01B00F80.f34 = 1.0f;
            D_01B00F80.f30 = 1.0f;

            p[0] = &D_01B00F80;
            p[1] = 0;
            *(float *)&p[2] = 0.05f;
            *(float *)&p[3] = 1.0f;
            func_01B06CB8(p);

            p[12] = a0->w00;
            func_01B0D088(&p[12]);
        }
        break;
    }
}
