#include "common.h"

typedef struct {
    u8 pad00[0x6C];
    s32 unk6C;
    u8 pad70[0x10];
} UnkAC80;

extern UnkAC80 *D_01B10470;
extern s32 D_01B10474;
extern s32 D_01B10478;
extern s32 D_01B1047C;

extern s32 func_01B07000(void (*)(void));
extern void func_01B071C8(s32);
extern void func_01B0ADC8(void);

s32 func_01B0AC80(UnkAC80 *arg0, s32 arg1) {
    s32 i;
    s32 id;

    D_01B10470 = arg0;
    for (i = 0; i < arg1; i++) {
        arg0->unk6C = 0;
        arg0++;
    }
    D_01B10474 = 0;
    D_01B10478 = arg1;
    D_01B1047C = 0;
    id = func_01B07000(func_01B0ADC8);
    func_01B071C8(id);
    return id;
}
