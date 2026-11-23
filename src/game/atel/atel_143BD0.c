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

typedef struct {
    u8 *hdr;
    void *blob;
    int w8;
    int arr0C[8];
    u16 h2C;
    u16 id;
    u16 h30;
    u8 b32;
    u8 b33;
    union {
        u32 w;
        struct {
            unsigned b0 : 1;
            unsigned b1 : 1;
            unsigned b2 : 1;
            unsigned b3 : 1;
            unsigned b4 : 1;
            unsigned b5 : 1;
            unsigned b6 : 1;
            unsigned b7 : 1;
            unsigned b8 : 1;
            unsigned b9 : 1;
            unsigned b10_12 : 3;
            unsigned b13_14 : 2;
            unsigned b15 : 1;
            unsigned b16 : 1;
            unsigned b17_18 : 2;
            unsigned b19 : 1;
            unsigned b20 : 1;
            unsigned b21 : 1;
            unsigned b22 : 1;
            unsigned b23_24 : 2;
            unsigned b25_26 : 2;
            unsigned b27 : 1;
            unsigned b28 : 1;
            unsigned b29_30 : 2;
            unsigned b31 : 1;
        } b;
    } w34;
    union {
        u32 w;
        struct {
            unsigned b0 : 1;
            unsigned b1 : 1;
            unsigned b2 : 1;
            unsigned b3 : 1;
            unsigned b4 : 1;
            unsigned b5 : 1;
            unsigned b6 : 1;
            unsigned b7 : 1;
            unsigned b8 : 1;
            unsigned b9 : 1;
            unsigned b10 : 1;
            unsigned b11 : 1;
            unsigned b12 : 1;
            unsigned pad : 19;
        } b;
    } w38;
    int w3C;
    u32 w40;
    int w44;
    int arr48[4];
    int arr58[10];
    int w80;
    int w84;
    int w88;
    int w8C;
    int w90;
    float f94;
    int w98;
    int w9C;
    int wA0;
    int wA4;
    u16 hA8;
    u8 bAA;
    u8 bAB;
    union {
        u32 w;
        struct {
            unsigned pad0 : 16;
            unsigned b16_19 : 4;
            unsigned b20_23 : 4;
            unsigned pad24 : 8;
        } b;
    } wAC;
    u8 padB0[8];
    int wB8;
    int wBC;
    int wC0;
    int wC4;
    u8 padC8[0xAE0 - 0xC8];
    int arrAE0[4];
    int wAF0;
    int arrAF4[2];
    int arrAFC[2];
    u16 arrB04[2];
    union {
        u32 w;
        ActorBits2 b;
    } arrB08[2];
    int wB10;
    u16 hB14;
    u16 hB16;
    struct {
        u16 h0;
        u16 h2;
        int w4;
        int w8;
        int wC;
    } ent[4];
} AtelInitView;

typedef struct {
    u8 pad0[0x3C];
    u16 h3C;
    u16 h3E;
    u16 h40;
} AtelBindInitView;

typedef struct {
    int flag;
    int id;
    int p2;
    int p3;
    int p4;
    u8 *hdr;
    void *blob;
    int w1C;
} AtelInitArg;

extern void func_00142CC0(Actor *a, int i);

