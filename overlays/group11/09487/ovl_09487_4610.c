#include "common.h"

extern int D_01B00658;
extern float D_01B00760;
extern u8 D_01B00A50;
extern int D_01B00A94;
extern int D_01B00AC8;
extern u8 D_01B03408;
extern u8 D_01B05C90;

extern void func_01B03700(void *, int);
extern void func_01B04E38(void *, float);
extern void func_01B05AE0(void *);
extern void func_00110830(int, void *);
extern void func_002DCE38(void *, void *, void *);

int func_01B04610(void)
{
    float mat[4][4];

    func_01B03700(&D_01B00A50, D_01B00A94);
    func_01B04E38(mat, D_01B00760 * 0.00100000005f);
    func_002DCE38(&D_01B05C90, &D_01B00A50, mat);
    func_00110830(D_01B00658, &D_01B05C90);
    func_01B05AE0(&D_01B03408);
    return D_01B00AC8 == 0;
}
