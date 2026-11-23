/* tu_110 0x1691c8-0x16cd98: low; ~TOMenuMainHelpSleep (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/g1.h"

int func_001691C8(void) {
    return get_hdd_inst_info();
}

void func_001691E8(void)
{
    /* DEBT(ORDER): independent resets preserve original address/store scheduling. */
    D_0030E0C8 = 0;
    D_0030E0CC = 0;
    D_0030E0BC = 0;
    D_00597E30 = 0;
    D_0030E0A8 = 0;
    D_00597A0C = 0;
    D_0030E0AC = 0;
    D_0030E0B0 = 0;
    D_0030E0B4 = 0;
    D_0030E0B8 = 0;
    D_00597A24 = 0;
    D_0030E0C0 = 0;
    D_00597A18 = 0;
    D_00597A1A = 0;
    D_00597A1C = 0;
}

typedef struct {
    s16 fnIdx;
    s16 arg;
    s8 mode;
    u8 pad5[3];
    s32 off;
} To169278Link;

typedef struct {
    u8 b00;
    u8 b01;
    u8 b02;
    u8 pad03[0x13];
    s16 h16;
    s16 h18;
    s16 h1A;
    u16 h1C;
    s16 h1E;
    u8 pad20[4];
    s16 h24;
    u8 pad26[4];
    u8 b2A;
    u8 pad2B[5];
    To169278Link links[8];
    u8 pad90[0x60];
    s16 hF0;
    s16 hF2;
    s16 hF4;
    s16 hF6;
    s16 hF8;
    s8 bFA;
    s8 bFB;
    s8 bFC;
    u8 padFD;
    s16 hFE;
    s16 h100;
    s16 h102;
    u8 b104;
    s8 b105;
    s8 b106;
    u8 pad107;
    u16 h108;
    u16 h10A;
    s16 h10C;
    u8 pad10E[2];
    s8 b110;
    u8 pad111[5];
    u16 h116;
    u8 pad118[0x20];
} To169278Ent;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    int (**fn)(int);
    void *p2C;
    s32 w30;
    void *p34;
} To30E070;

extern To169278Ent *D_00597A10;
extern To169278Ent *D_00597A20;
extern s32 D_00597A28;
typedef union {
    s32 w;
    u16 h;
} ToRegVal;

extern ToRegVal *_to_D_00597E30 __asm__("D_00597E30");
extern void (**D_0030E064)(void);
extern To30E070 _to_D_0030E070 __asm__("D_0030E070");
extern int (**D_0030E098)(int);
void TOMenuHelpSetExtMode(int, int);
void TOMenuTermHelp(void);
void func_0016B838(void);
void func_0016A268(s32, s32, s32, int *, int);
u16 func_00220318(void);
u16 TOMenuGetControlPadTrg(void);
u16 TOMenuGetControlPadRep(void);
int func_0016B5B0(s32);
void TOFTCTransfer(int);
int sa_task_buff_size_get(int);
void (**sa_task_init2(int, void *, int))(void);
void func_00162CD8(int);
void hdd_ins_size_check(void);
void func_0016B898(void);
void func_0016BA00(void);

