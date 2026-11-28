#include "common.h"

typedef struct {
    u8 pad0[0x18];
    float f18;          /* 0x18 */
    float f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    float f24;          /* 0x24 */
    float f28;          /* 0x28 */
    u8 pad2C[4];
    u8 f30[0x150];      /* 0x30 */
    u8 f180[0x148];     /* 0x180 */
    u8 *f2C8;           /* 0x2C8 */
    u8 pad2CC[4];
    u8 f2D0[0x24];      /* 0x2D0 */
    s32 f2F4;           /* 0x2F4 */
    u8 pad2F8[8];
    u8 f300[0x24];      /* 0x300 */
    s32 f324;           /* 0x324 */
    u8 pad328[0x28];
    float f350;         /* 0x350 */
    float f354;         /* 0x354 */
    float f358;         /* 0x358 */
    float f35C;         /* 0x35C */
    u8 pad360[0x20];
    float f380;         /* 0x380 */
    float f384;         /* 0x384 */
    float f388;         /* 0x388 */
    float f38C;         /* 0x38C */
    u8 f390[0x1C];      /* 0x390 */
    u8 f3AC;            /* 0x3AC */
    u8 pad3AD[3];
    float f3B0;         /* 0x3B0 */
    s32 f3B4;           /* 0x3B4 */
} Obj5EC8;

typedef struct {
    void *f00;
    Obj5EC8 *f04;
} Arg5EC8;

typedef struct {
    u8 pad0[0x160];
    void *f160;
    void *f164;
    u8 pad168[8];
    float f170;
    s32 f174;
} CamObj5EC8;

typedef struct {
    u8 pad0[0x30];
    float f30;
    float f34;
    float f38;
    float f3C;
    u8 pad40[0x20];
    float f60;
    float f64;
    float f68;
    float f6C;
} FadeObj5EC8;

typedef struct {
    u8 pad0[0x20];
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    u8 pad40[0x20];
    float f60;
    float f64;
    u8 pad68[0x10];
    u8 f78;
} BlurCtrl5EC8;

typedef struct {
    u8 pad0[0x2C];
    u32 f2C;
} EffObj5EC8;

typedef struct {
    void *f00;
    s32 f04;
    float f08;
    float f0C;
} MsgFade5EC8;

extern void *g_sym_0734;
extern u8 g_sym_0860[];
extern u8 g_sym_0890[];
extern u8 g_sym_08f0[];
extern s32 g_sym_0b18;
extern u8 g_sym_0b20[];
extern CamObj5EC8 g_sym_0b70;
extern u8 g_sym_0de0[];
extern u8 g_sym_1fc0[];
extern u8 g_sym_2170[];
extern u8 g_sym_22f0[];
extern FadeObj5EC8 g_sym_2580;
extern BlurCtrl5EC8 g_sym_2640;
extern EffObj5EC8 g_sym_2768;

extern void fn_01b08980(void *);
extern void fn_01b089e8(void *);
extern void fn_01b09018(void *);
extern void fn_01b09080(void *);
extern void fn_01b0ea18(void *);
extern void fn_01b0eaf8(void *);
extern void fn_01b118c8(void *);
extern void fn_01b12760(void *);
extern void fn_01b14740(void *);
extern void fn_01b14778(void *);
extern void fn_01b16040(void *);

extern void func_001A8128(s32, float);
extern void func_001A81E8(s32, float);
extern u32 func_00173708(void);
extern void func_001736F0(u32);
extern float func_001ACED8(void);
extern void func_001AAC18(float, float);
extern void *func_002B49A0(void *, s32, s32);
extern void func_0014D3F0(s32, s32, void *);

