/* Battle-effect overlay 09709: 0x01B017B0..0x01B0197C */
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
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern float D_01B00630;
extern TtCfg *D_01B00654;
extern u8 D_01B00658[];
extern int D_01B00A90;
extern int D_01B00A94;
extern char D_01B02620[];

int func_01B02170(char *, ...);
void func_01B01D08(int, int, float (*)[4]);
void func_01B01E98(float (*)[4], float *);
void func_01B01E08(float (*)[4], float);
void func_00267658(PppObj *, int, int, int);
int func_00267FA0(PppObj *, int);
void func_002DD0B0(float *, float *);
void func_002DD998(float *, float *, float);
void func_002DD0C0(void *, void *);
void func_002DCE38(void *, void *, void *);

int func_01B017B0(PppObj *p)
{
    func_01B02170(D_01B02620, D_01B00A90);
    D_006A3924 = D_01B00658;
    func_00267658(p, 0x1000, D_01B00654->w10[4], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.230594993f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B01860(PppObj *p)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float v[4];

    func_01B01D08(D_01B00A94, 7, m1);
    func_002DD0B0(v, m1[0]);
    v[1] = 0.0f;
    func_002DD998(v, v, -1.0f);
    func_01B01E98(m0, v);
    func_002DD0B0(m0[3], m1[3]);
    m0[3][1] = D_01B00630;
    func_01B01E08(m2, p->scale[0]);
    func_002DCE38(m0, m0, m2);
    func_002DD0C0(D_006A3930, m0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00658;
    return func_00267FA0(p, 0x30) == 0;
}
