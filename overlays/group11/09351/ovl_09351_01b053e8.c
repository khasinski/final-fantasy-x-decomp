#include "common.h"

extern u8 *D_01B0E828;

extern void func_01B049F8(void);
extern void func_01B04F20(void);
extern void func_01B052C0(void);
extern void func_01B02488(void);

void func_01B053E8(void)
{
    switch (*(int *)(D_01B0E828 + 0x1ED4)) {
    case 0:
        func_01B049F8();
        break;
    case 1:
        func_01B04F20();
        break;
    case 2:
        func_01B052C0();
        break;
    }
    func_01B02488();
}
