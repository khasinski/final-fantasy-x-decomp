#include "iopsound.h"

typedef struct Voice {
    void *trk;          /* 0x00 */
    u8 pad04[0x48];
    u32 unk4c;          /* 0x4c */
    u8 pad50[0x08];
    u32 voice_id;       /* 0x58 */
    u32 voice_bit;      /* 0x5c */
    u8 pad60[0x14];
} Voice; /* size 0x74 = 116 */

extern Voice *D_0192F0;

void func_002BEC(void) {
    u32 koff[2];
    Voice *v = D_0192F0;

    koff[1] = 0;
    koff[0] = 0;
    do {
        if ((v->unk4c & 6) == 2) {
            v->unk4c &= ~2;
            if (v->voice_id & 1) {
                koff[1] |= v->voice_bit;
            } else {
                koff[0] |= v->voice_bit;
            }
        }
        v++;
    } while (v < D_0192F0 + 48);

    if (koff[0] != 0) {
        imp_libsd_7(0x1600, koff[0]);
    }
    if (koff[1] != 0) {
        imp_libsd_7(0x1601, koff[1]);
    }
}
