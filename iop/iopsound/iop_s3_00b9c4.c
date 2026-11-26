#include "iopsound.h"

typedef struct {
    s32 idx;
    s32 id;
    void *data;
    s32 size;
} SepSlot;

extern SepSlot *D_01938C;

extern s32 func_0093C8(u32, s32, s32);

void func_00B9C4(void) {
    s32 i;
    SepSlot *p;

    func_0093C8((u32)D_01938C, 3088, 0);
    p = D_01938C;
    i = 0;
    do {
        p->idx = i;
        p->id = -1;
        p++;
        i++;
    } while (i < 192);
}
