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

void MsSetScreen(s32, float, float, float, float, float, float, float, float, float);

void Sg_CalcScreenMatrix(void)
{
    MsSetScreen(0, MsCameraGetScrDpt(), 0.8f, 14.0f / 15.0f, D_0058046C, D_00580470, 1.0f, 16770000.0f, 1.0f, 65536.0f);
}

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
extern s32 D_003038F4;
extern s32 D_003038F8;
extern u8 D_003038FC;
extern u8 D_003038FD;
void Sg_CaptureEnable(void);
int Sg_GetPlayerPos(float *);
double func_002E8278(double);
double func_002E7B28(double);

void Sg_CalcViewClipMatrix(float (*m)[4], s32 mode)
{
    float dpt;
    float near;
    float far;
    float w;
    float hw;
    float s;

    dpt = MsCameraGetScrDpt();
    far = 16770000.0f;
    if (mode != 0) {
        near = 1.0f;
        w = 3000.0f;
    } else {
        near = 1.0f;
        w = 500.0f;
    }
    func_002DD128(m);
    hw = (near * w) / dpt;
    s = (near * 2.0f) / (hw * 2.0f);
    m[2][3] = 1.0f;
    m[3][3] = 0.0f;
    m[2][2] = (far + near) / (far - near);
    m[3][2] = (far * near * -2.0f) / (far - near);
    m[0][0] = s;
    m[1][1] = s;
}

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

void Sg_ControlCamera(void)
{
    s32 ry;
    s32 rx;

    ry = D_003038FD;
    if (ry > 80 && ry < 176) {
        ry = 128;
    }
    D_00307EF0[0] += (float)D_00307F04 * (3.141592f / 180.0f) / 60.0f;
    D_00307F04 = 0;
    D_00307EF0[0] -= (float)(ry - 128) * (3.141592f / 180.0f) / 12.0f;
    rx = D_003038FC;
    if (rx > 80 && rx < 176) {
        rx = 128;
    }
    D_00307EF0[1] += (float)D_00307F00 * (3.141592f / 180.0f) / 60.0f;
    D_00307EF0[1] -= (float)(rx - 128) * (3.141592f / 180.0f) / 12.0f;
    if (D_00307EF0[0] > 3.141592f) {
        D_00307EF0[0] -= 3.141592f * 2.0f;
    }
    if (D_00307EF0[0] < -3.141592f) {
        D_00307EF0[0] += 3.141592f * 2.0f;
    }
    if (D_00307EF0[1] > 3.141592f) {
        D_00307EF0[1] -= 3.141592f * 2.0f;
    }
    if (D_00307EF0[1] < -3.141592f) {
        D_00307EF0[1] += 3.141592f * 2.0f;
    }
    if (ffx_debugmode && (D_003038F4 & 0x100) && Sg_CaptureGetSelect()) {
        Sg_CaptureEnable();
    }
    if (Sg_GetLRButtonMode() != 0) {
        if (D_003038F4 & 2) {
            D_00307EE0[1] += 0.2f;
        }
        if (D_003038F4 & 8) {
            D_00307EE0[1] -= 0.2f;
        }
        if (D_003038F4 & 1) {
            D_00580468 += 0.4f;
        }
        if (D_003038F4 & 4) {
            D_00580468 -= 0.4f;
        }
    }
    if (D_003038F8 & 0x400) {
        D_00580460++;
        switch ((D_00580460 & 0xFF) % 6) {
        case 0:
            D_00580468 = 50.0f;
            break;
        case 1:
            D_00580468 = 100.0f;
            break;
        case 2:
            D_00580468 = 180.0f;
            break;
        case 3:
            D_00580468 = 250.0f;
            break;
        case 4:
            D_00580468 = 1000.0f;
            break;
        case 5:
            D_00580468 = 30.0f;
            break;
        }
    }
}

void Sg_CameraSetPlayer(void)
{
    float v[4];
    float unused[4];
    float c;
    s32 p;

    D_00580464 -= (D_00580464 - D_00580468) * 0.125f;
    if (Sg_GetPlayerPos(D_00307ED0) != 0) {
        D_00307ED0[0] = 0.0f;
        D_00307ED0[1] = 0.0f;
        D_00307ED0[2] = 0.0f;
    }
    p = Sg_GetPlayer();
    if (p != 0) {
        func_00110560((Chr *)p);
    }
    D_00307ED0[1] -= 10.0f;
    D_00307ED0[0] += D_00307EE0[0];
    D_00307ED0[1] += D_00307EE0[1];
    D_00307ED0[2] += D_00307EE0[2];
    if (D_00307EF0[0] > 3.141592f / 2.0f) {
        D_00307EF0[0] = 3.141592f / 2.0f;
    }
    if (D_00307EF0[0] < -3.141592f / 2.0f) {
        D_00307EF0[0] = -3.141592f / 2.0f;
    }
    if (D_00580464 < 1.0f) {
        D_00580464 = 1.0f;
    }
    v[1] = (float)func_002E8278((double)D_00307EF0[0]);
    c = (float)func_002E7B28((double)D_00307EF0[0]);
    v[0] = (float)(func_002E8278((double)D_00307EF0[1]) * (double)c);
    v[2] = (float)(func_002E7B28((double)D_00307EF0[1]) * (double)c);
    v[0] *= -D_00580464;
    v[1] *= -D_00580464;
    v[2] *= -D_00580464;
    D_00307EC0[0] = D_00307ED0[0] + v[0];
    D_00307EC0[1] = D_00307ED0[1] + v[1];
    D_00307EC0[2] = D_00307ED0[2] + v[2];
    Sg_CalcCameraMatrix();
}
