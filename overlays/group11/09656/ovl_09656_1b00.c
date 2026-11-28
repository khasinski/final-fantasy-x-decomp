#include "common.h"

extern u8 *D_01B0A988;

extern s32 func_001038F8(void);

typedef struct {
    s32 unk00;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 pad0B;
    u16 unk0C;
    u16 unk0E;
    s32 unk10;
    s32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    s32 unk20;
    u8 pad24[0x10];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u16 unk40;
    u16 unk42;
    s32 unk44;
    s32 unk48;
} Param1B00;

void func_01B01B00(void) {
    u8 *base = D_01B0A988;
    Param1B00 *p;
    s32 r;

    *(volatile s32 *)(base + 0x3B80) = 0x20C;
    r = func_001038F8();
    p = (Param1B00 *)(base + 0x3B80);
    p->unk04 = r;
    p->unk08 = 0;
    p->unk09 = 0x80;
    p->unk0A = 0;
    p->unk0C = 0;
    p->unk0E = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    p->unk18 = 0x4C;
    p->unk19 = 0x4C;
    p->unk1A = 0x4C;
    p->unk1B = 0x80;
    p->unk1C = 0;
    p->unk1D = 0;
    p->unk1E = 0;
    p->unk1F = 0;
    p->unk20 = 0;
    p->unk34 = 0;
    p->unk38 = 0;
    p->unk3C = 0;
    p->unk40 = 0;
    p->unk42 = 0;
    p->unk44 = 0;
    p->unk48 = 0;
}
