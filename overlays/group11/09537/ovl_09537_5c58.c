typedef unsigned char u8;

typedef struct {
    u8 pad00[0x54];
    int w54;
    u8 pad58[0x48];
} OvlItem;

typedef struct {
    u8 pad00[0x20];
    OvlItem items[8];
    int count;
} OvlG7B0;

typedef struct {
    u8 pad00[0x5A0];
    u8 s5A0[0x20];
    float v5C0[3];
    float f5CC;
    u8 pad5D0[0x540];
    float fB10;
    float fB14;
    int idx;
    int state;
    OvlItem *pB20;
    u8 sB24[0x3C];
} OvlSlot;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    float farr1C[8];
    int w3C;
    int w40;
    int arr44[8];
    u8 pad64[0x0C];
    OvlSlot slots[6];
} OvlMainState;

typedef struct {
    int w00;
    void *p04;
} OvlTask;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
} OvlArgs16;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
} OvlArgs10;

typedef struct {
    void *p00;
    void *p04;
    int w08;
    int w0C;
    u8 b10;
} OvlArgs5d78;

extern int g_370;
extern int g_388;
extern int g_38c;
extern u8 g_540[];
extern u8 g_750[];
extern u8 g_768[];
extern OvlG7B0 g_7b0;

extern void fn_57d8(void);
extern void func_01B0EA80(void *);
extern void func_01B0EE88(void *);
extern void func_01B0A7E8(void *);
extern void func_01B07770(void *);
extern void func_01B0D260(void *);
extern void func_01B0D228(void *);
extern void func_01B06498(void *);
extern int func_001BB3F0(int, int, void *, void *, void *);
extern float func_001ACED8(void);
extern int func_001CE050(int, int);
extern int func_001CE1A8(int);
extern void func_001CE2F0(int, int);
extern void func_01B0EB28(void *);

void ovl_09537_5c58(OvlSlot *st, OvlItem *item, float scale)
{
    OvlArgs16 args;
    OvlArgs10 args10;

    args.p00 = st;
    args.p04 = fn_57d8;
    args.p08 = st;
    func_01B0EA80(&args);

    args.p00 = g_750;
    args.p04 = st;
    func_01B0EE88(&args);

    args.p00 = st->s5A0;
    args.p04 = g_768;
    func_01B0A7E8(&args);

    args.p00 = item;
    args.p04 = st->v5C0;
    func_01B07770(&args);

    {
        void *p370 = (void *)g_370;
        OvlArgs10 *a10 = &args10;
        *(volatile float *)&st->f5CC = 1.0f;
        *(volatile void **)&a10->p04 = g_768;
        *(volatile void **)&a10->p08 = g_540;
        args10.p0C = st->s5A0;
        args10.p00 = st->sB24;
        args10.p10 = p370;
        args10.p14 = 0;
        func_01B0D260(a10);
    }

    args.p00 = st->sB24;
    args.p04 = 0;
    func_01B0D228(&args);

    st->fB14 = scale;
    st->pB20 = item;
    st->fB10 = 0.0f;
    st->idx = 0;
    st->state = 0;
}

void ovl_09537_5d78(OvlTask *task)
{
    OvlArgs5d78 args;
    int tmp;
    int x;
    OvlMainState *st;
    OvlG7B0 *g7b0;
    int i;
    int r;
    float rnd;
    float inv;

    st = (OvlMainState *)task->p04;
    g7b0 = &g_7b0;
    switch (st->state) {
    case 0:
        args.p00 = g7b0;
        args.p04 = g_768;
        args.w08 = g_388;
        args.w0C = 0;
        args.b10 = 1;
        func_01B06498(&args);
        st->state = 10;
        /* fallthrough */
    case 10:
        st->w40 = 0;
        for (i = 0; i < g7b0->count; i++) {
            r = func_001BB3F0(g_38c, *(int *)((u8 *)g7b0 + i * sizeof(OvlItem) + 0x74), &tmp, &tmp, &tmp);
            st->arr44[i] = r;
            st->w40 += r;
        }
        inv = (float)st->w40;
        for (i = 0; i < g7b0->count; i++) {
            st->farr1C[i] = (float)st->arr44[i] / inv;
        }
        for (i = 0; i < 6; i++) {
            *(int *)((u8 *)st + i * sizeof(OvlSlot) + 0xB8C) = 0xFF;
        }
        st->w3C = 0;
        st->state++;
        /* fallthrough */
    case 11:
        if (st->w3C-- <= 0) {
            i = st->w40 % 5;
            if (*(int *)((u8 *)st + i * sizeof(OvlSlot) + 0xB8C) == 0xFF) {
                rnd = func_001ACED8() - 0.99f;
                for (tmp = 0; tmp < g7b0->count - 1 && !(rnd < st->farr1C[tmp]); tmp++) {
                    rnd -= st->farr1C[tmp];
                }
                ovl_09537_5c58(&st->slots[i], &g7b0->items[tmp], (func_001ACED8() - 0.99f) * 0.4f + 0.8f);
                if (--st->w40 == 0) {
                    func_001CE050(g_38c, 0x6A);
                    st->state = 10000;
                } else {
                    st->arr44[tmp]--;
                    st->w3C = 20;
                    for (i = 0; i < g7b0->count; i++) {
                        st->farr1C[i] = (float)st->arr44[i] / (float)st->w40;
                    }
                }
            }
        }
        break;
    case 10000:
        if (func_001CE1A8(g_38c)) {
            func_001CE2F0(g_38c, 0);
            x = task->w00;
            func_01B0EB28(&x);
        }
        break;
    }
}
