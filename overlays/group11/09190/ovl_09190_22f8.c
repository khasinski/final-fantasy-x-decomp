typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x18];
    unsigned int state;
    u8 pad1C[0xC];
    int w28;
    int frame;
    int w30;
    u16 arr34[32];
    u16 h74;
} Ovl22f8State;

typedef struct {
    int w00;
    void *p04;
} OvlTask;

typedef struct {
    u8 pad00[0x20];
    struct {
        u8 pad00[0x54];
        int w54;
        u8 pad58[0x48];
    } arr20[8];
    u8 pad520[4];
    int w524;
} OvlNode2eb0;

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
} Ovl1060;

typedef struct {
    void *p00;
    void *p04;
    union {
        void *p;
        int w;
        float f;
    } u08;
    union {
        void *p;
        int w;
        float f;
    } u0C;
    union {
        void *p;
        int w;
        u8 b;
    } u10;
    union {
        void *p;
        int w;
    } u14;
} OvlArgs24;

typedef struct {
    OvlArgs24 args;
    int pad18[2];
    int count;
    int sp24;
} OvlStack;

extern int D_01B005F0;
extern int D_01B006B8;
extern u8 D_01B006C8;
extern u8 D_01B00840[];
extern u8 D_01B00870[];
extern u8 D_01B00A98[];
extern u8 D_01B00AB8[];
extern OvlNode2eb0 D_01B00AE0;
extern u8 D_01B01020[];
extern Ovl1060 D_01B01060;
extern u8 D_01B01120[];
extern u8 D_01B01150[];
extern u8 D_01B01180[];
extern u8 D_01B011B0[];
extern u8 D_01B01300[];
extern u8 D_01B01450[];
extern u8 D_01B01550[];
extern u8 D_01B01650[];
extern u8 D_01B01750[];
extern u8 D_01B01788[];
extern u8 D_01B0E280[];
extern void *D_01B0E2AC;
extern u8 D_01B0E2B0[];

extern int func_001ACEA0(void);
extern int func_001B4E18(int);
extern void func_001B5810(int, int);
extern int func_001B5D38(int, int, float);
extern int func_001B6210(int, int);
extern u8 *func_001E4F58(int, int *);
extern void func_01B022A0(void *);
extern void func_01B02EB0(void *);
extern void func_01B047E0(void *);
extern void func_01B07858(void *);
extern void func_01B07988(void *);
extern void func_01B07A68(void *);
extern void func_01B08510(void *);
extern void func_01B089E0(void *);
extern void func_01B09D68(void *);
extern void func_01B0B620(void *);
extern void func_01B0B658(void *);
extern void func_01B0BEC8(void *);
extern void func_01B0CF20(void *);

