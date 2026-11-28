#include "common.h"

typedef struct {
    u8 pad0[0x18];
    float f18;          /* 0x18 */
    float f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    u8 pad24[0x0C];
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
    u8 f300[0x30];      /* 0x300 */
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
    u8 pad3B4[0x0C];
    u8 f3C0[0x10];      /* 0x3C0 */
} Obj6780;

typedef struct {
    void *f00;          /* 0x00 */
    Obj6780 *f04;       /* 0x04 */
} Arg6780;

typedef struct {
    u8 pad0[0x160];
    void *f160;         /* 0x160 */
    u8 *f164;           /* 0x164 */
    u8 pad168[8];
    float f170;         /* 0x170 */
    s32 f174;           /* 0x174 */
} CamObj6780;

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
} FadeObj6780;

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
} BlurCtrl6780;

typedef struct {
    void *f00;
    s32 f04;
    float f08;
    float f0C;
} MsgFade6780;

extern void *g_sym_0734;
extern s32 g_sym_0740;
extern u8 g_sym_0750;
extern u8 g_sym_0860[];
extern u8 g_sym_0890[];
extern u8 g_sym_08f0[];
extern s32 g_sym_0b2c;
extern u8 g_sym_0b50[];
extern u8 g_sym_0b70[];
extern u8 g_sym_0b90[];
extern CamObj6780 g_sym_0bc0;
extern u8 g_sym_0e30[];
extern u8 g_sym_1d50[];
extern u8 g_sym_2010[];
extern u8 g_sym_2470[];
extern u8 g_sym_25f0[];
extern u8 g_sym_26e0[];
extern u8 g_sym_2830[];
extern FadeObj6780 g_sym_28d0;
extern BlurCtrl6780 g_sym_2990;

extern void fn_01b06518(void *, void *);
extern void fn_01b081a0(void *);
extern void fn_01b085e8(void *);
extern void fn_01b08670(void *);
extern void fn_01b086f8(void *);
extern void fn_01b08c80(void *);
extern void fn_01b08ce8(void *);
extern void fn_01b08d70(void *);
extern void fn_01b09fb0(void *);
extern void fn_01b0a058(void *);
extern void fn_01b0d4f8(void *);
extern void fn_01b0d628(void *);
extern void fn_01b0d708(void *);
extern void fn_01b0e1b0(void *);
extern void fn_01b0fef0(void *);
extern void fn_01b10ba8(void *);
extern void fn_01b13d60(void *);

extern void func_001CE428(s32, s32);
extern void *func_002B49A0(void *, s32, s32);
extern void func_0014D3F0(s32, s32, void *);
extern void func_001B57F0(s32, s32);
extern void func_001B5810(s32, s32);
extern void func_001B6210(s32, s32);
extern void func_001A81E8(s32, float);
extern s32 func_001AF358(void);
extern u8 *func_001E4F58(s32, s32 *);
extern void func_001CE050(s32, s32);
extern void func_001AAC18(float, float);

