/* tu_077 0x143bd0-0x145938: low; ~Atel (config/tu_map.tsv) */
#define AtelSetUpCtrlWork _hdr_AtelSetUpCtrlWork
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r1.h"
#include "ffx/u0.h"
#undef AtelSetUpCtrlWork

void func_00143BD0(void) {
    int old = CALL0_AtelChangeCurrentCtrl();
    int i;

    for (i = 3; i >= 0; i--) {
        D_0058E3D8->ent[i].w0 = -1;
    }
    AtelSetCurrentCtrl(old);
}

int AtelGetMyWorkSize(int id) {
    return (OBJR(AtelGetBasicWork(id))->hdr[4] + 15) / 16 * 16;
}

void func_00143C60(Actor *a) {
    int *hdr = OBJR(a)->hdr;
    u8 *p = 0;
    int n = 0;

    if (hdr[0x2C / 4] != 0) {
        p = OBJR(a)->p4 + hdr[0x2C / 4];
        n = hdr[0x10 / 4];
    }
    if (OBJR(a)->pB8 != 0) {
        n = hdr[0x10 / 4];
        p = OBJR(a)->pB8;
    }
    if (p != 0 && n != 0 && n > 0) {
        do {
            *p++ = 0;
            n--;
        } while (n > 0);
    }
}

void func_00143CD8(int id, int v) {
    Actor *a = AtelGetBasicWork(id);

    OBJR(a)->pB8 = (u8 *)v;
    func_00143C60(a);
}

void AtelInitInternalActorWork(int id) {
    Actor *a = AtelGetBasicWork(id);
    int *arr1 = (int *)((char *)a + 0x58);
    int *arr0 = (int *)((char *)a + 0x48);
    int i;

    for (i = 3; i >= 0; i--) {
        arr0[i] = 0;
    }
    for (i = 9; i >= 0; i--) {
        arr1[i] = 0;
    }
}

int func_00143D78(void) {
    int old = AtelChangeCurrentCtrl(0);
    int r = ((ObjR *)D_0058E3D8->p48)->h18;

    AtelSetCurrentCtrl(old);
    return r;
}

int func_00143DB8(Actor *a) {
    int x = ((u16 *)a)[0x18 / 2]; /* DEBT(CAST): halfword at +0x18 */
    int r = 0;
    int t;

    if (x != 0xFFFF) {
        t = *(s16 *)(func_0013A2E8((char *)a, -1) + 6); /* DEBT(CAST): the actor used as a camera blob */
        if (t != 0) {
            func_00142530(0xFFFF, x, 0, 1, t);
            r = 1;
        }
    }
    return r;
}

/* DEBT(CAST): ObjR supplies the existing object-pool view and intrusive head sentinel. */
void func_00143E18(Actor *a)
{
    int type = a->hdr->type;
    ObjR *object = OBJR(a);
    ObjExtraPool *pool;
    ObjPoolNode *node;
    NodeQ *head;
    NodeQ *next;
    int remaining;

    if (type < 7) {
        if (type >= 5) {
            pool = object->extraPool;
            if (pool != 0) {
                node = pool->node;
                head = (NodeQ *)&object->p88;
                remaining = 15;
                do {
                    next = object->p88;
                    if (next != 0) {
                        next->prev = &node->link;
                    }
                    object->p88 = &node->link;
                    remaining--;
                    node->link.next = next;
                    node->link.prev = head;
                    node++;
                } while (remaining >= 0);
            }
        }
    }
}

void func_00143E78(Actor *a)
{
    int type = a->hdr->type;
    ObjExtraPool *pool;
    int index;

    if (type < 7) {
        if (type >= 5) {
            pool = OBJR(a)->extraPool;
            if (pool != 0) {
                for (index = 0; index < 8; index++) {
                    pool->slot[index].id = 0xFFFF;
                    pool->slot[index].count = 0;
                    pool->slot[index].flags = 3;
                }
            }
        }
    }
}

