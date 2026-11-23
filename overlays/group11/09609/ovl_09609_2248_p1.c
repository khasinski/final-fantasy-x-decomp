#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} Qword;

typedef struct {
    s32 count;
    u8 *data;
} ReelTbl;

typedef struct {
    ReelTbl *tbl;
    s32 pos;
    s32 speed;
    s32 timer;
    s32 target;
    s32 unk14;
    s32 state;
} Reel;

typedef struct {
    Reel reels[3];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 state;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    float unk78;
} ReelGroup;

typedef struct {
    ReelGroup groups[4];
    s32 unk1F0[4];
    s32 cur_idx;
    s32 count;
    s32 state;
} SlotMgr;

extern u64 D_006F2CE0[];
extern s32 D_01B00AF0[];
extern s32 D_01B0DEA8;
extern SlotMgr D_01B0DF88;
extern s32 D_01B0E194;
extern u8 D_01C03DD0[];

extern void MsSetReelResult(s32, u8 *, float, float);
extern void TOBtlInitLimitTimer(void);
extern void func_0021A7A8(s32, s32);
extern void func_0021A7C0(float);
extern void TOBtlStartLimitTimer(void);
extern void TOBtlStopLimitTimer(void);
extern void TOBtlStandbyLimitTimer(void);
extern void TOBtlClearLimitTimer(void);
extern float func_0021AA78(void);
extern void TOBtlStartWakkaSuccessAnm(void);
extern s32 func_0021BC98(void);
extern void func_002B2F18(s32);
extern void func_002DA610(s32, s32);
extern void *func_002DB6D8(s32);
extern void func_002DBA28(void *, void *);
extern void func_01B02168(SlotMgr *);
extern void func_01B095C0(void *, s32, s32, s32);
extern s32 func_01B0AB60(s32);
extern float func_01B0AC08(float, float, float, float, float, float);

void func_01B02900(void);

void func_01B02248(ReelGroup *grp) {
    Reel *r = grp->reels;
    s32 i;
    for (i = 0; i < 3; i++, r++) {
        r->speed = 0;
        r->timer = 20;
        r->state = 1;
    }
}

s32 func_01B02280(ReelGroup *grp) {
    Reel *r = grp->reels;
    s32 i;
    s32 done = 0;
    s32 stopped = 0;

    for (i = 0; i < 3; i++, r++) {
        switch (r->state) {
        case 0:
            done++;
            break;
        case 1:
            r->timer--;
            if (r->timer <= 0) {
                r->speed = grp->unk54;
                r->state = 2;
            } else {
                s32 d = 20;
                r->speed = (grp->unk54 * (d - r->timer)) / d;
            }
            r->pos -= r->speed;
            break;
        case 2:
            {
                s32 trig = 0;
                if (grp->unk64 == i) {
                    s32 pad = func_01B0AB60(0);
                    float rem = func_0021AA78();
                    if ((pad & 0x20) || rem == 0.0f) {
                        func_01B095C0(D_01C03DD0, 0, 0x40, 0x100);
                        trig = 1;
                        r->state = 3;
                    }
                }
                if (trig == 0) {
                    r->pos -= r->speed;
                    break;
                }
            }
            /* fallthrough */
        case 3:
            {
                s32 frac = r->pos & 0xFFFF;
                s32 base;
                if (r->speed < frac) {
                    r->pos -= r->speed;
                    break;
                }
                base = r->pos - frac;
                r->pos = base;
                r->target = base;
                r->timer = 8;
                r->state = 4;
                stopped = 1;
            }
            /* fallthrough */
        case 4:
            r->timer--;
            if (r->timer <= 0) {
                r->speed = 0;
                r->pos = r->target;
                r->state = 0;
            } else {
                r->pos = r->target + D_01B00AF0[r->timer];
            }
            break;
        }
        if (r->pos < 0) {
            r->pos += r->tbl->count << 16;
        }
    }

    if (stopped == 1) {
        grp->unk64++;
    }
    return done >= 3;
}

s32 func_01B024A8(Reel *r) {
    s32 idx = *(s16 *)((u8 *)&r->pos + 2) + 1;
    if (idx >= r->tbl->count) {
        idx = 0;
    }
    return r->tbl->data[idx];
}

