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
    u32 unk00;
    u32 unk04;
    u32 id;
    s32 size;
    u8 body[4];
} SepData;

typedef struct {
    s32 idx;
    s32 id;
    SepData *data;
    s32 size;
} SepSlot;

typedef struct {
    u8 pad00[0x0A];
    s16 count;
    s32 size;
    s32 offsets[1];
} SebHdr;

typedef struct {
    u32 magic;
    s16 id;
    s16 bank_id;
    u32 unk08;
    u32 unk0C;
    s32 size;
} BgmHdr;

typedef struct {
    s32 idx;
    s32 id;
    s32 lru;
    BgmHdr *hdr;
    s32 size;
    s32 unk14;
} BgmSlot;

typedef struct {
    u8 pad00[0x374];
    s32 bgm_id;
    u32 unk378;
    s32 bank_id;
    u8 pad380[0x0A];
    s16 active;
    u8 pad38C[4];
} SeqCtrl;

extern BankSlot *D_019308;
extern SepSlot *D_01938C;
extern SeqCtrl *D_01936C;
extern BgmSlot *D_019338;
extern SebHdr *D_01873C;
extern s32 D_122410[];
extern s32 D_122430;
extern s32 D_018700;
extern char *D_018FBC;
extern char *D_018FB8;
extern void *D_018FB4;

extern char D_016360[];

extern s32 func_009BB0(s32);
extern void func_009B28(s32);
extern s32 func_009834(s32);
extern s32 func_009948(s32);
extern s32 func_009360(s32, s32, s32);
extern s32 func_0093C8(u32, s32, s32);
extern void func_00AAA8(s32, s32);
extern s32 func_00B870(s32);
extern SepData *func_00BA1C(SepData *);
extern void func_013F30(s32);
extern void func_0072F4(s32);
extern s32 func_00B8D4(SepSlot *);
extern void func_00B5EC(u32, s32);
extern s32 func_00F4C8(char *);
extern s32 func_00F714(void *, void *, u32, s32);

s32 func_00BB10(s32 idx) {
    SebHdr *hdr = D_01873C;
    s32 count = hdr->count;

    if (idx < count) {
        s32 *offsets = hdr->offsets;
        s32 off = offsets[idx];
        if (off != -1) {
            u8 *p = (u8 *)(offsets + count) + off;
            s32 bank_id = (p[2] << 8) + p[1];
            func_00AAA8(-1, bank_id);
            return bank_id;
        }
    }

    return -1;
}

SepData *func_00BB90(SepData *src) {
    s32 res = func_00B870(src->id);

    if (res >= 0) {
        res = (s32)D_01938C[res].data;
    } else {
        res = (s32)func_00BA1C(src);
    }

    if (res != 0) {
        u8 *b = ((SepData *)res)->body;
        s32 bank_id = (b[2] << 8) | b[1];
        src->id &= 0x7FFFFFFF;
        func_013F30(bank_id);
    }

    return (SepData *)res;
}

s32 func_00BC2C(s32 arg0, s32 arg1) {
    SepSlot *p;
    s32 ret = 0;

    if (arg1 == 0) {
        if (arg0 == -1) {
            p = D_01938C;
            do {
                if (p->size != 0) {
                    func_0072F4(p->id);
                    func_00B8D4(p);
                }
                p++;
            } while (p < D_01938C + 192);
        } else {
            ret = func_00B870(arg0 | 0x80000000);
            if (ret >= 0) {
                func_0072F4(D_01938C[ret].id);
                ret = func_00B8D4(&D_01938C[ret]);
            }
        }
    } else {
        p = D_01938C;
        D_122430 = -1;
        do {
            if (p->size != 0) {
                s32 *q = D_122410;
                while (*q != -1) {
                    if (*q == p->id) {
                        u8 *b = p->data->body;
                        ret = func_009BB0(b[1] | (b[2] << 8));
                        if (ret >= 16) {
                            if (D_019308[ret].lru != 0) {
                                func_009B28(D_019308[ret].lru);
                                D_019308[ret].lru = 0;
                            }
                        }
                        break;
                    }
                    q++;
                }
                if (*q == -1) {
                    func_0072F4(p->id);
                    func_00B8D4(p);
                }
            }
            p++;
        } while (p < D_01938C + 192);
    }

    return ret;
}

