#include "common.h"

extern void *D_01B006A8;
extern float D_01B007B0;
extern s32 D_01B009C4;
extern float D_01B00AB0;
extern s32 D_01B00AB4;
extern s32 D_01B00AB8;

extern int func_00116068(void);
extern void func_00110540(void *, int, float);
extern void func_01B00CA8(float);

int func_01B01488(void)
{
    if (D_01B009C4 != 0 && D_01B00AB8 < 153) {
        return 1;
    }
    if (func_00116068()) {
        D_01B00AB0 -= 1.0f / D_01B007B0;
    }
    D_01B00AB0 = (D_01B00AB0 < 0.0f) ? 0.0f : ((D_01B00AB0 > 1.0f) ? 1.0f : D_01B00AB0);
    {
        void *p = D_01B006A8;
        float v = D_01B00AB0;
        __asm__("" : : "r"(p), "f"(v) : "memory");
        func_00110540(p, 0, v);
    }
    func_01B00CA8(D_01B00AB0);
    if (D_01B00AB0 == 0.0f) {
        D_01B00AB4 = 1;
        return 0;
    }
    return 1;
}
