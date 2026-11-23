#include "common.h"

typedef struct {
    u8 pad0[0x80];
    u8 unk80[0x10];
    u8 unk90[0x10];
    u8 unkA0[0x10];
    u8 padB0[0x20];
    u8 unkD0[0x10];
} Unk3860Obj;

extern void func_001072F8(s32, s32, void *);
extern float func_00110AF0(s32);
extern void func_002DD998(void *, void *, float);
extern s32 func_01B06880(void);
extern void func_01B069A8(void *);

void func_01B03860(Unk3860Obj *obj) {
    s32 id = func_01B06880();
    float sc;

    func_001072F8(id, 0, obj->unk80);
    sc = 1000.0f / func_00110AF0(id);
    func_002DD998(obj->unk80, obj->unk80, sc);
    func_002DD998(obj->unk90, obj->unk90, sc);
    func_002DD998(obj->unkA0, obj->unkA0, sc);
    func_01B069A8(obj->unkD0);
}
