/* tu_026 0x1194e0-0x119f30: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

U0Vec *func_001194E0(U0Vec *out)
{
    D_00580480.x = D_00307ED0[0] - D_00307EC0[0];
    D_00580480.y = D_00307ED0[1] - D_00307EC0[1];
    D_00580480.z = D_00307ED0[2] - D_00307EC0[2];
    if (out) {
        *out = D_00580480;
    }
    return &D_00580480;
}

float *func_00119548(float *out)
{
    if (out) {
        MsCameraGetPosNow(1, D_00307EC0);
        out[0] = D_00307EC0[0];
        out[1] = D_00307EC0[1];
        out[2] = D_00307EC0[2];
    }
    return D_00307EC0;
}

float *func_001195B8(float *dst)
{
    if (dst) {
        dst[0] = D_00307ED0[0];
        dst[1] = D_00307ED0[1];
        dst[2] = D_00307ED0[2];
    }
    return D_00307ED0;
}

void func_001195E8(s32 x, s32 y)
{
    D_0058046C = (float)(x - 0x100) + 2048.0f;
    D_00580470 = (float)(y - 0xD0) + 2048.0f;
}

void func_00119628(void) {
}

INCLUDE_ASM("build/ee_asm/game/main/sg_1194E0", Sg_CalcScreenMatrix);

void Sg_CalcCameraMatrix(void)
{
    s32 h = MsCameraGet(6, 0, 0);

    MsCameraSetRect(h, 0, D_00307ED0);
    MsCameraSetRect(h, 1, D_00307EC0);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_1194E0", Sg_CalcViewClipMatrix);

void Sg_InitCamera(void)
{
    D_00580460 = 0;
    D_00580468 = D_00580464 = 50.0f;
}

float func_00119810(void)
{
    return func_001A9FB0();
}

void func_00119830(s32 v)
{
    D_005804D0 = v;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_1194E0", func_00119840);

INCLUDE_ASM("build/ee_asm/game/main/sg_1194E0", Sg_ControlCamera);
INCLUDE_RODATA("build/ee_asm/game/main/sg_1194E0/rodata", jtbl_00569A30);

INCLUDE_ASM("build/ee_asm/game/main/sg_1194E0", Sg_CameraSetPlayer);
