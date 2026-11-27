#include "common.h"

extern void *D_01B10300;

extern int func_01B08BB8(int);
extern void func_0010D380(int, int, int);
extern void func_0010D3A8(int, int, int);
extern void func_002A7308(void *, int, int, int);
extern void func_01B09E60(int, int);

void func_01B060C8(void)
{
    int h = func_01B08BB8(0);
    func_0010D380(h, -1, 0x3C00);
    func_0010D3A8(h, -1, 0x2EE0);
    func_002A7308(D_01B10300, h, 1, 0);
    func_0010D380(h, -1, -1);
    func_0010D3A8(h, -1, -1);
    func_01B09E60(0, 1);
}
