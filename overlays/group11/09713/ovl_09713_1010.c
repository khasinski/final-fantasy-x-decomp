#include "common.h"

extern float D_01B00660[10][4];
extern float D_01B00858;
extern float D_01B0085C;
extern float D_01B00868;
extern int D_01B00B20;
extern float D_01B00B2C;
extern u8 D_01B00B40;
extern u8 D_01B00B50;
extern char D_01B04990[];

extern void func_01B027D8(char *, ...);
extern void func_01B033E8(void *, int, int, float, int, float);
extern void func_01B04678(void *, float);
extern void func_002B5C18(void *, void *, int);
extern void func_002B5FE8(void *, void *, void *, int, float);

int func_01B00E08(void)
{
    func_01B027D8(D_01B04990, D_01B00B20);
    func_002B5C18(&D_01B00B50, D_01B00660, 3);
    D_01B00B2C = 0.0f;
    return 1;
}

int func_01B00E58(void)
{
    int i;

    D_01B00858 = ((double)D_01B00858 < 0.0) ? 0.0f : (((double)D_01B00858 > 9.0) ? 9.0f : D_01B00858);
    for (i = 0; i < 10; i++) {
        func_01B04678(D_01B00660[i], 20.0f);
    }
    func_01B033E8(D_01B00660[(int)D_01B00858], 0, 0, 1.0f, 0, 0.0f);
    func_002B5FE8(&D_01B00B40, D_01B00660, &D_01B00B50, 3, D_01B00B2C);
    if (D_01B00868 == 0.0f) {
        D_01B00B2C += 1.0f / D_01B0085C;
    }
    if ((double)D_01B00B2C > 1.0) {
        return 0;
    }
    return 1;
}
