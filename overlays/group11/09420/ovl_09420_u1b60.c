#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct TtPart {
    u8 pad00[0x40];
    float pos[4];
    int rot[4];
    float scale[4];
} TtPart;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

extern TtCfg *D_01B00878;
extern u8 D_01B00880[];
extern int D_01B01254;
extern int D_01B01258;
extern int D_01B01590;
extern char D_01B044A8[];
extern char D_01B044C0[];

int func_01B03858(char *, ...);
void func_00107428(int, int, int, float *);
void func_002675B0(void *);
void func_00267658(void *, int, int, int);
int func_00267FA0(void *, int);
void func_002DCE38(void *, void *, void *);

int func_01B01B60(TtPart *p)
{
    func_01B03858(D_01B044A8, D_01B01258);
    D_006A3924 = D_01B00880;
    func_00267658(p, 0x1000, D_01B00878->w10[12], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0x4000;
    p->rot[1] = 0x6000;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0684959963f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B01C18(TtPart *p)
{
    int cnt;

    func_00107428(D_01B01254, 0xB, 0, p->pos);
    func_002675B0(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    cnt = D_01B01590;
    if ((u32)(cnt - 0xA8) < 10) {
        return 1;
    }
    if (cnt == 0xB2) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[14], 1);
        p->scale[2] = p->scale[1] = p->scale[0] = 0.1232927963f;
        p->scale[3] = 1.0f;
        func_01B03858(D_01B044C0);
    }
    D_006A3924 = D_01B00880;
    return func_00267FA0(p, 0x30) == 0;
}
