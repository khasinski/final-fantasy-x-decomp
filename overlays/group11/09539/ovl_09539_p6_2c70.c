typedef unsigned char u8;

extern u8 g_ovl_dat_b10[];
extern u8 g_ovl_dat_a08[];
extern void *g_ovl_ptr_630;
extern void *g_ovl_ptr_634;

extern void fn_ovl_3550(void *msg);
extern void fn_ovl_c898(void *msg);
extern int fn_sys_1bb3f0(void *a0, void *a1, int *a2, int *a3, int *a4);
extern float fn_sys_1aced8(void);
extern void fn_ovl_2ad0(void *a0, void *a1, float farg);
extern int fn_sys_1ce050(void *a0, int a1);
extern int fn_sys_1ce1a8(void *a0);
extern void fn_sys_1ce2f0(void *a0, int a1);

typedef struct {
    void *a;
    void *b;
    void *c;
    void *d;
    u8 e;
    u8 pad[3];
} Msg3550;

static __inline__ void call_3550(void *a, void *b, void *c, void *d, u8 e) {
    Msg3550 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    m.e = e;
    fn_ovl_3550(&m);
}

typedef struct {
    u8 pad0[32];
    u8 items[8][160];
    int count;
} Ovl9539B10;

typedef struct {
    u8 pad0[24];
    unsigned int state;
    float probs[8];
    int timer;
    int total;
    int counts[11];
    u8 slots[6][800];
} Ovl9539Ctx;

void ovl_09539_p6_2c70(void **arg) {
    Ovl9539Ctx *ctx = (Ovl9539Ctx *)arg[1];
    Ovl9539B10 *b10 = (Ovl9539B10 *)g_ovl_dat_b10;
    int i;
    int dummy;
    void *m_end;

    switch (ctx->state) {
    case 0:
        call_3550(b10, g_ovl_dat_a08, g_ovl_ptr_630, 0, 1);
        ctx->state = 10;
    case 10:
        ctx->total = 0;
        for (i = 0; i < b10->count; i++) {
            int n = fn_sys_1bb3f0(g_ovl_ptr_634, *(void **)(b10->items[i] + 84), &dummy, &dummy, &dummy);
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
            *(int *)(ctx->slots[i] + 732) = 255;
        }
        ctx->timer = 0;
        ctx->state += 1;
    case 11:
        if (ctx->timer-- > 0) {
            break;
        }
        i = ctx->total % 5;
        if (*(int *)(ctx->slots[i] + 732) != 255) {
            break;
        }
        {
            float r = fn_sys_1aced8() - 0.99f;
            for (dummy = 0; dummy < b10->count - 1; dummy++) {
                if (r < ctx->probs[dummy]) break;
                r -= ctx->probs[dummy];
            }
            fn_ovl_2ad0(ctx->slots[i], b10->items[dummy],
                        (fn_sys_1aced8() - 0.99f) * 0.4f + 0.8f);
            ctx->total -= 1;
            if (ctx->total == 0) {
                fn_sys_1ce050(g_ovl_ptr_634, 106);
                ctx->state = 10000;
                break;
            }
            ctx->counts[dummy] -= 1;
            ctx->timer = 17;
            for (i = 0; i < b10->count; i++) {
                ctx->probs[i] = (float)ctx->counts[i] / (float)ctx->total;
            }
        }
        break;
    case 10000:
        if (fn_sys_1ce1a8(g_ovl_ptr_634) != 0) {
            fn_sys_1ce2f0(g_ovl_ptr_634, 0);
            m_end = arg[0];
            fn_ovl_c898(&m_end);
        }
        break;
    }
}
