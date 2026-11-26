#include "iopsound.h"

typedef struct {
    s32 f00;
    s32 f04;
} S_WaveReq;

extern s32 D_01870C;
extern S_WaveReq D_019358;
extern s32 D_019320;

s32 func_0110AC(s32 *arg) {
    D_01870C = 1;
    D_019358.f00 = arg[0];
    D_019358.f04 = arg[1];
    imp_thsemap_7(D_019320);
    return 0;
}
