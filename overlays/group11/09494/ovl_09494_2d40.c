#include "vu0.h"

typedef struct {
    u8 pad00[0xC0];
    float rot[3];
    u8 padCC[4];
    float pos[4];
} Ctx2D40;

typedef struct {
    float pos[4];   /* 0x00 */
    float vel[3];   /* 0x10 */
    float f1C;      /* 0x1C */
    float acc[3];   /* 0x20 */
    float f2C;      /* 0x2C */
    u8 unk30[0x0C]; /* 0x30 */
    float f3C;      /* 0x3C */
    u8 pad40[0x0C]; /* 0x40 */
    int w4C;        /* 0x4C */
    int w50;        /* 0x50 */
} Part2D40;

typedef struct {
    u8 pad00[0x1C00];
    float vec1C00[4];
    u8 pad1C10[0x40];
    float vec1C50[4];
    u8 pad1C60[0x2C4];
    int w1F24;
} Work2D40;

extern Work2D40 *D_01B0A310;
extern u8 D_01B0A228[];

extern float func_002B3DB0(float);
extern void func_01B06108(void *, void *, float, int, int, int, void *);
extern int *func_01B06698(void *, int);
extern void func_01B074D0(void *, int);
extern Part2D40 *func_01B09C40(void);
extern Ctx2D40 *func_01B0A190(void);

static inline void copy_vec(float *dst, float *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B02D40(void)
{
    Work2D40 *s0 = D_01B0A310;
    int i;

    if (--s0->w1F24 == 0) {
        Ctx2D40 *s1 = func_01B0A190();
        if (s1 != 0) {
            float s = (func_002B3DB0(0.2f) + 1.0f) * 0.02f;
            func_01B06108(D_01B0A228, s1, s, 11, 0, 0, 0);
            copy_vec(s1->pos, s0->vec1C00);
            s1->rot[0] = s0->vec1C50[0];
            s1->rot[1] = s0->vec1C50[1];
            s1->rot[2] = func_002B3DB0(3.1415927410125732f);
        }
        s0->w1F24 = 3;
    }

    for (i = 0; i < 3; i++) {
        Part2D40 *p = func_01B09C40();
        if (p == 0) {
            return;
        }
        func_01B074D0(p->unk30, *func_01B06698(D_01B0A228, 7));
        copy_vec(p->pos, s0->vec1C00);
        p->pos[0] += func_002B3DB0(4.0f);
        p->pos[1] += func_002B3DB0(4.0f);
        p->pos[2] += func_002B3DB0(4.0f);
        p->vel[0] = func_002B3DB0(0.3f);
        p->vel[1] = func_002B3DB0(0.3f);
        p->vel[2] = func_002B3DB0(0.3f);
        p->f1C = func_002B3DB0(3.1415927410125732f);
        p->acc[0] = p->vel[0] * -(func_002B3DB0(0.01f) + 0.02f);
        p->acc[1] = p->vel[1] * -(func_002B3DB0(0.01f) + 0.02f);
        p->acc[2] = p->vel[2] * -(func_002B3DB0(0.01f) + 0.02f);
        p->f2C = 1.0f;
        p->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.05f;
        p->w50 = 0;
        p->w4C = 31;
    }
}
