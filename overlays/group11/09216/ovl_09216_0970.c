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
    u8 pad158[0x08];
} OvlCtx;

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
extern u8 D_01B04100[];
extern u8 D_01B04638[];
extern OvlCtx D_01B04660[];
extern OvlMgr D_01B05160;
extern OvlCtx D_01B052D0;
extern u8 *D_01B05400;
extern u8 *D_01B05404;
extern u8 D_01B0A950[];
extern u8 D_01B82100[];

extern void *func_002B49A0(void *, int, int);
extern void func_002DCE08(Vec4 *, float (*)[4], Vec4 *);
extern void func_002DCE38(float (*)[4], float (*)[4], float (*)[4]);
extern void func_002DD020(Vec4 *, Vec4 *, Vec4 *);
extern void func_002DD038(Vec4 *, Vec4 *, Vec4 *);
extern void func_002DD128(float (*)[4]);
extern void func_002DD270(float (*)[4], float (*)[4], float);
extern double sqrt(double);

extern s32 func_01B00FD0(int);
extern void func_01B01220(int, Vec4 *, int);
extern void func_01B017E0(int, int, float (*)[4]);
extern void func_01B02C08(int, void *, void *);
extern int func_01B02CC0(void *);
extern void func_01B032C8(void *, void *, void *);
extern void *func_01B037E0(void *);
extern void func_01B039A8(void *);
extern void func_01B03A68(void *, void *, void *, int);
extern PartObj *func_01B03B40(void *, void *, float, int, int, int, void *);
extern int func_01B03C20(void *, void *);

void ovl_09216_0b98(OvlTask *a0);
void ovl_09216_0c18(void);
void ovl_09216_0db8(OvlCtx *a0);

static inline void copy_vec(Vec4 *dst, Vec4 *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

int ovl_09216_0970(void)
{
    u8 *p = D_01B82100;
    u8 *res = D_01B0A950;
    OvlMgr *mgr = &D_01B05160;
    OvlCtx *ctx;
    PartObj *obj;
    Vec4 tmp;
    Vec4 vec10;
    int i;

    D_01B05400 = p;
    D_01B05404 = p + 0x40000;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B03A68(mgr, D_01B00040, D_01B05400, 0x40000);

    ctx = &D_01B052D0;
    obj = func_01B03B40(mgr, ctx, 0.14f, 1, 16, 0, 0);
    func_01B01220(-1, &ctx->pos, 1);
    obj->f68 *= 1.9f;
    ctx->p104 = (void *)ovl_09216_0db8;
    p += 0x140000;
    func_01B032C8(p, res, D_01B00518);
    ctx->p110 = p;

    func_01B01220(-1, &vec10, 3);
    {
        OvlCtx *e = D_01B04660;
        for (i = 0; i < D_01B00578.w04; i++, e++) {
            func_01B01220(i, &e->v130, 3);
            copy_vec(&e->v140, &vec10);
            func_002DD038(&tmp, &vec10, &e->v130);
            e->f150 = (float)sqrt((double)(tmp.x * tmp.x + tmp.z * tmp.z));
            e->w154 = 0;
        }
    }

    func_01B02C08(-1, D_01B04638, D_01B00530);
    func_01B039A8(func_01B037E0((void *)ovl_09216_0b98));
    return 0;
}

void ovl_09216_0b98(OvlTask *a0)
{
    int r = func_01B03C20(&D_01B05160, D_01B05404);
    ovl_09216_0c18();
    if (func_01B02CC0(D_01B04638) == 1 && r == 1) {
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00950;
    }
}

void ovl_09216_0c18(void)
{
    Vec4 tmp;
    Vec4 diff;
    OvlCtx *ctx = &D_01B052D0;
    int i;

    if (ctx->w118 <= 0) {
        return;
    }
    {
        OvlCtx *e = D_01B04660;
        for (i = 0; i < D_01B00578.w04; i++, e++) {
            if (e->w154 != 1) {
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
                    func_01B03B40(&D_01B05160, e, 0.1f, 0, 0, 0, D_01B04100);
                    func_01B01220(i, &e->pos, 1);
                    e->w120 = func_01B00FD0(i);
                    e->w154 = 1;
                }
            }
        }
    }
}

void ovl_09216_0db8(OvlCtx *a0)
{
    float mat[4][4];

    if (a0->w118 >= 81) {
        a0->p104 = 0;
        return;
    }
    func_002DD128(mat);
    func_002DD270(mat, mat, 0.095993116f);
    mat[3][2] = -3.0f;
    func_01B017E0(-1, 21, a0->mat80);
    func_002DCE38(a0->mat80, a0->mat80, mat);
    {
        /* DEBT(FAKE): match a0/v0/v1 register allocation for trailing copy + byte store */
        register Vec4 *dst __asm__("$4") = &a0->pos;
        register Vec4 *src __asm__("$2") = (Vec4 *)a0->mat80[3];
        register u8 two __asm__("$3");
        MMI_COPY_LQ_A3(dst, src);
        MMI_COPY_SQ_A3(dst);
        two = 2;
        a0->b126 = two;
    }
}
