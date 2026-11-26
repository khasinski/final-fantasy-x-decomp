#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task9716;

typedef struct {
    u8 pad00[0x2C];
    int w2C;
} Ctrl9716;

extern u8 D_01B72840[];
extern u8 D_01B00040[];
extern u8 D_01B00568[];
extern int D_01B00628[];
extern int D_01B07E00;
extern Ctrl9716 D_01B07E08;
extern int D_01B07E48;
extern u8 *D_01B07E4C;
extern u8 D_01B07E50[];
extern u8 *D_01B07ED0;
extern u8 *D_01B07ED4;
extern u8 *D_01B07ED8;
extern u8 D_01B0D630[];

extern void func_01B01F40(int);
extern int func_002B49A0(void *, int, int);
extern void func_01B04AD8(void *, void *, void *, int);
extern void func_01B01718(void);
extern void func_01B01858(void);
extern void func_01B018E0(void);
extern void func_01B07D20(void *, int);
extern void func_01B07A90(void *, void *);
extern void func_01B040C0(int);
extern Task9716 *func_01B04850(void *);
extern void func_01B04A18(Task9716 *);
extern void func_01B01630(void);
extern void func_01B016A8(void);

int func_01B014D8(void)
{
    u8 *s1 = D_01B72840;
    int *p = D_01B00628;
    Ctrl9716 *s0;
    Task9716 *task;

    D_01B07E48 = 0;
    D_01B07E4C = s1 + 0x40000;
    D_01B07ED4 = s1 + 0x180000;
    D_01B07ED8 = s1 + 0x1C0000;
    D_01B07ED0 = s1 + 0x1C6800;
    p[0] = 0x14;
    p[1] = 0;
    func_01B01F40(D_01B07E00);

    s0 = &D_01B07E08;
    s0->w2C = func_002B49A0(D_01B0D630, 8, 0);
    func_01B04AD8(s0, D_01B00040, s1, 0x40000);
    func_01B01718();
    func_01B01858();
    func_01B018E0();
    func_01B07D20(s1 + 0x1C4000, 0x20);
    func_01B07A90(D_01B07E50, D_01B00568);
    func_01B040C0(1);

    task = func_01B04850(func_01B01630);
    task->b18 = 1;
    func_01B04A18(task);

    task = func_01B04850(func_01B016A8);
    task->b18 = 2;
    func_01B04A18(task);

    return 0;
}
