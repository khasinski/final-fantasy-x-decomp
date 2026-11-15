#include "p9_overlay.h"

/* Matrix helpers (family F8, TU rank 14 part 3, position independent). */

void func_01B05060(float m[4][4], float rot[3])
{
    func_002DD1C8(m, m, rot[2]);
    func_002DD270(m, m, rot[0]);
    func_002DD318(m, m, rot[1]);
}

void func_01B050B8(float m[4][4], float s)
{
    func_002DD998(m[0], m[0], s);
    func_002DD998(m[1], m[1], s);
    func_002DD998(m[2], m[2], s);
}
