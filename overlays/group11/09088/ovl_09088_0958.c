#include "common.h"

extern u8 D_01B6F3C0[];
extern u8 *D_01B02DB0;
extern u8 *D_01B02DB4;
extern u8 D_01B07A10[];
extern u8 D_01B00040[];
extern u8 D_01B00900[];
extern u8 D_01B02C80[];
typedef struct {
    u8 pad00[0x1C];
    void *p1C;
} Mgr0958;
extern Mgr0958 D_01B02C48;

extern void *func_002B49A0(void *, int, int);
extern void func_01B01FE0(void *, void *, void *, int);
extern void func_01B020B8(void *, void *, int, int, int, int, float);
extern void func_01B00CF0(int, void *, int);
extern void *func_01B01D58(void *);
extern void func_01B01F20(void *);

int func_01B00958(void)
{
    u8 *p = D_01B6F3C0;
    Mgr0958 *mgr = &D_01B02C48;
    D_01B02DB4 = p + 0x40000;
    D_01B02DB0 = p;
    mgr->p1C = func_002B49A0(D_01B07A10, 8, 0);
    func_01B01FE0(mgr, D_01B00040, D_01B02DB0, 0x40000);
    func_01B020B8(mgr, D_01B02C80, 0, 0, 0, 0, 0.06f);
    func_01B00CF0(0, D_01B02C80 + 0xD0, 1);
    func_01B01F20(func_01B01D58(D_01B00900));
    return 0;
}
