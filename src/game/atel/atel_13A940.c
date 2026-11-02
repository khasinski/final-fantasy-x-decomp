/* tu_072 0x13a940-0x13ca30: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A940", func_0013A940);

int func_0013AAD8(void) {
    return D_0058E988;
}

int func_0013AAE8(void) {
    return D_0058E98A;
}

int func_0013AAF8(void) {
    return D_0058E98C;
}

int func_0013AB08(void) {
    return D_0058E98E;
}

int func_0013AB18(void) {
    return D_0058E990;
}

int func_0013AB28(void) {
    return D_0058E992;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A940", func_0013AB38);

Effect *AtelGetMesWinWork(int id)
{
    id = id < 0 ? 0 : (id < 8 ? id : 7);
    return (Effect *)&D_0058E630[func_00138C68()][id]; /* DEBT(CAST): EffectQ view of Effect */
}

int AtelGetCtrlworkActorTotal(char *p) {
    return *(u16 *)(p + 0xC);
}

void func_0013ABD0(int v) {
}

int AtelGetCurrentActorTotal(void) {
    Sys3D8 *s = D_0058E3D8;
    int r = 0;

    if (s->flags & 1) {
        r = s->hC;
    }
    return r;
}

void func_0013AC00(void) {
    D_0058E99C = 0;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A940", AtelGetBasicWork);

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A940", AtelGetRealVarAdrs);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_13A940/rodata", jtbl_0056A7F0);

int func_0013AF90(int id) {
    int n = D_0058E3D8->hC;
    int i;

    for (i = 0; i < n; i++) {
        if (id == OBJR(AtelGetBasicWork(i))->w40) {
            return i;
        }
    }
    return -1;
}

int func_0013B008(int v) {
    int id[3];
    int r;

    if (v >= 3) {
        r = -1;
    } else {
        MsGetSavePartyMember(&id[0], &id[1], &id[2]);
        v = id[v];
        if (v == 0xFF) {
            r = -1;
        } else {
            r = func_0013AF90(v);
        }
    }
    return r;
}

int func_0013B068(Actor *a) {
    return OBJR(a)->w40;
}

int AtelGetBindPCFromID(void) {
    return func_0013B068(CALL0_AtelGetBasicWork());
}

int func_0013B098(Actor *a) {
    return OBJR(a)->wA0;
}

int AtelGetHideStatusFromID(void) {
    return OBJR(CALL0_AtelGetBasicWork())->wA0;
}

int func_0013B0C0(Actor *a) {
    return (OBJR(a)->w38 >> 8) & 1;
}

int AtelGetKeepBattlePartyFromID(void) {
    return (OBJR(CALL0_AtelGetBasicWork())->w38 >> 8) & 1;
}

Chr *func_0013B0F8(int id) {
    int i = func_0013AF90(id);
    Actor *a;

    if (i < 0) {
        return 0;
    }
    a = AtelGetBasicWork(i);
    if (AtelIsBind(i)) {
        return AQ(a)->ptr9C;
    }
    return 0;
}

Chr *func_0013B150(int id) {
    int i = func_0013AF90(id);
    Actor *a;

    if (i < 0) {
        return 0;
    }
    a = AtelGetBasicWork(i);
    if (AtelIsBind(i)) {
        return AQ(a)->ptr9C;
    }
    return 0;
}

int func_0013B1A8(int id, int idx) {
    int i = func_0013AF90(id);

    if (i < 0) {
        return 0;
    }
    if (func_0013B8C0(i, idx)) {
        return func_0013B318(AtelGetBasicWork(i), idx);
    }
    return 0;
}

int func_0013B210(int id, int idx) {
    int i = func_0013AF90(id);

    if (i < 0) {
        return 0;
    }
    if (func_0013B8C0(i, idx)) {
        return func_0013B318(AtelGetBasicWork(i), idx);
    }
    return 0;
}

int AtelGetActorNumber(Actor *a) {
    return OBJR(a)->h36;
}

int AtelGetLineNumber(Actor *a) {
    return OBJR(a)->h14;
}

int AtelGetELineNumber(Actor *a) {
    return OBJR(a)->h1C;
}

