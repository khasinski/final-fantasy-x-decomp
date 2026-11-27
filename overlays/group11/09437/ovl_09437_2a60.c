#include "common.h"

extern void func_002DCE08(void *, void *, void *);
extern void func_002DCF48(void *, void *);
extern void func_01B05198(void *, void *);
extern float func_01B08600(void);

void func_01B02A60(u8 *s2)
{
    float m0[4][4];
    float m1[4][4];
    float v[4];
    float sc;
    s32 f;

    func_01B05198(m0, m1);
    func_002DCF48(s2 + 0x80, m1);
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 5.0f;
    v[3] = 1.0f;
    func_002DCE08(s2 + 0xD0, s2 + 0x80, v);
    *(float *)(s2 + 0xDC) = 1.0f;
    sc = func_01B08600() * 0.001f;
    *(float *)(s2 + 0x6C) = sc;
    *(float *)(s2 + 0x68) = sc;
    *(float *)(s2 + 0x64) = sc;
    *(float *)(s2 + 0x60) = sc;
    f = *(s32 *)(s2 + 0x118);
    if (f < 9) {
        s32 d = 8;
        s32 c = (f << 12) / d;
        *(s16 *)(s2 + 0x76) = c;
        *(s16 *)(s2 + 0x74) = c;
        *(s16 *)(s2 + 0x72) = c;
        *(s16 *)(s2 + 0x70) = c;
    }
    if (f >= 0x1C) {
        s32 n = *(s32 *)(s2 + 0x120);
        s32 c;
        if (n > 0) {
            n--;
            *(s32 *)(s2 + 0x120) = n;
        }
        c = (n << 12) / 6;
        *(s16 *)(s2 + 0x76) = c;
        *(s16 *)(s2 + 0x74) = c;
        *(s16 *)(s2 + 0x72) = c;
        *(s16 *)(s2 + 0x70) = c;
    }
}
