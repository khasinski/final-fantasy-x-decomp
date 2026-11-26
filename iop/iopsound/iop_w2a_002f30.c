#include "iopsound.h"

typedef struct Track {
    u8 pad000[0xe8];
    u32 unk0e8;         /* 0x0e8 */
} Track;

typedef struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x48];
    u32 unk4c;          /* 0x4c */
    u8 pad50[0x24];
} Voice; /* size 0x74 = 116 */

typedef struct {
    u32 flags;
} DriverState;

extern Voice *D_0192F0;
extern DriverState D_01931C;

void func_002F30(Track *trk) {
    Voice *v = D_0192F0;
    u32 mask = trk->unk0e8 & ~3;

    do {
        if (v->trk == trk) {
            v->unk4c = (v->unk4c & 3) | mask;
            D_01931C.flags |= 1;
        }
        v++;
    } while (v < D_0192F0 + 48);
}
