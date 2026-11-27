#include "common.h"

extern void func_001E4C80(int, int);
extern int func_001E4E30(void);

void func_01B01AB0(void)
{
    int v = func_001E4E30();
    int m = -1;
    if (v > m) {
        m = v;
    }
    func_001E4C80(0, m);
}
