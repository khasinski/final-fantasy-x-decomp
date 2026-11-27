#include "common.h"

extern void *D_01B00658;
extern float D_01B0076C;
extern float D_01B00AC0;
extern int D_01B00AC4;
extern int D_01B00AC8;

extern int func_00116068(void);
extern void func_00110540(void *, int, float);
extern void func_01B034F8(float);

int func_01B04110(void)
{
    if (!D_01B00AC4) {
        return 1;
    }
    if (func_00116068()) {
        D_01B00AC0 -= 1.0f / D_01B0076C;
    }
    D_01B00AC0 = (D_01B00AC0 < 0.0f) ? 0.0f : ((D_01B00AC0 > 1.0f) ? 1.0f : D_01B00AC0);
    {
        void *p = D_01B00658;
        float v = D_01B00AC0;
        __asm__("" : : "r"(p), "f"(v) : "memory");
        func_00110540(p, 0, v);
    }
    func_01B034F8(D_01B00AC0);
    if (D_01B00AC0 == 0.0f) {
        D_01B00AC8 = 1;
        return 0;
    }
    return 1;
}
