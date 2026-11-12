/* tu_038 0x1201b0-0x120cf8: low; ~Sg (config/tu_map.tsv) */
#define func_00120958 _hdr_func_00120958
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_00120958

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", func_001201B0);

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

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", Sg_MatrixToQuaternion);

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

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", Sg_QuaternionSlerp);
