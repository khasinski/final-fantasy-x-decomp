#include "common.h"

struct CtxE6B8;

typedef struct {
    u8 pad00[0x1C];
    void (*update)(struct CtxE6B8 *);
} VtblE6B8;

typedef struct {
    u8 pad00[0x54];
    s32 f54;
    u8 pad58[0x1B8];
    u32 f210;
    s32 f214;
    u8 pad218[0x28];
    float f240[4];
    u8 pad250[0x30];
    float f280;
    s16 f284;
    u16 f286;
    s32 f288;
    float f28C;
} ItemE6B8;

typedef struct NodeE6B8 {
    VtblE6B8 *vtbl;
    struct NodeE6B8 *prev;
    struct NodeE6B8 *next;
    struct NodeE6B8 *tail;
    struct NodeE6B8 *head;
    struct NodeE6B8 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u8 pad1C[0x14];
    float vecs[8][4];
    ItemE6B8 items[8];
    u8 pad1530[0x1E0];
    s32 count;
    float gravity;
    u8 pad1718[0xC];
    u8 flags;
} NodeE6B8;

typedef struct CtxE6B8 {
    NodeE6B8 *node;
    u8 dirty;
    u8 tick;
} CtxE6B8;

typedef struct {
    NodeE6B8 *obj;
    NodeE6B8 *parent;
} ArgE968;

extern void *g_sym_0904;
extern void fn_002dd0b0(void *, void *);
extern void fn_01b11998(void *);
extern float fn_001b63b8(s32);
extern s32 fn_001b53c0(s32);
extern s32 fn_001b4e18(s32);
extern void fn_01b11ab0(void *);
extern void fn_001c5e90(void *, s32, s32);

static inline void call_1998(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_01b11998(m);
}

static inline void call_1ab0(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_01b11ab0(m);
}

void ovl_09199_01b0e6b8(CtxE6B8 *a0) {
    float pos[4];
    NodeE6B8 *s2 = a0->node;

    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        NodeE6B8 *s0 = s2->head;
        while (s0 != s2) {
            a0->node = s0;
            s0 = s0->next;
            a0->node->vtbl->update(a0);
        }
        a0->node = s2;
        s2->flag_1a = a0->tick;
        a0->dirty = 1;
    }

    if (a0->dirty & 1) {
        NodeE6B8 *o = a0->node;
        ItemE6B8 *it;
        s32 i;
        if (o->flags & 2) {
            it = o->items;
            for (i = 0; i < o->count; i++, it++) {
                fn_002dd0b0(it->f240, o->vecs[i]);
            }
        }
        if (o->flags & 4) {
            it = o->items;
            for (i = 0; i < o->count; i++, it++) {
                float vel;
                float ground;
                if (it->f286 & 1) {
                    continue;
                }
                it->f280 += o->gravity;
                call_1998(it, pos);
                pos[0] = it->f240[1];
                if (it->f284 <= 0) {
                    pos[1] -= fn_001b63b8(it->f54) * 0.5f;
                } else {
                    if (fn_001b53c0(it->f54) != 0 || fn_001b4e18(it->f54) == 4217) {
                        pos[1] += it->f28C;
                    }
                }
                vel = it->f280;
                if (vel >= 0.0f && (ground = pos[1], pos[0] + vel >= ground)) {
                    if (it->f284 > 0) {
                        it->f240[1] = ground;
                        it->f286 |= 1;
                    } else {
                        float t = (ground - it->f240[1]) / vel;
                        it->f284++;
                        it->f280 = vel * -0.22f;
                        it->f240[1] = ground - vel * t;
                        if (it->f284 > 0) {
                            call_1ab0(it, &it->f210);
                            fn_001c5e90(g_sym_0904, it->f54, 0);
                        }
                    }
                } else {
                    if (it->f284 <= 0) {
                        it->f214 += it->f288;
                    }
                    it->f240[1] += vel;
                }
            }
        }
    }
}

void ovl_09199_01b0e968(ArgE968 *a0) {
    NodeE6B8 *v0 = a0->obj;
    NodeE6B8 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}
