/* Shared 09427-cluster active slot setter/getter (68 B, 2 funcs). */

#include "common.h"

typedef struct {
    u8 pad00[0x140];
    int active;
    u8 pad144[0x0C];
} SlotObj;

extern int g_slot_cur;
extern SlotObj g_slots[];

int ovl_09427_4ec0(int idx)
{
    int prev = g_slot_cur;
    g_slot_cur = idx;
    ((SlotObj *)((u8 *)g_slots + prev * sizeof(SlotObj)))->active = 0;
    ((SlotObj *)((u8 *)g_slots + idx * sizeof(SlotObj)))->active = 1;
    return prev;
}

int ovl_09427_4ef8(void)
{
    return g_slot_cur;
}
