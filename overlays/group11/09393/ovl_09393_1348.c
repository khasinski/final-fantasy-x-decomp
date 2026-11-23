/* EE Battle-Effect Overlay: group 0x11, file 09393 (shared 0x01B01348..0x01B0167C, also in 09635)
 * Load base: 0x01B00000, .text: 0x01B01348..0x01B0167C (1 function)
 */
#include "common.h"

typedef struct Task09393 {
    u8 pad00[0x14];
    s8 b14;
    s8 b15;
    s8 b16;
    s8 b17;
} Task09393;

typedef struct OvlCtx {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x08];
    void *p110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct Sub20 {
    u8 pad00[0x20];
} Sub20;

typedef struct Work09393 {
    u8 pad0000[0xAB0];
    OvlCtx ctxA[6];          /* 0xAB0 */
    OvlCtx ctxB[6];          /* 0x11D0 */
    u8 unk18F0[3][0x40];     /* 0x18F0 */
    float unk19B0[3][4];     /* 0x19B0 */
    float unk19E0[3][4];     /* 0x19E0 */
    u8 pad1A10[0x04];
    float unk1A14;           /* 0x1A14 */
    u8 pad1A18[0xC8];
    u8 unk1AE0[6][0x40];     /* 0x1AE0 */
} Work09393;

extern u8 D_01B005F8[];
extern u8 D_01B006F8[];
extern u8 D_01B07AE8[];
extern Sub20 D_01B07BB0[3];
extern Work09393 *D_01B07C10;
extern u8 D_01B0DB50[];

extern void func_01B012D8(void);
extern void func_01B01338(void);
extern void func_01B04B80(void);
extern void func_01B04B90(void);

int func_002EFD78(void);
float func_002B3DB0(float);
void func_01B045C0(void *, void *, int, int, float, int, void *);
void func_01B01CA0(int, void *, int);
void func_01B036F8(int, void *, void *);
void func_01B03490(int, void *, void *);
void func_01B029D8(int, int);
int func_01B01A50(int);
void func_01B03D48(void *, void *, void *);
void func_01B042E0(void *);

void func_01B01348(Task09393 *t)
{
    Work09393 *w = D_01B07C10;
    int flip;
    float vec[4];
    float tmp;
    float sc;
    OvlCtx *ctx;
    int owner;
    u8 *buf;

    if (t->b14 > 0) {
        t->b14--;
    } else {
        register int slot __asm__("$16");
        register int chr __asm__("$20");
        register int slot4 __asm__("$21");
        register int tgt __asm__("$22");
        register int idx __asm__("$23");
        int fp_tgt;
        void *cb;
        int buf_off;
        idx = t->b17;
        {
            register int c304 __asm__("$2") = 304;
            ctx = (OvlCtx *)((u8 *)w->ctxA + idx * c304);
        }
        slot = t->b16;
        chr = t->b15;
        slot4 = slot << 4;
        tgt = slot + 3;
        fp_tgt = tgt;
        __asm__("" : "+r"(fp_tgt));

        func_01B045C0(D_01B07AE8, ctx, 2, 2, 0.1f, 0, 0);
        ctx->fC4 = w->unk1A14;
        ctx->p104 = func_01B012D8;
        ctx->w120 = chr;
        func_01B01CA0(tgt, (u8 *)w->unk19E0 + slot4, 3);

        vec[1] = 0.0f;
        flip = func_002EFD78() & 1;
        __asm__("" : "+m"(vec[1]));
        if (flip == 0) {
            float a = vec[1] + 3.1415927f;
            if (a > 3.1415927f) {
                a -= 6.2831855f;
            } else if (a < -3.1415927f) {
                a += 6.2831855f;
            }
            vec[1] = a;
        }

        func_01B036F8(chr, &D_01B07BB0[slot], D_01B006F8);
        {
            float b = vec[1] + func_002B3DB0(0.7853982f);
            if (b > 3.1415927f) {
                b -= 6.2831855f;
            } else if (b < -3.1415927f) {
                b += 6.2831855f;
            }
            *(float *)((u8 *)w->unk19B0 + slot4 + 4) = b;
        }
        func_01B03490(chr, w->unk18F0[slot], (u8 *)w->unk19B0 + slot4);
        __asm__("" : "+m"(vec[0]) : "r"(slot4));
        func_01B029D8(chr, 0);

        owner = func_01B01A50(tgt);
        if (idx < 3) {
            if (flip == 0) {
                owner = fp_tgt;
                cb = func_01B01338;
            } else {
                cb = func_01B04B90;
            }
        } else {
            cb = func_01B04B80;
        }

        buf_off = idx << 6;
        sc = (func_002B3DB0(0.2f) + 1.0f) * 0.13f;
        {
            register int off __asm__("$2") = idx * 304;
            ctx = (OvlCtx *)((u8 *)w->ctxB + off);
        }
        func_01B045C0(D_01B07AE8, ctx, 0, 6, sc, 0, cb);
        ctx->fC4 = w->unk1A14;
        func_01B01CA0(tgt, ctx->pos, 3);
        __asm__("" : "+r"(owner), "+r"(buf_off) : "r"(idx), "m"(ctx->pos[1]));
        ctx->pos[1] -= 10.0f;
        ctx->w120 = owner;
        buf = (u8 *)w->unk1AE0 + buf_off;
        func_01B03D48(buf, D_01B0DB50, D_01B005F8);
        ctx->p110 = buf;
        func_01B042E0(t);
    }
}
