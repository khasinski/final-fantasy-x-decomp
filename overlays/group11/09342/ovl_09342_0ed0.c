#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x08];
    s32 w08;
    u8 pad0C[0x08];
    s32 w14;
    u8 pad18[0x08];
    Vec4 v20;
    Vec4 v30;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    u8 pad54[0x0C];
} Obj5670;

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    void *w14;
    u8 b18;
} OvlTask;

extern s32 D_01B0058C;
extern u8 D_01B00970[];
extern u8 D_01B055F8[];
extern Obj5670 D_01B05670[];
extern u8 D_01B05970[];
extern u8 *D_01B05AE4;

extern void func_00103788(int);
extern void func_0010C790(void *, int);
extern void *func_001B4E58(u32);
extern void *func_001B4EA8(u32, int);
extern u8 *func_001E4F58(int, s32 *);

extern void func_01B015A0(int, Vec4 *, int);
extern void func_01B016D0(int, Vec4 *);
extern s32 func_01B02098(int, int);
extern void func_01B02900(s32, int);
extern int func_01B03040(void *);
extern void func_01B03BE0(OvlTask *);
extern int func_01B03FA0(void *, void *);

void ovl_09342_10d0(int a0);
void ovl_09342_1128(u8 *a0, int a1, int a2);

void ovl_09342_0ed0(OvlTask *a0)
{
    int r1 = func_01B03040(D_01B055F8);
    int r2 = func_01B03FA0(D_01B05970, D_01B05AE4);
    int i;
    int n;

    func_00103788(1);
    if (r2 == 1 && r1 == 1) {
        n = D_01B0058C;
        for (i = 0; i < n; i++) {
            if (D_01B05670[i].w50 == 0) {
                break;
            }
        }
        if (i == n) {
            TaskSub *sub;
            ovl_09342_10d0(0);
            sub = a0->p08;
            *(void *volatile *)&a0->w14 = (void *)3;
            *(volatile s32 *)&sub->p10 = (s32)D_01B00970;
        }
    }
}

void ovl_09342_0fb0(OvlTask *a0)
{
    Vec4 v00;
    Obj5670 *e = (Obj5670 *)a0->w14;

    if (e->w40 > 0) {
        e->w40--;
        return;
    }
    if (e->w14 == 0 && func_01B03040(e) == 1) {
        func_01B02900(e->w08, 2);
    }
    VU0_LQC2_INPUTS(1, &e->v20, &e->v30, &e->v30);
    VU0_LQC2(2, 0, &e->v30);
    VU0_OP("vadd.xyz $vf1xyz, $vf1xyz, $vf2xyz");
    VU0_SQC2(1, 0, &e->v20);

    func_01B015A0(e->w48, &v00, 0);
    VU0_LQC2(1, 0, &v00);
    VU0_LQC2(2, 0, &e->v20);
    VU0_OP("vadd.xyz $vf1xyz, $vf1xyz, $vf2xyz");
    VU0_SQC2(1, 0, &v00);
    func_01B016D0(e->w48, &v00);

    if (e->w44 > 0) {
        if (--e->w44 > 0) {
            return;
        }
    }
    e->v20.x *= 0.9f;
    e->v20.y = 0.0f;
    e->v20.z *= 0.9f;
    e->v30.y = 0.0f;
    if (e->w14 == 1) {
        e->w50 = 1;
        func_01B02098(e->w48, e->w4C);
        func_01B03BE0(a0);
    }
}

void ovl_09342_10d0(int a0)
{
    s32 n;
    u8 *p;

    p = func_001E4F58(9, &n);
    ovl_09342_1128(p, n, a0);
    p = func_001E4F58(11, &n);
    ovl_09342_1128(p, n, a0);
}

void ovl_09342_1128(u8 *a0, int a1, int a2)
{
    int i;
    for (i = 0; i < a1; i++) {
        u32 id = a0[i];
        void *p;
        func_0010C790(func_001B4E58(id), a2);
        p = func_001B4EA8(id, 0);
        if (p != 0) {
            func_0010C790(p, a2);
        }
        p = func_001B4EA8(id, 1);
        if (p != 0) {
            func_0010C790(p, a2);
        }
    }
}
