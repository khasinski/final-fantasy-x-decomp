#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 f1C;                 /* 0x1C */
    u8 pad1D[3];
    u8 f20[0x38];           /* 0x20 */
    s32 f58;                /* 0x58 */
    u8 pad5C[8];
    s32 f64;                /* 0x64 */
    s32 f68;                /* 0x68 */
    s32 f6C;                /* 0x6C */
    u8 pad70;
    u8 f71;                 /* 0x71 */
    u8 pad72[0x59E];
    s32 f610;               /* 0x610 */
    float f614;             /* 0x614 */
} Obj6DB8;

typedef struct {
    void *f00;
    void *f04;
    s32 f08;
    u8 f0C;
} MsgC8F0;

extern u8 g_sym_0680_ptr[];
extern void *g_sym_0680;
extern u8 g_sym_0690;
extern u8 g_sym_0a60[];
extern u8 g_sym_0a78[];
extern u8 g_sym_0b00[];
extern u8 g_sym_0b30[];
extern u8 g_sym_0cb0[];
extern u8 g_sym_12e0[];
extern u8 g_sym_1380[];

extern void fn_01b06888(void);
extern void fn_01b166c8(void *);
extern void fn_01b16ad0(void *);
extern void fn_01b08738(void *);
extern void fn_01b0c8f0(void *);
extern s32 func_001CE940(void *);

typedef union {
    u8 b[4];
    float f;
} AliasF6DB8;

void ovl_09194_01b06db8(Obj6DB8 *s0) {
    union {
        void *p[4];
        MsgC8F0 c;
    } msg;

    msg.p[0] = s0;
    msg.p[1] = (void *)fn_01b06888;
    msg.p[2] = s0;
    fn_01b166c8(&msg);

    msg.p[0] = g_sym_0a60;
    msg.p[1] = s0;
    fn_01b16ad0(&msg);

    s0->f1C = 0;
    msg.p[0] = s0->f20;
    msg.p[1] = g_sym_0b30;
    msg.p[2] = g_sym_0cb0;
    msg.p[3] = g_sym_0b00;
    fn_01b08738(&msg);

    {
        u8 one_b = 1;
        float fm3 = -3.0f;
        s32 cm2000;
        u8 *p12e0;
        void *arg680;
        s0->f71 = one_b;
        s0->f610 = 0;
        cm2000 = -0x2000;
        arg680 = g_sym_0680;
        p12e0 = g_sym_12e0;
        s0->f64 = 0;
        s0->f68 = 0;
        s0->f6C = 0;
        s0->f614 = fm3;
        s0->f58 = cm2000;

        if (func_001CE940(arg680) == 0xFF) {
            register s32 one __asm__("$3") = 1;
            msg.c.f00 = p12e0;
            msg.c.f04 = g_sym_0a78;
            msg.c.f08 = one;
            msg.c.f0C = 0;
            fn_01b0c8f0(&msg);
        } else {
            s32 v = func_001CE940(g_sym_0680);
            msg.c.f00 = p12e0;
            msg.c.f04 = g_sym_0a78;
            msg.c.f08 = v;
            msg.c.f0C = 0;
            fn_01b0c8f0(&msg);
        }

        msg.c.f00 = g_sym_1380;
        msg.c.f04 = g_sym_0a78;
        msg.c.f08 = g_sym_0690;
        msg.c.f0C = 0;
        fn_01b0c8f0(&msg);
    }
}
