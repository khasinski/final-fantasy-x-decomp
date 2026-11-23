#include "common.h"

typedef struct UnkA9C0 {
    u16 *unk0;
    u8 pad4[0x20];
    void (*unk24)(struct UnkA9C0 *);
    void (*unk28)(struct UnkA9C0 *);
    u8 pad2C[0x28];
    u16 unk54;
    u8 unk56;
} UnkA9C0;

typedef u16 *(*OpFn)(UnkA9C0 *, u16 *);

extern OpFn D_01B00F50[];

extern s32 func_00116068(void);

s32 func_01B0A9C0(UnkA9C0 *arg0) {
    u16 *p;

    if (func_00116068() == 0) {
        return 0;
    }

    p = arg0->unk0;
    while (arg0->unk56 == 1) {
        p = D_01B00F50[*p](arg0, p);
    }
    arg0->unk0 = p;

    switch (arg0->unk56) {
        case 0:
            return 1;
        case 2:
            if (arg0->unk54 != 0xFFFF) {
                arg0->unk54--;
                if (arg0->unk54 == 0) {
                    arg0->unk56 = 1;
                }
            }
            break;
        case 3:
            arg0->unk24(arg0);
            break;
        default:
            return 0;
    }
    if (arg0->unk28 != 0) {
        arg0->unk28(arg0);
    }
    return 0;
}
