#include "common.h"

extern void *D_01B006A8;
extern float D_01B007B0;
extern s32 D_01B009B4;
extern float D_01B00AA0;
extern s32 D_01B00AA4;
extern s32 D_01B00AA8;

extern void func_01B00C08(void);
extern int func_00116068(void);
extern void func_00110540(void *, int, float);
extern void func_01B00C98(float);

int func_01B01400(void)
{
    func_01B00C08();
    D_01B00AA0 = 1.0f;
    return 1;
}

int func_01B01430(void)
{
    if (D_01B009B4 != 0 && D_01B00AA8 < 153) {
        return 1;
    }
    if (func_00116068()) {
        D_01B00AA0 -= 1.0f / D_01B007B0;
    }
    D_01B00AA0 = (D_01B00AA0 < 0.0f) ? 0.0f : ((D_01B00AA0 > 1.0f) ? 1.0f : D_01B00AA0);
    func_00110540(D_01B006A8, 0, D_01B00AA0);
    func_01B00C98(D_01B00AA0);
    if (D_01B00AA0 == 0.0f) {
        D_01B00AA4 = 1;
        return 0;
    }
    return 1;
}
