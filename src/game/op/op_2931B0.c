/* tu_314 0x2931b0-0x294cd8: medium; ~op (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#define func_002B21E0 _hdr_func_002B21E0
#define TkGetControlerHist _hdr_TkGetControlerHist
#define func_00293740 _hdr_func_00293740
#define op_deg_get _hdr_op_deg_get
#define func_002D41E8 _hdr_func_002D41E8
#include "common.h"
#include "vu0.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/r6.h"
#include "ffx/t6.h"
#include "ffx/g4.h"
#include "ffx/q7.h"
#undef func_002B21E0
#undef TkGetControlerHist
#undef func_00293740
#undef op_deg_get
#undef func_002D41E8

extern int D_003730F8[];
extern int D_00551BD0;
extern int D_00551BD4;
extern int D_003F3944;
extern int D_003F394C;
extern int D_003F3950;

void func_002B21E0(void *a, int b);
int TkGetControlerHist(s32 a, s32 b, s32 c);
void op_pad_set(int a, int b, int c);
void func_002B2298(void);
void opu_debug_check(void);
void func_2058390(void);

void func_002B3708(void);
void func_002CEFF0(void);
void func_00294038(void);
void func_00293E08(void);
void SndStandbySepWave(void);
int func_00294188(R6W8 *o, int flags);

extern s32 D_003730F0;
extern u8 D_004F8620[];
extern char D_005744B0[];
void ops_init_work(void);
void func_206B608(void);
void func_206A6B0(void);
void func_002B1E08(void);
void func_002B22F8(s32, s32);
void func_00124690(s32);
void func_002B4220(s32);
void func_2069D88(void);
void opu_et_init(void);
void opu_test_data_read(s32);
void op_et_battle_init(s32);
void func_00297578(s32);
void func_002B4340(void);
void func_002B41B0(char *);
void func_002B4390(s32, s32);
void func_002B4520(s32);
void func_002B42E0(s32);
void func_002B45E0(void);
void func_206C380(void);
void op_et_tex_load_triger(s32);

typedef struct {
    u8 pad00[0xD];
    s8 b0D;
    u8 pad0E[2];
    s8 b10;
    u8 pad11[3];
    s8 b14;
    u8 pad15[7];
    s32 w1C;
    u8 pad20[0x1F];
    s8 b3F;
    u8 pad40[4];
    s8 b44;
} OpInitWork;

typedef struct {
    s32 w00;
    s32 w04;
    void *p08;
} OpInit703E20;

void op_init_ffx(void)
{
    u8 *d2 = (u8 *)&D_2008250;

    if (D_003730F0 != 0) {
        return;
    }
    D_003730F0 = 1;
    ops_init_work();
    if (FFXIsDebug() != 0) {
        s32 v = func_0011A428();
        if (v == 1 || v == 2) {
            func_206B608();
            ((OpInitWork *)&D_00764990)->b44 = 1;
        } else {
            func_206A6B0();
            ((OpInitWork *)&D_00764990)->b44 = 0;
        }
    } else {
        ((OpInitWork *)&D_00764990)->b10 = 0;
    }
    func_002B1E08();
    if (((OpInitWork *)&D_00764990)->b14 != 0) {
        ((OpInitWork *)&D_00764990)->b10 = 0;
    }
    func_002B22F8(0x3400, 0xC00);
    func_002EFD68(0x3F4CF27B);
    {
        register u32 seed __asm__("$2") = 0xBFBFBFBFU;
        VU0_QMTC2_NI(31, seed);
        VU0_OP("vrinit R, $vf31x");
    }
    {
        register s32 b10 __asm__("$3") = ((OpInitWork *)&D_00764990)->b10;
        if (b10 != 0) {
            if (*(s8 *)(d2 + 8) != 0) {
                ((OpInitWork *)&D_00764990)->b3F = 1;
                func_00124690(0);
            }
            if (*(s8 *)(d2 + 2) != 0) {
                func_002B4220(*(s16 *)(d2 + 0x42) << 8);
            }
            func_2069D88();
        }
    }
    if (((OpInitWork *)&D_00764990)->b14 == 0) {
        register void (*fn)(s32) __asm__("$2");
        register s32 b10_2 __asm__("$2");
        opu_et_init();
        fn = *(void (**)(s32))&D_003737A0;
        fn(0);
        ((OpInit703E20 *)&D_00703E20)->p08 = D_004F8620;
        b10_2 = ((OpInitWork *)&D_00764990)->b10;
        if (b10_2 != 0) {
            register s32 b0d __asm__("$3");
            opu_test_data_read(0);
            b0d = ((OpInitWork *)&D_00764990)->b0D;
            if (b0d != 0) {
                if (*(u16 *)(d2 + 0x40) & 1) {
                    s32 v = *(s32 *)(d2 + 0x80);
                    ((OpInit703E20 *)&D_00703E20)->w00 = v;
                    op_et_battle_init(v);
                }
                if (*(u16 *)(d2 + 0x40) & 0x20) {
                    ((OpInit703E20 *)&D_00703E20)->p08 = *(void **)(d2 + 0x98);
                }
            }
        }
        func_00297578((s32)((OpInit703E20 *)&D_00703E20)->p08);
    }
    if (((OpInitWork *)&D_00764990)->w1C != 0) {
        func_002B4220(0x3000);
        func_002B4340();
        func_002B41B0(D_005744B0);
        func_002B4390(0x10, 0x10);
        func_002B4520(0x70000000);
        func_002B42E0(0);
        func_002B4580(0);
        func_002B45E0();
    }
    if (((OpInitWork *)&D_00764990)->b10 != 0) {
        func_206C380();
    }
    if (((OpInitWork *)&D_00764990)->b14 != 0) {
        *(s16 *)(d2 + 0x42) = 0x2C00;
        func_002B4220(0x2C0000);
        op_et_tex_load_triger(0);
        func_002D09D0(0);
    }
}

void ops_init_work(void)
{
    s8 primary;
    u8 *p;
    int i;
    char *name;

    if (FFXIsPC() != 0) {
        primary = D_00764990.primary;
    } else {
        primary = 0;
    }
    func_002EF0D0(&D_00764990, 0, 0xA0);
    D_00764990.primary = primary;
    D_00764990.mode15 = 1;
    func_002B37C0();
    func_002EF0D0(&D_00703E20, 0, 0x100);
    p = &D_00703E20.flags[3];
    for (i = 3; i >= 0; i--, p--) {
        *p = 0xFF;
    }
    func_0029A1A8();
    func_0029A3A0();
    func_00298708();
    func_002EF0D0(&D_00703FF0, 0, 0x40);
    D_00703FF0.b[3] = 1;
    D_00703FF0.b[6] = 1;
    D_00703FF0.b[4] = 1;
    func_00299AD8();
    func_002B3708();
    func_002CEFF0();
    func_00294038();
    func_00293E08();
    name = (char *)Sg_GetUserName();
    D_00764990.pad0[0xD] = 0;
    if (name != 0) {
        for (i = 0; i < 7; i++) {
            if (D_003730F8[i] != *name) {
                return;
            }
            name++;
        }
        D_00764990.pad0[0xD] = 1;
    }
}

void func_00293570(void)
{
    HwRegs2008250 *hw = &D_2008250;

    /* DEBT(FAKE): (&D_00764990)-> keeps the base address in a register like the original */
    if ((&D_00764990)->mirror != 0 && hw->b2 != 0) {
        func_002B4340();
    }
    if ((&D_00764990)->primary != 0) {
        func_002B4340();
    }
}

