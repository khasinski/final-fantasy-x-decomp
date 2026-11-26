#include "common.h"

typedef struct Task9360 {
    u8 pad00[0x8];
    struct Task9360 *p08;
    u8 pad0C[0x4];
    int p10;
    int w14;
    u8 b18;
} Task9360;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} Ctrl9360;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float fD0;
    float fD4;
    u8 padD8[0x38];
    void *p110;
    u8 pad114[0x1C];
} Part9360;

typedef struct {
    u8 pad000[0xA0];
    u8 subA0[0x40];
    u8 subE0[0x40];
    int w120;
    int w124;
} Obj9360;

extern u8 D_01BB6840[];
extern u8 D_01B00040[];
extern u8 D_01B00658[];
extern u8 D_01B00670[];
extern u8 D_01B00698[];
extern u8 D_01B00760[];
extern int D_01B007B8[];
extern u8 *D_01B009C4;
extern u8 D_01B00C90[];
extern int D_01B08310;
extern u8 D_01B08318[];
extern u8 D_01B08378[];
extern u8 *D_01B08398;
extern Obj9360 *D_01B0839C;
extern Ctrl9360 D_01B083A0;
extern Part9360 D_01B083E0[2];
extern u8 *D_01B08640;
extern u8 *D_01B08644;
extern u8 D_01B0DBB0[];

extern void func_01B01658(int);
extern int func_002B49A0(void *, int, int);
extern void func_01B041F0(void *, void *, void *, int);
extern float func_01B01880(int);
extern void func_01B042C8(void *, void *, float, int, int, int, void *);
extern void func_01B019A8(int, void *, int);
extern void func_01B03A50(void *, void *, void *);
extern void func_01B07B30(void *, int, int, float, float);
extern void func_01B037D8(int);
extern void func_01B03970(void *, int, int, int);
extern void func_01B07858(void *, void *);
extern void func_01B03390(int, void *, void *);
extern Task9360 *func_01B03F68(void *);
extern void func_01B04130(Task9360 *);
extern void func_01B07D68(void *, int);
extern void func_01B05650(void);
extern int func_01B07878(void *);
extern int func_01B03448(void *);
extern int func_01B043A8(void *, void *);
extern void func_01B010F0(void);
extern void func_01B01250(void);
extern void func_01B01270(void);

void func_01B01008(void);
void func_01B01068(Task9360 *a0);

int func_01B00CB0(void)
{
    u8 *s4 = D_01BB6840;
    Ctrl9360 *s1;
    Part9360 *s3;
    u8 *p1;
    u8 *p2;
    Obj9360 *obj;
    Task9360 *task;
    float fs0;

    D_01B08640 = s4;
    D_01B08644 = s4 + 0x40000;
    D_01B08398 = s4 + 0x140000;
    D_01B007B8[0] = 0x14;
    D_01B007B8[1] = 0;
    func_01B01658(D_01B08310);

    s1 = &D_01B083A0;
    s1->w2C = func_002B49A0(D_01B0DBB0, 8, 0);
    func_01B041F0(s1, D_01B00040, D_01B08640, 0x40000);

    fs0 = func_01B01880(-1);
    s3 = &D_01B083E0[1];
    func_01B042C8(s1, s3, 0.3f, 1, 0xB9, 0x78, func_01B01250);
    func_01B019A8(-1, &s3->fD0, 3);
    s3->fD4 -= 0.5f;
    s3->fC4 = fs0;
    p1 = s4 + 0x180130;
    func_01B03A50(p1, D_01B0DBB0, D_01B00658);
    s3->p110 = p1;

    s3 = &D_01B083E0[0];
    func_01B042C8(s1, s3, 0.5f, 0, 0x131, 0x3C, func_01B01270);
    func_01B019A8(-1, &s3->fD0, 0);
    {
        float f2 = fs0 + 3.1415927410125732f;
        if (f2 > 3.1415927410125732f) {
            f2 -= 6.2831854820251465f;
        } else if (f2 < -3.1415927410125732f) {
            f2 += 6.2831854820251465f;
        }
        s3->fC4 = f2;
    }
    s3->fD4 -= 5.0f;
    p2 = s4 + 0x180170;
    func_01B03A50(p2, D_01B0DBB0, D_01B00670);
    s3->p110 = p2;

    obj = (Obj9360 *)(s4 + 0x180000);
    D_01B0839C = obj;
    func_01B07B30(obj->subA0, 0x40, 0, 1.0f, 0.5f);
    func_01B07B30(obj->subE0, 0x34, 0x1C7, 0.5f, 1.0f);
    func_01B037D8(1);
    func_01B03970(D_01B0DBB0, 0, 0x40, 0x100);
    func_01B03970(D_01B0DBB0, 1, 0x40, 0x100);
    func_01B07858(D_01B08318, D_01B00698);
    func_01B03390(-1, D_01B08378, D_01B00760);

    task = func_01B03F68(func_01B01008);
    task->b18 = 1;
    func_01B04130(task);

    func_01B07D68(s4 + 0x170000, 0x200);

    task = func_01B03F68(func_01B010F0);
    task->w14 = 0xA0;
    func_01B04130(task);

    task = func_01B03F68(func_01B01068);
    task->b18 = 2;
    func_01B04130(task);

    return 0;
}

void func_01B01008(void)
{
    Obj9360 *s0 = D_01B0839C;

    func_01B05650();
    D_01B009C4 = D_01B08398;
    s0->w124 = func_01B07878(D_01B08318);
    s0->w120 = func_01B03448(D_01B08378);
}

void func_01B01068(Task9360 *a0)
{
    Obj9360 *s0 = D_01B0839C;

    if (func_01B043A8(&D_01B083A0, D_01B08644) == 1 && s0->w120 == 1 && s0->w124 == 1) {
        a0->w14 = 3;
        a0->p08->p10 = (int)D_01B00C90;
    }
}
