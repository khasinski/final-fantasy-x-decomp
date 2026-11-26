#include "iopsound.h"

typedef struct {
    u32 unk00;
    s32 spu_size;
    u32 unk08;
    u32 unk0C;
    s32 spu_addr;
} BankHdr;

typedef struct {
    s32 idx;
    s32 id;
    s32 lru;
    BankHdr *hdr;
    s32 active;
    s32 spu_addr;
} BankSlot;

extern BankSlot *D_019308;

BankSlot *func_009D50(s32 mode, s32 addr, s32 max_size) {
    BankSlot *p;
    BankSlot *best;
    s32 best_size;

    if (mode == 2) {
        p = D_019308;
        best = p + 128;
        do {
            if (p->active != 0 && p->hdr->spu_size != 0 && p->spu_addr == addr) {
                best = p;
                break;
            }
            p++;
        } while (p < D_019308 + 128);
    } else if (mode == 1) {
        BankSlot *end;
        best_size = 0x200000;
        p = D_019308;
        best = p + 128;
        end = best;
        do {
            if (p->active != 0 && p->spu_addr > addr) {
                s32 sz = p->hdr->spu_size;
                if (sz <= max_size && sz < best_size) {
                    best = p;
                    best_size = sz;
                }
            }
            p++;
        } while (p < end);
    } else {
        BankSlot *end;
        best_size = 0;
        p = D_019308;
        best = p + 128;
        end = best;
        do {
            if (p->active != 0 && p->spu_addr > addr) {
                s32 sz = p->hdr->spu_size;
                if (sz <= max_size && sz > best_size) {
                    best = p;
                    best_size = sz;
                }
            }
            p++;
        } while (p < end);
    }

    return best;
}
