#include "iopsound.h"

typedef struct {
    s32 magic;
    s16 unk04;
    s16 unk06;
} S00C43C_Hdr;

typedef struct {
    u8 pad00[0xC];
    s32 unk0C;
    u8 pad10[0x8];
} S00C43C_Entry; /* size 24 */

extern char D_016168[];
extern char D_016184[];
extern char D_016200[];
extern char D_01637C[];
extern s32 D_01870C;
extern volatile s32 D_018718;
extern s32 D_019320;
extern S00C43C_Entry *D_019338;
extern s32 D_019358[];

extern void func_00BFE8(S00C43C_Entry *);
extern s32 func_00C054(s32);
extern s32 func_00C348(S00C43C_Hdr *);
extern void func_00F0D4(s32);
extern void func_00F120(s32);

s32 func_00C43C(S00C43C_Hdr *hdr) {
    s32 res;

    func_00F120(9);
    res = hdr->magic;
    if (res != 0x204D4742) {
        imp_sysmem_14(D_01637C, D_016168, D_016200, D_016184);
        D_018718++;
        func_00F0D4(9);
        return 0;
    }

    res = func_00C054(hdr->unk04);
    if (res >= 0) {
        func_00BFE8(&D_019338[res]);
        res = D_019338[res].unk0C;
    } else {
        res = func_00C348(hdr);
    }

    if (res != 0) {
        D_019358[0] = -1;
        D_01870C = 1;
        D_019358[1] = hdr->unk06;
        imp_thsemap_6(D_019320);
    }
    return res;
}
