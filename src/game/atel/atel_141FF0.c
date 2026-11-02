/* tu_075 0x141ff0-0x143910: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r1.h"
#include "ffx/u0.h"

void func_00141FF0(Actor *a, SlotCQ *s) {
    Res588Q *res = (Res588Q *)AtelGetCtrlWork(s->h40);
    int *tab = res->a1F8;
    int first;
    int second;

    if (tab) {
        first = tab[s->h3E];
        if (res->a1FC) {
            second = res->a1FC[s->h3E];
        } else {
            second = 0;
        }
        func_001458B0(AQ(a)->id, first, second, s->h3C);
    }
}

void func_00142070(Actor *a, ObjNodeR *n) {
    SlotCQ *s;
    int slot;
    int w;

    if (n) {
        slot = n->h0E & 0xF;
        w = n->h08;
        s = (SlotCQ *)func_0013C9C8(a, slot); /* DEBT(CAST): bind entry used as a slot */
        a->slotIdx = slot;
        AQ(a)->h2C = w;
        ((SlotCQ *)func_0013C9C8(a, slot))->b1D = 0; /* DEBT(CAST): bind entry used as a slot */
        s->h3E = n->h12;
        s->h3C = n->h10;
        s->h40 = n->h14;
        func_00142B50(a, s, slot);
        func_00141FF0(a, s);
        func_0013CAD0((ScrQ *)a, (ScrEntQ *)s, func_0013CA30((ScrQ *)a, w)); /* DEBT(CAST): the actor used as a script reader */
    }
}

int AtelDecodeCommand(int id, int c) {
    return func_00140B48(AtelGetBasicWork(id), c, 1);
}

void func_00142190(NodeQ *p, NodeQ *n) {
    NodeQ *prev = p->prev;

    if (prev) {
        prev->next = n;
    }
    p->prev = n;
    n->prev = prev;
    n->next = p;
}

void func_001421B0(NodeQ *tail, NodeQ *node)
{
    NodeQ *next;

    /* DEBT(CAST): address comparison preserves the original loop and shared splice sequence. */
    while ((u32)(next = tail->next) > 0)
    {
        tail = next;
    }
    if (next != 0)
    {
        next->prev = node;
    }
    tail->next = node;
    /* DEBT(ORDER): keep these link writes in the original scheduling order. */
    node->prev = tail;
    node->next = next;
}

void func_001421F8(NodeQ *n) {
    NodeQ *prev = n->prev;
    NodeQ *next = n->next;

    if (prev) {
        prev->next = next;
    }
    if (next) {
        next->prev = prev;
    }
}

void func_00142218(Actor *a, NodeQ *n) {
    NodeQ *head;
    NodeQ *next;

    if (n) {
        func_001421F8(n);
        head = OBJR(a)->p88;
        next = head->next;
        if (next) {
            next->prev = n;
        }
        head->next = n;
        n->prev = head;
        n->next = next;
    }
}

