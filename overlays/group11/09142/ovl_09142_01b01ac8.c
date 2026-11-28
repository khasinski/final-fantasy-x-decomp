#include "common.h"

extern void *D_01B00658;
extern float D_01B00BA0;
extern void func_01B01658(void);
extern void func_0010C790(void *, int);

int func_01B01AC8(void)
{
    func_01B01658();
    D_01B00BA0 = 1.0f;
    func_0010C790(D_01B00658, 1);
    return 1;
}