void AtelInitBasicWork(AtelInitArg *arg, int clearMyWork)
{
    int flag = arg->flag;
    int id = arg->id;
    int p2 = arg->p2;
    int p3 = arg->p3;
    int p4 = arg->p4;
    u8 *hdr = arg->hdr;
    void *blob = arg->blob;
    int w1C = arg->w1C;
    AtelInitView *a = (AtelInitView *)AtelGetBasicWork(id);
    int i;
    int j;
    int type;
    ActorState *pos;
    AtelBindInitView *bind;
    int sig[8];

    a->blob = blob;
    a->w8 = w1C;
    a->hdr = hdr;
    a->id = id;
    for (i = 7; i >= 0; i--) {
        a->arr0C[i] = 0;
    }
    if (flag == 0) {
        return;
    }
    a->wAC.b.b16_19 = p2;
    a->wAC.b.b20_23 = p3;
    a->wB8 = 0;
    func_0013D7A0(&a->wC4);
    {
        u8 *h = a->hdr;
        int t;
        for (i = 3; i >= 0; i--) {
            a->arr48[i] = 0;
        }
        for (i = 9; i >= 0; i--) {
            a->arr58[i] = 0;
        }
        t = *h;
        if (t < 7) {
            if (t >= 5) {
                for (j = 0; j < 2; j++) {
                    AtelBindInitView *b = (AtelBindInitView *)func_0013C9C8((Actor *)a, j);
                    b->h40 = p2;
                    b->h3E = p3;
                    b->h3C = p4;
                    func_00142CC0((Actor *)a, j);
                }
                goto after_bind;
            }
        }
        for (j = 0; j < 9; j++) {
            bind = (AtelBindInitView *)func_0013C9C8((Actor *)a, j);
            bind->h40 = p2;
            bind->h3E = p3;
            bind->h3C = p4;
            func_00142CC0((Actor *)a, j);
            if (*a->hdr == 1) {
                func_00142C40((Actor *)a, (ActorBind *)bind, j);
            }
        }
    after_bind:;
    }
    func_0013D830(id, 1.0f);
    a->w34.b.b1 = 1;
    a->w34.b.b2 = 1;
    a->w34.b.b3 = 1;
    a->w34.b.b4 = 0;
    a->w34.b.b5 = 0;
    a->w34.b.b6 = 0;
    a->w34.b.b7 = 0;
    a->w34.b.b8 = 0;
    a->w34.b.b0 = 0;
    a->w34.b.b9 = 0;
    a->w34.b.b19 = 0;
    a->w34.b.b10_12 = 1;
    a->w34.b.b13_14 = 0;
    a->w34.b.b15 = 0;
    a->w34.b.b16 = 0;
    a->w34.b.b17_18 = 3;
    a->w34.b.b20 = 0;
    a->w34.b.b21 = 0;
    a->w38.b.b0 = 0;
    a->w38.b.b1 = 0;
    a->w38.b.b2 = 0;
    a->w38.b.b3 = 0;
    a->w38.b.b4 = 0;
    a->w38.b.b5 = 1;
    a->w38.b.b6 = 0;
    a->w38.b.b7 = 0;
    a->w38.b.b8 = 0;
    a->w38.b.b9 = 0;
    a->w38.b.b10 = 0;
    a->w38.b.b11 = 0;
    a->w38.b.b12 = 0;
    a->b33 = 0;
    a->b32 = 0;
    a->w84 = 0;
    a->w80 = 0;
    a->w8C = 0;
    a->w88 = 0;
    a->w90 = 0;
    a->wBC = 0;
    if (*(u16 *)((u8 *)D_0058E3D8 + 0x1A) < 2) {
        a->w34.b.b22 = 0;
    } else {
        a->w34.b.b22 = 1;
    }
    a->w34.b.b23_24 = 0;
    a->w34.b.b25_26 = 0;
    a->w34.b.b27 = 1;
    a->w34.b.b28 = 0;
    a->w34.b.b29_30 = 0;
    a->w34.b.b31 = 0;
    ((u8 *)a)[0xAF] = 0xF;
    a->w40 = 0xFFFFFFFF;
    a->f94 = 1.0f;
    a->w44 = 0;
    a->bAA = 0;
    a->hA8 = 0;
    a->w9C = 0;
    a->w98 = 0;
    a->w3C = 0;
    ((u8 *)a)[0xAD] = 0;
    type = *a->hdr;
    pos = AtelGetPosWorkAdrs((Actor *)a);
    switch (type) {
    case 4:
        a->w34.b.b7 = 1;
        break;
    case 1:
        for (i = 0; i < 2; i++) {
            a->arrAF4[i] = 0;
            a->arrAFC[i] = 0;
            a->arrB04[i] = 0;
            a->arrB08[i].b.b0 = 1;
            a->arrB08[i].b.b1 = 0;
            a->arrB08[i].b.rest = 0;
        }
        a->hB14 = 0;
        a->w34.b.b7 = 1;
        for (i = 0; i < 4; i++) {
            a->ent[i].w4 = 0;
            a->ent[i].w8 = 0;
            a->ent[i].h0 = 0;
            a->ent[i].h2 = 0;
            a->ent[i].wC = 0;
        }
    case 2:
    case 3:
    case 5:
    case 6:
        pos->h28 = 0xFFFF;
        pos->x = 0.0f;
        pos->y = 0.0f;
        pos->z = 0.0f;
        pos->f0C = 0.0f;
        pos->f1C = 0.0f;
        pos->px = 0.0f;
        pos->py = 0.0f;
        pos->pz = 0.0f;
        pos->f2C = -1.0f;
        pos->f20 = 0.0f;
        pos->f24 = 0.0f;
        pos->f34 = 0.0f;
        pos->f30 = 0.0f;
        pos->f38 = 0.0f;
        pos->f3C = 1.0471976f;
        pos->f4C = 1.0471976f;
        if (type == 1) {
            pos->f44 = 1.0f;
            pos->f40 = 2.0f;
            pos->f48 = 1.5f;
            pos->f1C = 5.0f;
            a->hB16 = 10;
            for (i = 3; i >= 0; i--) {
                a->arrAE0[i] = 0;
            }
            a->wAF0 = 0;
        } else {
            pos->f1C = -1.0f;
            pos->f48 = 1.0f;
            pos->f40 = 0.0f;
            pos->f44 = 0.0f;
        }
        break;
    }
    switch (*hdr) {
    case 1:
        a->bAB = 0xF7;
        break;
    case 4:
        a->bAB = 0;
        break;
    case 2:
    case 3:
    case 5:
    case 6:
        a->bAB = 0xFF;
        break;
    }
    func_001440C8((Actor *)a);
    if (clearMyWork != 0) {
        func_00143C60((Actor *)a);
    }
    {
        AtelBindInitView *b0 = (AtelBindInitView *)func_0013C9C8((Actor *)a, 0);
        sig[0] = 0xFFFF;
        sig[5] = b0->h40;
        sig[6] = b0->h3E;
        sig[7] = b0->h3C;
        sig[3] = 7;
        sig[1] = id;
        sig[2] = 0;
        sig[4] = 0;
    }
    AtelRegistSignal2((void *)sig);
    sig[3] = 0;
    sig[4] = 1;
    AtelRegistSignal2((void *)sig);
    AtelDecodeSignal(id, 10);
}

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

