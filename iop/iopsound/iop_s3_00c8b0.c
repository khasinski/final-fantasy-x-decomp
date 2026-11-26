#include "iopsound.h"

typedef struct {
    u8 pad00[0x1C];
    u32 voice_mask;
    u8 pad20[0x50];
} StreamCtrl;

extern StreamCtrl *D_018754;

extern void func_00EFBC(s32, u32);

void func_00C8B0(void) {
    func_00EFBC(6, D_018754[1].voice_mask);
}

void func_00C8DC(void) {
    func_00EFBC(5, D_018754[0].voice_mask);
}

u32 func_00C908(void) {
    return D_018754[1].voice_mask;
}

u32 func_00C920(void) {
    return D_018754[0].voice_mask;
}
