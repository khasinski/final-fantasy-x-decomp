#include "iopsound.h"

typedef struct {
    u32 addr;
    s32 size;
} S_SpuBlock;

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    u32 f10;
} S_WaveHdr;

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    S_WaveHdr *f0c;
    s32 f10;
    u32 f14;
} S_WaveInfo;

extern S_SpuBlock *D_019334;
extern S_WaveInfo *D_019308;
extern u32 D_06D26C;

extern char D_0165F0[];
extern char D_016890[];
extern char D_0168BC[];
extern char D_0168F4[];
extern char D_016928[];
extern char D_016958[];
extern char D_016988[];
extern char D_0169C4[];

extern u32 func_00EFB0(void);
extern void func_015AA0(void);

s32 func_013900(void) {
    S_SpuBlock *b;
    S_WaveInfo *w;
    s32 total;
    s32 max_free;
    s32 free_sz;
    u32 addr;
    u32 now_sp;
    u32 total_free;
    u32 max_cont;

    imp_sysmem_14(D_016890, D_0165F0);
    imp_sysmem_14(D_0168BC, D_0165F0);

    total = 0;
    for (b = D_019334; b->size != 0 && b < D_019334 + 128; b++) {
        addr = b->addr;
        for (w = D_019308; w < D_019308 + 128; w++) {
            if (w->f10 != 0 && addr == w->f0c->f10) {
                break;
            }
        }
        if (b[1].size != 0) {
            free_sz = b[1].addr;
        } else {
            free_sz = 0x200000;
        }
        free_sz -= b->addr + b->size;
        if (w < D_019308 + 128) {
            imp_sysmem_14(D_0168F4, D_0165F0, w->f04, b->addr, b->size, free_sz, w->f08);
            total++;
        } else {
            imp_sysmem_14(D_016928, D_0165F0, b->addr, b->size, free_sz);
        }
    }

    max_free = 0;
    for (b = D_019334; b->size != 0 && b < D_019334 + 128; b++) {
        s32 gap;
        addr = b->addr + b->size;
        if (b[1].size != 0) {
            gap = b[1].addr - addr;
        } else {
            gap = 0x200000 - addr;
        }
        if (gap > max_free) {
            max_free = gap;
        }
    }

    imp_sysmem_14(D_016958, D_0165F0, D_0165F0, total, max_free);
    imp_sysmem_14(D_016988);
    now_sp = func_00EFB0();
    total_free = imp_sysmem_8();
    max_cont = imp_sysmem_7();
    imp_sysmem_14(D_0169C4, D_06D26C, now_sp, total_free, max_cont);
    func_015AA0();
    return total;
}
