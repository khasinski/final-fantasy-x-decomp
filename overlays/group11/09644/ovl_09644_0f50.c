#include "common.h"

extern float D_01B00C7C;
extern float D_01B00C80;

extern void func_001AAC18(float, float);
extern void func_01B04310(int);

int ovl_09644_0f50(void)
{
    D_01B00C80 = 0.0f;
    D_01B00C7C = 0.0f;
    func_01B04310(1);
    func_001AAC18(D_01B00C7C, D_01B00C80);
    return 0;
}
