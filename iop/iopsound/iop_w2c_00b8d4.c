#include "iopsound.h"

typedef struct {
    u8 pad[16];
    u8 body[4];
} SebHdr;

typedef struct {
    s32 idx;
    s32 id;
    SebHdr *data;
    s32 size;
} SepSlot;

extern SepSlot *D_01938C;

extern s32 func_009834(void *);
extern void func_00B5EC(s32, s32);

s32 func_00B8D4(SepSlot *slot) {
    u8 *d = (u8 *)slot->data;
    s32 bank_id = d[17] + (d[18] << 8);
    SepSlot *p;
    u8 *pd;
    s32 ret;

    p = D_01938C;
    while (slot->size == 0 || p == slot || (pd = p->data->body, bank_id != pd[1] + (pd[2] << 8))) {
        p++;
        if (p >= D_01938C + 192) {
            break;
        }
    }

    ret = func_009834(slot->data);
    slot->id = -1;
    slot->size = 0;
    slot->data = NULL;
    if (p >= D_01938C + 192) {
        func_00B5EC(1, bank_id);
    }
    return ret;
}
