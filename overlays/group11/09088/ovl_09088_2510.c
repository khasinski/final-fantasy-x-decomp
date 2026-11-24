#include "common.h"

typedef struct {
    u8 pad00[0x124];
    u16 h124;
} Obj2510;

extern void *D_006A3924;

extern s32 func_01B02820(void *, void *);
extern void func_00267530(void *);

s32 ovl_09088_2510(u8 *s1, Obj2510 *s0)
{
    if (func_01B02820(s1 + 0x20, s0) == 0) {
        return 0;
    }
    D_006A3924 = s1;
    func_00267530(s0);
    s0->h124 &= 0x7FFF;
    return 1;
}
