#include "common.h"

extern void *D_ovl_buf;

extern int fn_ovl_get(int);
extern void func_0010D380(int, int, int);
extern void func_0010D3A8(int, int, int);
extern void func_002A7308(void *, int, int, int);

void func_01B018A0(void)
{
    int s0 = fn_ovl_get(-1);

    func_0010D380(s0, -1, 0x3C00);
    func_0010D3A8(s0, -1, 0x2EE0);
    func_002A7308(D_ovl_buf, s0, 1, 0);
    func_0010D380(s0, -1, -1);
    func_0010D3A8(s0, -1, -1);
}
