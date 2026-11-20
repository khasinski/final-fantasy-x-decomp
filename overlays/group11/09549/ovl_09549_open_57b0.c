#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

extern TtCfg *D_01B004BC;
extern TtHeap D_01B004C0;
extern PppObj D_01B00570;
extern float D_01B053E0[4];
extern char D_01B07038[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern int func_01B063F0(char *, ...);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

void func_01B057B0(void)
{
    func_01B063F0(D_01B07038);
    D_006A3924 = &D_01B004C0;
    func_00267658(&D_01B00570, 0x1000, D_01B004BC->w10[1], 1);
    D_01B00570.pos[0] = 0.0f;
    D_01B00570.pos[1] = 0.0f;
    D_01B00570.pos[2] = 0.0f;
    D_01B00570.pos[3] = 1.0f;
    D_01B00570.rot[0] = 0;
    D_01B00570.rot[1] = 0;
    D_01B00570.rot[2] = 0;
    D_01B00570.rot[3] = 1;
    D_01B00570.scale[0] = 0.03125f;
    D_01B00570.scale[1] = 0.0375000015f;
    D_01B00570.scale[2] = 0.03125f;
    D_01B00570.scale[3] = 1.0f;
    D_01B053E0[0] = 0.0f;
    D_01B053E0[1] = -505.0f;
    D_01B053E0[2] = 0.0f;
    D_01B053E0[3] = 1.0f;
}

int func_01B05888(void)
{
    D_006A3924 = &D_01B004C0;
    D_01B004C0.w20 = D_01B004BC->w14;
    D_01B004C0.w24 = D_01B004BC->w18;
    D_01B004C0.w28 = D_01B004BC->w1c;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_01B00570.pos[0] = D_01B053E0[0];
    D_01B00570.pos[1] = D_01B053E0[1];
    D_01B00570.pos[2] = D_01B053E0[2];
    func_002675B0(&D_01B00570);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B004C0;
    func_00267FA0(&D_01B00570, 0x30);
    return 1;
}
