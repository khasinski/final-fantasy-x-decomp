#include "iopsound.h"

typedef struct {
    s32 idx;
    s32 id;
    s32 lru;
    void *hdr;
    s32 active;
    s32 spu_addr;
} BankSlot;

extern BankSlot *D_019308;

extern s32 func_009C14(BankSlot *);
extern s32 func_009BB0(s32);

s32 func_00B4A8(s32 arg0) {
    BankSlot *p;

    if (arg0 < 0) {
        if (arg0 == -1) {
            p = D_019308 + 16;
            while (p < D_019308 + 128) {
                if (p->id >= 0) {
                    func_009C14(p);
                }
                p++;
            }
        } else if (arg0 == -2) {
            p = D_019308 + 16;
            while (p < D_019308 + 128) {
                if (p->id >= 0 && p->lru > 0) {
                    func_009C14(p);
                }
                p++;
            }
        }
    } else {
        arg0 = func_009BB0(arg0);
        if (arg0 >= 0) {
            func_009C14(&D_019308[arg0]);
        }
    }

    return arg0;
}
