#include "rcef_overlay.h"

extern float D_01B01AA0[3];
extern float D_01B01AAC;
extern float D_01B01AB0;
extern int D_01B01AB4;
extern int D_01B01AB8;
extern int D_01B01ABC;
extern float D_01B01AC0;
extern int D_01B01AC4;
extern float D_01B01AD0[16][4];
extern int D_01B01BD0[16];

extern void func_01B007C0(W3Task *);

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

    func_001A2698(0x48, 0, 6, 1);
    max_ang = 0.0f;
    D_01B01AC4 = D_00313CB0.target_count;
    D_01B01AAC = max_ang;
    base_ang = func_001A2A28();
    v0[0] = max_ang;
    v0[1] = max_ang;
    v0[2] = max_ang;
    v0[3] = max_ang;
    func_001A2F50(D_00313CB0.caster, 0x48, v0, v1);
    for (i = 0; i < D_01B01AC4; i++) {
        float dist;
        float ang;
        dist = func_001A2A08(i) + 20.0f;
        if (D_01B01AAC < dist) {
            D_01B01AAC = dist;
            D_01B01AB8 = (int)(dist / 3.0f);
            D_01B01AB0 = func_001A2A58(i);
        }
        {
            /* DEBT(FAKE): match mov.s $f1,$f0 copy after func_001A3360 */
            register float ang_r __asm__("$f1") = func_001A3360(func_001A2A38(i), base_ang);
            __asm__("" : "+f"(ang_r));
            if (max_ang < ang_r) {
                max_ang = ang_r;
            }
        }
        func_001A3040(D_00313CB0.targets[i], 0, D_01B01AD0[i]);
    }
    if (max_ang < 0.436332315f) {
        max_ang = 0.436332315f;
    }
    D_01B01AA0[0] = base_ang;
    D_01B01AA0[1] = base_ang + max_ang;
    D_01B01AA0[2] = base_ang - max_ang;
    D_01B01AC0 = 1.0f;
    D_01B01AB4 = 0;
    D_01B01ABC = 0;
    func_002EF0D0(D_01B01BD0, 0, 0x40);
    func_001A1D08(t, func_01B007C0);
    func_001A1D50(t, func_001A2058);
}
