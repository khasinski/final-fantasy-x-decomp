#include "iopsound.h"

typedef struct Voice {
    void *trk;          /* 0x00 */
    u8 pad04[0x48];
    volatile u32 flags4C; /* 0x4C */
    u8 pad50[0x18];
    u32 unk68;          /* 0x68 */
    u8 pad6C[0x08];
} Voice; /* size 0x74 = 116 */

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0xD4];
    s32 rand_scale;     /* 0x0D8 */
    u8 pad0DC[0x0C];
    u32 flagsE8;        /* 0x0E8 */
    u8 pad0EC[0x04];
    u32 flagsF0;        /* 0x0F0 */
    s32 wait_cnt;       /* 0x0F4 */
    u8 pad0F8[0x28];
    s16 gate_add;       /* 0x120 */
    u8 pad122[0x0A];
    u16 cmd_cnt;        /* 0x12C */
    s16 tick_acc;       /* 0x12E */
    u8 pad130[0x07];
    u8 voice_idx;       /* 0x137 */
    u8 pad138[0x04];
} Track; /* size 0x13C = 316 */

typedef struct SeqCtrl {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x374];
    s32 unk378;         /* 0x378 */
    u8 pad37C[0x0E];
    s16 unk38A;         /* 0x38A */
} SeqCtrl;

extern s32 D_019328;
extern u32 D_0193A0;
extern u32 D_01933C;
extern Voice *D_0192F0;
extern u32 D_01931C;
extern void (*D_017500[])(SeqCtrl *, void *, Track *);

extern void func_005BFC(Track *, s32);
extern void func_002E70(void *, Track *);
extern void func_00F0D4(s32);
extern s32 func_006118(Track *);
extern s32 func_009330(void);

s32 func_006954(SeqCtrl *ctrl, void *arg1, Track *trk, s32 step) {
    do {
        if (trk->ptr != NULL && (trk->flagsE8 & 8) == 0) {
            trk->tick_acc -= (u16)D_019328;
            if (trk->tick_acc <= 0) {
                do {
                    s32 w;
                    s32 d;
                    s32 r;

                    D_0193A0 = 0;
                    D_01933C = 0;
                    trk->tick_acc += 300;
                    w = trk->wait_cnt;
                    d = step;
                    if (w < d) {
                        d = w;
                    }
                    trk->wait_cnt = w - step;
                    func_005BFC(trk, d);

                    if ((trk->flagsF0 & 0x200000) == 0 && trk->wait_cnt == 1) {
                        func_002E70(arg1, trk);
                    }

                    while (trk->ptr != NULL && trk->wait_cnt <= 0) {
                        s32 cmd;
                        s32 dt;

                        trk->cmd_cnt++;
                        cmd = *trk->ptr++;
                        if (cmd & 0x80) {
                            cmd = 0;
                            func_00F0D4(28);
                        }
                        D_017500[cmd](ctrl, arg1, trk);
                        if (trk->ptr == NULL) {
                            break;
                        }
                        dt = func_006118(trk);
                        if (dt != 0) {
                            dt += trk->gate_add;
                            if (dt <= 0) {
                                dt = 1;
                            } else if (trk->flagsE8 & 0x20000) {
                                s32 t = dt * trk->rand_scale;
                                r = t >> 8;
                                r *= (s8)func_009330();
                                r >>= 7;
                                dt += r;
                                if (dt <= 0) {
                                    dt = 1;
                                }
                            }
                        }
                        if (trk->wait_cnt < -1) {
                            s32 adj = dt;
                            if (trk->wait_cnt + dt > 0) {
                                adj = -trk->wait_cnt;
                            }
                            func_005BFC(trk, adj);
                        }
                        trk->wait_cnt += dt;
                    }

                    if ((D_01933C | D_0193A0) != 0) {
                        u32 f = trk->flagsE8;
                        D_0192F0[trk->voice_idx].unk68 |= D_0193A0;
                        D_0192F0[trk->voice_idx].flags4C &= 3;
                        r = f & ~3;
                        D_0192F0[trk->voice_idx].flags4C |= r;
                        (*(volatile u32 *)&D_01931C) |= 1;
                    }
                } while (trk->tick_acc <= 0);
            }
        }
        trk++;
    } while (trk < ctrl->tracks + 24);

    ctrl->unk378 = 1;
    return ctrl->unk38A;
}
