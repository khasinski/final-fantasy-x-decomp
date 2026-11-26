#include "iopsound.h"

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
    void *data;
    s32 size;
    s32 unk14;
} BgmSlot;

extern BgmSlot *D_019338;
extern s32 D_019320;
extern s32 D_019358[2];
extern s32 D_01870C;
extern s32 D_018718;

extern char D_01637C[];
extern char D_016168[];
extern char D_016200[];
extern char D_016184[];

extern BgmSlot *func_00C170(void);
extern void func_00C100(void);
extern void *func_009948(s32);
extern void func_00BF5C(void);
extern void func_009360(BgmHdr *, void *, s32);
extern void func_00F0D4(s32);
extern void func_00F120(s32);
extern s32 func_00C054(s32);
extern void func_00BFE8(BgmSlot *);

void *func_00C348(BgmHdr *hdr) {
    void *buf = NULL;
    BgmSlot *slot = func_00C170();

    if (slot != NULL) {
        if (slot->size != 0) {
            func_00C100();
            slot = func_00C170();
        }
        if (slot != NULL) {
            hdr->size = (hdr->size + 3) & ~3;
            buf = func_009948(hdr->size);
            if (buf != NULL) {
                slot->data = buf;
                slot->size = hdr->size;
                slot->id = hdr->id;
                func_00BF5C();
                slot->lru = 1;
                func_009360(hdr, buf, hdr->size);
                goto done;
            }
            func_00F0D4(13);
        }
    }
    D_018718++;
done:
    return buf;
}
