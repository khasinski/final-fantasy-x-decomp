#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
    float f[4];
} Qword;

typedef struct {
    s32 tex_idx;
    float u;
    float v;
} SymTex;

extern SymTex D_01B00A58[];
extern u8 D_01C03DD0[];

extern void *op_oef2_a_get(void *, s32, s32);
extern void func_002DA610(s32, s32);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);

void func_01B02B30(s32 sym, s32 x, s32 y16, s32 w, s32 h, s32 rgb, s32 alpha) {
    void *ch;
    Qword *p;
    SymTex *t;
    u64 *tex;
    float u0, v0, u1, v1;
    s32 x0, x1, y0, y1;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    t = &D_01B00A58[sym];
    u0 = t->u;
    v0 = t->v;
    u1 = u0 + 0.5f;
    v1 = v0 + 0.48f;

    x0 = (x << 4) + 0x6FF8;
    x1 = ((x + w) << 4) + 0x6FF8;
    y0 = y16 + 0x72F8;
    y1 = y16 + ((h + 0x730) << 4) - 8;

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000010;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = 0x0000008000000044ULL;
    p->d[1] = 0x42ULL;
    p++;

    p->q = 0;
    p->d[0] = 0xD02E400000008001ULL;
    p->d[1] = 0x0005125125125126ULL;
    p++;

    tex = (u64 *)op_oef2_a_get(D_01C03DD0, 2, t->tex_idx);
    p->d[0] = *tex;
    p++;

    p->f[0] = u0;
    p->f[1] = v0;
    p->f[2] = 1.0f;
    p++;

    p->w[0] = rgb;
    p->w[1] = rgb;
    p->w[2] = rgb;
    p->w[3] = alpha;
    p++;

    p->w[0] = x0;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->f[0] = u1;
    p->f[1] = v0;
    p->f[2] = 1.0f;
    p++;

    p->w[0] = rgb;
    p->w[1] = rgb;
    p->w[2] = rgb;
    p->w[3] = alpha;
    p++;

    p->w[0] = x1;
    p->w[1] = y0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->f[0] = u0;
    p->f[1] = v1;
    p->f[2] = 1.0f;
    p++;

    p->w[0] = rgb;
    p->w[1] = rgb;
    p->w[2] = rgb;
    p->w[3] = alpha;
    p++;

    p->w[0] = x0;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->f[0] = u1;
    p->f[1] = v1;
    p->f[2] = 1.0f;
    p++;

    p->w[0] = rgb;
    p->w[1] = rgb;
    p->w[2] = rgb;
    p->w[3] = alpha;
    p++;

    p->w[0] = x1;
    p->w[1] = y1;
    p->w[2] = 0;
    p->w[3] = 0;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