void ovl_09645_01b06780(Arg6780 *arg0) {
    union {
        void *p[10];
        MsgFade6780 mf;
    } msg;
    s32 count;
    void *msg34;
    void *msg38;
    void *msg3C;
    void *msg40;
    Obj6780 *fp = arg0->f04;
    u8 *p2830 = g_sym_2830;

    fp->f18 += (1.0f / 30.0f);
    fp->f1C += (1.0f / 30.0f);
    fp->f20++;

    switch (g_sym_0b2c) {
        case 60:
            func_001CE428(g_sym_0740, 0x100);
            func_0014D3F0(7, 2, func_002B49A0(g_sym_0734, 5, 0));
            func_001B57F0(g_sym_0740, 1);
            func_001B5810(g_sym_0740, 0);
            func_001B6210(g_sym_0740, 0);

            {
                register u8 *p26e0 __asm__("$3") = g_sym_26e0;
                msg.p[0] = p2830;
                msg.p[1] = p26e0;
                fn_01b0a058(&msg);
            }

            msg.p[0] = fp->f2D0;
            msg.p[1] = g_sym_0b50;
            fn_01b0fef0(&msg);

            {
                register void *p180 __asm__("$3") = fp->f180;
                register u8 *p1d50 __asm__("$20") = g_sym_1d50;
                register u8 *p0860 __asm__("$18") = g_sym_0860;
                register u8 *p0890 __asm__("$19") = g_sym_0890;
                register void **m __asm__("$2") = &msg.p[4];
                msg.p[4] = p180;
                fp->f2F0 = 0;
                fp->f2F4 = 0;
                fp->f2F8 = 0;
                msg.p[8] = fp->f2D0;
                m[1] = g_sym_0b50;
                m[2] = p1d50;
                m[3] = p0860;
                m[5] = p0890;
                fn_01b10ba8(m);
            }

            fp->f2CC = 1;
            msg.p[0] = fp->f330;
            msg.p[1] = g_sym_0b50;
            fn_01b0e1b0(&msg);
            fp->f35C = 1.0f;

            msg.p[0] = fp->f360;
            msg.p[1] = g_sym_0b50;
            fn_01b0e1b0(&msg);
            fp->f38C = 1.0f;

            msg.p[0] = &g_sym_0bc0;
            msg.p[1] = g_sym_0b50;
            msg.p[2] = g_sym_08f0;
            msg.p[3] = 0;
            msg.p[4] = 0;
            msg.p[5] = 0;
            msg.p[6] = fp->f360;
            msg.p[7] = g_sym_2010;
            msg.p[8] = fp->f330;
            msg.p[9] = g_sym_08f0;
            fn_01b08d70(&msg);
            g_sym_0bc0.f170 = 1.0f;
            func_001A81E8(g_sym_0bc0.f174, 900.0f);

            msg.p[0] = &g_sym_28d0;
            msg.p[1] = g_sym_0b90;
            fn_01b0d4f8(&msg);
            g_sym_28d0.f6C = 0.5f;
            g_sym_28d0.f68 = 0.5f;
            g_sym_28d0.f64 = 0.5f;
            g_sym_28d0.f60 = 0.5f;
            g_sym_28d0.f38 = 0.5f;
            g_sym_28d0.f34 = 0.5f;
            g_sym_28d0.f30 = 0.5f;
            msg.mf.f00 = &g_sym_28d0;
            msg.mf.f04 = 0;
            msg.mf.f08 = 1.0f;
            fn_01b0d628(&msg);

            msg.p[0] = fp->f30;
            msg.p[1] = g_sym_0b50;
            msg.p[2] = g_sym_0e30;
            msg.p[3] = g_sym_0860;
            msg.p[4] = g_sym_2470;
            msg.p[5] = g_sym_0890;
            fn_01b10ba8(&msg);

            {
                fp->f2C8 = g_sym_2470;
                fp->f380 = 0.0f;
                fp->f384 = 30.0f;
                fp->f388 = 0.0f;
                g_sym_0bc0.f160 = fp->f30;
                g_sym_0bc0.f164 = g_sym_1d50;
            }
            switch (func_001AF358()) {
                case 0x01BE0000:
                case 0x01BE0001:
                case 0x01BE0002:
                case 0x01BE0003:
                case 0x01BE0004:
                case 0x01BE0005:
                case 0x01BE0006:
                case 0x01BE0007:
                case 0x02050000:
                    fp->f350 = 30.0f;
                    fp->f354 = -90.0f;
                    fp->f358 = -70.0f;
                    break;
                default:
                    fp->f350 = 30.0f;
                    fp->f354 = -70.0f;
                    fp->f358 = -200.0f;
                    break;
            }
            {
                u8 *list = func_001E4F58(0xB, &count);
                s32 i = 0;
                register s32 n __asm__("$3");
                if ((n = count) > 0) {
                    do {
                        func_001B5810(*list++, 0);
                        i++;
                        n = count;
                    } while (i < n);
                }
            }
            g_sym_0bc0.f170 = 1.0f;
            g_sym_0b2c++;
            break;

        case 61:
            msg.p[0] = fp->f390;
            msg.p[1] = g_sym_0b70;
            fn_01b081a0(&msg);
            fp->f3AC = 0x30;
            fp->f3B0 = 1.0f;
            msg.p[0] = &g_sym_2990;
            msg.p[1] = g_sym_0b70;
            msg.p[2] = g_sym_25f0;
            msg.p[3] = g_sym_08f0;
            fn_01b08670(&msg);
            g_sym_0b2c++;
            break;

        case 62:
            fp->f384 -= 0.5f;
            g_sym_0b2c++;
            break;

        case 63:
            g_sym_2990.f78 = 0;
            g_sym_2990.f28 = 128.0f;
            g_sym_2990.f24 = 128.0f;
            g_sym_2990.f20 = 128.0f;
            g_sym_2990.f2C = 0.0f;
            g_sym_2990.f38 = 128.0f;
            g_sym_2990.f34 = 128.0f;
            g_sym_2990.f30 = 128.0f;
            g_sym_2990.f3C = 78.0f;
            g_sym_2990.f60 = 1.0f;
            g_sym_2990.f64 = 0.975f;
            msg.mf.f00 = &g_sym_2990;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.05f;
            msg.mf.f0C = 0.05f;
            fn_01b08ce8(&msg);
            fp->f384 -= 0.5f;
            g_sym_0b2c++;

        case 64:
            fp->f384 -= 0.5f;
            break;

        case 70:
            fp->f15C = g_sym_08f0;
            fp->f170 = g_sym_25f0;
            fp->f350 = 30.0f;
            fp->f354 = -20.0f;
            fp->f358 = -80.0f;
            fp->f384 = 0.0f;
            fp->f1C = 0.0f;
            g_sym_0b2c = 71;
            break;

        case 71:
            if (fp->f1C >= 2.0f) {
                msg.p[0] = p2830;
                msg.p[1] = 0;
                fn_01b09fb0(&msg);
                func_001CE050(g_sym_0750, 0xB8);
                fn_01b06518(fp->f3C0, g_sym_26e0);
                g_sym_0b2c++;
            }
            break;

        case 72:
            break;

        case 80:
            g_sym_2990.f38 = 128.0f;
            g_sym_2990.f34 = 128.0f;
            g_sym_2990.f3C = 0.0f;
            g_sym_2990.f30 = 128.0f;
            msg.mf.f00 = &g_sym_2990;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.05f;
            msg.mf.f0C = 0.05f;
            fn_01b08ce8(&msg);
            g_sym_0b2c++;
            break;

        case 81:
            g_sym_0b2c = 82;
            break;

        case 82:
            break;

        case 110:
            func_001A81E8(g_sym_0bc0.f174, 1024.0f);
            func_001AAC18(0.0f, 0.0f);
            fp->f380 = 0.0f;
            fp->f384 = -70.0f;
            fp->f388 = 0.0f;
            fp->f350 = 50.0f;
            fp->f354 = -150.0f;
            fp->f358 = -100.0f;
            g_sym_0bc0.f160 = g_sym_0e30;
            g_sym_0bc0.f164 = g_sym_1d50;
            g_sym_0bc0.f170 = 0.1f;
            g_sym_28d0.f6C = 1.0f;
            g_sym_28d0.f68 = 1.0f;
            g_sym_28d0.f64 = 1.0f;
            g_sym_28d0.f60 = 1.0f;
            g_sym_28d0.f38 = 1.0f;
            g_sym_28d0.f34 = 1.0f;
            g_sym_28d0.f30 = 1.0f;
            msg.mf.f00 = &g_sym_28d0;
            msg.mf.f04 = 0;
            msg.mf.f08 = 0.01f;
            msg.mf.f0C = 1.0f;
            fn_01b0d708(&msg);
            g_sym_0b2c++;
            break;

        case 111:
            {
                register float c128 __asm__("$f0") = 128.0f;
                register float c32 __asm__("$f3") = 32.0f;
                register float c60 __asm__("$f4") = 60.0f;
                g_sym_2990.f2C = c32;
                g_sym_2990.f38 = c128;
                g_sym_2990.f34 = c128;
                g_sym_2990.f30 = c128;
                g_sym_2990.f3C = c60;
                g_sym_2990.f60 = 0.85f;
                g_sym_2990.f64 = 0.97f;
            }
            msg.mf.f00 = &g_sym_2990;
            msg.mf.f04 = 1;
            msg.mf.f08 = 0.1f;
            msg.mf.f0C = 0.1f;
            fn_01b08ce8(&msg);
            fp->f20 = 0;
            g_sym_0b2c++;

        case 112:
            if (fp->f20 >= 0x4B) {
                g_sym_2990.f64 = 0.9f;
                g_sym_2990.f3C = 0.0f;
                msg.mf.f00 = &g_sym_2990;
                msg.mf.f04 = 1;
                msg.mf.f08 = (1.0f / 15.0f);
                msg.mf.f0C = (1.0f / 15.0f);
                fn_01b08ce8(&msg);
                fp->f20 = 0;
                g_sym_0b2c++;
            }
            break;

        case 113:
            break;

        case 10000:
            msg34 = &g_sym_2990;
            fn_01b08c80(&msg34);
            msg38 = &g_sym_2990;
            fn_01b086f8(&msg38);
            msg3C = fp->f390;
            fn_01b085e8(&msg3C);
            msg40 = arg0->f00;
            fn_01b13d60(&msg40);
            break;
    }
}