typedef struct OpDbuffQ16 { u64 q[16]; } OpDbuffQ16;

typedef struct OpDbuffBlk {
    u8 pad0[0x60];
    OpDbuffQ16 a;
    u8 padE0[0x1D0 - 0xE0];
    OpDbuffQ16 b;
} OpDbuffBlk; /* DEBT(NAME): Sg_GetDBuffDC return block */

typedef struct OpDbuffLocal {
    u8 pad0[0x60];
    OpDbuffQ16 a;
    u8 padE0[0x150 - 0xE0];
    OpDbuffQ16 b;
    u8 pad1D0[0x230 - 0x1D0];
} OpDbuffLocal; /* DEBT(NAME): local copy of Sg_GetDBuffDC buffers */

void op_loop_ffx_after(void)
{
    OpDbuffLocal local;
    s32 dc;
    OpDbuffBlk *blk;

    D_00551BD0++;
    D_00551BD4++;
    blk = (OpDbuffBlk *)Sg_GetDBuffDC(&dc);
    local.a = blk->a;
    local.b = blk->b;
    func_002B21E0(&local, dc & 1);
    op_pad_set(0, 0, TkGetControlerHist(0, 0, 0) & 0xFFFF);
    op_pad_set(1, 0, TkGetControlerHist(1, 0, 0) & 0xFFFF);
    func_002B2298();
    D_003F3944 = D_003F3940;
    D_003F3950 = D_003F394C;
    if ((s8)(&D_00764990)->pad0[0x10] != 0) {
        opu_debug_check();
        if ((s8)(&D_00764990)->pad0[0x10] != 0) {
            func_2058390();
        }
    }
}

