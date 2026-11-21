/* Shared debug pad transform controller (Sub-family A: 9541, 9685, 9710, 9713).
 * .text in 9541: 0x01B01448..0x01B01958 (1 function, .rodata at 0x01B02408).
 */
#include "common.h"

extern u8 D_006A3970[];
extern u16 D_01B005C0;
extern u16 D_01B005C2;
extern u16 D_01B005C4;
extern u8 D_01B005C6;
extern char D_01B02390[];
extern char D_01B023A0[];
extern char D_01B023B0[];
extern char D_01B023C0[];
extern char D_01B023D8[];
extern char D_01B023F0[];

extern u16 func_002D28E8(int, int, int);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCF48(float *, void *);
extern void func_002EF240(const char *, ...);

void func_01B01448(float *pos, s32 *rot, float *scale)
{
    float dpos[4] __attribute__((aligned(16)));
    s32 drot[4] __attribute__((aligned(16)));
    float dscale[4] __attribute__((aligned(16)));
    float inv_mtx[16];
    float speed;

    D_01B005C0 = func_002D28E8(1, 0, 0);
    speed = 1.0f;
    {
        /* DEBT(FAKE): pin mask to $a0 so ee-gcc reloads lui $v0 for D_01B005C2 store */
        u16 t = D_01B005C2 & D_01B005C0;
        register int mask __asm__("$4");
        D_01B005C2 = t;
        D_01B005C4 = t;
        mask = t & 0x40;
        if (mask) {
            D_01B005C6++;
            if (D_01B005C6 >= 3) {
                D_01B005C6 = 0;
            }
            if (D_01B005C6 == 0) {
                func_002EF240(D_01B02390);
            } else if (D_01B005C6 == 1) {
                func_002EF240(D_01B023A0);
            } else if (D_01B005C6 == 2) {
                func_002EF240(D_01B023B0);
            }
        }
    }
    if (D_01B005C4 & 0x10) {
        if (pos != 0) {
            func_002EF240(D_01B023C0, pos[0], pos[1], pos[2], pos[3]);
        }
        if (rot != 0) {
            func_002EF240(D_01B023D8, rot[0], rot[1], rot[2], rot[3]);
        }
        if (scale != 0) {
            func_002EF240(D_01B023F0, scale[0], scale[1], scale[2], scale[3]);
        }
    }
    if (D_01B005C0 & 0x8) {
        speed /= 10.0f;
    }
    if (D_01B005C6 < 2) {
        if (D_01B005C4 & 0x4) {
            if (pos != 0) {
                pos[0] = pos[1] = pos[2] = 0.0f;
            }
            if (rot != 0) {
                rot[2] = 0;
                rot[1] = 0;
                rot[0] = 0;
            }
        }
        if (rot != 0 && (D_01B005C0 & 0x80)) {
            *(u_long128 *)drot = 0;
            if (D_01B005C0 & 0x8000) {
                drot[1] = (s32)((float)drot[1] - speed * 32768.0f * 0.015625f);
            } else if (D_01B005C0 & 0x2000) {
                drot[1] = (s32)((float)drot[1] + speed * 32768.0f * 0.015625f);
            }
            if (rot != 0) {
                rot[1] += drot[1];
            }
            *(u_long128 *)dscale = 0;
            if (D_01B005C0 & 0x1000) {
                dscale[1] = (float)((double)dscale[1] + (double)speed * 0.001);
            } else if (D_01B005C0 & 0x4000) {
                dscale[1] = (float)((double)dscale[1] - (double)speed * 0.001);
            }
            if (scale != 0) {
                scale[0] += dscale[1];
                scale[1] += dscale[1];
                scale[2] += dscale[1];
            }
        } else {
            *(u_long128 *)dpos = 0;
            if (D_01B005C0 & 0x8000) {
                dpos[0] -= speed;
            } else if (D_01B005C0 & 0x2000) {
                dpos[0] += speed;
            }
            if (D_01B005C0 & 0x20) {
                if (D_01B005C0 & 0x1000) {
                    dpos[1] -= speed;
                } else if (D_01B005C0 & 0x4000) {
                    dpos[1] += speed;
                }
            } else {
                if (D_01B005C0 & 0x1000) {
                    dpos[2] += speed;
                } else if (D_01B005C0 & 0x4000) {
                    dpos[2] -= speed;
                }
            }
            if (dpos[0] != 0.0f || dpos[1] != 0.0f || dpos[2] != 0.0f) {
                if (D_01B005C6 != 0) {
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
    D_01B005C2 = ~D_01B005C0;
}
