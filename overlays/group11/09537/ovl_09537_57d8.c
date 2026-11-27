typedef unsigned char u8;

typedef struct {
    u8 pad00[0x54];
    int w54;
    u8 pad58[0x48];
} OvlItem;

typedef struct {
    u8 pad00[0xE8];
    int wE8;
    u8 padEC[0x14];
} OvlSub20;

typedef struct {
    u8 pad00[0x20];
    float v20[3];
    float f2C;
} OvlSub420;

typedef struct {
    u8 pad00[0x150];
} OvlSub5D0;

typedef struct {
    u8 pad00[0x20];
    OvlSub20 arr20[4];
    OvlSub420 arr420[4];
    OvlSub420 arr4E0[4];
    u8 s5A0[0x20];
    float v5C0[3];
    float f5CC;
    OvlSub5D0 arr5D0[4];
    float fB10;
    float fB14;
    int idx;
    int state;
    OvlItem *pB20;
    u8 sB24[0x3C];
} OvlSlot;

typedef struct {
    int w00;
    void *p04;
} OvlTask;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
    void *p10;
    void *p14;
} OvlArgs6;

typedef struct {
    void *p00;
} OvlArgs1;

extern float g_378[];
extern int g_38c;
extern u8 g_510[];
extern u8 g_540[];
extern u8 g_768[];
extern u8 g_788[];
extern u8 g_fe70[];
extern void *g_fe9c;

extern void func_001C5E90(int, int, int);
extern float func_001ACED8(void);
extern void func_002DD068(void *, void *, float);
extern void func_002DD020(void *, void *, void *);
extern void func_01B0A7E8(void *);
extern void func_01B0A838(void *);
extern void func_01B0A930(void *);
extern void func_01B0B970(void *);
extern void func_01B0B9C0(void *);
extern void func_01B0BA68(void *);
extern void func_01B0D2B0(void *);
extern void func_01B0D3B8(void *);
extern void func_01B0DAD0(void *);
extern void func_01B0EB28(void *);

static inline void call_a930(void *p) { void *a = p; func_01B0A930(&a); }
static inline void call_a838(void *p) { void *a = p; func_01B0A838(&a); }
static inline void call_ba68(void *p) { void *a = p; func_01B0BA68(&a); }
static inline void call_b9c0(void *p) { void *a = p; func_01B0B9C0(&a); }
static inline void call_d3b8(void *p) { void *a = p; func_01B0D3B8(&a); }
static inline void call_d2b0(void *p) { void *a = p; func_01B0D2B0(&a); }
static inline void call_eb28(int x) { int a = x; func_01B0EB28(&a); }

void ovl_09537_57d8(OvlTask *task)
{
    void *args[10];
    OvlSlot *st = (OvlSlot *)task->p04;
    int i;
    int flag;

    st->fB10 += 1.0f / 30.0f;
    switch (st->state) {
    case 0:
        if (st->fB10 >= g_378[st->idx]) {
            if (st->idx == 2) {
                func_001C5E90(g_38c, st->pB20->w54, 32);
            }
            {
                register int stride5d0 __asm__("$18") = sizeof(OvlSub5D0);
                register u8 *p768 __asm__("$17") = g_768;
                register float c8 __asm__("$f22") = 8.0f;
                register float c4 __asm__("$f21") = 4.0f;
                args[0] = (u8 *)st + st->idx * sizeof(OvlSub420) + 0x420;
                args[1] = p768;
                func_01B0A7E8(args);

                *(float *)((u8 *)st + st->idx * sizeof(OvlSub420) + 0x440) = (func_001ACED8() - 1.0f) * c8 - c4;
                *(float *)((u8 *)st + st->idx * sizeof(OvlSub420) + 0x444) = 2.5f - (func_001ACED8() - 1.0f) * 7.0f;
                {
                    float r = func_001ACED8() - 1.0f;
                    int off;
                    u8 *p;
                    float f;
                    __asm__("" : : "f"(r));
                    off = st->idx * sizeof(OvlSub420);
                    __asm__("" : : "r"(off));
                    f = r * c8 - c4;
                    __asm__("" : : "f"(f));
                    p = (u8 *)st + off;
                    __asm__("" : "+r"(off));
                    {
                        u8 *q = (u8 *)(off + (int)st) + 0x440;
                        __asm__("" : : "r"(q));
                        *(volatile float *)(p + 0x448) = f;
                        func_002DD068(q, q, st->fB14);
                    }
                }
                func_002DD020((u8 *)st + st->idx * sizeof(OvlSub420) + 0x440, (u8 *)st + st->idx * sizeof(OvlSub420) + 0x440, st->v5C0);
                *(float *)((u8 *)st + st->idx * sizeof(OvlSub420) + 0x44C) = 1.0f;

                args[0] = (u8 *)st + st->idx * sizeof(OvlSub420) + 0x4E0;
                args[1] = p768;
                func_01B0A7E8(args);

                {
                    int off = st->idx * sizeof(OvlSub420);
                    u8 *p = (u8 *)st + off;
                    *(volatile float *)(p + 0x508) = 1.0f;
                    __asm__("" : "+r"(off));
                    {
                        u8 *q = (u8 *)(off + (int)st);
                        __asm__("" : : "r"(q));
                        *(volatile float *)(p + 0x500) = 1.0f;
                        q += 0x500;
                        __asm__("" : : "r"(q));
                        *(volatile float *)(p + 0x504) = 1.0f;
                        func_002DD068(q, q, st->fB14);
                    }
                }
                {
                    float f = (func_001ACED8() - 1.0f) * 0.6f + 0.9f;
                    OvlArgs6 *a10 = (OvlArgs6 *)&args[4];
                    *(volatile void **)&a10->p00 = (u8 *)st + st->idx * stride5d0 + 0x5D0;
                    *(float *)((u8 *)st + st->idx * sizeof(OvlSub420) + 0x50C) = f;
                    *(volatile void **)&a10->p04 = p768;
                    *(volatile void **)&a10->p08 = g_540;
                    args[7] = (u8 *)st + st->idx * sizeof(OvlSub420) + 0x420;
                    *(volatile void **)&a10->p10 = g_510;
                    args[9] = (u8 *)st + st->idx * sizeof(OvlSub420) + 0x4E0;
                    func_01B0B970(a10);
                }

                args[0] = (u8 *)(st->idx * sizeof(OvlSub20) + (int)st) + 0x20;
                args[1] = g_788;
                args[2] = (u8 *)st + st->idx * stride5d0 + 0x5D0;
                args[3] = g_fe9c;
                args[4] = g_fe70;
                args[5] = 0;
                func_01B0DAD0(args);
            }

            if (++st->idx >= 4) {
                st->state++;
            }
        }
        break;
    case 1:
        flag = 4;
        for (i = 0; i < 4; i++) {
            flag &= st->arr20[i].wE8;
        }
        if (flag) {
            for (i = 0; i < 4; i++) {
                call_a930(&st->arr420[i]);
                call_a838(&st->arr420[i]);
                call_a930(&st->arr4E0[i]);
                call_a838(&st->arr4E0[i]);
                call_ba68(&st->arr5D0[i]);
                call_b9c0(&st->arr5D0[i]);
            }
            call_a930(st->s5A0);
            call_a838(st->s5A0);
            call_d3b8(st->sB24);
            call_d2b0(st->sB24);
            call_eb28(task->w00);
            st->state = 0xFF;
        }
        break;
    }
}