void ovl_09086_01b05ec8(Arg5EC8 *arg0) {
    union {
        void *p[10];
        MsgFade5EC8 mf;
    } msg;
    void *msg30;
    void *msg34;
    void *msg38;
    void *msg3C;
    Obj5EC8 *s5 = arg0->f04;
    float t18;
    float t1C;
    u32 cnt;

    t18 = s5->f18 + (1.0f / 30.0f);
    t1C = s5->f1C + (1.0f / 30.0f);
    cnt = s5->f20 + 1;
    s5->f18 = t18;
    s5->f1C = t1C;
    s5->f20 = cnt;

    switch (g_sym_0b18) {
        case 0:
            {
                register float z __asm__("$f0") = 0.0f;
                g_sym_0b70.f170 = 1.0f;
                g_sym_0b70.f160 = g_sym_08f0;
                g_sym_2580.f6C = z;
                g_sym_2580.f68 = z;
                g_sym_2580.f64 = z;
                g_sym_2580.f60 = z;
                g_sym_2580.f38 = z;
                g_sym_2580.f34 = z;
                g_sym_2580.f30 = z;
                g_sym_0b70.f164 = g_sym_08f0;
                msg.mf.f00 = &g_sym_2580;
                msg.mf.f04 = 0;
                msg.mf.f08 = 0.02f;
                fn_01b0ea18(&msg);
            }
            g_sym_0b18++;
            s5->f20 = 0;
            break;

        case 1:
            if (cnt >= 0x28) {
                g_sym_0b18 = 2;
            }
            break;

        case 2:
            s5->f384 -= 4.0f;
            break;

        case 90:
            s5->f380 = 0.0f;
            s5->f384 = 90000.0f;
            s5->f388 = 0.0f;
            s5->f350 = 0.0f;
            s5->f354 = -500.0f;
            s5->f358 = -35.0f;
            g_sym_0b70.f160 = g_sym_1fc0;
            g_sym_0b70.f164 = g_sym_0de0;
            g_sym_2580.f60 = 0.6f;
            g_sym_2580.f68 = 0.5f;
            g_sym_2580.f6C = 0.45f;
            g_sym_2580.f64 = 0.45f;
            g_sym_2580.f30 = 0.6f;
            g_sym_2580.f38 = 0.5f;
            g_sym_2580.f34 = 0.45f;
            msg.mf.f00 = &g_sym_2580;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.01f;
            fn_01b0ea18(&msg);
            g_sym_0b70.f170 = 1.0f;
            g_sym_0b18++;
            break;

        case 91:
            g_sym_0b70.f170 = 0.2f;
            s5->f1C = 0.0f;
            func_001A8128(g_sym_0b70.f174, 0.47123894f);
            s5->f3B0 = 0.95f;
            g_sym_0b18++;
            break;

        case 92:
            s5->f354 += 2.2f;
            if (t1C < 2.0f) {
                break;
            }
            s5->f3AC = (u8)(s32)((t1C - 2.0f) * 37.0f);
            if (t1C >= 3.0f) {
                g_sym_0b18++;
            }
            break;

        case 93:
            break;

        case 10:
            func_001736F0(func_00173708() | 4U);
            s5->f384 = -5.0f;
            s5->f380 = 0.0f;
            s5->f388 = 0.0f;
            s5->f350 = 0.0f;
            g_sym_0b70.f160 = g_sym_0de0;
            g_sym_0b70.f164 = g_sym_0de0;
            g_sym_0b70.f170 = 1.0f;
            func_001A8128(g_sym_0b70.f174, 0.0f);
            s5->f3AC = 1;
            s5->f2F4 = 0x1800;
            s5->f24 = 30.0f;
            s5->f28 = 1.0f;
            s5->f1C = 0.0f;
            s5->f3B0 = 1.0f;
            g_sym_0b18++;

        case 11:
            msg.p[0] = s5->f300;
            msg.p[1] = s5->f2D0;
            fn_01b118c8(&msg);
            {
                register float f28 __asm__("$f5") = s5->f28;
                register float d __asm__("$f1");
                register u8 *p180 __asm__("$3");
                register float d90 __asm__("$f2");
                register u8 c55 __asm__("$2");
                register float c20 __asm__("$f4");
                register float cm40 __asm__("$f3");
                register float c80 __asm__("$f0");
                register float c85 __asm__("$f4");
                CamObj5EC8 *cam = &g_sym_0b70;
                __asm__("" : "+f"(f28), "+r"(cam) : : "$2", "$3");
                d = 1.0f;
                p180 = s5->f180;
                d90 = 90.0f;
                __asm__("" : "+f"(d90), "+f"(d) : "r"(p180) : "$2");
                c55 = 0x55;
                __asm__("" : "+r"(c55), "+f"(d));
                d = d - f28;
                __asm__("" : "+f"(d), "+r"(c55) : : "$f4");
                c20 = 20.0f;
                __asm__("" : "+f"(c20), "+f"(d) : "r"(c55), "r"(p180) : "memory");
                cam->f164 = p180;
                s5->f3AC = c55;
                __asm__("" : "+f"(d), "+f"(d90), "+f"(c20) : "m"(s5->f3AC) : "$f3", "$f0");
                d90 = d * d90;
                __asm__("" : "+f"(d90) : "f"(d), "f"(c20) : "$f3", "$f0");
                cm40 = -40.0f;
                __asm__("" : "+f"(cm40) : "f"(d90), "f"(d), "f"(c20) : "$f0");
                d = d * c20;
                __asm__("" : "+f"(d), "+f"(cm40) : "f"(d90) : "$f0", "$f4");
                c80 = 80.0f;
                __asm__("" : "+f"(c80) : "f"(d), "f"(d90), "f"(cm40) : "$f4");
                c85 = 0.85f;
                __asm__("" : "+f"(c85) : "f"(c80), "f"(d), "f"(d90), "f"(cm40) : "memory");
                {
                    s32 st = g_sym_0b18;
                    __asm__("" : "+r"(st) : "f"(c85));
                    d90 = d90 + c80;
                    __asm__("" : "+f"(d90) : "r"(st), "f"(cm40), "f"(d));
                    cm40 = cm40 - d;
                    __asm__("" : "+f"(cm40) : "f"(d90), "f"(f28), "f"(c85));
                    f28 = f28 * c85;
                    __asm__("" : "+f"(f28), "+r"(st) : "f"(cm40), "f"(d90));
                    g_sym_0b18 = st + 1;
                    __asm__("" : : "m"(g_sym_0b18) : "memory");
                    s5->f354 = cm40;
                    __asm__("" : "+f"(d90) : "m"(s5->f354));
                    s5->f358 = d90;
                    __asm__("" : "+f"(f28) : "m"(s5->f358) : "memory");
                    s5->f28 = f28;
                }
            }
            break;

        case 12:
            break;

        case 100:
            {
                float d = 1.0f - s5->f28;
                s5->f324++;
                s5->f354 = -40.0f - d * 20.0f;
                s5->f358 = d * 90.0f + 80.0f;
                s5->f28 *= 0.85f;
                if (s5->f3AC >= 3) {
                    float r = (func_001ACED8() - 1.49f) * s5->f24;
                    func_001AAC18(r, r);
                    s5->f24 *= 0.9f;
                    s5->f3AC = (u8)(s32)((float)s5->f3AC * 0.98f);
                    break;
                }
                func_001AAC18(0.0f, 0.0f);
                s5->f3AC = 1;
                g_sym_0b18++;
            }

        case 101:
            s5->f324++;
            if (s5->f324 >= 0x80) {
                g_sym_0b18++;
            }
            break;

        case 102:
            break;

        case 20:
            func_001A8128(g_sym_0b70.f174, 0.15707964f);
            func_001A81E8(g_sym_0b70.f174, 400.0f);
            s5->f380 = -18.0f;
            s5->f384 = -55.0f;
            s5->f388 = 0.0f;
            s5->f350 = 18.0f;
            s5->f354 = -50.0f;
            s5->f358 = 68.0f;
            g_sym_0b70.f160 = g_sym_0de0;
            g_sym_0b70.f164 = g_sym_0de0;
            g_sym_0b70.f170 = 1.0f;
            s5->f3AC = 0x70;
            s5->f3B4 = 1;
            g_sym_0b18++;
            break;

        case 21:
            s5->f380 -= 0.05f;
            s5->f350 += 0.05f;
            break;

        case 60:
            {
                register u8 *p860 __asm__("$3") = g_sym_0860;
                register void *p734 __asm__("$6") = g_sym_0734;
                register void *c3 __asm__("$5") = (void *)3;
                register void **m __asm__("$2") = &msg.p[4];
                m[3] = p860;
                msg.p[8] = p734;
                m[5] = c3;
                msg.p[4] = &g_sym_2768;
                m[1] = g_sym_0b20;
                m[2] = g_sym_08f0;
                fn_01b14778(m);
            }
            g_sym_2768.f2C |= 6;
            msg.p[0] = &g_sym_2768;
            msg.p[1] = 0;
            fn_01b14740(&msg);

            func_0014D3F0(7, 2, func_002B49A0(g_sym_0734, 5, 0));

            msg30 = s5->f390;
            fn_01b08980(&msg30);

            func_001A8128(g_sym_0b70.f174, 0.0f);
            func_001A81E8(g_sym_0b70.f174, 1024.0f);

            msg.p[0] = s5->f30;
            msg.p[1] = g_sym_0b20;
            msg.p[2] = g_sym_08f0;
            msg.p[3] = g_sym_22f0;
            msg.p[4] = g_sym_2170;
            msg.p[5] = g_sym_0890;
            fn_01b12760(&msg);

            g_sym_0b70.f160 = s5->f30;
            s5->f2C8 = g_sym_2170;
            g_sym_0b70.f164 = s5->f180;
            s5->f380 = 0.0f;
            s5->f384 = 0.0f;
            s5->f388 = 0.0f;
            s5->f350 = 60.0f;
            s5->f354 = -90.0f;
            s5->f358 = -50.0f;
            g_sym_0b70.f170 = 1.0f;
            g_sym_0b18++;
            break;

        case 61:
            g_sym_0b18 = 62;
        case 62:
            g_sym_2640.f78 = 0;
            g_sym_2640.f28 = 128.0f;
            g_sym_2640.f24 = 128.0f;
            g_sym_2640.f20 = 128.0f;
            g_sym_2640.f2C = 0.0f;
            g_sym_2640.f38 = 128.0f;
            g_sym_2640.f34 = 128.0f;
            g_sym_2640.f30 = 128.0f;
            g_sym_2640.f3C = 78.0f;
            g_sym_2640.f60 = 1.0f;
            g_sym_2640.f64 = 0.975f;
            msg.mf.f00 = &g_sym_2640;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.05f;
            msg.mf.f0C = 0.05f;
            fn_01b09080(&msg);
            g_sym_0b18++;
            break;

        case 63:
            break;

        case 70:
            {
                register float c30 __asm__("$f0") = 30.0f;
                register float cm20 __asm__("$f2") = -20.0f;
                register float cm80 __asm__("$f1") = -80.0f;
                g_sym_0b18 = 71;
                s5->f358 = cm80;
                s5->f350 = c30;
                s5->f354 = cm20;
                s5->f384 = 0.0f;
            }
            break;

        case 71:
            break;

        case 80:
            g_sym_2580.f6C = 1.0f;
            g_sym_2580.f68 = 1.0f;
            g_sym_2580.f64 = 1.0f;
            g_sym_2580.f60 = 1.0f;
            g_sym_2580.f3C = 1.0f;
            g_sym_2580.f38 = 1.0f;
            g_sym_2580.f34 = 1.0f;
            g_sym_2580.f30 = 1.0f;
            msg.mf.f00 = &g_sym_2580;
            msg.mf.f04 = 0;
            msg.mf.f08 = 0.08f;
            msg.mf.f0C = 1.0f;
            fn_01b0eaf8(&msg);

            msg34 = &g_sym_2640;
            fn_01b089e8(&msg34);
            msg38 = &g_sym_2640;
            fn_01b09018(&msg38);

            {
                register s32 st __asm__("$3") = g_sym_0b18;
                g_sym_0b70.f160 = g_sym_0de0;
                g_sym_0b70.f164 = g_sym_0de0;
                s5->f380 = 0.0f;
                s5->f384 = -90.0f;
                s5->f388 = 0.0f;
                s5->f350 = 80.0f;
                s5->f354 = 50.0f;
                s5->f358 = -100.0f;
                g_sym_0b18 = st + 1;
            }
            break;

        case 81:
            g_sym_0b18 = 82;
            break;

        case 82:
            break;

        case 110:
            func_001A81E8(g_sym_0b70.f174, 1024.0f);
            func_001AAC18(0.0f, 0.0f);
            s5->f380 = 0.0f;
            s5->f384 = -70.0f;
            s5->f388 = 0.0f;
            s5->f350 = 40.0f;
            s5->f354 = -120.0f;
            s5->f358 = -50.0f;
            g_sym_0b70.f170 = 0.1f;
            s5->f20 = 0;
            g_sym_0b18++;
            g_sym_0b70.f160 = g_sym_0de0;
            g_sym_0b70.f164 = g_sym_0de0;
            s5->f28 = 1.0f;
            break;

        case 111:
            if (cnt >= 0xF) {
                s5->f358 = s5->f28 * 75.0f + -125.0f;
                s5->f28 *= 0.9f;
            }
            break;

        case 10000:
            msg3C = arg0->f00;
            fn_01b16040(&msg3C);
            break;
    }
}
