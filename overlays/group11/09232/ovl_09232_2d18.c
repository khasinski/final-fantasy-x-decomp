#include "common.h"

extern u8 D_006A3970[];
extern u16 D_01B00BF0;
extern u16 D_01B00BF2;
extern u16 D_01B00BF4;
extern u8 D_01B00BF6;

extern u16 func_002D28E8(int, int, int);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCF48(float *, void *);

void func_01B02D18(float *pos, s32 *rot, float *scale)
{
    float dpos[4] __attribute__((aligned(16)));
    s32 drot[4] __attribute__((aligned(16)));
    float dscale[4] __attribute__((aligned(16)));
    float inv_mtx[16];
    float speed = 1.0f;

    D_01B00BF0 = func_002D28E8(1, 0, 0);
    D_01B00BF2 &= D_01B00BF0;
    D_01B00BF4 = D_01B00BF2;
    if (D_01B00BF4 & 0x40) {
        D_01B00BF6++;
        if (D_01B00BF6 >= 3) {
            D_01B00BF6 = 0;
        }
    }
    if (D_01B00BF0 & 0x8) {
        speed = 0.100000002f;
    }
    {
        u16 trig = D_01B00BF4;
        __asm__("" : "+r"(trig) : : "memory");
        if (D_01B00BF6 < 2) {
            if (trig & 0x4) {
            if (pos != 0) {
                float z = 0.0f;
                pos[2] = z;
                pos[1] = z;
                pos[0] = z;
            }
            if (rot != 0) {
                rot[2] = 0;
                rot[1] = 0;
                rot[0] = 0;
            }
        }
        if (rot != 0 && (D_01B00BF0 & 0x80)) {
            *(u_long128 *)drot = 0;
            if (D_01B00BF0 & 0x8000) {
                drot[1] = (s32)((float)drot[1] - speed * 32768.0f * 0.015625f);
            } else if (D_01B00BF0 & 0x2000) {
                drot[1] = (s32)((float)drot[1] + speed * 32768.0f * 0.015625f);
            }
            if (rot != 0) {
                rot[1] += drot[1];
            }
            *(u_long128 *)dscale = 0;
            if (D_01B00BF0 & 0x1000) {
                dscale[1] = (float)((double)dscale[1] + (double)speed * 0.0010000000000000002);
            } else if (D_01B00BF0 & 0x4000) {
                dscale[1] = (float)((double)dscale[1] - (double)speed * 0.0010000000000000002);
            }
            if (scale != 0) {
                scale[0] += dscale[1];
                scale[1] += dscale[1];
                scale[2] += dscale[1];
            }
        } else {
            *(u_long128 *)dpos = 0;
            if (D_01B00BF0 & 0x8000) {
                dpos[0] -= speed;
            } else if (D_01B00BF0 & 0x2000) {
                dpos[0] += speed;
            }
            if (D_01B00BF0 & 0x20) {
                if (D_01B00BF0 & 0x1000) {
                    dpos[1] -= speed;
                } else if (D_01B00BF0 & 0x4000) {
                    dpos[1] += speed;
                }
            } else {
                if (D_01B00BF0 & 0x1000) {
                    dpos[2] += speed;
                } else if (D_01B00BF0 & 0x4000) {
                    dpos[2] -= speed;
                }
            }
            if (dpos[0] != 0.0f || dpos[1] != 0.0f || dpos[2] != 0.0f) {
                if (D_01B00BF6 != 0) {
                    dpos[3] = 0.0f;
                    func_002DCF48(inv_mtx, D_006A3970);
                    func_002DCE08(dpos, inv_mtx, dpos);
                }
                if (pos != 0) {
                    pos[0] += dpos[0];
                    pos[1] += dpos[1];
                    pos[2] += dpos[2];
                }
            }
        }
        }
    }
    D_01B00BF2 = ~D_01B00BF0;
}
