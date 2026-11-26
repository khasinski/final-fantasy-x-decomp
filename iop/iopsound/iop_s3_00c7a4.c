#include "iopsound.h"

typedef struct {
    s32 idx;
    s32 id;
    s32 lru;
    void *hdr;
    s32 size;
    s32 unk14;
} BgmSlot;

typedef struct {
    u8 pad00[0x374];
    s32 bgm_id;
    u8 pad378[0x18];
} SeqCtrl;

extern SeqCtrl *D_01936C;
extern BgmSlot *D_019338;

extern s32 func_00C054(s32);
extern s32 func_00C0AC(BgmSlot *);

s32 func_00C7A4(s32 id) {
    SeqCtrl *sc = D_01936C;
    BgmSlot *p;
    s32 ret;

    if (id == -1) {
        p = D_019338;
        ret = 2;
        do {
            if (p->size != 0 && p->id != sc[0].bgm_id && p->id != sc[1].bgm_id) {
                func_00C0AC(p);
            }
            p++;
            ret--;
        } while (ret != 0);
    } else {
        ret = func_00C054(id);
        if (ret >= 0 && id != sc[0].bgm_id && id != sc[1].bgm_id) {
            ret = func_00C0AC(&D_019338[ret]);
        }
    }

    return ret;
}