int func_00143ED8(Actor *a, int id)
{
    int type = a->hdr->type;
    int res = -1;
    ObjExtraPool *pool;
    u16 *p90;
    int i;

    if (type < 7) {
        if (type >= 5) {
            pool = OBJR(a)->extraPool;
            p90 = *(u16 **)((u8 *)a + 0x90);
            if (pool != 0 && p90 != 0) {
                u16 cnt = p90[4];
                if (id >= 0) {
                    for (i = 0; i < 8; i++) {
                        if (pool->slot[i].count == cnt && pool->slot[i].id == id) {
                            res = pool->slot[i].flags;
                            break;
                        }
                    }
                } else {
                    for (i = 0; i < 8; i++) {
                        if (pool->slot[i].count == cnt) {
                            res = pool->slot[i].flags;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (res == 3) {
        res = -1;
    }
    return res;
}

int func_00143FB8(Actor *a, int id, int count)
{
    int type = a->hdr->type;
    int idx = -1;
    ObjExtraPool *pool;
    int i;

    if (type < 7) {
        if (type >= 5) {
            pool = OBJR(a)->extraPool;
            if (pool != 0) {
                for (i = 0; i < 8; i++) {
                    if (pool->slot[i].id == id) {
                        idx = i;
                    }
                }
                if (idx < 0) {
                    for (i = 0; i < 8; i++) {
                        if (pool->slot[i].id == 0xFFFF || pool->slot[i].count == 0) {
                            idx = i;
                        }
                    }
                }
                if (idx >= 0) {
                    pool->slot[idx].id = id;
                    pool->slot[idx].count = count;
                    pool->slot[idx].flags = 3;
                }
            }
        }
    }
    if (idx >= 0) {
        idx = 1;
    } else {
        idx = 0;
    }
    return idx;
}

int func_00144080(Actor *a, int v) {
    int type = a->hdr->type;

    if (type < 7) {
        if (type >= 5) {
            *(int *)((char *)a + 0x2E4) = v; /* DEBT(CAST): pool pointer at +0x2E4 */
        }
    }
    func_00143E18(a);
    func_00143E78(a);
}

/* DEBT(CAST): ObjR is the existing object-pool view of Actor; the head is an intrusive-list sentinel. */
void func_001440C8(Actor *a)
{
    int type = a->hdr->type;
    ObjR *object = OBJR(a);
    NodeQ *head;
    NodeQ *next;
    ObjPoolNode *node;
    int remaining;

    if (type < 7) {
        head = (NodeQ *)&object->p88;
        if (type >= 5) {
            object->extraPool = 0;
            node = object->node1C4;
            remaining = 7;
            do {
                next = object->p88;
                if (next != 0) {
                    next->prev = &node->link;
                }
                object->p88 = &node->link;
                remaining--;
                node->link.next = next;
                node->link.prev = head;
                node++;
            } while (remaining >= 0);
            return;
        }
    } else {
        head = (NodeQ *)&object->p88;
    }
    node = object->node3D8;
    remaining = 15;
    do {
        next = object->p88;
        if (next != 0) {
            next->prev = &node->link;
        }
        object->p88 = &node->link;
        remaining--;
        node->link.next = next;
        node->link.prev = head;
        node++;
    } while (remaining >= 0);
}

u8 *func_00144158(Actor *a) {
    return &a->idC0;
}

u8 *AtelGetBattleIdAdrs(int id) {
    return func_00144158(AtelGetBasicWork(id));
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", AtelInitBasicWork);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_143BD0/rodata", jtbl_0056AD00);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_143BD0/rodata", jtbl_0056AD20);

/* DEBT(CAST) */
s32 func_00144810(s32 a) {
    s32 temp_2;
    s32 var_16;
    s32 var_17 = 0;
    s8 *temp_2_2;

    temp_2 = AtelGetActorNumber((Actor *) a);
    for (var_16 = 0; var_16 < temp_2; var_16++) {
        temp_2_2 = AtelGetIndexWork((Actor *) a, var_16);
        var_17 += (((*(s32 *)((u8 *)(temp_2_2) + (0x10))) + 0xF) / 16) * 0x10;
    }
    return var_17;
}

typedef struct SrcDebugEnt {
    int a, b, c;
} SrcDebugEnt;

typedef struct SrcDebug {
    int count;
    SrcDebugEnt ent[8];
} SrcDebug;

void AtelInitSourceCodeDebugWork(int id, SrcDebug *src)
{
    if (src != 0) {
        ActorH1 *x = (ActorH1 *)AtelGetBasicWork(id);
        int i = src->count - 1;
        i = (i >= 0) ? ((i < 8) ? i : 7) : 0;
        for (; i >= 0; i--) {
            x->wC[i] = src->ent[i].a;
        }
    }
}

void func_00144938(void) {
    EvGameState *r = AtelGetCtrlWork_0();

    r->flags.w &= ~1;
    r->w48 = 0;
}

/* DEBT(TYPE): declared with a return type (shared header) but no value is returned; callers ignore it */
int func_00144968(int id)
{
    ActorState *st;
    Sys3D8 *s;
    float x, y, z;

    D_0058E3D8->hA = id;
    if (id != 0xFFFF) {
        st = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
        s = D_0058E3D8;
        x = st->x;
        y = st->y;
        z = st->z;
        s->prev[0] = x;
        s->prev[1] = y;
        s->prev[2] = z;
        s->cur[0] = x;
        s->cur[1] = y;
        s->cur[2] = z;
    }
}

int _m2c_func_001449D0_func_00138C78(int) __asm__("func_00138C78");
void func_001449D0(s32 arg0) {
    Effect *temp_2;
    s32 temp_19;
    s32 var_17;

    temp_19 = func_00138C68();
    _m2c_func_001449D0_func_00138C78(arg0);
    for (var_17 = 0; var_17 < 8; var_17++) {
        temp_2 = AtelGetMesWinWork(var_17);
        temp_2->h00 = 0;
        temp_2->h02 = 0;
        temp_2->h04 = 0x200;
        temp_2->h06 = 0x1A0;
        temp_2->w10 = 0x50000080;
        temp_2->w28 = 0;
        temp_2->w08 = (s32) D_0030B8C0;
        temp_2->kind = 0;
        temp_2->h16 = 0;
        temp_2->b1C = 0;
        temp_2->b1D = 0;
        temp_2->b1E = 0;
        temp_2->b1F = 0;
    }
    _m2c_func_001449D0_func_00138C78(temp_19);
}

void func_00144A90(void) {
    int i = 0;

    do {
        func_001449D0(i);
        i++;
    } while (i < 2);
}

int func_00144AC8(void) {
    return AtelGetMesWinWork_0()->kind;
}

typedef struct SysWinView {
    union {
        u32 w;
        s32 i;
        struct {
            unsigned b0 : 10;
            unsigned b10 : 1;
            unsigned b11 : 17;
            unsigned b28 : 1;
            unsigned b29 : 2;
            unsigned b31 : 1;
        } b;
    } flags;
    u8 pad4[0x1A - 4];
    u16 h1A;
    u8 pad1C[0x1EA - 0x1C];
    u8 b1EA;
} SysWinView;
#define SYSW() ((SysWinView *)D_0058E3D8)

void AtelUpdateWindowStatus(void)
{
    int v21 = 0;
    int v19 = 0;
    int v18 = 0;
    int i;

    for (i = 0; i < 8; i++) {
        Effect *eff = AtelGetMesWinWork(i);
        eff->kind = TOGetWindowStatus(i);
        if (eff->kind == 4) {
            eff->kind = 0;
        }
        if (eff->kind != 0) {
            if (eff->b1D & 2) {
                v18 = 1;
            }
        }
        if (eff->kind == 2) {
            if (eff->b1D & 0x32) {
                v21 = i;
            }
        }
    }
    if (SYSW()->h1A == 0) {
        if (SYSW()->b1EA != 0 && !func_0014F158() && !func_00138C68() && !MsBattleCheck()) {
            int c = SYSW()->b1EA;
            c--;
            if (c == 0) {
                SYSW()->flags.b.b31 = 0;
                v19 = 1;
            }
            if (c < 0) {
                c = 0;
            }
            SYSW()->b1EA = c;
        }
        if (SYSW()->flags.b.b10 != v18) {
            if (!(SYSW()->flags.w & 0x800)) {
                SYSW()->flags.b.b10 = 0;
            } else {
                SYSW()->flags.b.b10 = v18;
            }
            v19 = 1;
        }
        if (v19) {
            func_00145470();
        }
        SYSW()->flags.b.b28 = ((SYSW()->flags.w & 0x402) != 2);
    }
    func_0020B6A8(v21);
}

int func_00144CD0(void)
{
    int i;
    Effect *effect;
    u8 flags;

    for (i = 0; i < 8; i++)
    {
        effect = AtelGetMesWinWork(i);
        if ((u32)(effect->kind - 1) < 2U)
        {
            flags = effect->b1D;
            if (flags & 0x22)
                return 2;
            if (effect->h16)
                return 1;
            if (flags & 0x10)
                return 1;
        }
    }
    return 0;
}

void func_00144D48(int v) {
    D_0058E3D8->w44 = v;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", AtelRequireCtrlWork);

EvGameState *_m2c_AtelSetUpCtrlWork_AtelGetCtrlWork() __asm__("AtelGetCtrlWork");
s32 _m2c_AtelSetUpCtrlWork_func_00124828() __asm__("func_00124828");
s32 _m2c_AtelSetUpCtrlWork_func_0013AB38(s32, s32) __asm__("func_0013AB38");
extern s32 _m2c_AtelSetUpCtrlWork_AtelGetBasicWork __asm__("AtelGetBasicWork");
extern s32 _m2c_AtelSetUpCtrlWork_func_0013C920 __asm__("func_0013C920");
extern s32 _m2c_AtelSetUpCtrlWork_func_00140468 __asm__("func_00140468");
extern s32 _m2c_AtelSetUpCtrlWork_func_00140558 __asm__("func_00140558");
extern s32 _m2c_AtelSetUpCtrlWork_func_001406E8 __asm__("func_001406E8");

void AtelSetUpCtrlWork(void) {
    EvGameState *temp_2;

    temp_2 = _m2c_AtelSetUpCtrlWork_AtelGetCtrlWork();
    temp_2->flags.w |= 1;
    if (temp_2->w1C == 0) {
        _m2c_AtelSetUpCtrlWork_func_0013AB38(0, 8);
    }
    if (temp_2->p20 == 0) {
        temp_2->p20 = &_m2c_AtelSetUpCtrlWork_AtelGetBasicWork;
    }
    if (temp_2->w2C == 0) {
        temp_2->w2C = _m2c_AtelSetUpCtrlWork_func_00124828() + 0x1EC;
    }
    if (temp_2->p4C == 0) {
        temp_2->p4C = &_m2c_AtelSetUpCtrlWork_func_0013C920;
    }
    if (temp_2->p58 == 0) {
        temp_2->p58 = &_m2c_AtelSetUpCtrlWork_func_00140468;
    }
    if (temp_2->p5C == 0) {
        temp_2->p5C = &_m2c_AtelSetUpCtrlWork_func_00140558;
    }
    if (temp_2->p60 == 0) {
        temp_2->p60 = &_m2c_AtelSetUpCtrlWork_func_001406E8;
    }
}

void func_00145148(int id)
{
    EvGameState *r;

    func_0013AC00(id);
    r = AtelGetCtrlWork(id);
    r->w1F4 = 0;
    r->flags.w &= ~1;
}

int func_00145188(int id)
{
    return AtelGetCtrlWork(id)->flags.byte & 1;
}

void AtelUcOff(void)
{
    int i = 0;
    int total = AtelGetCtrlworkActorTotal((char *)D_0058E3D8);

    for (; i < total; i++) {
        int type = AtelGetActorType(i);
        if (type == 1) {
            Actor *a = AtelGetBasicWork(i);
            ActorState *pos = AtelGetPosWorkAdrs(a);
            if (AR(a)->stateAA == type) {
                if (AR(a)->w34.w & 0x20) {
                    AR(a)->w34.b.b5 = 0;
                    pos->f0C = 0.0f;
                    if (AR(a)->ptr9C) {
                        Ch_SetSp(AR(a)->ptr9C, 0.0f);
                    }
                }
            }
        }
    }
    Sg_SetPlayer(0);
    SYS()->flags.b.b1 = 0;
}

void AtelUcOn(void)
{
    int set = 0;
    int i;
    int total = AtelGetCtrlworkActorTotal((char *)D_0058E3D8);

    if (!(SYS()->flags.w & 0x84000400)) {
        for (i = 0; i < total; i++) {
            if (AtelGetActorType(i) == 1) {
                Actor *a = AtelGetBasicWork(i);
                int ok;
                if (SYS()->flags.w & 0x20) {
                    ok = (AR(a)->w34.w >> 19) & 1;
                } else {
                    ok = (AR(a)->w34.w >> 9) & 1;
                }
                if (AR(a)->stateAA == 1 && *(u32 *)((u8 *)a + 0x40) != 0xFFFFFFFFL && ok) {
                    AR(a)->w34.b.b5 = 1;
                    if (AR(a)->id == SYS()->hA && AR(a)->ptr9C) {
                        Sg_SetPlayer((s32)AR(a)->ptr9C);
                        set = 1;
                    }
                }
            }
        }
    }
    if (!set) {
        Sg_SetPlayer(0);
    }
    SYS()->flags.b.b1 = 1;
}

void func_00145400(void)
{
    int f = (SYS()->flags.w & 0x22) != 0;

    AtelUcOff();
    if (!(SYS()->flags.w & 0x84000400) && f) {
        AtelUcOn();
    }
}

void func_00145470(void)
{
    int f = (SYS()->flags.w >> 1) & 1;

    func_00145400();
    SYS()->flags.b.b1 = f;
}

int func_001454C8(Actor *a, int on)
{
    if (on) {
        AR(a)->w34.b.b9 = 1;
    } else {
        AR(a)->w34.b.b9 = 0;
    }
    return AR(a)->w34.b.b9;
}

int func_001454F8(Actor *a, int on)
{
    if (on) {
        AR(a)->w34.b.b19 = 1;
    } else {
        AR(a)->w34.b.b19 = 0;
    }
    return AR(a)->w34.b.b19;
}

int AtelGetNowCtrlTopId(void)
{
    int h = SYS()->hA;

    if (h == 0xFFFF) {
        h = -1;
    }
    return h;
}

int func_00145558(void)
{
    int a = AtelChangeCurrentCtrl(0);
    int r = AtelGetNowCtrlTopId();

    AtelSetCurrentCtrl(a);
    return r;
}

int func_001455A0(void)
{
    AtelGetCtrlworkActorTotal((char *)D_0058E3D8);
    return D_0058E3D8->hC;
}

int AtelGetTotalActorNumber2(void)
{
    Sys3D8 *s = D_0058E3D8;
    int a = s->h14;
    int c = s->h16;
    int b = s->h18;

    return AtelGetCtrlworkActorTotal((char *)s) - (a + b + c);
}

int func_00145628(Actor *a) {
    return a->id;
}

int func_00145630(ActorV *a) {
    return a->fAC.h.hi & 0xF;
}

int func_00145640(ActorV *a) {
    return (a->fAC.w >> 20) & 0xF;
}

void AtelSetCtrlChar(int v)
{
    if (v >= 0) {
        if (!(SYS()->flags.w & 0x40)) {
            SYS()->flags.w |= 0x40;
            SYS()->hE = SYS()->hA;
        }
    } else {
        if (SYS()->flags.w & 0x40) {
            v = SYS()->hE;
            SYS()->flags.i &= ~0x40;
        } else {
            v = -1;
        }
    }
    if (SYS()->hA != 0xFFFF) {
        func_001454F8(AtelGetBasicWork(SYS()->hA), 0);
        func_00145470();
    }
    if (v >= 0 && v != 0xFFFF) {
        func_00144968(v);
        func_001454F8(AtelGetBasicWork(v), 1);
        SYS()->flags.w |= 0x20;
    } else {
        SYS()->flags.i &= ~0x20;
    }
    func_00145470();
}

void func_00145760(int from, int to)
{
    Sys3D8 *saved = D_0058E3D8;
    int i;

    func_0013A940();
    for (i = from; i < to; i++) {
        AtelChangeCurrentCtrl(i);
        D_0058E3E0 = i;
        if (SYS()->b8 < 3) {
            if (SYS()->flags.w & 1) {
                SYS()->f4C(SYS());
                if (SYS()->flags.w & 8) {
                    SYS()->w1F4++;
                }
            }
            if (SYS()->b8 == 1 || SYS()->b8 == 2) {
                SYS()->b8 = 3;
            }
        }
    }
    D_0058E3D8 = saved;
    AtelUpdateWindowStatus();
}

void func_00145858(void)
{
    func_00145760(0, 6);
}

void func_00145868(void)
{
    func_00145760(6, 7);
}

void AtelInitActor(void)
{
    if (SYS()->f50) {
        SYS()->f50(SYS());
    }
}

void func_001458A8(void)
{
    func_0014E800();
}

void func_001458B0(int id, int b, int c, int d)
{
    ActorH1 *x;
    int i;
    char *p;

    x = (ActorH1 *)AtelGetBasicWork(id);
    p = AtelGetIndexWork((Actor *)b, d); /* DEBT(TYPE): the first argument is passed through as an int */
    x->w4 = b;
    x->w8 = c;
    x->p0 = p;
    for (i = 7; i >= 0; i--) {
        x->wC[i] = 0;
    }
}
