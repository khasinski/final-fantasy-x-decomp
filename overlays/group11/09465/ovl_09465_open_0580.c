#include "rcef_overlay.h"

extern float D_01B01AD0[3];
extern float D_01B01ADC;
extern float D_01B01AE0;
extern int D_01B01AE4;
extern int D_01B01AE8;
extern int D_01B01AEC;
extern float D_01B01AF0;
extern int D_01B01AF4;
extern float D_01B01B00[16][4];
extern int D_01B01C00[16];

extern void func_01B007E8(W3Task *);

extern int func_001AF358(void);
extern void func_001A2698(int, int, int, int);
extern float func_001A2A08(int);
extern float func_001A2A28(void);
extern float func_001A2A38(int);
extern float func_001A2A58(int);
extern void func_001A2F50(int, int, float *, float *);
extern void func_001A3040(int, int, float *);
extern float func_001A3360(float, float);
extern void *func_002EF0D0(void *, int, int);

void func_01B00580(W3Task *t)
{
    float v0[4];
    float v1[4];
    float max_ang;
    float base_ang;
    int i;

    if (func_001AF358() == 0x02380000) {
        func_001A2698(0xB, 0, 0, 1);
    } else {
        func_001A2698(0xB, 0, 6, 1);
    }
    max_ang = 0.0f;
    D_01B01AF4 = D_00313CB0.target_count;
    D_01B01ADC = max_ang;
    base_ang = func_001A2A28();
    v0[0] = max_ang;
    v0[1] = max_ang;
    v0[2] = max_ang;
    v0[3] = max_ang;
    func_001A2F50(D_00313CB0.caster, 0xB, v0, v1);
    for (i = 0; i < D_01B01AF4; i++) {
        float dist;
        dist = func_001A2A08(i) + 20.0f;
        if (D_01B01ADC < dist) {
            D_01B01ADC = dist;
            D_01B01AE8 = (int)(dist / 3.0f);
            D_01B01AE0 = func_001A2A58(i);
        }
        {
            /* DEBT(FAKE): match mov.s $f1,$f0 copy after func_001A3360 */
            register float ang_r __asm__("$f1") = func_001A3360(func_001A2A38(i), base_ang);
            __asm__("" : "+f"(ang_r));
            if (max_ang < ang_r) {
                max_ang = ang_r;
            }
        }
        func_001A3040(D_00313CB0.targets[i], 0, D_01B01B00[i]);
    }
    if (max_ang < 0.436332315f) {
        max_ang = 0.436332315f;
    }
    D_01B01AD0[0] = base_ang;
    D_01B01AD0[1] = base_ang - max_ang;
    D_01B01AD0[2] = base_ang + max_ang;
    D_01B01AF0 = 1.0f;
    D_01B01AE4 = 0;
    D_01B01AEC = 0;
    func_002EF0D0(D_01B01C00, 0, 0x40);
    func_001A1D08(t, func_01B007E8);
    func_001A1D50(t, func_001A2058);
}