void func_00169278(void)
{
    u16 pad;
    int dir;
    To169278Ent *target;
    int i;

    D_0030E0C5 = 0;
    if (D_0030E0A8 == 0) {
        return;
    }
    if (D_00597A10 == 0) {
        return;
    }
    pad = 0;
    switch (D_00597A10->b02) {
    case 0:
        pad = D_00597A1A;
        break;
    case 1:
        pad = D_00597A18;
        break;
    case 2:
        pad = D_00597A1C;
        break;
    }
    if (pad == 0) {
        return;
    }
    dir = -1;
    if (pad & 0x1000) dir = 0;
    if (pad & 0x4000) dir = 1;
    if (pad & 0x2000) dir = 3;
    if (pad & 0x8000) dir = 2;
    if (pad & 0x20) dir = 4;
    if (pad & 0x40) dir = 7;
    if (pad & 0x80) dir = 5;
    if (pad & 0x10) dir = 6;
    if (dir < 0) {
        return;
    }
    target = (To169278Ent *)((s32)D_0030E0C8 + D_00597A10->links[dir].off);
    if (target == 0) {
        return;
    }
    if (D_0030E0A8 == 0) {
        return;
    }
    for (i = 0; i < D_00597A0C; i++) {
        s32 *hdr = (s32 *)((i * 8) + (s32)D_0030E0A8);
        To169278Ent *p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        int n = *(s16 *)(hdr + 1);
        int j;

        for (j = 0; j < n; j++, p++) {
            if (p == target) {
                int blocked = 0;

                if (D_00597A10->links[dir].fnIdx >= 0) {
                    int r = _to_D_0030E070.fn[D_00597A10->links[dir].fnIdx](D_00597A10->links[dir].arg);

                    if (D_00597A10->links[dir].mode == 0) {
                        if (r == 0) {
                            blocked = 1;
                        }
                    } else {
                        if (r != 0) {
                            blocked = 1;
                        }
                    }
                }
                if (blocked == 0) {
                    D_0030E0C5 = 1;
                    return;
                }
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_001694E8);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_00169B10);

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 b7;
} To16A048Cmd;

extern s32 D_005979F8;
extern s32 D_005979FC;

void func_0016A048(u8 **a0, u8 **a1, int a2)
{
    register u8 *dst __asm__("$16") = *a0;
    u8 *src = *a1;
    To16A048Cmd cmd;
    int val = 0;
    int i;

    memcpy(&cmd, src, 8);
    src += 8;
    switch (cmd.b1) {
    case 0:
        switch (cmd.b0) {
        case 0:
            val = D_0030E098[cmd.h2](cmd.h4);
            break;
        case 1:
            val = _to_D_00597E30[cmd.h4].w;
            break;
        }
        if (cmd.b6 == 0) {
            u16 digits[32];
            u16 *q;
            int nz;

            for (i = 0; i < 6; i++) {
                digits[i] = val % 10;
                val /= 10;
            }
            nz = 0;
            for (i = 5; i > 0; i--) {
                if (digits[i] == 0) {
                    if (nz != 0) {
                        digits[i] += 0x30;
                    } else {
                        digits[i] = 0x3A;
                    }
                } else {
                    nz = 1;
                    digits[i] += 0x30;
                }
            }
            digits[i] += 0x30;
            for (i = 5; i >= 0; i--) {
                *dst++ = digits[i];
            }
        } else {
            D_005979F8 = cmd.b6;
            D_005979FC = val;
        }
        break;
    case 1: {
        u8 *s = (u8 *)D_0030E098[cmd.h2](cmd.h4 + a2);

        for (i = 0; s[i] != 0; i++) {
            *dst++ = s[i];
        }
        break;
    }
    }
    *a0 = dst;
    *a1 = src;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016A268);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C040);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C060);

extern s32 D_0030E094;
void func_002DA928(void *, s16, s16, s16, s16, s16, s16, s16);
void func_002DAC50(void *, void *);

void func_0016AA88(s32 *a0, s32 *a1, s32 *a2)
{
    u8 sp[0x60];
    int v = D_0030E094;

    *a1 = a0[0];
    *a2 = a0[1];
    func_002DA928(sp, v, 1, 0, 0, 0, 0x10, 0x10);
    v += 4;
    func_002F8660(0);
    func_002DAC50(sp, a0 + 4);
    func_002DA610(0, 0);
    func_002DA928(sp, v, a0[0] / 64, 0x13, 0, 0, a0[0], a0[1]);
    func_002F8660(0);
    func_002DAC50(sp, a0 + 0x104);
    func_002DA610(0, 0);
}

typedef struct {
    u8 pad0[0x20];
    s16 h20;
    s16 h22;
    u8 pad24[7];
    s8 b2B;
} To16AB78Arg;

extern int (**D_0030E098)(int);

int func_0016AB78(To16AB78Arg *p)
{
    int r;

    if (p->h20 < 0) {
        return 0;
    }
    r = D_0030E098[p->h20](p->h22);
    switch (p->b2B) {
    case 0:
        if (r == 0) {
            return 1;
        }
        break;
    case 1:
        if (r != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016AC00);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C080);

void func_0016B4E0(void)
{
    extern s32 D_0030E05C, D_0030E0D0, D_0030E0D4, D_0030E0D8;
    extern s32 dvd_hdd_copy_system_cnf_buff;

    D_0030E0C8 = 0;
    D_00597E30 = 0;
    D_0030E0CC = 0;
    D_0030E0A8 = 0;
    D_00597A0C = 0;
    D_0030E0AC = 0;
    D_0030E0B0 = 0;
    D_0030E0B8 = 0;
    D_0030E0C0 = 0;
    D_0030E0BC = 0;
    D_0030E060 = 0;
    D_0030E0D0 = 0;
    D_0030E0D8 = 0;
    D_0030E0D4 = 0;
    dvd_hdd_copy_system_cnf_buff = 0;
    D_0030E05C = 0;
    if (D_0030E064 != 0) {
        D_0030E064[1]();
        D_0030E064 = 0;
    }
    D_0030E068 = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016B5B0);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C0A0);

