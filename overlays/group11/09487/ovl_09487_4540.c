#include "common.h"

extern int D_01B00658;
extern u8 D_01B00720;
extern float D_01B00760;
extern float D_01B00A30[4];
extern float D_01B00A40[4];
extern int D_01B00AC8;
extern u8 D_01B03408;

extern void func_01B05A90(void *, void *, int);
extern int func_00102B98(int);
extern void func_00105050(int, int);
extern void func_00110550(int, int);
extern void func_00110558(int, int);
extern void func_00110810(int, int);

int func_01B04540(void)
{
    D_01B00AC8 = 0;
    if (D_01B00658 == 0) {
        D_01B00658 = func_00102B98(0x3015);
        func_00105050(0x3015, 1);
        func_00110550(D_01B00658, 1);
        func_00110558(D_01B00658, 1);
        func_00110810(D_01B00658, 0);
    }
    D_01B00A40[2] = D_01B00A40[1] = D_01B00A40[0] = D_01B00760;
    D_01B00A40[3] = 1.0f;
    D_01B00A30[0] = 0.0f;
    D_01B00A30[1] = 0.0f;
    D_01B00A30[2] = 0.0f;
    D_01B00A30[3] = 0.0f;
    func_01B05A90(&D_01B03408, &D_01B00720, D_01B00658);
    return 1;
}