extern s16 D_00551C90;
extern void *D_00764AD8;
extern int D_003F3940;
extern char D_005744B8[];
extern char D_005744C8[];
extern char D_005744D8[];
extern char D_005744F0[];
extern char D_00574508[];
extern char D_00574520[];
extern char D_00574538[];
extern char D_00574550[];
extern char D_00574568[];
extern char D_00574578[];
void func_002D41F0(int);
int TkGetSyncH(int);
int func_002D41E8(int);
int func_00293CD8(u8 *p);
void func_2068188(void);
void func_2068988(void);
void func_2069078(void);
void func_206C488(void);
void func_20694D0(void);
int func_0020D540(void);
int op_oef2_sound_cue_check(int);
int func_002D0570(int);
void TODapsSetPos(int, int);
void TODapsString(char *);
void func_2058398(void);

void func_00293740(void)
{
    char buf[0x400];
    s8 *hw = (s8 *)&D_2008250;

    if ((s8)(&D_00764990)->pad0[0x10] != 0) {
        int *q;
        s16 sync;

        func_002D41F0(3);
        sync = TkGetSyncH(3);
        D_00551C90 = sync;
        func_002D41E8(3);
        ((int (*)(int, int, int))func_206C3F8)(func_00293CD8((u8 *)D_00764AD8), 0x60000, 0x800);
        q = (int *)&D_006F2CB0;
        {
            /* DEBT(FAKE): register pins fix a1/v0/s2 allocation for diff */
            register int q2 __asm__("$5") = q[2];
            register int q1 __asm__("$2") = q[1];
            register int diff __asm__("$18");
            register int sign __asm__("$5");
            __asm__("" : "+r"(q2), "+r"(q1));
            diff = q2 - q1;
            sign = (u32)diff >> 31;
            ((int (*)(int, int, int))func_206C3F8)(q[3], (diff + sign) >> 1, 0x801);
        }
        ((int (*)(int, int, int))func_206C3F8)(D_003F3944 - D_003F3940, 0xC0000, 0x802);
        if (hw[1] != 0) {
            if ((s8)(&D_00764990)->pad0[0xC] == 0) {
                if (hw[3] != 0) {
                    func_2068188();
                    func_2068988();
                }
                func_2069078();
                func_206C488();
            } else {
                if ((u8)hw[9] & 1) {
                    func_2069078();
                }
                if ((u8)hw[9] & 2) {
                    func_206C488();
                }
            }
        } else {
            if ((u8)hw[9] & 1) {
                func_2069078();
            }
            if ((u8)hw[9] & 2) {
                func_206C488();
            }
        }
        if ((&D_00764990)->pad0[0x44] == 1) {
            func_20694D0();
        }
    }
    if (D_00703FF0.b[0xA] != 0 && func_0020D540() != 0) {
        register char *p __asm__("$17");
        int cue;

        p = buf + func_002F0008(buf, D_005744B8);
        cue = op_oef2_sound_cue_check(0xFFFF);
        if (cue != 0) {
            p += func_002F0008(p, D_005744C8);
            p += func_002F0008(p, D_005744D8, D_006EA790.count);
            p += func_002F0008(p, D_005744F0, *(s8 *)D_006EA790.pad104);
            if (cue & 0x1000) {
                if (cue & 1) {
                    p += func_002F0008(p, D_00574508);
                } else {
                    p += func_002F0008(p, D_00574520);
                }
            } else if (cue & 0x2000) {
                if (cue & 1) {
                    p += func_002F0008(p, D_00574538);
                } else {
                    p += func_002F0008(p, D_00574550);
                }
            }
        }
        if (func_002D0570(0xFFFF) != 0) {
            p += func_002F0008(p, D_00574568);
        }
        if (D_00703FF0.b[1] != 0) {
            func_002F0008(p, D_00574578);
        }
        TODapsSetPos(0x10, 0x28);
        TODapsString(buf);
    }
    if ((s8)(&D_00764990)->pad0[0x10] != 0) {
        func_2058398();
    }
}

