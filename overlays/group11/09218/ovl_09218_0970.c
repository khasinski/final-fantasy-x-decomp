#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x04];
    s32 w04;
} Cfg578;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x68];
    float f68;
} PartObj;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x80];
    float mat80[4][4];
    u8 padC0[0x10];
    Vec4 pos;
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x08];
    void *p110;
    u8 pad114[0x04];
    s32 w118;
    u8 pad11C[0x04];
    s32 w120;
    u8 pad124[0x02];
    u8 b126;
    u8 pad127[0x09];
    Vec4 v130;
    Vec4 v140;
    float f150;
    s32 w154;
    s32 w158;
    u8 pad15C[0x04];
} OvlCtx;

typedef struct {
    u8 pad00[0x80];
    float mat80[4][4];
    u8 padC0[0x10];
    Vec4 pos;
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x08];
    void *p110;
    u8 pad114[0x04];
    s32 w118;
    u8 pad11C[0x0A];
    u8 b126;
    u8 pad127[0x09];
} OvlCtxSmall;

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
} OvlTask;

extern u8 D_01B00040[];
extern u8 D_01B00518[];
extern u8 D_01B00530[];
extern Cfg578 D_01B00578;
extern u8 D_01B00950[];
extern u8 D_01B043C0[];
extern u8 D_01B048F8[];
extern OvlCtx D_01B04920[];
extern OvlMgr D_01B05420;
extern OvlCtxSmall D_01B05460[];
extern u8 *D_01B057F0;
extern u8 *D_01B057F4;
extern u8 D_01B0AE00[];
extern u8 D_01B87EC0[];

extern void *func_002B49A0(void *, int, int);
extern void func_002DCE08(Vec4 *, float (*)[4], Vec4 *);
extern void func_002DCE38(float (*)[4], float (*)[4], float (*)[4]);
extern void func_002DD020(Vec4 *, Vec4 *, Vec4 *);
extern void func_002DD038(Vec4 *, Vec4 *, Vec4 *);
extern void func_002DD128(float (*)[4]);
extern void func_002DD270(float (*)[4], float (*)[4], float);
extern void func_002DD318(float (*)[4], float (*)[4], float);
extern float func_002E94A0(float, float);
extern double sqrt(double);

extern s32 func_01B01290(int);
extern void func_01B014E0(int, Vec4 *, int);
extern float func_01B01930(int);
extern void func_01B01980(int, int, int, Vec4 *);
extern void func_01B01AA0(int, int, float (*)[4]);
extern void func_01B02660(int, float, float, float, int);
extern void func_01B02EC8(int, void *, void *);
extern int func_01B02F80(void *);
extern void func_01B03588(void *, void *, void *);
extern void *func_01B03AA0(void *);
extern void func_01B03C68(void *);
extern void func_01B03D28(void *, void *, void *, int);
extern PartObj *func_01B03E00(void *, void *, float, int, int, int, void *);
extern int func_01B03EE0(void *, void *);

void ovl_09218_0c00(OvlTask *a0);
int ovl_09218_0ce8(void);
void ovl_09218_0f28(OvlCtxSmall *a0);
void ovl_09218_0fd0(OvlCtxSmall *a0);

