#include "common.h"

extern u8 *D_01B00464;
extern void func_00219F50(void);
extern void func_0021A280(int);

int func_01B0AC08(void)
{
    func_00219F50();
    func_0021A280(*D_01B00464);
    return 1;
}
