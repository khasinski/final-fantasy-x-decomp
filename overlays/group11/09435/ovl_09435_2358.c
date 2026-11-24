#include "common.h"

static __inline__ void copy_vec4_a3(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float vD0[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x0C];
    int f120;
    u8 pad124[0x0C];
} Part2358;

typedef struct {
    Part2358 parts[6];
    float v720[4];
    float v730[4];
    u8 pad740[0x60];
    float v7A0[4];
    float v7B0[4];
    float v7C0[4];
    u8 sub7D0[6][0x40];
    u8 pad950[0x04];
    int f954;
    int f958;
    u8 pad95C[0x04];
    int f960;
    int f964;
    u8 pad968[0x1C];
    u8 b984[16];
} Sub2358;

extern u8 D_01B00610[];
extern u8 D_01B00660[];
extern u8 D_01B00678[];
extern u8 D_01B00690[];
extern u8 D_01B006A8[];
extern u8 D_01B05AB8[];
extern u8 D_01B09180[];
extern u8 D_01B09228[];
extern u8 D_01B0ED00[];

extern float func_002B3DB0(float);
extern void func_01B01790(Sub2358 *);
extern int func_01B02988(int);
extern void func_01B02BD8(int, void *, int);
extern void func_01B045C0(int, void *, void *);
extern void func_01B04C80(void *, void *, void *);
extern void func_01B04E88(void *, int, int);
extern void func_01B054F8(void *, void *, int, int, int, void *, float);
extern float func_01B06500(float, float);

void func_01B02358(Sub2358 *s)
{
    int flag = s->f954;
    float ang;
    void *tbl;
    float scale;
    int idx;
    Part2358 *p;
    u8 *sub;

    func_01B01790(s);
    ang = func_01B06500(s->v720[1], s->v730[1]);
    if (flag == 0) {
        if (s->v720[1] <= ang) {
            tbl = D_01B00660;
        } else {
            tbl = D_01B00690;
        }
    } else {
        if (s->v720[1] <= ang) {
            tbl = D_01B00678;
        } else {
            tbl = D_01B006A8;
        }
    }
    func_01B045C0(-1, D_01B09228, tbl);

    scale = (func_002B3DB0(0.2f) + 1.0f) * 0.35f;
    idx = s->f958 - 1;
    p = &s->parts[idx];
    func_01B054F8(D_01B09180, p, 1, 3, 0, D_01B05AB8, scale);
    func_01B02BD8(s->b984[idx], p->vD0, 4);
    p->fC4 = s->v720[1];
    p->f120 = func_01B02988(s->b984[idx]);
    sub = s->sub7D0[idx];
    func_01B04C80(sub, D_01B0ED00, D_01B00610);
    p->p110 = sub;
    func_01B04E88(D_01B0ED00, 1, 0);
    func_01B02BD8(-1, s->v7B0, 0);
    {
        register void *d __asm__("$4") = s->v7C0;
        void *src = s->v7A0;
        __asm__("" : "+r"(d));
        copy_vec4_a3(d, src);
    }
    {
        register int v __asm__("$3") = 0x24;
        s->f964 = v;
        s->f960 = v;
    }
}
