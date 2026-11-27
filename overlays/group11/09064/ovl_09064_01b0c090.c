#include "common.h"

typedef struct {
    u8 pad[320];
} Entry0630;

extern Entry0630 g_arr_0630[];
extern void g_fn_c9b8(int, int);
extern void g_fn_d930(void *, float, float, float, float, float, float, float, float, float);

void func_01B0C090(float f12)
{
    int i;
    float d;

    g_fn_c9b8(32, 27);
    d = 2.0f;
    for (i = 0; i < 2; i++) {
        float fk = (float)(i + 1);
        float dx = fk * 0.01923077f;
        float dy;

        g_fn_d930(&g_arr_0630[i * 4 + 0], f12 / d, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f - dx, 1.0f, 1.0f - dx);
        d += 1.0f;
        g_fn_d930(&g_arr_0630[i * 4 + 1], f12 / d, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, dx + -1.0f, 1.0f, dx + 1.0f);
        d += 1.0f;
        g_fn_d930(&g_arr_0630[i * 4 + 2], f12 / d++, -1.0f, -1.0f, 1.0f, 1.0f, (dy = fk * (1.0f / 64.0f)) + -1.0f, -1.0f, dy + 1.0f, 1.0f);
        g_fn_d930(&g_arr_0630[i * 4 + 3], f12 / d, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f - dy, -1.0f, 1.0f - dy, 1.0f);
        d += 1.0f;
    }
}
