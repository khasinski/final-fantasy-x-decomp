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

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", func_00143ED8);

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", func_00143FB8);

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

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", func_00144810);

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", AtelInitSourceCodeDebugWork);

void func_00144938(void) {
    ResQ2 *r = (ResQ2 *)AtelGetCtrlWork_0();

    r->w0 &= ~1;
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
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_001449D0(s32 arg0) {
    Effect *temp_2;
    s32 temp_19;
    register s32 var_17 __asm__("$17");
    register s32 c1a0 __asm__("$20");

    var_17 = 0;
    temp_19 = func_00138C68();
    _m2c_func_001449D0_func_00138C78(arg0);
    c1a0 = 0x1A0;
    do {
        temp_2 = AtelGetMesWinWork(var_17);
        temp_2->h00 = 0;
        temp_2->h02 = 0;
        temp_2->h04 = 0x200;
        temp_2->h06 = c1a0;
        (*(s32 *)((u8 *)(temp_2) + (0x10))) = 0x50000080;
        (*(s32 *)((u8 *)(temp_2) + (0x28))) = 0;
        temp_2->w08 = (s32) D_0030B8C0;
        temp_2->kind = 0;
        temp_2->h16 = 0;
        temp_2->b1C = 0;
        temp_2->b1D = 0;
        temp_2->b1E = 0;
        temp_2->b1F = 0;
        var_17 += 1;
    } while (var_17 < 8);
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

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", AtelUpdateWindowStatus);

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
            /* DEBT(CAST): EffectQ provides the unsigned halfword view used here. */
            if (((EffectQ *)effect)->h16)
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

void *_m2c_AtelSetUpCtrlWork_AtelGetCtrlWork() __asm__("AtelGetCtrlWork");
s32 _m2c_AtelSetUpCtrlWork_func_00124828() __asm__("func_00124828");
s32 _m2c_AtelSetUpCtrlWork_func_0013AB38(s32, s32) __asm__("func_0013AB38");
extern s32 _m2c_AtelSetUpCtrlWork_AtelGetBasicWork __asm__("AtelGetBasicWork");
extern s32 _m2c_AtelSetUpCtrlWork_func_0013C920 __asm__("func_0013C920");
extern s32 _m2c_AtelSetUpCtrlWork_func_00140468 __asm__("func_00140468");
extern s32 _m2c_AtelSetUpCtrlWork_func_00140558 __asm__("func_00140558");
extern s32 _m2c_AtelSetUpCtrlWork_func_001406E8 __asm__("func_001406E8");
/* DEBT(CAST) */
void AtelSetUpCtrlWork(void) {
    void *temp_2;

    temp_2 = _m2c_AtelSetUpCtrlWork_AtelGetCtrlWork();
    (*(s32 *)((u8 *)(temp_2) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_2) + (0))) | 1);
    if ((*(s32 *)((u8 *)(temp_2) + (0x1C))) == 0) {
        _m2c_AtelSetUpCtrlWork_func_0013AB38(0, 8);
    }
    if ((*(s32 **)((u8 *)(temp_2) + (0x20))) == 0) {
        (*(s32 **)((u8 *)(temp_2) + (0x20))) = &_m2c_AtelSetUpCtrlWork_AtelGetBasicWork;
    }
    if ((*(s32 *)((u8 *)(temp_2) + (0x2C))) == 0) {
        (*(s32 *)((u8 *)(temp_2) + (0x2C))) = (s32) (_m2c_AtelSetUpCtrlWork_func_00124828() + 0x1EC);
    }
    if ((*(s32 **)((u8 *)(temp_2) + (0x4C))) == 0) {
        (*(s32 **)((u8 *)(temp_2) + (0x4C))) = &_m2c_AtelSetUpCtrlWork_func_0013C920;
    }
    if ((*(s32 **)((u8 *)(temp_2) + (0x58))) == 0) {
        (*(s32 **)((u8 *)(temp_2) + (0x58))) = &_m2c_AtelSetUpCtrlWork_func_00140468;
    }
    if ((*(s32 **)((u8 *)(temp_2) + (0x5C))) == 0) {
        (*(s32 **)((u8 *)(temp_2) + (0x5C))) = &_m2c_AtelSetUpCtrlWork_func_00140558;
    }
    if ((*(s32 **)((u8 *)(temp_2) + (0x60))) == 0) {
        (*(s32 **)((u8 *)(temp_2) + (0x60))) = &_m2c_AtelSetUpCtrlWork_func_001406E8;
    }
}

void func_00145148(int id)
{
    Res588R1 *r;

    func_0013AC00(id);
    r = (Res588R1 *)AtelGetCtrlWork(id);
    r->w1F4 = 0;
    r->w0 &= ~1;
}

int func_00145188(int id)
{
    return *(u8 *)AtelGetCtrlWork(id) & 1; /* DEBT(CAST): flag byte at the start of the resource */
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", AtelUcOff);

INCLUDE_ASM("build/ee_asm/game/atel/atel_143BD0", AtelUcOn);

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
