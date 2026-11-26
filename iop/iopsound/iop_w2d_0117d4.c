#include "iopsound.h"

typedef struct {
    s32 f00;
    u8 pad04[0xe4];
    u32 f0e8;
    u8 padec[0x50];
} S_Voice; /* size 0x13c = 316 */

typedef struct {
    S_Voice *voices;
    u8 pad04[0x386];
    s16 f38a;
    u8 pad38c;
    u8 count;
    u8 pad38e[2];
} S_TrackGroup; /* size 0x390 = 912 */

typedef struct {
    S_Voice *voice;
    u8 pad04[0x48];
    u32 f4c;
    u8 pad50[0x24];
} S_HwVoice; /* size 0x74 = 116 */

typedef struct {
    u32 f00;
    u32 f04;
} S_Mask;

extern S_TrackGroup *D_01936C;
extern S_Mask D_018740;
extern S_HwVoice *D_0192F0;
extern u32 D_01931C[];

s32 func_0117D4(u32 *arg) {
    u32 mask;
    S_TrackGroup *grp;
    s32 flag;
    S_Voice *v;
    u32 bit;
    u32 n;

    mask = arg[0];
    D_018740.f00 = mask;
    D_018740.f04 = arg[1];
    if (D_01936C->f38a != 0) {
        u32 m;
        grp = D_01936C;
        bit = 0;
        v = grp->voices + 1;
        n = grp->count < 32 ? grp->count : 32;
        m = mask;
        while (v < grp->voices + n) {
            if (v->f00 != 0) {
                S_HwVoice *hw;
                if (m & (1 << bit)) {
                    flag = 1;
                    v->f0e8 |= 0x20;
                } else {
                    flag = 0;
                    v->f0e8 &= ~0x20;
                }
                hw = D_0192F0;
                do {
                    if (hw->voice == v) {
                        if (flag) {
                            hw->f4c |= 0x20;
                        } else {
                            hw->f4c &= ~0x20;
                        }
                    }
                    hw++;
                } while (hw < D_0192F0 + 48);
            }
            bit++;
            v++;
        }

        bit = 0;
        m = D_018740.f04;
        while (v < grp->voices + grp->count) {
            if (v->f00 != 0) {
                S_HwVoice *hw;
                if (m & (1 << bit)) {
                    flag = 1;
                    v->f0e8 |= 0x20;
                } else {
                    flag = 0;
                    v->f0e8 &= ~0x20;
                }
                hw = D_0192F0;
                do {
                    if (hw->voice == v) {
                        if (flag) {
                            hw->f4c |= 0x20;
                        } else {
                            hw->f4c &= ~0x20;
                        }
                    }
                    hw++;
                } while (hw < D_0192F0 + 48);
            }
            bit++;
            v++;
        }

        D_01931C[0] |= 1;
    }
    return 0;
}