#ifndef MMI_SQ_ZERO
#define MMI_SQ_ZERO(off, p) __asm__ volatile("sq $0, " #off "(%0)" : : "r"(p) : "memory")
#endif

typedef struct OpHeapSeg {
    u8 *start;
    u8 *end;
    union {
        struct {
            s16 prev;
            s16 next;
        } s;
        s32 link;
    } u;
    s16 max_idx;
    u16 count;
} OpHeapSeg;

u8 *op_heap_init(u8 *buf, int size)
{
    int off;
    u8 *end;

    if (size == 0) {
        return 0;
    }
    for (off = size - 0x10; off >= 0; off -= 0x10) {
        *(u_long128 *)(buf + off) = 0;
    }
    end = buf + size;
    MMI_SQ_ZERO(-0x10, end);
    MMI_SQ_ZERO(-0x20, end);
    *(u8 **)(end - 0xC) = buf;
    *(u8 **)(end - 0x10) = buf;
    return end;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2931B0", op_malloc);

INCLUDE_ASM("build/ee_asm/game/op/op_2931B0", op_free);

int func_00293CD8(u8 *p)
{
    int n = ((u16 *)p)[-1];
    V6Seg *e;
    int total = 0;
    int i;
    int k;

    if (n == 0) {
        return 0;
    }
    e = (V6Seg *)(p - 0x20);
    for (i = 0; i < n; i++) {
        total += e->end - e->start;
        k = e->next;
        if (k == 0) {
            break;
        }
        e = (V6Seg *)(p - k * 16);
    }
    return total;
}

void func_00293D48(int a, int b) {
    if (D_007649A0 != 0) {
        func_206C3B8(b);
        func_206C440(a, b);
    }
}

void func_00293DA8(void) {
    if (D_007649A0 != 0) {
        func_206C3F8();
    }
}

void func_00293DC8(int a) {
    if (D_007649A0 != 0) {
        func_206C3B8(a);
    }
}

void func_00293DE8(void) {
    if (D_007649A0 != 0) {
        func_206C380();
    }
}

void func_00293E08(void)
{
    V6Env *e = &D_00703FA0;
    int unused[4]; /* DEBT(PADDING): the original reserves a 16-byte frame */

    e->v20[1] = 0.0f; /* DEBT(ORDER): first store moved to reproduce the schedule */
    e->v20[0] = 8.0f;
    e->v20[2] = -32.0f;
    e->v20[3] = 128.0f;
    e->v30[0] = 0.0f;
    e->v30[1] = 255.0f;
    e->v30[2] = 0.0f;
    e->v30[3] = 255.0f;
    e->v40[0] = 0.0f;
    e->v40[1] = 0.0f;
    e->v40[2] = 128.0f;
    e->v40[3] = 128.0f;
}

void func_00293E70(void)
{
    V6Env *e = &D_00703FA0;
    int rgb[8]; /* DEBT(PADDING): 3 used, the original buffer is 0x20 bytes */

    func_00173888(rgb);
    e->col[0] = rgb[0];
    e->col[1] = rgb[1];
    e->col[2] = rgb[2];
    func_00173828(&e->f4, &e->f8, &e->fC);
    e->f1C = 255.0f;
    e->f18 = -e->f4;
    e->f14 = 255.0f - e->fC;
    e->f10 = -(255.0f / (e->f8 - e->f4));
}

void op_et_tex_load_triger(int on)
{
    ResEntry *e;
    int i;
    u8 unused[0x340]; /* DEBT(PADDING): the original frame has an unused 0x340-byte local */

    D_00703FF3 = on;
    e = owu_chr_status;
    if (on) {
        for (i = 0; i < 208; i++, e++) {
            if (e->chr != 0 && e->hE < 0xF0) {
                owu_chr_drawoff_back[e->hE] &= ~2;
            }
        }
    } else {
        for (i = 0; i < 208; i++, e++) {
            if (e->chr != 0 && e->hE < 0xF0) {
                owu_chr_drawoff_back[e->hE] |= 2;
            }
        }
    }
}

void opd_exit_from_ovl(void) {
    op_oef2_tex_clut_ovl_clear(0xFFFFFFFF);
}

void func_00293FD8(int a)
{
    char buf[1024];

    func_002F0008(buf, D_005745E0, a);
    AtelPs2DebugString(buf);
}

void op_dvd_debug_print2(int a)
{
    char buf[1024];

    func_002F0008(buf, D_005745E0, a);
    func_0014D7B8(buf);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2931B0", func_00294038);

int func_00294130(R6W8 *o) {
    int i;
    int key;

    if ((u32)o->p8 <= 0x100000) {
        return 0;
    }
    key = o->p8[2];
    for (i = 0; i < 32; i++) {
        if (D_006EA550[i].w0 == key) {
            return 1;
        }
    }
    return 0;
}

int func_00294180(void) {
    return 0;
}

int func_00294188(R6W8 *o, int flags)
{
    R6Ent8 *e;
    int *p;
    int i;
    int h;

    if (func_00294130(o) == 0) {
        p = o->p8;
        e = D_006EA550;
        for (i = 0; i < 32; i++, e++) {
            if (e->w0 == 0) {
                e->w0 = p[2];
                e->w4 |= flags;
                SndSepTransSepOnly(p, p[3]);
                goto done; /* DEBT(GOTO): break gives a different loop layout */
            }
        }
    done:
    }
    h = o->hC;
    if (h <= 0) {
        return 0;
    }
    SndStandbyBattleWave(h, func_002D8040((W11Grid *)h)); /* DEBT(CAST): handle doubles as grid pointer */
    return 1;
}

void op_oef2_sep_wave_load_all(T6_ResHdr *res, int flags)
{
    int n = res->count;
    int i;
    R6W8 *o;

    for (i = 0; i < n; i++) {
        o = op_oef2_a_get((int)res, 6, i); /* DEBT(CAST): op_oef2_a_get takes the header as int */
        if (o != 0) {
            func_00294188(o, flags);
        }
    }
}

void func_002942B8(PtrHolder8 *ent, int ch)
{
    IntBox *p;

    if (ent != 0) {
        p = ent->p8;
        if (ent->type == 2) {
            D_00704013 = 1;
            if (ch == 0) {
                V6_D76F0((int)p, 0);
                D_006EA8A0[0] = ent;
            } else {
                V6_D76F0(0, (int)p);
                D_006EA8A0[1] = ent;
            }
        }
    }
}

void op_oef2_sep_free_all(int flags)
{
    R6Ent8 *e = D_006EA550;
    int i;
    int rest;
    int key;

    for (i = 0; i < 32; i++, e++) {
        if (e->w4 & flags) {
            e->w4 &= ~flags;
            rest = e->w4;
            if (rest == 0) {
                key = e->w0;
                SndSepStop(key);
                SndSepClear(key);
                e->w0 = 0;
            }
        }
    }
}

/* NAME guess: read field of heap object, -1 if pointer is not a valid address */
int func_002943B8(PtrHolder8 *h) {
    if ((u32)h->p8 <= 0x100000) {
        return -1;
    }
    return h->p8->v8;
}

int func_002943E0(PtrHolderC *h) {
    if ((u32)h->pC <= 0x100000) {
        return -1;
    }
    return h->pC->v2;
}

int func_00294408(QueueReq *ent, int arg)
{
    PtrSlots *q = &D_006EA790;
    u16 count = q->count;
    int idx;

    if (count >= 32 || ent->type != 1) {
fail:
        return -1;
    }
    if (ent->w8 == 0) {
        goto fail; /* DEBT(GOTO): shares early return block across second check */
    }
    q->count = count + 1;
    idx = (q->head + count) & 0x1F;
    q->objs[idx] = ent;
    q->args[idx] = arg;
}

int op_oef2_stream_cue(R6TypedObj *o, int i) {
    if (o->type != 2) {
        return -1;
    }
    if (D_006EA790.slot[i & 1] != 0) {
        return -1;
    }
    D_006EA790.slot[i & 1] = o;
    return 0;
}

int op_oef2_sound_cue_multi(T6_ResHdr *res, u16 from, u16 to, int arg)
{
    u16 end;
    int i;
    QueueReq *p;

    if (res->count == 0) {
        return 0;
    }
    end = to + 1;
    if (end >= res->count) {
        end = res->count;
    }
    for (i = from; i < end; i++) {
        p = op_oef2_a_get((int)res, 6, i); /* DEBT(CAST): op_oef2_a_get takes the header as int */
        if (p != 0 && p->type == 1) {
            func_00294408(p, arg);
        }
    }
}

int op_oef2_sound_cue_check(int unused)
{
    PtrSlots *q = &D_006EA790;
    u16 n = 0;

    if (q->slot[0] != 0) {
        if (q->slot[0] != (void *)-1) {
            return 0x2000;
        }
        if (T6_D85A8(0)) {
            return 0x1000;
        }
        q->slot[0] = 0;
    }
    if (q->slot[1] != 0) {
        if (q->slot[1] != (void *)-1) {
            return 0x2001;
        }
        if (T6_D85A8(0)) {
            return 0x1001;
        }
        q->slot[1] = 0;
    }
    if (q->count != 0) {
        n = q->count;
    }
    return n;
}

int func_00294618(void) {
    return 0;
}

void op_oef2_sound_cue_trans(int a) {
    while (op_oef2_sound_cue_check(a)) {
        op_oef2_sound_cue_loop();
    }
}

void op_oef2_sound_cue_loop(void)
{
    PtrSlots *q = &D_006EA790;
    s8 state;
    int idx;
    R6W8 *obj;

    if (q->count != 0) {
        state = *(s8 *)q->pad104;
        if (state == 2) {
            if (SndSyncTrans(0) != 0) {
                return;
            }
            *(s8 *)q->pad104 = 3;
            SndStandbySepWave();
            return;
        }
        if (state == 3) {
            if (SndSyncWaveTrans(0) != 0) {
                return;
            }
            *(s8 *)q->pad104 = 0;
            q->head++;
            if (--q->count != 0) {
                goto do_next;
            }
            goto check_slots;
        }
        if (state != 1) {
        do_next:
            *(s8 *)q->pad104 = 2;
            idx = q->head & 0x1F;
            obj = q->objs[idx];
            if (obj == 0) {
                return;
            }
            if (func_00294188(obj, q->args[idx]) == 0) {
                *(s8 *)q->pad104 = 3;
            }
            return;
        }
        *(s8 *)q->pad104 = 2;
        return;
    }
check_slots:
    if (q->slot[0] != 0) {
        if (q->slot[0] != (void *)-1) {
            ((void (*)(void *, int, int))func_002942B8)(q->slot[0], 0, 0); /* DEBT(CAST): caller passes an unused 3rd arg */
            q->slot[0] = (void *)-1;
        }
        return;
    }
    if (q->slot[1] != 0) {
        if (q->slot[1] != (void *)-1) {
            ((void (*)(void *, int, int))func_002942B8)(q->slot[1], 1, 0); /* DEBT(CAST): caller passes an unused 3rd arg */
            q->slot[1] = (void *)-1;
        }
    }
}

typedef struct {
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
} Op3dSoundParam;

extern Op3dSoundParam D_006EA750;
extern float D_004F3FD0[];
void func_002B5880(float *, float *, int);
float op_length_get(float *, float *);
float op_deg_get(int, float, float, float, float);

int op_3d_vol_pan_get(int pos, int vol, int *out_vol)
{
    float v0[4];
    float v1[4];
    float pad[8];
    Op3dSoundParam *s = &D_006EA750;
    float *vp = v0;
    float d;
    /* DEBT(FAKE): register pin fixes $f0/$f1 swap in volume clamp */
    register float f __asm__("$f1");
    int v;
    float deg;
    float pan;

    func_002B5880(v0, D_004F3FD0, pos);
    MMI_SQ_ZERO(0x10, vp);
    {
        float len = op_length_get(v0, v1);
        register float f24 __asm__("$f1") = s->f24;
        f = len * f24 + s->f20;
    }
    if (f > s->f08) {
        f = s->f08;
    }
    if (f < s->f0C) {
        f = s->f0C;
    }
    v = (int)f;
    v = (v * vol) / 256;
    if (v >= 0x80) {
        v = 0x7F;
    }
    *out_vol = v;
    deg = op_deg_get(0, 0.0f, 0.0f, v0[0], v0[2]);
    if (deg > 1024.0f && deg < 3072.0f) {
        if (deg < 2048.0f) {
            pan = (2048.0f - deg) * s->f2C;
        } else {
            pan = -((deg - 2048.0f) * s->f2C);
        }
    } else {
        if (deg < 1024.0f) {
            pan = deg * s->f2C;
        } else {
            pan = -((4096.0f - deg) * s->f2C);
        }
    }
    pan += 64.0f;
    if (pan < s->f1C) {
        pan = s->f1C;
    }
    if (pan > s->f18) {
        pan = s->f18;
    }
    return (int)pan;
}

int op_oef2_se_3d_on(PtrHolder8 *ent, int a, int b)
{
    int vol;
    int pan;
    int h;
    int n;

    if (a != 0) {
        vol = op_3d_vol_pan_get(a, b, &pan);
    } else {
        pan = b * 127 / 256;
        vol = 64;
    }
    if (ent->type == 1) {
        h = func_002943B8(ent);
        if (h >= 0) {
            SndSepPlay(h, vol, pan);
        }
        return 1;
    }
    if (ent->type == 2) {
        n = 0;
        D_00704013 = 1;
        SndStopBattleStream();
        if (D_006EA8A0[0] == ent) {
            SndStartBattleStream(0, vol, pan);
            n++;
        }
        if (D_006EA8A0[1] == ent) {
            SndStartBattleStream(1, vol, pan);
            n++;
        }
        if (n == 0) {
            func_00120108(D_005745F0, ent);
        }
        return 1;
    }
    return 0;
}

int op_oef2_se_3d_move(PtrHolder8 *ent, int a, int b)
{
    int vol;
    int pan;
    int h;

    if (a != 0) {
        vol = op_3d_vol_pan_get(a, b, &pan);
    } else {
        pan = b * 127 / 256;
        vol = 64;
    }
    if (ent->type == 1) {
        h = func_002943B8(ent);
        if (h >= 0) {
            if (SndIsSepPlay(h) == 0) {
                return 0;
            }
            SndSepPanDirect(h, vol);
            SndSepVolumeDirect(h, pan);
            return 1;
        }
    }
    if (ent->type == 2) {
        SndVagStreamVolumeDirect(pan);
        func_002D8508(vol);
        return 1;
    }
    return 0;
}

int op_oef2_se_on(PtrHolder8 *ent, int vol, int b)
{
    int pan = b * 127 / 256;
    int h;
    int n;

    if (ent->type == 1) {
        h = func_002943B8(ent);
        if (h >= 0) {
            SndSepPlay(h, vol, pan);
        }
        return 1;
    }
    if (ent->type == 2) {
        n = 0;
        D_00704013 = 1;
        SndStopBattleStream();
        if (D_006EA8A0[0] == ent) {
            SndStartBattleStream(0, vol, pan);
            n++;
        }
        if (D_006EA8A0[1] == ent) {
            SndStartBattleStream(1, vol, pan);
            n++;
        }
        if (n == 0) {
            func_00120108(D_005745F0, ent);
        }
        return 1;
    }
    return 0;
}

void op_oef2_se_fade_out(PtrHolder8 *h, int a)
{
    if (h->type == 1) {
        SndSepVolumeTranslate(func_002943B8(h), a, 0);
    }
}

u8 func_00294CC8(void) {
    return D_00704013;
}
