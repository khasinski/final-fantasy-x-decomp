#include "common.h"
#include "vu0.h"

extern u8 *D_01B0BC98;
extern u8 D_01B0BB70[];
extern u8 D_01B0BC78[];
extern int D_01B00E98[];
extern void func_01B049D0(int, void *, int);
extern float func_01B048A8(int);
extern int func_001ACEA0(void);
extern float func_002B3DB0(float);
extern int func_01B072F0(void *, void *, int, int, int, int, float);
extern void func_01B078B0(void);
extern void *func_01B04780(int);
extern void func_01B05C40(int, void *);
extern void func_01B06710(void *, int);
extern void func_01B057D8(int);

void func_01B04108(void)
{
    u8 buf[0x10];
    u8 *s0 = D_01B0BC98 + 0xBE0;
    int s2;

    for (s2 = 0; s2 < D_01B00E98[1]; s2++) {
        float f22;
        int s1;
        int s3;

        func_01B049D0(s2, buf, 5);
        f22 = func_01B048A8(s2);
        s1 = func_001ACEA0() % 5;
        for (s3 = 0; s3 < 3; s3++) {
            float r = (func_002B3DB0(0.2f) + 1.0f) * 0.2f;
            u8 *dst;

            func_01B072F0(D_01B0BB70, s0, 9, s1, 0, 0, r);
            dst = s0 + 0xD0;
            MMI_COPY_LQ_A3(dst, buf);
            MMI_COPY_SQ_A3(dst);
            *(float *)(s0 + 0xE0) = func_002B3DB0(20.0f);
            *(float *)(s0 + 0xE4) = func_002B3DB0(20.0f);
            *(float *)(s0 + 0xE8) = func_002B3DB0(10.0f);
            *(float *)(s0 + 0xC4) = f22;
            if (s3 == 2) {
                *(void **)(s0 + 0x100) = (void *)func_01B078B0;
                *(void **)(s0 + 0x120) = func_01B04780(s2);
            }
            s1 += func_001ACEA0() % 10 + 5;
            s0 += 0x130;
        }
    }
    func_01B05C40(-1, 0);
    func_01B06710(D_01B0BC78, 0);
    func_01B057D8(1);
}
