#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 *D_01B09358;
extern u8 *D_01B0935C;
extern u8 *D_01B00B04;
extern u8 D_01B092D8[];
extern u8 D_01B09338[];

extern void func_01B068D0(void);
extern s32 func_01B08AF8(void *);
extern s32 func_01B046C8(void *);
extern void func_01B01150(void);
extern void func_01B05268(void *);

void func_01B00FC8(void *a0) {
    u8 *s = D_01B09358;
    s32 r1;
    s32 r2;

    func_01B068D0();
    D_01B00B04 = D_01B0935C;
    r1 = func_01B08AF8(D_01B092D8);
    r2 = func_01B046C8(D_01B09338);
    if (r1 != 0 && r2 != 0) {
        *(s32 *)(s + 0x54C8) = 1;
        func_01B01150();
        func_01B05268(a0);
    } else {
        copy_vec(s + 0xD40, s + 0xF60);
    }
}
