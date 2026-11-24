#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    u8 pad1C[0x8];
    void *p24;          /* 0x24 */
    u8 pad28[0x8];
    u8 sub30[0xB0];     /* 0x30 */
    u8 subE0[0x30];     /* 0xE0 */
    float f110;         /* 0x110 */
    float f114;         /* 0x114 */
    float f118;         /* 0x118 */
} Sub4080;

typedef struct {
    u8 pad00[0x2C];
    float f2C;
} Inner4080;

typedef struct {
    u8 pad00[0x144];
    Inner4080 *p144;
} Param4080;

extern void *D_01B007A8;
extern u8 D_01B00B80[];
extern u8 D_01B00B98[];
extern void *D_00303550;

extern void *func_002B49A0(void *, int, int);
extern void func_01B03E98(void *);
extern void func_01B05C78(void *);
extern void func_01B05E38(void *);
extern void func_01B0B790(void *);
extern void func_01B0FBF0(void *);
extern void func_01B0FFF8(void *);

static inline void call_FBF0(void *a, void *b, void *c)
{
    struct { void *a, *b, *c; } arg;
    arg.a = a; arg.b = b; arg.c = c;
    func_01B0FBF0(&arg);
}

static inline void call_FFF8(void *a, void *b)
{
    struct { void *a, *b; } arg;
    arg.a = a; arg.b = b;
    func_01B0FFF8(&arg);
}

static inline void call_B790(void *a, void *b, void *c)
{
    struct { void *a, *b, *c; } arg;
    arg.a = a; arg.b = b; arg.c = c;
    func_01B0B790(&arg);
}

static inline void call_5E38(void *a, void *b, void *c, void *d, void *e, void *f)
{
    struct { void *a, *b, *c, *d, *e, *f; } arg;
    arg.d = d; arg.b = b; arg.e = e; arg.a = a; arg.c = c; arg.f = f;
    func_01B05E38(&arg);
}

static inline void call_5C78(void *a, void *b, void *c, int d, int e, int f, void *g, int h)
{
    struct { void *a, *b, *c; int d, e, f; void *g; int h; } arg;
    arg.a = a; arg.b = b; arg.c = c; arg.d = d; arg.e = e; arg.f = f; arg.g = g; arg.h = h;
    func_01B05C78(&arg);
}

void func_01B04080(Sub4080 *s, void *a1, Param4080 *a2, void *a3, void *a4)
{
    void *subE0 = s->subE0;
    void *sub30 = s->sub30;
    void *res;

    call_FBF0(s, (void *)func_01B03E98, s);
    call_FFF8(D_01B00B80, s);
    call_B790(subE0, D_01B00B98, a2);
    {
        Inner4080 *in = a2->p144;
        s->f110 = (1.0f / in->f2C) * 0.0f;
        s->f114 = (1.0f / in->f2C) * -4.5f;
        s->f118 = (1.0f / in->f2C) * -3.2f;
    }
    res = func_002B49A0(D_01B007A8, 2, 0xD);
    call_5E38(sub30, D_01B00B98, a1, a2, subE0, res);
    call_5C78(sub30, a3, a4, 0xF0000, 0xBB800, 2, D_00303550, 1);
    s->p24 = a1;
    s->state = 0;
}
