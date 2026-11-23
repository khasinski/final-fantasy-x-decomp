#include "common.h"
#include "vu0.h"

#define VEC_COPY(dst, src) do { MMI_COPY_LQ_A3((dst), (src)); MMI_COPY_SQ_A3((dst)); } while (0)

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} TaskObj;

typedef struct {
    u8 pad00[0x390];
    u8 sub390[0x30];
    Vec4 v3C0;
    u8 sub3D0[0x30];
    Vec4 v400;
    Vec4 v410;
    Vec4 v420;
    Vec4 v430;
    Vec4 v440;
    Vec4 v450;
    Vec4 v460;
    u8 pad470[0x2D0];
    float f740;
    u8 pad744[0x08];
    s32 w74C;
} Work09640;

typedef struct {
    u8 pad00[0x30];
    Vec4 v30;
    u8 pad40[0x106];
    u8 b146;
} MatObj;

extern u8 D_01B00040[];
extern u8 D_01B005B8[];
extern u8 D_01B00738[];
extern void *D_01B00AA4;
extern void *D_01B087F0;
extern OvlMgr D_01B087F8;
extern s32 D_01B08838;
extern u8 *D_01B0883C;
extern u8 D_01B08840[];
extern u8 D_01B088A0[];
extern u8 D_01B08900[];
extern s32 D_01B08914;
extern u8 D_01B08920[];
extern s32 D_01B08934;
extern Work09640 *D_01B08940;
extern u8 *D_01B08944;
extern u8 D_01B0E0A0[];
extern u8 D_01B89D80[];

extern void *op_oef2_a_get(void *, int, int);
extern void MsEffectTerminate(void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);

extern void func_01B011F0(void);
extern float func_01B016A0(int);
extern void func_01B017C8(int, Vec4 *, int);
extern void func_01B02490(int, int);
extern void func_01B02530(int, int);
extern void func_01B02A38(int, void *);
extern void func_01B02FB8(int, void *, Vec4 *);
extern void func_01B03268(void *);
extern void func_01B035F8(int);
extern TaskObj *func_01B03D88(void *);
extern void func_01B03E08(void *);
extern void func_01B03F50(TaskObj *);
extern void func_01B04010(OvlMgr *, void *, void *, int);
extern int func_01B041C8(OvlMgr *, void *);
extern void func_01B04F20(Vec4 *, Vec4 *, Vec4 *);
extern void func_01B05470(void);
extern void func_01B05B20(int);
extern void func_01B05C98(void);
extern MatObj *func_01B05E50(int);
extern void func_01B07678(void *, void *);
extern int func_01B07698(void *);
extern void func_01B07DB8(void *, int);

void ovl_09640_0ee0(void *a0);
void ovl_09640_0fa0(void);
void ovl_09640_1008(void);
void ovl_09640_1180(void);

int ovl_09640_0db0(void)
{
    u8 *heap = D_01B89D80;
    OvlMgr *mgr = &D_01B087F8;
    TaskObj *t;

    D_01B0883C = heap + 0x80000;
    D_01B08838 = 0;
    D_01B08944 = heap + 0x160000;
    D_01B08940 = (Work09640 *)(heap + 0x1C0000);
    __asm__("" : "+r"(mgr));
    mgr->w2C = op_oef2_a_get(D_01B0E0A0, 8, 0);
    func_01B04010(mgr, D_01B00040, heap + 0x60000, 0x20000);
    ovl_09640_1008();
    ovl_09640_1180();
    func_01B07678(D_01B08840, D_01B005B8);
    func_01B07678(D_01B088A0, D_01B00738);
    func_01B035F8(1);
    t = func_01B03D88(ovl_09640_0ee0);
    t->b18 = 1;
    func_01B03F50(t);
    func_01B07DB8(heap + 0x1A0000, 1024);
    t = func_01B03D88(ovl_09640_0fa0);
    t->b18 = 2;
    func_01B03F50(t);
    return 0;
}

void ovl_09640_0ee0(void *a0)
{
    Work09640 *s1 = D_01B08940;
    int s0;

    func_01B05470();
    D_01B00AA4 = D_01B08944;
    s0 = func_01B07698(D_01B08840);
    func_01B07698(D_01B088A0);
    if (s0 == 0) {
        VEC_COPY(&s1->v400, &s1->v440);
        func_01B03268(D_01B08900);
        func_01B03268(D_01B08920);
        func_01B05C98();
    } else {
        s1->w74C = 1;
        func_01B011F0();
        func_01B03E08(a0);
    }
}

void ovl_09640_0fa0(void)
{
    Work09640 *s0 = D_01B08940;

    if (func_01B041C8(&D_01B087F8, D_01B0883C) == 1 && s0->w74C == 1) {
        MsEffectTerminate(D_01B087F0);
    }
}

void ovl_09640_1008(void)
{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    Work09640 *s1 = D_01B08940;
    register Vec4 *pv1 __asm__("$18");
    register Vec4 *p420 __asm__("$19");
    register Vec4 *p440 __asm__("$20");
    register u8 *sub __asm__("$16");

    {
        register int z __asm__("$4") = 0;
        register Vec4 *p0 __asm__("$5") = &v0;
        __asm__("" : "+r"(z));
        __asm__("" : "+r"(s1) : "r"(z));
        __asm__("" : "+r"(p0) : "r"(s1));
        func_01B017C8(z, p0, 0);
    }
    VEC_COPY(&s1->v450, &v0);
    v1.x = 0.0f;
    v1.y = func_01B016A0(0);
    {
        Vec4 *v410 = &s1->v410;
        __asm__("" : "+r"(v410) : "m"(v1.y));
        v1.z = 0.0f;
        pv1 = &v1;
        __asm__("" : "+r"(pv1) : "m"(v1.z));
        VEC_COPY(v410, pv1);
    }
    p420 = &s1->v420;
    VEC_COPY(p420, &v0);
    sub = s1->sub390;
    __asm__("" : "+r"(sub));
    func_01B02A38(0, sub);
    func_01B02FB8(0, sub, pv1);
    VEC_COPY(&s1->v3C0, p420);
    VEC_COPY(&s1->v430, pv1);
    p440 = &s1->v440;
    VEC_COPY(p440, &v0);
    {
        register float fy __asm__("$f0") = s1->v440.y;
        __asm__ volatile("");
        sub = s1->sub3D0;
        __asm__ volatile("");
        s1->v440.y = fy + 47.0f;
    }
    func_01B02A38(-1, sub);
    func_01B02FB8(-1, sub, pv1);
    VEC_COPY(&s1->v400, p440);
    func_01B02530(-1, 1);
    func_01B02490(-1, 0);
    {
        Vec4 *p460 = &s1->v460;
        s1->f740 = v1.y;
        VEC_COPY(p460, p420);
        __asm__("" : "+r"(pv1));
        v2.x = 0.0f;
        v2.y = 0.0f;
        v2.z = -5.0f;
        func_01B04F20(pv1, p460, &v2);
    }
    s1->w74C = 0;
    D_01B08914 = 1;
    D_01B08934 = 1;
}

void ovl_09640_1180(void)
{
    Work09640 *s1 = D_01B08940;
    MatObj *s0;

    func_01B05B20(0);
    s0 = func_01B05E50(0);
    s0->b146 = 1;
    func_002DD128(s0);
    func_002DD318(s0, s0, s1->f740);
    VEC_COPY(&s0->v30, &s1->v420);
}
