#include "common.h"

typedef union {
    u8 b[4];
    float f;
    void *p;
    s32 i;
} Alias32_68A0;

typedef struct {
    u8 pad0[0x18];
    float f18;          /* 0x18 */
    float f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    float f24;          /* 0x24 */
    float f28;          /* 0x28 */
    u8 pad2C[4];
    u8 f30[0x12C];      /* 0x30 */
    void *f15C;         /* 0x15C */
    u8 pad160[0x10];
    void *f170;         /* 0x170 */
    u8 pad174[0x0C];
    u8 f180[0x148];     /* 0x180 */
    u8 *f2C8;           /* 0x2C8 */
    u8 f2CC;            /* 0x2CC */
    u8 pad2CD[3];
    u8 f2D0[0x20];      /* 0x2D0 */
    s32 f2F0;           /* 0x2F0 */
    s32 f2F4;           /* 0x2F4 */
    s32 f2F8;           /* 0x2F8 */
    u8 pad2FC[4];
    u8 f300[0x20];      /* 0x300 */
    s32 f320;           /* 0x320 */
    s32 f324;           /* 0x324 */
    s32 f328;           /* 0x328 */
    u8 pad32C[4];
    u8 f330[0x20];      /* 0x330 */
    float f350;         /* 0x350 */
    float f354;         /* 0x354 */
    float f358;         /* 0x358 */
    float f35C;         /* 0x35C */
    u8 f360[0x20];      /* 0x360 */
    float f380;         /* 0x380 */
    float f384;         /* 0x384 */
    float f388;         /* 0x388 */
    float f38C;         /* 0x38C */
    u8 f390[0x1C];      /* 0x390 */
    u8 f3AC;            /* 0x3AC */
    u8 pad3AD[3];
    float f3B0;         /* 0x3B0 */
    s32 f3B4;           /* 0x3B4 */
    u8 pad3B8[8];
    u8 f3C0[0x10];      /* 0x3C0 */
} Obj68A0;

typedef struct {
    void *f00;          /* 0x00 */
    Obj68A0 *f04;       /* 0x04 */
} Arg68A0;

typedef struct {
    u8 pad0[0x160];
    void *f160;         /* 0x160 */
    void *f164;         /* 0x164 */
    u8 pad168[8];
    float f170;         /* 0x170 */
    s32 f174;           /* 0x174 */
} CamObj68A0;

typedef struct {
    u8 pad0[0x30];
    float f30;          /* 0x30 */
    float f34;          /* 0x34 */
    float f38;          /* 0x38 */
    u8 pad3C[0x24];
    float f60;          /* 0x60 */
    float f64;          /* 0x64 */
    float f68;          /* 0x68 */
    float f6C;          /* 0x6C */
} FadeObj68A0;

typedef struct {
    u8 pad0[0x20];
    float f20;          /* 0x20 */
    float f24;          /* 0x24 */
    float f28;          /* 0x28 */
    float f2C;          /* 0x2C */
    float f30;          /* 0x30 */
    float f34;          /* 0x34 */
    float f38;          /* 0x38 */
    float f3C;          /* 0x3C */
    u8 pad40[0x20];
    float f60;          /* 0x60 */
    float f64;          /* 0x64 */
    u8 pad68[0x10];
    u8 f78;             /* 0x78 */
} BlurCtrl68A0;

typedef struct {
    void *f00;
    s32 f04;
    float f08;
    float f0C;
} MsgFade68A0;

typedef struct {
    void *f00;
    void *f04;
    s32 f08;
    u8 f0C;
} MsgD818;

extern void *g_sym_0734;
extern s32 g_sym_0740;
extern u8 g_sym_0750;
extern u8 g_sym_0860[];
extern u8 g_sym_0890[];
extern u8 g_sym_08f0[];
extern s32 g_sym_0b2c;
extern u8 g_sym_0b30[];
extern u8 g_sym_0b50[];
extern u8 g_sym_0b70[];
extern u8 g_sym_0b90[];
extern CamObj68A0 g_sym_0bd0;
extern float g_sym_0e04;
extern u8 g_sym_0e40[];
extern u8 g_sym_0f90[];
extern u8 g_sym_10e0[];
extern u8 g_sym_1d60[];
extern u8 g_sym_2020[];
extern u8 g_sym_2480[];
extern u8 g_sym_24b0[];
extern u8 g_sym_2600[];
extern u8 g_sym_26f0[];
extern u8 g_sym_2840[];
extern FadeObj68A0 g_sym_28e0;
extern BlurCtrl68A0 g_sym_29a0;

