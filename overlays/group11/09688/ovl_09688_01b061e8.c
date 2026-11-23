#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x20];
} Unk61E8Slot;

typedef struct {
    u8 pad0[0xEAD4];
    Unk61E8Slot unkEAD4[4];
    Unk61E8Slot *unkEB74;
    s32 unkEB78;
    s32 unkEB7C;
    s32 unkEB80;
    s32 unkEB84;
} Unk61E8Work;

extern u8 D_01B00AE8;
extern void *D_01B00F18[];
extern void *D_01B01214;
extern u8 D_01B0DC28;
extern u8 D_01B0DC88;
extern Unk61E8Work *D_01B0DCA8;
extern void *D_01B0DCB4;

extern void func_001E4640(s32);
extern void func_01B06418(void);
extern void func_01B06678(void);
extern s32 func_01B070D8(s32);
extern void func_01B08DC8(void *);
extern void func_01B09968(void *);
extern void func_01B0A730(void);
extern void func_01B0B148(void);
extern void func_01B0D350(void *, void *);
extern s32 func_01B0D370(void *);

void func_01B061E8(void *arg0) {
    Unk61E8Work *work = D_01B0DCA8;

    func_01B0B148();
    D_01B01214 = D_01B0DCB4;

    switch (work->unkEB80) {
    case 0:
        func_01B0D350(&D_01B0DC28, &D_01B00AE8);
        work->unkEB80 = 1;
        break;
    case 1:
        func_01B0A730();
        if (func_01B0D370(&D_01B0DC28) == 1) {
            func_001E4640(func_01B070D8(-1));
            func_01B06418();
            work->unkEB80 = 2;
        }
        break;
    case 2: {
        Unk61E8Slot *slot = &work->unkEAD4[work->unkEB7C];
        work->unkEB74 = slot;
        func_01B0D350(&D_01B0DC28, D_01B00F18[slot->unk0]);
        work->unkEB80 = 3;
        work->unkEB7C++;
    }
    case 3:
        if (func_01B0D370(&D_01B0DC28) == 1) {
            if (work->unkEB7C >= work->unkEB78) {
                work->unkEB84 = 1;
                func_01B06678();
                func_01B09968(arg0);
            } else {
                work->unkEB80 = 2;
            }
        }
        break;
    }

    func_01B08DC8(&D_01B0DC88);
}
