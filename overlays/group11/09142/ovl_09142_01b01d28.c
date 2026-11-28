#include "common.h"

extern void *D_01B00658;
extern u8 D_01B00AF0[];
extern int D_01B00AB4;
extern u8 D_01B00E68[];
extern u8 D_01B00E78[];
extern u8 D_01B00AC0[];
extern u8 D_01B00B40[];
extern u8 D_01B00B70[];
extern int D_01B00BA4;
extern void func_00110830(void *, void *);
extern void func_01B044D0(void *);
extern void func_01B04150(void *, float);
extern void func_01B04148(void *, float);

int func_01B01D28(void)
{
    func_00110830(D_01B00658, D_01B00AF0);
    if (D_01B00AB4 != 0) {
        func_01B044D0(D_01B00E68);
    } else {
        func_01B044D0(D_01B00E78);
    }
    func_01B04150(D_01B00AC0, 5.0f);
    func_01B04148(D_01B00AF0, 20000.0f);
    func_01B04150(D_01B00B40, 5.0f);
    func_01B04150(D_01B00B70, 5.0f);
    return D_01B00BA4 == 0;
}
