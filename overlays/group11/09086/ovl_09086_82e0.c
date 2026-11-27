#include "common.h"

extern u8 D_01B02440[];
extern void func_01B0B330(void *);
extern void func_01B0BBE8(void *);

int func_01B082E0(void)
{
    struct {
        void *p;
        int n;
    } m0;
    void *m1;
    void *m2;

    m0.p = D_01B02440;
    m0.n = 1;
    func_01B0B330(&m0);
    m1 = D_01B02440;
    func_01B0BBE8(&m1);
    m2 = D_01B02440 + 0xA0;
    func_01B0BBE8(&m2);
    return 0;
}
