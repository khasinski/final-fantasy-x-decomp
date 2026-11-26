#include "iopsound.h"

typedef struct {
    s32 addr;
    s32 size;
} MemBlock;

extern MemBlock *D_019334;

extern void *func_009D50(s32, s32, s32);
extern void func_009D04(void *, s32);

s32 func_00A200(s32 target_size) {
    MemBlock *p;
    MemBlock *best;
    s32 gap_addr;
    s32 gap_size;
    s32 max_gap;
    s32 sz;

    p = D_019334;
    while (p[1].size != 0) {
        p++;
    }

    if (p->size != 0 && p->addr > 0x22000) {
        p--;
        while (1) {
            gap_addr = p->addr + p->size;
            gap_size = p[1].addr - gap_addr;
            p--;
            if (gap_size != 0) {
                break;
            }
            if (p->addr <= 0x22000) {
                goto calc_max;
            }
        }

        if (p->addr >= 0x22000) {
            max_gap = 0;
            best = NULL;
            do {
                sz = p[1].addr - (p->addr + p->size);
                if (sz > max_gap) {
                    max_gap = sz;
                    best = p;
                }
                p--;
            } while (p->addr >= 0x22000);

            if (best != NULL && gap_size != 0) {
                MemBlock *best1 = best + 1;
loop_move:
                if (best->addr >= 0x22000) {
                    s32 cur_sz = best1[-1].size;
                    s32 nxt_sz = best1->size;
                    if (cur_sz < nxt_sz) {
                        if (gap_size >= nxt_sz) {
                            sz = nxt_sz;
                            func_009D04(func_009D50(2, best1->addr, 0), gap_addr);
                            gap_size -= sz;
                            gap_addr += sz;
                        } else if (gap_size >= cur_sz) {
                            sz = cur_sz;
                            func_009D04(func_009D50(2, best->addr, 0), gap_addr);
                            gap_addr += sz;
                            gap_size -= sz;
                            best1--;
                            best--;
                        } else {
                            goto calc_max;
                        }
                    } else if (gap_size >= cur_sz) {
                        sz = cur_sz;
                        func_009D04(func_009D50(2, best->addr, 0), gap_addr);
                        gap_addr += sz;
                        gap_size -= sz;
                        best1--;
                        best--;
                    } else if (gap_size >= nxt_sz) {
                        sz = nxt_sz;
                        func_009D04(func_009D50(2, best1->addr, 0), gap_addr);
                        gap_size -= sz;
                        gap_addr += sz;
                    } else {
                        goto calc_max;
                    }
                    if (best1->addr - (best->addr + best1[-1].size) < target_size && gap_size != 0) {
                        goto loop_move;
                    }
                }
            }
        }
    }

calc_max:
    p = D_019334;
    gap_size = 0;
    while (p->size != 0 && p < D_019334 + 128) {
        gap_addr = p->addr + p->size;
        if (p[1].size != 0) {
            sz = p[1].addr - gap_addr;
        } else {
            sz = 0x200000 - gap_addr;
        }
        if (sz > gap_size) {
            gap_size = sz;
        }
        p++;
    }

    return gap_size;
}