int AtelGetBgNumber(Actor *a) {
    return OBJR(a)->h16;
}

int func_0013B298(Actor *a) {
    return AtelGetBgNumber(a);
}

int AtelGetNamespaceNumber(Actor *a) {
    return OBJR(a)->h34;
}

char *AtelGetIndexWork(Actor *a, int i) {
    int *t = (int *)((char *)a + i * 4);
    return (char *)a + t[0x38 / 4];
}

float func_0013B2D8(Actor *a) {
    return OBJR(a)->f28;
}

int func_0013B2E0(Actor *a, int slot, int v) {
    OBJR(a)->slot[slot].h4 = v;
}

int func_0013B2F8(Actor *a, int slot, int v) {
    OBJR(a)->slotB[slot].h4 = v;
}

Chr *AtelGetCharHandle(Actor *a) {
    return a->ptr9C;
}

int func_0013B318(Actor *a, int i) {
    return OBJR(a)->wAF4[i];
}

void func_0013B328(Actor *a, int i, int v) {
    OBJR(a)->wAF4[i] = v;
}

int func_0013B338(Actor *a, int v) {
    int i;

    for (i = 0; i < 9; ) {
        func_0013B2E0(a, i++, v);
    }
}

int func_0013B398(Actor *a, int v) {
    int i;

    for (i = 0; i < 9; ) {
        func_0013B2F8(a, i++, v);
    }
}

void func_0013B3F8(Actor *a, int i, float f) {
    OBJR(a)->slot[i].f38 = f;
}

void func_0013B410(Actor *a, float f) {
    int i;

    for (i = 8; i >= 0; i--) {
        OBJR(a)->slot[i].f38 = f;
    }
}

void func_0013B440(Actor *a, float f) {
    OBJR(a)->slot[a->slotIdx].f10 = f;
}

void func_0013B458(Actor *a, int v) {
    OBJR(a)->slot[a->slotIdx].w14 = v;
}

void func_0013B470(Actor *a, float v) {
    a->slot[a->slotIdx].f0C = v;
}

void func_0013B488(Actor *a, float v) {
    a->slot[a->slotIdx].f08 = v;
}

void func_0013B4A0(Actor *a, float f) {
    OBJR(a)->slot[a->slotIdx].f34 = f;
}

void func_0013B4B8(Actor *a, float f) {
    int i;

    for (i = 8; i >= 0; i--) {
        OBJR(a)->slot[i].f10 = f;
    }
}

float func_0013B4E8(Actor *a, int i, float v) {
    return OBJR(a)->slot[i].f3C = v;
}

float func_0013B500(Actor *a, int i, float v) {
    return OBJR(a)->slot[i].f40 = v;
}

float func_0013B518(Actor *a, int i, float v) {
    return OBJR(a)->slotB[i].f10 = v;
}

float func_0013B530(Actor *a, int i, float v) {
    return OBJR(a)->slotB[i].f14 = v;
}

float func_0013B548(Actor *a, int i, float v) {
    return OBJR(a)->slotB[i].f18 = v;
}

float func_0013B560(Actor *a, int i, float v) {
    return OBJR(a)->slotB[i].f1C = v;
}

void func_0013B578(Actor *a, float f) {
    int i;

    for (i = 0; i < 9; ) {
        func_0013B4E8(a, i++, f);
    }
}

float func_0013B5D8(Actor *a, float f)
{
    int i;

    for (i = 0; i < 9; i++) {
        CALLV_func_0013B530(a, i, f);
    }
    return f;
}

void func_0013B638(Actor *a, float f)
{
    int i;

    for (i = 0; i < 9; i++) {
        ((R0SlotFn)func_0013B500)(a, i, f);
    }
}

void func_0013B698(Actor *a, float f)
{
    int i;

    for (i = 0; i < 9; i++) {
        ((R0SlotFn)func_0013B518)(a, i, f);
    }
}

void func_0013B6F8(Actor *a, float f)
{
    int i;

    for (i = 0; i < 9; i++) {
        ((R0SlotFn)func_0013B548)(a, i, f);
    }
}

