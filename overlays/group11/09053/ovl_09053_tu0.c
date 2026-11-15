#include "common.h"

extern void *D_01B00000[];
extern float D_01B0078C;
extern float D_01B00790;
extern int D_01B05B50;
extern int D_01B05B54;
extern u8 D_01B0B670[];

void func_001AAC18(float a, float b);
int MsEffectMotionLevel(int a);
void MsEffectReady(int a, int b);
int func_0029B830(int a);
void func_002B22F8(int a, int b);
void op_oef2_set2(void *a);

int func_01B00938(void);
int func_01B00988(void);
int func_01B009B0(int a);
void func_01B009D8(void);
void func_01B01428(void);
void func_01B02E60(void *a, int b, int c);
void func_01B03568(void);
void func_01B03590(void);
void func_01B035C8(void);
void func_01B03618(int a);
void func_01B03728(void *a, int b, int c);
void func_01B03C78(void);
void func_01B03CF8(int a);
void func_01B046F8(void);

int func_01B007D8(int eff_id)
{
    void *res;

    D_01B05B50 = eff_id;
    func_01B01428();
    func_01B03590();
    func_01B03C78();
    func_01B046F8();
    func_002B22F8(0x3400, 0x800);
    res = D_01B0B670;
    op_oef2_set2(res);
    func_01B02E60(res, 0, 1000);
    func_01B03728(res, 0, 1000);
    D_01B05B54 = 0;
    return 0;
}

int func_01B00858(int a)
{
    func_01B035C8();
    func_01B03618(0);
    func_01B03568();
    return func_01B009B0(a);
}

int func_01B00898(void)
{
    if (func_0029B830(1) != 0) {
        return 0;
    }
    if (D_01B05B54 == 0) {
        int one = 1;

        MsEffectReady(D_01B05B50, 1);
        D_01B05B54 = one;
    }
    if (MsEffectMotionLevel(D_01B05B50) <= 0) {
        return 0;
    }
    func_01B009D8();
    D_01B00000[3] = func_01B00938;
    D_01B00000[4] = func_01B00988;
    return 0;
}

int func_01B00938(void)
{
    D_01B00790 = 0.0f;
    D_01B0078C = 0.0f;
    func_01B03CF8(1);
    func_001AAC18(D_01B0078C, D_01B00790);
    return 0;
}

int func_01B00988(void)
{
    func_01B03CF8(0);
    func_01B03CF8(2);
    return 0;
}

int func_01B009B0(int a)
{
    return 0;
}
