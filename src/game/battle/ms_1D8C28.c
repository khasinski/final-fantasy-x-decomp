/* tu_203 0x1d8c28-0x1dbb50: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/u2.h"

extern char D_0056F6B0[];
void yiDisposeAnimDObj(int a, int b);

typedef struct Blk662D28Full {
    u8 pad0[0x810];
    s32 f810;
    s32 f814[8];
    s32 f834;
    float f838;
    s32 f83C;
    s32 f840;
    s32 f844;
    s32 f848;
    s32 f84C;
    s32 f850;
    s32 f854;
    s32 f858;
    s32 f85C;
    s32 f860;
    s32 f864;
} Blk662D28Full; /* DEBT(NAME): full layout of Blk662D28 (0x870 bytes) */

int MsCheckCommandCue(int id, int sub)
{
    int n = D_003172F0.f1511;
    GsEnt48 *p = D_003172F0.ent48;
    int i;

    for (i = 0; i < n; i++, p++) {
        if (p->id == id && p->sub == sub) {
            return 0;
        }
    }
    return 1;
}

int func_001D8C78(int id, int hi)
{
    int n = D_003172F0.f1511;
    GsEnt48 *p = D_003172F0.ent48;
    int i;

    hi &= 0xF0;
    for (i = 0; i < n; i++, p++) {
        if (p->id == id && (p->f7 & 0xF0) == hi) {
            return 0;
        }
    }
    return 1;
}

int func_001D8CD0(int id) {
    BtlChr *c = MsGetChr(id);
    int i;
    GameState *g = &D_003172F0;
    int n = g->f1511;
    GsEnt48 *e = g->ent48;
    for (i = 0; i < n; i++, e++) {
        if (e->id == id && c->fAA5 != i && (e->f7 & 0xF0) != 0x40) {
            return 1;
        }
    }
    return 0;
}

int MsUseItem(int id, GsEnt48 *e, int v);

