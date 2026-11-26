#include "iopsound.h"

typedef struct Seq {
    u8 pad000[0x390];
} Seq;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0xE4];
    u32 flags;          /* 0x0E8 */
} Track;

void func_0056FC(Seq *seq, s32 a1, Track *trk) {
    s32 cmd = *trk->ptr++;

    switch (cmd) {
    case 1:
        trk->flags &= ~0x8000;
        break;
    case 2:
        trk->flags &= ~0x10000;
        break;
    case 3:
        trk->flags &= ~0x20000;
        break;
    case 4:
        trk->flags &= ~0x40000;
        break;
    default:
        trk->flags &= ~0x4000;
        break;
    }
}
