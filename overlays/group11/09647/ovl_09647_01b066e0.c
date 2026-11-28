#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 f1C;             /* 0x1C */
    u8 pad1D[3];
    u8 f20[0x38];       /* 0x20 */
    s32 f58;            /* 0x58 */
    u8 pad5C[8];
    s32 f64;            /* 0x64 */
    float f68;          /* 0x68 */
    s32 f6C;            /* 0x6C */
    u8 pad70;
    u8 f71;             /* 0x71 */
    u8 pad72[0x59E];
    s32 f610;           /* 0x610 */
    float f614;         /* 0x614 */
} Obj66E0;

typedef struct {
    void *a;
    void *b;
    s32 c;
    u8 d;
} MsgC1E0;

extern u8 g_sym_0688;
extern u8 g_sym_0a60[];
extern u8 g_sym_0a78[];
extern u8 g_sym_0b00[];
extern u8 g_sym_0b30[];
extern u8 g_sym_0cb0[];
extern u8 g_sym_12e0[];

extern void fn_01b063b8(void);
extern void fn_01b15fb8(void *);
extern void fn_01b163c0(void *);
extern void fn_01b08028(void *);
extern void fn_01b0c1e0(void *);

#define DEF_CALL2(name) static __inline__ void call_##name(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; name(m); }
#define DEF_CALL3(name) static __inline__ void call_##name(void *a, void *b, void *c) { void *m[3]; m[0] = a; m[1] = b; m[2] = c; name(m); }
#define DEF_CALL4(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d) { void *m[4]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; name(m); }

DEF_CALL3(fn_01b15fb8)
DEF_CALL2(fn_01b163c0)
DEF_CALL4(fn_01b08028)

static __inline__ void call_fn_01b0c1e0(void *a, void *b, s32 c, u8 d) {
    MsgC1E0 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    fn_01b0c1e0(&m);
}

void ovl_09647_01b066e0(Obj66E0 *s0) {
    union {
        void *p[4];
        MsgC1E0 c;
    } msg;
    register u8 *p12e0 __asm__("$17");
    register u8 *p0a78 __asm__("$18");

    msg.p[0] = s0;
    msg.p[1] = (void *)fn_01b063b8;
    msg.p[2] = s0;
    fn_01b15fb8(&msg);

    msg.p[0] = g_sym_0a60;
    msg.p[1] = s0;
    fn_01b163c0(&msg);

    s0->f1C = 0;
    msg.p[0] = s0->f20;
    msg.p[1] = g_sym_0b30;
    msg.p[2] = g_sym_0cb0;
    msg.p[3] = g_sym_0b00;
    fn_01b08028(&msg);

    {
        register MsgC1E0 *a0 __asm__("$4");
        register float f01 __asm__("$f0") = 0.1f;
        register s32 cm2000 __asm__("$5") = -0x2000;
        register float fm3 __asm__("$f1") = -3.0f;
        register u8 one_b __asm__("$2") = 1;
        register s32 one_i __asm__("$3") = 1;
        __asm__("" : "+r"(cm2000) : "f"(f01));
        __asm__("" : "+f"(fm3) : "r"(cm2000));
        __asm__("" : "+r"(one_b) : "f"(fm3));
        p12e0 = g_sym_12e0;
        p0a78 = g_sym_0a78;
        s0->f610 = 0;
        s0->f64 = 0;
        s0->f6C = 0;
        __asm__("" : "+f"(f01), "+r"(cm2000), "+r"(one_b) : "r"(p12e0), "r"(p0a78), "r"(one_i) : "memory");
        s0->f68 = f01;
        __asm__("" : "+r"(cm2000), "+r"(one_b) : "m"(s0->f68) : "$4");
        a0 = &msg.c;
        __asm__("" : "+r"(cm2000) : "r"(a0));
        s0->f58 = cm2000;
        __asm__("" : "+r"(one_b) : "m"(s0->f58));
        s0->f71 = one_b;
        __asm__("" : "+f"(fm3) : : "memory");
        s0->f614 = fm3;

        msg.c.a = p12e0;
        msg.c.b = p0a78;
        msg.c.c = one_i;
        msg.c.d = 0;
        fn_01b0c1e0(a0);
    }
    msg.c.a = p12e0 + 0xA0;
    msg.c.b = p0a78;
    msg.c.c = g_sym_0688;
    msg.c.d = 0;
    fn_01b0c1e0(&msg.c);
}
