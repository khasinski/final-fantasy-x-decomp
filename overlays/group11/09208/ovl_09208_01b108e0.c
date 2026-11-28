#include "common.h"

struct Ctx108E0;

typedef struct {
    u8 pad00[0x1C];
    void (*update)(struct Ctx108E0 *);
} Vtbl108E0;

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
} Item108E0;

typedef struct Node108E0 {
    Vtbl108E0 *vtbl;
    struct Node108E0 *prev;
    struct Node108E0 *next;
    struct Node108E0 *tail;
    struct Node108E0 *head;
    struct Node108E0 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u8 pad1C[0x14];
    float vecs[9][4];
    Item108E0 items[8];
    u8 pad1540[0x1E0];
    s32 count;
    float gravity;
    u8 pad1728[0xC];
    u8 flags;
} Node108E0;

typedef struct Ctx108E0 {
    Node108E0 *node;
    u8 dirty;
    u8 tick;
} Ctx108E0;

typedef struct {
    Node108E0 *obj;
    Node108E0 *parent;
} Arg10B80;

extern void *g_sym_0904;
extern void fn_002dd0b0(void *, void *);
extern void fn_01b13bb0(void *);
extern float fn_001b63b8(s32);
extern s32 fn_001b53c0(s32);
extern float fn_001b73c8(s32);
extern void fn_01b13cc8(void *);
extern void fn_001c5e90(void *, s32, s32);

static inline void call_3bb0(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_01b13bb0(m);
}

static inline void call_3cc8(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_01b13cc8(m);
}

void ovl_09208_01b108e0(Ctx108E0 *a0) {
    float pos[4];
    Node108E0 *s2 = a0->node;

    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        Node108E0 *s0 = s2->head;
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
        Node108E0 *o = a0->node;
        Item108E0 *it;
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
                call_3bb0(it, pos);
                pos[0] = it->f240[1];
                if (it->f284 <= 0) {
                    pos[1] -= fn_001b63b8(it->f54) * 0.5f;
                } else {
                    if (fn_001b53c0(it->f54) != 0) {
                        pos[1] += fn_001b73c8(it->f54);
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
                            call_3cc8(it, &it->f210);
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

void ovl_09208_01b10b80(Arg10B80 *a0) {
    Node108E0 *v0 = a0->obj;
    Node108E0 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}