extern void fn_01b06638(void *, void *);
extern void fn_01b0a1f0(void *);
extern void fn_01b0a638(void *);
extern void fn_01b0a6c0(void *);
extern void fn_01b0a748(void *);
extern void fn_01b0acd0(void *);
extern void fn_01b0ad38(void *);
extern void fn_01b0be38(void *);
extern void fn_01b0ceb0(void *);
extern void fn_01b0d070(void *);
extern void fn_01b0d118(void *);
extern void fn_01b0d818(void *);
extern void fn_01b105b8(void *);
extern void fn_01b106e8(void *);
extern void fn_01b107c8(void *);
extern void fn_01b11270(void *);
extern void fn_01b13678(void *);
extern void fn_01b13c30(void *);
extern void fn_01b14ac8(void *);
extern void fn_01b183a8(void *);

extern void func_001CE428(s32, s32);
extern void func_001A81E8(s32, float);
extern void func_001A8128(s32, float);
extern u32 func_00173708(void);
extern void func_001736F0(u32);
extern void func_001B57F0(s32, s32);
extern void func_001B5810(s32, s32);
extern void func_001B6210(s32, s32);
extern void func_001CE050(s32, s32);
extern float func_001ACED8(void);
extern void func_001AAC18(float, float);
extern void func_001AAC30(s32, float, float);
extern void *func_002B49A0(void *, s32, s32);
extern void func_0014D3F0(s32, s32, void *);
extern s32 func_001AF358(void);

