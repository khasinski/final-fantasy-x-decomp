#include "p9_overlay.h"

/* -O0 unit (s8 frame pointer). Family F13, the one TU rank 28 function without VU0 inline asm. */

typedef struct P9Mdl {
    u8 pad[0xA8];
    float alpha;    /* 0xA8 */
    u8 padAC[4];
    int flags;      /* 0xB0 */
} P9Mdl;

typedef struct P9MdlRef {
    P9Mdl *mdl;
    u8 pad[8];
    float alpha;    /* 0x0C */
} P9MdlRef;

void func_01B0EA18(P9MdlRef *ref);

void func_01B0EAF8(P9MdlRef *ref)
{
    func_01B0EA18(ref);
    ref->mdl->flags = ref->mdl->flags | 4;
    ref->mdl->alpha = ref->alpha;
}
