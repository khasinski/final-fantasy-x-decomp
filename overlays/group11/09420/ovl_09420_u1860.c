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
    u8 pad70[0x10];
} TtPart;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

extern float D_01B00790[2][2][4];
extern TtCfg *D_01B00878;
extern u8 D_01B00880[];
extern TtPart D_01B01030[];
extern int D_01B01258;
extern int D_01B01590;
extern char D_01B04478[];

int func_01B03858(char *, ...);
void func_002675B0(void *);
void func_00267658(void *, int, int, int);
int func_00267FA0(void *, int);
void func_002DCE38(void *, void *, void *);
void func_002DD020(float *, float *, float *);
void func_002DD038(float *, float *, float *);
void func_002DD998(float *, float *, float);

int func_01B01860(TtPart *p)
{
    func_01B03858(D_01B04478, D_01B01258);
    if (p - D_01B01030 == 0) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[15], 1);
        p->pos[0] = -155.0405579f;
        p->pos[1] = -121.0739441f;
        p->pos[2] = 146.0440063f;
        p->pos[3] = 0.0f;
        p->rot[0] = 0;
        p->rot[1] = 0x7183;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.1104919985f;
        p->scale[3] = 1.0f;
    } else {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[16], 1);
        p->pos[0] = -159.4998474f;
        p->pos[1] = -121.0054626f;
        p->pos[2] = 137.3176575f;
        p->pos[3] = 0.0f;
        p->rot[0] = 0;
        p->rot[1] = 0x6A24;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.1003910005f;
        p->scale[3] = 1.0f;
    }
    return 1;
}

int func_01B019B8(TtPart *p)
{
    float diff[4];
    float scaled[4];
    float t = (float)(D_01B01590 - 0x10A) / 51.0f;

    if (p - D_01B01030 == 0) {
        func_002DD038(diff, D_01B00790[0][1], D_01B00790[0][0]);
        func_002DD998(scaled, diff, t);
        func_002DD020(p->pos, D_01B00790[0][0], scaled);
    } else {
        func_002DD038(diff, D_01B00790[1][1], D_01B00790[1][0]);
        func_002DD998(scaled, diff, t);
        func_002DD020(p->pos, D_01B00790[1][0], scaled);
    }
    func_002675B0(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00880;
    return func_00267FA0(p, 0x30) == 0;
}
