#include "common.h"

extern void *func_01B00BE0(int);
extern int func_01B00C08(int);
extern void func_001B5D38(void *, float, int);
extern void func_00107378(int, void *);
extern void func_001B6790(void *, void *);
extern void func_001B6BB0(void *, void *);
extern void func_00110830(int, void *);
extern void func_001B7178(void *, int, void *, int, int);

extern void *D_01B00620;
extern int D_01B0062C;

void func_01B012C8(int a0, int a1, float f)
{
    func_001B5D38(func_01B00BE0(a0), f, a1);
}

void func_01B01308(int a0, void *a1)
{
    float buf[4];
    int s2 = func_01B00C08(a0);

    if (a1 != 0) {
        func_00107378(s2, a1);
    } else if (D_01B0062C == 0) {
        void *s0 = func_01B00BE0(a0);
        func_001B6790(s0, buf);
        func_001B6BB0(s0, buf);
    }
    func_00110830(s2, a1);
}

void func_01B013A0(int a0, int a1, int a2)
{
    void *p = func_01B00BE0(a0);
    func_001B7178(D_01B00620, 2, p, a1, a2);
}
