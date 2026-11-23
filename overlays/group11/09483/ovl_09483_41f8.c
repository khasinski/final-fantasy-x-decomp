typedef unsigned char u8;

extern u8 g_ovl_dat_cf0[];
extern u8 g_ovl_dat_c30[];
extern u8 g_ovl_dat_be8[];
extern u8 g_ovl_dat_c08[];
extern void *g_ovl_ptr_810;
extern void *g_ovl_ptr_814;

extern void fn_ovl_4a08(void *msg);
extern void fn_ovl_8d58(void *msg);
extern void fn_ovl_8e88(void *msg);
extern void fn_ovl_8f68(void *msg);
extern void fn_ovl_dd50(void *msg);
extern int fn_sys_1bb3f0(void *a0, void *a1, int *a2, int *a3, int *a4);
extern float fn_sys_1aced8(void);
extern void fn_ovl_3eb8(void *a0, void *a1, float farg);
extern void fn_sys_1cdd38(void *a0);
extern int fn_sys_1ce1a8(void *a0);
extern void fn_sys_1ce2f0(void *a0, int a1);

typedef struct {
    void *a;
    void *b;
    void *c;
    void *d;
    u8 e;
    u8 pad[3];
} Msg4a08;

typedef struct {
    void *a;
    void *b;
    float c;
} Msg8e88;

typedef struct {
    void *a;
    void *b;
    float c;
    float d;
} Msg8f68;

static __inline__ void call_4a08(void *a, void *b, void *c, void *d, u8 e) {
    Msg4a08 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    m.e = e;
    fn_ovl_4a08(&m);
}

static __inline__ void call_8d58(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_ovl_8d58(m);
}

static __inline__ void call_8e88(void *a, void *b, float c) {
    Msg8e88 m;
    m.a = a;
    m.b = b;
    m.c = c;
    fn_ovl_8e88(&m);
}

static __inline__ void call_8f68(void *a, void *b, float c, float d) {
    Msg8f68 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    fn_ovl_8f68(&m);
}

typedef struct {
    u8 pad0[32];
    u8 items[8][160];
    int count;
} Ovl9483Cf0;

typedef struct {
    u8 pad0[24];
    unsigned int state;
    float probs[8];
    int timer;
    int frame;
    int total;
    int counts[10];
    u8 slots[6][1488];
} Ovl9483Ctx;

void ovl_09483_41f8(void **arg) {
    Ovl9483Ctx *ctx = (Ovl9483Ctx *)arg[1];
    Ovl9483Cf0 *cf0 = (Ovl9483Cf0 *)g_ovl_dat_cf0;
    u8 *c30 = g_ovl_dat_c30;
    int i;
    int dummy;
    void *m_end;

    switch (ctx->state) {
    case 0:
        call_4a08(cf0, g_ovl_dat_be8, g_ovl_ptr_810, 0, 1);
        call_8d58(c30, g_ovl_dat_c08);
        *(float *)(c30 + 108) = 0.3f;
        *(float *)(c30 + 104) = 0.3f;
        *(float *)(c30 + 100) = 0.3f;
        *(float *)(c30 + 96) = 0.3f;
        *(float *)(c30 + 56) = 0.3f;
        *(float *)(c30 + 52) = 0.3f;
        *(float *)(c30 + 48) = 0.3f;
        call_8e88(c30, 0, 0.1f);
        ctx->state = 10;
    case 10:
        ctx->total = 0;
        for (i = 0; i < cf0->count; i++) {
            int n = fn_sys_1bb3f0(g_ovl_ptr_814, *(void **)(cf0->items[i] + 84), &dummy, &dummy, &dummy);
            ctx->counts[i] = n;
            ctx->total += n;
        }
        {
            float total = (float)ctx->total;
            for (i = 0; i < cf0->count; i++) {
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
            for (dummy = 0; dummy < cf0->count - 1; dummy++) {
                if (r < ctx->probs[dummy]) break;
                r -= ctx->probs[dummy];
            }
            fn_ovl_3eb8(ctx->slots[i], cf0->items[dummy],
                        (fn_sys_1aced8() - 0.99f) * 0.4f + 0.8f);
            ctx->total -= 1;
            if (ctx->total == 0) {
                fn_sys_1cdd38(g_ovl_ptr_810);
                ctx->frame = 0;
                ctx->state += 1;
                break;
            }
            ctx->counts[dummy] -= 1;
            ctx->timer = 28;
            for (i = 0; i < cf0->count; i++) {
                ctx->probs[i] = (float)ctx->counts[i] / (float)ctx->total;
            }
        }
        break;
    case 12:
        if (ctx->frame < 60) {
            break;
        }
        *(float *)(c30 + 108) = 1.0f;
        *(float *)(c30 + 104) = 1.0f;
        *(float *)(c30 + 100) = 1.0f;
        *(float *)(c30 + 96) = 1.0f;
        *(float *)(c30 + 56) = 1.0f;
        *(float *)(c30 + 52) = 1.0f;
        *(float *)(c30 + 48) = 1.0f;
        call_8f68(c30, 0, 0.05f, 1.0f);
        ctx->state = 10000;
        break;
    case 10000:
        if (fn_sys_1ce1a8(g_ovl_ptr_814) != 0) {
            fn_sys_1ce2f0(g_ovl_ptr_814, 0);
            m_end = arg[0];
            fn_ovl_dd50(&m_end);
        }
        break;
    }
    ctx->frame += 1;
}
