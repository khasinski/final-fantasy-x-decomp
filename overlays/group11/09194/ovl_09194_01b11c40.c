#include "common.h"

typedef struct Ovl09194Vtbl {
    u8 pad00[0x1C];
    void (*fn1C)(void *);
} Ovl09194Vtbl;

typedef struct Ovl09194Sub {
    Ovl09194Vtbl *vtbl;
    u8 pad04[0x1C];
    union {
        struct {
            s32 x;
            s32 y;
            s32 z;
            float w;
        } s;
        u_long128 q;
    } v20;
} Ovl09194Sub;

typedef struct Ovl09194Node {
    u8 pad00[0x20];
    u8 f20[0x10];
    u8 f30[0x10];
    u8 f40[0x10];
    u8 f50[0x10];
    u8 f60[0x10];
    u8 f70[0x10];
    u8 f80[0x20];
    u8 fA0[0x30];
    u8 fD0[0x10];
    u8 fE0[0x40];
    union {
        struct {
            s32 x;
            s32 y;
            s32 z;
            struct Ovl09194Node *parent;
        } s;
        u_long128 q;
    } v120;
    u8 f130[0xC];
    float f13C;
    Ovl09194Sub *f140;
    Ovl09194Sub *f144;
    Ovl09194Sub *f148;
    u8 b14C;
} Ovl09194Node;

typedef struct Ovl09194Arg {
    Ovl09194Node *node;
    u8 b4;
    u8 b5;
} Ovl09194Arg;

typedef struct Ovl09194Call {
    Ovl09194Sub *obj;
    u8 pad04;
    u8 b5;
    u8 pad06[0xA];
} Ovl09194Call;

void *memcpy(void *, const void *, u32);
extern void (*D_01B04AF0[])(void *, void *);
void func_01B12198(Ovl09194Arg *);
void func_01B122B0(void *, void *, void *);
void func_002DD068(void *, void *, float);
void func_002DD0B0(void *, void *);
void func_002DD0C0(void *, void *);
void func_002DD050(void *, void *, void *);
void func_002DCE38(void *, void *, void *);
void func_002DCE08(void *, void *, void *);

void func_01B11C40(register Ovl09194Arg *arg)
{
    Ovl09194Node *node = arg->node;
    Ovl09194Node *parent = node->v120.s.parent;
    float vec[4] __attribute__((aligned(16)));

    func_01B12198(arg);
    if ((u8)(arg->b4 & 1) == 0) {
        return;
    }
    {
        Ovl09194Call c;
        c.obj = node->f140;
        c.b5 = arg->b5;
        c.obj->vtbl->fn1C(&c);
    }
    {
        Ovl09194Call c;
        c.obj = node->f148;
        c.b5 = arg->b5;
        c.obj->vtbl->fn1C(&c);
    }
    {
        Ovl09194Call c;
        c.obj = node->f144;
        c.b5 = arg->b5;
        c.obj->vtbl->fn1C(&c);
    }
    if (node->v120.s.parent != 0) {
        Ovl09194Call c;
        c.obj = (Ovl09194Sub *)node->v120.s.parent;
        c.b5 = arg->b5;
        c.obj->vtbl->fn1C(&c);
    }
        D_01B04AF0[node->b14C](node->f60, &node->f148->v20);
        func_002DD068(vec, &node->f144->v20, node->f144->v20.s.w * 0.001f);
        func_002DD068(node->f20, node->f60, vec[0]);
        func_002DD068(node->f30, node->f70, vec[1]);
        func_002DD068(node->f40, node->f80, vec[2]);
        func_002DD0B0(node->f50, &node->f140->v20);
        if (parent == 0) {
            *(u_long128 *)&node->v120 = *(u_long128 *)&node->f148->v20;
            func_002DD0B0(node->f130, &node->f144->v20);
            node->f13C *= 1000.0f;
            func_002DD0C0(node->fE0, node->f60);
            func_002DD0C0(node->fA0, node->f20);
        } else {
            node->v120.s.x = parent->v120.s.x + node->f148->v20.s.x;
            node->v120.s.y = parent->v120.s.y + node->f148->v20.s.y;
            node->v120.s.z = parent->v120.s.z + node->f148->v20.s.z;
            func_002DD050(node->f130, parent->f130, &node->f144->v20);
            node->f13C *= 1000.0f;
            func_002DCE38(node->fE0, parent->fE0, node->f60);
            func_002DCE38(node->fA0, parent->fA0, node->f20);
            func_002DCE08(node->fD0, parent->fE0, node->f50);
            func_01B122B0(node->fD0, node->fD0, parent->fD0);
        }
}
