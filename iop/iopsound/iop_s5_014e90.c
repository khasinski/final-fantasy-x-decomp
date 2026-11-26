#include "iopsound.h"

typedef struct {
    u32 src;
    u32 dst;
    s32 remain;
    s32 state;
} S_Defrag;

typedef struct {
    u8 pad00[0x108];
    s32 f108;
    u8 pad10c[0x30];
} S_Voice; /* size 0x13c = 316 */

typedef struct {
    S_Voice *voices;
    u8 pad04[0x389];
    u8 count; /* 0x38d = 909 */
    u8 pad38e[0x02];
} S_TrackGroup; /* size 0x390 = 912 */

typedef struct {
    u8 pad00[0x58];
    u16 ch;
    u8 pad5a[0x1a];
} S_HwVoice; /* size 0x74 = 116 */

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
} S_WaveInfo; /* size 24 */

typedef struct {
    u32 addr;
    s32 size;
} S_SpuBlock; /* size 8 */

extern u8 *D_018FB4;
extern volatile u32 D_019394;
extern S_TrackGroup *D_01936C;
extern S_HwVoice *D_0192F0;
extern S_WaveInfo *D_019308;
extern s32 D_01939C;
extern S_SpuBlock *D_019334;

extern void func_00F038(s32);
extern void func_00F084(s32);
extern void func_00FC2C(s32, s32, void *, u32, s32);
extern void func_00FDF4(s32, void *, void *);
extern s32 func_014CC8(s32, S_Defrag *);

void func_014E90(s32 old_addr, s32 new_addr) {
    S_TrackGroup *grp = D_01936C;
    S_Voice *v;

    if (grp->count != 0) {
        v = grp->voices;
        do {
            if (v->f108 == old_addr) {
                v->f108 = new_addr;
            }
            v++;
        } while (v < grp->voices + grp->count);
    }
    grp++;
    if (grp->count != 0) {
        v = grp->voices;
        do {
            if (v->f108 == old_addr) {
                v->f108 = new_addr;
            }
            v++;
        } while (v < grp->voices + grp->count);
    }
    grp++;
    v = grp->voices;
    do {
        if (v->f108 == old_addr) {
            v->f108 = new_addr;
        }
        v++;
    } while (v < grp->voices + 24);
    grp++;
    if (grp->count != 0) {
        v = grp->voices;
        do {
            if (v->f108 == old_addr) {
                v->f108 = new_addr;
            }
            v++;
        } while (v < grp->voices + grp->count);
    }
}

s32 func_015008(s32 start, s32 end) {
    S_HwVoice *v = D_0192F0;
    s32 found = 0;

    do {
        if ((s16)imp_libsd_6(v->ch | 0x0500) > 0) {
            s32 addr = imp_libsd_10(v->ch | 0x2240);
            if (addr >= start && addr < end) {
                found++;
                break;
            }
        }
        v++;
    } while (v < D_0192F0 + 48);
    return found;
}

void func_0150C0(S_WaveHdr *w, u32 dst) {
    S_Defrag df;
    s32 old_addr;
    s32 end_addr;
    s32 diff;
    S_HwVoice *v;

    df.src = w->f10;
    df.dst = dst;
    df.remain = w->f04;
    df.state = 2;
    func_00FDF4(0, func_014CC8, &df);
    func_00FDF4(1, func_014CC8, &df);
    func_00FC2C(0, 1, D_018FB4 + 0x8000, df.src, 0x4000);
    func_00FC2C(1, 1, D_018FB4 + 0xC000, df.src + 0x4000, 0x4000);
    D_019394 |= 0x10000;
    while (D_019394 & 0x10000) {
        imp_thbase_33(1000);
    }
    old_addr = w->f10;
    end_addr = old_addr + w->f04;
    w->f10 = dst;
    func_014E90(old_addr, dst);
    diff = old_addr - dst;
    v = D_0192F0;
    do {
        if ((s16)imp_libsd_6(v->ch | 0x0500) > 0) {
            s32 loop_addr = imp_libsd_10(v->ch | 0x2140);
            if (loop_addr >= old_addr && loop_addr < end_addr) {
                imp_libsd_9(v->ch | 0x2140, loop_addr - diff);
                imp_libsd_9(v->ch | 0x2040, imp_libsd_10(v->ch | 0x2040) - diff);
            }
        }
        v++;
    } while (v < D_0192F0 + 48);
    func_00F038(5);
    while (func_015008(old_addr, end_addr) != 0) {
        imp_thbase_33(500);
    }
    func_00F084(5);
}

S_WaveInfo *func_0152C8(s32 mode, u32 addr, s32 max_sz) {
    S_WaveInfo *w;
    S_WaveInfo *best_w;
    S_WaveInfo *end;
    s32 best_sz;

    if (mode == 2) {
        w = D_019308;
        best_w = w + 128;
        do {
            if (w->f10 != 0 && w->f0c->f04 != 0 && w->f0c->f10 == addr) {
                best_w = w;
                break;
            }
            w++;
        } while (w < D_019308 + 128);
    } else if (mode == 1) {
        w = D_019308;
        best_sz = 0x200000;
        best_w = w + 128;
        end = best_w;
        do {
            if (w->f10 != 0 && addr < w->f0c->f10) {
                s32 sz = w->f0c->f04;
                if (sz <= max_sz && sz < best_sz) {
                    best_w = w;
                    best_sz = sz;
                }
            }
            w++;
        } while (w < end);
    } else {
        w = D_019308;
        best_sz = 0;
        best_w = w + 128;
        end = best_w;
        do {
            if (w->f10 != 0 && addr < w->f0c->f10) {
                s32 sz = w->f0c->f04;
                if (sz <= max_sz && sz > best_sz) {
                    best_w = w;
                    best_sz = sz;
                }
            }
            w++;
        } while (w < end);
    }
    return best_w;
}

void func_01544C(void) {
    while (1) {
        S_SpuBlock *b;
        imp_thsemap_8(D_01939C);
        func_00F038(4);
        b = D_019334;
        do {
            if (b->size != 0) {
                S_WaveInfo *w = D_019308;
                u32 addr = b->addr;
                do {
                    if (w->f10 != 0 && w->f14 == addr) {
                        break;
                    }
                    w++;
                } while (w < D_019308 + 128);
                if (w < D_019308 + 128) {
                    S_WaveHdr *hdr = w->f0c;
                    if (hdr->f10 != addr) {
                        ((void (*)(S_WaveHdr *, u32, s32))func_0150C0)(hdr, addr, 0x8000);
                    }
                }
            }
            b++;
        } while (b->size != 0);
        D_019394 = 0;
        func_00F084(4);
    }
}