void func_0013B758(Actor *a, float f)
{
    int i;

    for (i = 0; i < 9; i++) {
        ((R0SlotFn)func_0013B560)(a, i, f);
    }
}

float func_0013B7B8(void) {
    return AtelGetPosWorkAdrs(CALL0_AtelGetBasicWork())->f34;
}

float func_0013B7E0(void) {
    return AtelGetPosWorkAdrs(CALL0_AtelGetBasicWork())->f30;
}

float func_0013B808(void) {
    return AtelGetPosWorkAdrs(CALL0_AtelGetBasicWork())->f38;
}

float func_0013B830(void) {
    return AtelGetPosWorkAdrs(CALL0_AtelGetBasicWork())->f20;
}

float func_0013B858(void) {
    return AtelGetPosWorkAdrs(CALL0_AtelGetBasicWork())->f24;
}

int AtelIsBind(int id) {
    Actor *a = AtelGetBasicWork(id);

    if (a->stateAA == 1 && a->ptr9C) {
        return 1;
    }
    return 0;
}

int func_0013B8C0(int id, int idx) {
    Actor *a = AtelGetBasicWork(id);

    if (a->stateAA == 1 && a->ptr9C && OBJR(a)->wAF4[idx]) {
        return 1;
    }
    return 0;
}

void AtelSetPos(Actor *a, int flag, float x, float z) {
    StateQ *st = STATEQ(AtelGetPosWorkAdrs(a));
    StateQ *st2;
    Sys3D8 *g;

    st->x = x;
    st->y = 0.0f;
    st->z = z;
    if (AQ(a)->stateAA == 1 && AQ(a)->ptr9C != 0) {
        Ch_SetPos(AQ(a)->ptr9C, x, z);
        Ch_ClothReset(AQ(a)->ptr9C);
    }
    if (AQ(a)->id == D_0058E3D8->hA) {
        st2 = STATEQ(AtelGetPosWorkAdrs(a));
        g = D_0058E3D8;
        g->prev[0] = g->cur[0];
        g->prev[1] = g->cur[1];
        g->prev[2] = g->cur[2];
        g->prev[3] = g->cur[3];
        g->cur[0] = st2->x;
        g->cur[1] = st2->y;
        g->cur[2] = st2->z;
        g->cur[3] = 1.0f;
        if (!(AQ(a)->w34.w & 0x10) || flag) {
            g->prev[0] = g->cur[0];
            g->prev[1] = g->cur[1];
            g->prev[2] = g->cur[2];
            g->prev[3] = g->cur[3];
        }
        if (AQ(a)->ptr9C != 0) {
            AtelSetBattleSceneGroup(Ch_IdGetEncount(AQ(a)->ptr9C));
            AtelSetSaveDicIndex(func_00121AB0(AQ(a)->ptr9C));
        } else {
            AtelSetBattleSceneGroup(0);
            AtelSetSaveDicIndex(0);
        }
    }
    if (!(AQ(a)->w34.w & 0x10) || flag) {
        st->px = st->x;
        st->py = st->y;
        st->pz = st->z;
    }
    D_0058E3D8->flags |= 0x100000;
}

void graphicPreviousLevelGetNameHash(Chr *c, float x, float y, float z) {
    Ch_SetPos3(c, x, y, z);
}

