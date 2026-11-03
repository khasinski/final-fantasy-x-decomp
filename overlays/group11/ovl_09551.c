/* EE Battle-Effect Overlay: group 0x11, file 09551 (group_index 507)
 * Load base: 0x01B00000, .text: 0x01B00530..0x01B00720
 *
 * Minimal effect scene.
 */
#include "../rcef_overlay.h"

extern u8 D_01B004F0[8];
extern u8 D_01B004F8[8];
extern u8 D_01B00730[8];

void func_01B00568(W3Task *t);
void func_01B005B0(W3Task *t);
void func_01B005E0(W3Task *t);

void func_01B00530(W3Task *t)
{
    W3Task *task = t;

    func_001A1D08(task, func_01B00568);
    func_001A1D50(task, func_001A2058);
}

void func_01B00568(W3Task *t)
{
    W3Task *task = t;

    func_001A2B58(0);
    func_001A1D08(task, func_01B005B0);
    func_001A1D50(task, func_001A2098);
}

void func_01B005B0(W3Task *t)
{
    func_001A2B68();
    func_001A1D08(t, func_01B005E0);
}

void func_01B005E0(W3Task *t)
{
    t->flags |= 4;
}

int func_01B005F0(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00730, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B004F0, D_01B004F8);
    func_0019FF90(&D_00313CB0, func_01B00530);
    return 0;
}

int func_01B00660(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B00688(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B006B0(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B006D8(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00700(void)
{
    return 0;
}

int func_01B00708(void)
{
    return 0;
}

int func_01B00710(void)
{
    return 0;
}

int func_01B00718(void)
{
    return 0;
}
