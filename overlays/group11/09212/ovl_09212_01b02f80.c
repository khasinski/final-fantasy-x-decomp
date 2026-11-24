#include "common.h"

typedef struct Ovl09212Work {
    u8 pad00[0x31D0];
    int w31D0;
} Ovl09212Work;

extern Ovl09212Work *D_01B0A8E8;
void func_01B01C00(void);

void func_01B02F80(void)
{
    Ovl09212Work *w = D_01B0A8E8;

    if (w->w31D0 > 0) {
        w->w31D0--;
    }
    func_01B01C00();
}
