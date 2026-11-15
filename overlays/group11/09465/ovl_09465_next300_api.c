/* Battle-effect overlay 9465: byte-exact C helpers and callbacks. */
#include "rcef_overlay.h"
extern void *D_01B00540[];
extern u8 D_01B00548[0x38];
extern u8 D_01B01C40[];
void func_01B00580(W3Task *t);
int func_01B01990(int id)
{
    func_0019FC00(&D_00313CB0,id,D_01B01C40,0x01e40000,0xc0000,0x01d40000,1,D_01B00540,D_01B00548);
    func_0019FF90(&D_00313CB0,func_01B00580);
    return 0;
}

int func_01B01A00(void)
{
    rcefMainProcRunAfter((W3ObjBig *)&D_00313CB0);
    return 0;
}

int func_01B01A28(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B01A50(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B01A78(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B01AA0(void)
{
    return 0;
}

int func_01B01AA8(void)
{
    return 0;
}

int func_01B01AB0(void)
{
    return 0;
}

int func_01B01AB8(void)
{
    return 0;
}
