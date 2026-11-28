#include "common.h"
#include "vu0.h"

extern s32 D_01B00D54;
extern u8 D_01B0BF90[];
extern u8 D_01B0BFF0[];
extern u8 D_01B0C050[];
extern u8 D_01B0C070[];
extern u8 D_01B0C090[];
extern u8 *D_01B0C0B0;
extern s32 D_01B0C0B4;

extern void func_01B08A50(void);
extern s32 func_01B0AC78(void *);
extern void func_01B06848(void *);
extern void func_01B09278(void);
extern void func_01B0B2D0(void *, s32, s32, float, float);
extern void func_01B03908(void);
extern void func_01B073E8(void *);

void func_01B034A0(void *s2) {
    u8 *s1 = D_01B0C0B0;
    s32 s0;

    func_01B08A50();
    D_01B00D54 = D_01B0C0B4;
    s0 = func_01B0AC78(D_01B0BF90);
    func_01B0AC78(D_01B0BFF0);
    if (s0 == 0) {
        MMI_COPY_LQ_A3(s1 + 0x880, s1 + 0x920);
        MMI_COPY_SQ_A3(s1 + 0x880);
        MMI_COPY_LQ_A3(s1 + 0x8C0, s1 + 0x940);
        MMI_COPY_SQ_A3(s1 + 0x8C0);
        MMI_COPY_LQ_A3(s1 + 0x900, s1 + 0x960);
        MMI_COPY_SQ_A3(s1 + 0x900);
        func_01B06848(D_01B0C050);
        func_01B06848(D_01B0C070);
        func_01B06848(D_01B0C090);
        func_01B09278();
    } else {
        func_01B0B2D0(s1 + 0x8410, 1, 0, 0.5f, 1.0f);
        *(s32 *)(s1 + 0x85EC) = 1;
        func_01B03908();
        func_01B073E8(s2);
    }
}
