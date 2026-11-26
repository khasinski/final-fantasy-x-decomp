#include "iopsound.h"

extern void (*D_06D220[])(s32, void *);
extern void *D_06D228[];
extern s32 D_06D230[];

s32 func_00FBD0(s32 ch) {
    ch &= 1;
    D_06D230[ch] = 0;
    if (D_06D220[ch] != NULL) {
        D_06D220[ch](ch, D_06D228[ch]);
    }
    return ch;
}
