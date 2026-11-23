#include "common.h"

typedef struct {
    u8 pad00[0x1E];
    u16 stride1E;       /* 0x1E */
    u8 pad20[4];
    u32 w24;            /* 0x24 */
    u32 w28;            /* 0x28 */
    u16 h2C;            /* 0x2C */
    u16 h2E;            /* 0x2E */
} Obj3F58;

typedef struct {
    Obj3F58 *obj;
    u16 n;
} Arg3F58;

void func_01B03F58(Arg3F58 *a)
{
    Obj3F58 *o = a->obj;
    int n = a->n;

    if (n < (int)o->h2C) {
        o->h2C -= n;
        o->w24 += n * o->stride1E;
    } else {
        n -= o->h2C;
        if (n >= (int)o->h2E) {
            o->h2E = 0;
            o->h2C = 0;
            return;
        }
        o->h2C = o->h2E - n;
        o->h2E = 0;
        o->w24 = n * o->stride1E;
        o->w28 = o->h2C * o->stride1E + o->w24;
    }
}
