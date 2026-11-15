/* Battle-effect overlay 9405: byte-exact C helpers and callbacks. */
#include "../rcef_overlay.h"
extern void *D_01B005B8[];
extern u8 D_01B005C0[0x38];
extern u8 D_01B01D20[];
void func_01B005F8(W3Task *t);
int func_01B01B18(int id)
{
    func_0019FC00(&D_00313CB0,id,D_01B01D20,0x01e80000,0x80000,0x01d80000,1,D_01B005B8,D_01B005C0);
    func_0019FF90(&D_00313CB0,func_01B005F8);
    return 0;
}

int func_01B01B88(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B01BB0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B01BD8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01C00(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01C28(void)
{
    return 0;
}

int func_01B01C30(void)
{
    return 0;
}

int func_01B01C38(void)
{
    return 0;
}

int func_01B01C40(void)
{
    return 0;
}