SebHdr *func_00BE50(SebHdr *src) {
    if (D_01873C != NULL) {
        func_009834((s32)D_01873C);
    }

    src->size = (src->size + 3) & -4;
    D_01873C = (SebHdr *)func_009948(src->size);
    if (D_01873C != NULL) {
        func_009360((s32)src, (s32)D_01873C, src->size);
    }

    return D_01873C;
}

void func_00BEC4(s32 id) {
    if (D_018700 != 0) {
        imp_sysclib_19(D_018FBC, D_016360, D_018FB8, id);
    }
    if (func_00F4C8(D_018FBC) != 0) {
        if (D_018700 != 0) {
            func_00F714(D_018FBC, D_018FB4, 0, 0x10000);
        }
        func_00BE50((SebHdr *)D_018FB4);
    }
}

void func_00BF5C(void) {
    BgmSlot *p = D_019338;
    BgmSlot *end = p + 2;

    do {
        if (p->lru != 0) {
            p->lru++;
        }
        p++;
    } while (p < end);
}

void func_00BF9C(s32 lru) {
    if (lru != 0) {
        BgmSlot *p = D_019338;
        BgmSlot *end = p + 2;
        do {
            if (p->lru > lru) {
                p->lru--;
            }
            p++;
        } while (p < end);
    }
}

void func_00BFE8(BgmSlot *slot) {
    if (slot->lru != 0) {
        BgmSlot *p = D_019338;
        BgmSlot *end = p + 2;
        do {
            if (p->lru != 0 && p->lru < slot->lru) {
                p->lru++;
            }
            p++;
        } while (p < end);
        slot->lru = 1;
    }
}

s32 func_00C054(s32 id) {
    BgmSlot *p = D_019338;
    BgmSlot *end = p + 2;

    do {
        if (p->size != 0 && p->id == id) {
            return p->idx;
        }
        p++;
    } while (p < end);

    return -1;
}

s32 func_00C0AC(BgmSlot *slot) {
    s32 ret;

    func_00B5EC(4, slot->hdr->bank_id);
    ret = func_009834((s32)slot->hdr);
    slot->size = 0;
    slot->hdr = NULL;
    slot->lru = 0;
    slot->id = -1;
    return ret;
}

s32 func_00C100(void) {
    BgmSlot *p = D_019338;
    BgmSlot *end = p + 2;
    BgmSlot *best = NULL;
    s32 max = 0;

    do {
        if (p->lru > max) {
            max = p->lru;
            best = p;
        }
        p++;
    } while (p < end);

    if (max != 0) {
        func_00C0AC(best);
    }

    return max;
}

BgmSlot *func_00C170(void) {
    BgmSlot *best = NULL;
    BgmSlot *p = D_019338;
    BgmSlot *end = p + 2;
    s32 max = 0;

    do {
        if (p->size == 0) {
            return p;
        }
        if (p->lru > max) {
            max = p->lru;
            best = p;
        }
        p++;
    } while (p < end);

    return best;
}

void func_00C1C8(u32 arg0, s32 arg1) {
    if (arg0 & 1) {
        SeqCtrl *sc = D_01936C;
        s32 in_use = 0;

        if (sc[0].active != 0) {
            if (sc[0].bgm_id == arg1) {
                in_use = 1;
            }
        }
        if (sc[1].active != 0 && sc[1].bgm_id == arg1) {
            in_use |= 1;
        }

        if (in_use == 0) {
            s32 idx = func_00C054(arg1);
            if (idx >= 0) {
                if (D_019338[idx].lru == 0) {
                    func_00BF5C();
                    D_019338[idx].lru = 1;
                }
            }
        }
    } else {
        s32 idx = func_00C054(arg1);
        if (idx >= 0) {
            if (D_019338[idx].lru != 0) {
                func_00BF9C(D_019338[idx].lru);
                D_019338[idx].lru = 0;
            }
        }
    }
}

void func_00C2F0(void) {
    s32 i;
    BgmSlot *p;

    func_0093C8((u32)D_019338, 72, 0);
    p = D_019338;
    i = 0;
    do {
        p->idx = i;
        p->id = -1;
        p++;
        i++;
    } while (i < 2);
}
