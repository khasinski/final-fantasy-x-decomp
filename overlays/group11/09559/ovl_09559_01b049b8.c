/* Overlay 09559: rank 696 matrix 3x3 scale helper (0x01B049B8..0x01B04A10). */
#include "common.h"

void func_002DD068(void *, void *, float);

void func_01B049B8(float (*a0)[4], float (*a1)[4], float f12) {
    func_002DD068(a0[0], a1[0], f12);
    func_002DD068(a0[1], a1[1], f12);
    func_002DD068(a0[2], a1[2], f12);
}
