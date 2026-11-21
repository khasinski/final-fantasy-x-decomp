typedef unsigned char u8;

extern u8 g_ovl_dat_b10[];
extern u8 g_ovl_dat_a50[];
extern u8 g_ovl_dat_a08[];
extern u8 g_ovl_dat_a28[];
extern void *g_ovl_ptr_630;
extern void *g_ovl_ptr_634;

extern void fn_ovl_3550(void *msg);
extern void fn_ovl_78a0(void *msg);
extern void fn_ovl_79d0(void *msg);
extern void fn_ovl_7ab0(void *msg);
extern void fn_ovl_c898(void *msg);
extern int fn_sys_1bb3f0(void *a0, void *a1, int *a2, int *a3, int *a4);
extern float fn_sys_1aced8(void);
extern void fn_ovl_2ad0(void *a0, void *a1, float farg);

typedef struct {
    void *a;
    void *b;
    void *c;
    void *d;
    u8 e;
    u8 pad[3];
} Msg3550;

typedef struct {
    void *a;
    void *b;
    float c;
} Msg79d0;

typedef struct {
    void *a;
    void *b;
    float c;
    float d;
} Msg7ab0;

static __inline__ void call_3550(void *a, void *b, void *c, void *d, u8 e) {
    Msg3550 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    m.e = e;
    fn_ovl_3550(&m);
}

static __inline__ void call_78a0(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_ovl_78a0(m);
}

static __inline__ void call_79d0(void *a, void *b, float c) {
    Msg79d0 m;
    m.a = a;
    m.b = b;
    m.c = c;
    fn_ovl_79d0(&m);
}

static __inline__ void call_7ab0(void *a, void *b, float c, float d) {
    Msg7ab0 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    fn_ovl_7ab0(&m);
}

typedef struct {
    u8 pad0[32];
    u8 items[8][160];
    int count;
} Ovl9664B10;

typedef struct {
    u8 pad0[24];
    unsigned int state;
    float probs[8];
    int timer;
    int frame;
    int total;
    int counts[10];
    u8 slots[6][1488];
} Ovl9664Ctx;

void ovl_09726_p6_41f8(void **arg) {
    Ovl9664Ctx *ctx = (Ovl9664Ctx *)arg[1];
    Ovl9664B10 *b10 = (Ovl9664B10 *)g_ovl_dat_b10;
    u8 *a50 = g_ovl_dat_a50;
    int i;
    int dummy;
    void *m_end;

    switch (ctx->state) {
    case 0:
        call_3550(b10, g_ovl_dat_a08, g_ovl_ptr_630, 0, 1);
        call_78a0(a50, g_ovl_dat_a28);
        *(float *)(a50 + 108) = 0.3f;
        *(float *)(a50 + 104) = 0.3f;
        *(float *)(a50 + 100) = 0.3f;
        *(float *)(a50 + 96) = 0.3f;
        *(float *)(a50 + 56) = 0.3f;
        *(float *)(a50 + 52) = 0.3f;
        *(float *)(a50 + 48) = 0.3f;
        call_79d0(a50, 0, 0.1f);
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
            float r = fn_sys_1aced8() - 0.99f;
            for (dummy = 0; dummy < b10->count - 1; dummy++) {
                if (r < ctx->probs[dummy]) break;
                r -= ctx->probs[dummy];
            }
            fn_ovl_2ad0(ctx->slots[i], b10->items[dummy],
                        (fn_sys_1aced8() - 0.99f) * 0.4f + 0.8f);
            ctx->total -= 1;
            if (ctx->total == 0) {
                ctx->frame = 0;
                ctx->state += 1;
                break;
            }
            ctx->counts[dummy] -= 1;
            ctx->timer = 28;
            for (i = 0; i < b10->count; i++) {
                ctx->probs[i] = (float)ctx->counts[i] / (float)ctx->total;
            }
        }
        break;
    case 12:
        if (ctx->frame < 60) {
            break;
        }
        *(float *)(a50 + 108) = 1.0f;
        *(float *)(a50 + 104) = 1.0f;
        *(float *)(a50 + 100) = 1.0f;
        *(float *)(a50 + 96) = 1.0f;
        *(float *)(a50 + 56) = 1.0f;
        *(float *)(a50 + 52) = 1.0f;
        *(float *)(a50 + 48) = 1.0f;
        call_7ab0(a50, 0, 0.05f, 1.0f);
        ctx->state = 10000;
        break;
    case 10000:
        m_end = arg[0];
        fn_ovl_c898(&m_end);
        break;
    }
    ctx->frame += 1;
}