void func_0016B7D8(void)
{
    s32 *hdr = (s32 *)D_0030E0C8;

    if (hdr != 0) {
        D_0030E0A8 = (u8 *)hdr + hdr[2];
        D_00597A0C = hdr[1];
        D_0030E0AC = (u8 *)hdr + hdr[3];
        D_0030E0B0 = (u8 *)hdr + hdr[4];
        D_0030E0B4 = (u8 *)hdr + hdr[5];
    }
}

typedef struct {
    s32 off;
    s16 cnt;
    s16 pad;
} To16B838Hdr;

typedef struct {
    u8 b00;
    u8 b01;
    u8 pad02[0x1A];
    u16 h1C;
    s16 h1E;
    u8 pad20[0xF4];
    u16 h114;
    u16 h116;
    s32 w118;
    s32 w11C;
    u16 h120;
    u16 h122;
    u8 pad124[0x14];
} To16B838Ent;

extern s32 _m2c_D_0030E0A8 __asm__("D_0030E0A8");
extern s32 _m2c_D_0030E0C8 __asm__("D_0030E0C8");

void func_0016B838(void)
{
    To16B838Hdr *hdr = (To16B838Hdr *)((D_00597A14 * 8) + _m2c_D_0030E0A8);
    int j;
    int n = hdr->cnt;
    To16B838Ent *p = (To16B838Ent *)(_m2c_D_0030E0C8 + hdr->off);

    for (j = 0; j < n; j++, p++) {
        p->h114 = p->h120;
        p->h116 = p->h122;
        p->w118 = 0;
        p->w11C = 0;
    }
}

void func_0016B898(void)
{
    int i;

    D_00597A28 = 0;
    D_00597A20 = 0;
    D_00597A10 = 0;
    D_00597A14 = 0;
    if (D_0030E0A8 == 0) {
        return;
    }
    for (i = 0; i < D_00597A0C; i++) {
        s32 *hdr = (s32 *)((i * 8) + (s32)D_0030E0A8);
        To169278Ent *p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        int n = *(s16 *)(hdr + 1);
        int j;

        func_0016B838();
        for (j = 0; j < n; j++, p++) {
            if (p->b01 & 1) {
                D_00597A10 = p;
                D_00597A14 = i;
                D_00597A28 = i - (s32)D_0030E0C8;
                if (p->h1C != 0) {
                    s32 *q = (s32 *)((s32)D_0030E0B4 + (p->h1E << 3));
                    int k;

                    for (k = 0; k < p->h1C; k++, q += 2) {
                        _to_D_00597E30[q[0]].w = q[1];
                    }
                }
                return;
            }
        }
    }
}

void func_0016BA00(void)
{
    To169278Ent *target = (To169278Ent *)((s32)D_0030E0C8 + D_00597A28);
    int i;

    D_00597A28 = 0;
    D_00597A20 = 0;
    D_00597A10 = 0;
    D_00597A14 = 0;
    if (D_0030E0A8 == 0) {
        return;
    }
    for (i = 0; i < D_00597A0C; i++) {
        s32 *hdr = (s32 *)((i * 8) + (s32)D_0030E0A8);
        To169278Ent *p = (To169278Ent *)((s32)D_0030E0C8 + hdr[0]);
        int n = *(s16 *)(hdr + 1);
        int j;

        func_0016B838();
        for (j = 0; j < n; j++, p++) {
            if (p == target) {
                D_00597A10 = p;
                D_00597A14 = i;
                D_00597A28 = i - (s32)D_0030E0C8;
                if (p->h1C != 0) {
                    s32 *q = (s32 *)((s32)D_0030E0B4 + (p->h1E << 3));
                    int k;

                    for (k = 0; k < p->h1C; k++, q += 2) {
                        _to_D_00597E30[q[0]].w = q[1];
                    }
                }
                return;
            }
        }
    }
}

extern char D_0056C118[];

int func_0016BB88(int a0, int a1)
{
    int max = func_00220808();
    int ret;

    if (a0 == 0) {
        D_00597A24 = 0;
    }
    a1 = ((a1 + 0x3F) / 64) * 64;
    ret = func_00220800() + D_00597A24;
    D_00597A24 += a1;
    if (D_00597A24 >= max) {
        ((void (*)(int, char *, char *, int, int))yiAssert)(0, D_0056C020, D_0056C118, D_00597A24, max); /* DEBT(CAST) */
    }
    return ret;
}

void func_0016BC30(int a) {
    D_00597A24 -= ((a + 0x3F) / 64) * 64;
    if (D_00597A24 < 0) {
        yiAssert(0, D_0056C020, D_0056C140);
    }
}

