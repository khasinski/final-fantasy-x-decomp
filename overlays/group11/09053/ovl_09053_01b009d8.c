#include "vu0.h"

typedef struct Ovl09053PppMgr {
    u8 pad00[0x2C];
    void *p2C;
} Ovl09053PppMgr;

typedef struct Ovl09053PppObj {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    u8 padE0[0x40];
    int w120;
} Ovl09053PppObj;

typedef struct Ovl09053TaskObj {
    u8 pad00[0x18];
    u8 b18;
} Ovl09053TaskObj;

extern u8 D_01B00040[];
extern u8 D_01B00540[];
extern u8 D_01B00CB8[];
extern u8 D_01B00CE8[];
extern u8 D_01B00F30[];
extern u8 D_01B046C8[];
extern u8 *D_01B05B58;
extern u8 D_01B05B60[];
extern u8 *D_01B05BA0;
extern Ovl09053PppMgr D_01B05BA8;
extern Ovl09053PppObj D_01B05BF0;
extern Ovl09053PppObj D_01B05D20;
extern u8 *D_01B05E50;
extern u8 *D_01B05E54;
extern u8 D_01B0B670[];
extern u8 D_01B5BE40[];

void *func_002B49A0(void *a0, int a1, int a2);
void func_01B00D40(void *a0, void *a1, void *a2);
int func_01B01598(int a0);
void func_01B017E8(int a0, float *a1, int a2);
void func_01B03890(void *a0, void *a1, void *a2);
Ovl09053TaskObj *func_01B03DA8(void *a0);
void func_01B03F70(Ovl09053TaskObj *a0);
void func_01B04030(void *a0, void *a1, void *a2, int a3);
void *func_01B04108(void *a0, void *a1, int a2, int a3, int a4, void *a5, float a6);
void func_01B04E38(float *a0, float *a1, float *a2);
void func_01B04F40(float *a0, float *a1, float *a2);

int func_01B009D8(void)
{
    u8 *base = D_01B5BE40;
    float v00[4];
    float v10[4];
    float v20[4];
    float v30[4];
    Ovl09053PppMgr *mgr;
    Ovl09053PppObj *p;
    Ovl09053TaskObj *t;
    float ang;

    D_01B05E50 = base;
    D_01B05E54 = base + 0x40000;
    D_01B05BA0 = base + 0x140000;
    D_01B05B58 = base + 0x160000;

    mgr = &D_01B05BA8;
    mgr->p2C = func_002B49A0(D_01B0B670, 8, 0);
    func_01B04030(mgr, D_01B00040, D_01B05E50, 0x40000);

    func_01B017E8(0, v20, 5);
    v20[1] -= 3.0f;
    func_01B017E8(-1, v30, 5);
    v30[1] -= 3.0f;

    func_01B04E38(v00, v30, v20);
    v10[0] = 0.0f;
    v10[1] = 0.0f;
    v10[2] = 6.0f;
    func_01B04F40(v00, v20, v10);

    p = &D_01B05D20;
    func_01B04108(mgr, p, 1, 0, 0, D_01B046C8, 0.07f);
    MMI_COPY_LQ_A3(p->pos, v20);
    MMI_COPY_SQ_A3(p->pos);
    ang = v00[1] + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    p->fC4 = ang;
    p->w120 = func_01B01598(0);

    p = &D_01B05BF0;
    func_01B04108(mgr, p, 0, 0x12, 0, D_01B046C8, 0.06f);
    MMI_COPY_LQ_A3(p->pos, v30);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = v00[1];
    p->w120 = func_01B01598(-1);

    func_01B03890(D_01B05B60, D_01B0B670, D_01B00540);
    v10[2] = 3.0f;
    func_01B04F40(v00, v30, v10);
    func_01B00D40(v20, v30, v00);

    t = func_01B03DA8(D_01B00CB8);
    t->b18 = 1;
    func_01B03F70(t);

    t = func_01B03DA8(D_01B00F30);
    func_01B03F70(t);

    t = func_01B03DA8(D_01B00CE8);
    t->b18 = 2;
    func_01B03F70(t);

    return 0;
}
