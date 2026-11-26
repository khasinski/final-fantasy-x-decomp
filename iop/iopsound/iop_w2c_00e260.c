#include "iopsound.h"

typedef struct {
    u8 pad00[0x50];
    s32 f50;
    s32 f54;
    s32 f58;
    u8 pad5C[0x70 - 0x5C];
} StreamCh;

extern StreamCh *D_018754;
extern void func_00E0A4(StreamCh *);

void func_00E260(s32 vol) {
    StreamCh *s = D_018754 + 1;

    if (vol != 0) {
        vol++;
        vol <<= 7;
        vol--;
        vol <<= 12;
    }
    s->f50 = vol;
    s->f58 = 0;
    func_00E0A4(s);
}

void func_00E2A8(s32 time, s32 vol) {
    StreamCh *s = D_018754 + 1;

    if (vol != 0) {
        vol++;
        vol <<= 7;
        vol--;
        vol <<= 12;
    }
    vol |= 0x800;
    vol -= s->f50;
    vol /= time;
    s->f58 = time;
    s->f54 = vol;
}
