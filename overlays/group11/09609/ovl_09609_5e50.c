#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad0[0xC0];
    Vec4 unkC0;
    Vec4 unkD0;
    u8 padE0[0x50];
} Work5E50;

typedef struct {
    Work5E50 unk0;
    Work5E50 unk130;
    Vec4 unk260;
    Vec4 unk270;
    Vec4 unk280;
    u8 pad290[0x280];
    s32 unk510;
    s32 unk514;
    s32 unk518;
    u8 pad51C[4];
} Obj5E50;

typedef struct {
    Obj5E50 objs[4];
    s32 unk1480;
    s32 unk1484;
} SubD770;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 unk8[16];
} UnkECA4;

typedef struct {
    u8 pad0[0x2730];
    u8 unk2730[0xD770 - 0x2730];
    SubD770 unkD770;
    float unkEC00;
    u8 padEC04[0xA0];
    UnkECA4 *unkECA4;
} State5E50;

typedef struct {
    u8 pad0[0x14];
    Obj5E50 *unk14;
} Task5E50;

extern u8 D_01B0DEB0[];
extern State5E50 *D_01B0DF78;
extern u8 D_01B17DF0[];
extern u8 D_01C03DD0[];

extern void func_00110540(void *, s32, float);
extern float func_002B3DB0(float);
extern void *func_01B06880(void);
extern void func_01B069A8(void *);
extern void func_01B069F0(void);
extern void func_01B06FA8(void *, void *, s32);
extern s32 func_01B073A8(s32);
extern float func_01B07A48(s32);
extern void func_01B07C40(void *);
extern void func_01B08958(s32, s32);
extern void func_01B09608(void *, s32, void *, s32);
extern void func_01B098A8(void *, s32, s32);
extern Task5E50 *func_01B09BB8(void (*)(void *));
extern void func_01B09C38(void *);
extern void func_01B09D80(void *);
extern void func_01B09F18(void *, void *, s32, s32, s32, void *, float);
extern void func_01B0A388(void *, void *);
extern void func_01B0ADC0(void *, void *, void *);
extern void func_01B0AEC8(void *, void *, void *);
extern float func_01B0AF68(void *, void *);

void func_01B05E50(Task5E50 *arg0) {
    Vec4 pos;
    Obj5E50 *obj;
    State5E50 *s;
    SubD770 *sub;
    Vec4 *p270;
    Vec4 *p260;
    float t;
    s32 i;

    obj = arg0->unk14;
    s = D_01B0DF78;
    sub = &s->unkD770;

    if (obj->unk510 > 0) {
        obj->unk510--;
    }

    p270 = &obj->unk270;
    p260 = &obj->unk260;
    t = (float)obj->unk510 / (float)obj->unk514;
    for (i = 0; i < 3; i++) {
        ((float *)&pos)[i] = ((float *)p270)[i] * (1.0f - t) + ((float *)p260)[i] * t;
    }
    pos.w = 1.0f;

    func_01B06FA8(&obj->unk280, &pos, 0x80);
    MMI_COPY_LQ_A3(&obj->unk0.unkD0, &pos);
    MMI_COPY_SQ_A3(&obj->unk0.unkD0);

    if (obj->unk510 <= 0) {
        Work5E50 *w;
        s32 type;
        if (obj->unk518 == 0) {
            type = 0x19;
            for (i = 0; i < s->unkECA4->unk4; i++) {
                func_01B08958(func_01B073A8(s->unkECA4->unk8[i]), 0);
            }
            func_01B098A8(D_01B17DF0, 1, 2);
            func_01B09608(D_01C03DD0, 0x12, p270, 0x100);
        } else {
            type = 4;
        }

        w = &obj->unk130;
        func_01B09F18(D_01B0DEB0, w, type, 0, 0, 0, 0.4f);
        MMI_COPY_LQ_A3(&obj->unk130.unkD0, p270);
        __asm__ volatile("sq $7, 0($20)" : : : "memory");
        w->unkC0.y = s->unkEC00;
        w->unkD0.y -= 0.5f;
        func_01B0A388(D_01B0DEB0, obj);
        {
            register s32 n __asm__("$3") = sub->unk1484 + 1;
            sub->unk1484 = n;
        }
        func_01B09C38(arg0);
    }
}

void func_01B060C0(void) {
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    Vec4 v3;
    State5E50 *s;
    SubD770 *sub;
    void *p2730;
    Obj5E50 *obj;
    Task5E50 *task;
    s32 i;

    s = D_01B0DF78;
    sub = &s->unkD770;
    p2730 = s->unk2730;
    func_01B069A8(&v0);
    v2.x = 0.0f;
    v2.y = s->unkEC00;
    v2.z = 0.0f;
    v2.w = 0.0f;
    v3.w = 1.0f;
    func_01B07C40(&v1);
    v1.y = func_01B07A48(0);

    obj = sub->objs;
    for (i = 0; i < 3; i++, obj++) {

        MMI_COPY_LQ_A3(&obj->unk260, &v0);
        MMI_COPY_SQ_A3(&obj->unk260);
        MMI_COPY_LQ_A3(&obj->unk270, &v1);
        MMI_COPY_SQ_A3(&obj->unk270);

        switch (i) {
        case 0:
            v3.x = 0.0f;
            v3.y = -25.0f;
            v3.z = 0.0f;
            break;
        case 1:
            v3.x = 40.0f;
            v3.y = 0.0f;
            v3.z = func_002B3DB0(15.0f);
            break;
        case 2:
            v3.x = -40.0f;
            v3.y = 0.0f;
            v3.z = func_002B3DB0(15.0f);
            break;
        }

        func_01B0AEC8(&v2, &obj->unk270, &v3);
        func_01B0ADC0(&obj->unk280, &obj->unk260, &obj->unk270);
        obj->unk510 = (s32)(func_01B0AF68(&obj->unk260, &obj->unk270) / 10.0f);
        if (obj->unk510 < 0) {
            obj->unk510 = 1;
        }
        if (i == 0) {
            obj->unk510 += 2;
        }
        obj->unk514 = obj->unk510;
        func_01B09F18(D_01B0DEB0, obj, 0x27, 0, 0, 0, 0.08f);
        {
            register Vec4 *c0 __asm__("$3") = &obj->unk0.unkC0;
            MMI_COPY_LQ_A3(c0, &obj->unk280);
            MMI_COPY_SQ_A3(c0);
        }
        obj->unk518 = i;
        task = func_01B09BB8((void (*)(void *))func_01B05E50);
        task->unk14 = obj;
        func_01B09D80(task);
    }

    sub->unk1484 = 0;
    sub->unk1480 = 3;
    func_01B0A388(D_01B0DEB0, p2730);
    func_01B069F0();
    func_00110540(func_01B06880(), 1, 0.0f);
}
