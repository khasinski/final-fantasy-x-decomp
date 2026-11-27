#include "common.h"

extern void *D_01B0BD5C;

extern int func_01B04B70(int);
extern void func_002A7120(int, int, int);
extern void func_01B066B8(int, int, int);
extern int func_001038F8(void);
extern void func_002A7308(void *, int, int, int);

void func_01B02CA0(void)
{
    int h = func_01B04B70(-1);
    func_002A7120(h, 2, 1);
    func_01B066B8(-1, 0x3C00, 0x2EE0);
    func_002A7308(D_01B0BD5C, h, 2, func_001038F8());
    func_01B066B8(-1, -1, -1);
}
