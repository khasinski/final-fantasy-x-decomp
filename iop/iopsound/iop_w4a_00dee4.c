#include "iopsound.h"

typedef struct {
    u8 pad00[0xC];
    s32 unk0C;
    u8 pad10[0x8];
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x10];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s8 *unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 pad54;
    s32 unk58;
    s32 unk5C;
    s32 pad60;
    s32 unk64;
    s32 pad68;
    s32 unk6C;
} S00DEE4_Stream; /* size 0x70 */

extern char D_016418[];
extern char D_016444[];
extern char D_016458[];
extern char D_016460[];
extern char D_016468[];
extern char D_0164A8[];
extern s32 D_018710;
extern S00DEE4_Stream *D_018754;
extern volatile s32 D_019350;
extern s8 *D_019384;

extern void func_00D014(s32, s8 *, S00DEE4_Stream *);
extern void func_00EFBC(s32, s32);
extern void func_00F0D4(s32);
extern void func_00F120(s32);

void func_00DEE4(s32 a0, s32 a1) {
    if ((D_019350 & 3) != 0) {
        imp_sysmem_14(D_016418, D_016444, D_016458, D_016460);
        func_00F0D4(22);
        return;
    }

    func_00F120(22);
    if (D_018710 != 0) {
        func_00F0D4(20);
    } else {
        func_00F120(20);
        if (D_019384[0] == 'V' && D_019384[1] == 'S') {
            S00DEE4_Stream *s;
            D_019350 |= 8;
            func_00F120(21);
            s = &D_018754[1];
            s->unk0C = 10000;
            s->unk44 = -1;
            s->unk4C = 16;
            s->unk3C = D_019384;
            s->unk30 = 0;
            s->unk34 = 0;
            s->unk38 = 0;
            s->unk48 = 0;
            s->unk18 = 0;
            s->unk40 = 0x8000;
            s->unk6C += 0x8000;
            if (a1 != 0) {
                a1++;
                a1 <<= 7;
                a1--;
                a1 <<= 12;
            }
            s->unk50 = a1;
            s->unk5C = (a0 + 64) << 12;
            s->unk64 = 0;
            s->unk58 = 0;
            func_00D014(0, s->unk3C, s);
        } else {
            imp_sysmem_14(D_016468, D_016444, D_0164A8, D_016460);
            func_00F0D4(21);
        }
    }
    func_00EFBC(6, D_018754[1].unk1C);
}