void AtelSetPos3d(Actor *a, int flag, float x, float y, float z) {
    StateQ *st = STATEQ(AtelGetPosWorkAdrs(a));
    float v[4];

    if (st == 0) {
        return;
    }
    st->x = x;
    st->y = y;
    st->z = z;
    switch (AQ(a)->stateAA) {
    case 1:
        if (AQ(a)->ptr9C != 0) {
            graphicPreviousLevelGetNameHash(AQ(a)->ptr9C, x, y, z);
            Ch_ClothReset(AQ(a)->ptr9C);
        }
        break;
    case 2:
        v[0] = x;
        v[1] = y;
        v[2] = z;
        v[3] = 1.0f;
        MsCameraSetRect(AQ(a)->w3C, 1, v);
        break;
    }
    if (AQ(a)->id == D_0058E3D8->hA) {
        D_0058E3D8->prev[0] = D_0058E3D8->cur[0];
        D_0058E3D8->prev[1] = D_0058E3D8->cur[1];
        D_0058E3D8->prev[2] = D_0058E3D8->cur[2];
        D_0058E3D8->prev[3] = D_0058E3D8->cur[3];
        D_0058E3D8->cur[0] = st->x;
        D_0058E3D8->cur[1] = st->y;
        D_0058E3D8->cur[2] = st->z;
        D_0058E3D8->cur[3] = 1.0f;
        if (!(AQ(a)->w34.w & 0x10) || flag) {
            D_0058E3D8->prev[0] = D_0058E3D8->cur[0];
            D_0058E3D8->prev[1] = D_0058E3D8->cur[1];
            D_0058E3D8->prev[2] = D_0058E3D8->cur[2];
            D_0058E3D8->prev[3] = D_0058E3D8->cur[3];
        }
        if (AQ(a)->ptr9C != 0) {
            AtelSetBattleSceneGroup(Ch_IdGetEncount(AQ(a)->ptr9C));
            AtelSetSaveDicIndex(func_00121AB0(AQ(a)->ptr9C));
        } else {
            AtelSetBattleSceneGroup(0);
            AtelSetSaveDicIndex(0);
        }
    }
    if (!(AQ(a)->w34.w & 0x10) || flag) {
        st->px = st->x;
        st->py = st->y;
        st->pz = st->z;
    }
    D_0058E3D8->flags |= 0x100000;
}

ObjSlotR *func_0013BCC8(Actor *a) {
    return &OBJR(a)->slot[a->slotIdx];
}

void func_0013BCE0(Actor *a, float x, float y, float z) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    ObjSlotR *s = &OBJR(a)->slot[a->slotIdx];

    s->f28 = x;
    s->f2C = y;
    s->f30 = z;
    s->f1C = st->x;
    s->f20 = st->y;
    s->f24 = st->z;
}

void func_0013BD60(Actor *a, float x, float z) {
    func_0013BCE0(a, x, 0.0f, z);
}

s32 func_0013BD70(Actor *actor, s32 slotIndex)
{
    ActorBind *bind;
    ActorSlot *destination;
    s32 more;
    s32 selected;
    s32 i;
    ActorSlot *source;

    selected = slotIndex;
    if (selected < 0)
    {
        selected = (s32) actor->slotIdx;
    }
    source = func_0013C9C8(actor, selected)->slotInfo44;
    if (source->flags & 0x4000)
    {
        func_0013BE58(actor, selected);
    }
    i = 0;
    destination = actor->slot;
    /* DEBT(ORDER): retain the loop condition as the returned completion status. */
    for (; (more = i < 9); i++)
    {
        bind = func_0013C9C8(actor, i);
        if (bind->slotInfo44 == source)
        {
            bind->slotInfo44 = destination;
            destination->f28 = source->f28;
            destination->flags = 0;
            destination->f2C = source->f2C;
            destination->f30 = source->f30;
            destination->f38 = (float) source->f38;
            destination->f44 = source->f44;
            destination->f48 = source->f48;
            destination->f08 = source->f08;
            destination->f0C = source->f0C;
        }
        destination++;
    }
    return more;
}

s32 func_0013BE58(Actor *actor, s32 slotIndex)
{
    ActorBind *bind;
    ActorSlotB *destination;
    BindInfo *source;
    s32 more;
    s32 i;
    s32 selected;

    selected = slotIndex;
    if (selected < 0)
    {
        selected = (s32) actor->slotIdx;
    }
    i = 0;
    destination = actor->slotB;
    source = func_0013C9C8(actor, selected)->info;
    /* DEBT(ORDER): retain the loop condition as the returned completion status. */
    for (; (more = i < 9); i++)
    {
        bind = func_0013C9C8(actor, i);
        if (bind->info == source)
        {
            /* DEBT(CAST): embedded slot storage is exposed through the shared BindInfo view. */
            bind->info = (BindInfo *) destination;
            destination->f20 = source->f20;
            destination->flags = 0;
            destination->f24 = source->f24;
            destination->f28 = source->f28;
            destination->f2C = source->f2C;
            destination->f30 = source->f30;
            destination->f34 = source->f34;
            destination->f0C = (float) source->scale;
            destination->f08 = (float) source->offset;
        }
        destination++;
    }
    return more;
}

