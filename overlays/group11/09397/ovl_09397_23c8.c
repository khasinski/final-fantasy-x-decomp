#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task9397;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} Ctrl9397;

typedef struct {
    u8 pad0000[0xE40];
    int wE40;
    float fE44;
    int wE48;
    int wE4C;
    u_long128 qE50;
    u8 pad0E60[0x330];
    u8 sub1190[0x2B0];
    int w1440;
    u8 pad1444[0x18];
    int w145C;
} Obj9397;

extern u8 D_01B90200[];
extern u8 D_01B00040[];
extern u8 D_01B00718[];
extern int D_01B00808[];
extern int D_01B09D30;
extern Ctrl9397 D_01B09D38;
extern u8 *D_01B09D78;
extern u8 *D_01B09D7C;
extern u8 D_01B09D80[];
extern u8 D_01B09DE0[];
extern int D_01B09DF4;
extern Obj9397 *D_01B09E00;
extern u8 *D_01B09E04;
extern u8 *D_01B09E08;
extern u8 D_01B0F490[];

extern void func_01B03380(int);
extern int func_002B49A0(void *, int, int);
extern void func_01B05F18(void *, void *, void *, int);
extern void func_01B09678(void *, int);
extern void func_01B08ED0(void *, void *);
extern void func_01B05500(int);
extern Task9397 *func_01B05C90(void *);
extern void func_01B05E58(Task9397 *);
extern void func_01B09750(void *);
extern int func_01B08EF0(void *);
extern int func_01B05170(void *);
extern void func_01B05D10(void *);
extern int func_01B060D0(void *, void *);
extern void func_001CDDD8(int);
extern float func_01B035A8(int);
extern void func_01B036D0(int, void *, int);
extern void func_01B098F8(void *);
extern int func_01B03518(int);
extern void func_001178E0(int);
extern void func_01B047C0(int, int);
extern void func_01B04768(int, int);
extern void func_0010D380(int, int, int);
extern void func_0010D3A8(int, int, int);
extern void func_002A7308(void *, int, int, int);
extern void func_00117A68(int);
extern void func_002A3BD8(int, void *);

void func_01B02530(void *a0);
void func_01B025B0(void);
void func_01B02618(void);
void func_01B02678(void);
void func_01B026C0(void);
void func_01B02748(void);

int func_01B023C8(void)
{
    u8 *base = D_01B90200;
    Ctrl9397 *s0;
    Task9397 *task;

    D_01B09D78 = 0;
    D_01B09D7C = base + 0x40000;
    D_01B09E04 = base + 0x180000;
    D_01B09E08 = base + 0x1C0000;
    D_01B09E00 = (Obj9397 *)(base + 0x1C6800);
    D_01B00808[0] = 0x14;
    D_01B00808[1] = 0;
    func_01B03380(D_01B09D30);

    s0 = &D_01B09D38;
    s0->w2C = func_002B49A0(D_01B0F490, 8, 0);
    func_01B05F18(s0, D_01B00040, base, 0x40000);
    func_01B02618();
    func_01B026C0();
    func_01B02748();
    func_01B09678(base + 0x1C4000, 0x20);
    func_01B08ED0(D_01B09D80, D_01B00718);
    func_01B05500(1);

    task = func_01B05C90(func_01B02530);
    task->b18 = 1;
    func_01B05E58(task);

    func_01B09750(D_01B09E00->sub1190);

    task = func_01B05C90(func_01B025B0);
    task->b18 = 2;
    func_01B05E58(task);

    return 0;
}

void func_01B02530(void *a0)
{
    Obj9397 *s1 = D_01B09E00;
    int s0 = func_01B08EF0(D_01B09D80);

    func_01B05170(D_01B09DE0);
    if (s0 == 1) {
        s1->w145C = 1;
        func_01B02678();
        func_01B05D10(a0);
    }
}

void func_01B025B0(void)
{
    Obj9397 *s0 = D_01B09E00;

    if (func_01B060D0(&D_01B09D38, D_01B09D7C) == 1 && s0->w145C == 1) {
        func_001CDDD8(D_01B09D30);
    }
}

void func_01B02618(void)
{
    Obj9397 *s0 = D_01B09E00;

    s0->wE40 = 0;
    s0->fE44 = func_01B035A8(-1);
    s0->wE48 = 0;
    s0->wE4C = 0;
    func_01B036D0(-1, &s0->qE50, 3);
    s0->w1440 = 0;
    s0->w145C = 0;
    D_01B09DF4 = 1;
}

void func_01B02678(void)
{
    func_01B098F8(D_01B09E00->sub1190);
    func_001178E0(func_01B03518(-1));
    func_01B047C0(-1, 0);
    func_01B04768(-1, 0);
}

void func_01B026C0(void)
{
    int s0 = func_01B03518(-1);

    func_0010D380(s0, -1, 0x3C00);
    func_0010D3A8(s0, -1, 0x2EE0);
    func_002A7308(D_01B09E04, s0, 1, 0);
    func_0010D380(s0, -1, -1);
    func_0010D3A8(s0, -1, -1);
    func_01B047C0(-1, 1);
}

void func_01B02748(void)
{
    int s0 = func_01B03518(-1);

    func_00117A68(s0);
    func_002A3BD8(s0, D_01B09E08);
}
