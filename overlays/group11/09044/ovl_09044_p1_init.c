#include "p1_overlay.h"

typedef struct P1Slot {
    s16 active;
    u8 pad2[0x2E];
} P1Slot;

typedef struct P1SlotList {
    u32 count;
    u32 head;
    u8 pad8[8];
    P1Slot slot[1];
} P1SlotList;

void func_01B09498(P1SlotList *list, u32 n)
{
    P1Slot *s;
    u32 i;

    list->count = n;
    list->head = 0;
    s = list->slot;
    for (i = 0; i < n; i++) {
        s->active = 0;
        s++;
    }
}
