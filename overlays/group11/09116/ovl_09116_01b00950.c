#include "common.h"

typedef struct Ovl09116PppMgr {
    u8 pad00[0x2C];
    void *p2C;
} Ovl09116PppMgr;

typedef struct Ovl09116PppObj {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x08];
    void *p110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} Ovl09116PppObj;

typedef struct Ovl09116Fade {
    u8 pad00[0x40];
} Ovl09116Fade;

typedef struct Ovl09116TaskObj {
    u8 pad00[0x18];
    u8 b18;
} Ovl09116TaskObj;

extern u8 D_01B00040[];
extern u8 D_01B004A0[];
extern u8 D_01B004B8[];
extern u8 D_01B004D0[];
extern int D_01B0052C;
extern u8 D_01B00CF8[];
extern u8 D_01B00D28[];
extern u8 D_01B01830[];
extern u8 D_01B04BD8[];
extern u8 D_01B062E8[];
extern Ovl09116PppObj D_01B06310[];
extern Ovl09116Fade D_01B06C90[];
extern u8 *D_01B06D10;
extern int D_01B06D14;
extern int D_01B06D18;
extern int D_01B06D1C;
extern int D_01B06D20;
extern float D_01B06D24;
extern Ovl09116PppMgr D_01B06D38;
extern Ovl09116PppObj D_01B06D80;
extern u8 *D_01B06FE0;
extern u8 *D_01B06FE4;
extern u8 D_01B0C730[];
extern u8 D_01B7E0C0[];

void *func_002B49A0(void *a0, int a1, int a2);
int func_002EFD78(void);
void func_01B01320(void *a0, int a1);
int func_01B01AA8(int a0);
void func_01B01CF8(int a0, float *a1, int a2);
void func_01B036E0(int a0, void *a1, void *a2);
void func_01B03B28(int a0);
void func_01B03DA0(void *a0, void *a1, void *a2);
Ovl09116TaskObj *func_01B042B8(void *a0);
void func_01B04480(Ovl09116TaskObj *a0);
void func_01B04540(void *a0, void *a1, void *a2, int a3);
void *func_01B04618(void *a0, void *a1, int a2, int a3, int a4, void *a5, float a6);
void func_01B05348(float *a0, float *a1, float *a2);
float func_01B054F0(float *a0, float *a1);
void func_01B06098(void *a0, int a1, int a2, float a3, float a4);

int func_01B00950(void)
{
    u8 *base = D_01B7E0C0;
    float v00[4];
    float v10[4];
    float v20[4];
    float max_dist = 0.0f;
    float d;
    int n;
    int i = 0;
    int d_int;
    int delay;
    Ovl09116PppMgr *mgr;
    Ovl09116PppObj *obj;
    Ovl09116TaskObj *t;

    D_01B06FE0 = base;
    D_01B06FE4 = base + 0x40000;
    D_01B06D10 = base + 0x140000;

    mgr = &D_01B06D38;
    mgr->p2C = func_002B49A0(D_01B0C730, 8, 0);
    func_01B04540(mgr, D_01B00040, D_01B06FE0, 0x40000);

    obj = &D_01B06D80;
    func_01B04618(mgr, obj, 0, 0x1D, 0, 0, 0.12f);
    func_01B01CF8(-1, obj->pos, 1);
    obj->p104 = D_01B01830;
    func_01B03DA0(base + 0x18E000, D_01B0C730, D_01B004A0);
    obj->p110 = base + 0x18E000;

    func_01B01CF8(-1, v00, 1);
    n = D_01B0052C;
    for (; i < n; i++) {
        func_01B01CF8(i, v10, 1);
        d = func_01B054F0(v00, v10);
        if (max_dist < d) {
            max_dist = d;
        }
    }

    D_01B06D24 = max_dist;
    d_int = (int)(max_dist / 2.5f);
    D_01B06D14 = d_int;
    delay = d_int + 0x49;

    obj = D_01B06310;
    for (i = 0; i < n; i++, obj++) {
        func_01B04618(mgr, obj, 1, delay + (func_002EFD78() % 10), 0, D_01B04BD8, 0.2f);
        func_01B01CF8(i, obj->pos, 1);
        obj->w120 = func_01B01AA8(i);
        func_01B05348(v20, obj->pos, v00);
        obj->fC4 = v20[1];
        func_01B03DA0(base + (i * 0x40 + 0x18E040), D_01B0C730, D_01B004B8);
        obj->p110 = base + (i * 0x40 + 0x18E040);
    }

    func_01B06098(&D_01B06C90[0], 0x20, 0, 1.0f, 0.5f);
    func_01B06098(&D_01B06C90[1], 0x20, 0x94, 0.5f, 1.0f);
    func_01B03B28(1);
    D_01B06D18 = 0x1D;
    D_01B06D1C = 0x59;
    D_01B06D20 = 0x1E;
    func_01B036E0(-1, D_01B062E8, D_01B004D0);

    t = func_01B042B8(D_01B00CF8);
    t->b18 = 1;
    func_01B04480(t);

    func_01B01320(base + 0x180000, 0x200);

    t = func_01B042B8(D_01B00D28);
    t->b18 = 2;
    func_01B04480(t);

    return 0;
}
