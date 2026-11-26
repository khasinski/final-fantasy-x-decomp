#include "iopsound.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s16 unk08;
    s16 unk0A;
    s32 unk0C;
    s32 unk10;
} S008824_Eff;

typedef struct {
    void (*unk00)(s32, void *);
    s32 unk04;
    s32 unk08;
    s8 *unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} S008824_State;

extern char D_0160A8[];
extern char D_0160C4[];
extern char D_016120[];
extern char D_016148[];
extern u8 D_017700[];
extern S008824_Eff *D_018728;
extern s32 D_018734[];
extern s32 D_01877C;
extern volatile s32 D_019350;
extern S008824_State D_06D270;

extern void func_008214(s32, void *);
extern void func_0086F8(void);
extern void func_00F038(s32);
extern void func_00F0D4(s32);
extern void func_00F120(s32);
extern void func_00FC2C(s32, s32, void *, s32, s32);
extern void func_00FDF4(s32, void *, void *);

void func_008824(s8 *a0, s32 a1, s32 a2, s32 a3) {
    s32 size;
    s32 chunk;

    func_00F120(12);
    imp_libsd_24(0, D_018728);
    if (D_018728->unk04 != a0[9]) {
        if (D_019350 != 0) {
            imp_sysmem_14(D_016120, D_0160A8, D_016148, D_0160C4);
            func_00F0D4(12);
        }
    }
    if (D_019350 == 0 && D_018728->unk04 != a0[9]) {
        D_019350 |= 1;
        func_00F038(16);
        size = D_01877C;
        imp_libsd_11(2, 0);
        imp_libsd_11(3, 0);
        D_018728->unk04 = a0[9];
        D_018728->unk0A = 0;
        D_018728->unk08 = 0;
        D_018728->unk0C = 0;
        D_018728->unk10 = 0;
        imp_libsd_23(0, D_018728);
        imp_libsd_23(1, D_018728);
        chunk = 0x1000;
        if (size <= 0x1000) {
            chunk = size;
        }
        {
            S008824_State *st = &D_06D270;
            st->unk24 = size - chunk;
            st->unk2C = size - chunk;
            st->unk00 = func_008214;
            st->unk08 = 1;
            st->unk0C = a0;
            st->unk10 = a1;
            st->unk14 = a2;
            st->unk18 = a3;
            st->unk20 = D_018734[0] + chunk;
            st->unk28 = D_018734[1] + chunk;
            if (size > 0x1000) {
                func_00FDF4(0, func_0086F8, 0);
                func_00FDF4(1, func_0086F8, 0);
            } else {
                func_00FDF4(0, 0, 0);
                func_00FDF4(1, st->unk00, &st->unk08);
            }
        }
        func_00FC2C(0, 0, D_017700, D_018734[0], chunk);
        func_00FC2C(1, 0, D_017700, D_018734[1], chunk);
    } else {
        S008824_State *st = &D_06D270;
        st->unk08 = 0;
        st->unk0C = a0;
        st->unk10 = a1;
        st->unk14 = a2;
        st->unk18 = a3;
        func_008214(1, &st->unk08);
    }
}
