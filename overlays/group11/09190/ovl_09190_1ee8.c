typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    u8 pad1C[0x10];
    int frame;
    u8 s030[0x30];
    u8 s060[0x30];
    u8 s090[0x30];
    u8 s0C0[0x100];
    u8 s1C0[0x150];
    u8 s310[0xC60];
    u8 sF70[0x50];
    u8 sFC0[0x60];
} Ovl1ee8State;

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
    void *p18;
} OvlArgs28;

extern u8 D_01B00600[];
extern u8 D_01B00650[];
extern int D_01B006A0;
extern int D_01B006A8[4];
extern int D_01B006B8;
extern u8 D_01B006C8;
extern u8 D_01B00840[];
extern u8 D_01B00870[];
extern u8 D_01B00A98[];
extern u8 D_01B00AB8[];
extern u8 D_01B01020[];
extern u8 D_01B01180[];
extern u8 D_01B0E280[];
extern void *D_01B0E2AC;

extern void func_00282060(void *, int, int);
extern void func_01B090B0(void *);
extern int func_001ACEA0(void);
extern void func_01B03518(void *);
extern void func_01B031A8(void *);
extern void func_01B03148(void *);
extern void func_01B08510(void *);
extern void func_00282798(void *, void *);
extern float func_001ACED8(void);
extern void func_01B09D68(void *);
extern void func_01B0BEC8(void *);
extern void func_001CE2F0(int, int);
extern void func_001C5E90(int, int, int);
extern void func_001C69C8(int, int, int);
extern void func_01B0CF20(void *);

void ovl_09190_1ee8(OvlTask *task)
{
    void *sp00[4];
    OvlArgs28 args;
    int sp30;
    register Ovl1ee8State *st __asm__("$23") = (Ovl1ee8State *)task->p04;
    unsigned int state = st->state;

    switch (state) {
    case 0:
        {
            u8 *s310 = st->s310;
            u8 *p600 = D_01B00600;
            u8 *p1020 = D_01B01020;

            func_00282060(s310, 1, 64);

            {
                register u8 *s030 __asm__("$18") = st->s030;
                register u8 *pa98 __asm__("$17") = D_01B00A98;
                register u8 *sF70 __asm__("$16") = st->sF70;
                register u8 *sFC0 __asm__("$19") = st->sFC0;
                OvlArgs28 *a;

                sp00[0] = s030;
                sp00[1] = pa98;
                func_01B090B0(sp00);

                __asm__("" : "+r"(s030), "+r"(sF70), "+r"(sFC0));
                *(int *)(s030 + 0x20) = (u16)func_001ACEA0();
                *(int *)(s030 + 0x24) = (u16)func_001ACEA0();
                *(int *)(s030 + 0x28) = (u16)func_001ACEA0();

                sp00[0] = sF70;
                sp00[1] = pa98;
                sp00[2] = D_01B01180;
                sp00[3] = 0;
                func_01B03518(sp00);

                *(int *)(sF70 + 0x34) = 0;
                *(int *)(sF70 + 0x38) = 0;
                *(float *)(sF70 + 0x30) = 50.0f;

                a = &args;
                *(volatile void **)&a->p04 = pa98;
                args.p08 = sF70;
                args.p0C = p1020;
                args.p10 = s310;
                args.p14 = p600;
                args.p18 = s030;
                args.p00 = sFC0;
                func_01B031A8(a);

                sFC0[0x34] |= 0x2C;
                sFC0[0x54] |= 1;
                *(volatile int *)&st->frame = 0;
                st->state++;
            }
        }
        break;
    case 1:
        {
            register u8 *sFC0 __asm__("$18") = st->sFC0;
            __asm__("" : "+r"(sFC0));
            sp00[0] = sFC0;
            func_01B03148(sp00);
            if (sp00[1] != 0) {
                register u8 *p __asm__("$20") = *(u8 **)((u8 *)sp00[0] + 0x30);
                register u8 *s060 __asm__("$17") = st->s060;
                register u8 *pa98 __asm__("$19") = D_01B00A98;
                OvlArgs28 *a = &args;

                *(void **)(sFC0 + 0x40) = D_01B00650;

                args.p00 = s060;
                *(volatile void **)&a->p04 = pa98;
                func_01B08510(a);

                {
                    register u8 *s090 __asm__("$18") = st->s090;
                    register u8 *s1C0 __asm__("$21") = st->s1C0;
                    register u8 *s0C0 __asm__("$22") = st->s0C0;

                    func_00282798(&st->s060[0x20], p + (p[0x36] * 0x30 + 0x40));
                    __asm__("" : "+r"(s060));
                    *(float *)(s060 + 0x20) += 25.0f - (func_001ACED8() - 0.99f) * 50.0f;
                    {
                        float r = func_001ACED8();
                        *(float *)(s060 + 0x2C) = 1.0f;
                        args.p00 = s090;
                        *(volatile void **)&a->p04 = pa98;
                        *(float *)(s060 + 0x28) += 25.0f - (r - 0.99f) * 50.0f;
                        func_01B08510(a);
                    }

                    __asm__("" : "+r"(s090), "+r"(s1C0));
                    *(float *)(s090 + 0x20) = 1.0f;
                    *(float *)(s090 + 0x24) = 1.0f;
                    *(float *)(s090 + 0x28) = 1.0f;
                    {
                        float r = func_001ACED8();
                        args.p00 = s1C0;
                        a->p04 = pa98;
                        a->p08 = D_01B00870;
                        args.p0C = s060;
                        a->p10 = D_01B00840;
                        args.p14 = s090;
                        *(float *)(s090 + 0x2C) = (r - 0.99f) * 0.2f + 1.0f;
                        func_01B09D68(a);
                    }

                    s1C0[0x14C] = 1;

                    args.p00 = s0C0;
                    *(volatile void **)&a->p04 = D_01B00AB8;
                    args.p08 = s1C0;
                    args.p0C = D_01B0E2AC;
                    *(volatile void **)&a->p10 = D_01B0E280;
                    *(volatile void **)&a->p14 = (void *)2;
                    func_01B0BEC8(a);

                    if (++D_01B006A0 >= 8) {
                        func_001CE2F0(D_01B006C8, 0);
                        func_001C5E90(D_01B006B8, D_01B006C8, 0);
                    } else {
                        func_001C69C8(D_01B006C8, D_01B006A8[func_001ACEA0() & 3], 1);
                    }
                    st->state = 10000;
                }
            }
        }
        break;
    case 10000:
        sp30 = task->w00;
        func_01B0CF20(&sp30);
        break;
    }

    st->frame++;
}
