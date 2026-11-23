#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x04];
    s32 w04;
} Cfg3B0;

typedef struct {
    u8 pad00[0x0C];
    s32 w0C;
    u8 pad10[0x0C];
} Entry4B4;

typedef struct {
    u8 pad00[0xD0];
    float pos[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x0C];
    s32 w120;
    u8 pad124[0x0C];
} OvlCtx;

extern u8 D_01B47900[];
extern void *D_01B04B80;
extern void *D_01B04B84;
extern u8 D_01B0B120[];
extern OvlMgr D_01B041B8;
extern u8 D_01B00040[];
extern Cfg3B0 D_01B003B0;
extern Entry4B4 D_01B004B4[];
extern OvlCtx D_01B04200[];
extern u8 D_01B03C78[];
extern u8 D_01B00360[];
extern u8 D_01B007B0[];

extern void *func_002B49A0(void *, s32, s32);
extern void func_01B035E0(void *, void *, void *, s32);
extern void func_01B036B8(void *, void *, s32, s32, float, s32, void *);
extern void func_01B00D98(s32, void *, s32);
extern s32 func_01B00B48(s32);
extern void func_01B02E40(void *, void *, void *);
extern void *func_01B03358(void *);
extern void func_01B03520(void *);

s32 ovl_09118_0808(void)
{
    u8 *buf = D_01B47900;
    u8 *p5;
    OvlCtx *ctx;
    s32 i, j;
    s32 delay = 0;

    OvlMgr *m = &D_01B041B8;

    {
        register u8 *end __asm__("$2") = buf + 0x40000;
        D_01B04B84 = end;
    }
    D_01B04B80 = buf;
    m->w2C = func_002B49A0(D_01B0B120, 8, 0);
    func_01B035E0(m, D_01B00040, D_01B04B80, 0x40000);

    ctx = D_01B04200;
    p5 = buf + 0x140000;
    for (i = 0; i < D_01B003B0.w04; i++) {
        Entry4B4 *e = &D_01B004B4[i];
        for (j = 0; j < e->w0C; j++) {
            func_01B036B8(m, ctx, 0, delay, 0.2f, 18, D_01B03C78);
            delay += 15;
            func_01B00D98(i, ctx->pos, 5);
            ctx->w120 = func_01B00B48(i);
            func_01B02E40(p5, D_01B0B120, D_01B00360);
            ctx->p110 = p5;
            ctx++;
            p5 += 64;
        }
    }

    func_01B03520(func_01B03358(D_01B007B0));
    return 0;
}
