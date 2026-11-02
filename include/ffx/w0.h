#ifndef FFX_W0_H

#define FFX_W0_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* Chr.flags / Chr.flags2 are 64-bit flag words; single-bit accessors */
#define FLAGS2_BIT(c, n) ((s32)((c)->flags2 >> (n)) & 1)

#define FLAGS2_SET(c, n, v) \
    ((c)->flags2 = ((c)->flags2 & ~(1L << (n))) | ((s64)((v) & 1) << (n)))

#define FLAGS_BIT(c, n) ((s32)((c)->flags >> (n)) & 1)

#define FLAGS_SET(c, n, v) \
    ((c)->flags = ((c)->flags & ~(1L << (n))) | ((s64)((v) & 1) << (n)))

#endif /* FFX_W0_H */
