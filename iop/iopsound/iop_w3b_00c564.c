#include "iopsound.h"

typedef struct {
    s32 magic;
    s16 f4;
    s16 f6;
} BgmHdr;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    BgmHdr *fC;
    s32 f10;
    s32 f14;
} MusicSlot;

typedef struct {
    s32 f0;
    s32 f4;
} BgmEntry;

extern char D_016168[];
extern char D_016184[];
extern char D_016200[];
extern char D_01639C[];
extern char D_0163B8[];
extern s32 D_018700;
extern s32 D_01870C;
extern s32 D_018718;
extern s32 D_018760;
extern s32 D_018F70[];
extern void *D_018FB4;
extern char *D_018FB8;
extern char *D_018FC0;
extern BgmEntry *D_0192F8;
extern s32 D_019320;
extern MusicSlot *D_019338;
extern s32 D_019358[];
extern s8 D_122470[];

extern s32 func_00C054(s32);
extern void func_00BFE8(MusicSlot *);
extern s32 func_00F4C8(char *);
extern s32 func_00F714(void *, void *, s32);
extern BgmHdr *func_00C43C(void *);
extern void func_00F0D4(s32);

BgmHdr *func_00C564(s32 id) {
    s32 idx;
    BgmHdr *res;
    s32 *buf;

    idx = func_00C054(id);
    if (idx >= 0) {
        func_00BFE8(&D_019338[idx]);
        res = D_019338[idx].fC;
        D_019358[0] = -1;
        D_01870C = 1;
        D_019358[1] = res->f6;
        imp_thsemap_6(D_019320);
        return res;
    }

    buf = D_018F70;
    if (D_122470[0] != 0) {
        *buf = D_0192F8[id].f0 << 11;
        idx = D_0192F8[id].f4;
    } else if (D_018700 == 0) {
        *buf = D_018760 + D_0192F8[id].f0;
        idx = D_0192F8[id].f4;
    } else {
        imp_sysclib_19(D_018FC0, D_01639C, D_018FB8, id);
        idx = func_00F4C8(D_018FC0);
    }

    res = NULL;
    if (idx != 0) {
        if (idx <= 0xffff) {
            if (D_122470[0] != 0) {
                if (func_00F714(D_122470, D_018FB4, *buf) != 0) {
                    return (BgmHdr *)-1;
                }
            } else {
                func_00F714(D_018700 != 0 ? (void *)D_018FC0 : (void *)buf, D_018FB4, 0);
            }
            res = func_00C43C(D_018FB4);
        } else {
            imp_sysmem_14(D_0163B8, D_016168, D_016200, idx, D_016184);
            D_018718++;
            func_00F0D4(10);
        }
    } else {
        D_018718++;
        func_00F0D4(11);
    }

    return res;
}
