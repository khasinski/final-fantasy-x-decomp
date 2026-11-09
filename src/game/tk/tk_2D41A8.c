/* tu_338 0x2d41a8-0x2d5b90: low; ~Tk (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: pad/vector helpers (see w10.h). */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/u5.h"

void func_002D41A8(s32 unused, u16 b, s32 c) {
    D_0078B160[c] = b;
    D_0078B138[c] = -1;
}

void func_002D41D8(void) {
}

void func_002D41E0(void) {
}

void func_002D41E8(int v) {
}

void func_002D41F0(int v) {
}

s32 TkGetSyncH(s32 i) {
    return D_0078B160[i];
}

void func_002D4210(void) {
}

float func_002D4218(float x) {
    return func_002E89C0(x);
}

float func_002D4238(float x) {
    return func_002E8648(x);
}

float func_002D4258(float x) {
    return func_002E8AB0(x);
}

float func_002D4278(float x, float y, float z) {
    return x * x + y * y + z * z;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D4290);

void func_002D42C8(void *a) {
    func_002DCEC8(a, a);
}

float func_002D42D0(float x)
{
    float t = x + 3.1415927f;

    t -= func_002E8750(t / 6.2831855f) * 6.2831855f;
    return t - 3.1415927f;
}

float func_002D4338(float a) {
    float var_f0;

    var_f0 = a;
    if (var_f0 < -3.1415927f) {
        do {
            var_f0 += 6.2831855f;
        } while (var_f0 < -3.1415927f);
    }
    if (var_f0 > 3.1415927f) {
        do {
            var_f0 -= 6.2831855f;
        } while (var_f0 > 3.1415927f);
    }
    return var_f0;
}

float func_002D43C8(float x)
{
    if (x < -3.1415927f) {
        x = -3.1415927f;
    }
    if (x > 3.1415927f) {
        x = 3.1415927f;
    }
    return x;
}

s32 func_002D4410(void) {
    return func_002E94A0();
}

void func_002D4430(float value)
{
    CALL_func_002D4410_FLOAT(value, 1.0f);
}

s32 func_002D4458(s32 a)
{
    a &= 0x7FFF;
    if (a < 0x2000) {
        return D_00561F28[a];
    }
    if (a < 0x4000) {
        return D_00561F28[0x3FFF - a];
    }
    a -= 0x4000;
    if (a < 0x2000) {
        return -D_00561F28[a];
    }
    return -D_00561F28[0x3FFF - a];
}

s32 func_002D44E0(s32 a) {
    return func_002D4458(a);
}

s32 func_002D4500(s32 a) {
    return func_002D4458(a + 0x2000);
}

extern float D_00576040;
float _m2c_func_002D4520_func_002E94A0(float, float) __asm__("func_002E94A0");

float func_002D4520(float a, float b, float c, float d)
{
    float dx = c - a;
    float dy = d - b;

    if (__builtin_fabsf(dx) == 0.0f) {
        if (dy >= 0.0f) {
            return 1.5707964f;
        }
        return -1.5707964f;
    }
    if (__builtin_fabsf(dy) == 0.0f) {
        if (dx >= 0.0f) {
            return D_00576040;
        }
        return 3.1415927f;
    }
    return _m2c_func_002D4520_func_002E94A0(dy, dx);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D45C0);

float func_002D4690(float a, float b)
{
    float r;

    a = __builtin_fabsf(a);
    r = b;
    if (a < r) {
        r = a;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D46B0);

float func_002D4740(float a, float b, float c)
{
    float t = a + c;
    float p = (a - b) * (t - b);

    float r;

    if (p == 0.0f) {
        r = b;
    } else if (p > 0.0f) {
        r = t;
    } else {
        r = b;
    }
    return func_002D4338(r);
}

float func_002D4798(int mode, float a, float b, float c)
{
    float r;

    switch (mode) {
    case 1:
        r = func_002D4740(a, b, c);
        break;
    case 2:
        r = func_002D4740(a, b, -c);
        break;
    default:
        r = func_002D46B0(a, b, c);
        break;
    }
    return r;
}

int func_002D47E8(float a, float b, float c, float d, float e, float f)
{
    float r = func_002D4520(c, d, e, f);

    r = func_002D4338(r - a);
    if (func_002D4690(r, b) < b) {
        return 1;
    }
    return 0;
}

int func_002D4850(float w, float x, float y, float z)
{
    if (x * x + y * y + z * z <= w * w) {
        return 1;
    }
    return 0;
}

int func_002D4888(float x)
{
    float a = func_002D4338(x);

    if (a < 0.0f) {
        a += 6.2831855f;
    }
    return (int)(a * 32768.0f / 6.2831855f) & 0x7FFF;
}

int func_002D48F8(float x)
{
    float a = func_002D4338(x);

    if (a < 0.0f) {
        a += 6.2831855f;
    }
    return (int)(a * 4096.0f / 6.2831855f) & 0xFFF;
}

float func_002D4968(int a)
{
    return func_002D4338((float)(a & 0x7FFF) * 6.2831855f * 0.000030517578125f);
}

float func_002D49A8(int a)
{
    return func_002D4338((float)(a & 0xFFF) * 6.2831855f * 0.000244140625f);
}

void func_002D49E8(float (*m)[4])
{
    int i;
    int j;
    float one = 1.0f;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            m[i][j] = 0.0f;
        }
    }
    for (i = 0; i < 4; i++) {
        m[i][i] = one;
    }
}

