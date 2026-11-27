#include "common.h"

typedef struct Control {
    u8 pad0[0x18C];
    s16 counter;
    s16 pad18E;
} Control;

Control *func_01B025B8(int);
void func_01B02940(Control *, float, float, int);

void func_01B06448(float a0, float a1, int a2)
{
    func_01B02940(func_01B025B8(0), a0, a1, a2 - func_01B025B8(0)->counter);
}
