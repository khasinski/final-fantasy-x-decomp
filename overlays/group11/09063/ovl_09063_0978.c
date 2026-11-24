#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct {
    u8 pad00[0x10];
    void *p10;
} Sub08;

typedef struct {
    u8 pad00[0x8];
    Sub08 *p08;
    u8 pad0C[0x8];
    s32 w14;
} Task0978;

typedef struct {
    u8 pad00[0x76];
    s16 h76;
} Ret4268;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x4];
    u_long128 qD0;
    u8 padE0[0x50];
} Arr130;

typedef struct {
    u8 pad00[0xD0];
    u_long128 qD0;
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x24C];
    u_long128 q360;
    u8 pad370[0x10];
    void *p380;
    void *p384;
    void *p388;
    u8 pad38C[0x8];
    s32 w394;
    s32 w398;
    s16 h39C;
    u8 pad39E[0x132];
    float f4D0;
    float f4D4;
    float f4D8;
    u8 pad4DC[0x4];
    float f4E0;
    u8 pad4E4[0xC];
} Coin4F0;

extern s32 D_01B00368[];
extern s32 D_01B00308[];
extern s32 D_01B00328[];
extern float D_01B00348[];
extern u8 D_01B00388[];
extern Arr130 D_01B06010[];
extern Coin4F0 *D_01B06008;
extern u8 D_01B063A0[];
extern u8 D_01B06420[];
extern u8 D_01B0C2B0[];

extern s32 func_01B016F8(s32);
extern s32 func_001E4F40(s32);
extern s32 func_01B01568(void);
extern void func_01B01DE8(s32, s32, s32, void *);
extern void func_01B01948(s32, void *, s32);
extern void func_01B04F98(void *, void *, void *);
extern float func_01B05140(void *, void *);
extern void func_002DD038(void *, void *, void *);
extern void func_002DCFD8(void *, void *, float);
extern Ret4268 *func_01B04268(void *, void *, s32, s32, s32, s32, float);
extern void func_002DD020(void *, void *, void *);
extern float func_002B3DB0(float);
extern float func_01B01CB8(s32);
extern float func_01B01D98(s32);
extern void func_01B050A0(void *, void *, void *);
extern void func_01B039F0(void *, void *, void *);
extern void func_01B05CA0(void *, s32, float);
extern void func_01B00E10(void);
extern void func_01B00E90(void);
extern void func_01B00FE8(void);

void ovl_09063_0978(Task0978 *task)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;
    Vec4 v40;
    s32 s5;
    s32 s0;
    s32 s6;
    s32 i;
    Coin4F0 *coin;
    s32 s3;
    float fs2;
    float fs0f;
    void *mgr;

    if (--task->w14 > 0) {
        return;
    }

    s5 = func_001E4F40(func_01B016F8(-1));
    if (s5 < 0) {
        s5 = 1;
    }
    if (s5 >= 10000) {
        s5 = 9999;
    }

    {
        s32 r = func_01B01568();
        func_01B01DE8(-1, D_01B00368[r], 0, &v00);
    }
    func_01B01948(0, &v10, 4);
    func_01B04F98(&v20, &v00, &v10);
    s0 = (s32)(func_01B05140(&v00, &v10) / 3.0f);

    if (s5 >= 6000) {
        s6 = 3;
    } else if (s5 >= 3000) {
        s6 = 2;
    } else if (s5 >= 1000) {
        s6 = 1;
    } else {
        s6 = 0;
    }

    mgr = D_01B06420;
    if (s6 > 0) {
        s32 step;
        s32 delay;
        Arr130 *p;
        func_002DD038(&v30, &v10, &v00);
        func_002DCFD8(&v30, &v30, (float)s6 + 1.0f);
        copy_vec(&v40, &v00);
        step = s0 / (s6 + 1);
        delay = step;
        p = D_01B06010;
        for (i = 0; i < s6; i++, p++) {
            Ret4268 *r = func_01B04268(mgr, p, 8, delay, 0, 0, 0.0075f);
            func_002DD020(&v40, &v40, &v30);
            copy_vec(&p->qD0, &v40);
            *((float *)&p->qD0 + 3) = 1.0f;
            p->fC0 = v20.x;
            p->fC4 = v20.y;
            p->fC8 = func_002B3DB0(3.1415927f);
            r->h76 = 0x800;
            delay += step;
        }
    }

    coin = D_01B06008;
    s3 = 0;
    v20.x = 0.0f;
    i = 0;
    fs2 = -func_01B01CB8(0) * 0.5f;
    fs0f = func_01B01D98(0);
    while (s5 > 0) {
        float d;
        if (s5 < D_01B00308[i]) {
            i++;
            if (i >= 7) {
                break;
            }
            continue;
        }
        if (s3 >= 24) {
            break;
        }
        func_01B04268(mgr, coin, D_01B00328[i], 0, 0, 0, 0.01f);
        copy_vec(&coin->qD0, &v00);
        copy_vec(&coin->q360, &v10);
        d = 3.0f;
        v30.x = func_002B3DB0(5.0f);
        v30.y = func_002B3DB0(5.0f);
        v30.z = fs2 + func_002B3DB0(d);
        func_01B050A0(&v20, &coin->q360, &v30);
        if (fs0f < *((float *)&coin->q360 + 1)) {
            *((float *)&coin->q360 + 1) = fs0f;
        }
        {
            register s32 c2 __asm__("$4") = 2;
            coin->h39C = c2;
        }
        coin->p380 = D_01B06420;
        __asm__("" : "+r"(coin));
        coin->p384 = (void *)func_01B00E90;
        coin->p388 = (void *)func_01B00FE8;
        coin->w394 = -1;
        coin->w398 = s3;
        if (s3 == 0) {
            func_01B039F0(D_01B063A0, D_01B0C2B0, D_01B00388);
            coin->p110 = D_01B063A0;
        } else {
            d += func_002B3DB0(1.0f);
        }
        func_01B05CA0(coin, 1, d);
        s3++;
        coin->f4D0 = func_002B3DB0(0.31415927f);
        coin->f4D4 = func_002B3DB0(0.31415927f);
        coin->f4D8 = func_002B3DB0(0.31415927f);
        coin->f4E0 = D_01B00348[i];
        s5 -= D_01B00308[i];
        coin++;
    }

    task->p08->p10 = (void *)func_01B00E10;
}
