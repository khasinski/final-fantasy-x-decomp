/* tu_073 0x13ca30-0x13ca80: low; unk_13CA30 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

int func_0013CA30(Actor *s, int i) {
    return ((int *)((char *)s->blob + s->hdr->o20))[i];
}

int func_0013CA50(int id, int i) {
    return func_0013CA30(AtelGetBasicWork(id), i);
}