int MsRegistCommandCue(int id, u8 *p, int a, int b, int c)
{
    int n = D_003172F0.f1511;
    if (n < 0x3E) {
        BtlChr *ch = MsGetChr(id);
        GsEnt48 *e = &D_003172F0.ent48[n];
        ch->fAA7++;
        *e = *(GsEnt48 *)p;
        e->f7 = b;
        e->sub = c;
        e->f4 = 0;
        e->f2 = 0;
        e->pad5[0] = 0;
        e->pad5[1] = a;
        e->id = id;
        MsUseItem(id, (GsEnt48 *)p, -1);
        D_003172F0.f1511 = n + 1;
        return -1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsInsertCommandCue);

GsEnt48 *func_001D92A0(void)
{
    if (D_003172F0.f1511 > 0) {
        return D_003172F0.ent48;
    }
    return 0;
}

int MsDeleteCommandCue(int id, int idx, int flag)
{
    Ent48Tbl *tbl = (Ent48Tbl *)D_00317690;
    int n = tbl->n;
    BtlChr *chr;
    int i;
    int dst;
    int deleted;

    if (n > 0 && idx != 0xFF) {
        chr = MsGetChr(id);
        for (i = 0, dst = 0, deleted = 0; i < n; i++) {
            if (i == idx && tbl->e[i].id == id) {
                if (i == chr->fAA5) {
                    if (flag != 0) {
                        goto keep; /* DEBT(GOTO): fall into keep path when active slot is protected by flag */
                    }
                    chr->fAA5 = 0xFF;
                }
                ((u8 *)chr)[0x39E] = 0;
                deleted++;
                ((u8 *)chr)[0x3D7] = 0;
                chr->fAA7--;
                ((u8 *)chr)[0x106] = 0;
            } else {
            keep:
                if (i != dst) {
                    tbl->e[dst] = tbl->e[i];
                }
                dst++;
            }
        }
        if (deleted > 0) {
            n--;
            D_00318801 = n;
        }
        return deleted;
    }
    return 0;
}

int MsCleanCommandCue(int a, int b) {
    int sum = 0;
    int i;
    for (i = D_00318801 - 1; i >= 0; i--) {
        sum += MsDeleteCommandCue(a, i, b);
    }
    return sum;
}

GsEnt48 *MsGetChrCommand(int id)
{
    BtlChr *c = MsGetChr(id);

    if (c->fAA5 != 0xFF) {
        return &D_00317690[c->fAA5];
    }
    return &c->f3EC;
}

GsEnt48 *MsGetChrCommand2(int id)
{
    BtlChr *c = MsGetChr(id);

    if (c->fAA5 != 0xFF) {
        return &D_00317690[c->fAA5];
    }
    return 0;
}

int func_001D95C0(int id, int v) {
    Ent48Tbl *t = (Ent48Tbl *)D_00317690; /* DEBT(CAST): D_00317690 is D_003172F0.ent48, n is GameState.f1511 */
    int r = 0;
    if (t->n > 0) {
        BtlChr *c = MsGetChr(id);
        if (c->fAA5 != 0xFF) {
            GsEnt48 *e = &t->e[c->fAA5];
            if (e->id == id) {
                e->f4 = v;
                r = 1;
            }
        }
    }
    return r;
}

int MsUseItem(int id, GsEnt48 *e, int v) {
    int n = 0;
    int i;
    int tmp;
    struct GsEnt48Sub *s = e->f8;
    for (i = 0; i < e->f3; s++, i++) {
        MsGetCommand(id, 0, -1, s, &tmp);
        if (tmp == 0x311E) break;
        if ((tmp >> 12) == 2 && MsGetRamChrMonster(id) == 0) {
            n += MsSaveItemUse(tmp, v);
        }
    }
    return n;
}

int func_001D9730(int id, int sub)
{
    int n = D_003172F0.f1510;
    GsEnt8 *p = D_003172F0.ent8;
    int i;

    for (i = 0; i < n; i++, p++) {
        if (p->id == id && p->sub == sub) {
            return 0;
        }
    }
    return 1;
}

int func_001D9780(int id)
{
    int n;
    GsEnt8 *p;
    int i;

    MsGetChr(id);
    n = D_003172F0.f1510;
    p = D_003172F0.ent8;
    for (i = 0; i < n; i++, p++) {
        if (p->id == id && (p->f4 & 0xF0) != 0x40) {
            return 1;
        }
    }
    return 0;
}

int MsRegistInputCue(int id, int a, int b, int c) {
    int n = D_003172F0.f1510;
    if (n < 0x3E) {
        BtlChr *ch = MsGetChr(id);
        GsEnt8 *e = &D_003172F0.ent8[n];
        ch->fAA6++;
        e->f4 = a;
        e->id = id;
        e->sub = c;
        e->f2 = b;
        e->f3 = 0;
        D_003172F0.f1510 = n + 1;
        return -1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsInsertInputCue);

GsEnt8 *MsGetInputCue(void)
{
    if (D_003172F0.f1510 > 0) {
        return D_003172F0.ent8;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsDeleteInputCue);

int MsCleanInputCue(int a, int b) {
    int sum = 0;
    int i;
    for (i = D_00318800 - 1; i >= 0; i--) {
        sum += MsDeleteInputCue(a, i, 0, b);
    }
    return sum;
}

int func_001D9D68(int id, int v) {
    int r = 0;
    if (D_003174A0.id > 0) {
        BtlChr *c = MsGetChr(id);
        if (c->fAA4 != 0xFF) {
            Ent3174A0 *e = &D_003174A0.e[c->fAA4];
            if (e->b0 == id) {
                e->b3 = v;
                r = 1;
            }
        }
    }
    return r;
}

int func_001D9DF0(int id) {
    int r = 0;
    if (D_003174A0.id > 0) {
        BtlChr *c = MsGetChr(id);
        if (c->fAA4 != 0xFF) {
            Ent3174A0 *e = &D_003174A0.e[c->fAA4];
            if (e->b0 == id) {
                r = e->b2 != 0;
            }
        }
    }
    return r;
}

void func_001D9E70(int id) {
    GameState *g = &D_003172F0;
    GsEnt8 *e = g->ent8;
    if (g->f1510 > 0) {
        if (e->f3 != 0 && g->ent8[0].id == id) {
            BtlChr *c = MsGetChr(id);
            if (c->fAA4 == 0xFF) {
                c->fAA4 = 0;
            }
        }
    }
}

s8 func_001D9ED0(void) {
    if (D_003172F0.f1752 == 1 && (s8)D_003172F0.f17 == 0) {
        return D_003172F0.f16;
    }
    return 0;
}

void MsBattleSpecialCameraPause(int v)
{
    if (D_003172F0.f18 == 0) {
        D_003172F0.f18 = 1;
        D_003172F0.f19 = D_003172F0.f17;
    }
    D_003172F0.f17 = v;
}

void MsBattleSpecialCameraFree(void)
{
    if (D_003172F0.f18 != 0) {
        D_003172F0.f18 = 0;
        D_003172F0.f17 = D_003172F0.f19;
    }
}

void func_001D9F58(int mode)
{
    Blk662D28Full *p;
    int i;

    D_00662D28 = 0;
    switch (mode) {
    case 1:
        func_0019D0B0();
        func_0019D0B8();
        p = (Blk662D28Full *)user_malloc(0x870, 5, D_0056F6B0, -1); /* DEBT(CAST): Blk662D28Full view of Blk662D28 */
        D_00662D28 = (Blk662D28 *)p;
        p->f838 = 0.002f;
        p->f810 = 0;
        p->f854 = 0;
        p->f850 = 0;
        p->f83C = 0;
        p->f840 = 0;
        p->f864 = 0;
        p->f834 = 0;
        p->f844 = 0;
        p->f848 = 0;
        p->f84C = 0;
        p->f858 = 0;
        p->f85C = 0;
        {
            s32 *q = &p->f814[4];
            for (i = 0; i < 4; i++, q++) {
                q[-4] = 0;
                q[0] = 0;
            }
        }
        for (i = 0; i < 3; i++) {
            yiDisposeAnimDObj(i + 0x1C, -1);
        }
        break;
    case 2:
        p = (Blk662D28Full *)user_malloc(0x870, 5, D_0056F6B0, -1);
        D_00662D28 = (Blk662D28 *)p;
        p->f810 = 0;
        p->f844 = 0;
        break;
    case 3:
        p = (Blk662D28Full *)user_malloc(0x870, 5, D_0056F6B0, -1);
        D_00662D28 = (Blk662D28 *)p;
        p->f810 = 0;
        p->f844 = 0;
        break;
    default:
        mode = 0;
        break;
    }
    D_003172F0.f16 = mode;
}

void MsBattleSpecialFree(void) {
    switch (D_003172F0.f16) {
    case 1:
        MsScreenResetShake(0);
        MsSetNormalUpVector(D_00662D28->f810);
        func_0011D590((s32)D_00662D28, 5); /* DEBT(TYPE): handle/pointer kept as int */
        D_00662D28 = 0;
        break;
    case 2:
        Yn_SeaResetMatrix();
        MsSetNormalUpVector(D_00662D28->f810);
        func_0011D590((s32)D_00662D28, 5); /* DEBT(TYPE): handle/pointer kept as int */
        D_00662D28 = 0;
        break;
    case 3:
        Yn_SeaResetMatrix();
        MsSetNormalUpVector(D_00662D28->f810);
        func_0011D590((s32)D_00662D28, 5); /* DEBT(TYPE): handle/pointer kept as int */
        D_00662D28 = 0;
        break;
    }
    D_003172F0.f16 = 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsBattleSpecial);

void func_001DAB28(Chr *a, int b, BtlChr *c)
{
    func_001089E0(a, b, 0, c->f7C0);
    func_001AC230(c->f7C0, c->f7C0);
    func_001AC230(c->f7D0, c->f7D0);
    func_001AC230(c->f7E0, c->f7E0);
    func_0019D1B8(c->f7C0);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", func_001DAB90);

void func_001AC528(void *dst, void *src, float a);
void func_001AC698(void *dst, void *src, float a);
void func_001AC200(void *dst, void *mat, void *src);

extern s8 D_00317306;

typedef struct Blk662D28_Sp {
    u8 pad0[0x7C0];
    float mat7C0[12];
    float f7F0;
    float f7F4;
    float f7F8;
    float f7FC;
    float f800;
    float f804;
    float f808;
    u8 pad80C[0x844 - 0x80C];
    float f844;
} Blk662D28_Sp;

void MsTransSpPos(int a, int b) {
    float mat[16];
    float *pos = (float *)b;

    switch (D_00317306) {
    case 1:
        func_002DD128(mat);
        pos[1] -= ((Blk662D28_Sp *)D_00662D28)->f844;
        if (a != 0) {
            func_001AC528(mat, mat, -((Blk662D28_Sp *)D_00662D28)->f800);
            func_001AC698(mat, mat, -((Blk662D28_Sp *)D_00662D28)->f808);
        } else {
            func_001AC698(mat, mat, ((Blk662D28_Sp *)D_00662D28)->f808);
            func_001AC528(mat, mat, ((Blk662D28_Sp *)D_00662D28)->f800);
        }
        func_001AC200(pos, mat, pos);
        break;
    case 2:
    case 3:
        ((Blk662D28_Sp *)D_00662D28)->f7F0 = 0.0f;
        ((Blk662D28_Sp *)D_00662D28)->f7F4 = 0.0f;
        ((Blk662D28_Sp *)D_00662D28)->f7F8 = 0.0f;
        func_001AC200(pos, ((Blk662D28_Sp *)D_00662D28)->mat7C0, pos);
        break;
    }
}

void MsSpCameraProcess(int a, int b, int c) {
    if (D_0031941C != 0) {
        MsTransSpPos(0, a);
        MsTransSpPos(0, b);
        D_00662D28->f810 = c;
        MsSetNormalUpVector(c);
        MsTransSpPos(0, c);
    }
}

void func_001DAF08(BtlChr *c)
{
    if (c->f2C8 != 0) {
        c->f1CE = 1;
        c->f1CF = 1;
    }
}

int MsCheckChrHitMotionAll(void)
{
    int i;
    BtlChr *c;

    for (i = 0; i < 31; i++) {
        c = MsGetChr(i);
        if (c->fA88 != 0 && c->fF3 != 0 && c->f2D2 != 0) {
            return -1;
        }
    }
    return 0;
}

int func_001DAF88(BtlChr *c, int mode) {
    int r = 0;
    if (c->f1C8 == 0 && c->f2C8 == 0) {
        s8 f;
        u8 k;
        switch (mode) {
        case 1:
            f = c->fF2; k = c->fB0;
            if (f == 0 || k == 0x28 || k == 0x29) r = 1;
            break;
        case 2:
            f = c->fF2; k = c->fB0;
            if (f == 0 && k != 0x28 && k != 0x29) r = 1;
            break;
        default:
            if (c->fF2 == 0) r = 1;
            break;
        }
    }
    return r;
}

void func_001DB008(int a, BtlChr *c)
{
    if (func_001DAF88(c, 1)) {
        c->fF3 = 1;
        MsSetMotion(a, 0x36, 1, 0, 1, 0, 0);
    }
}

int MsCheckStatusBeforeAction(int id, BtlChr *c)
{
    int i;

    if (c->fA88 != 0 && c->f3D6 == 0) {
        u8 *st;
        Ent4 *e;

        for (i = 0; i < 31; i++) {
            BtlChr *d = MsGetChr(i);
            if (d->f2D2 != 0 && d->fA88 != 0 && *(s32 *)((u8 *)d + 0x290) > 0 && (*(u32 *)((u8 *)d + 0xA8C) & 0x00FF00FF) == 0) {
                int val = ((u32)(d->f254 * d->f392) >> 8) + 100;
                if (val > 0) {
                    ((u8 *)d)[0xA90] = 0;
                    if ((d->f2C6 >> 1) & 1) {
                        ((u8 *)d)[0xAAD] = i;
                        ((void (*)(int, BtlChr *, int, int, int, int, int))func_001C7DC0)(i, d, val, val, 0, 1, ((s8 *)d)[0xA9B] != 0 ? 0x81 : 1); /* DEBT(CAST): header prototype has fewer args */
                        MsSetChrWeak(i, -1);
                        MsCheckAutoStatus(i, d);
                        if (MsDamageCheckDeath(i, i, 0, 1) == 0) {
                            MsDamageSetMotion(i, 8, 1);
                        }
                    } else {
                        val = -val;
                        ((void (*)(int, BtlChr *, int, int, int, int, int))func_001C7DC0)(i, d, val, val, 0, 1, 3); /* DEBT(CAST): header prototype has fewer args */
                        MsSetChrWeak(i, -1);
                        MsCheckAutoStatus(i, d);
                        if (func_001DAF88(d, 2) != 0) {
                            MsDamageSetMotion(i, 2, 1);
                        }
                    }
                }
                d->f392 = 0;
            }
        }
        st = &c->f2C8;
        e = D_0031FA50;
        for (i = 0; i < 13; i++, e++) {
            u8 v = st[i];
            if ((u32)(v - 1) < 0xFD && (((u8 *)e)[3] & 1)) {
                st[i] = v - 1;
                if (((u8 *)e)[3] & 2) {
                    MsStatusEffect(id, c, e, v - 1, c->fAF0);
                }
            }
        }
    }

    if (((*(u16 *)((u8 *)c + 0x2D6) >> 11) & 1) && !((*(u16 *)((u8 *)c + 0x2EE) >> 11) & 1)) {
        *(u16 *)((u8 *)c + 0x2D6) &= ~0x800;
        func_001DB008(id, c);
    }
    if (((*(u16 *)((u8 *)c + 0x2D6) >> 12) & 1) && !((*(u16 *)((u8 *)c + 0x2EE) >> 12) & 1)) {
        *(u16 *)((u8 *)c + 0x2D6) &= ~0x1000;
    }
    if (((*(u16 *)((u8 *)c + 0x2D6) >> 13) & 1) && !((*(u16 *)((u8 *)c + 0x2EE) >> 13) & 1)) {
        *(u16 *)((u8 *)c + 0x2D6) &= ~0x2000;
        func_001DB008(id, c);
    }
    if (((*(u16 *)((u8 *)c + 0x2D6) >> 6) & 1) && !((*(u16 *)((u8 *)c + 0x2EE) >> 6) & 1)) {
        *(u16 *)((u8 *)c + 0x2D6) &= ~0x40;
        func_001DB008(id, c);
    }
    if (((*(u16 *)((u8 *)c + 0x2D6) >> 7) & 1) && !((*(u16 *)((u8 *)c + 0x2EE) >> 7) & 1)) {
        *(u16 *)((u8 *)c + 0x2D6) &= ~0x80;
    }

    MsThreatOff(id, c);
    return 0;
}

int func_001DB3B8(BtlChr *c) {
    int a = 0;
    int b = 0;
    int i;
    if (c->fA88 != 0 && c->f3D6 == 0) {
        for (i = 0; i < 31; i++) {
            BtlChr *d = MsGetChr(i);
            if (d->fA88 != 0 && d->f2D2 != 0 && (int)((u32)(d->f254 * d->f392) >> 8) + 100 > 0) {
                if ((d->f2C6 >> 1) & 1) {
                    b++;
                } else {
                    a++;
                }
            }
        }
    }
    if (b != 0) {
        return 2;
    }
    return a != 0;
}

int MsCheckStatusAfterAction(int id, BtlChr *c)
{
    if (c->fA88 != 0) {
        u8 b0 = c->f2C8;
        u8 b1 = c->f2C9;
        u8 b2 = c->f2CA;
        u8 *p = &c->f2C8;
        Ent4 *e = D_0031FA50;
        int i;

        for (i = 0; i < 13; i++, e++) {
            int v = p[i];
            if (v > 0 && v < 0xFE) {
                if ((e->v & 4) != 0) {
                    p[i] = v - 1;
                    if ((e->v & 8) != 0 && ((s8 *)c)[0xA8B] == 0) { /* DEBT(TYPE): BtlChr+0xA8B inside padA89 */
                        MsStatusEffect(id, c, e, v - 1, c->fAF0);
                    }
                }
            }
        }
        if (b0 != 0 && c->f2C8 == 0) {
            c->f1CF = 0;
            c->f1CE = 1;
            c->fF3 = 1;
            MsSetMotion(id, 0x1B, 1, 0, 1, 0, 0);
        } else if ((b1 != 0 && c->f2C9 == 0) || (b2 != 0 && c->f2CA == 0)) {
            if (func_001DAF88(c, 0) != 0) {
                MsDamageSetMotion(id, 2, 1);
            }
        }
    }
    return 0;
}

int MsCheckStatusAfterInput(void) {
    int i;
    int n = 0;
    for (i = 0; i < 0x1F; i++) {
        BtlChr *c = MsGetChr(i);
        c->f3B0 = 0;
        c->f39A = 0;
        MsPopBtlPos(c);
        n += MsCheckAutoStatus(i, c);
    }
    return n;
}

int MsCheckAutoStatus(int a, BtlChr *c)
{
    int r = 0;

    if (c->f2FC != 0 && c->f2FE != c->f2FF) {
        MsResetAutoStatus(c);
        r = 1;
        MsSetAutoStatus(c);
        MsStatusEffectCheck(a);
    }
    return r;
}

void MsPoisonProcess(int id, BtlChr *c) {
    int v;

    c->fAB8 = 0;
    if (id == D_003172F0.f2114) {
        c->fA90 = 0;
        MsResetDirMove(c);
        c->fDC = 1;
        v = (u32)(c->f254 * c->f27A) / 100;
        ((void (*)(int, BtlChr *, int, int, int, int, int))func_001C7DC0)(id, c, v, v, 0, 1, 0x82); /* DEBT(CAST): called with a 7th argument */
        MsActionRequest(id, id, 8, 0, 1, 0);
        MsSetChrWeak(id, -1);
        MsCheckAutoStatus(id, c);
        c->fAAD = id;
        if (!MsDamageCheckDeath(id, id, 0, 1)) {
            MsDamageSetMotion(id, 8, 1);
        }
    }
    D_003172F0.f2114 = -1;
}

void func_001AC258(float *dst, float *a, float *b, float t);
void func_001AC3D0(float *dst, float *a, float *b);

void MsDefenseStartProcess(void)
{
    float pos0[4];
    float pos2[4];
    float posMid[4];
    int i;

    for (i = 0; i < 0x1F; i++) {
        BtlChr *c = MsGetChr(i);
        if (c->fA88 != 0) {
            int s0 = c->f394;
            int s2 = c->f393;
            if (s0 != 0xFF) {
                c->fD1 = 1;
                MsGetChr(s0);
                MsGetChrBtlPos(s2, pos2);
                MsGetChrBtlPos(s0, pos0);
                func_001AC258(posMid, pos2, pos0, (MsGetChrWidth(i) + MsGetChrWidth(s0)) + 5.0);
                func_001AC3D0((float *)c->pad70, pos0, posMid);
                MsVectorRect2Polar(pos2, c->pad70, (s32)&c->f1D4[3], 0, 0);
                MsSetDirThetaMode(c);
                MsSetMotion(i, ((c->f2D6 >> 13) & 1) ? 0x3D : 0x3C, 0, 0, 1, 0, 0);
                if (func_001DAF88(MsGetChr(s2), 0)) {
                    MsSetMotion(s2, 0x34, 0, 0, 1, 0, 0);
                }
            }
        }
    }
}

int MsDefenseProcess(void) {
    int r = 1;
    int i;
    for (i = 0; i < 0x1F; i++) {
        BtlChr *c = MsGetChr(i);
        int t = c->f394;
        if (t != 0xFF && c->fA88 != 0) {
            D_003172F0.f2004 |= (1 << i) | (1 << t);
            if (c->f1C8 != 0) {
                r = 0;
                break;
            }
            if (MsGetChr(t)->f1C8 != 0) {
                r = 0;
                break;
            }
        }
    }
    return r;
}

void MsDefenseEndProcess(void) {
    int i;
    if (D_003172F0.f212B != 0) {
        for (i = 0; i < 0x1F; i++) {
            BtlChr *c = MsGetChr(i);
            if (c->f394 != 0xFF) {
                MsDefensePosOff(c);
            }
        }
        D_003172F0.f212B = 0;
    }
}

void MsDefensePosOff(BtlChr *c)
{
    c->f393 = 0xFF;
    c->f394 = 0xFF;
    MsSetDirThetaMode(c);
}

int func_001DBAF0(BtlChr *c)
{
    if ((c->f2D6 >> 11 & 1) || (c->f2D6 >> 13 & 1) || (c->f2D6 >> 6 & 1)) {
        return 1;
    }
    return 0;
}

void func_001DBB30(BtlChr *c)
{
    MsSetMotion(c->f391, 0x4E, 1, 0, 1, 0, 0);
}
