#include "common.h"

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Ovl9088Entry;

typedef struct {
    int f00;
    int f04;
    u8 *f08;
    int f0C;
    int f10;
    u8 b14[32];
    int w34[32];
    Ovl9088Entry entries[5];
    int f104;
} Ovl9088Ctx;

extern Ovl9088Ctx D_01B00620;
extern int func_001CE048(int);
extern int func_01B01BF0(int);
extern u8 *func_001E53D0(int, int *);
extern int func_001BB3F0(int, int, int *, int *, int *);

void func_01B00A30(int a0_in)
{
    /* DEBT(FAKE): pin a0 to $s7 to match $s6/$s7 tie with sum */
    register int a0 __asm__("$23") = a0_in;
    int i;
    int sum;
    u8 *p;
    Ovl9088Ctx *ctx = &D_01B00620;

    ctx->f0C = 0;
    i = 0;
    while (1) {
        ctx->b14[i] = 0xFF;
        ctx->w34[i] = -1;
        if (++i >= 32) {
            break;
        }
    }

    i = 0;
    sum = 0;
    ctx->f00 = func_001CE048(a0);
    ctx->f10 = func_01B01BF0(ctx->f00);
    p = func_001E53D0(a0, &ctx->f04);
    if (ctx->f04 > 0) {
        int *pc = &ctx->entries[0].c;
        int *pb = &ctx->entries[0].b;
        int *pa = &ctx->entries[0].a;
        do {
            u8 id = p[i];
            int n;
            ctx->b14[i] = id;
            ctx->w34[id] = func_01B01BF0(id);
            n = func_001BB3F0(a0, id, pa, pb, pc);
            pc[1] = n;
            sum += n;
            pb += 4;
            pa += 4;
            pc += 4;
            i++;
        } while (i < ctx->f04);
    }
    ctx->f104 = sum;
    ctx->f08 = ctx->b14;
}
