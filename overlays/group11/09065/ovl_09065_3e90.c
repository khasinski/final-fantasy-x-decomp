/* EE Battle-Effect Overlay: group 0x11, file 09065 (shared by ~129 p4/p2 overlays)
 * .text: 0x01B03E90..0x01B04048 (1 function, 440B).
 */
#include "common.h"

typedef struct {
    u8 pad00[0x28];
    s32 *flags;     /* 0x28 */
} Ovl3E90Obj;

typedef struct {
    u8 pad00[0x3C];
    float f3C;      /* 0x3C */
    u8 pad40[0x0C];
    float f4C;      /* 0x4C */
} Ovl3E90Param;

typedef struct {
    s32 w00;        /* 0x00 */
    s32 w04;        /* 0x04 */
    u8 pad08[0x14];
    s32 w1C;        /* 0x1C */
    u8 pad20[0x2C];
    s8 b4C;         /* 0x4C */
    s8 b4D;         /* 0x4D */
    s16 pad4E;
    s16 h50;        /* 0x50 */
    s16 h52;        /* 0x52 */
    s16 h54;        /* 0x54 */
    s16 h56;        /* 0x56 */
} Ovl3E90Ctx;

extern void *func_002B3888(int size);
extern void func_002B39C0(int size);
extern void func_01B04048(Ovl3E90Param *a1, void *a2, s32 *a3, s32 *flags, void *a5, void *a6, void *a7);
extern void func_002B0178(Ovl3E90Ctx *ctx, void *buf, Ovl3E90Obj *a0, Ovl3E90Param *a1, int a4);
extern void func_002B0400(Ovl3E90Ctx *ctx, void *buf, Ovl3E90Obj *a0, Ovl3E90Param *a1, int a4);
extern void func_002B5830(void *dst, void *src);
extern void func_002B56D8(void *dst, void *a, void *b);
extern void func_002B7B20(s32 *flags, Ovl3E90Ctx *ctx);

void func_01B03E90(Ovl3E90Obj *a0, Ovl3E90Param *a1, void *a2, s32 *a3, int a4, void *a5, void *a6, void *a7)
{
    u8 *buf;
    s32 *flags;
    Ovl3E90Ctx *ctx;

    buf = func_002B3888(0x400);
    flags = a0->flags;
    func_01B04048(a1, a2, a3, flags, a5, a6, a7);

    ctx = (Ovl3E90Ctx *)(buf + 0x100);
    func_002B0178(ctx, buf, a0, a1, -1);

    {
        /* DEBT(FAKE): pin 0x44C/0x01F80000 to v1/v0 to match ee-gcc register choice */
        register s32 w00 __asm__("$3") = 0x44C;
        register s32 w04 __asm__("$2") = 0x01F80000;
        ctx->w00 = w00;
        ctx->w1C = 0;
        ctx->w04 = w04;
    }
    func_002B0400(ctx, buf, a0, a1, a4);

    {
        /* DEBT(FAKE): pin scissor constants to v1/a0/a1 and b4C temp to v0 */
        /* DEBT(ORDER): volatile stores preserve sb 76(s5) -> sh 82/84/86/80(s5) order */
        register s32 c0 __asm__("$2") = (int)(a1->f3C * 0.5f);
        register s16 h52 __asm__("$3") = 0x1FF;
        register s16 h50 __asm__("$4") = 1;
        register s16 h56 __asm__("$5") = 0x19F;
        float f4c;
        *(volatile s8 *)&ctx->b4C = c0;
        f4c = (*(volatile float *)&a1->f4C) * 0.5f;
        *(volatile s16 *)&ctx->h52 = h52;
        *(volatile s16 *)&ctx->h54 = h50;
        *(volatile s16 *)&ctx->h56 = h56;
        *(volatile s16 *)&ctx->h50 = h50;
        ctx->b4D = (s8)(int)f4c;
    }

    if ((*a3 & 0x3FFF) >= 0x3400) {
        *flags = (*flags & ~0x10) | 4;
    } else {
        *flags = (*flags | 0x10) & ~4;
    }

    func_002B5830(buf + 0x80, a5);
    func_002B56D8(buf + 0xC0, a6, buf + 0x80);
    func_002B56D8(buf + 0xC0, a7, buf + 0xC0);
    func_002B7B20(flags, ctx);
    func_002B39C0(0x400);
}
