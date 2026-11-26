#include "iopsound.h"

typedef struct {
    s32 unk00;
    u8 pad04[0x122];
    s16 unk126;
    s16 unk128;
    s16 unk12A;
    u8 pad12C[4];
    s8 unk130;
    u8 pad131[11];
} Track;

typedef struct {
    u8 pad00[0x10];
    s32 unk10;
} VoiceSub;

typedef struct {
    Track *track;
    VoiceSub *unk04;
    u8 pad08[0x0E];
    u8 unk16;
    u8 pad17[0x39];
    s32 unk50;
    s32 unk54;
    u8 pad58[0x10];
    u32 flags;
    u8 pad6C[8];
} Voice;

typedef struct {
    s32 val;
    s32 delta;
    s32 cnt;
} FadeParam;

extern Voice *D_0192F0;
extern FadeParam D_122440;

extern s32 func_0013E4(s32, s32, s32, s32);

void func_0091E4(s32 arg0) {
    Voice *v;
    FadeParam *p;

    arg0 <<= 12;
    v = D_0192F0;
    p = &D_122440;
    p->val = arg0;
    p->cnt = 0;

    do {
        if ((v->unk16 & 3) == 0) {
            Track *tr = v->track;
            v->unk50 = func_0013E4(v->unk54 + D_122440.val, tr->unk12A + tr->unk126, v->unk04->unk10, tr->unk130);
            v->flags |= 1;
        }
        v++;
    } while (v < D_0192F0 + 48);
}