void ovl_09190_22f8(OvlTask *task)
{
    OvlStack sk;
    Ovl22f8State *st = (Ovl22f8State *)task->p04;

retry:
    switch (st->state) {
    case 0:
        sk.args.p00 = &D_01B00AE0;
        sk.args.p04 = D_01B00A98;
        sk.args.u08.w = D_01B006B8;
        sk.args.u0C.w = 0;
        sk.args.u10.b = 1;
        func_01B02EB0(&sk.args);

        sk.args.p00 = D_01B01180;
        sk.args.p04 = D_01B00A98;
        func_01B08510(&sk.args);

        sk.args.p00 = D_01B00AE0.arr20;
        sk.args.p04 = D_01B01180 + 0x20;
        func_01B047E0(&sk.args);

        *(float *)(D_01B01180 + 0x2C) = 1.0f;
        sk.args.p00 = D_01B01750;
        sk.args.p04 = D_01B00A98;
        sk.args.u08.p = D_01B00870;
        sk.args.u0C.p = D_01B01180;
        sk.args.u10.w = D_01B005F0;
        sk.args.u14.w = 0;
        func_01B0B658(&sk.args);

        sk.args.p00 = D_01B01750;
        sk.args.p04 = 0;
        func_01B0B620(&sk.args);

        sk.args.p00 = &D_01B01060;
        sk.args.p04 = D_01B00AB8;
        func_01B07858(&sk.args);

        st->state = 10;
        /* fallthrough */
    case 10:
        {
            OvlNode2eb0 *node = &D_01B00AE0;
            u8 *p;
            int i, j;

            D_01B01060.f30 = D_01B01060.f34 = D_01B01060.f38 =
                D_01B01060.f60 = D_01B01060.f64 = D_01B01060.f68 = D_01B01060.f6C = 0.5f;
            sk.args.p00 = &D_01B01060;
            sk.args.u08.f = 0.05f;
            sk.args.p04 = 0;
            func_01B07988(&sk.args);

            st->h74 = 0;
            p = func_001E4F58(16, &sk.count);
            for (i = 0; i < sk.count; i++, p++) {
                int n = node->w524;
                for (j = 0; j < n; j++) {
                    if (*(int *)((u8 *)node + j * 0xA0 + 0x74) == *p) {
                        goto next_item;
                    }
                }
                func_001B5D38(*p, 10, 0.0f);
                st->arr34[st->h74] = *p;
                st->h74++;
            next_item:;
            }
            st->state = 20;
            goto retry;
        }
    case 20:
        st->frame = 0;
        st->state = 21;
        break;
    case 21:
        if (st->frame >= 15) {
            u8 *p1120 = D_01B01120;
            u8 *pa98 = D_01B00A98;
            u8 *p11b0 = D_01B011B0;
            u8 *p1550 = D_01B01550;

            sk.args.p00 = p1120;
            sk.args.p04 = pa98;
            func_01B08510(&sk.args);

            *(float *)(p1120 + 0x20) = 1.0f;
            *(float *)(p1120 + 0x24) = 1.0f;
            *(float *)(p1120 + 0x28) = 1.0f;
            *(float *)(p1120 + 0x2C) = 0.7f;
            sk.args.p00 = p11b0;
            sk.args.p04 = pa98;
            sk.args.u08.p = D_01B00870;
            sk.args.u0C.p = p1120 + 0x60;
            sk.args.u10.p = D_01B00840;
            sk.args.u14.p = p1120;
            func_01B09D68(&sk.args);

            sk.args.p00 = p1550;
            sk.args.p04 = D_01B00AB8;
            sk.args.u08.p = p11b0;
            sk.args.u0C.p = D_01B0E2AC;
            sk.args.u10.p = D_01B0E280;
            sk.args.u14.w = 1;
            func_01B0BEC8(&sk.args);

            st->state = 40;
            goto retry;
        }
        break;
    case 40:
        st->frame = 0;
        st->state = 41;
        break;
    case 41:
        if (st->frame >= 30) {
            sk.args.p00 = D_01B01650;
            sk.args.p04 = D_01B00AB8;
            sk.args.u08.p = D_01B00870;
            sk.args.u0C.p = D_01B0E2AC;
            sk.args.u10.p = D_01B0E280;
            sk.args.u14.w = 3;
            func_01B0BEC8(&sk.args);

            st->frame = 0;
            st->state++;
        }
        break;
    case 42:
        if (st->frame >= 5) {
            int m;

            D_01B01060.f30 = D_01B01060.f34 = D_01B01060.f38 =
                D_01B01060.f60 = D_01B01060.f64 = D_01B01060.f68 = D_01B01060.f6C = 0.0f;
            sk.args.p00 = &D_01B01060;
            sk.args.p04 = 0;
            sk.args.u08.f = 1.0f;
            func_01B07988(&sk.args);

            {
                u8 *p1150 = D_01B01150;
                u8 *p1300 = D_01B01300;
                u8 *p1450 = D_01B01450;
                int c;

                sk.args.p04 = D_01B00A98;
                sk.args.p00 = p1150;
                func_01B08510(&sk.args);

                c = D_01B006C8;
                __asm__("" : "+r"(c));
                *(float *)(p1150 + 0x20) = 1.0f;
                *(float *)(p1150 + 0x24) = 1.0f;
                *(float *)(p1150 + 0x28) = 1.0f;
                m = func_001B4E18(c);
                switch (m) {
                case 4232:
                case 4233:
                case 4236:
                    *(float *)(p1150 + 0x2C) = 4.0f;
                    break;
                default:
                    {
                        float one = 1.0f;
                        __asm__("" : "+f"(one));
                        *(float *)(p1150 + 0x2C) = one;
                    }
                    break;
                }

                sk.args.p00 = p1300;
                sk.args.p04 = D_01B00A98;
                sk.args.u08.p = D_01B00870;
                sk.args.u0C.p = D_01B01180;
                sk.args.u10.p = D_01B00840;
                sk.args.u14.p = p1150;
                func_01B09D68(&sk.args);

                sk.args.p00 = p1450;
                sk.args.p04 = D_01B00AB8;
                sk.args.u08.p = p1300;
                sk.args.u0C.p = D_01B0E2AC;
                sk.args.u10.p = D_01B0E280;
                sk.args.u14.w = 0;
                func_01B0BEC8(&sk.args);
            }

            func_001B6210(D_01B006C8, 0);
            st->frame = 0;
            st->state++;
        }
        break;
    case 43:
        if (st->frame >= 50) {
            st->state = 30;
            goto retry;
        }
        break;
    case 30:
        sk.args.p00 = D_01B01020;
        sk.args.p04 = D_01B00A98;
        sk.args.u08.p = D_01B01180;
        func_01B089E0(&sk.args);

        *(float *)(D_01B01020 + 0x34) = -300.0f;
        sk.args.p00 = D_01B01788;
        sk.args.p04 = D_01B00A98;
        sk.args.u08.p = D_01B00870;
        sk.args.u0C.p = D_01B01180;
        sk.args.u10.w = D_01B005F0;
        sk.args.u14.w = 1;
        func_01B0B658(&sk.args);

        sk.args.p00 = D_01B01788;
        sk.args.p04 = 0;
        func_01B0B620(&sk.args);

        st->w28 = 0;
        st->w30 = 0;
        st->state++;
        break;
    case 31:
        {
            register int t __asm__("$2") = st->w28;
            register int prev __asm__("$3") = t;
            __asm__("" : "+r"(prev));
            t = t - 1;
            __asm__("" : "+r"(t));
            st->w28 = t;
            if (prev != 0) {
                break;
            }
        }
        func_01B022A0(D_01B0E2B0 + st->w30 * 0x1020);
        if (++st->w30 >= 8) {
            st->state = 50;
            goto retry;
        }
        st->w28 = (func_001ACEA0() & 3) + 2;
        break;
    case 50:
        st->frame = 0;
        st->state = 51;
        break;
    case 51:
        if (st->frame >= 25) {
            int i;
            for (i = 0; i < st->h74; i++) {
                func_001B5810(st->arr34[i], 1);
                func_001B5D38(st->arr34[i], 15, 1.0f);
            }
            st->state++;
            st->frame = 0;
        }
        break;
    case 52:
        if (st->frame >= 15) {
            D_01B01060.f30 = D_01B01060.f34 = D_01B01060.f38 =
                D_01B01060.f60 = D_01B01060.f64 = D_01B01060.f68 = D_01B01060.f6C = 1.0f;
            sk.args.p00 = &D_01B01060;
            sk.args.u08.f = 0.05f;
            sk.args.u0C.f = 1.0f;
            sk.args.p04 = 0;
            func_01B07A68(&sk.args);

            st->state = 10000;
            goto retry;
        }
        break;
    case 10000:
        sk.sp24 = task->w00;
        func_01B0CF20(&sk.sp24);
        break;
    }

    st->frame++;
}
