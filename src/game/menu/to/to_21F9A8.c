/* tu_245 0x21f9a8-0x21fdd8: low; ~TOBtlInitActiveChrCursor (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"

void TOBtlInitActiveChrCursor(void)
{
    D_00692950[0] = 0;
    D_00692950[1] = -0.3f;
    D_00692950[2] = 0;
    D_00692950[3] = 1.0f;
    D_00692960[0] = -1.0f;
    D_00692960[1] = -2.3f;
    D_00692960[2] = 0;
    D_00692960[3] = 1.0f;
    D_00692970[0] = 1.0f;
    D_00692970[1] = -2.3f;
    D_00692970[2] = 0;
    D_00692970[3] = 1.0f;
    D_00692980[0] = 0;
    D_00692980[1] = 0;
    D_00692980[2] = 0.1f;
    D_00692980[3] = 1.0f;
    D_00692990[0] = -1.1f;
    D_00692990[1] = -2.2f;
    D_00692990[2] = 0.1f;
    D_00692990[3] = 1.0f;
    D_006929A0[0] = 1.1f;
    D_006929A0[1] = -2.2f;
    D_006929A0[2] = 0.1f;
    D_006929A0[3] = 1.0f;
    TOSeqGetColor(2, D_00571178, &D_00692BF0);
    TOSeqGetColor(2, D_00571180, &D_00692BF4);
    TOSeqGetColor(2, D_00571188, &D_00692BF8);
    TOSeqGetColor(2, D_00571190, &D_00692BFC);
}

void func_0021FB00(void)
{
    D_006929C0.ang += 0.10471976f;
    if (D_006929C0.ang > 3.1415927f) {
        D_006929C0.ang -= 6.2831855f;
    }
}

void TOBtlDrawActiveChrCursor(int character)
{
    int x[3], y[3];
    int i;

    MsGetChrHeadPos(character, D_006929B0);
    func_001AACA0(D_00692B10);
    func_001A9EE0(D_00692B50);
    func_002DD128(D_006929D0);
    func_002DD3C0(D_00692A10, D_006929D0, &D_006929C0);
    func_002DD080(D_00692A10, D_00692A10, D_006929B0);
    func_002DCE38(D_00692A50, D_00692B50, D_00692A10);
    func_002DCE38(D_00692AD0, D_00692B10, D_00692A50);
    if (func_001AC458(D_00692B90, D_00692AD0, D_00692950, 1) <= 0.0f) return;
    if (func_001AC458(D_00692BA0, D_00692AD0, D_00692960, 1) <= 0.0f) return;
    if (func_001AC458(D_00692BB0, D_00692AD0, D_00692970, 1) <= 0.0f) return;
    if (func_001CB7A0(D_003252A4) == 1) return;

    x[0] = (D_00692B90[0] >> 4) - 0x700;
    x[1] = (D_00692BA0[0] >> 4) - 0x700;
    x[2] = (D_00692BB0[0] >> 4) - 0x700;
    y[0] = (D_00692B90[1] >> 4) - 0x730;
    y[1] = (D_00692BA0[1] >> 4) - 0x730;
    y[2] = (D_00692BB0[1] >> 4) - 0x730;
    for (i = 0; i < 3; i++) {
        if ((unsigned)(x[i] - 1) >= 0x1FE) return;
        if ((unsigned)(y[i] - 1) >= 0x19F) return;
    }
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001FAC60(x[0], y[0], x[1], y[1], x[2], y[2], D_00692BF0, D_00692BF4);
}
