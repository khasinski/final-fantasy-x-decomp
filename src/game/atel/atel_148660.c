/* tu_079 0x148660-0x148f40: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u0.h"

/* DEBT(TYPE): declared with a return type (shared header) but no value is returned; callers ignore it */
int TkSetVibrateMask(int v)
{
    func_0014CED0(1, v);
    func_0014CED0(2, v);
    func_0014CED0(3, v);
    func_0014CED0(4, v);
    func_0014CED0(5, v);
    func_0014CED0(6, v);
    func_0014CED0(7, v);
}

void func_001486D0(void)
{
    func_00138C78(0);
    func_0019CE30(1);
    func_001487B0();
    TkSetVibrateMask(1);
    func_0014AD08(6);
}

int AtelEnterMenuCallback(void)
{
    func_0019CE30(0);
    TkSetVibrateMask(0);
    MsEventEffectFree();
    func_00138C78(1);
    func_001449D0(1);
    TkMenuInitDummyControler();
    return ((int (*)(int))func_0014AD08)(3); /* DEBT(CAST): the original returns the value of func_0014AD08 (void here) */
}

void func_00148758(int v)
{
    func_00124828()->x0E = v;
}

void func_00148780(u16 v)
{
    Rec124828 *r = func_00124828();

    r->xD4 = v;
    r->xD6 = 1;
}

void func_001487B0(void)
{
    func_00124828()->xD6 = 0;
}

u16 func_001487D0(void)
{
    Rec124828 *r = func_00124828();

    if (r->xD6) {
        return r->xD4;
    }
    return r->x0E;
}

int func_0013A398(int a);
u16 *func_00206ED8(int a);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148660", AtelGetSaveDicName);

u8 func_00148870(void)
{
    return func_00124828()->control10.bytes[0];
}

void AtelSetBattleSceneGroup(int v)
{
    func_00124828()->control10.bytes[0] = v;
}

typedef struct DicHdr148 {
    u8 pad00[0x1E];
    u16 h1E;
    u8 pad20[8];
    s32 off28;
} DicHdr148;

int AtelSetSaveDicIndex(int idx)
{
    int old = AtelChangeCurrentCtrl(0);
    DicHdr148 *p = S1SYS()->p48;
    u16 v;

    if (p != 0) {
        v = p->h1E;
        if (v & 0x8000) {
            v &= 0x7FFF;
            if (idx >= v) {
                idx = 0;
            }
            v = ((u16 *)((u8 *)p + p->off28))[idx];
        }
        func_00148758(v);
    } else {
        func_00148758(0);
    }
    AtelSetCurrentCtrl(old);
}

int AtelGetEventActorLinkWork(int id)
{
    int old = AtelChangeCurrentCtrl(0);
    Actor *a = AtelGetBasicWork(id);

    AtelSetCurrentCtrl(old);
    return a->b33;
}

void AtelSetEventActorLinkWork(int id, u8 v)
{
    int old = AtelChangeCurrentCtrl(0);

    AtelGetBasicWork(id)->b33 = v;
    AtelSetCurrentCtrl(old);
}

int func_001489F0(void)
{
    int v1;
    int v2;

    v1 = AtelChangeCurrentCtrl(0);
    v2 = AtelGetCurrentActorTotal();
    AtelSetCurrentCtrl(v1);
    return v2;
}

int func_00148A38(int a)
{
    int v1;
    int v2;

    v1 = AtelChangeCurrentCtrl(0);
    v2 = AtelGetActorType(a);
    AtelSetCurrentCtrl(v1);
    return v2;
}

int AtelGetEventCharHandleFromID(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    Chr *chr;

    v1 = AtelChangeCurrentCtrl(0);
    chr = AtelGetCharHandle(AtelGetBasicWork(a));
    AtelSetCurrentCtrl(v1);
    return chr;
}

int AtelGetEventElemHandleFromID(int id, int i)
{
    int old = AtelChangeCurrentCtrl(0);
    int r = func_0013B318(AtelGetBasicWork(id), i);

    AtelSetCurrentCtrl(old);
    return r;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148660", AtelGetEventElemStatus);

void AtelSetEventElemStatus(int id, int bit, int on)
{
    Actor *actor;
    int saved;
    int flags;

    saved = AtelChangeCurrentCtrl(0);
    actor = AtelGetBasicWork(id);
    if (on != 0) {
        flags = actor->hB14 | (1 << bit);
    } else {
        flags = actor->hB14 & ~(1 << bit);
    }
    actor->hB14 = flags;
    AtelSetCurrentCtrl(saved);
}

void AtelSetEventElemHandleFromID(int a, int b, int c)
{
    int v1;

    v1 = AtelChangeCurrentCtrl(0);
    func_0013B328(AtelGetBasicWork(a), b, c);
    AtelSetCurrentCtrl(v1);
}

s32 func_00148CB0(s32 arg0, s32 arg1) {
    s32 temp_17;
    s32 temp_17_2;

    temp_17_2 = AtelChangeCurrentCtrl(0);
    temp_17 = (((struct { u8 _pad[0xAFC]; s32 a[1]; } *)(AtelGetBasicWork(arg0)))->a[arg1]);
    AtelSetCurrentCtrl(temp_17_2);
    return temp_17;
}

void AtelSetEventElemPosFromID(int id, int index, int value)
{
    int saved;
    Actor *actor;
    saved = AtelChangeCurrentCtrl(0);
    actor = AtelGetBasicWork(id);
    actor->valueAFC[index] = value;
    AtelSetCurrentCtrl(saved);
}

u16 func_00148D78(s32 arg0, s32 arg1) {
    s32 temp_17_2;
    u16 temp_17;

    temp_17_2 = AtelChangeCurrentCtrl(0);
    temp_17 = (((struct { u8 _pad[0xB04]; u16 a[1]; } *)(AtelGetBasicWork(arg0)))->a[arg1]);
    AtelSetCurrentCtrl(temp_17_2);
    return temp_17;
}

void AtelSetEventElemCharIDFromID(int id, int idx, int val)
{
    int old = AtelChangeCurrentCtrl(0);

    AR(AtelGetBasicWork(id))->hB04[idx] = val;
    AtelSetCurrentCtrl(old);
}

int AtelGetEventBindIdFromID(int id)
{
    int old = AtelChangeCurrentCtrl(0);
    int v = AtelGetBasicWork(id)->stateAA;

    AtelSetCurrentCtrl(old);
    return v;
}

int AtelGetEventCharIDFromID(int id)
{
    int old = AtelChangeCurrentCtrl(0);
    int v = AtelGetBasicWork(id)->hA8;

    AtelSetCurrentCtrl(old);
    return v;
}

void AtelSetEventCharHandleFromID(int id, Chr *c)
{
    int old = AtelChangeCurrentCtrl(0);
    Actor *a = AtelGetBasicWork(id);

    if (a->stateAA == 1) {
        a->ptr9C = c;
    }
    AtelSetCurrentCtrl(old);
}
