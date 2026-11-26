#include "iopsound.h"

typedef struct {
    u8 pad00[0x18];
    u32 flags;
    u8 pad1C[0x1C];
    u32 unk38;
    u8 pad3C[0x10];
    u32 unk4C;
} StreamCtrl;

u32 func_00CFB4(StreamCtrl *sc, u32 *p) {
    u32 step = 1;

    if (sc->flags & 1) {
        step = 2;
    }
    sc->unk38 += step;
    *p += step;
    if (*p > sc->unk4C - 1) {
        *p = 0;
    }
    return *p;
}
