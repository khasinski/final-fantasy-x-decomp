#include "common.h"

extern int D_01B006A8;
extern float D_01B007C0[4];
extern int D_01B007D0;
extern float D_01B009D0[4];
extern float D_01B00AA0[4];
extern int D_01B00AB4;

extern void func_00107BE8(int, int);
extern void func_0010D720(void);
extern void func_0010D728(int);
extern void func_0010DB58(int, float, float, float, int, int, int, int, float);
extern void func_0010DC38(int, int);
extern void func_002DD020(void *, void *, void *);

int func_01B01E50(void)
{
    func_0010D728(4);
    func_0010DB58(0, 0.0f, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0, 100.0f);
    func_0010DB58(1, 0.0f, 0.0f, 0.0f, 1, 1, 1, 1, 100.0f);
    func_0010DB58(2, 0.0f, 0.0f, 0.0f, 1, 1, 1, 2, 100.0f);
    func_0010DB58(3, 0.0f, 0.0f, 0.0f, 1, 1, 1, 3, 100.0f);
    func_0010DC38(D_01B006A8, 0xF);
    func_00107BE8(D_01B006A8, 1);
    return 1;
}

int func_01B01F58(void)
{
    func_002DD020(D_01B00AA0, D_01B009D0, D_01B007C0);
    func_0010DB58(0, D_01B00AA0[0], D_01B00AA0[1], D_01B00AA0[2], 0xFF, 0xFF, 0xFF, 0, 1000.0f);
    func_0010DB58(3, D_01B00AA0[0], D_01B00AA0[1], D_01B00AA0[2], D_01B007D0, D_01B007D0, D_01B007D0, 3, 100.0f);
    return D_01B00AB4 != 1;
}

int func_01B02000(void)
{
    func_00107BE8(D_01B006A8, 0);
    func_0010D720();
    return 1;
}
