/* tu_286 0x266eb8-0x266ee8: low; unk_266A48; split at 0x266eb8: flag split: func_00266EB8 needs -fno-schedule-insns -fno-schedule-insns2 (config/cflags.txt), the functions before it do not; split at 0x266ee8: flag split: func_00266EE8 does not build with the flags of func_00266EB8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

/* DEBT(ORDER): cache the count before link writes and increment it between them.
   This translation unit preserves that order with both instruction schedulers disabled. */
/* DEBT(CAST): the public entry uses untyped callback/argument words and a separate list-head view. */
void func_00266EB8(ObjTable *tbl, void *obj, void *cb, void *arg)
{
    ListNode *node = obj;
    ListNode *tail = tbl->next;
    int count = tbl->count;

    node->prev = (ListNode *)tbl;
    count++;
    tail->prev = node;
    tbl->count = count;
    node->callback = (ListCallback)cb;
    node->u.b = (int)arg;
    node->next = tail;
    tbl->next = node;
}
