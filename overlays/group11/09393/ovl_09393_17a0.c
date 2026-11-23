/* EE Battle-Effect Overlay: group 0x11, file 09393 (unique 0x01B017A0)
 * Load base: 0x01B00000, .text: 0x01B017A0..0x01B018DC (1 function)
 */
#include "common.h"
#include "vu0.h"

typedef struct Work09393 {
    u8 pad0000[0x4C0];
    u8 unk4C0[5][0x130];  /* 0x04C0 */
    u8 pad0AB0[0xF64];
    float unk1A14;        /* 0x1A14 */
    u8 pad1A18[8];
    float unk1A20[4];     /* 0x1A20 */
    u8 pad1A30[0x30];
    u8 unk1A60[4];        /* 0x1A60 */
    float unk1A64;        /* 0x1A64 */
} Work09393;

extern u8 D_01B00610[5][0x10];
extern int D_01B00660[5];
extern u8 D_01B07AE8[];
extern Work09393 *D_01B07C10;

float func_002B3DF8(float a0);
void func_01B045C0(void *a0, void *a1, int a2, int a3, float f0, int t0, void *t1);
void func_01B078A0(void *a0, int a1, int a2, float f0, float f1);

void func_01B017A0(void)
{
    Work09393 *w = D_01B07C10;
    u8 *p = w->unk4C0[0];
    u8 *q = w->unk1A60;
    int i;

    for (i = 0; i < 5; i++) {
        float r = (func_002B3DF8(0.5f) + 1.0f) * 0.15f;
        register u8 *d0 __asm__("$3");
        register u8 *d1 __asm__("$2");

        func_01B045C0(D_01B07AE8, p, 3, D_01B00660[i], r, 0, 0);
        *(float *)(p + 0xC4) = w->unk1A14;
        d0 = p + 0xD0;
        MMI_COPY_LQ_A3(d0, w->unk1A20);
        MMI_COPY_SQ_A3(d0);
        d1 = p + 0xE0;
        MMI_COPY_LQ_A3(d1, D_01B00610[i]);
        MMI_COPY_SQ_A3(d1);
        p += 0x130;
    }

    func_01B078A0(q, 0x1E, 0x28, 0.5f, 1.0f);
    *(float *)(q + 4) = 0.65f;
}