typedef struct {
    union {
        u32 w;
        struct {
            unsigned b0 : 1;
            unsigned b1 : 1;
            unsigned b2 : 1;
            unsigned b3 : 1;
            unsigned b4 : 1;
            unsigned b5 : 1;
            unsigned b6 : 1;
            unsigned b7 : 1;
            unsigned b8 : 1;
            unsigned b9 : 1;
            unsigned b10 : 1;
            unsigned b11 : 1;
            unsigned b12 : 1;
            unsigned b13 : 1;
            unsigned b14 : 1;
            unsigned b15 : 1;
            unsigned b16 : 1;
            unsigned b17 : 1;
            unsigned b18 : 1;
            unsigned b19 : 1;
            unsigned b20 : 1;
            unsigned b21 : 1;
            unsigned b22 : 1;
            unsigned b23 : 1;
            unsigned b24_25 : 2;
            unsigned b26 : 1;
            unsigned b27 : 1;
            unsigned b28 : 1;
            unsigned b29 : 1;
            unsigned b30 : 1;
            unsigned b31 : 1;
        } b;
    } f00;
    s16 h04;
    s16 h06;
    u8 b08;
    u8 pad09;
    u16 h0A;
    u16 h0C;
    u16 pad0E;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u16 h18;
    s16 h1A;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
    u8 pad38[0xC];
    s32 w44;
    s32 w48;
    s32 w4C;
    void *p50;
    s32 w54;
    s32 w58;
    s32 w5C;
    s32 w60;
    u8 pad64[0x40];
    struct {
        unsigned b0 : 8;
        unsigned b1 : 8;
        u8 pad[6];
    } subA4[32];
    struct {
        s32 w0;
        s32 w4;
    } sub1A4[8];
    u8 b1E4;
    u8 pad1E5[2];
    u8 b1E7;
    u16 h1E8;
    u8 b1EA;
    u8 pad1EB;
    s32 w1EC;
    s32 w1F0;
    s32 w1F4;
    s32 w1F8;
    s32 w1FC;
    s32 w200;
    s32 w204;
    s32 w208;
    s32 w20C;
    union {
        u32 w;
        struct {
            unsigned b0 : 1;
            unsigned b1 : 1;
            unsigned b2 : 1;
            unsigned b3 : 1;
            unsigned b4 : 1;
            unsigned b5 : 1;
            unsigned b6 : 1;
            unsigned pad : 25;
        } b;
    } f210;
    s32 w214;
    s32 w218;
    s32 w21C;
    s32 w220;
    float f224;
    s32 w228;
    s32 w22C;
    s32 w230;
    float f234;
} AtelCtrlWorkView;

