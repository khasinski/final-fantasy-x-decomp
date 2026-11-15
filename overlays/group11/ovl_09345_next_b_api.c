/* Battle-effect overlay 09345: byte-exact C helpers and callbacks. */
#include "../rcef_overlay.h"
extern void *D_01B00608[];
extern u8 D_01B00610[0x38];
extern u8 D_01B019C0[];
void func_01B00648(W3Task *t);
int func_01B01830(int id)
{
    func_0019FC00(&D_00313CB0,id,D_01B019C0,0x01e80000,0x80000,0x01d80000,1,D_01B00608,D_01B00610);
    func_0019FF90(&D_00313CB0,func_01B00648);
    return 0;
}

int func_01B018A0(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B018C8(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B018F0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01918(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01940(void)
{
    return 0;
}

int func_01B01948(void)
{
    return 0;
}

int func_01B01950(void)
{
    return 0;
}

int func_01B01958(void)
{
    return 0;
}
