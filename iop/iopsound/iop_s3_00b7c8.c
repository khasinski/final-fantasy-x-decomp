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

typedef struct {
    s32 idx;
    s32 id;
    void *data;
    s32 size;
} SepSlot;

extern BankSlot *D_019308;
extern SepSlot *D_01938C;

extern s32 func_009C14(BankSlot *);
extern s32 func_009BB0(s32);

s32 func_00B7C8(void) {
    s32 i = 0;

    do {
        func_009C14(&D_019308[i]);
        i++;
    } while (i < 16);

    return 0;
}

s32 func_00B818(s32 arg0) {
    s32 ret = 0;
    s32 idx = func_009BB0(arg0);

    if (idx >= 0) {
        ret = D_019308[idx].hdr->spu_addr;
    }

    return ret;
}

s32 func_00B870(s32 id) {
    SepSlot *p;

    for (p = D_01938C; p < D_01938C + 192; p++) {
        if (p->size != 0 && p->id == id) {
            return p->idx;
        }
    }

    return -1;
}