s32 func_01B024D0(ReelGroup *grp) {
    Reel *r = grp->reels;
    s32 i;
    s32 sym;
    s32 match = 1;

    sym = func_01B024A8(r);
    for (i = 1; i < 3; i++) {
        r++;
        if (sym != func_01B024A8(r)) {
            match = 0;
            break;
        }
    }
    grp->unk70 = match;
    return match;
}

s32 func_01B02550(SlotMgr *mgr) {
    ReelGroup *grp = &mgr->groups[mgr->cur_idx];
    s32 ret = 0;

    switch (grp->state) {
    case 0:
        grp->unk60--;
        if (grp->unk60 <= 0) {
            TOBtlInitLimitTimer();
            func_0021A7C0(20.0f);
            func_0021A7A8(0x138, 0x81);
            TOBtlStandbyLimitTimer();
            TOBtlStartLimitTimer();
            grp->unk58 = 0xA6;
            func_01B02248(grp);
            grp->state = 1;
        } else {
            float t = func_01B0AC08(0.0f, -0.05f, -0.1f, 0.2f, 1.0f, (float)grp->unk60 / 15.0f);
            grp->unk58 = (s32)((1.0f - t) * 166.0f + t * 512.0f);
        }
        break;
    case 1:
        if (func_01B02280(grp) == 1) {
            TOBtlStopLimitTimer();
            grp->unk78 = func_0021AA78();
            if (func_01B024D0(grp) == 1) {
                func_01B095C0(D_01C03DD0, 1, 0x40, 0x100);
                TOBtlStartWakkaSuccessAnm();
                grp->unk60 = 1;
            } else {
                grp->unk60 = 5;
            }
            grp->state = 2;
        }
        break;
    case 2:
        if (grp->unk70 == 1) {
            if (func_0021BC98() == 0) {
                break;
            }
        }
        grp->unk60--;
        if (grp->unk60 <= 0) {
            TOBtlClearLimitTimer();
            grp->unk60 = 10;
            grp->state = 3;
        }
        break;
    case 3:
        grp->unk60--;
        if (grp->unk60 <= 0) {
            grp->unk74 = 0;
            grp->unk6C = 8;
            grp->unk58 = 0xB5;
            grp->state = 4;
        } else {
            float t = func_01B0AC08(0.0f, 0.6f, 0.9f, 0.999f, 1.0f, (float)grp->unk60 / 10.0f);
            grp->unk58 = (s32)((1.0f - t) * -231.0f + t * 166.0f);
        }
        break;
    case 4:
        ret = 1;
        break;
    }

    return ret;
}

s32 func_01B02818(void) {
    SlotMgr *mgr = &D_01B0DF88;

    switch (mgr->state) {
    case 0:
        func_01B02168(mgr);
        mgr->state = 1;
        break;
    case 1:
        if (func_01B02550(mgr) == 1) {
            mgr->cur_idx++;
            if (mgr->cur_idx < mgr->count) {
                mgr->state = 0;
            } else {
                mgr->state = 2;
            }
        }
        break;
    case 2:
        func_01B02900();
        if (D_01B0E194 != -1) {
            func_002B2F18(D_01B0E194);
            D_01B0E194 = -1;
        }
        return 1;
    }
    return 0;
}

void func_01B02900(void) {
    u8 res[12];
    SlotMgr *mgr = &D_01B0DF88;
    ReelGroup *g;
    u8 *p;
    s32 i, j;

    for (i = 0; i < 12; i++) {
        res[i] = 0xFF;
    }

    g = mgr->groups;
    for (i = 0; i < mgr->count; i++, g++) {
        Reel *r = g->reels;
        s32 idx = mgr->unk1F0[i] * 3;
        for (j = 0; j < 3; j++, r++, idx++) {
            res[idx] = func_01B024A8(r);
        }
    }

    MsSetReelResult(D_01B0DEA8, res, mgr->groups[0].unk78, 20.0f);
}

void func_01B02A10(void) {
    void *ch;
    Qword *p;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = 0x0003000DULL;
    p->d[1] = 0x47ULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}

void func_01B02AA0(void) {
    void *ch;
    Qword *p;

    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (Qword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;

    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0xEULL;
    p++;

    p->d[0] = D_006F2CE0[12];
    p->d[1] = 0x47ULL;

    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
