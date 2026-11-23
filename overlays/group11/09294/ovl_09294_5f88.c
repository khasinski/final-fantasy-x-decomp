#include "common.h"

typedef struct Unk5F88Item Unk5F88Item;
struct Unk5F88Item {
    u8 pad0[0x3C];
    float unk3C;
    u8 pad40[0x18];
    s32 unk58;
    u32 unk5C;
    u32 unk60;
    s32 unk64;
    u16 unk68;
    u8 pad6A[6];
};

extern Unk5F88Item *D_01B0CC60;
extern s32 D_01B0CC64;
extern s32 D_01B0CC68;

extern void *func_01B03D98(void (*)(void));
extern void func_01B03F60(void *);
extern void func_01B060A0(void);

void *func_01B05F88(Unk5F88Item *buf, s32 count) {
    s32 i;
    void *task;

    D_01B0CC60 = buf;
    for (i = 0; i < count; i++, buf++) {
        buf->unk64 = 0;
    }
    D_01B0CC64 = 0;
    D_01B0CC68 = count;
    task = func_01B03D98(func_01B060A0);
    func_01B03F60(task);
    return task;
}

Unk5F88Item *func_01B06010(void) {
    s32 i;
    s32 idx;

    idx = D_01B0CC64;
    for (i = 0; i < D_01B0CC68; i++) {
        Unk5F88Item *p = &D_01B0CC60[idx];

        idx++;
        if (idx >= D_01B0CC68) {
            idx = 0;
        }
        if (p->unk64 == 0) {
            p->unk5C = 0x80808080;
            p->unk60 = 0x80808080;
            p->unk58 = 0;
            p->unk3C = 1.0f;
            p->unk64 = 1;
            D_01B0CC64 = idx;
            return p;
        }
    }
    return 0;
}
