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
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x08];
    float fE8;
} ObjEff;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} SubA0;

typedef struct {
    s32 w00;
    float f04;
    s32 w08;
    s32 w0C;
    Vec4 v10;
    u8 pad20[0x80];
    SubA0 subA0;
    u8 padF8[0x10];
    s32 w108;
    s32 w10C;
    s32 w110;
} Work09319;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} TaskObj;

extern u8 D_01B00040[];
extern u8 D_01B006A8[];
extern u8 D_01B00700[];
extern u8 D_01B00DF0[];
extern u8 D_01B00E80[];
extern u8 D_01B056C8[];
extern u8 *D_01B056E8;
extern Work09319 *D_01B056EC;
extern u8 *D_01B056F0;
extern OvlMgr D_01B056F8;
extern ObjEff D_01B059A0;
extern u8 *D_01B05C00;
extern u8 *D_01B05C04;
extern u8 D_01B0B310[];
extern u8 D_01B93040[];

extern void *op_oef2_a_get(void *, int, int);
extern void func_002DCE08(Vec4 *, float *, Vec4 *);
extern void func_002DD128(float *);
extern void func_002DD318(float *, float *, float);

extern void func_01B01200(void);
extern void func_01B01318(void);
extern float func_01B01788(int);
extern void func_01B018B0(int, Vec4 *, int);
extern void func_01B03298(int, void *, void *);
extern TaskObj *func_01B03E70(void *);
extern void func_01B04038(TaskObj *);
extern void func_01B040F8(OvlMgr *, void *, void *, int);
extern void func_01B041D0(OvlMgr *, ObjEff *, int, float, int, int, void *);
extern void func_01B05558(void *, void *, void *, int);

int ovl_09319_0b50(void)
{
    float mat[16];
    Vec4 v40;
    u8 *heap = D_01B93040;
    OvlMgr *mgr = &D_01B056F8;
    Work09319 *w;
    ObjEff *eff;
    TaskObj *t;
    register float ang __asm__("$f20");

    D_01B05C00 = heap;
    D_01B05C04 = heap + 0x40000;
    D_01B056E8 = heap + 0x140000;
    D_01B056F0 = heap + 0x190000;
    D_01B056EC = (Work09319 *)(heap + 0x194000);
    mgr->w2C = op_oef2_a_get(D_01B0B310, 8, 0);
    func_01B040F8(mgr, D_01B00040, D_01B05C00, 0x40000);
    w = D_01B056EC;
    ang = func_01B01788(-1);
    eff = &D_01B059A0;
    func_01B041D0(mgr, eff, 2, 0.05f, 50, 0, 0);
    func_01B018B0(-1, &eff->vD0, 3);
    eff->fC4 = ang;
    eff->fE8 = -6.0f;
    v40.x = 0.0f;
    v40.y = 0.0f;
    v40.z = -6.0f;
    v40.w = 1.0f;
    func_002DD128(mat);
    func_002DD318(mat, mat, ang);
    func_002DCE08(&v40, mat, &v40);
    VEC_COPY(&w->v10, &eff->vD0);
    VU0_LQC2(1, 0, &w->v10);
    VU0_LQC2(2, 0, &v40);
    VU0_OP("vadd.xyz $vf1xyz, $vf1xyz, $vf2xyz");
    VU0_SQC2(1, 0, &w->v10);
    {
        float y;
        ang += 3.1415927f;
        y = eff->vD0.y - 1.0f;
        eff->vD0.y = y;
        __asm__("" : "+r"(w) : "m"(eff->vD0.y));
        w->w00 = 0;
    }
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    w->w08 = 0;
    w->w0C = 0;
    w->w108 = 0;
    w->w110 = 0;
    __asm__("" : "+f"(ang) : "m"(w->w08), "m"(w->w0C), "m"(w->w108));
    w->f04 = ang;
    w->w10C = 50;
    func_01B01200();
    func_01B01318();
    {
        SubA0 *sub = &w->subA0;
        func_01B05558(sub, D_01B0B310, D_01B006A8, 1);
        sub->w54 = -1;
    }
    func_01B03298(-1, D_01B056C8, D_01B00700);
    func_01B04038(func_01B03E70(D_01B00E80));
    t = func_01B03E70(D_01B00DF0);
    t->b18 = 2;
    func_01B04038(t);
    return 0;
}
