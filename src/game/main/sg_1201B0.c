/* tu_038 0x1201b0-0x120cf8: low; ~Sg (config/tu_map.tsv) */
#define func_00120958 _hdr_func_00120958
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_00120958

extern float func_002E8648(float);
extern float func_002E89C0(float);

static inline float sg_1201B0_deg2rad(float deg)
{
    float rad = deg * 3.141592f / 180.0f;
    while (rad > 3.141592f) {
        rad -= 3.141592f * 2.0f;
    }
    while (rad < -3.141592f) {
        rad += 3.141592f * 2.0f;
    }
    return rad;
}

void func_001201B0(float *v, float a, float b)
{
    v[1] = func_002E89C0(sg_1201B0_deg2rad(b));
    v[0] = func_002E89C0(sg_1201B0_deg2rad(a)) * func_002E8648(sg_1201B0_deg2rad(b));
    v[2] = func_002E8648(sg_1201B0_deg2rad(a)) * func_002E8648(sg_1201B0_deg2rad(b));
    v[3] = 1.0f;
}

void func_002DCE80(void *a, void *b, void *c);

void Sg_VectorToMatrix2(float (*m)[4], float *v)
{
    float tmp[4];
    float v1[4];
    float v2[4];
    float v3[4];
    float up[4];

    up[0] = 0.0f;
    up[1] = -1.0f;
    up[2] = 0.0f;
    tmp[0] = v[0];
    tmp[1] = v[1];
    tmp[2] = v[2];
    tmp[3] = 1.0f;
    func_002DCEC8(v2, tmp);
    func_002DCE80(tmp, up, v2);
    func_002DCEC8(v1, tmp);
    func_002DCE80(tmp, v1, v2);
    func_002DCEC8(v3, tmp);
    func_002DD128(m);
    m[0][0] = v2[0];
    m[0][1] = v2[1];
    m[0][2] = v2[2];
    m[1][0] = v3[0];
    m[1][1] = v3[1];
    m[1][2] = v3[2];
    m[2][0] = v1[0];
    m[2][1] = v1[1];
    m[2][2] = v1[2];
}

typedef struct {
    int a[3];
} Next3;
extern const Next3 D_00569FB8;

void Sg_MatrixToQuaternion(float (*m)[4], float *q)
{
    float tmp[4];
    Next3 nxt = D_00569FB8;
    float tr = m[0][0] + m[1][1] + m[2][2];
    float s;

    if ((double)tr > 0.0) {
        s = sqrtf(tr + 1.0);
        q[3] = s * 0.5;
        s = 0.5 / s;
        q[0] = (m[1][2] - m[2][1]) * s;
        q[1] = (m[2][0] - m[0][2]) * s;
        q[2] = (m[0][1] - m[1][0]) * s;
    } else {
        int i = 0;
        int j;
        int k;

        if (m[1][1] > m[0][0]) {
            i = 1;
        }
        if (m[2][2] > m[i][i]) {
            i = 2;
        }
        j = nxt.a[i];
        k = nxt.a[j];
        s = sqrtf((m[i][i] - (m[j][j] + m[k][k])) + 1.0);
        tmp[i] = s * 0.5;
        if ((double)s != 0.0) {
            s = 0.5 / s;
        }
        tmp[3] = (m[j][k] - m[k][j]) * s;
        tmp[j] = (m[i][j] + m[j][i]) * s;
        tmp[k] = (m[i][k] + m[k][i]) * s;
        q[0] = tmp[0];
        q[1] = tmp[1];
        q[2] = tmp[2];
        q[3] = tmp[3];
    }
}

/* DEBT(CAST) */
void func_00120958(void *arg0, void *arg1) {
    float temp_f0;
    float temp_f0_2;
    float temp_f1;
    float temp_f20;
    float temp_f20_2;
    float temp_f21;
    float temp_f21_2;
    float temp_f22;
    float temp_f22_2;
    float temp_f23;
    float temp_f23_2;
    float temp_f24;
    float temp_f24_2;
    float temp_f25;
    float temp_f26;
    float temp_f27;
    float temp_f28;
    s64 temp_17;

    temp_f20 = (*(float *)((u8 *)(arg0) + (0)));
    temp_f21 = (*(float *)((u8 *)(arg0) + (4)));
    temp_f22 = (*(float *)((u8 *)(arg0) + (8)));
    temp_f24 = 2.0f * temp_f20;
    temp_f1 = 2.0f * temp_f21;
    temp_f23 = (*(float *)((u8 *)(arg0) + (0xC)));
    temp_f0 = 2.0f * temp_f22;
    temp_f24_2 = temp_f20 * temp_f24;
    temp_f22_2 = temp_f22 * temp_f0;
    temp_f23_2 = temp_f23 * temp_f1;
    temp_f21_2 = temp_f21 * temp_f0;
    temp_f20_2 = temp_f20 * temp_f1;
    temp_f25 = temp_f20 * temp_f0;
    temp_f26 = temp_f23 * temp_f0;
    temp_f27 = temp_f23 * temp_f24;
    temp_f28 = temp_f21 * temp_f1;
    (*(float *)((u8 *)(arg1) + (0))) = (float)(1.0 - (double)(temp_f28 + temp_f22_2));
    (*(float *)((u8 *)(arg1) + (0x10))) = (float) (temp_f20_2 - temp_f26);
    (*(float *)((u8 *)(arg1) + (0x20))) = (float) (temp_f25 + temp_f23_2);
    (*(float *)((u8 *)(arg1) + (4))) = (float) (temp_f20_2 + temp_f26);
    (*(s32 *)((u8 *)(arg1) + (0x30))) = 0;
    temp_f0_2 = (float)(1.0 - (double)(temp_f24_2 + temp_f22_2));
    (*(float *)((u8 *)(arg1) + (0x24))) = (float) (temp_f21_2 - temp_f27);
    (*(float *)((u8 *)(arg1) + (8))) = (float) (temp_f25 - temp_f23_2);
    (*(float *)((u8 *)(arg1) + (0x18))) = (float) (temp_f21_2 + temp_f27);
    (*(float *)((u8 *)(arg1) + (0x14))) = temp_f0_2;
    (*(s32 *)((u8 *)(arg1) + (0x34))) = 0;
    (*(float *)((u8 *)(arg1) + (0x28))) = (float)(1.0 - (double)(temp_f24_2 + temp_f28));
    (*(s32 *)((u8 *)(arg1) + (0xC))) = 0;
    (*(float *)((u8 *)(arg1) + (0x3C))) = 1.0f;
    (*(s32 *)((u8 *)(arg1) + (0x1C))) = 0;
    (*(s32 *)((u8 *)(arg1) + (0x2C))) = 0;
    (*(s32 *)((u8 *)(arg1) + (0x38))) = 0;
}

extern double func_002E8B38(double);
INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", Sg_QuaternionSlerp);