void func_0016BC80(void (*v)(void)) {
    D_0030E068 = v;
}

int func_0016BC90(void) {
    return D_0030E068 != 0;
}

void func_0016BCA0(void)
{
    for (;;) {
        if (D_0030E068 != 0) {
            D_0030E068();
            D_0030E068 = 0;
        }
        func_0017135C(1);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016BCE0);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_1691C8/rodata", jtbl_0056C160);

int func_0016C318(void) {
    return D_0030E060;
}

typedef union {
    u_long128 q;
    struct {
        u64 d0;
        u64 d1;
    } ad;
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } w;
} ToGifQword;

#define SET_AD(p, d_val, r_val) \
    { \
        ToGifQword *_q = (p); \
        _q->ad.d0 = (d_val); \
        _q->ad.d1 = (r_val); \
    }

#define SET_W4(p, a, b, c, d) \
    { \
        ToGifQword *_q = (p); \
        _q->w.w0 = (a); \
        _q->w.w1 = (b); \
        _q->w.w2 = (c); \
        _q->w.w3 = (d); \
    }

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016C328);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1691C8", func_0016C688);

void func_0016C920(ToGifQword *p, int x, int y, int w, int h)
{
    p[0].q = 0;
    SET_AD(&p[1], 0x1000000000000004UL, 0xE);
    SET_AD(&p[2], 0x44, 0x42);
    SET_AD(&p[3], 0x5001D, 0x47);
    SET_AD(&p[4], 0, 0x49);
    SET_AD(&p[5], 0, 0x14);
    SET_AD(&p[6], 0x8022400000008001UL, 0x41414141);

    x += 0x700;
    y += 0x730;

    SET_W4(&p[7], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[8], (x - 4) << 4, (y - 4) << 4, 0xFFFFFF, 0);
    SET_W4(&p[9], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[10], (x + w + 4) << 4, (y - 4) << 4, 0xFFFFFF, 0);
    SET_W4(&p[11], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[12], (x - 4) << 4, (y + h + 6) << 4, 0xFFFFFF, 0);
    SET_W4(&p[13], 0x20, 0x20, 0x20, 0x40);
    SET_W4(&p[14], (x + w + 4) << 4, (y + h + 6) << 4, 0xFFFFFF, 0);

    p[15].q = 0;
    p[15].w.w0 = 0x70000000;
    p[0].w.w0 = 0x1000000E;
}

PartySlot *func_0016CAC8(int id) {
    return MsGetSavePlayerPtr(id);
}

int func_0016CAE8(void) {
    int a = MsGetSaveBattleCount();

    return a - TkGetEncountCounterEventStart();
}

int func_0016CB18(void) {
    return MsGetSaveBattleCount();
}

int func_0016CB38(int id) {
    return func_0016CAC8(id)->v50;
}

int func_0016CB58(int id) {
    return func_0016CAC8(id)->v58;
}

int func_0016CB78(int id) {
    return func_0016CAC8(id)->v54;
}

/* Character-record accessors: MsGetSaveCommand(chr, id) flag tests (ids 0x30xx) and ChrRec1D8 field getters (D_0030E0C0[i]). */

int func_0016CB98(int a) {
    return func_001BFE30(a);
}

int func_0016CBB8(void) {
    return MsImportantGet();
}

int func_0016CBD8(void) {
    return MsGetGIL();
}

s8 func_0016CBF8(int i) {
    return ((s8 *)MsGetSaveEventFlag())[i];
}

s32 func_0016CC28(s32 arg0) {
    return ((s8) *(s8 *)(MsGetSaveEventFlag() + (((s32)arg0 / 8))) >> (arg0 & 7)) & 1;
}

int func_0016CC78(void) {
    return func_0014AC00();
}

int func_0016CC98(void) {
    return func_0014AF20();
}

int func_0016CCB8(int i) {
    return MsGetMonsterCapture(i);
}

int func_0016CCD8(void) {
    return hdd_rmode_get();
}

int func_0016CCF8(void) {
    if (D_00597A18 & 0x20) {
        return 1;
    }
    return 0;
}

/* DEBT(FAKE) */
s32 func_0016CD10(void) {
    register s32 var_2 __asm__("$2");

    var_2 = 0;
    if (D_0030E0C5 != 0) {
        var_2 = ((D_00597A18 | D_00597A1C) & 0xF000) != 0;
    }
    return var_2;
}

int func_0016CD48(int id) {
    return MsGetSavePlyJoin(id) == 1;
}

int func_0016CD70(void) {
    if (D_00597A18 & 0x40) {
        return 1;
    }
    return 0;
}

int func_0016CD88(void) {
    return D_00597A04;
}
