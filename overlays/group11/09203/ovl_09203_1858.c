typedef unsigned char u8;

typedef struct {
    int w00;
    void *p04;
} OvlTask;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    u8 pad1C[0x0C];
    int w28;
    int w2C;
} Ovl09203State;

typedef struct {
    u8 pad00[0x20];
    float v[4];
} OvlVec30;

typedef struct {
    u8 pad00[0x14C];
    u8 b14C;
    u8 pad14D[3];
} OvlSub150;

typedef struct {
    void *p00;
    void *p04;
    void *p08;
    void *p0C;
} OvlArgs4;

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
    void *p04;
    int w08;
    u8 b0C;
} OvlArgs33D8;

typedef struct {
    void *p00;
    u8 pad04;
    u8 b05;
} OvlArgs7388;

typedef struct {
    void *p00;
    int w04;
    int w08;
} OvlArgs2E60;

extern void *D_01B005F0;
extern int D_01B005F8;
extern u8 D_01B00720[];
extern u8 D_01B00750[];
extern u8 D_01B00780[];
extern u8 D_01B007B0[];
extern u8 D_01B009D4;
extern u8 D_01B009D8[];
extern u8 D_01B009F8[];
extern u8 D_01B00AE0[];
extern OvlVec30 D_01B00B80;
extern OvlVec30 D_01B00BB0[2];
extern OvlVec30 D_01B00C10[3];
extern OvlSub150 D_01B00CA0[2];
extern OvlSub150 D_01B00F40;
extern u8 D_01B01090[];
extern u8 D_01B01190[];
extern u8 D_01B0B800[];
extern void *D_01B0B82C;

extern void func_01B033D8(void *);
extern void func_01B06178(void *);
extern void func_01B03250(void *);
extern void func_01B06648(void *);
extern void func_01B03368(void *);
extern void func_01B07300(void *);
extern void func_01B07388(void *);
extern int func_001B4E58(int);
extern float func_00110AF0(int);
extern void func_01B02CD8(void *);
extern void func_001CE050(int, int);
extern void func_01B02ED0(void *);
extern void func_01B09460(void *);
extern void func_01B08BF0(void *);
extern void func_01B08BB8(void *);
extern void func_01B02E60(void *);
extern int func_001CE1A8(int);
extern void func_00299170(void *);
extern void func_01B02C30(void *);
extern void func_01B03580(void *);
extern void func_01B03478(void *);
extern void func_01B0A4B8(void *);

