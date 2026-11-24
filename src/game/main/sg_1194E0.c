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

void func_002DD128(void *);
void func_002DD270(void *, void *, float);
void func_002DD318(void *, void *, float);
void func_002DCE08(void *, void *, void *);
extern float D_00307EE0[];
extern float D_00307EF0[];
extern s32 D_00307F00;
extern s32 D_00307F04;

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

void func_00119840(void)
{
    float v0[4];
    float v1[4];
    float m[4][4];
    float fx;
    float fy;
    if (D_005804D0 == 0) {
        return;
    }
    {
        register u8 *b0 __asm__("$6") = (u8 *)0x2000000;
        register u8 *b1 __asm__("$3") = (u8 *)0x2000000;
        register u8 *b2 __asm__("$4");
        s32 btn;
        __asm__("" : "+r"(b0));
        __asm__("" : "+r"(b1));
        btn = *(volatile s32 *)(b0 + 0x4ABC);
        b2 = (u8 *)0x2000000;
        __asm__ volatile("" : "+r"(b2));
        fx = *(float *)(b1 + 0x4AC0);
        fy = *(float *)(b2 + 0x4AC4);
        if (btn & 1) {
            D_00307F00 = (s32)((fx < 0.0f) ? (fx * -fx) : (fx * fx));
            {
                float t = *(volatile float *)(b2 + 0x4AC4);
                D_00307F04 = (s32)((t < 0.0f) ? (t * -t) : (t * t));
            }
        }
        {
            s32 b = *(volatile s32 *)(b0 + 0x4ABC);
            if (b & 0x100) {
                D_00580468 = D_00580464 = D_00580464 - (fy * D_00580464) / 250.0f;
                fy = 0.0f;
            } else if (!(b & 0x10000)) {
                return;
            }
        }
    }
    v0[0] = -(fx * D_00580464) / 1000.0f;
    v0[1] = -(fy * D_00580464) / 1000.0f;
    v0[2] = 0.0f;
    func_002DD128(m);
    func_002DD270(m, m, -D_00307EF0[0]);
    func_002DD318(m, m, D_00307EF0[1]);
    func_002DCE08(v1, m, v0);
    D_00307EE0[0] += v1[0];
    D_00307EE0[1] += v1[1];
    D_00307EE0[2] += v1[2];
}

INCLUDE_ASM("build/ee_asm/game/main/sg_1194E0", Sg_ControlCamera);
INCLUDE_RODATA("build/ee_asm/game/main/sg_1194E0/rodata", jtbl_00569A30);

INCLUDE_ASM("build/ee_asm/game/main/sg_1194E0", Sg_CameraSetPlayer);
