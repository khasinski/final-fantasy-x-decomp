#include "common.h"

typedef struct SeqEntry {
    int mot;                /* 0x00 */
    int end_frame;          /* 0x04 */
    void (*cb)(int);        /* 0x08 */
    int cb_arg;             /* 0x0C */
} SeqEntry;

typedef struct SeqCtrl {
    SeqEntry *tbl;          /* 0x00 */
    int chr;                /* 0x04 */
    int idx;                /* 0x08 */
    int seq_frame;          /* 0x0C */
} SeqCtrl;

extern void Ch_SetSysMotion(int, int, int);
extern int Ch_GetSeqFrame(int);
extern int func_00111B50(int);
extern void Ch_ResetMotion(int);

void func_01B03858(SeqCtrl *s0)
{
    SeqEntry *tbl = s0->tbl;
    int done;

    if (tbl[s0->idx].mot == 0) {
        return;
    }

    if (s0->seq_frame == 0) {
        Ch_SetSysMotion(s0->chr, 1, tbl[s0->idx].mot);
        s0->seq_frame = Ch_GetSeqFrame(s0->chr);
        if (s0->seq_frame == -1) {
            while (tbl[s0->idx].mot != 0) {
                s0->idx++;
            }
        }
    }

    {
        SeqEntry *e = (SeqEntry *)((s0->idx << 4) + (u32)tbl);
        if (e->end_frame == 0) {
            done = s0->seq_frame == (func_00111B50(s0->chr) >> 8) + 1;
        } else {
            done = e->end_frame == (func_00111B50(s0->chr) >> 8) + 1;
        }
    }

    if (done) {
        s0->idx++;
        if (tbl[s0->idx].mot == 0) {
            return;
        }
        Ch_ResetMotion(s0->chr);
        Ch_SetSysMotion(s0->chr, 1, tbl[s0->idx].mot);
        s0->seq_frame = Ch_GetSeqFrame(s0->chr);
    }

    if (tbl[s0->idx].cb != 0) {
        tbl[s0->idx].cb(tbl[s0->idx].cb_arg);
    }
}
