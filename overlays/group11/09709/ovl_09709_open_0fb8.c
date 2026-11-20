/* Battle-effect overlay 09709: 0x01B00FB8..0x01B01160 */
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
extern float D_01B0061C;
extern TtCfg *D_01B00654;
extern u8 D_01B00658[];
extern int D_01B00A90;
extern int D_01B00A94;
extern char D_01B02568[];

int func_01B02170(char *, ...);
void func_01B00BB8(float (*)[4], int, int, float, float);
void func_00267658(PppObj *, int, int, int);
void func_00267530(PppObj *);
int func_00267FA0(PppObj *, int);
void func_002DD0C0(void *, void *);
void func_002DCE38(void *, void *, void *);

int func_01B00FB8(PppObj *p)
{
    func_01B02170(D_01B02568, D_01B00A90);
    D_006A3924 = D_01B00658;
    func_00267658(p, 0x1000, D_01B00654->w10[5], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0599999987f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B01068(PppObj *p)
{
    float m[4][4];

    func_01B00BB8(m, D_01B00A94, 0x74, D_01B0061C, p->scale[0]);
    func_002DD0C0(D_006A3930, m);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00658;
    if (func_00267FA0(p, 0x30) != 0) {
        D_006A3924 = D_01B00658;
        func_00267530(p);
        D_006A3924 = D_01B00658;
        func_00267658(p, 0x1000, D_01B00654->w10[5], 1);
    }
    return 1;
}
