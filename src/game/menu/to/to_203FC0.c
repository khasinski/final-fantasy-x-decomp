#include "common.h"
#include "ffx/types.h"
#include "ffx/funcs.h"
#include "ffx/r4.h"

extern float TkGetMessageSpeed(int speed);

void func_00203FC0(MenuCmd *m)
{
    if (m->xA4 == 0) {
        m->xA0 = (int)((float)m->xA0 + (float)m->x9C * TkGetMessageSpeed(func_001BD360()));
        if (TOGetFFXVideoMode() == 0) {
            if (m->xA0 >= 30) {
                m->x90 += m->xA0 / 30;
                m->xA0 %= 30;
            }
        } else {
            if (m->xA0 >= 25) {
                m->x90 += m->xA0 / 25;
                m->xA0 %= 25;
            }
        }
    } else {
        m->xA4--;
    }
}
