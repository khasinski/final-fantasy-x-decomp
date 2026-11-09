/* tu_156 0x198cd8-0x198f10: medium; rcbgPre (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

void rcbgPreInit(void) {
    W3Core *core;

    rcbgPreFini();
    core = _rcCalloc(1, 0x14, D_0056DB00, 0x23);
    if (g_pMainWork != 0) {
        g_pMainWork->core = core;
    }
    core->buf0C = _rcAlloc(0x10000, D_0056DB00, 0x26);
}

void rcbgPreFini(void)
{
    W3Core *core;
    int i;

    core = W3_CORE();
    if (core != 0) {
        for (i = 0; i < core->npool; i++) {
            rcbgSceneFini(&core->pools[i]);
        }
        if (core->pools != 0) {
            func_0018FC10(core->pools);
            core->pools = 0;
        }
        if (core->buf0C != 0) {
            func_0018FC10(core->buf0C);
            core->buf0C = 0;
        }
        if (W3_CORE() != 0) {
            func_0018FC10(g_pMainWork->core);
            g_pMainWork->core = 0;
        }
        MsSetCameraMatrix(1024.0f, 0, 0, 0, 0, 0);
    }
}

void rcbgPreDummyInit(void) {
    W3Core *core = 0;

    if (g_pMainWork) {
        core = g_pMainWork->core;
    }
    if (core == 0) {
        core = _rcCalloc(1, 0x14, D_0056DB00, 0x4D);
        if (g_pMainWork) {
            g_pMainWork->core = core;
        }
    }
    if (core->npool == 0) {
        core->npool = 1;
        core->pools = _rcAlloc(sizeof(W3Pool), D_0056DB00, 0x54);
        rcbgSceneInit(core->pools);
        core->pool = core->pools;
    }
}
