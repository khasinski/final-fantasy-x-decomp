#include "p9_overlay.h"

/* Direction-to-angles and offset-by-rotation helpers (family F8, TU rank 14 part 2). */

void func_01B04E38(float out[3], float from[3], float to[3])
{
    float dz = to[2] - from[2];
    float dx = to[0] - from[0];
    float dy = to[1] - from[1];
    float a;

    out[0] = func_002E94A0(dy, func_002E9290(dx * dx + dz * dz));
    a = 4.712389f - func_002E94A0(dz, dx);
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    out[1] = a;
    out[2] = 0.0f;
}

void func_01B04F40(float rot[2], float pos[4], float ofs[4])
{
    float m[4][4] __attribute__((aligned(16)));
    float v[4] __attribute__((aligned(16)));

    func_002DD128(m);
    func_002DD270(m, m, rot[0]);
    func_002DD318(m, m, rot[1]);
    ofs[3] = 1.0f;
    func_002DCE08(v, m, ofs);
    func_002DD020(pos, pos, v);
    pos[3] = 1.0f;
}
