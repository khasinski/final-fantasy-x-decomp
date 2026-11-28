#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B010B4;
extern u8 D_01B0A340[];
extern u8 D_01B0A3A0[];
extern u8 D_01B0A400[];
extern u8 D_01B0A420[];
extern u8 D_01B0A440[];
extern u8 D_01B0A460[];
extern u8 *D_01B0A480;
extern u8 *D_01B0A484;

extern void func_01B07458(void);
extern s32 func_01B09680(void *);
extern void func_01B05250(void *);
extern void func_01B07C80(void);
extern void func_01B02160(void);
extern void func_01B05DF0(void *);

void func_01B01DB8(void *a0) {
    u8 *s = D_01B0A480;
    s32 r;

    func_01B07458();
    D_01B010B4 = D_01B0A484;
    r = func_01B09680(D_01B0A340);
    func_01B09680(D_01B0A3A0);
    if (r == 0) {
        copy_vec(s + 0xB00, s + 0xC60);
        copy_vec(s + 0xB40, s + 0xC80);
        copy_vec(s + 0xB80, s + 0xCA0);
        copy_vec(s + 0xBC0, s + 0xCC0);
        func_01B05250(D_01B0A400);
        func_01B05250(D_01B0A420);
        func_01B05250(D_01B0A440);
        func_01B05250(D_01B0A460);
        func_01B07C80();
    } else {
        *(s32 *)(s + 0xEDC) = 1;
        func_01B02160();
        func_01B05DF0(a0);
    }
}
