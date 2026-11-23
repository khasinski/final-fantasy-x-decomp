/* EE Battle-Effect Overlay: group 0x11, file 09396 (0x01B01378..0x01B01798)
 * Load base: 0x01B00000, .text: 0x01B01378..0x01B01798 (1 function)
 */
#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

typedef struct OvlCtx {
    u8 pad00[0x104];
    void *p104;
    u8 pad108[0x1E];
    u8 b126;
    u8 pad127[0x09];
} OvlCtx;

typedef struct RetCtx {
    u8 pad00[0x64];
    float f64;
} RetCtx;

typedef struct Sub9A0 {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0x0C];
    u8 b98;
    u8 b99;
} Sub9A0;

typedef struct SubAC0 {
    u8 pad00[0xF0];
    u8 bF0;
    u8 bF1;
    u8 bF2;
    u8 bF3;
    u8 padF4[0x04];
    int wF8;
    float fFC;
    int w100;
    u8 pad104[0x0C];
    int w110;
    int w114;
    int w118;
    u8 pad11C[0x08];
    u16 h124;
} SubAC0;

typedef struct Work09396 {
    u8 pad000[0x130];
    OvlCtx ctx1;      /* 0x130 */
    OvlCtx ctx2;      /* 0x260 */
    OvlCtx ctx3;      /* 0x390 */
    OvlCtx ctx4;      /* 0x4C0 */
    OvlCtx ctx5;      /* 0x5F0 */
    u8 pad720[0x280];
    Sub9A0 sub9A0;    /* 0x9A0 */
    u8 padA3C[0x84];
    SubAC0 subAC0;    /* 0xAC0 */
    u8 padBE8[0x1C];
    int wC04;         /* 0xC04 */
    int wC08;         /* 0xC08 */
} Work09396;

extern u64 D_006F2CE0[];
extern u8 D_01B07AA0[];
extern Work09396 *D_01B07B68;
extern void *D_01B07B6C;

extern void func_01B00FB0(void);
extern void func_01B01030(void);
extern void func_01B01110(void);

int func_002DA610(int, int);
void *func_002DB6D8(int);
void func_0011A538(int *);
void func_002DBA28(void *, void *);
void func_002DAB10(void *, int, int, int, int, int, int, int);
void func_002F8660(int);
void func_002DADD0(void *, void *);
void func_01B048F8(void *, void *);
float func_01B00EF0(void);
RetCtx *func_01B04488(void *, void *, int, int, float, int, void *);
void func_01B07488(void *, int);
void func_01B075F8(void *, int);
void *func_01B04128(void *);
void func_01B042F0(void *);

void func_01B01378(void)
{
    u8 buf[0x70];
    int disp[4];
    int d;
    void *ch;
    Qword *p;
    Work09396 *w;
    u8 *mgr;
    OvlCtx *ctx;
    float sc;
    float sc2;
    RetCtx *r;
    Sub9A0 *s9;
    SubAC0 *sa;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x7000000C;
    p++;

    func_0011A538(disp);
    {
        register int d __asm__("$5") = disp[0];
        int tbp;

        p->q = 0;
        p->d[0] = 0xB08B400000008001ULL;
        p->d[1] = 0x0EEE535136EEULL;
        p++;

        p->d[0] = 0x0A0800D0ULL;
        p->d[1] = 0x4CULL;
        p++;

        tbp = (d & 1) ? 0xD00 : 0;
        p->d[0] = 0x0003000DULL;
        p->d[1] = 0x47ULL;
        p++;

        {
            u64 tex0 = (u64)(long)(0x24020000 | tbp);
            tex0 |= 0x240000000ULL;
            p->d[0] = tex0;
        }
    }
    p++;

    p->w[0] = 0;
    p->w[1] = 0;
    p++;

    p->w[0] = 0x80;
    p->w[1] = 0x80;
    p->w[2] = 0x80;
    p->w[3] = 0x80;
    p++;

    p->w[0] = 0x6FF8;
    p->w[1] = 0x72F8;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->w[0] = 0x2000;
    p->w[1] = 0x1A00;
    p++;

    p->w[0] = 0x8FF8;
    p->w[1] = 0x8CF8;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;

    p->d[0] = 0;
    p->d[1] = 0x3FULL;
    p++;

    p->d[0] = D_006F2CE0[4];
    p->d[1] = 0x4CULL;
    p++;

    p->d[0] = D_006F2CE0[12];
    p->d[1] = 0x47ULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);

    func_002DAB10(buf, 0x1A00, 8, 10, 0, 0, 0x200, 0x1A0);
    func_002F8660(0);
    func_002DADD0(buf, D_01B07B6C);
    {
        register int keep_v0 __asm__("$2") = func_002DA610(0, 0);
        w = D_01B07B68;
        mgr = D_01B07AA0;
        __asm__("" : "+m"(buf[0]) : "r"(keep_v0));
        func_01B048F8(mgr, &w->ctx5);
    }

    sc = func_01B00EF0() * 0.000157f;
    ctx = &w->ctx4;
    r = func_01B04488(mgr, ctx, 4, 0, sc, 0, 0);
    sc2 = sc * 0.9285714f;
    ctx->b126 = 2;
    ctx->p104 = func_01B01030;
    r->f64 = sc2;

    ctx = &w->ctx3;
    r = func_01B04488(mgr, ctx, 3, 0, sc, 0, 0);
    ctx->b126 = 2;
    r->f64 = sc2;
    ctx->p104 = func_01B00FB0;

    ctx = &w->ctx2;
    r = func_01B04488(mgr, ctx, 2, 0, sc, 0, 0);
    ctx->b126 = 2;
    ctx->p104 = func_01B00FB0;
    r->f64 = sc2;

    ctx = &w->ctx1;
    r = func_01B04488(mgr, ctx, 1, 0, sc, 0, 0);
    ctx->b126 = 2;
    r->f64 = sc2;
    ctx->p104 = func_01B00FB0;

    s9 = &w->sub9A0;
    s9->b82 = 0xFF;
    s9->b81 = 0xFF;
    s9->b80 = 0xFF;
    s9->b83 = 0x80;
    s9->b84 = 0xFF;
    s9->b85 = 0xFF;
    s9->b86 = 0xFF;
    s9->b87 = 0;
    s9->w88 = 0;
    s9->b98 = 0x48;
    s9->b99 = 0;
    func_01B07488(s9, 12);

    sa = &w->subAC0;
    sa->bF0 = 0x80;
    sa->bF1 = 0x80;
    sa->bF2 = 0x80;
    sa->bF3 = 0x30;
    sa->w114 = 0x100;
    sa->w118 = 0xD0;
    sa->fFC = 0.05f;
    sa->h124 = 0;
    sa->w110 = 0;
    sa->wF8 = 0;
    sa->w100 = 0;
    func_01B075F8(sa, 0x32);

    w->wC04 = 0xC;
    w->wC08 = 0x1E;
    func_01B042F0(func_01B04128(func_01B01110));
}
