/* tu_075 0x141ff0-0x143910: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r1.h"
#include "ffx/u0.h"

void func_00141FF0(Actor *a, ActorBind *s) {
    EvGameState *res = AtelGetCtrlWork(s->h40);
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
        func_001458B0(a->id, first, second, s->h3C);
    }
}

void func_00142070(Actor *a, ObjNodeR *n) {
    ActorBind *s;
    int slot;
    int w;

    if (n) {
        slot = n->u0E.h & 0xF;
        w = n->h08;
        s = func_0013C9C8(a, slot);
        a->slotIdx = slot;
        a->h2C = w;
        func_0013C9C8(a, slot)->b1D = 0;
        s->h3E = n->h12;
        s->h3C = n->h10;
        s->h40 = n->h14;
        func_00142B50(a, s, slot);
        func_00141FF0(a, s);
        func_0013CAD0(a, s, func_0013CA30(a, w));
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

void func_00142218(Actor *a, void *p) {
    NodeQ *n = p;
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

typedef struct ObjNodeR_Bits2 {
    struct ObjNodeR_Bits2 *next;
    struct ObjNodeR_Bits2 *prev;
    u16 h08;
    u16 h0A;
    union {
        u32 w0C;
        struct {
            unsigned h0C : 16;
            unsigned level : 4;
            unsigned kind : 3;
            unsigned flag : 1;
            unsigned b0F : 8;
        } b;
    } u0C;
    u16 h10;
    u16 h12;
    u16 h14;
} ObjNodeR_Bits2;

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
        if (n->u0E.b.hi != 3 && (n->u0E.h & 0xF) == r->wC) {
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
        if (n->u0E.b.hi != 3 && n->h08 == r->w10) {
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
    if (n && n->u0E.b.hi == 1) {
        func_00142530(a->id, n->h0A, 3, n->u0E.h & 0xF, n->h08);
    }
}

void func_001426F0(Actor *a, ObjNodeR *n) {
    if (n && n->u0E.b.hi == 2) {
        func_00142530(a->id, n->h0A, 3, n->u0E.h & 0xF, n->h08);
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
        if (n->u0E.b.hi != 3 && n->h08 == x) {
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
        if (n->u0E.b.hi != 3 && (n->u0E.h & 0xF) >= x) {
            r = 1;
            break;
        }
        n = next;
    }
    return r;
}

void AtelDecodeSignal(int id, int level)
{
    Actor *a = AtelGetBasicWork(id);
    ObjNodeR *head;
    ObjNodeR *pick;

    if (!(a->flags34.w & 2)) {
        return;
    }
    if (a->flags34.w & 4) {
        goto check_b3;
    }
    if (a->flags34.w & 0x400000) {
        goto check_b3;
    }
    if (MsBattleCheck() != 0) {
        return;
    }
check_b3:
    if (!(a->flags34.w & 8)) {
        return;
    }
    pick = 0;
    {
        int cur = a->slotIdx;
        if (level < 0) {
            level = cur;
        }
    }
    if (level >= 10) {
        level = -1;
    }
    head = OBJR(a)->head80;
    if (head != 0 && head->u0E.b.hi != 3 && (head->u0E.h & 0xF) > level) {
        pick = head;
    }
    if (pick != 0) {
        if ((((ObjNodeR_Bits2 *)pick)->u0C.w0C & 0x700000) == 0x100000) {
            func_00142070(a, pick);
            func_001426B8(a, pick);
            ((ObjNodeR_Bits2 *)pick)->u0C.b.kind = 2;
        } else {
            a->slotIdx = ((ObjNodeR_Bits2 *)pick)->u0C.b.level;
            func_00141FF0(a, func_0013C9C8(a, a->slotIdx));
        }
        a->node90 = pick;
    }
    head = OBJR(a)->head80;
    while (head != 0) {
        ObjNodeR *next = head->next;
        ((ObjNodeR_Bits2 *)head)->u0C.w0C &= ~0x800000;
        head = next;
    }
}

typedef struct ObjNodeR_Bits {
    struct ObjNodeR_Bits *next;
    u8 p04[8];
    union {
        u32 w0C;
        struct {
            unsigned pad0C : 16;
            unsigned level : 4;
            unsigned kind : 3;
            unsigned flag : 1;
            unsigned pad0F : 8;
        } b;
    } u0C;
} ObjNodeR_Bits;

int func_00142988(Actor *a, int b, int c) {
    ObjNodeR_Bits *n = (ObjNodeR_Bits *)OBJR(a)->head80;
    ObjNodeR_Bits *next;
    int kind;

    b++;
    while (n != 0) {
        next = n->next;
        if (n->u0C.b.level >= b) {
            kind = (n->u0C.w0C >> 20) & 7;
            if (c != 2 || (n->u0C.w0C & 0x800000) == 0) {
                switch (kind) {
                case 1:
                    func_001426B8(a, (ObjNodeR *)n);
                    /* fallthrough */
                case 2:
                    if (c == 1) {
                        goto check_kind;
                    }
                    func_001426F0(a, (ObjNodeR *)n);
                    break;
                }
                if (c == 1) {
                check_kind:
                    if (kind == 2) {
                        goto next_node;
                    }
                }
                func_00142218(a, n);
                if (a->node90 == (ObjNodeR *)n) {
                    a->node90 = 0;
                }
            }
        }
    next_node:
        n = next;
    }
}

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

