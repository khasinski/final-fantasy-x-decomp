#include "iopsound.h"

typedef struct {
    s32 vol;
    s32 step;
    s32 cnt;
} MasterVol;

extern MasterVol D_06D2A0;
extern s32 D_018F90;

void func_00EE60(void) {
    MasterVol *p = &D_06D2A0;

    p->cnt--;
    p->vol += p->step;
    if (D_018F90 != 0) {
        s32 vol = p->vol >> 12;
        imp_libsd_5(0x0f81, (u16)vol);
        imp_libsd_5(0x1081, (u16)vol);
    }
}

s32 func_00EECC(s32 vol) {
    if (vol != 0) {
        vol++;
        vol <<= 8;
        vol--;
    }
    D_06D2A0.vol = vol << 12;
    D_06D2A0.cnt = 0;
    if (D_018F90 != 0) {
        u16 v = (u16)vol;
        imp_libsd_5(0x0f81, v);
        imp_libsd_5(0x1081, v);
    }
    return vol;
}

s32 func_00EF44(s32 time, s32 vol) {
    if (vol != 0) {
        vol++;
        vol <<= 8;
        vol--;
        vol <<= 12;
    }
    vol |= 0x800;
    vol -= D_06D2A0.vol;
    D_06D2A0.step = vol / time;
    D_06D2A0.cnt = time;
    return vol;
}
