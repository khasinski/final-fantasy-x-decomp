#include "iopsound.h"

typedef struct {
    u32 src;
    u32 dst;
    s32 remain;
    s32 state;
} S_Defrag;

extern u8 *D_018FB4;
extern u32 D_019394;

extern void func_00FC2C(s32, s32, void *, u32, s32);
extern void func_00FDF4(s32, void *, void *);

s32 func_014CC8(s32 ch, S_Defrag *df) {
    switch (--df->state) {
        case 0: {
            s32 half;
            df->state = 4;
            if (df->remain > 0x8000) {
                half = 0x8000;
            } else {
                half = df->remain;
            }
            half >>= 1;
            func_00FC2C(0, 0, D_018FB4 + 0x8000, df->dst, half);
            func_00FC2C(1, 0, D_018FB4 + 0x8000 + half, df->dst + half, half);
            break;
        }
        case 2:
            df->src += 0x8000;
            df->dst += 0x8000;
            df->remain -= 0x8000;
            if (df->remain > 0) {
                if (df->remain <= 0x7fff && (df->remain & 0x7f) != 0) {
                    s32 pad = 0x80 - (df->remain & 0x7f);
                    df->src -= pad;
                    df->dst -= pad;
                    df->remain += pad;
                }
                func_00FC2C(0, 1, D_018FB4 + 0x8000, df->src, 0x4000);
                func_00FC2C(1, 1, D_018FB4 + 0xc000, df->src + 0x4000, 0x4000);
            } else {
                func_00FDF4(0, 0, 0);
                func_00FDF4(1, 0, 0);
                D_019394 &= ~0x10000;
            }
            break;
    }

    return ch;
}
