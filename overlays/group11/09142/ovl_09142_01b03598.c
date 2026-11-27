/* Debug controller transform editor for 09142 (0x01B03598..0x01B03AC8) and 09395 (0x01B048A0..0x01B04DD0). */
#include "common.h"

extern u16 D_01B00F10;
extern u16 D_01B00F12;
extern u16 D_01B00F14;
extern u8 D_01B00F16;
extern char D_01B04720[];
extern char D_01B04730[];
extern char D_01B04740[];
extern char D_01B04750[];
extern char D_01B04768[];
extern char D_01B04780[];
extern u8 D_006A3970[];

extern u16 TkGetControlerHist(int, int, int);
extern void func_002EF240(const char *, ...);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);

typedef unsigned int u_long128 __attribute__((mode(TI)));

void func_01B03598(float *pos, int *rot, float *scale)
{
    float dp[4] __attribute__((aligned(16)));
    int dr[4] __attribute__((aligned(16)));
    float ds[4] __attribute__((aligned(16)));
    float mtx[16];
    float step = 1.0f;

    D_01B00F10 = TkGetControlerHist(1, 0, 0);
    D_01B00F12 &= D_01B00F10;
    D_01B00F14 = D_01B00F12;

    if (D_01B00F14 & 0x40) {
        D_01B00F16++;
        if (D_01B00F16 >= 3) {
            D_01B00F16 = 0;
        }
        if (D_01B00F16 == 0) {
            func_002EF240(D_01B04720);
        } else if (D_01B00F16 == 1) {
            func_002EF240(D_01B04730);
        } else if (D_01B00F16 == 2) {
            func_002EF240(D_01B04740);
        }
    }

    if (D_01B00F14 & 0x10) {
        if (pos != 0) {
            func_002EF240(D_01B04750, (double)pos[0], (double)pos[1], (double)pos[2], (double)pos[3]);
        }
        if (rot != 0) {
            func_002EF240(D_01B04768, rot[0], rot[1], rot[2], rot[3]);
        }
        if (scale != 0) {
            func_002EF240(D_01B04780, (double)scale[0], (double)scale[1], (double)scale[2], (double)scale[3]);
        }
    }

    if (D_01B00F10 & 8) {
        step = 0.100000002f;
    }

    if (D_01B00F16 < 2) {
        if (D_01B00F14 & 4) {
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

        if (rot != 0 && (D_01B00F10 & 0x80)) {
            *(u_long128 *)dr = 0;
            if (D_01B00F10 & 0x8000) {
                dr[1] = (int)((float)dr[1] - step * 32768.0f * 0.015625f);
            } else if (D_01B00F10 & 0x2000) {
                dr[1] = (int)((float)dr[1] + step * 32768.0f * 0.015625f);
            }
            if (rot != 0) {
                rot[1] += dr[1];
            }

            *(u_long128 *)ds = 0;
            if (D_01B00F10 & 0x1000) {
                ds[1] = (float)((double)ds[1] + (double)step * 0.0010000000000000002);
            } else if (D_01B00F10 & 0x4000) {
                ds[1] = (float)((double)ds[1] - (double)step * 0.0010000000000000002);
            }
            if (scale != 0) {
                scale[0] += ds[1];
                scale[1] += ds[1];
                scale[2] += ds[1];
            }
        } else {
            *(u_long128 *)dp = 0;
            if (D_01B00F10 & 0x8000) {
                dp[0] -= step;
            } else if (D_01B00F10 & 0x2000) {
                dp[0] += step;
            }
            if (D_01B00F10 & 0x20) {
                if (D_01B00F10 & 0x1000) {
                    dp[1] -= step;
                } else if (D_01B00F10 & 0x4000) {
                    dp[1] += step;
                }
            } else {
                if (D_01B00F10 & 0x1000) {
                    dp[2] += step;
                } else if (D_01B00F10 & 0x4000) {
                    dp[2] -= step;
                }
            }
            if (dp[0] != 0.0f || dp[1] != 0.0f || dp[2] != 0.0f) {
                if (D_01B00F16 != 0) {
                    dp[3] = 0.0f;
                    func_002DCF48(mtx, D_006A3970);
                    func_002DCE08(dp, mtx, dp);
                }
                if (pos != 0) {
                    pos[0] += dp[0];
                    pos[1] += dp[1];
                    pos[2] += dp[2];
                }
            }
        }
    }

    D_01B00F12 = ~D_01B00F10;
}