void ovl_09203_1858(OvlTask *task)
{
    union {
        OvlArgs4 a4;
        OvlArgs33D8 a33d8;
        OvlArgs7388 a7388;
        OvlArgs2E60 a2e60;
    } args;
    OvlArgs6 args10;
    void *a30;
    void *a34;
    int a38;
    Ovl09203State *st;
    u8 *g_ae0;
    OvlVec30 *g_b80;
    OvlSub150 *g_df0;

    g_ae0 = D_01B00AE0;
    g_b80 = &D_01B00B80;
    g_df0 = &D_01B00CA0[1];
    st = (Ovl09203State *)task->p04;
    switch (st->state) {
    case 0:
        st->state = 10;
        /* fallthrough */
    case 10:
        {
            OvlVec30 *pC70 = &D_01B00C10[2];
            OvlVec30 *pC10 = &D_01B00C10[0];
            OvlVec30 *pC40 = &D_01B00C10[1];

            args.a33d8.p00 = g_ae0;
            args.a33d8.p04 = D_01B009D8;
            args.a33d8.w08 = D_01B005F8;
            args.a33d8.b0C = 0;
            func_01B033D8(&args);

            args.a4.p00 = pC70;
            args.a4.p04 = D_01B009D8;
            func_01B06178(&args);

            args.a4.p00 = g_ae0;
            args.a4.p04 = pC70->v;
            func_01B03250(&args);
            pC70->v[3] = 1.0f;

            args.a4.p00 = g_b80;
            args.a4.p04 = D_01B009D8;
            func_01B06648(&args);

            args.a4.p00 = g_ae0;
            args.a4.p04 = g_b80->v;
            func_01B03368(&args);

            {
                OvlArgs6 *a10 = &args10;
                args10.p0C = pC70;
                *(volatile void **)&args10.p00 = g_df0;
                *(volatile void **)&a10->p08 = D_01B007B0;
                args10.p10 = g_b80;
                *(volatile void **)&a10->p14 = D_01B00750;
                *(volatile void **)&a10->p04 = D_01B009D8;
                func_01B07300(a10);
            }

            args.a7388.p00 = g_df0;
            args.a7388.b05 = D_01B009D4;
            func_01B07388(&args);

            {
                register OvlSub150 *pF40 __asm__("$16") = &D_01B00F40;
                args.a4.p00 = pC10;
                args.a4.p04 = D_01B009D8;
                func_01B06178(&args);
                pC10->v[0] = 0.0f;
                pC10->v[1] = 0.0f;
                pC10->v[2] = 0.0f;
                pC10->v[3] = 1.0f;

                args.a4.p00 = pC40;
                args.a4.p04 = D_01B009D8;
                func_01B06178(&args);
                pC40->v[0] = 1.0f;
                pC40->v[1] = 1.0f;
                pC40->v[2] = 1.0f;
                pC40->v[3] = func_00110AF0(func_001B4E58(D_01B005F8)) * 0.001f;

                {
                    OvlArgs6 *a6 = (OvlArgs6 *)&args;
                    a6->p00 = pF40;
                    a6->p04 = D_01B009D8;
                    a6->p08 = g_df0;
                    a6->p0C = pC10;
                    a6->p10 = D_01B00780;
                    a6->p14 = pC40;
                    func_01B07300(a6);
                }

                args.a4.p00 = g_ae0;
                args.a4.p04 = pF40;
                func_01B02CD8(&args);
            }

            func_001CE050(D_01B005F8, 0x98);
            st->w2C = 0;
            {
                register unsigned int s __asm__("$3") = st->state + 1;
                st->state = s;
            }
        }
        break;
    case 11:
        if (st->w2C < 15) {
            break;
        }
        {
            OvlVec30 *pBB0 = &D_01B00BB0[0];
            OvlVec30 *pBE0 = &D_01B00BB0[1];
            register u8 *p1090 __asm__("$20") = D_01B01090;
            __asm__("" : "+r"(p1090));

            args.a4.p00 = pBB0;
            args.a4.p04 = D_01B009D8;
            func_01B06178(&args);

            args.a4.p00 = g_ae0;
            args.a4.p04 = 0;
            args.a4.p08 = pBB0->v;
            func_01B02ED0(&args);
            pBB0->v[3] = 1.0f;
            pBB0->v[1] -= 0.2f;

            args.a4.p00 = pBE0;
            args.a4.p04 = D_01B009D8;
            func_01B06178(&args);
            pBE0->v[0] = 1.0f;
            pBE0->v[1] = 1.0f;
            pBE0->v[2] = 1.0f;
            pBE0->v[3] = 1.0f;

            {
                OvlArgs6 *a6 = (OvlArgs6 *)&args;
                a6->p00 = &D_01B00CA0[0];
                a6->p04 = D_01B009D8;
                a6->p08 = D_01B007B0;
                a6->p0C = pBB0;
                a6->p10 = D_01B00780;
                a6->p14 = pBE0;
                func_01B07300(a6);
            }

            D_01B00CA0[0].b14C = 1;
            {
                OvlArgs6 *a6 = (OvlArgs6 *)&args;
                a6->p00 = p1090;
                a6->p04 = D_01B009F8;
                a6->p08 = &D_01B00CA0[0];
                a6->p0C = D_01B0B82C;
                a6->p10 = D_01B0B800;
                a6->p14 = 0;
                func_01B09460(a6);
            }

            {
                OvlArgs6 *a6 = (OvlArgs6 *)&args;
                a6->p00 = D_01B01190;
                a6->p04 = D_01B009D8;
                a6->p08 = &D_01B00CA0[0];
                a6->p0C = D_01B00720;
                a6->p10 = D_01B005F0;
                a6->p14 = 0;
                func_01B08BF0(a6);
            }

            args.a4.p00 = D_01B01190;
            args.a4.p04 = 0;
            func_01B08BB8(&args);

            st->w2C = 0;
            st->state++;
        }
        break;
    case 12:
        if (st->w2C >= 5) {
            args.a2e60.p00 = g_ae0;
            args.a2e60.w04 = 0;
            args.a2e60.w08 = 8;
            func_01B02E60(&args);
            st->state++;
        }
        /* fallthrough */
    case 13:
        D_01B00C10[0].v[2] += 5.0f;
        if (func_001CE1A8(D_01B005F8)) {
            st->state = 10000;
        }
        break;
    case 10000:
        func_00299170(*(void **)(g_ae0 + 0x58));
        *(int *)(g_ae0 + 0x70) = 2;
        args.a2e60.p00 = g_ae0;
        args.a2e60.w04 = 1;
        func_01B02C30(&args);
        a30 = g_ae0;
        func_01B03580(&a30);
        a34 = g_ae0;
        func_01B03478(&a34);
        a38 = task->w00;
        func_01B0A4B8(&a38);
        break;
    }
    st->w2C++;
    st->w28++;
}
