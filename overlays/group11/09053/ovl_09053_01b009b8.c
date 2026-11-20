/* Shared 09053-family helper (TU rank 154, 165 containers): countdown then MsEffectTerminate. */
#include "p7_overlay.h"

typedef struct Ovl09053Wait {
    u8 pad00[0x14];
    int timer;
} Ovl09053Wait;

extern int D_01B05B50;
void MsEffectTerminate(int id);

void func_01B009B8(Ovl09053Wait *w)
{
    if (w->timer > 0) {
        w->timer--;
        return;
    }
    MsEffectTerminate(D_01B05B50);
}
