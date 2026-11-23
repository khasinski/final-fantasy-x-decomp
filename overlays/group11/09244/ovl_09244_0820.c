/* EE Battle-Effect Overlay: group 0x11, file 09244 (0x01B00820..0x01B00AF4)
 * Load base: 0x01B00000, .text: 0x01B00820..0x01B00AF4 (1 function)
 */
#include "common.h"
#include "vu0.h"

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct OvlMgr {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct OvlCtx {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x04];
    Vec4 pos;
    float fE0;
    float fE4;
    float fE8;
    u8 padEC[0x34];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct SubC0 {
    u8 pad00[0x14];
    int w14;
    u8 pad18[0x90];
    int wA8;
    u8 padAC[0x04];
    u16 hB0;
    u8 padB2[0x0E];
} SubC0;

typedef struct Sub5790 {
    u8 pad00[0x54];
    int w54;
} Sub5790;

extern u8 D_01B00040[];
extern int D_01B00388[4];
extern u8 D_01B00398[];
extern u8 D_01B003C8[];
extern u8 D_01B05128[];
extern OvlCtx D_01B05150[4];
extern SubC0 D_01B05610[2];
extern Sub5790 D_01B05790;
extern int D_01B057F0;
extern OvlMgr D_01B057F8;
extern void *D_01B05838;
extern void *D_01B0583C;
extern u8 D_01B0B1B0[];
extern u8 D_01B76600[];

extern void func_01B00AF8(void *);
extern void func_01B03EC0(void);
extern void func_01B03ED0(void);

void *op_oef2_a_get(void *, int, int);
float func_002B3DB0(float);
void func_01B03828(void *, void *, void *, int);
void func_01B00FE0(int, void *, int);
void func_01B03900(void *, void *, int, int, float, int, void *);
int func_01B00D90(int);
void func_01B04630(void *, void *, void *);
void func_01B04738(void *, void *, void *);
void func_01B04C88(void *, int, void *, int, float, float, float);
void func_01B04FB0(void *, void *, void *, int);
void func_01B029C8(int, void *, void *);
u8 *func_01B035A0(void *);
void func_01B03768(void *);

int func_01B00820(void)
{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    u8 *buf = D_01B76600;
    OvlMgr *mgr;
    OvlCtx *ctx;
    int i;
    u8 *t;

    D_01B05838 = buf;
    D_01B0583C = buf + 0x40000;
    mgr = &D_01B057F8;
    mgr->w2C = op_oef2_a_get(D_01B0B1B0, 8, 0);
    func_01B03828(mgr, D_01B00040, D_01B05838, 0x40000);

    ctx = D_01B05150;
    func_01B00FE0(0, &v0, 1);
    for (i = 0; i < 4; i++) {
        func_01B03900(mgr, ctx, 0, D_01B00388[i], 0.15f, 0,
                      (i == 3) ? func_01B03EC0 : func_01B03ED0);
        {
            register Vec4 *vp __asm__("$3") = &ctx->pos;
            MMI_COPY_LQ_A3(vp, &v0);
            MMI_COPY_SQ_A3(vp);
        }
        ctx->fC0 = func_002B3DB0(6.2831855f);
        ctx->fC4 = func_002B3DB0(6.2831855f);
        ctx->fC8 = func_002B3DB0(6.2831855f);
        ctx->fE0 += func_002B3DB0(4.0f);
        ctx->fE4 += func_002B3DB0(3.0f);
        ctx->fE8 += func_002B3DB0(4.0f);
        ctx->w120 = func_01B00D90(0);
        ctx++;
    }

    v0.y = 0.0f;
    func_01B00FE0(-1, &v1, 3);
    func_01B04630(&v2, &v1, &v0);
    v1.x = 0.0f;
    v1.y = 0.0f;
    v1.z = 30.0f;
    v1.w = 0.0f;
    v2.x = 0.0f;
    v2.w = 0.0f;
    func_01B04738(&v2, &v0, &v1);

    func_01B04C88(&D_01B05610[0], -1, &v0, 0x1E, 0.5f, 0.7f, 0.99f);
    D_01B057F0 = 0;
    D_01B05610[0].w14 = 1;
    func_01B04FB0(&D_01B05790, D_01B0B1B0, D_01B00398, 1);
    D_01B05790.w54 = -1;
    func_01B029C8(-1, D_01B05128, D_01B003C8);
    t = func_01B035A0(func_01B00AF8);
    t[0x18] = 2;
    func_01B03768(t);
    return 0;
}
