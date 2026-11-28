#include "common.h"

extern s32 fn_01b08bb8(s32);
extern void fn_00110300(s32, float);

void ovl_09478_01b08cd0(s32 a0, float f12) {
    fn_00110300(fn_01b08bb8(a0), f12);
}

void ovl_09478_01b08d00(s32 a0, float f12) {
    f12 = 4.7123889923095703f - f12;
    if (f12 > 3.1415927410125732f) {
        f12 -= 6.2831854820251465f;
    } else if (f12 < -3.1415927410125732f) {
        f12 += 6.2831854820251465f;
    }
    ovl_09478_01b08cd0(a0, f12);
}
