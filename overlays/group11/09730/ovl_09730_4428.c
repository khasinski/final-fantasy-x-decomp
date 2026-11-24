#include "common.h"

extern int D_01B00658;
extern u8 D_01B00708;
extern float D_01B00748;
extern u8 D_01B007B8;
extern float D_01B00A10[4];
extern float D_01B00A20[4];
extern u8 D_01B00A30;
extern int D_01B00AA8;
extern u8 D_01B033D8;
extern u8 D_01B05B80;

extern void *D_006A3924;

extern void func_01B04D30(void *, float);
extern void func_01B05428(void *, void *, int);
extern void func_01B05478(void *);
extern int func_00102B98(int);
extern void func_00105050(int, int);
extern void func_00110550(int, int);
extern void func_00110558(int, int);
extern void func_00110810(int, int);
extern void func_00110830(int, void *);
extern void func_00267530(void *);
extern void func_002DCE38(void *, void *, void *);

int func_01B04428(void *a0)
{
    D_006A3924 = &D_01B007B8;
    func_00267530(a0);
    return 1;
}

int func_01B04458(void)
{
    D_01B00AA8 = 0;
    if (D_01B00658 == 0) {
        D_01B00658 = func_00102B98(0x3015);
        func_00105050(0x3015, 1);
        func_00110550(D_01B00658, 1);
        func_00110558(D_01B00658, 1);
        func_00110810(D_01B00658, 0);
    }
    D_01B00A20[2] = D_01B00A20[1] = D_01B00A20[0] = D_01B00748;
    D_01B00A20[3] = 1.0f;
    D_01B00A10[0] = 0.0f;
    D_01B00A10[1] = 0.0f;
    D_01B00A10[2] = 0.0f;
    D_01B00A10[3] = 0.0f;
    func_01B05428(&D_01B033D8, &D_01B00708, D_01B00658);
    return 1;
}

int func_01B04528(void)
{
    float mat[4][4];

    func_01B04D30(mat, D_01B00748 * 0.00100000005f);
    func_002DCE38(&D_01B05B80, &D_01B00A30, mat);
    func_00110830(D_01B00658, &D_01B05B80);
    func_01B05478(&D_01B033D8);
    return D_01B00AA8 == 0;
}
