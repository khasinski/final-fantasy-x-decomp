#include "common.h"

typedef struct Control {
    u8 pad0[0x18C];
    s16 counter;
    s16 pad18E;
} Control;

Control *func_GET(int);
void func_SET(Control *, float, float, int);

void func_01B03F48(float a0, float a1, int a2) {
    func_SET(func_GET(0), a0, a1, a2 - func_GET(0)->counter);
}
