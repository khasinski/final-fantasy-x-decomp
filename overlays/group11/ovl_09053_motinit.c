#include "p9_overlay.h"

/* Motion primitive context reset and keyframe player init (family F11, TU rank 155). */

extern P9MotCtx D_01B007A0;

void func_01B05490(void)
{
    func_002EF0D0(&D_01B007A0, 0, sizeof(D_01B007A0));
    D_01B007A0.flags |= 0x80;
}

void func_01B054D0(P9MotHead *head, P9MotData *data)
{
    head->data = data;
    head->active = 1;
    head->frame = -1;
    head->timer = 0x200;
}
