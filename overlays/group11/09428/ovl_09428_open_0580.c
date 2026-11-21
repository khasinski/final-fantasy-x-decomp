#include "rcef_overlay.h"

extern float D_01B01B00[3];
extern float D_01B01B0C;
extern float D_01B01B10;
extern int D_01B01B14;
extern int D_01B01B18;
extern int D_01B01B1C;
extern int D_01B01B20;
extern float D_01B01B24;
extern int D_01B01B28;
extern float D_01B01B30[16][4];
extern int D_01B01C30[16];

extern void func_01B007D0(W3Task *);

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

    func_001A2698(0x4A, 0, 6, 1);
    max_ang = 0.0f;
    D_01B01B28 = D_00313CB0.target_count;
    D_01B01B0C = max_ang;
    base_ang = func_001A2A28();
    v0[0] = -4.0f;
    v0[1] = max_ang;
    v0[2] = max_ang;
    v0[3] = max_ang;
    func_001A2F50(D_00313CB0.caster, 0x4A, v0, v1);
    for (i = 0; i < D_01B01B28; i++) {
        float dist;
        dist = func_001A2A08(i) + 20.0f;
        if (D_01B01B0C < dist) {
            D_01B01B0C = dist;
            D_01B01B1C = (int)(dist / 3.0f);
            D_01B01B10 = func_001A2A58(i);
        }
        {
            /* DEBT(FAKE): match mov.s $f1,$f0 copy after func_001A3360 */
            register float ang_r __asm__("$f1") = func_001A3360(func_001A2A38(i), base_ang);
            __asm__("" : "+f"(ang_r));
            if (max_ang < ang_r) {
                max_ang = ang_r;
            }
        }
        func_001A3040(D_00313CB0.targets[i], 0, D_01B01B30[i]);
    }
    if (max_ang < 0.436332315f) {
        max_ang = 0.436332315f;
    }
    D_01B01B00[0] = base_ang;
    D_01B01B00[1] = base_ang + max_ang;
    D_01B01B00[2] = base_ang - max_ang;
    D_01B01B24 = 1.0f;
    D_01B01B14 = 0;
    D_01B01B18 = 0;
    D_01B01B20 = 0;
    func_002EF0D0(D_01B01C30, 0, 0x40);
    func_001A1D08(t, func_01B007D0);
    func_001A1D50(t, func_001A2058);
}
