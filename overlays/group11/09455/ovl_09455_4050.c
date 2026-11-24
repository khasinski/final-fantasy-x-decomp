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
} OvlG9D0;

typedef struct {
    u8 pad00[0x30];
    float f30;
    float f34;
    float f38;
    u8 pad3C[0x24];
    float f60;
    float f64;
    float f68;
    float f6C;
} OvlG910;

typedef struct {
    u8 pad00[0x58C];
    int w58C;
    u8 pad590[0x40];
} OvlSlot;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    float farr1C[8];
    int w3C;
    int w40;
    int w44;
    int arr48[8];
    u8 pad68[0x08];
    OvlSlot slots[6];
} OvlState;

typedef struct {
    int w00;
    OvlState *p04;
} OvlTask;

typedef union {
    struct {
        void *p00;
        void *p04;
        int w08;
        int w0C;
        u8 b10;
    } a;
    struct {
        void *p00;
        void *p04;
        float f08;
        float f0C;
    } b;
} OvlArgs;

extern OvlG9D0 g_9d0;
extern OvlG910 g_910;
extern int g_4f0;
extern int g_4f4;
extern u8 g_8c8[];
extern u8 g_8e8[];

extern void func_01B04860(void *);
extern void func_01B08BB0(void *);
extern void func_01B08CE0(void *);
extern void func_01B08DC0(void *);
extern int func_001BB3F0(int, int, void *, void *, void *);
extern float func_001ACED8(void);
extern void func_01B03CC8(void *, void *, float);
extern int func_001CE050(int, int);
extern int func_001CE1A8(int);
extern void func_001CE2F0(int, int);
extern void func_01B0DBA8(void *);

void ovl_09455_4050(OvlTask *task)
{
    OvlArgs args;
    int tmp;
    int x;
    OvlState *st;
    OvlG9D0 *g9d0;
    OvlG910 *g910;
    int i;
    int r;
    float rnd;
    float inv;

    st = task->p04;
    g9d0 = &g_9d0;
    g910 = &g_910;
    switch (st->state) {
    case 0:
        args.a.p00 = g9d0;
        args.a.p04 = g_8c8;
        args.a.w08 = g_4f0;
        args.a.w0C = 0;
        args.a.b10 = 1;
        func_01B04860(&args);

        args.b.p00 = g910;
        args.b.p04 = g_8e8;
        func_01B08BB0(&args);

        g910->f6C = 0.5f;
        g910->f68 = 0.5f;
        g910->f64 = 0.5f;
        g910->f60 = 0.5f;
        g910->f38 = 0.5f;
        g910->f34 = 0.5f;
        g910->f30 = 0.5f;
        args.b.p00 = g910;
        args.b.p04 = 0;
        args.b.f08 = 0.1f;
        func_01B08CE0(&args);
        st->state = 10;
        /* fallthrough */
    case 10:
        st->w44 = 0;
        for (i = 0; i < g9d0->count; i++) {
            r = func_001BB3F0(g_4f4, *(int *)((u8 *)g9d0 + i * sizeof(OvlItem) + 0x74), &tmp, &tmp, &tmp);
            st->arr48[i] = r;
            st->w44 += r;
        }
        inv = (float)st->w44;
        for (i = 0; i < g9d0->count; i++) {
            st->farr1C[i] = (float)st->arr48[i] / inv;
        }
        for (i = 0; i < 6; i++) {
            *(int *)((u8 *)st + i * sizeof(OvlSlot) + 0x5FC) = 0xFF;
        }
        st->w3C = 0;
        st->state++;
        /* fallthrough */
    case 11:
        if (st->w3C-- <= 0) {
            i = st->w44 % 5;
            if (*(int *)((u8 *)st + i * sizeof(OvlSlot) + 0x5FC) == 0xFF) {
                rnd = func_001ACED8() - 0.99f;
                for (tmp = 0; tmp < g9d0->count - 1 && !(rnd < st->farr1C[tmp]); tmp++) {
                    rnd -= st->farr1C[tmp];
                }
                func_01B03CC8(&st->slots[i], &g9d0->items[tmp], (func_001ACED8() - 0.99f) * 0.4f + 0.8f);
                if (--st->w44 == 0) {
                    func_001CE050(g_4f4, 0x6A);
                    st->w40 = 0;
                    st->state++;
                } else {
                    st->arr48[tmp]--;
                    st->w3C = 22;
                    for (i = 0; i < g9d0->count; i++) {
                        st->farr1C[i] = (float)st->arr48[i] / (float)st->w44;
                    }
                }
            }
        }
        break;
    case 12:
        if (st->w40 >= 40) {
            g910->f30 = g910->f34 = g910->f38 = g910->f60 = g910->f64 = g910->f68 = g910->f6C = 1.0f;
            args.b.p00 = g910;
            args.b.p04 = 0;
            args.b.f08 = 0.05f;
            args.b.f0C = 1.0f;
            func_01B08DC0(&args);
            st->state = 10000;
        }
        break;
    case 10000:
        if (func_001CE1A8(g_4f4)) {
            func_001CE2F0(g_4f4, 0);
            x = task->w00;
            func_01B0DBA8(&x);
        }
        break;
    }
    st->w40++;
}
