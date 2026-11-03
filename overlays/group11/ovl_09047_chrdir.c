#include "p6_overlay.h"

/* F2 TU rank 132: battle character facing as an angle. Compiled with -O0. */

int func_001B6E48(int id, float *out);
float func_01B07238(float rad);
int func_01B07278(float rad);

int func_01B072D8(register int id)
{
    float dir;

    func_001B6E48(id, &dir);
    return func_01B07278(func_01B07238(dir));
}
