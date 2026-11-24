#include "common.h"

extern u8 D_01B054D0[];
extern void *D_01B05540;
extern int D_01B05544;

extern void *func_01B01BA0(int);
extern int func_0010D380(void *, int, int);
extern int func_0010D3A8(void *, int, int);
extern void func_002A7308(void *, void *, int, int);
extern void func_01B022A8(int, void *);
extern void func_01B035A8(int, void *);
extern void func_01B03608(void *);
extern void func_01B00588(void *, void *, void *, void *, void *, void *, float, float);
extern void func_01B01E88(int, void *);
extern void func_01B01D58(int, void *, int);
extern float func_01B01C30(int);
extern float func_01B04A98(float, float, float, float);
extern void func_01B04DE8(void *, void *, void *);

void func_01B016D0(void)
{
    void *s0 = func_01B01BA0(0);
    func_0010D380(s0, -1, 0x3C00);
    func_0010D3A8(s0, -1, 0x2EE0);
    func_002A7308(D_01B05540, s0, 1, 0);
}

void func_01B01730(void)
{
    void *s0 = func_01B01BA0(0);
    func_0010D380(s0, -1, -1);
    func_0010D3A8(s0, -1, -1);
}

void func_01B01778(void)
{
    u8 a[0x40];
    u8 b[0x40];
    u8 c[0x40];
    float col[4];
    float f0;
    float f1;

    func_01B022A8(0, a);
    f1 = 1.0f;
    func_01B035A8(0, b);
    func_01B03608(c);
    col[0] = 80.0f;
    col[1] = 80.0f;
    col[2] = 220.0f;
    col[3] = 128.0f;
    if (D_01B05544 >= 51) {
        float t = (float)(D_01B05544 - 50) / 50.0f;
        f0 = 1.0f;
        f1 = (1.0f - t) + t * 0.0f;
    } else {
        f0 = (float)D_01B05544 / 50.0f;
    }
    func_01B00588(func_01B01BA0(0), D_01B05540, a, b, c, col, f0, f1);
}

void func_01B01898(void)
{
    float v00[4];
    float v10[4];
    float v20[4];
    int s0 = D_01B05544 - 15;
    float f;
    float z;

    if (s0 >= 51) {
        func_01B01E88(0, D_01B054D0);
        return;
    }
    func_01B01D58(0, v00, 0);
    v20[0] = 0.0f;
    v20[1] = func_01B01C30(0);
    v20[2] = 0.0f;
    z = *(volatile float *)&v20[2];
    f = func_01B04A98(z, 0.8f, z, (float)s0 / 50.0f);
    v10[0] = f;
    v10[1] = z;
    v10[2] = z;
    v10[3] = 1.0f;
    if (D_01B05544 & 1) {
        v10[0] = -f;
    }
    func_01B04DE8(v20, v00, v10);
    func_01B01E88(0, v00);
}
