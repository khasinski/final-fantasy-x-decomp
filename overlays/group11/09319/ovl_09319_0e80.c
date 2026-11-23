#include "common.h"
#include "vu0.h"

#define VEC_COPY(dst, src) { MMI_COPY_LQ_A3((dst), (src)); MMI_COPY_SQ_A3((dst)); }

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x1C];
} ObjEff;

typedef struct {
    s32 w00;
    float f04;
    s32 w08;
    s32 w0C;
    Vec4 v10;
    u8 pad20[0x40];
    u8 sub60[0xA4];
    float f104;
    s32 w108;
    s32 w10C;
    s32 w110;
} Work09319;

extern u8 D_01B006C0[];
extern u8 D_01B04770[];
extern Work09319 *D_01B056EC;
extern u8 D_01B056F8[];
extern ObjEff D_01B05740[];
extern u8 D_01B0B310[];

extern void func_00103208(int);
extern void func_001178E0(int);
extern void func_002DD998(Vec4 *, Vec4 *, float);

extern void func_01B01360(Vec4 *, int);
extern int func_01B016F8(int);
extern float func_01B01788(int);
extern void func_01B018B0(int, Vec4 *, int);
extern void func_01B030A0(int, Vec4 *, Work09319 *);
extern void func_01B03958(void *, void *, void *);
extern void func_01B03EF0(void *);
extern void func_01B041D0(void *, ObjEff *, int, float, int, int, void *);

void ovl_09319_0e80(void *task)
{
    Vec4 mat[4];
    float scale[4];
    int alpha = 128;
    Work09319 *w = D_01B056EC;
    ObjEff *eff;
    float s = w->f104;
    s32 cnt;

    scale[0] = s;
    scale[1] = s;
    scale[2] = s;
    cnt = --w->w10C;
    switch (w->w108) {
    case 0:
        if (cnt == 0) {
            w->w108 = 1;
            w->w10C = 60;
        }
        return;
    case 1:
        if (cnt == 0) {
            eff = &D_01B05740[3];
            func_01B041D0(D_01B056F8, eff, 3, 0.1f, 85, 0, 0);
            {
                register Vec4 *v1 __asm__("$3") = &eff->vD0;
                VEC_COPY(v1, &w->v10);
            }
            eff->vD0.y -= 4.5f;
            eff->fC4 = w->f04;
            eff = &D_01B05740[0];
            func_01B041D0(D_01B056F8, eff, 0, 0.18f, 95, 0, D_01B04770);
            func_01B018B0(0, &eff->vD0, 1);
            eff->fC4 = func_01B01788(0);
            func_01B03958(w->sub60, D_01B0B310, D_01B006C0);
            eff->p110 = w->sub60;
            w->w10C = 90;
            w->w108 = 2;
        } else {
            register float f2 __asm__("$f2") = (float)cnt;
            register float f3 __asm__("$f3") = 60.0f;
            register float f1 __asm__("$f1") = 0.0f;
            register float f0 __asm__("$f0");
            f2 = f2 / f3;
            __asm__("" : "+f"(f1), "+f"(f2));
            f0 = 1.0f;
            __asm__("" : "+f"(f0));
            __asm__("" : "+f"(f1) : "r"(&w->v10), "f"(f0));
            f1 = f2 * f1;
            __asm__("" : "+f"(f0) : "f"(f1));
            f0 = f0 - f2;
            s = s * (f0 + f1);
            scale[0] = s;
            scale[1] = s;
            scale[2] = s;
            {
                register s32 d __asm__("$3") = 60;
                alpha = (u8)(((d - cnt) * 128) / d);
            }
        }
        break;
    case 2:
        if (cnt == 0) {
            eff = &D_01B05740[1];
            func_01B041D0(D_01B056F8, eff, 1, 0.05f, 0, 0, 0);
            VEC_COPY(&eff->vD0, &w->v10);
            eff->fC4 = w->f04;
            w->w10C = 40;
            w->w108 = 3;
            eff->vD0.y -= 1.0f;
        }
        break;
    case 3:
        if (cnt == 0) {
            func_001178E0(func_01B016F8(1));
            func_00103208(func_01B016F8(1));
            w->w110 = 1;
            func_01B03EF0(task);
            return;
        } else {
            float t = (float)cnt / 40.0f;
            float omt = 1.0f - t;
            float sy = s * (omt * 0.0f + t);
            float sxz = s * (omt * 2.0f + t);
            scale[1] = sy;
            scale[0] = sxz;
            scale[2] = sxz;
            alpha = (u8)((cnt * 128) / 40);
        }
        break;
    }
    func_01B030A0(1, mat, w);
    func_002DD998(&mat[0], &mat[0], scale[0]);
    func_002DD998(&mat[1], &mat[1], scale[1]);
    func_002DD998(&mat[2], &mat[2], scale[2]);
    VEC_COPY(&mat[3], &w->v10);
    func_01B01360(mat, alpha);
}
