#include "common.h"

typedef struct Task9517 {
    u8 pad00[0x8];
    struct Task9517 *p08;
    u8 pad0C[0x4];
    int p10;
    int w14;
    u8 b18;
} Task9517;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} Ctrl9517;

typedef struct {
    u8 pad000[0x390];
    u8 sub390[0x270];
    int w600;
    u8 pad604[0x24];
    int w628;
    u8 pad62C[0x24];
    int w650;
    int w654;
    int w658;
    int w65C;
    int w660;
    int w664;
} Obj9517;

extern u8 D_01B83780[];
extern u8 D_01B00040[];
extern u8 D_01B00608[];
extern u8 D_01B00B58[];
extern Ctrl9517 D_01B086E8;
extern u8 *D_01B08728;
extern u8 *D_01B0872C;
extern u8 D_01B08730[];
extern u8 D_01B08790[];
extern int D_01B087A4;
extern Obj9517 *D_01B087B0;
extern u8 *D_01B087B4;
extern u8 D_01B0DF20[];

extern int func_002B49A0(void *, int, int);
extern void func_01B04C38(void *, void *, void *, int);
extern void func_01B07BF0(void *, void *);
extern void func_01B018A0(void);
extern void func_01B04220(int);
extern Task9517 *func_01B049B0(void *);
extern void func_01B04B78(Task9517 *);
extern void func_01B08100(void *);
extern int func_01B07C10(void *);
extern int func_01B03E90(void *);
extern void func_01B04A30(void *);
extern int func_01B04DF0(void *, void *);
extern void func_01B04130(void *, int);
extern void func_01B082A8(void *);

void func_01B01720(void *a0);
void func_01B017B0(Task9517 *a0);
void func_01B01828(void);
void func_01B01868(void);

int func_01B01608(void)
{
    u8 *base = D_01B83780;
    Ctrl9517 *s0;
    Task9517 *task;

    D_01B08728 = base;
    D_01B0872C = base + 0x40000;
    D_01B087B4 = base + 0x140000;
    D_01B087B0 = (Obj9517 *)(base + 0x1A0000);
    s0 = &D_01B086E8;
    s0->w2C = func_002B49A0(D_01B0DF20, 8, 0);
    func_01B04C38(s0, D_01B00040, D_01B08728, 0x40000);
    func_01B01828();
    func_01B07BF0(D_01B08730, D_01B00608);
    func_01B018A0();
    func_01B04220(1);

    task = func_01B049B0(func_01B01720);
    task->b18 = 1;
    func_01B04B78(task);

    func_01B08100(D_01B087B0->sub390);

    task = func_01B049B0(func_01B017B0);
    task->b18 = 2;
    func_01B04B78(task);

    return 0;
}

void func_01B01720(void *a0)
{
    Obj9517 *s1 = D_01B087B0;
    int s0 = func_01B07C10(D_01B08730);
    int v1 = func_01B03E90(D_01B08790);

    if (s0 == 1 && v1 == 1) {
        s1->w664 = 1;
        func_01B01868();
        func_01B04A30(a0);
    }
}

void func_01B017B0(Task9517 *a0)
{
    Obj9517 *s0 = D_01B087B0;

    if (func_01B04DF0(&D_01B086E8, D_01B0872C) == 1 && s0->w664 == 1) {
        a0->w14 = 3;
        a0->p08->p10 = (int)D_01B00B58;
    }
}

void func_01B01828(void)
{
    Obj9517 *v0 = D_01B087B0;

    v0->w658 = 200;
    v0->w664 = 0;
    v0->w660 = 60;
    v0->w65C = 60;
    v0->w600 = 0;
    v0->w628 = 0;
    D_01B087A4 = 1;
    v0->w654 = 0;
    v0->w650 = 0;
}

void func_01B01868(void)
{
    Obj9517 *s0 = D_01B087B0;

    func_01B04130(D_01B08790, 0);
    func_01B082A8(s0->sub390);
}