void func_00142B50(Actor *a, ActorBind *s, int n) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    ObjSlotR *temp_v0;
    ObjSlotBR *temp_v1;

    if (a->hdr->type == 1) {
        temp_v0 = &OBJR(a)->slot[n];
        temp_v1 = &OBJR(a)->slotB[n];
        ((ObjBindR *)s)->s44 = temp_v0;
        ((ObjBindR *)s)->s48 = temp_v1;
        temp_v0->f08 = 0.0f;
        temp_v0->fC = 0.0f;
        temp_v0->h0 = 0;
        temp_v1->h0 = 0;
        temp_v0->h2 = 0;
        temp_v1->h2 = 0;
        temp_v0->f1C = st->x;
        temp_v0->f20 = st->y;
        temp_v0->f24 = st->z;
        temp_v0->w14 = 0;
        temp_v0->f28 = st->x;
        temp_v0->f2C = st->y;
        temp_v0->f30 = st->z;
        temp_v0->f34 = 0.0f;
        *(float *)temp_v0->p18 = 0.0f;
        temp_v0->f44 = 0.0f;
        temp_v0->f48 = 0.0f;
        temp_v1->f20 = 0.0f;
        temp_v1->f24 = 0.0f;
        temp_v1->f28 = 0.0f;
        temp_v1->f2C = 0.0f;
        temp_v1->f30 = 0.0f;
        temp_v1->f34 = 0.0f;
    }
}

void func_00142C40(Actor *a, ObjBindR *b, s32 n) {
    ObjSlotR *temp_3;
    ObjSlotBR *temp_4;

    temp_3 = &OBJR(a)->slot[n];
    temp_3->f10 = 0.0f;
    temp_3->f3C = 3.1415927f;
    temp_3->f40 = 3.1415927f;
    temp_4 = &OBJR(a)->slotB[n];
    temp_4->f10 = 0.049087387f;
    temp_4->f14 = 0.049087387f;
    temp_4->f18 = 0.049087387f;
    temp_3->h4 = 0x5A;
    temp_3->h6 = 0;
    temp_4->f1C = 0.049087387f;
    temp_4->h4 = 0x5A;
    temp_4->h6 = 0;
    b->s44 = temp_3;
    temp_3->f38 = 1.0f;
    b->s48 = temp_4;
}

void func_00142CC0(Actor *a, int n)
{
    ActorBind *slot;

    func_0013C9C8(a, n)->b1D = 0;
    slot = func_0013C9C8(a, n);
    func_00141FF0(a, slot);
    func_0013CAD0(a, slot, func_0013CA30(a, 0));
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
    func_00142218(actor, actor->node90);
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
        func_00141FF0(actor, binding);
        func_0013CAD0(actor, binding, func_0013CA30(actor, 1));
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
    func_00142218(actor, actor->node90);
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
        func_00141FF0(actor, binding);
        func_0013CAD0(actor, binding, func_0013CA30(actor, 1));
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

    D_0058E3D8->f210.b.b0 = (v != 0);
    AtelSetCurrentCtrl(old);
}