AtelCtrlWorkView *AtelRequireCtrlWork(int a0, Actor *a1, s32 a2, s32 a3)
{
    AtelCtrlWorkView *r = (AtelCtrlWorkView *)AtelGetCtrlWork(a0);
    int i;

    r->f00.b.b0 = 0;
    r->f00.b.b2 = 0;
    r->f00.b.b3 = 0;
    r->f00.b.b7 = 1;
    r->f00.b.b21 = 0;
    r->f00.b.b4 = 0;
    r->f00.b.b8 = 0;
    r->f00.b.b9 = 0;
    r->f00.b.b14 = 0;
    r->f00.b.b15 = 1;
    r->f00.b.b10 = 0;
    r->f00.b.b26 = 0;
    r->f00.b.b31 = 0;
    r->f00.b.b11 = 1;
    r->f00.b.b24_25 = 0;
    r->f00.b.b22 = 1;
    r->f00.b.b1 = 0;
    r->f00.b.b5 = 0;
    r->f00.b.b6 = 0;
    r->f00.b.b12 = 1;
    r->f00.b.b13 = 0;
    r->f00.b.b16 = 0;
    r->f00.b.b17 = 0;
    r->f00.b.b18 = 0;
    r->f00.b.b19 = 1;
    r->f00.b.b23 = 1;
    r->f00.b.b27 = 0;
    r->f210.b.b0 = 1;
    r->f210.b.b1 = 0;
    r->f210.b.b2 = 0;
    r->f210.b.b3 = 1;
    r->f210.b.b4 = 0;
    r->f210.b.b5 = 0;
    r->w1C = a2;
    r->w24 = a3;
    r->p50 = (void *)AtelExecInitFunc;
    r->h04 = 4;
    r->h06 = 2;
    r->b1E7 = 0xFF;
    r->w20C = 0;
    r->w20 = 0;
    r->w28 = 0;
    r->w2C = 0;
    r->w30 = 0;
    r->w4C = 0;
    r->w58 = 0;
    r->w5C = 0;
    r->w60 = 0;
    r->w34 = 0;
    r->h1A = a0;
    r->w44 = 0;
    r->b1EA = 0;
    r->w200 = 0;
    r->w204 = 0;
    r->w1F8 = 0;
    r->w1FC = 0;
    r->w1F4 = 0;
    r->w54 = 0;
    r->b08 = 0;
    r->h0A = 0xFFFF;
    r->w48 = (s32)a1;
    r->w228 = 0;
    r->w22C = 0;
    r->w230 = 0;
    r->f234 = 1.0f;
    r->f224 = 1.0f;
    r->h1E8 = 0xFFFF;
    r->f00.b.b28 = 1;
    r->f00.b.b29 = 1;
    r->f00.b.b30 = 0;
    r->f210.b.b6 = 1;
    r->w214 = -1;
    r->w218 = 0;
    r->w21C = 0;
    r->w220 = 0;
    r->b1E4 = 0;
    r->w1EC = 0;
    r->w1F0 = 0;
    r->w208 = 0;
    if (a1 != 0) {
        r->h0C = AtelGetActorNumber(a1);
        r->h10 = AtelGetNamespaceNumber(a1);
        r->h12 = r->h0C;
        r->h14 = AtelGetLineNumber(a1);
        r->h18 = AtelGetELineNumber(a1);
        r->h16 = AtelGetBgNumber(a1);
    } else {
        r->h0C = 0;
        r->h10 = 0;
        r->h12 = 0;
        r->h14 = 0;
        r->h18 = 0;
        r->h16 = 0;
    }
    ((void (*)(int))func_00143BD0)(a0);
    for (i = 0; i < 32; i++) {
        r->subA4[i].b0 = 0;
        r->subA4[i].b1 = 0;
    }
    for (i = 7; i >= 0; i--) {
        r->sub1A4[i].w0 = 0;
    }
    ((void (*)(void))func_0013AC00)();
    return r;
}

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
