/* tu_286 0x266ee8-0x266f10: low; unk_266A48; split at 0x266ee8: flag split: func_00266EE8 does not build with the flags of func_00266EB8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

/* unlink p from the list headed by t */
void func_00266EE8(ObjTable *t, char *p)
{
    ListNode *n = (ListNode *)p;

    n->next->prev = n->prev;
    t->count--;
    n->prev->next = n->next;
}