static inline void copy_vec(Vec4 *dst, Vec4 *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int ovl_09218_0970(void)
{
    u8 *p = D_01B87EC0;
    u8 *res = D_01B0AE00;
    OvlMgr *mgr = &D_01B05420;
    OvlCtxSmall *ctx;
    PartObj *obj;
    Vec4 tmp;
    Vec4 vec10;
    int i;

    D_01B057F0 = p;
    D_01B057F4 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B03D28(mgr, D_01B00040, D_01B057F0, 0x40000);

    ctx = &D_01B05460[0];
    obj = func_01B03E00(mgr, ctx, 0.04f, 0, 16, 0, 0);
    func_01B014E0(-1, &ctx->pos, 1);
    obj->f68 *= 1.9f;
    ctx->p104 = (void *)ovl_09218_0f28;
    p += 0x140000;
    func_01B03588(p, res, D_01B00518);
    ctx->p110 = p;

    ctx += 2;
    obj = func_01B03E00(mgr, ctx, 0.09f, 2, 16, 0, 0);
    func_01B014E0(-1, &ctx->pos, 3);
    obj->f68 *= 1.2f;
    ctx->p104 = (void *)ovl_09218_0fd0;

    func_01B014E0(-1, &vec10, 3);
    {
        OvlCtx *e = D_01B04920;
        for (i = 0; i < D_01B00578.w04; i++, e++) {
            func_01B014E0(i, &e->v130, 3);
            copy_vec(&e->v140, &vec10);
            func_002DD038(&tmp, &vec10, &e->v130);
            e->f150 = (float)sqrt((double)(tmp.x * tmp.x + tmp.z * tmp.z));
            e->w158 = 0;
        }
    }

    func_01B02EC8(-1, D_01B048F8, D_01B00530);
    func_01B03C68(func_01B03AA0((void *)ovl_09218_0c00));
    return 0;
}

void ovl_09218_0c00(OvlTask *a0)
{
    int r = func_01B03EE0(&D_01B05420, D_01B057F4);
    int i;

    ovl_09218_0ce8();
    if (func_01B02F80(D_01B048F8) == 1 && r == 1) {
        for (i = 0; i < D_01B00578.w04; i++) {
            func_01B02660(i, 1.0f, 1.0f, 1.0f, 1);
        }
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00950;
    }
}

int ovl_09218_0ce8(void)
{
    Vec4 tmp;
    Vec4 diff;
    OvlCtxSmall *ctx = &D_01B05460[0];
    int ret;
    int i;

    if (ctx->w118 <= 0) {
        return 0;
    }
    ret = 1;
    {
        OvlCtx *e = D_01B04920;
        for (i = 0; i < D_01B00578.w04; i++, e++) {
            if (e->w158 == 1) {
                if (e->w154 > 0) {
                    if (--e->w154 == 0) {
                        func_01B02660(i, 1.0f, 1.0f, 1.0f, 8);
                    }
                    ret = 0;
                } else if (e->w154 >= -7) {
                    e->w154--;
                    ret = 0;
                }
            } else {
                ret = 0;
                ctx->mat80[3][0] = 0.0f;
                ctx->mat80[3][1] = 0.0f;
                ctx->mat80[3][2] = 0.0f;
                ctx->mat80[3][3] = 1.0f;
                tmp.x = 0.0f;
                tmp.y = 0.0f;
                tmp.z = -e->f150;
                tmp.w = 1.0f;
                func_002DCE08(&tmp, ctx->mat80, &tmp);
                func_002DD020(&tmp, &tmp, &e->v140);
                func_002DD038(&diff, &tmp, &e->v130);
                if ((float)sqrt((double)(diff.x * diff.x + diff.z * diff.z)) < e->f150 * e->f150 * 0.0018f) {
                    func_01B03E00(&D_01B05420, e, 0.1f, 1, 0, 0, D_01B043C0);
                    func_01B014E0(i, &e->pos, 1);
                    e->w120 = func_01B01290(i);
                    e->w154 = 40;
                    e->w158 = 1;
                    func_01B02660(i, 0.5f, 0.5f, 0.5f, 8);
                }
            }
        }
    }
    return ret;
}

void ovl_09218_0f28(OvlCtxSmall *a0)
{
    float mat[4][4];

    if (a0->w118 >= 81) {
        a0->p104 = 0;
        return;
    }
    func_002DD128(mat);
    func_002DD270(mat, mat, 0.095993116f);
    mat[3][2] = 3.0f;
    func_01B01AA0(-1, 21, a0->mat80);
    func_002DCE38(a0->mat80, a0->mat80, mat);
    {
        register Vec4 *dst __asm__("$4") = &a0->pos;
        register Vec4 *src __asm__("$2") = (Vec4 *)a0->mat80[3];
        register u8 two __asm__("$3");
        MMI_COPY_LQ_A3(dst, src);
        MMI_COPY_SQ_A3(dst);
        two = 2;
        a0->b126 = two;
    }
}

void ovl_09218_0fd0(OvlCtxSmall *a0)
{
    float mat[4][4];
    Vec4 in;
    Vec4 out;
    float ang;

    if (a0->w118 >= 81) {
        a0->p104 = 0;
        return;
    }
    func_01B01AA0(-1, 21, mat);
    {
        register float z __asm__("$f0") = 0.0f;
        register Vec4 *a0_ __asm__("$4");
        register float f1 __asm__("$f1");
        register float (*a1_)[4] __asm__("$5");
        register float f2 __asm__("$f2");
        register Vec4 *a2_ __asm__("$6");
        __asm__("" : "+f"(z) : : "memory");
        a0_ = &out;
        f1 = -1000.0f;
        __asm__("" : "+r"(a0_), "+f"(f1) : : "memory");
        a1_ = mat;
        f2 = 1.0f;
        __asm__("" : "+r"(a1_), "+f"(f2) : : "memory");
        a2_ = &in;
        __asm__("" : "+r"(a2_) : : "memory");
        *(volatile float *)&in.x = f1;
        *(volatile float *)&in.z = z;
        *(volatile float *)&in.w = f2;
        *(volatile float *)&mat[3][2] = z;
        *(volatile float *)&mat[3][1] = z;
        *(volatile float *)&mat[3][0] = z;
        __asm__("" : : : "memory");
        in.y = z;
        func_002DCE08(a0_, a1_, a2_);
    }
    ang = 3.1415927f - func_002E94A0(out.z, out.x);
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    func_002DD128(a0->mat80);
    func_002DD318(a0->mat80, a0->mat80, ang);
    func_01B01980(-1, 21, 0, &a0->pos);
    a0->pos.y = func_01B01930(-1) - 0.1f;
    a0->b126 = 2;
}
