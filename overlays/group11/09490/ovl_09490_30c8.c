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
} Work30C8;

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
} Obj30C8;

typedef struct {
    Obj30C8 objs[16];
    s32 unk5200;
    s32 unk5204;
    s32 unk5208;
    s32 unk520C;
} Sub8550_30C8;

typedef struct {
    u8 pad0[0x1300];
    Work30C8 unk1300;
    u8 pad1430[0x2F80 - 0x1430];
    Vec4 unk2F80;
    u8 pad2F90[0x8550 - 0x2F90];
    Sub8550_30C8 unk8550;
    u8 padD760[0xEC00 - 0xD760];
    float unkEC00;
} State30C8;

typedef struct {
    u8 pad0[0x14];
    Obj30C8 *unk14;
} Task30C8;

typedef struct {
    u8 pad0[0x56];
    u8 unk56;
} Arg30C8;

extern State30C8 *D_01B0B398;

extern s32 func_00116068(void);
extern s32 func_001ACEA0(void);
extern float func_002B3DB0(float);
extern void func_01B02CD0(void *);
extern void func_01B03080(void *);
extern void func_01B03E00(void *);
extern void func_01B04A88(s32, void *, s32);
extern Task30C8 *func_01B07000(void (*)(void *));
extern void func_01B071C8(void *);
extern void func_01B080C8(void *, void *, void *);
extern void func_01B081D0(void *, void *, void *);
extern float func_01B08270(void *, void *);

void func_01B030C8(Arg30C8 *arg0) {
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    State30C8 *s;
    Sub8550_30C8 *sub;
    Obj30C8 *obj;
    Vec4 *p270;
    register Vec4 *p260 __asm__("$19");
    Task30C8 *task;

    s = D_01B0B398;
    sub = &s->unk8550;

    if (sub->unk5200 > 0) {
        if (func_00116068() != 0) {
            sub->unk5200--;
        }
        return;
    }

    if (sub->unk5208 == 0) {
        MMI_COPY_LQ_A3(&v0, &s->unk2F80);
        MMI_COPY_SQ_A3(&v0);
    } else {
        func_01B03E00(&v0);
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
        func_01B081D0(&v1, &v0, &v2);
    }

    p260 = &obj->unk260;
    MMI_COPY_LQ_A3(p260, &v0);
    MMI_COPY_SQ_A3(p260);

    p270 = &obj->unk270;
    func_01B04A88(0, p270, 4);
    if (sub->unk5208 == 0) {
        obj->unk270.x += func_002B3DB0(4.0f);
        obj->unk270.y += func_002B3DB0(4.0f);
        obj->unk270.z += func_002B3DB0(4.0f);
    }

    func_01B080C8(&obj->unk280, p260, p270);
    obj->unk510 = (s32)(func_01B08270(p260, p270) / 6.0f);
    if (obj->unk510 < 0) {
        obj->unk510 = 1;
    }
    obj->unk514 = obj->unk510;
    obj->unk518 = 0;

    task = func_01B07000(func_01B02CD0);
    task->unk14 = obj;
    func_01B071C8(task);

    sub->unk5200 = (func_001ACEA0() % 8) + 4;
    sub->unk5204++;
    if (sub->unk5204 >= sub->unk520C) {
        Work30C8 *w = &s->unk1300;
        w->unk104 = func_01B03080;
        w->unk120 = 0x3C;
        arg0->unk56 = 1;
    }
}
