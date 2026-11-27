#include "common.h"

extern void *D_01B00788;
extern float D_01B00974;
extern s32 D_01B00F6C;
extern float D_01B01000;
extern s32 D_01B01004;
extern s32 D_01B011EC;
extern s32 D_01B011F8;

extern void func_01B01358(void);
extern int func_00116068(void);
extern void func_00110540(void *, int, float);
extern void func_01B01410(float);

int func_01B01948(void)
{
    func_01B01358();
    D_01B01000 = 1.0f;
    return 1;
}

int func_01B01978(void)
{
    if (D_01B011EC >= 61 || (D_01B00F6C != 0 && D_01B011F8 >= 186)) {
        if (func_00116068()) {
            D_01B01000 -= 1.0f / D_01B00974;
        }
        D_01B01000 = (D_01B01000 < 0.0f) ? 0.0f : ((D_01B01000 > 1.0f) ? 1.0f : D_01B01000);
        {
            void *p = D_01B00788;
            float v = D_01B01000;
            __asm__("" : : "r"(p), "f"(v) : "memory");
            func_00110540(p, 0, v);
        }
        func_01B01410(D_01B01000);
        if (D_01B01000 == 0.0f) {
            D_01B01004 = 1;
            return 0;
        }
    }
    return 1;
}
