/* Shared 09662/09718 main controller (1156 B, 09662 @ 0x01B03F28). */

#include "common.h"

extern u8 g_9d0[];
extern u8 g_910[];
extern u8 g_8c8[];
extern u8 g_8e8[];
extern void *g_4f0;
extern void *g_4f4;

extern void fn_4728(void *msg);
extern void fn_8a78(void *msg);
extern void fn_8ba8(void *msg);
extern void fn_8c88(void *msg);
extern void fn_da70(void *msg);
extern int func_001BB3F0(void *a0, void *a1, int *a2, int *a3, int *a4);
extern float func_001ACED8(void);
extern void fn_3cc8(void *a0, void *a1, float farg);

typedef struct {
    void *a;
    void *b;
    void *c;
    void *d;
    u8 e;
    u8 pad[3];
} Msg4728;

typedef struct {
    void *a;
    void *b;
    float c;
} Msg8ba8;

typedef struct {
    void *a;
    void *b;
    float c;
    float d;
} Msg8c88;

static __inline__ void call_4728(void *a, void *b, void *c, void *d, u8 e)
{
    Msg4728 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    m.e = e;
    fn_4728(&m);
}

static __inline__ void call_8a78(void *a, void *b)
{
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_8a78(m);
}

static __inline__ void call_8ba8(void *a, void *b, float c)
{
    Msg8ba8 m;
    m.a = a;
    m.b = b;
    m.c = c;
    fn_8ba8(&m);
}

static __inline__ void call_8c88(void *a, void *b, float c, float d)
{
    Msg8c88 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    fn_8c88(&m);
}

typedef struct {
    u8 pad0[32];
    u8 items[8][160];
    int count;
} Ovl9662Mgr;

typedef struct {
    u8 pad0[24];
    unsigned int state;
    float probs[8];
    int timer;
    int frame;
    int total;
    int counts[10];
    u8 slots[6][1488];
} Ovl9662Ctx;

void ovl_09662_3f28(void **arg)
{
    Ovl9662Ctx *ctx = (Ovl9662Ctx *)arg[1];
    Ovl9662Mgr *b10 = (Ovl9662Mgr *)g_9d0;
    u8 *a50 = g_910;
    int i;
    int dummy;
    void *m_end;

    switch (ctx->state) {
    case 0:
        call_4728(b10, g_8c8, g_4f0, 0, 1);
        call_8a78(a50, g_8e8);
        *(float *)(a50 + 108) = 0.5f;
        *(float *)(a50 + 104) = 0.5f;
        *(float *)(a50 + 100) = 0.5f;
        *(float *)(a50 + 96) = 0.5f;
        *(float *)(a50 + 56) = 0.5f;
        *(float *)(a50 + 52) = 0.5f;
        *(float *)(a50 + 48) = 0.5f;
        call_8ba8(a50, 0, 0.1f);
        ctx->state = 10;
    case 10:
        ctx->total = 0;
        for (i = 0; i < b10->count; i++) {
            int n = func_001BB3F0(g_4f4, *(void **)(b10->items[i] + 84), &dummy, &dummy, &dummy);
            ctx->counts[i] = n;
            ctx->total += n;
        }
        {
            float total = (float)ctx->total;
            for (i = 0; i < b10->count; i++) {
                ctx->probs[i] = (float)ctx->counts[i] / total;
            }
        }
        for (i = 0; i < 6; i++) {
            *(int *)(ctx->slots[i] + 1420) = 255;
        }
        ctx->timer = 0;
        ctx->state += 1;
    case 11:
        if (ctx->timer-- > 0) {
            break;
        }
        i = ctx->total % 5;
        if (*(int *)(ctx->slots[i] + 1420) != 255) {
            break;
        }
        {
            float r = func_001ACED8() - 0.99f;
            for (dummy = 0; dummy < b10->count - 1; dummy++) {
                if (r < ctx->probs[dummy]) break;
                r -= ctx->probs[dummy];
            }
            fn_3cc8(ctx->slots[i], b10->items[dummy],
                    (func_001ACED8() - 0.99f) * 0.4f + 0.8f);
            ctx->total -= 1;
            if (ctx->total == 0) {
                ctx->frame = 0;
                ctx->state += 1;
                break;
            }
            ctx->counts[dummy] -= 1;
            ctx->timer = 22;
            for (i = 0; i < b10->count; i++) {
                ctx->probs[i] = (float)ctx->counts[i] / (float)ctx->total;
            }
        }
        break;
    case 12:
        if (ctx->frame < 40) {
            break;
        }
        *(float *)(a50 + 108) = 1.0f;
        *(float *)(a50 + 104) = 1.0f;
        *(float *)(a50 + 100) = 1.0f;
        *(float *)(a50 + 96) = 1.0f;
        *(float *)(a50 + 56) = 1.0f;
        *(float *)(a50 + 52) = 1.0f;
        *(float *)(a50 + 48) = 1.0f;
        call_8c88(a50, 0, 0.05f, 1.0f);
        ctx->state = 10000;
        break;
    case 10000:
        m_end = arg[0];
        fn_da70(&m_end);
        break;
    }
    ctx->frame += 1;
}