void AtelDeleteSignal(int id, NodeQ *n) {
    func_00142218(AtelGetBasicWork(id), n);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_141FF0", func_001422A0);

int AtelRegistSignal2(Req142 *r) {
    if (r->w4 == 0xFFFF) {
        return 0;
    }
    return func_001422A0(r, -1);
}

int func_00142530(int a, int b, int c, int d, int e) {
    Req142 r;

    r.w0 = a;
    r.w4 = b;
    r.w8 = c;
    r.wC = d;
    r.w10 = e;
    return AtelRegistSignal2(&r);
}

int func_00142560(Req142 *r) {
    ObjNodeR *n;

    if (r->w4 == 0xFFFF) {
        return 0;
    }
    for (n = OBJR(AtelGetBasicWork(r->w4))->head80; n != 0; n = n->next) {
        if (((u8 *)n)[0xF] != 3 && (n->h0E & 0xF) == r->wC) {
            return 0;
        }
    }
    return func_001422A0(r, -1);
}

int func_001425E0(int a, int b, int c, int d, int e) {
    Req142 r;

    r.w0 = a;
    r.w4 = b;
    r.w8 = c;
    r.wC = d;
    r.w10 = e;
    return func_00142560(&r);
}

int func_00142610(Req142 *r) {
    ObjNodeR *n;

    if (r->w4 == 0xFFFF) {
        return 0;
    }
    for (n = OBJR(AtelGetBasicWork(r->w4))->head80; n != 0; n = n->next) {
        if (((u8 *)n)[0xF] != 3 && n->h08 == r->w10) {
            return 0;
        }
    }
    return func_001422A0(r, -1);
}

int func_00142688(int a, int b, int c, int d, int e) {
    Req142 r;

    r.w0 = a;
    r.w4 = b;
    r.w8 = c;
    r.wC = d;
    r.w10 = e;
    return func_00142610(&r);
}

void func_001426B8(Actor *a, ObjNodeR *n) {
    if (n && ((u8 *)&n->h0E)[1] == 1) { /* DEBT(CAST): kind byte = high byte of h0E */
        func_00142530(a->id, n->h0A, 3, n->h0E & 0xF, n->h08);
    }
}

void func_001426F0(Actor *a, ObjNodeR *n) {
    if (n && ((u8 *)&n->h0E)[1] == 2) { /* DEBT(CAST): kind byte = high byte of h0E */
        func_00142530(a->id, n->h0A, 3, n->h0E & 0xF, n->h08);
    }
}

int AtelGetRequestLevel(int id) {
    return AtelGetBasicWork(id)->slotIdx;
}

int func_00142748(int id, int x) {
    ObjNodeR *n = OBJR(AtelGetBasicWork(id))->head80;
    ObjNodeR *next;
    int r = 0;

    while (n != 0) {
        next = n->next;
        if (((u8 *)n)[0xF] != 3 && n->h08 == x) {
            r = 1;
            break;
        }
        n = next;
    }
    return r;
}

int func_001427A8(int id, int x) {
    ObjNodeR *n = OBJR(AtelGetBasicWork(id))->head80;
    ObjNodeR *next;
    int r = 0;

    while (n != 0) {
        next = n->next;
        if (((u8 *)n)[0xF] != 3 && (n->h0E & 0xF) >= x) {
            r = 1;
            break;
        }
        n = next;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_141FF0", AtelDecodeSignal);

INCLUDE_ASM("build/ee_asm/game/atel/atel_141FF0", func_00142988);

void AtelSkipReqLevel(int id, int x) {
    func_00142988(AtelGetBasicWork(id), x, 0);
}

int AtelSkipReqLevel2(int id, int v) {
    func_00142988_v(AtelGetBasicWork(id), v, 1);
}

int AtelGetActorType(int id) {
    if (id < 0 || id >= AtelGetCtrlworkActorTotal((char *)D_0058E3D8)) {
        return 7;
    }
    return AtelGetBasicWork(id)->hdr->type;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_141FF0", func_00142B50);

INCLUDE_ASM("build/ee_asm/game/atel/atel_141FF0", func_00142C40);

/* DEBT(CAST): SlotCQ is the existing subsystem view of the bind-slot record. */
void func_00142CC0(Actor *a, int n)
{
    SlotCQ *slot;

    ((SlotCQ *)func_0013C9C8(a, n))->b1D = 0;
    slot = (SlotCQ *)func_0013C9C8(a, n);
    func_00141FF0(a, slot);
    func_0013CAD0((ScrQ *)a, (ScrEntQ *)slot, func_0013CA30((ScrQ *)a, 0));
    slot->b1F = 0;
    if (a->hdr->type == 1) {
        func_00142B50(a, slot, n);
    }
    slot->pending = 0;
}

void AtelExecReturn(s32 id, s32 b, s32 c)
{
    Actor *actor;
    ActorBind *binding;

    actor = AtelGetBasicWork(id);
    func_001426F0(actor, actor->node90);
    /* DEBT(CAST): shared node has legacy helper views NodeQ/ScrEntQ/SlotCQ. */
    func_00142218(actor, (NodeQ *) actor->node90);
    actor->node90 = 0;
    if (b >= 0)
    {
        func_00142988(actor, b, 2);
    }
    AtelDecodeSignal(id, 0xA);
    if (c != 0)
    {
        binding = func_0013C9C8(actor, (s32) actor->slotIdx);
        func_00142CC0(actor, (s32) actor->slotIdx);
        func_00141FF0(actor, (SlotCQ *) binding);
        func_0013CAD0((ScrQ *) actor, (ScrEntQ *) binding, func_0013CA30((ScrQ *) actor, 1));
    }
    actor->flags34.w |= 0x10;
}

void AtelExecReturn2(int id, int b, int c) {
    if (AtelGetBasicWork(id)->slotIdx != 0) {
        AtelExecReturn(id, b, c);
    }
}

void func_00142EA8(s32 arg0, s32 arg1, s32 arg2)
{
    Actor *actor;
    ActorBind *binding;

    actor = AtelGetBasicWork(arg0);
    func_001426F0(actor, actor->node90);
    /* DEBT(CAST): shared node has legacy helper views NodeQ/ScrEntQ/SlotCQ. */
    func_00142218(actor, (NodeQ *) actor->node90);
    actor->node90 = 0;
    if (arg1 >= 0)
    {
        func_00142988(actor, arg1, 0);
    }
    AtelDecodeSignal(arg0, 0xA);
    if (arg2 != 0)
    {
        binding = func_0013C9C8(actor, (s32) actor->slotIdx);
        func_00142CC0(actor, (s32) actor->slotIdx);
        func_00141FF0(actor, (SlotCQ *) binding);
        func_0013CAD0((ScrQ *) actor, (ScrEntQ *) binding, func_0013CA30((ScrQ *) actor, 1));
    }
    actor->flags34.w |= 0x10;
}

void func_00142F88(int id, int b, int c) {
    if (AtelGetBasicWork(id)->slotIdx != 0) {
        AtelExecReturn(id, b, c);
    }
}

void func_00142FF0(int id, float *px, float *py, float *pz) {
    int old = AtelChangeCurrentCtrl(0);
    ActorState *st;

    if (id < 0 || id >= AtelGetCtrlworkActorTotal((char *)D_0058E3D8)) {
        id = D_0058E3DC;
    }
    st = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
    if (px) {
        *px = st->x;
    }
    if (py) {
        *py = st->y;
    }
    if (pz) {
        *pz = st->z;
    }
    AtelSetCurrentCtrl(old);
}

void func_001430B0(int id, float *a, float *b, float *c) {
    int old = AtelChangeCurrentCtrl(0);
    ActorState *st;

    if (id < 0 || id >= AtelGetCtrlworkActorTotal((char *)D_0058E3D8)) {
        id = D_0058E3DC;
    }
    st = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
    if (a) {
        *a = st->f30;
    }
    if (c) {
        *c = st->f38;
    }
    if (b) {
        *b = st->f34;
    }
    AtelSetCurrentCtrl(old);
}

int func_00143170(int v) {
    int old = AtelChangeCurrentCtrl(0);

    D_0058E3D8->f210.b0 = (v != 0);
    AtelSetCurrentCtrl(old);
}

int func_001431C0(void) {
    int old = AtelChangeCurrentCtrl(0);
    int r = D_0058E3D8->f210.b0;

    AtelSetCurrentCtrl(old);
    return r;
}

int func_00143200(int v) {
    REC124828F()->b25 = (v != 0);
}

int func_00143248(void) {
    return REC124828F()->b25;
}

void func_00143270(int v) {
    REC124828F()->b26 = (v != 0);
}

int func_001432B8(void) {
    return REC124828F()->b26;
}

int func_001432E0(void) {
    u8 *r = (u8 *)REC124828_BASE(); /* DEBT(CAST): byte member of the record at +0x29 */
    int v;

    if (MsBattleCheck() != 0) {
        return 0;
    }
    v = func_00173690();
    if (v >= 0) {
        r[0x29] = v & 1;
    }
    return r[0x29];
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_141FF0", AtelUpdateWaterStatus);

INCLUDE_ASM("build/ee_asm/game/atel/atel_141FF0", AtelUpdateBattleStatus);

void func_00143608(int id, float x, float y, float z) {
    int old = AtelChangeCurrentCtrl(0);
    ActorState *st;

    if (id < 0 || id >= AtelGetCtrlworkActorTotal((char *)D_0058E3D8)) {
        id = D_0058E3DC;
    }
    st = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
    st->x = x;
    st->y = y;
    st->z = z;
    AtelSetCurrentCtrl(old);
}

void func_001436A8(int id, float x, float y, float z) {
    int old = AtelChangeCurrentCtrl(0);
    ActorState *st;

    if (id < 0 || id >= AtelGetCtrlworkActorTotal((char *)D_0058E3D8)) {
        id = D_0058E3DC;
    }
    st = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
    st->f30 = x;
    st->f34 = y;
    st->f38 = z;
    AtelSetCurrentCtrl(old);
}

void func_00143748(int id, int mode, float *a, float *b, float *c) {
    int old = AtelChangeCurrentCtrl(0);
    ActorState *st;

    if (id < 0 || id >= AtelGetCtrlworkActorTotal((char *)D_0058E3D8)) {
        id = D_0058E3DC;
    }
    st = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
    if (mode) {
        if (a) {
            *a = st->f30;
        }
        if (b) {
            *b = st->f34;
        }
        if (c) {
            *c = st->f38;
        }
    } else {
        if (a) {
            *a = st->x;
        }
        if (b) {
            *b = st->y;
        }
        if (c) {
            *c = st->z;
        }
    }
    AtelSetCurrentCtrl(old);
}

void func_00143850(int id, int mode, float x, float y, float z) {
    int old = AtelChangeCurrentCtrl(0);
    ActorState *st;

    if (id < 0 || id >= AtelGetCtrlworkActorTotal((char *)D_0058E3D8)) {
        id = D_0058E3DC;
    }
    st = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
    if (mode) {
        st->f30 = x;
        st->f34 = y;
        st->f38 = z;
    } else {
        st->x = x;
        st->y = y;
        st->z = z;
    }
    AtelSetCurrentCtrl(old);
}
