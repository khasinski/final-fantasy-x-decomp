#include "common.h"

typedef struct {
    u8 pad0[0x18];
    float f18;              /* 0x18 */
    float f1C;              /* 0x1C */
    u8 pad20[0x160];
    u8 f180[0x14C];         /* 0x180 */
    u8 f2CC;                /* 0x2CC */
    u8 pad2CD[3];
    u8 f2D0[0x20];          /* 0x2D0 */
    s32 f2F0;               /* 0x2F0 */
    s32 f2F4;               /* 0x2F4 */
    s32 f2F8;               /* 0x2F8 */
    u8 pad2FC[0x34];
    u8 f330[0x20];          /* 0x330 */
    float f350[3];          /* 0x350 */
    float f35C;             /* 0x35C */
    u8 f360[0x20];          /* 0x360 */
    float f380[3];          /* 0x380 */
    float f38C;             /* 0x38C */
    u8 f390[0x1C];          /* 0x390 */
    u8 f3AC;                /* 0x3AC */
} Obj6A10;

extern u8 g_sym_0860[];
extern u8 g_sym_0890[];
extern u8 g_sym_08f0[];
extern u8 g_sym_0b00[];
extern s32 g_sym_0b18;
extern u8 g_sym_0b20[];
extern u8 g_sym_0b40[];
extern u8 g_sym_0b70[];
extern u8 g_sym_0de0[];
extern u8 g_sym_1fc0[];
extern u8 g_sym_22f0[];
extern u8 g_sym_2580[];
extern u8 g_sym_2640[];

extern void fn_01b05ec8(void);
extern void fn_01b15f98(void *);
extern void fn_01b163a0(void *);
extern void fn_01b11310(void *);
extern void fn_01b12760(void *);
extern void fn_01b0f5a0(void *);
extern void fn_01b0a180(void *);
extern void fn_01b08538(void *);
extern void fn_01b08a08(void *);
extern void fn_01b0e8e8(void *);

extern void func_001A9FE8(s32, float *);
extern u32 func_00173708(void);
extern void func_001736F0(u32);

#define DEF_CALL2(name) static __inline__ void call_##name(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; name(m); }
#define DEF_CALL3(name) static __inline__ void call_##name(void *a, void *b, void *c) { void *m[3]; m[0] = a; m[1] = b; m[2] = c; name(m); }
#define DEF_CALL4(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d) { void *m[4]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; name(m); }
#define DEF_CALL6(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d, void *e, void *f) { void *m[6]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; m[4] = e; m[5] = f; name(m); }
#define DEF_CALL10(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h, void *i, void *j) { void *m[10]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; m[4] = e; m[5] = f; m[6] = g; m[7] = h; m[8] = i; m[9] = j; name(m); }

DEF_CALL3(fn_01b15f98)
DEF_CALL2(fn_01b163a0)
DEF_CALL2(fn_01b11310)
DEF_CALL2(fn_01b0f5a0)
DEF_CALL10(fn_01b0a180)
DEF_CALL2(fn_01b08538)
DEF_CALL4(fn_01b08a08)
DEF_CALL2(fn_01b0e8e8)

static __inline__ void call_fn_01b12760_x(Obj6A10 *s0, void *a, void *b, void *c, void *d, void *e, void *f) {
    void *m[6];
    register void *ra __asm__("$4") = a;
    register void *rc __asm__("$3") = c;
    register void *rd __asm__("$5") = d;
    register void **p __asm__("$2");
    register void **a0 __asm__("$4");
    register void *rf __asm__("$6");
    __asm__("" : "+r"(ra) : : "$2");
    m[0] = ra;
    p = m;
    __asm__("" : "+r"(p) : "m"(m[0]));
    __asm__("" : "+r"(rc), "+r"(rd) : "r"(p));
    s0->f2F0 = 0;
    s0->f2F4 = 0;
    __asm__("" : "+r"(p) : "m"(s0->f2F0), "m"(s0->f2F4) : "memory");
    rf = f;
    s0->f2F8 = 0;
    __asm__("" : "+r"(rc), "+r"(rd), "+r"(p), "+r"(rf) : "m"(s0->f2F8));
    p[2] = rc;
    a0 = p;
    __asm__("" : "+r"(a0) : "m"(p[2]));
    p[3] = rd;
    m[4] = e;
    p[1] = b;
    p[5] = rf;
    fn_01b12760(a0);
}

void ovl_09086_01b06a10(Obj6A10 *s0) {
    call_fn_01b15f98(s0, fn_01b05ec8, s0);
    call_fn_01b163a0(g_sym_0b00, s0);

    call_fn_01b11310(s0->f2D0, g_sym_0b20);
    call_fn_01b12760_x(s0, s0->f180, g_sym_0b20, g_sym_0de0, g_sym_0860, s0->f2D0, g_sym_0890);

    s0->f2CC = 1;
    call_fn_01b0f5a0(s0->f330, g_sym_0b20);
    func_001A9FE8(1, s0->f350);
    s0->f35C = 1.0f;

    call_fn_01b0f5a0(s0->f360, g_sym_0b20);
    func_001A9FE8(0, s0->f380);
    s0->f38C = 1.0f;

    call_fn_01b0a180(g_sym_0b70, g_sym_0b20, g_sym_08f0, 0, 0, 0, s0->f360, g_sym_1fc0, s0->f330, g_sym_08f0);
    *(float *)(g_sym_0b70 + 0x170) = 1.0f;

    call_fn_01b08538(s0->f390, g_sym_0b40);
    s0->f3AC = 1;

    call_fn_01b08a08(g_sym_2640, g_sym_0b40, g_sym_22f0, g_sym_08f0);

    func_001736F0(func_00173708() & ~4U);

    call_fn_01b0e8e8(g_sym_2580, g_sym_0b40);

    {
        register float z __asm__("$f0") = 0.0f;
        *(volatile float *)&s0->f18 = z;
        *(volatile float *)&s0->f1C = z;
    }
    g_sym_0b18 = 0;
}
