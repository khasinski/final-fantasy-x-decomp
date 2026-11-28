#include "common.h"

extern void func_002DCE38(void *, void *, void *);
extern void func_01B019C0(void *, void *, void *, s32);

s32 func_01B01A10(u8 *a0, void *a1, u8 *a2, float *a3, float *a4) {
    float mat[16];
    s32 total;
    s32 i;
    u8 *entry;

    a3[0] = 20000.0f;
    a3[1] = 20000.0f;
    a3[2] = 20000.0f;
    a4[0] = -20000.0f;
    a4[1] = -20000.0f;
    a4[2] = -20000.0f;

    total = 0;
    entry = a0 + 0x10;
    {
        register u8 *a2_r __asm__("$22") = a2;
        register s32 i_r __asm__("$23") = 0;
        a2 = a2_r;
        for (i = i_r; i < *(u16 *)(a0 + 4); i++) {
        u8 *sub = *(u8 **)entry;
        u8 *prim = sub + *(u32 *)(sub + 4);
        u8 *verts = sub + *(u32 *)(sub + 8);
        s32 rem;

        func_002DCE38(mat, a1, *(void **)(entry + 4));
        func_01B019C0(mat, verts, a2, *(s16 *)(sub + 0x12));

        rem = *(s16 *)(sub + 0x10);
        total += rem;
        while (rem > 0) {
            u8 *p = prim + 0x20;
            if (*(s8 *)(prim + 1) == 0x10) {
                s32 n = *(s16 *)(prim + 2);
                s32 j;
                for (j = 0; j < n; j++, p += 0x1C) {
                    float *v;

                    v = (float *)((*(u16 *)(p + 0) << 4) + (u32)a2);
                    if (a3[0] > v[0]) a3[0] = v[0];
                    if (a3[1] > v[1]) a3[1] = v[1];
                    if (a3[2] > v[2]) a3[2] = v[2];
                    if (a4[0] < v[0]) a4[0] = v[0];
                    if (a4[1] < v[1]) a4[1] = v[1];
                    if (a4[2] < v[2]) a4[2] = v[2];

                    v = (float *)((*(u16 *)(p + 2) << 4) + (u32)a2);
                    if (a3[0] > v[0]) a3[0] = v[0];
                    if (a3[1] > v[1]) a3[1] = v[1];
                    if (a3[2] > v[2]) a3[2] = v[2];
                    if (a4[0] < v[0]) a4[0] = v[0];
                    if (a4[1] < v[1]) a4[1] = v[1];
                    if (a4[2] < v[2]) a4[2] = v[2];

                    v = (float *)((*(u16 *)(p + 4) << 4) + (u32)a2);
                    if (a3[0] > v[0]) a3[0] = v[0];
                    if (a3[1] > v[1]) a3[1] = v[1];
                    if (a3[2] > v[2]) a3[2] = v[2];
                    if (a4[0] < v[0]) a4[0] = v[0];
                    if (a4[1] < v[1]) a4[1] = v[1];
                    if (a4[2] < v[2]) a4[2] = v[2];
                }
            }
            rem -= *(s16 *)(prim + 2);
            prim = p;
        }
        {
            register u8 *next_e __asm__("$8") = entry + 0x10;
            register s32 step __asm__("$3");
            __asm__("" : "+r"(next_e));
            entry = next_e;
            step = *(s16 *)(sub + 0x12) << 4;
            __asm__("" : "+r"(step));
            a2 += step;
        }
        }
    }

    return total;
}
