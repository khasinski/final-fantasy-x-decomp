#include "common.h"

typedef struct {
    s32 cmd;
    s32 arg;
} MotionEntry;

typedef struct {
    MotionEntry *entries;
    void *unk04;
    void *unk08;
    void *unk0C;
    s32 idx;
    s32 done;
    s16 timer;
    s16 unk1A;
    s16 mode;
} MotionCtrl;

extern s32 Sg_GetCurExecFrames(void);
extern s32 MsEffectCheckMotion(void *);
extern s32 Ch_GetWaitMotion(void *);
extern void Ch_MotionSetNextHokan(void *, s32);
extern s32 func_001CE050(void *, s32);
extern void Ch_ResetMotion(void *);
extern void Ch_SetSequence(void *, s32);
extern void Ch_SetSysMotion(void *, s32, s32);
extern s32 Ch_GetSeqFrame(void *);
extern void func_01B05528(void *);
extern void func_01B06768(MotionCtrl *, s32);
extern void func_01B06770(MotionCtrl *, s32);

s32 func_01B064C0(MotionCtrl *ctrl) {
    MotionEntry *entry;
    s32 frames;
    s32 ready;

    if (ctrl->done == 1) {
        return 1;
    }
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }

    if (ctrl->timer == 0) {
        ctrl->unk1A++;
        if (ctrl->mode == 0) {
            ready = MsEffectCheckMotion(ctrl->unk08);
        } else {
            s32 ok = 1;
            if (Ch_GetWaitMotion(ctrl->unk0C) != 0) {
                ok = 0;
            }
            ready = ok;
        }
    } else {
        ctrl->timer--;
        ready = ctrl->timer == 0;
    }

    if (ready) {
        while (1) {
            ctrl->idx++;
            entry = &ctrl->entries[ctrl->idx];
            switch (entry->cmd) {
            case -2:
                func_01B06768(ctrl, entry->arg);
                continue;
            case -3:
                Ch_MotionSetNextHokan(ctrl->unk0C, 0);
                continue;
            case -4:
                func_01B05528(ctrl->unk04);
                continue;
            case -1:
                frames = 1;
                break;
            default:
                switch (ctrl->mode) {
                case 0:
                    frames = func_001CE050(ctrl->unk08, entry->cmd);
                    break;
                case 1:
                    Ch_ResetMotion(ctrl->unk0C);
                    Ch_SetSequence(ctrl->unk0C, entry->cmd);
                    frames = Ch_GetSeqFrame(ctrl->unk0C);
                    break;
                case 2:
                    Ch_ResetMotion(ctrl->unk0C);
                    Ch_SetSysMotion(ctrl->unk0C, 1, entry->cmd);
                    frames = Ch_GetSeqFrame(ctrl->unk0C);
                    break;
                default:
                    frames = 1;
                    break;
                }
                break;
            }
            break;
        }

        switch (entry->arg) {
        case -1:
            func_01B06770(ctrl, 0);
            break;
        case -2:
            ctrl->timer = 0;
            ctrl->unk1A = 0;
            break;
        case -3:
            func_01B06770(ctrl, 1);
            break;
        case -4:
            ctrl->done = 1;
            break;
        case -5:
            func_01B06770(ctrl, 3);
            break;
        case -6:
            func_01B06770(ctrl, 2);
            break;
        case -7:
            if (frames <= 0) {
                s32 mode = ctrl->mode;
                if (mode == 0) {
                    frames = func_001CE050(ctrl->unk08, 0x10);
                    if (frames <= mode) {
                        frames = 1;
                    }
                } else {
                    frames = 1;
                }
            }
            ctrl->timer = frames;
            ctrl->idx--;
            break;
        default:
            ctrl->timer = entry->arg;
            break;
        }
    }

    return ctrl->done;
}
