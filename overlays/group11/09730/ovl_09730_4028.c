#include "common.h"

extern void *D_01B00658;
extern float D_01B00754;
extern float D_01B00AA0;
extern int D_01B00AA4;
extern int D_01B00AA8;

extern int func_00116068(void);
extern void func_00110540(void *, int, float);
extern void func_01B034C8(float);

int func_01B04028(void)
{
    if (!D_01B00AA4) {
        return 1;
    }
    if (func_00116068()) {
        D_01B00AA0 -= 1.0f / D_01B00754;
    }
    D_01B00AA0 = (D_01B00AA0 < 0.0f) ? 0.0f : ((D_01B00AA0 > 1.0f) ? 1.0f : D_01B00AA0);
    {
        void *p = D_01B00658;
        float v = D_01B00AA0;
        __asm__("" : : "r"(p), "f"(v) : "memory");
        func_00110540(p, 0, v);
    }
    func_01B034C8(D_01B00AA0);
    if (D_01B00AA0 == 0.0f) {
        D_01B00AA8 = 1;
        return 0;
    }
    return 1;
}
