/* tu_277 0x254028-0x254a38: medium; decode (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

int func_00254028(Actor *a, int b, ScriptCtx *ctx) {
    AtelPopStackInteger(a, ctx);
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/sqs/decode", spline_get_near_point);

INCLUDE_ASM("build/ee_asm/game/sqs/decode", spline_get_near_point_init);

typedef struct {
    u8 pad0[0x503E0];
    float m0[16];
    float m1[16];
    float m2[16];
    float m3[16];
    float v0[4];
    float v1[4];
    float v2[4];
    float f50510;
    u8 pad50514[0x14];
    s32 w50528;
    u8 pad5052C[0x50773 - 0x5052C];
    s8 b50773;
} Decode503E0;

extern float D_0031430C;
void func_001ACB48(void *a, void *b, void *c, void *d, float f);
void MsSetCameraMatrix(int a, void *b, void *c, void *d, void *e, float f);
void yiRenderEnable(int a);
void func_00173450(void *a, void *b);

void func_002545E0(Decode503E0 *a)
{
    int i;

    D_0031430C = a->f50510;
    func_001ACB48(a->m0, a->v0, a->v1, a->v2, 0.0f);
    MsSetCameraMatrix(1, a->m1, a->m0, a->v1, a->v0, a->f50510);
    switch (a->b50773) {
    case 1:
        if (a->w50528 >= 0x406) {
            a->b50773 = 2;
        }
        break;
    case 2:
        yiRenderEnable(0x800);
        func_00173450(a->m3, a->m2);
        break;
    }
    for (i = 0; i < 16; i++) {
        a->m2[i] = a->m0[i];
        a->m3[i] = a->m1[i];
    }
}

INCLUDE_ASM("build/ee_asm/game/sqs/decode", func_00254730);

int func_00254910(u8 *p, void *dst, int *out)
{
    int len = p[1] + (p[2] << 8) + (p[3] << 16) + (p[4] << 24);

    func_002EEF1C(dst, p + 5, len);
    *out = len;
    return len;
}

int sa_decode(int a, u8 *p)
{
    int out;

    D_00327070[*p](p, a, &out);
    return out;
}

int func_002549C8(u8 *p)
{
    if (p[0] != 1) {
        func_001577A8(D_00573818, D_00573820, 0x40);
    }
    return p[1] + (p[2] << 8) + (p[3] << 16) + (p[4] << 24);
}
