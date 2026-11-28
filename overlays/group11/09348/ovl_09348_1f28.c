#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B0AB88;
extern u8 *D_01B0AB8C;
extern u8 *D_01B01A64;
extern u8 D_01B0AA88[];
extern u8 D_01B0AAE8[];
extern u8 D_01B0AB48[];
extern u8 D_01B0AB68[];

extern void func_01B07638(void);
extern s32 func_01B09860(void *);
extern void func_01B05430(void *);
extern void func_01B07E60(void);
extern void func_01B02288(void);
extern void func_01B05FD0(void *);

void func_01B01F28(void *a0) {
    u8 *s = D_01B0AB88;
    s32 r;

    func_01B07638();
    D_01B01A64 = D_01B0AB8C;
    r = func_01B09860(D_01B0AA88);
    func_01B09860(D_01B0AAE8);
    if (r == 0) {
        copy_vec(s + 0x1520, s + 0x1560);
        func_01B05430(D_01B0AB48);
        func_01B05430(D_01B0AB68);
        func_01B07E60();
    } else {
        *(s32 *)(s + 0x184C) = 1;
        func_01B02288();
        func_01B05FD0(a0);
    }
}
