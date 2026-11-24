#include "common.h"
#include "vu0.h"

#ifndef ARG_A2
#define ARG_A2 1
#endif
#ifndef ARG_T0
#define ARG_T0 0
#endif

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} Ctx7358;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    Vec4 vecD0;
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x1C];
} Obj130;

typedef struct {
    u8 pad00[0x10];
    Vec4 pos;
    u8 pad20[0x240];
    Vec4 pos260;
    u8 pad270[0x10];
    void *cb280;
    void *cb284;
    u8 pad288[0x8];
    s32 w290;
    s32 w294;
    u8 pad298[0x8];
} Work2A0;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Node3C28;

extern u8 D_01BA4000[];
extern u8 *D_01B07398;
extern u8 *D_01B0739C;
extern u8 *D_01B07350;
extern u8 D_01B0C690[];
extern Ctx7358 D_01B07358;
extern u8 D_01B00040[];
extern Obj130 D_01B06E50[];
extern float D_01B004C8[];
extern u8 D_01B004E0[];
extern Work2A0 D_01B06540[];
extern u8 D_01B07330[];
extern u8 D_01B004F8[];
extern u8 D_01B00D40[];
extern u8 D_01B00D70[];
extern u8 D_01B071E0[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B03EB0(void *, void *, void *, s32);
extern float func_01B01540(s32);
extern void func_01B01668(s32, void *, s32);
extern void func_01B04DC0(void *, void *, void *);
extern void func_01B03F88(void *, void *, s32, s32, s32, s32, float);
extern s32 func_002EFD78(void);
extern void func_01B03710(void *, void *, void *);
extern void func_01B00FD0(void *);
extern void func_01B00F60(void *);
extern void func_01B00DF0(void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_01B03050(s32, void *, void *);
extern Node3C28 *func_01B03C28(void *);
extern void func_01B03DF0(void *);
extern void func_01B059C0(void *, s32);

s32 ovl_09329_0970(void)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    u8 *mem = D_01BA4000;
    register u8 *res __asm__("$18");
    float f20;
    Obj130 *s4;
    s32 i;
    s32 s5;
    Node3C28 *n;
    Ctx7358 *ctx;

    D_01B0739C = mem + 0x40000;
    D_01B07350 = mem + 0x140000;
    D_01B07398 = mem;
    res = D_01B0C690;
    ctx = &D_01B07358;
    ctx->w2C = func_002B49A0(res, 8, 0);
    func_01B03EB0(ctx, D_01B00040, D_01B07398, 0x40000);

    f20 = func_01B01540(-1);
    v10.x = 0.0f;
    v10.y = f20;
    v10.z = 0.0f;
    v10.w = 0.0f;
    v20.x = 0.0f;
    v20.y = 0.0f;
    v20.z = -13.0f;
    v20.w = 1.0f;
    func_01B01668(-1, &v00, 0);
    v00.y -= 40.0f;
    func_01B04DC0(&v10, &v00, &v20);

    s4 = D_01B06E50;
    func_01B03F88(ctx, s4, ARG_A2, 4, ARG_T0, 0, 0.12f);
    MMI_COPY_LQ_A3(&s4->vecD0, &v00);
    MMI_COPY_SQ_A3(&s4->vecD0);
    {
        s32 r = func_002EFD78() % 5;
        s4->fC4 = f20;
        s4->vecD0.y += D_01B004C8[r];
    }
    mem += 0x160000;
    func_01B03710(mem, res, D_01B004E0);
    s4->p110 = mem;

    {
        Work2A0 *s1 = D_01B06540;
        MMI_COPY_LQ_A3(&s1->pos, &s4->vecD0);
        MMI_COPY_SQ_A3(&s1->pos);
        func_01B01668(0, &s1->pos260, 1);
        s4++;
        s1->w290 = 4;
        s1->cb284 = func_01B00F60;
        s1->cb280 = 0;
        s1->w294 = 0;
        s5 = 6;
        func_01B00FD0(s1);
        s1++;
        for (i = 0; i < 2; i++, s5 += 2, s1++) {
            func_01B03F88(ctx, s4, ARG_A2, s5, ARG_T0, 0, 0.12f);
            MMI_COPY_LQ_A3(&s4->vecD0, &v00);
            MMI_COPY_SQ_A3(&s4->vecD0);
            s4->fC4 = f20;
            s4->vecD0.y += D_01B004C8[func_002EFD78() % 5];
            {
                void *p = &s1->pos;
                MMI_COPY_LQ_A3(p, &s4->vecD0);
                MMI_COPY_SQ_A3(p);
            }
            func_01B01668(0, &s1->pos260, 3);
            s4++;
            v20.x = func_002B3DB0(15.0f);
            v20.y = 10.0f;
            v20.z = 5.0f - func_002B3DF8(40.0f);
            func_01B04DC0(&v10, &s1->pos260, &v20);
            {
                void (*fn)(void *) = func_01B00DF0;
                s1->w290 = s5;
                s1->w294 = i;
                s1->cb280 = (void *)fn;
                s1->cb284 = 0;
            }
            func_01B00FD0(s1);
        }
    }

    func_01B03050(-1, D_01B07330, D_01B004F8);
    n = func_01B03C28(D_01B00D40);
    n->b18 = 1;
    func_01B03DF0(n);
    func_01B059C0(D_01B071E0, 3);
    n = func_01B03C28(D_01B00D70);
    n->b18 = 2;
    func_01B03DF0(n);
    return 0;
}