void func_002D4A68(float (*m)[4])
{
    float t[4][4];
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            t[i][j] = m[i][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            m[j][i] = t[i][j];
        }
    }
}

void func_002D4B10(float (*m)[4], int angle)
{
    float a = angle;
    float s = func_002E89C0(a);
    float c = func_002E8648(a);

    func_002D49E8(m);
    m[0][0] = c;
    m[0][1] = -s;
    m[1][0] = s;
    m[1][1] = c;
    func_002D4A68(m);
}

void func_002D4B80(float (*m)[4], int angle)
{
    float a = angle;
    float s = func_002E89C0(a);
    float c = func_002E8648(a);

    func_002D49E8(m);
    m[0][0] = c;
    m[2][0] = -s;
    m[0][2] = s;
    m[2][2] = c;
    func_002D4A68(m);
}

void func_002D4BF0(float (*m)[4], int angle)
{
    float a = angle;
    float s = func_002E89C0(a);
    float c = func_002E8648(a);

    func_002D49E8(m);
    m[1][1] = c;
    m[1][2] = -s;
    m[2][1] = s;
    m[2][2] = c;
    func_002D4A68(m);
}

void func_002D4C60(void *unused, float *m, Vec4 *v)
{
    float t[4];
    int i;

    for (i = 0; i < 4; i++) {
        t[i] = m[i] * v->x + m[i + 4] * v->y + m[i + 8] * v->z + m[i + 12] * v->w;
    }
}

void func_002D4CC8(void *unused, float (*a)[4], float (*b)[4])
{
    float t[4][4];
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            t[j][i] = a[0][j] * b[i][0] + a[1][j] * b[i][1] + a[2][j] * b[i][2] + a[3][j] * b[i][3];
        }
    }
}

void func_002D4D58(float *out, float a, float b, float c)
{
    float componentY;
    float angleC;
    float angleB;

    angleB = b;
    angleC = func_002D4338(c);
    /* DEBT(ORDER): independent angle updates retain original float scheduling. */
    if (angleC > 1.5707964f)
    {
        angleB += 3.1415927f;
        angleC = 3.1415927f - angleC;
    }
    if (angleC < -1.5707964f)
    {
        angleB += 3.1415927f;
        angleC += 3.1415927f;
    }
    angleB = func_002D4338(angleB);
    componentY = func_002D4218(angleC) * a;
    out[3] = 1.0f;
    out[1] = componentY;
    a = a * func_002D4238(angleC);
    out[0] = func_002D4238(angleB) * a;
    out[2] = (float) (func_002D4218(angleB) * a);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D4E50);

void TkMtCalcSpline(s32 a, void *b, s32 c, float f) {
    func_002D4E50(a, b, c, 1, f);
}

void func_002D5188(s32 a, void *b, s32 c, float f) {
    func_002D4E50(a, b, c, 0, f);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D5190);

void func_002D5448(s32 a, void *b, s32 c, float f) {
    func_002D5190(a, b, c, 1, f);
}

void func_002D5450(s32 a, void *b, s32 c, float f) {
    func_002D5190(a, b, c, 0, f);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D5458);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D5540);

void func_002D5628(float fparg0) {
    float var_f0;

    var_f0 = func_002D4338(fparg0) * 57.295776f;
    if (var_f0 > 360.0f) {
        do {
            var_f0 -= 360.0f;
        } while (var_f0 > 360.0f);
    }
    if (var_f0 < 0.0f) {
        do {
            var_f0 += 360.0f;
        } while (var_f0 < 0.0f);
    }
}

float func_002D56C0(float angle)
{
    return func_002D4338(angle * 0.01745329238474369f);
}

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D56E8);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D5798);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D5A40);

INCLUDE_ASM("build/ee_asm/game/tk/tk_2D41A8", func_002D5AE8);

float func_002D5B60(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
}
