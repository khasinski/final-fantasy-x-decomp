#include "common.h"

typedef struct {
    u8 pad0[0xD34];
    int wD34;
} Work9492;

extern Work9492 *D_01B09098;
extern void func_00297CE8(int);

void func_01B02638(void)
{
    Work9492 *w = D_01B09098;

    func_00297CE8(w->wD34);
    w->wD34 = -1;
}
