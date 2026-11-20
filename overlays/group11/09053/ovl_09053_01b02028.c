/* Shared 09053-family helper (TU rank 28, 225 containers): average target position via VU0. */
#include "p8_overlay.h"

extern u8 *func_001E4F58(int, int *);
extern void *func_001B4E58(int);
extern void func_00110220(void *, float *, float *, float *);

void func_01B02028(float *out)
{
    float pos[4];
    float sum[4];
    int cnt;
    u8 *ids;
    /* DEBT(FAKE): pin loop counter to $s1 so &sum takes $s0 instead of swapping $s0/$s1. */
    register int i __asm__("$17");

    ids = func_001E4F58(0x13, &cnt);
    sum[0] = sum[1] = sum[2] = 0.0f;
    for (i = 0; i < cnt; i++) {
        func_00110220(func_001B4E58(ids[i]), &pos[0], &pos[1], &pos[2]);
        __asm__ volatile(
            "lqc2 $vf1, 0(%0)\n\t"
            "lqc2 $vf2, 0(%1)\n\t"
            "vadd.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, 0(%0)"
            : : "r"(sum), "r"(pos) : "memory"
        );
    }
    __asm__ volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "qmtc2 %2, $vf2\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(out), "r"(sum), "r"((float)cnt) : "memory"
    );
    out[3] = 1.0f;
}
