#include "common.h"

extern int D_01B00350;
extern int D_01B0A9E0;
extern float D_01B00348;
extern int D_01B0A7B0;
extern int D_01B00468;
extern int D_01B00470[];
extern int D_01B00338[];
extern int D_01B0A7B8;

extern void func_01B0C268(int, float);
extern void func_0010C790(int, int);

int func_01B0AEA0(void)
{
    if (D_01B00350 == 0) {
        if (D_01B0A9E0 >= 6) {
            D_01B00348 += 0.025000001f;
            if (D_01B00348 > 1.0f) {
                D_01B00348 = 1.0f;
            }
        }
    } else {
        D_01B00348 -= 0.025000001f;
        if (D_01B00348 < 0.0f) {
            D_01B00348 = 0.0f;
        }
    }
    func_01B0C268(D_01B0A7B0, D_01B00348);
    if (D_01B00350 != 0) {
        int i;
        for (i = 0; i < D_01B00468; i++) {
            func_0010C790(D_01B00470[i], 0);
        }
        for (i = 0; i < 2; i++) {
            if (D_01B00338[i] != 0) {
                func_0010C790(D_01B00338[i], 0);
            }
        }
        D_01B0A7B8 = 1;
        return 0;
    }
    return 1;
}
