#include "iopsound.h"

typedef struct Track Track;

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x30];    /* 0x004 */
    s32 unk034;         /* 0x034 */
    s32 unk038;         /* 0x038 */
    s32 unk03c;         /* 0x03c */
};

extern s32 func_002CC0(s32 *, s32, s32 *);
extern s32 func_006118(void *);

void func_003D00(void *seq, void *q, Track *trk) {
    s32 cnt;
    s32 val;

    cnt = func_006118(trk);
    if (cnt == 0) {
        cnt = 1;
    }
    val = ((s8)*trk->ptr++) << 7;
    if (val > 0) {
        val += 127;
    }
    trk->unk038 = func_002CC0(&trk->unk034, val, &cnt);
    trk->unk03c = cnt;
}
