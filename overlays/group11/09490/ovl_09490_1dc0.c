#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0xC0];
    float unkC0;
    float unkC4;
    u8 padC8[0x8];
    float unkD0[4];
    u8 padE0[0x4];
    float unkE4;
    float unkE8;
    u8 padEC[0x34];
    s32 unk120;
    u8 pad124[0xC];
} Elem1DC0;

typedef struct {
    u8 pad0[0x130];
    Elem1DC0 unk130;
    u8 pad260[0x10];
    float unk270[4];
    u8 pad280[0x298];
    s32 unk518;
} Obj1DC0;

typedef struct {
    u8 pad0[0x2B60];
    void *unk2B60;
    u8 pad2B64[0x4];
    s32 unk2B68;
} Sub30B0;

typedef struct {
    Elem1DC0 elems[1];
    u8 pad130[0x30B0 - 0x130];
    Sub30B0 unk30B0;
    u8 pad5C1C[0xEC00 - 0x5C1C];
    float unkEC00;
} Work1DC0;

extern Work1DC0 *D_01B0B398;
extern u8 D_01B0B2D0[];
extern s32 D_01B00938[];
extern s32 D_01B00948[];

extern void func_01B03E00(float *);
extern s32 func_01B04838(s32);
extern void func_01B07360(void *, void *, s32, s32, s32, void *, float);
extern void func_01B07828(void *, void *);
extern void func_01B07978(void);

void func_01B01DC0(void) {
    Work1DC0 *work = D_01B0B398;
    Sub30B0 *sub = &work->unk30B0;
    Elem1DC0 *elem;
    s32 idx;

    if (sub->unk2B68 != 0) {
        func_01B07828(D_01B0B2D0, sub->unk2B60);
    }
    idx = D_01B00938[sub->unk2B68];
    elem = &work->elems[idx];
    func_01B07360(D_01B0B2D0, elem, idx, 0, 0, 0, 0.2f);
    func_01B03E00(elem->unkD0);
    elem->unkC4 = work->unkEC00;
    elem->unkE4 = 3.0f;
    elem->unkE8 = -3.0f;
}

void func_01B01E90(Obj1DC0 *obj, float *vec, s32 idx) {
    Elem1DC0 *elem = &obj->unk130;

    func_01B07360(D_01B0B2D0, elem, D_01B00948[idx], 0, 0, (void *)func_01B07978, 0.2f);
    MMI_COPY_LQ_A3(elem->unkD0, obj->unk270);
    MMI_COPY_SQ_A3(elem->unkD0);
    elem->unkC0 = vec[0];
    elem->unkC4 = vec[1];
    elem->unk120 = func_01B04838(obj->unk518);
}
