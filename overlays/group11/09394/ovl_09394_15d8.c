#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task9394;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} Ctrl9394;

typedef struct {
    u8 pad000[0x980];
    int w980;
    float f984;
    int w988;
    int w98C;
    u8 sub990[0x2A0];
    u8 subC30[0x28C];
    int wEBC;
} Obj9394;

extern u8 D_01BCAB40[];
extern u8 D_01B00040[];
extern u8 D_01B006C0[];
extern u8 *D_01B009A4;
extern int D_01B096D8;
extern Ctrl9394 D_01B096E0;
extern int D_01B09720;
extern u8 *D_01B09724;
extern u8 D_01B09728[];
extern u8 D_01B09788[];
extern int D_01B0979C;
extern Obj9394 *D_01B097A8;
extern u8 *D_01B097AC;
extern u8 *D_01B097B0;
extern u8 D_01B0F2B0[];

extern int func_002B49A0(void *, int, int);
extern void func_01B04EC0(void *, void *, void *, int);
extern void func_01B018A8(void);
extern void func_01B08528(void *, void *);
extern void func_01B044A8(int);
extern Task9394 *func_01B04C38(void *);
extern void func_01B04E00(Task9394 *);
extern void func_01B090F8(void *);
extern void func_01B08B60(void *, int);
extern void func_01B06320(void);
extern int func_01B08548(void *);
extern int func_01B04118(void *);
extern void func_01B04CB8(void *);
extern int func_01B05078(void *, void *);
extern void func_001CDDD8(int);
extern void func_01B03628(int);
extern float func_01B02550(int);
extern void func_01B02678(int, void *, int);
extern void func_01B092A0(void *);

void func_01B01710(void *a0);
void func_01B017B0(void);
void func_01B01818(void);
void func_01B01880(void);

int func_01B015D8(void)
{
    u8 *s1 = D_01BCAB40;
    Ctrl9394 *s0;
    Task9394 *task;

    D_01B09720 = 0;
    D_01B09724 = s1 + 0x40000;
    D_01B097B0 = s1 + 0x140000;
    D_01B097AC = s1 + 0x190000;
    D_01B097A8 = (Obj9394 *)(s1 + 0x210000);
    s0 = &D_01B096E0;
    s0->w2C = func_002B49A0(D_01B0F2B0, 8, 0);
    func_01B04EC0(s0, D_01B00040, s1, 0x40000);
    func_01B01818();
    func_01B018A8();
    func_01B08528(D_01B09728, D_01B006C0);
    func_01B044A8(1);

    task = func_01B04C38(func_01B01710);
    task->b18 = 1;
    func_01B04E00(task);

    func_01B090F8(D_01B097A8->subC30);
    func_01B08B60(s1 + 0x1D0000, 0x800);

    task = func_01B04C38(func_01B017B0);
    task->b18 = 2;
    func_01B04E00(task);

    return 0;
}

void func_01B01710(void *a0)
{
    Obj9394 *s1 = D_01B097A8;
    int s0;
    int v1;

    func_01B06320();
    D_01B009A4 = D_01B097B0;
    s0 = func_01B08548(D_01B09728);
    v1 = func_01B04118(D_01B09788);
    if (s0 == 1 && v1 == 1) {
        s1->wEBC = 1;
        func_01B01880();
        func_01B04CB8(a0);
    }
}

void func_01B017B0(void)
{
    Obj9394 *s0 = D_01B097A8;

    if (func_01B05078(&D_01B096E0, D_01B09724) == 1 && s0->wEBC == 1) {
        func_001CDDD8(D_01B096D8);
    }
}

void func_01B01818(void)
{
    Obj9394 *s0 = D_01B097A8;

    func_01B03628(0);
    s0->w980 = 0;
    s0->f984 = func_01B02550(-1);
    s0->w988 = 0;
    s0->w98C = 0;
    func_01B02678(-1, s0->sub990, 3);
    s0->wEBC = 0;
    D_01B0979C = 1;
}

void func_01B01880(void)
{
    func_01B092A0(D_01B097A8->subC30);
    func_01B03628(1);
}
