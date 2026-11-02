#ifndef FFX_W3_H

#define FFX_W3_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* Pool of the global owner, or 0. DEBT(NAME): guess. */
static inline W3Pool *W3_GetPool(void)
{
    W3Core *core;
    W3Pool *pool;

    pool = 0;
    if (g_pMainWork != 0) {
        core = g_pMainWork->core;
        if (core != 0) {
            pool = core->pool;
        }
    }
    return pool;
}

#endif
