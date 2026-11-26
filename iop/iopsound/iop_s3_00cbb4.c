#include "iopsound.h"

typedef struct {
    u8 pad00[0x26];
    u8 unk26;
    u8 pad27[0x110];
    u8 unk137;
    u8 pad138[4];
} Track;

typedef struct {
    void *track;
    u8 pad04[0x12];
    u8 unk16;
    u8 pad17[0x35];
    u32 unk4C;
    u8 pad50[0x10];
    u32 unk60;
    u8 pad64[0x10];
} Voice;

typedef struct {
    Track *track;
} StreamCtrl;

typedef struct {
    u8 pad00[0x720];
    Track *tracks;
} TrackPool;

extern Voice *D_0192F0;
extern TrackPool *D_019374;

extern Track *func_0071C8(s32, s32, s32);

s32 func_00CBB4(StreamCtrl *sc, s32 count) {
    Track *tr = func_0071C8(count, 255, 0);

    if (tr != NULL) {
        Voice *v;
        sc->track = tr;
        v = &D_0192F0[tr->unk137];
        v->track = NULL;
        v->unk16 = 2;
        tr->unk26 |= 2;
        v->unk4C &= ~13;
        v->unk60 = (v->unk60 & ~0x1F0000) | 4;
        if (count >= 2) {
            v++;
            v->track = NULL;
            v->unk16 = 2;
            tr[1].unk26 |= 2;
            v->unk4C &= ~13;
            v->unk60 = (v->unk60 & ~0x1F0000) | 4;
        }
        return tr - D_019374->tracks;
    }

    return -1;
}
