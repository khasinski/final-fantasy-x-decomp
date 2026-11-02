#ifndef FFX_W7_H

#define FFX_W7_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* input/pad state block returned by MsGetSaveMenu; only the flag word is known. DEBT(NAME) */
typedef struct PadState { s32 flags; } PadState;

/* END PROTOS */

#endif
