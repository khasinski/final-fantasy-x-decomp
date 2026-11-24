#include "common.h"

typedef struct {
    u8 pad0[0xD34];
    int wD34;
} Work9435;

extern Work9435 *D_01B09248;
extern void func_00297CE8(int);

void func_01B027E0(void)
{
    Work9435 *w = D_01B09248;

    func_00297CE8(w->wD34);
    w->wD34 = -1;
}