void func_0013BF20(Actor *a, int n, int mask, int flags) {
    ObjSlotR *slot;
    int i = 0;

    OBJBIND(a, n)->s44 = slot = &OBJR(a)->slot[n];
    mask |= 1 << n;
    if (flags & 0x20) {
        n = 7;
    }
    if (n >= 0) {
        do {
            ObjBindR *b = OBJBIND(a, i);

            if ((mask >> i) & 1) {
                if (!(flags & 0x100) || !(b->s44->h2 & 0xFF80)) {
                    b->s44 = slot;
                }
            }
            i++;
        } while (i <= n);
    }
}

void func_0013C000(Actor *a, int n, int mask, int flags) {
    ObjSlotBR *slot;
    int i = 0;

    OBJBIND(a, n)->s48 = slot = &OBJR(a)->slotB[n];
    mask |= 1 << n;
    if (flags & 0x20) {
        n = 7;
    }
    if (n >= 0) {
        do {
            ObjBindR *b = OBJBIND(a, i);

            if ((mask >> i) & 1) {
                if (!(flags & 0x100) || !(b->s48->h2 & 0xFFE0)) {
                    b->s48 = slot;
                }
            }
            i++;
        } while (i <= n);
    }
}

void func_0013C0E0(Actor *a, int p, int q, int h) {
    func_0013C9C8(a, a->slotIdx);
    OBJR(a)->slot[a->slotIdx].h0 = h;
    OBJR(a)->slot[a->slotIdx].h2 = q;
    OBJR(a)->slot[a->slotIdx].h6 = 0;
    func_0013BF20(a, a->slotIdx, p, q);
}

void func_0013C170(Actor *a, int p, int q, int h) {
    OBJR(a)->slotB[a->slotIdx].h0 = h;
    OBJR(a)->slotB[a->slotIdx].h2 = q;
    OBJR(a)->slotB[a->slotIdx].h6 = 0;
    func_0013C000(a, a->slotIdx, p, q);
}

int func_0013C1C0(Actor *a, int mask) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    ObjSlotBR *b = OBJBIND(a, a->slotIdx)->s48;

    if (mask & 1) {
        b->f38 = st->f34;
    }
    if (mask & 2) {
        b->f3C = st->f30;
    }
    if (mask & 4) {
        b->f40 = st->f38;
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A940", AtelExecInitFunc);

void func_0013C308(int v) {
    D_0058E3D8->b1E6 = v;
    D_0058E3D8->b1E4 = 1;
    D_0058E3D8->h1E8 = 0xFFFF;
}

void func_0013C330(void) {
    D_0058E3D8->b1E4 = 0;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A940", func_0013C340);

INCLUDE_ASM("build/ee_asm/game/atel/atel_13A940", func_0013C710);

void func_0013C920(int *w) {
    if (*w & 8) {
        func_0013C340(w, 1, 1);
    } else {
        func_0013C710(w, 0);
    }
}

void AtelExecCtrlEvent(int *w) {
    if (*w & 8) {
        func_0013C340(w, 1, 0);
        func_0013C340(w, 0, 0);
        func_0013C340(w, 0, 1);
    } else {
        func_0013C710(w, 1);
    }
    if (AtelCheckCallbackQue(0)) {
        AtelExecCallbackQue(0);
    }
}

ActorBind *func_0013C9C8(Actor *a, int slot) {
    int t;

    slot = slot > -1 ? slot : 0;
    t = a->hdr->type;
    if (t < 7) {
        if (t >= 5) {
            slot = slot < 2 ? slot : 1;
            return (ActorBind *)((char *)a + (slot * 0x4C + 0x12C)); /* DEBT(CAST): bind table inside the actor */
        }
    }
    slot = slot < 9 ? slot : 8;
    return (ActorBind *)((char *)a + (slot * 0x4C + 0x12C)); /* DEBT(CAST): bind table inside the actor */
}