void ovl_09577_01b06218(Arg68A0 *arg0) {
    union {
        void *p[10];
        MsgFade68A0 mf;
        MsgD818 md;
    } msg;
    void *msg30;
    void *msg34;
    void *msg38;
    void *msg3C;
    void *msg40;
    Obj68A0 *s7 = arg0->f04;
    u8 *p2840 = g_sym_2840;
    float t18;
    float t1C;
    u32 cnt;

    t18 = s7->f18 + (1.0f / 30.0f);
    t1C = s7->f1C + (1.0f / 30.0f);
    cnt = s7->f20 + 1;
    s7->f18 = t18;
    s7->f1C = t1C;
    s7->f20 = cnt;

    switch (g_sym_0b2c) {
        case 0:
            func_001CE428(g_sym_0740, 0x100);
            msg.p[0] = s7->f2D0;
            msg.p[1] = g_sym_0b50;
            fn_01b13678(&msg);
            {
                register void *ra __asm__("$4") = s7->f180;
                register void *rc __asm__("$3") = g_sym_1d60;
                register void *rd __asm__("$5") = g_sym_0860;
                register void **m __asm__("$2");
                register void **a0 __asm__("$4");
                u8 *rf;
                __asm__("" : "+r"(ra) : : "$2");
                msg.p[4] = ra;
                m = &msg.p[4];
                __asm__("" : "+r"(m) : "m"(msg.p[4]));
                __asm__("" : "+r"(rc), "+r"(rd) : "r"(m));
                s7->f2F0 = 0;
                s7->f2F4 = 0;
                __asm__("" : "+r"(m) : "m"(s7->f2F0), "m"(s7->f2F4) : "memory");
                rf = g_sym_0890;
                s7->f2F8 = 0;
                __asm__("" : "+r"(rc), "+r"(rd), "+r"(m), "+r"(rf) : "m"(s7->f2F8));
                m[2] = rc;
                a0 = m;
                __asm__("" : "+r"(a0) : "m"(m[2]));
                m[3] = rd;
                msg.p[8] = s7->f2D0;
                m[1] = g_sym_0b50;
                m[5] = rf;
                fn_01b14ac8(a0);
            }
            s7->f2CC = 1;
            msg.p[0] = s7->f330;
            msg.p[1] = g_sym_0b50;
            fn_01b11270(&msg);
            s7->f35C = 1.0f;

            msg.p[0] = s7->f360;
            msg.p[1] = g_sym_0b50;
            fn_01b11270(&msg);
            s7->f38C = 1.0f;

            msg.p[0] = &g_sym_0bd0;
            msg.p[1] = g_sym_0b50;
            msg.p[2] = g_sym_08f0;
            msg.p[3] = 0;
            msg.p[4] = 0;
            msg.p[5] = 0;
            msg.p[6] = s7->f360;
            msg.p[7] = g_sym_2020;
            msg.p[8] = s7->f330;
            msg.p[9] = g_sym_08f0;
            fn_01b0be38(&msg);
            g_sym_0bd0.f170 = 1.0f;
            func_001A81E8(g_sym_0bd0.f174, 900.0f);

            msg.p[0] = s7->f390;
            msg.p[1] = g_sym_0b70;
            fn_01b0a1f0(&msg);
            s7->f3AC = 0x30;
            s7->f3B0 = 1.0f;

            msg.p[0] = &g_sym_29a0;
            msg.p[1] = g_sym_0b70;
            msg.p[2] = g_sym_2600;
            msg.p[3] = g_sym_08f0;
            fn_01b0a6c0(&msg);

            func_001736F0(func_00173708() & ~4U);

            msg.p[0] = &g_sym_28e0;
            msg.p[1] = g_sym_0b90;
            fn_01b105b8(&msg);

            {
                register float z __asm__("$f0") = 0.0f;
                float c12 = -15000.0f;
                register float c4 __asm__("$f3") = 4000.0f;
                register float c5 __asm__("$f2");
                register float c10 __asm__("$f1");
                __asm__("" : "+f"(c4) : "f"(c12), "f"(z) : "$f2", "$f1");
                c5 = -7000.0f;
                __asm__("" : "+f"(c5) : : "$f1");
                c10 = -10000.0f;
                __asm__("" : "+f"(c10), "+f"(c12), "+f"(c4), "+f"(z), "+f"(c5) : : "memory");
                s7->f384 = c12;
                s7->f350 = c4;
                s7->f354 = c5;
                s7->f358 = c10;
                s7->f380 = z;
                s7->f388 = z;
                g_sym_0bd0.f170 = 1.0f;
                {
                    register float c02 __asm__("$f5");
                    __asm__("" : "+f"(z) : "m"(g_sym_0bd0.f170) : "$f5");
                    c02 = 0.02f;
                    __asm__("" : "+f"(c02), "+f"(z));
                    g_sym_28e0.f30 = z;
                    __asm__("" : "+f"(c02), "+f"(z) : "m"(g_sym_28e0.f30) : "memory");
                    msg.mf.f00 = &g_sym_28e0;
                    __asm__("" : "+f"(c02), "+f"(z) : "m"(msg.mf.f00) : "memory");
                    msg.mf.f08 = c02;
                    g_sym_0bd0.f160 = g_sym_26f0;
                    g_sym_0bd0.f164 = g_sym_26f0;
                    __asm__("" : "+f"(z) : "m"(g_sym_0bd0.f164) : "memory");
                    g_sym_28e0.f6C = z;
                    g_sym_28e0.f68 = z;
                    g_sym_28e0.f64 = z;
                    g_sym_28e0.f60 = z;
                    g_sym_28e0.f38 = z;
                    __asm__("" : "+f"(z) : "m"(g_sym_28e0.f38) : "memory");
                    g_sym_28e0.f34 = z;
                }
                msg.mf.f04 = 0;
                fn_01b106e8(&msg);
            }

            func_001B57F0(g_sym_0740, 1);
            func_001B5810(g_sym_0740, 0);
            func_001B6210(g_sym_0740, 0);

            msg.md.f00 = p2840;
            msg.md.f04 = g_sym_0b30;
            msg.md.f08 = g_sym_0750;
            msg.md.f0C = 0;
            fn_01b0d818(&msg);

            msg.p[0] = p2840;
            msg.p[1] = g_sym_26f0;
            fn_01b0d118(&msg);

            msg30 = p2840;
            fn_01b0ceb0(&msg30);

            g_sym_0b2c++;
            s7->f20 = 0;
            break;

        case 1:
            s7->f384 += 50.0f;
            s7->f358 -= 600.0f;
            if (cnt >= 0x28) {
                s7->f384 = g_sym_0e04 * 1000.0f;
                g_sym_0b2c = 2;
                g_sym_0bd0.f160 = g_sym_26f0;
                g_sym_0bd0.f170 = 0.003f;
            }
            break;

        case 2:
            break;

        case 90:
            s7->f3AC = 1;
            func_001A81E8(g_sym_0bd0.f174, 650.0f);
            s7->f380 = 0.0f;
            s7->f384 = 90000.0f;
            s7->f388 = 0.0f;
            s7->f350 = 35.0f;
            s7->f354 = -520.0f;
            s7->f358 = 35.0f;
            g_sym_0bd0.f160 = g_sym_2020;
            g_sym_0bd0.f164 = g_sym_0e40;
            g_sym_0bd0.f170 = 1.0f;
            g_sym_0b2c++;
            break;

        case 91:
            g_sym_28e0.f6C = 0.5f;
            g_sym_28e0.f68 = 0.5f;
            g_sym_28e0.f64 = 0.5f;
            g_sym_28e0.f60 = 0.5f;
            g_sym_28e0.f38 = 0.5f;
            g_sym_28e0.f34 = 0.5f;
            g_sym_28e0.f30 = 0.5f;
            msg.mf.f00 = &g_sym_28e0;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.02f;
            fn_01b106e8(&msg);
            g_sym_0bd0.f170 = 0.2f;
            s7->f1C = 0.0f;
            func_001A8128(g_sym_0bd0.f174, 0.47123894f);
            s7->f3B0 = 0.95f;
            g_sym_0b2c++;
            break;

        case 92:
            s7->f354 += 2.2f;
            if (t1C < 2.0f) {
                break;
            }
            s7->f3AC = (u8)(s32)((t1C - 2.0f) * 37.0f);
            if (t1C >= 3.0f) {
                g_sym_0b2c++;
            }
            break;

        case 93:
            break;

        case 10:
            func_001736F0(func_00173708() | 4U);
            func_001A81E8(g_sym_0bd0.f174, 330.0f);
            s7->f3AC = 0;
            s7->f2F4 -= 0x4000;
            s7->f384 = -5.0f;
            s7->f380 = 0.0f;
            s7->f388 = 0.0f;
            s7->f350 = 0.0f;
            g_sym_0bd0.f160 = g_sym_1d60;
            g_sym_0bd0.f164 = g_sym_1d60;
            g_sym_0bd0.f170 = 1.0f;
            func_001A8128(g_sym_0bd0.f174, 0.0f);
            s7->f3AC = 0x55;
            s7->f24 = 30.0f;
            s7->f1C = 0.0f;
            s7->f28 = 1.0f;
            s7->f3B0 = 1.0f;
            g_sym_0b2c++;
        case 11:
            msg.p[0] = s7->f300;
            msg.p[1] = s7->f2D0;
            fn_01b13c30(&msg);
            {
                float d = 1.0f - s7->f28;
                s7->f320 = 0;
                s7->f324 = 0;
                s7->f328 = 0;
                g_sym_0bd0.f164 = s7->f180;
                s7->f354 = -40.0f - d * 20.0f;
                s7->f358 = d * 40.0f + 30.0f;
                s7->f28 *= 0.85f;
                g_sym_0b2c++;
            }
            break;

        case 12:
            break;

        case 100:
            if (func_001AF358() == 0x024B0005) {
                s7->f2F4 = 0;
            }
            g_sym_0b2c++;
        case 101:
            {
                float d = 1.0f - s7->f28;
                s7->f324++;
                s7->f354 = -40.0f - d * 20.0f;
                s7->f358 = d * 40.0f + 30.0f;
                s7->f28 *= 0.9f;
                if (s7->f3AC >= 3) {
                    float r = (func_001ACED8() - 1.49f) * s7->f24;
                    func_001AAC18(r, r);
                    s7->f24 *= 0.9f;
                    s7->f3AC = (u8)(s32)((float)s7->f3AC * 0.98f);
                    break;
                }
                func_001AAC18(0.0f, 0.0f);
                s7->f3AC = 1;
                g_sym_0b2c++;
            }
        case 102:
            s7->f324++;
            if (s7->f324 >= 0x80) {
                g_sym_0b2c++;
            }
            break;

        case 103:
            break;

        case 20:
            func_001A81E8(g_sym_0bd0.f174, 650.0f);
            s7->f384 = -50.0f;
            s7->f354 = -55.0f;
            s7->f358 = 70.0f;
            s7->f380 = 0.0f;
            s7->f388 = 0.0f;
            s7->f350 = 0.0f;
            g_sym_0bd0.f160 = g_sym_0e40;
            g_sym_0bd0.f164 = g_sym_0e40;
            g_sym_0bd0.f170 = 1.0f;
            s7->f3AC = 0x70;
            s7->f3B4 = 1;
            g_sym_0b2c++;
            break;

        case 21:
            break;

        case 30:
            {
                float c10 = -10.0f;
                float c7500 = -7500.0f;
                float c45000 = -45000.0f;
                s7->f358 = c45000;
                s7->f384 = c10;
                s7->f354 = c7500;
                s7->f380 = 0.0f;
                s7->f388 = 0.0f;
                s7->f350 = 0.0f;
                g_sym_0bd0.f170 = 1.0f;
                g_sym_0bd0.f160 = g_sym_0e40;
                g_sym_0bd0.f164 = g_sym_24b0;
                s7->f3AC = 1;
                s7->f3B4 = 0;
                s7->f28 = 20.0f;
                func_001AAC30(g_sym_0bd0.f174, 20.0f, 0.0f);
                func_001A81E8(g_sym_0bd0.f174, 850.0f);
                g_sym_0b2c++;
            }
            break;

        case 31:
            s7->f28 -= 0.5f;
            func_001AAC30(g_sym_0bd0.f174, s7->f28, 0.0f);
            break;

        case 40:
            s7->f380 = -100.0f;
            s7->f384 = 0.0f;
            s7->f388 = 120.0f;
            s7->f350 = 30.0f;
            s7->f354 = -10.0f;
            s7->f358 = 160.0f;
            s7->f3B4 = 0;
            g_sym_0bd0.f160 = g_sym_10e0;
            g_sym_0bd0.f164 = g_sym_10e0;
            g_sym_0bd0.f170 = 1.0f;
            func_001AAC18(0.0f, 0.0f);
            g_sym_0b2c++;
            break;

        case 50:
            s7->f380 = 100.0f;
            s7->f384 = 0.0f;
            s7->f388 = 100.0f;
            s7->f350 = -30.0f;
            s7->f354 = -10.0f;
            s7->f358 = 160.0f;
            g_sym_0bd0.f160 = g_sym_0f90;
            g_sym_0bd0.f164 = g_sym_0f90;
            g_sym_0bd0.f170 = 1.0f;
            g_sym_0b2c = 51;
            break;

        case 41:
        case 51:
            s7->f388 -= 4.0f;
            break;

        case 60:
            func_0014D3F0(7, 2, func_002B49A0(g_sym_0734, 5, 0));
            g_sym_0b2c++;
        case 61:
            msg.p[0] = s7->f30;
            msg.p[1] = g_sym_0b50;
            msg.p[2] = g_sym_0e40;
            msg.p[3] = g_sym_0860;
            msg.p[4] = g_sym_2480;
            msg.p[5] = g_sym_0890;
            fn_01b14ac8(&msg);
            {
                CamObj68A0 *p0bd0 = &g_sym_0bd0;
                u8 *p1d60 = g_sym_1d60;
                s7->f380 = 0.0f;
                s7->f384 = 30.0f;
                s7->f388 = 0.0f;
                p0bd0->f160 = s7->f30;
                s7->f2C8 = g_sym_2480;
                p0bd0->f164 = p1d60;
            }
            s7->f350 = 30.0f;
            s7->f354 = -70.0f;
            s7->f358 = -150.0f;
            g_sym_0bd0.f170 = 1.0f;
            g_sym_0b2c++;
            break;

        case 62:
            g_sym_0b2c = 63;
            s7->f384 -= 0.5f;
            break;

        case 63:
            {
                register float c128 __asm__("$f0") = 128.0f;
                g_sym_29a0.f78 = 0;
                g_sym_29a0.f28 = c128;
                g_sym_29a0.f24 = c128;
                g_sym_29a0.f20 = c128;
                g_sym_29a0.f2C = 0.0f;
                g_sym_29a0.f38 = c128;
                g_sym_29a0.f34 = c128;
                g_sym_29a0.f30 = c128;
                g_sym_29a0.f3C = 78.0f;
                g_sym_29a0.f60 = 1.0f;
                g_sym_29a0.f64 = 0.975f;
            }
            msg.mf.f00 = &g_sym_29a0;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.05f;
            msg.mf.f0C = 0.05f;
            fn_01b0ad38(&msg);
            s7->f384 -= 0.5f;
            g_sym_0b2c++;
        case 64:
            s7->f384 -= 0.5f;
            break;

        case 70:
            g_sym_0b2c = 71;
            s7->f15C = g_sym_08f0;
            s7->f170 = g_sym_2600;
            s7->f350 = 30.0f;
            s7->f354 = -20.0f;
            s7->f358 = -80.0f;
            s7->f384 = 0.0f;
            s7->f1C = 0.0f;
            break;

        case 71:
            if (t1C >= 2.0f) {
                g_sym_0b2c = 72;
            }
            break;

        case 72:
            break;

        case 80:
            g_sym_29a0.f38 = 128.0f;
            g_sym_29a0.f34 = 128.0f;
            g_sym_29a0.f3C = 0.0f;
            g_sym_29a0.f30 = 128.0f;
            msg.mf.f00 = &g_sym_29a0;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.05f;
            msg.mf.f0C = 0.05f;
            fn_01b0ad38(&msg);
            g_sym_0b2c++;
            break;

        case 81:
            g_sym_0b2c = 82;
            break;

        case 82:
            break;

        case 110:
            func_001A81E8(g_sym_0bd0.f174, 1024.0f);
            func_001AAC18(0.0f, 0.0f);
            s7->f380 = 0.0f;
            s7->f384 = -70.0f;
            s7->f388 = 0.0f;
            s7->f350 = 50.0f;
            s7->f354 = -150.0f;
            s7->f358 = -100.0f;
            g_sym_0bd0.f160 = g_sym_0e40;
            g_sym_0bd0.f164 = g_sym_1d60;
            g_sym_0bd0.f170 = 0.1f;
            g_sym_28e0.f6C = 1.0f;
            g_sym_28e0.f68 = 1.0f;
            g_sym_28e0.f64 = 1.0f;
            g_sym_28e0.f60 = 1.0f;
            g_sym_28e0.f38 = 1.0f;
            g_sym_28e0.f34 = 1.0f;
            g_sym_28e0.f30 = 1.0f;
            msg.mf.f00 = &g_sym_28e0;
            msg.mf.f04 = 0;
            msg.mf.f08 = 0.01f;
            msg.mf.f0C = 1.0f;
            fn_01b107c8(&msg);
            g_sym_0b2c++;
            break;

        case 111:
            {
                register float c128 __asm__("$f0") = 128.0f;
                register float c32 __asm__("$f3") = 32.0f;
                register float c60 __asm__("$f4") = 60.0f;
                g_sym_29a0.f2C = c32;
                g_sym_29a0.f38 = c128;
                g_sym_29a0.f34 = c128;
                g_sym_29a0.f30 = c128;
                g_sym_29a0.f3C = c60;
                g_sym_29a0.f60 = 0.85f;
                g_sym_29a0.f64 = 0.97f;
            }
            msg.mf.f00 = &g_sym_29a0;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.1f;
            msg.mf.f0C = 0.1f;
            fn_01b0ad38(&msg);
            s7->f20 = 0;
            g_sym_0b2c++;
        case 112:
            if (s7->f20 >= 0x4B) {
                g_sym_29a0.f64 = 0.9f;
                g_sym_29a0.f3C = 0.0f;
                msg.mf.f00 = &g_sym_29a0;
                msg.mf.f04 = 1;
                msg.mf.f08 = (1.0f / 15.0f);
                msg.mf.f0C = (1.0f / 15.0f);
                fn_01b0ad38(&msg);
                s7->f20 = 0;
                g_sym_0b2c++;
            }
            break;

        case 113:
            break;

        case 10000:
            msg34 = &g_sym_29a0;
            fn_01b0acd0(&msg34);
            msg38 = &g_sym_29a0;
            fn_01b0a748(&msg38);
            msg3C = s7->f390;
            fn_01b0a638(&msg3C);
            msg40 = arg0->f00;
            fn_01b183a8(&msg40);
            break;
    }
}
