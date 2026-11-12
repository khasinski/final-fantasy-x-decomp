/* tu_203 0x1d8c28-0x1dbb50: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/u2.h"

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsRegistCommandCue);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsInsertCommandCue);

GsEnt48 *func_001D92A0(void)
{
    if (D_003172F0.f1511 > 0) {
        return D_003172F0.ent48;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsDeleteCommandCue);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", func_001D9F58);

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

extern s8 D_00317306;
void func_001AC528(void *dst, void *src, float a);
void func_001AC698(void *dst, void *src, float a);
void func_001AC200(void *dst, void *mat, void *src);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsCheckStatusBeforeAction);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsCheckStatusAfterAction);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8C28", MsDefenseStartProcess);

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
