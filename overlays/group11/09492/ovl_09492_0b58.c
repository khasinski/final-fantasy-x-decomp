#include "common.h"

typedef struct {
    u8 pad0[0x18];
    u8 b18;
} Task9492;

typedef struct {
    u8 pad0[0x2C];
    int w2C;
} Ctx8FD0;

typedef struct {
    u8 pad0[0xD38];
    int wD38;
} Work9492;

extern u8 D_01B00040[];
extern u8 D_01B00558[];
extern void *D_01B00884;
extern int D_01B08FC8;
extern Ctx8FD0 D_01B08FD0;
extern int D_01B09010;
extern void *D_01B09014;
extern u8 D_01B09018[];
extern u8 D_01B09078[];
extern Work9492 *D_01B09098;
extern void *D_01B0909C;
extern u8 D_01B0EA20[];
extern u8 D_01B71000[];

extern void func_001CDDD8(int);
extern int func_002B49A0(void *, int, int);
extern void func_01B00D88(void);
extern void func_01B00ED8(void);
extern int func_01B044D0(void *);
extern void func_01B04860(int);
extern Task9492 *func_01B04FF0(void *);
extern void func_01B05070(void *);
extern void func_01B051B8(Task9492 *);
extern void func_01B05278(Ctx8FD0 *, void *, void *, int);
extern int func_01B05430(Ctx8FD0 *, void *);
extern void func_01B066D8(void);
extern void func_01B088E0(void *, void *);
extern int func_01B08900(void *);
extern void func_01B08A00(void *, int);
extern int func_01B08B38(void);

void func_01B00C68(void *);
void func_01B00D08(void);

int func_01B00B58(void)
{
    u8 *base = D_01B71000;
    Ctx8FD0 *ctx = &D_01B08FD0;
    Task9492 *t;

    D_01B09014 = base + 0x40000;
    D_01B09010 = 0;
    D_01B0909C = base + 0x140000;
    D_01B09098 = (Work9492 *)(base + 0x190000);
    ctx->w2C = func_002B49A0(D_01B0EA20, 8, 0);
    func_01B05278(ctx, D_01B00040, base, 0x40000);
    func_01B00D88();
    func_01B088E0(D_01B09018, D_01B00558);
    func_01B04860(1);
    t = func_01B04FF0((void *)func_01B00C68);
    t->b18 = 1;
    func_01B051B8(t);
    func_01B08A00(base + 0x180000, 0x200);
    t = func_01B04FF0((void *)func_01B00D08);
    t->b18 = 2;
    func_01B051B8(t);
    return 0;
}

void func_01B00C68(void *a0)
{
    Work9492 *w = D_01B09098;
    int r0;
    int r1;

    func_01B066D8();
    D_01B00884 = D_01B0909C;
    r0 = func_01B08900(D_01B09018);
    r1 = func_01B044D0(D_01B09078);
    if (r0 != 0 && r1 != 0) {
        w->wD38 = 1;
        func_01B00ED8();
        func_01B05070(a0);
    }
}

void func_01B00D08(void)
{
    Work9492 *w = D_01B09098;
    int r = func_01B05430(&D_01B08FD0, D_01B09014);

    if (r == 1 && func_01B08B38() == 0 && w->wD38 == 1) {
        func_001CDDD8(D_01B08FC8);
    }
}
