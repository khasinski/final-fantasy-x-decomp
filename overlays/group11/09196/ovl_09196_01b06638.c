#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    s32 f1C;                /* 0x1C */
    s32 f20;                /* 0x20 */
    void *f24;              /* 0x24 */
    void *f28;              /* 0x28 */
    void *f2C;              /* 0x2C */
    u8 f30[0x30];           /* 0x30 */
    float f60;              /* 0x60 */
    float f64;              /* 0x64 */
    float f68;              /* 0x68 */
    u8 pad6C[0x14];
    u8 f80[0x30];           /* 0x80 */
    s32 fB0;                /* 0xB0 */
    s32 fB4;                /* 0xB4 */
    s32 fB8;                /* 0xB8 */
    u8 padBC[0x14];
    u8 fD0[0x20];           /* 0xD0 */
    float fF0;              /* 0xF0 */
    float fF4;              /* 0xF4 */
    float fF8;              /* 0xF8 */
    float fFC;              /* 0xFC */
    u8 f100[0x20];          /* 0x100 */
    float f120;             /* 0x120 */
    float f124;             /* 0x124 */
    float f128;             /* 0x128 */
    float f12C;             /* 0x12C */
    u8 f130[0x20];          /* 0x130 */
    s32 f150;               /* 0x150 */
    s32 f154;               /* 0x154 */
    s32 f158;               /* 0x158 */
    u8 pad15C[4];
    u8 f160[0x20];          /* 0x160 */
} Obj6638;

extern u8 g_sym_0b18[];
extern u8 g_sym_0b50[];

extern void fn_01b064e8(void);
extern void fn_01b18300(void *);
extern void fn_01b18708(void *);
extern void fn_01b11270(void *);
extern void fn_01b13678(void *);
extern void fn_01b14ac8(void *);
extern void fn_01b12fe0(void *);

extern s32 func_001A6858(s32, s32, s32);
extern void func_001AA820(s32, s32, s32);
extern void func_001AA8A0(s32, s32, s32, s32, s32, s32, s32);
extern void func_001AA908(s32, s32, s32, s32, s32);
extern void func_00117EA8(s32, s32);

#define DEF_CALL2(name) static __inline__ void call_##name(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; name(m); }
#define DEF_CALL3(name) static __inline__ void call_##name(void *a, void *b, void *c) { void *m[3]; m[0] = a; m[1] = b; m[2] = c; name(m); }
#define DEF_CALL6(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d, void *e, void *f) { void *m[6]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; m[4] = e; m[5] = f; name(m); }

DEF_CALL3(fn_01b18300)
DEF_CALL2(fn_01b18708)
DEF_CALL2(fn_01b11270)
DEF_CALL2(fn_01b13678)
DEF_CALL3(fn_01b12fe0)

static __inline__ void call_fn_01b14ac8_x(Obj6638 *s0, void *a, void *b, void *c, void *d, void *e, void *f) {
    void *m[6];
    register void **p __asm__("$5");
    register void **a0 __asm__("$4");
    register s32 c1000 __asm__("$2") = 0x1000;
    register s32 cm1000 __asm__("$3") = -0x1000;
    __asm__("" : "+r"(c1000));
    __asm__("" : "+r"(cm1000) : "r"(c1000));
    __asm__("" : "=m"(s0->f158), "+r"(c1000) : "r"(cm1000));
    *(volatile s32 *)&s0->f158 = 0;
    __asm__("" : "+r"(c1000) : "m"(s0->f158) : "$5");
    p = m;
    __asm__("" : "+r"(c1000) : "r"(p));
    *(volatile s32 *)&s0->f150 = c1000;
    __asm__("" : "+r"(cm1000) : "m"(s0->f150) : "$4");
    a0 = p;
    __asm__("" : "+r"(cm1000) : "r"(a0));
    *(volatile s32 *)&s0->f154 = cm1000;
    __asm__("" : "=m"(m[3]), "=m"(m[4]), "=m"(m[5]), "=m"(m[0]), "+r"(p) : "m"(s0->f154));
    m[3] = d;
    m[4] = e;
    m[5] = f;
    m[0] = a;
    p[1] = b;
    m[2] = c;
    fn_01b14ac8(a0);
}

void ovl_09196_01b06638(Obj6638 *s0, void *a1) {
    call_fn_01b18300(s0, fn_01b064e8, s0);
    call_fn_01b18708(g_sym_0b18, s0);

    s0->f20 = func_001A6858(1, 1, 7);
    func_001AA820(0, 1, 0);
    func_001AA820(1, 1, 1);
    func_001AA8A0(0, 0, 0, 0x200, 0x1A0, 0, -1);
    func_001AA908(0, 0, 0, 0x200, 0x1A0);
    func_001AA8A0(1, 0, 0, 0x200, 0x1A0, 1, -1);
    func_001AA908(1, 0, 0, 0x200, 0x1A0);
    func_00117EA8(0x28, 0x14);

    call_fn_01b11270(s0->fD0, g_sym_0b50);
    s0->fF0 = 1.0f;
    s0->fFC = 1.0f;
    s0->fF8 = 0.0f;
    s0->fF4 = -15.0f;

    call_fn_01b11270(s0->f100, g_sym_0b50);
    s0->f120 = 1.0f;
    s0->f124 = 1.0f;
    s0->f128 = 1.0f;
    s0->f12C = 1000.0f;

    call_fn_01b13678(s0->f130, g_sym_0b50);
    call_fn_01b14ac8_x(s0, s0->f160, g_sym_0b50, a1, s0->fD0, s0->f130, s0->f100);

    call_fn_01b12fe0(s0->f30, g_sym_0b50, s0->f160);
    s0->f60 = 0.0f;
    s0->f64 = 0.0f;
    s0->f68 = -10.0f;

    call_fn_01b12fe0(s0->f80, g_sym_0b50, s0->f160);

    *(void *volatile *)&s0->f24 = s0->f30;
    *(void *volatile *)&s0->f28 = s0->f80;
    *(void *volatile *)&s0->f2C = a1;
    *(volatile s32 *)&s0->f1C = 0;
    *(volatile s32 *)&s0->fB0 = 0;
    *(volatile s32 *)&s0->fB4 = 0;
    *(volatile s32 *)&s0->fB8 = 0;
}
