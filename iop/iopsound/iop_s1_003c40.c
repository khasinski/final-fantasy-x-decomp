#include "iopsound.h"

typedef struct Track Track;

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x24];    /* 0x004 */
    s32 unk028;         /* 0x028 */
    s32 unk02c;         /* 0x02c */
    s32 unk030;         /* 0x030 */
};

extern s32 func_002CC0(s32 *, s32, s32 *);
extern s32 func_006118(void *);

void func_003C40(void *seq, void *q, Track *trk) {
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
    trk->unk02c = func_002CC0(&trk->unk028, val, &cnt);
    trk->unk030 = cnt;
}
