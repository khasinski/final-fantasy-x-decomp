#include "common.h"

extern int D_01B00658;
extern float D_01B00770[4];
extern int D_01B00780;
extern float D_01B00A00[4];
extern float D_01B00A90[4];
extern int D_01B00AA8;

extern void func_00107BE8(int, int);
extern void func_0010D720(void);
extern void func_0010D728(int);
extern void func_0010DB58(int, float, float, float, int, int, int, int, float);
extern void func_0010DC38(int, int);
extern void func_002DD020(void *, void *, void *);

int func_01B045B0(void)
{
    func_0010D728(4);
    func_0010DB58(0, 0.0f, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0, 100.0f);
    func_0010DB58(1, 0.0f, 0.0f, 0.0f, 1, 1, 1, 1, 100.0f);
    func_0010DB58(2, 0.0f, 0.0f, 0.0f, 1, 1, 1, 2, 100.0f);
    func_0010DB58(3, 0.0f, 0.0f, 0.0f, 1, 1, 1, 3, 100.0f);
    func_0010DC38(D_01B00658, 0xF);
    func_00107BE8(D_01B00658, 1);
    return 1;
}

int func_01B046B8(void)
{
    func_002DD020(D_01B00A90, D_01B00A00, D_01B00770);
    func_0010DB58(0, D_01B00A90[0], D_01B00A90[1], D_01B00A90[2], 0xFF, 0xFF, 0xFF, 0, 1000.0f);
    func_0010DB58(3, D_01B00A90[0], D_01B00A90[1], D_01B00A90[2], D_01B00780, D_01B00780, D_01B00780, 3, 100.0f);
    return D_01B00AA8 != 1;
}

int func_01B04760(void)
{
    func_00107BE8(D_01B00658, 0);
    func_0010D720();
    return 1;
}
