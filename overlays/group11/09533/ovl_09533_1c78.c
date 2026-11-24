#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

extern TtCfg *D_01B006C8;
extern u8 D_01B006D0;
extern PppObj D_01B00A80[];
extern int D_01B00DB0;
extern int D_01B00DB4;
extern int D_01B00E60;
extern char D_01B037E8[];
extern char D_01B03800[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;
extern int D_006A3BC4;

extern int func_01B02BC0(char *, ...);
extern void func_00107428(int, int, int, float *);
extern void func_00267530(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

int func_01B01C78(PppObj *p)
{
    func_01B02BC0(D_01B037E8, D_01B00E60);
    D_006A3924 = &D_01B006D0;
    func_00267658(p, 0x1000, D_01B006C8->w10[3], 1);
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.025f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B01D28(PppObj *p)
{
    if (D_006A3BC4 == 0) {
        if (p - D_01B00A80 == 0) {
            func_00107428(D_01B00DB0, 7, 0, p->pos);
        } else {
            func_00107428(D_01B00DB4, 7, 0, p->pos);
        }
    }
    func_002675B0(p);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B006D0;
    return func_00267FA0(p, 0x30) == 0;
}

int func_01B01E08(PppObj *p)
{
    func_01B02BC0(D_01B03800, D_01B00E60);
    D_006A3924 = &D_01B006D0;
    func_00267530(p);
    return 1;
}
