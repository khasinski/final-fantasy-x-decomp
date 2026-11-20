/* Battle-effect overlay 09584: 0x01B010D8..0x01B01554 */
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
extern void *D_006A3BCC;

extern void *D_01B00910;
extern TtCfg *D_01B00920;
extern u8 D_01B00928[];
extern PppObj D_01B00C60[];
extern int D_01B00D60;
extern int D_01B00D68[9];
extern u8 D_01B00DA0[];
extern char D_01B02788[];
extern char D_01B027A0[];
extern char D_01B027B0[];
extern char D_01B027C8[];
extern char D_01B027E0[];

int func_01B023F0(char *, ...);
void func_01B02558(void *);
void func_00110540(int, int, float);
void func_00173A90(int);
void func_00173A70(int);
void func_00267658(PppObj *, int, int, int);
void func_0010C790(int, int);
void func_002DA610(int, int);
void func_002B2730(int);
void func_002675B0(void *);
void func_002DCE38(void *, void *, void *);
int func_00267FA0(void *, int);
void func_00103788(int);
void func_00267530(void *);

void func_01B010D8(int *p)
{
    func_01B023F0(D_01B02788, D_01B00D60);
    func_00110540(*p, 0x14, 0.0f);
}

int func_01B01118(void)
{
    func_01B023F0(D_01B027A0, D_01B00D60);
    func_00173A90(1);
    return 1;
}

int func_01B01150(void)
{
    return 1;
}

int func_01B01158(void)
{
    func_01B023F0(D_01B027B0, D_01B00D60);
    func_00173A70(1);
    return 1;
}

void func_01B01190(void)
{
    D_006A3BCC = D_01B00910;
    func_01B02558(D_01B00DA0);
}

int func_01B011B0(PppObj *p)
{
    int i;

    func_01B023F0(D_01B027A0, D_01B00D60);
    D_006A3924 = D_01B00928;
    func_00267658(p, 0x1000, D_01B00920->w10[6], 1);
    p->pos[0] = 0.200000003f;
    p->pos[1] = -30.3999977f;
    p->pos[2] = 139.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.175595999f;
    p->scale[3] = 1.0f;
    for (i = 0; i < 9; i++) {
        func_0010C790(D_01B00D68[i], 1);
    }
    return 1;
}

int func_01B012C0(PppObj *p)
{
    func_002DA610(0, 0);
    func_002B2730(0);
    func_002675B0(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00928;
    if (func_00267FA0(p, 0x30) != 0) {
        func_00103788(1);
        return 0;
    }
    func_00103788(1);
    return 1;
}

int func_01B01380(PppObj *p)
{
    int i;

    func_01B023F0(D_01B027C8, D_01B00D60);
    for (i = 0; i < 9; i++) {
        func_0010C790(D_01B00D68[i], 0);
    }
    D_006A3924 = D_01B00928;
    func_00267530(p);
    return 1;
}

int func_01B01410(PppObj *p)
{
    func_01B023F0(D_01B027E0, D_01B00D60);
    if (p - D_01B00C60 == 0) {
        D_006A3924 = D_01B00928;
        func_00267658(p, 0x1000, D_01B00920->w10[3], 1);
        p->pos[0] = -0.799998999f;
        p->pos[1] = -1.99999702f;
        p->pos[2] = 135.0f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0985959992f;
        p->scale[3] = 1.0f;
    } else {
        D_006A3924 = D_01B00928;
        func_00267658(p, 0x1000, D_01B00920->w10[4], 1);
        p->pos[0] = -0.799998999f;
        p->pos[1] = -35.3996506f;
        p->pos[2] = 135.0f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0795959979f;
        p->scale[3] = 1.0f;
    }
    return 1;
}
