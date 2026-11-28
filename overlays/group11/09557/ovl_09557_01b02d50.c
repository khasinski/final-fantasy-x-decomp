#include "common.h"

extern u8 D_01B02CD8[];
extern u8 D_01B00A10[];
extern u8 D_01B00A28[];
extern u8 D_01B00A24;
extern u8 D_01B00800[];
extern u8 D_01B00A48[];
extern void *D_01B1055C;
extern u8 D_01B10530[];
extern u8 D_01B00A68[];
extern void *D_01B00640;
extern void func_01B0F148(void *);
extern void func_01B0F550(void *);
extern void func_01B096A0(void *);
extern void func_002DD0B0(void *, void *);
extern void func_01B0B380(void *);
extern void func_01B0B408(void *);
extern void func_01B0C038(void *);
extern void func_01B0E198(void *);
extern void func_01B04328(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_0014D3F0(int, int, void *);

static __inline__ void call_f148(void *a, void *b, void *c) { void *m[3]; m[0] = a; m[1] = b; m[2] = c; func_01B0F148(m); }
static __inline__ void call_f550(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; func_01B0F550(m); }
static __inline__ void call_96a0(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; func_01B096A0(m); }
static __inline__ void call_b380(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; func_01B0B380(m); }
static __inline__ void call_b408(void *a, u8 b) { struct { void *a; u8 pad; u8 b; } m; m.a = a; m.b = b; func_01B0B408(&m); }
static __inline__ void call_c038(void *a, void *b, void *c, void *d, void *e, void *f)
{
    void *m[6];
    register void **v0 __asm__("$2") = m;
    *(void *volatile *)&m[0] = a;
    v0[1] = b;
    v0[2] = c;
    m[3] = d;
    m[4] = e;
    m[5] = f;
    func_01B0C038(v0);
}
static __inline__ void call_e198(void *a, void *b, void *c, void *d, void *e, void *f) { void *m[6]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; m[4] = e; m[5] = f; func_01B0E198(m); }
static __inline__ void call_4328(void *a, int b, int c, float d, float e, float f, int g, float h, int i) { struct { void *a; int b, c; float d, e, f; int g; float h; int i; } m; m.a = a; m.b = b; m.c = c; m.d = d; m.e = e; m.f = f; m.g = g; m.h = h; m.i = i; func_01B04328(&m); }

void func_01B02D50(u8 *s0, void *s3, u8 *s2)
{
    u8 *s7 = s0 + 0x170;
    u8 *s6 = s0 + 0x1D0;
    u8 *s4 = s0 + 0x1A0;
    u8 *s5 = s0 + 0x20;
    u8 *s1;

    call_f148(s0, D_01B02CD8, s0);
    call_f550(D_01B00A10, s0);

    s1 = D_01B00A28;
    call_96a0(s7, s1);
    func_002DD0B0(s0 + 0x190, s3);

    call_b380(s6, s1);
    call_b408(s2, D_01B00A24);

    *(u32 *)(s0 + 0x1F0) = *(u32 *)(s2 + 0x20);
    *(u32 *)(s0 + 0x1F4) = *(u32 *)(s2 + 0x24);
    *(u32 *)(s0 + 0x1F8) = *(u32 *)(s2 + 0x28);

    call_96a0(s4, s1);
    *(float *)(s0 + 0x1C0) = 1.0f;
    *(float *)(s0 + 0x1C4) = 1.0f;
    *(float *)(s0 + 0x1C8) = 1.0f;
    *(float *)(s0 + 0x1CC) = 1.0f;

    call_c038(s5, s1, D_01B00800, s7, s6, s4);
    call_e198(s0 + 0x200, D_01B00A48, s5, D_01B1055C, D_01B10530, 0);
    call_4328(D_01B00A68, 0, 0, 5.0f, 12.0f, 1.0f, 0, 5.0f, 0);

    func_0014D3F0(7, 1, func_002B49A0(D_01B00640, 5, 0));
    *(int *)(s0 + 0x18) = 0;
}
