#include "iopsound.h"

typedef struct {
    s32 addr;
    s32 size;
} MemBlock;

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
extern MemBlock *D_019334;

extern BankSlot *func_009D50(s32, s32, s32);
extern void func_009D04(BankSlot *, s32);
extern s32 func_015008(s32, s32);

s32 func_009EDC(void) {
    MemBlock *p = D_019334;
    s32 cur = 0;
    s32 max_gap;

    do {
        s32 gap = p->addr - cur;
        while (gap == 0 && p->size != 0) {
            cur = p->addr + p->size;
            p++;
            if (p->size != 0) {
                gap = p->addr - cur;
            }
        }
        if (gap != 0) {
            BankSlot *b = func_009D50(0, cur, gap);
            if (b < D_019308 + 128) {
                func_009D04(b, cur);
            }
        }
        cur = p->addr + p->size;
        p++;
    } while (p->size != 0);

    p = D_019334;
    max_gap = 0;
    if (p->size != 0) {
        MemBlock *end = p + 128;
        do {
            s32 gap;
            if (p >= end) {
                break;
            }
            cur = p->addr + p->size;
            if (p[1].size != 0) {
                gap = p[1].addr - cur;
            } else {
                gap = 0x200000 - cur;
            }
            if (gap > max_gap) {
                max_gap = gap;
            }
            p++;
        } while (p->size != 0);
    }

    return max_gap;
}

s32 func_00A038(void) {
    s32 cur = 0;
    MemBlock *p = D_019334;
    s32 max_gap;

    do {
        s32 gap = p->addr - cur;
        while (gap == 0 && p->size != 0) {
            cur = p->addr + p->size;
            p++;
            if (p->size != 0) {
                gap = p->addr - cur;
            }
        }
        if (gap != 0 && p->size != 0 && p->addr > 0x21FFF) {
            BankSlot *b = func_009D50(2, p->addr, 0);
            if (b < D_019308 + 128) {
                if (func_015008(b->spu_addr, b->spu_addr + b->hdr->spu_size) == 0) {
                    func_009D04(b, cur);
                }
            }
        }
        cur = p->addr + p->size;
        p++;
    } while (p->size != 0);

    p = D_019334;
    max_gap = 0;
    if (p->size != 0) {
        MemBlock *end = p + 128;
        do {
            s32 gap;
            if (p >= end) {
                break;
            }
            cur = p->addr + p->size;
            if (p[1].size != 0) {
                gap = p[1].addr - cur;
            } else {
                gap = 0x200000 - cur;
            }
            if (gap > max_gap) {
                max_gap = gap;
            }
            p++;
        } while (p->size != 0);
    }

    return max_gap;
}
