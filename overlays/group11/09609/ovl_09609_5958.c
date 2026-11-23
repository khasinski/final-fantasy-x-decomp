#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad0[0x104];
    void *unk104;
    u8 pad108[0x18];
    s32 unk120;
    u8 pad124[0xC];
} Work5958;

typedef struct {
    u8 pad0[0x260];
    Vec4 unk260;
    Vec4 unk270;
    Vec4 unk280;
    u8 pad290[0x280];
    s32 unk510;
    s32 unk514;
    s32 unk518;
    u8 pad51C[4];
} Obj5958;

typedef struct {
    Obj5958 objs[16];
    s32 unk5200;
    s32 unk5204;
    s32 unk5208;
    s32 unk520C;
} Sub8550_5958;

typedef struct {
    u8 pad0[0x8];
    u8 unk8[16];
} UnkECA4;

typedef struct {
    u8 pad0[0xF70];
    Work5958 unkF70;
    u8 pad10A0[0x2F80 - 0x10A0];
    Vec4 unk2F80;
    u8 pad2F90[0x8550 - 0x2F90];
    Sub8550_5958 unk8550;
    u8 padD760[0xEC00 - 0xD760];
    float unkEC00;
    u8 padEC04[0xA0];
    UnkECA4 *unkECA4;
} State5958;

typedef struct {
    u8 pad0[0x14];
    Obj5958 *unk14;
} Task5958;

typedef struct {
    u8 pad0[0x56];
    u8 unk56;
} Arg5958;

extern State5958 *D_01B0DF78;

extern s32 func_001ACEA0(void);
extern float func_002B3DB0(float);
extern void func_01B05530(void *);
extern void func_01B05910(void *);
extern void func_01B069A8(void *);
extern void func_01B075F8(s32, void *, s32);
extern Task5958 *func_01B09BB8(void (*)(void *));
extern void func_01B09D80(void *);
extern void func_01B0ADC0(void *, void *, void *);
extern void func_01B0AEC8(void *, void *, void *);
extern float func_01B0AF68(void *, void *);

void func_01B05958(Arg5958 *arg0) {
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    State5958 *s;
    Sub8550_5958 *sub;
    Obj5958 *obj;
    Vec4 *p270;
    register Vec4 *p260 __asm__("$19");
    Task5958 *task;
    s32 idx;

    s = D_01B0DF78;
    sub = &s->unk8550;

    if (sub->unk5200 > 0) {
        sub->unk5200--;
        return;
    }

    if (sub->unk5208 == 0) {
        MMI_COPY_LQ_A3(&v0, &s->unk2F80);
        MMI_COPY_SQ_A3(&v0);
    } else {
        func_01B069A8(&v0);
    }

    v1.x = 0.0f;
    obj = &sub->objs[sub->unk5204];
    v1.y = s->unkEC00;
    v1.z = 0.0f;
    v1.w = 0.0f;
    v2.x = 0.0f;
    v2.y = 0.0f;
    v2.z = 0.0f;
    v2.w = 1.0f;

    if (sub->unk5208 == 0) {
        v2.x = func_002B3DB0(5.0f);
        v2.y = func_002B3DB0(2.0f) + -16.0f;
        func_01B0AEC8(&v1, &v0, &v2);
    }

    p260 = &obj->unk260;
    MMI_COPY_LQ_A3(p260, &v0);
    MMI_COPY_SQ_A3(p260);

    p270 = &obj->unk270;
    idx = s->unkECA4->unk8[sub->unk5204];
    func_01B075F8(idx, p270, 4);
    if (sub->unk5208 == 0) {
        obj->unk270.x += func_002B3DB0(4.0f);
        obj->unk270.y += func_002B3DB0(4.0f);
        obj->unk270.z += func_002B3DB0(4.0f);
    }

    func_01B0ADC0(&obj->unk280, p260, p270);
    obj->unk510 = (s32)(func_01B0AF68(p260, p270) / 10.0f) + 1;
    if (obj->unk510 < 0) {
        obj->unk510 = 1;
    }
    obj->unk514 = obj->unk510;
    obj->unk518 = idx;

    task = func_01B09BB8(func_01B05530);
    task->unk14 = obj;
    func_01B09D80(task);

    sub->unk5200 = (func_001ACEA0() % 8) + 4;
    sub->unk5204++;
    if (sub->unk5204 >= sub->unk520C) {
        Work5958 *w = &s->unkF70;
        w->unk104 = func_01B05910;
        w->unk120 = 0x3C;
        arg0->unk56 = 1;
    }
}
