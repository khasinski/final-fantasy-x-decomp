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
    Track *track;
    void *unk04;
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
    Track *tracks;
    u8 pad04[0x18];
    s32 vol;
    s32 vol_delta;
    s32 vol_cnt;
    u8 pad28[0x348];
    u32 flags;
    s32 id;
    u8 pad378[0x12];
    s16 unk38A;
    u8 pad38C;
    u8 track_cnt;
    u8 pad38E[2];
} SeqCtrl;

typedef struct {
    s32 val;
    s32 delta;
    s32 cnt;
} FadeParam;

extern SeqCtrl *D_01936C;
extern Voice *D_0192F0;
extern s32 D_019328;
extern FadeParam D_122450;

s32 func_008E60(s32 arg0, s32 arg1) {
    SeqCtrl *ctrl;
    SeqCtrl *ctrl_end;
    Voice *voice_end;

    if (arg1 != 0) {
        arg1++;
        arg1 <<= 2;
        arg1--;
        arg1 <<= 12;
    }

    voice_end = D_0192F0 + 48;
    ctrl = D_01936C;
    ctrl_end = ctrl + 2;
    do {
        if (arg0 == -1 || arg0 == ctrl->id || ctrl->id < 0) {
            ctrl->vol = arg1;
            ctrl->vol_cnt = 0;
            if (ctrl->unk38A != 0) {
                Track *tr = ctrl->tracks;
                do {
                    if (tr->unk00 != 0) {
                        Voice *v = D_0192F0;
                        do {
                            if (v->track == tr) {
                                v->flags |= 2;
                            }
                            v++;
                        } while (v < voice_end);
                    }
                    tr++;
                } while (tr < ctrl->tracks + ctrl->track_cnt);
            }
        }
        ctrl++;
    } while (ctrl < ctrl_end);

    return 0;
}

s32 func_008F64(s32 arg0, s32 arg1, s32 arg2) {
    SeqCtrl *ctrl;
    SeqCtrl *ctrl_end;

    if (arg2 != 0) {
        arg2++;
        arg2 <<= 2;
        arg2--;
        arg2 <<= 12;
    }
    arg2 |= 0x800;

    if (D_019328 != 120) {
        arg1 *= 60;
        arg1 /= 50;
    }

    ctrl = D_01936C;
    ctrl_end = ctrl + 2;
    do {
        if (arg0 == -1 || arg0 == ctrl->id || ctrl->id < 0) {
            ctrl->vol_delta = (arg2 - ctrl->vol) / arg1;
            ctrl->vol_cnt = arg1;
        }
        ctrl++;
    } while (ctrl < ctrl_end);

    return 0;
}

s32 func_009040(s32 arg0, s32 arg1) {
    SeqCtrl *ctrl;
    SeqCtrl *ctrl_end;

    if (D_019328 != 120) {
        arg1 *= 60;
        arg1 /= 50;
    }

    ctrl = D_01936C;
    ctrl_end = ctrl + 2;
    do {
        if (arg0 == -1 || arg0 == ctrl->id || ctrl->id < 0) {
            ctrl->vol_delta = (0x800 - ctrl->vol) / arg1;
            ctrl->vol_cnt = arg1;
            if (ctrl->unk38A != 0) {
                ctrl->flags |= 0x10000;
            }
        }
        ctrl++;
    } while (ctrl < ctrl_end);

    return 0;
}

void func_009120(s32 arg0) {
    FadeParam *p;

    arg0 <<= 8;
    if (arg0 > 0) {
        arg0 += 255;
    }
    arg0 <<= 12;
    p = &D_122450;
    p->val = arg0;
    p->cnt = 0;
}
