/* Battle-effect overlay 09709: 0x01B00BB8..0x01B00D30 */
#include "common.h"

typedef struct PppObj {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

extern void *D_006A3924;
extern TtCfg *D_01B00654;
extern u8 D_01B00658[];
extern int D_01B00A90;
extern char D_01B02508[];

void func_01B01D08(int, int, float (*)[4]);
void func_01B01E98(float (*)[4], float *);
void func_01B01E08(float (*)[4], float);
void func_002DD0B0(float *, float *);
void func_002DCE38(void *, void *, void *);
int func_01B02170(char *, ...);
void func_00267658(PppObj *, int, int, int);

void func_01B00BB8(float (*out)[4], int chr, int bone, float y, float s)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float v[4];

    func_01B01D08(chr, bone, m1);
    func_002DD0B0(v, m1[1]);
    v[1] = 0.0f;
    func_01B01E98(m0, v);
    func_002DD0B0(m0[3], m1[3]);
    m0[3][1] = y;
    func_01B01E08(m2, s);
    func_002DCE38(out, m0, m2);
}

int func_01B00C58(PppObj *p)
{
    func_01B02170(D_01B02508, D_01B00A90);
    D_006A3924 = D_01B00658;
    func_00267658(p, 0x1000, D_01B00654->w10[11], 1);
    p->pos[0] = 1.90999699f;
    p->pos[1] = -0.00999999978f;
    p->pos[2] = -4.17999887f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0x4AA6;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.00545400009f;
    p->scale[3] = 1.0f;
    return 1;
}
