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
    u8 pad00[0x14];
    s32 w14;
    u8 pad18[0x78];
    void *p90;
} Obj6360;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj6420;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x30];
    void *p110;
} ObjEff;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} TaskObj;

extern u8 D_01B00040[];
extern u8 D_01B005E0[];
extern u8 D_01B005F8[];
extern u8 D_01B00610[];
extern u8 D_01B00DF8[];
extern u8 D_01B00E28[];
extern u8 D_01B00F08[];
extern u8 D_01B04468[];
extern u8 D_01B06338[];
extern Obj6360 D_01B06360;
extern Obj6420 D_01B06420;
extern s32 D_01B06480;
extern s32 D_01B06484;
extern u8 *D_01B06488;
extern OvlMgr D_01B06490;
extern ObjEff D_01B06600;
extern ObjEff D_01B06730;
extern u8 *D_01B06860;
extern u8 *D_01B06864;
extern u8 D_01B0BF40[];
extern u8 D_01BA7F40[];

extern void *op_oef2_a_get(void *, int, int);

extern void func_01B015A8(int, Vec4 *, int);
extern void func_01B01780(int, Vec4 *);
extern void func_01B02F90(int, void *, void *);
extern void func_01B03650(void *, void *, void *);
extern TaskObj *func_01B03B68(void *);
extern void func_01B03D30(TaskObj *);
extern void func_01B03DF0(OvlMgr *, void *, void *, int);
extern void func_01B03EC8(OvlMgr *, ObjEff *, int, float, int, int, void *);
extern void func_01B04BF8(Vec4 *, Vec4 *, Vec4 *);
extern float func_01B04DA0(Vec4 *, Vec4 *);
extern void func_01B05900(Obj6360 *, int, Vec4 *, float, float, float, int);
extern void func_01B05C28(void *, int);
extern void func_01B061C0(Obj6420 *, void *, void *, int);

int ovl_09398_0a90(void)
{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    u8 *heap = D_01BA7F40;
    OvlMgr *mgr;
    Obj6360 *o6360;
    ObjEff *eff;
    TaskObj *t;
    s32 s0;
    u8 *q;
    float ang;

    D_01B06864 = heap + 0x40000;
    D_01B06488 = heap + 0x140000;
    D_01B06860 = heap;
    mgr = &D_01B06490;
    mgr->w2C = op_oef2_a_get(D_01B0BF40, 8, 0);
    func_01B03DF0(mgr, D_01B00040, D_01B06860, 0x40000);
    func_01B015A8(-1, &v0, 0);
    func_01B01780(-1, &v1);
    v1.y = v0.y;
    s0 = (s32)(func_01B04DA0(&v0, &v1) / 5.0f);
    o6360 = &D_01B06360;
    func_01B05900(o6360, -1, &v1, 0.2f, 1.1f, 1.0f, s0);
    o6360->w14 = 1;
    o6360->p90 = D_01B00F08;
    func_01B04BF8(&v2, &v0, &v1);
    __asm__("" : "+r"(s0) : "m"(v2));
    v2.x = 0.0f;
    s0 -= 20;
    D_01B06480 = s0;
    if (s0 <= 0) {
        D_01B06480 = 1;
    }
    D_01B06484 = 0;
    eff = &D_01B06730;
    func_01B03EC8(mgr, eff, 2, 0.1f, 10, 0, D_01B04468);
    func_01B015A8(0, &eff->vD0, 0);
    eff->vD0.y -= 15.0f;
    ang = v2.y + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    eff->fC4 = ang;
    q = heap + 0x170000;
    func_01B03650(q, D_01B0BF40, D_01B005F8);
    eff->p110 = q;
    eff = &D_01B06600;
    func_01B03EC8(mgr, eff, 1, 0.15f, D_01B06480 + 4, 0, 0);
    func_01B015A8(0, &eff->vD0, 0);
    VEC_COPY(&eff->vD0, &v1);
    {
        register float f1 __asm__("$f1") = eff->vD0.y;
        Obj6420 *o6420 = &D_01B06420;
        __asm__("" : "+f"(f1) : "r"(o6420));
        f1 -= 0.5f;
        eff->vD0.y = f1;
        eff->fC4 = v2.y;
        func_01B061C0(o6420, D_01B0BF40, D_01B005E0, 1);
        o6420->w54 = -1;
    }
    func_01B02F90(-1, D_01B06338, D_01B00610);
    t = func_01B03B68(D_01B00DF8);
    t->b18 = 1;
    func_01B03D30(t);
    func_01B05C28(heap + 0x160000, 512);
    t = func_01B03B68(D_01B00E28);
    t->b18 = 2;
    func_01B03D30(t);
    return 0;
}
