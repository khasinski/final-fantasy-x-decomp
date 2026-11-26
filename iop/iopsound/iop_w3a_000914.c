#include "iopsound.h"

typedef struct Seq {
    u8 pad000[0x1C];
    s32 unk01C;
    s32 unk020;
    s32 unk024;
    u8 pad028[0x34C];
    s32 unk374;
    u8 pad378[0x18];
} Seq; /* size 0x390 = 912 */

extern Seq *D_01936C;
extern u32 *D_0192FC;
extern u32 *D_019314;
extern volatile s32 D_01874C;
extern u32 D_01931C[];
extern s32 D_018724;

extern void func_009360(Seq *, Seq *, s32);

void func_000914(void) {
    Seq *seq = D_01936C;
    s32 oldstat;
    s32 intr;
    u32 *src;
    volatile u32 *dst;

    if (seq->unk374 < 0) {
        return;
    }

    intr = imp_intrman_17(&oldstat);

    src = D_0192FC;
    dst = D_019314;
    do {
        if (src[0] != 0 && dst[0] == 0) {
            dst[0] = src[0];
            dst[1] = src[1];
            D_01874C++;
        }
        src += 2;
        dst += 2;
    } while (src < D_0192FC + 96);

    src = D_0192FC + 96;
    dst = D_019314 + 96;
    while (dst < D_019314 + 192) {
        if (dst[0] == 0) {
            break;
        }
        dst += 2;
    }
    while (dst < D_019314 + 192 && src < D_0192FC + 192) {
        if (src[0] != 0) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst += 2;
            D_01874C++;
        }
        src += 2;
    }

    src = D_0192FC + 192;
    dst = D_019314 + 192;
    while (dst < D_019314 + 288) {
        if (dst[0] == 0) {
            break;
        }
        dst += 2;
    }
    while (dst < D_019314 + 288 && src < D_0192FC + 288) {
        if (src[0] != 0) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst += 2;
            D_01874C++;
        }
        src += 2;
    }

    seq[3].unk374 = seq[0].unk374;
    seq[3].unk01C = seq[0].unk01C;
    seq[3].unk020 = seq[0].unk020;
    seq[3].unk024 = seq[0].unk024;
    func_009360(&D_01936C[3], D_01936C, sizeof(Seq));

    D_01931C[0] |= 7;
    D_018724++;

    if (intr == 0) {
        imp_intrman_18(oldstat);
    }
}
