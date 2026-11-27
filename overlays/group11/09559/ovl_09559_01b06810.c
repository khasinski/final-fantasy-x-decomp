#include "common.h"

typedef struct Control {
    u8 pad0[0x18C];
    s16 counter;
    s16 pad18E;
} Control;

Control *func_01B02810(int);
void func_01B02B98(Control *, float, float, int);

void func_01B06810(float a0, float a1, int a2)
{
    func_01B02B98(func_01B02810(0), a0, a1, a2 - func_01B02810(0)->counter);
}