int func_001431C0(void) {
    int old = AtelChangeCurrentCtrl(0);
    int r = D_0058E3D8->f210.b.b0;

    AtelSetCurrentCtrl(old);
    return r;
}

int func_00143200(int v) {
    func_00124828()->control10.b.b25 = (v != 0);
}

int func_00143248(void) {
    return func_00124828()->control10.b.b25;
}

void func_00143270(int v) {
    func_00124828()->control10.b.b26 = (v != 0);
}

int func_001432B8(void) {
    return func_00124828()->control10.b.b26;
}

int func_001432E0(void) {
    Rec124828 *r = func_00124828();
    int v;

    if (MsBattleCheck() != 0) {
        return 0;
    }
    v = func_00173690();
    if (v >= 0) {
        r->x29 = v & 1;
    }
    return r->x29;
}

void func_00138BD8(int v);

void AtelUpdateWaterStatus(void) {
    float pos[4];
    int old = AtelChangeCurrentCtrl(0);

    if (func_001432E0() == 0) {
        if (D_0058E3D8->flags & 0x10000) {
            MsCameraGetPosNow(1, pos);
            if (((EvGameState *)D_0058E3D8)->f208 <= pos[1]) {
                func_00138BD8(1);
            } else {
                func_00138BD8(0);
            }
        } else {
            func_00138BD8(0);
        }
    } else {
        func_00138BD8(1);
    }
    AtelSetCurrentCtrl(old);
}

typedef struct {
    s32 f00;
    u8 pad04[6];
    u16 h0A;
    u8 pad0C[0x1E8];
    u32 f1F4;
    u8 pad1F8[0x18];
    u32 f210;
    u8 pad214[4];
    float f218;
    float f21C;
    float f220;
    u8 pad224[4];
    float f228;
    float f22C;
    float f230;
} AtelBtlWork; /* DEBT(NAME): AtelCtrlWork offset view for AtelUpdateBattleStatus */

typedef struct {
    void *f0;
    void *f4;
    int (*f8)(int);
} CdDrvView; /* DEBT(NAME): GetCD driver vtable view */

extern int func_00145188(int);
extern void MsBattleExeClear(void);
extern float func_002D4278(float, float, float);
extern float func_002D4290(float);
extern int MsBattleCheck(void);
extern void MsWalkAbilityProcess(float);
extern int func_002D6768(void);
extern int func_0013A278(void);
extern int func_0014AF40(int);
extern void MsBattleEncountExe(int, int, float);

#define BTL_W ((AtelBtlWork *)D_0058E3D8) /* DEBT(CAST): offset view */

void AtelUpdateBattleStatus(void)
{
    int enc = 0;
    int walk = 0;
    CdDrvView *cd = (CdDrvView *)GetCD(); /* DEBT(CAST): GetCD vtable view */
    float enc_dist = 0.0f;

    AtelChangeCurrentCtrl(0);
    if (func_00145188(0) != 0) {
        u32 *rec = (u32 *)func_00124828(); /* DEBT(CAST): Rec124828 word view */
        float dist;
        if ((BTL_W->f210 >> 1) & 1) {
            MsBattleExeClear();
        }
        dist = func_002D4290(func_002D4278(
            BTL_W->f228 - BTL_W->f218,
            BTL_W->f22C - BTL_W->f21C,
            BTL_W->f230 - BTL_W->f220));
        if (BTL_W->h0A != 0xFFFF && (BTL_W->f00 & 0x8400051AU) == 0xA && BTL_W->f1F4 >= 7) {
            u32 w = BTL_W->f210;
            if ((w & 1) && (rec[4] & 0x6000000)) {
                if (!((w >> 2) & 1)) {
                    enc_dist = dist;
                    enc = 1;
                }
            }
            walk = 1;
        }
        if (walk != 0 && MsBattleCheck() == 0 && !(BTL_W->f00 & 0x3000000)) {
            MsWalkAbilityProcess(dist);
        }
        if (MsBattleCheck() == 0 && !(BTL_W->f00 & 0x3000000) && func_002D6768() == 0 && cd->f8(1) == 0 && enc != 0) {
            int a = func_0014AF40(func_0013A278());
            int b = func_00148870();
            MsBattleEncountExe(a, b, enc_dist);
        }
    }
    BTL_W->f00 &= ~0x100;
    BTL_W->f00 &= ~0x200;
}

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
