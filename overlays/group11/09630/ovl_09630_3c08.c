#include "common.h"
#include "vu0.h"

extern u8 D_01B0BF48[];
extern u8 *D_01B0C0B0;

extern s32 func_01B076C8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B06018(s32, void *);
extern void func_01B06598(s32, void *, void *);

void func_01B03C08(void) {
    u8 *s0 = D_01B0C0B0;
    u8 *s1 = s0 + 0x260;
    register u8 *s3 __asm__("$19");
    register u8 *s2 __asm__("$18");

    func_01B076C8(D_01B0BF48, s1, 2, 0, 0, 0, 0.2f);
    MMI_COPY_LQ_A3(s0 + 0x330, s0 + 0x990);
    MMI_COPY_SQ_A3(s0 + 0x330);
    *(float *)(s1 + 0xC4) = *(float *)(s0 + 0x85C8);
    *(float *)(s1 + 0xD4) -= 120.0f;
    s3 = s0 + 0x920;
    MMI_COPY_LQ_A3(s3, s0 + 0x990);
    MMI_COPY_SQ_A3(s3);
    *(float *)(s0 + 0x924) -= 100.0f;
    s2 = s0 + 0x890;
    func_01B06018(1, s2);
    MMI_COPY_LQ_A3(s0 + 0x930, s0 + 0x910);
    MMI_COPY_SQ_A3(s0 + 0x930);
    MMI_COPY_LQ_A3(s0 + 0x940, s3);
    MMI_COPY_SQ_A3(s0 + 0x940);
    func_01B06598(1, s2, s0 + 0x930);
    MMI_COPY_LQ_A3(s0 + 0x8C0, s0 + 0x940);
    MMI_COPY_SQ_A3(s0 + 0x8C0);
}
