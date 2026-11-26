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
extern u32 D_018708;

extern char D_016168[];
extern char D_016184[];
extern char D_0161BC[];
extern char D_0161DC[];

extern s32 func_009C14(BankSlot *);

void func_00A680(void) {
    BankSlot *p = D_019308;
    BankSlot *end = p + 128;

    do {
        if (p->active != 0) {
            p->spu_addr = p->hdr->spu_addr;
        }
        p++;
    } while (p < end);
}

s32 func_00A6D0(void) {
    BankSlot *p = D_019308 + 16;
    BankSlot *end = D_019308 + 128;
    BankSlot *best = NULL;
    s32 max = 0;

    do {
        if (p->lru > max) {
            max = p->lru;
            best = p;
        }
        p++;
    } while (p < end);

    if (max != 0) {
        imp_sysmem_14(D_0161BC, D_016168, D_0161DC, best->id, D_016184);
        if ((D_018708 & 1) == 0) {
            best->hdr->spu_addr = best->spu_addr;
        }
        func_009C14(best);
    }

    return max;
}
