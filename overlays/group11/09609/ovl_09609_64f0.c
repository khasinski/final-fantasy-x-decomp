#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x20];
} Unk64F0Slot;

typedef struct {
    u8 pad0[0xEC04];
    Unk64F0Slot unkEC04[4];
    Unk64F0Slot *unkECA4;
    s32 unkECA8;
    s32 unkECAC;
    s32 unkECB0;
    s32 unkECB4;
} Unk64F0Work;

extern u8 D_01B00B10;
extern void *D_01B00F58[];
extern s32 D_01B0104C;
extern void *D_01B01254;
extern void *D_01B0DEA8;
extern u8 D_01B0DEB0;
extern void *D_01B0DEF4;
extern u8 D_01B0DEF8;
extern u8 D_01B0DF58;
extern Unk64F0Work *D_01B0DF78;
extern void *D_01B0DF84;

extern void func_001CDDD8(void *);
extern void func_001E4640(s32);
extern u8 *func_001E4680(void *, s32 *, s32, s32 *);
extern void func_01B06980(void);
extern void func_01B06A18(void);
extern s32 func_01B073A8(s32);
extern void func_01B09098(void *);
extern void func_01B09C38(void *);
extern s32 func_01B09FF8(void *, void *);
extern void func_01B0AA00(void);
extern void func_01B0B418(void);
extern void func_01B0D620(void *, void *);
extern s32 func_01B0D640(void *);

void func_01B06720(void);

void func_01B064F0(void *arg0) {
    Unk64F0Work *work = D_01B0DF78;

    func_01B0B418();
    D_01B01254 = D_01B0DF84;

    switch (work->unkECB0) {
    case 0:
        func_01B0D620(&D_01B0DEF8, &D_01B00B10);
        work->unkECB0 = 1;
        break;
    case 1:
        func_01B0AA00();
        if (func_01B0D640(&D_01B0DEF8) == 1) {
            func_001E4640(func_01B073A8(-1));
            func_01B06720();
            work->unkECB0 = 2;
        }
        break;
    case 2: {
        Unk64F0Slot *slot = &work->unkEC04[work->unkECAC];
        work->unkECA4 = slot;
        func_01B0D620(&D_01B0DEF8, D_01B00F58[slot->unk0]);
        work->unkECB0 = 3;
        work->unkECAC++;
    }
    case 3:
        if (func_01B0D640(&D_01B0DEF8) == 1) {
            if (work->unkECAC >= work->unkECA8) {
                work->unkECB4 = 1;
                func_01B06980();
                func_01B09C38(arg0);
            } else {
                work->unkECB0 = 2;
            }
        }
        break;
    }

    func_01B09098(&D_01B0DF58);
}

void func_01B066A8(void) {
    Unk64F0Work *work = D_01B0DF78;

    if (func_01B09FF8(&D_01B0DEB0, D_01B0DEF4) == 1) {
        if (work->unkECB4 == 1) {
            func_01B06A18();
            func_001CDDD8(D_01B0DEA8);
        }
    }
}

void func_01B06720(void) {
    s32 cnt;
    s32 id;
    Unk64F0Work *work = D_01B0DF78;
    Unk64F0Slot *slot = work->unkEC04;
    s32 n = D_01B0104C;
    s32 total = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *arr = func_001E4680(D_01B0DEA8, &cnt, i, &id);
        if (id != 0) {
            s32 j;
            slot->unk0 = id;
            slot->unk4 = cnt;
            for (j = 0; j < cnt; j++) {
                s32 k;
                for (k = 0; k < n; k++) {
                    if (arr[j] == func_01B073A8(k)) {
                        slot->unk8[j] = k;
                        break;
                    }
                }
            }
            total++;
            slot++;
        }
    }
    work->unkECA8 = total;
}
