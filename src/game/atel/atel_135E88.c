/* tu_063 0x135e88-0x1365d0: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

extern float D_0058D160[16];
extern float D_0058D1A0[16];
void func_002DCF48(void *dst, void *src);

void AtelSetSndCameraPos(void)
{
    float mat[16];
    int old;
    Sys3D8 *ctrl;

    func_001A9EE0(D_0058D1A0);
    D_0058D1E0 = -1;
    old = AtelChangeCurrentCtrl(0);
    ctrl = (Sys3D8 *)AtelGetCurCtrlWork();
    if (ctrl->hA != 0xFFFF) {
        ActorState *st;

        func_002DCF48(mat, D_0058D1A0);
        st = AtelGetPosWorkAdrs(AtelGetBasicWork(ctrl->hA));
        mat[12] = st->x;
        mat[13] = st->y;
        mat[14] = st->z;
        func_002DCF48(D_0058D160, mat);
    } else {
        func_002DD0C0(D_0058D160, D_0058D1A0);
    }
    AtelSetCurrentCtrl(old);
}

void func_00135F50(void) {
    D_0058D1E0 = -1;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_135E88", func_00135F60);

void func_00136428(int a, int b) {
    func_00135F60(a, b, 0x100);
}

void func_00136430(float v) {
    D_0058D1E4 = v;
}

void func_00136440(float v) {
    D_0058D1E8 = v;
}

/* DEBT(CAST): this table uses signed address comparisons and an integer-address helper interface. */
void func_00136450(void)
{
    Q1F0Ent *next;
    Q1F0Ent *entry;
    float value;

    value = D_0058D1E4 + D_0058D1E8;
    D_0058D1E4 = value;
    if (value < 0.0f)
    {
        D_0058D1E4 = 0.0f;
    }
    if (D_0058D1E4 > 1.0f)
    {
        D_0058D1E4 = 1.0f;
    }
    AtelSetSndCameraPos();
    next = D_0058D1F0;
    entry = D_0058D1F0;
    do
    {
        next++;
        func_00135F60((s32) entry, 0, 0x100);
        entry = next;
    } while ((s32) next < (s32) (D_0058D1F0 + 16));
}

void *AtelGetSnd3dWork(s32 id) {
    s32 n;

    if (id >= 0) {
        if (id > 15) {
            n = 15;
        } else {
            n = id;
        }
    } else {
        n = 0;
    }
    return &D_0058D1F0[n];
}

void func_00136520(int i)
{
    int idx;
    Q1F0Ent *e;

    if (i >= 0) {
        if (i > 15) {
            idx = 15;
        } else {
            idx = i;
        }
    } else {
        idx = 0;
    }
    e = &D_0058D1F0[idx];
    e->w0 = 0;
    e->w4 = 0;
    e->b20 = 0;
    e->b21 = 0;
}

void AtelClearSnd3dWorkAll(void) {
    int i;

    for (i = 0; i < 16; i++) {
        func_00136520(i);
    }
    D_0058D1E4 = 0;
    D_0058D1E8 = 0;
}

extern u_long128 D_0058D150;

void AtelInitCalcSound(void)
{
    AtelClearSnd3dWorkAll();
    VU0_STORE_VF0(&D_0058D150);
}
