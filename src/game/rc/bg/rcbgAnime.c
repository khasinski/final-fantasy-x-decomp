/* tu_147 0x190e38-0x190f20: medium; rcbgAnime (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

void func_00190E38(R2Anim *a) {
    func_002EF0D0(a, 0, sizeof(R2Anim));
    a->speed = 0x100;
}

void func_00190E70(R2Anim *a) {
    if (a->frames != 0) {
        func_0018FC10(a->frames);
        a->frames = 0;
    }
}

void rcbgAnimeSetDataCnt(R2Anim *a, int n) {
    a->frames = _rcRealloc(a->frames, n * 4, D_0056D630, 0x2B);
    if (a->n < n) {
        int size = (n - a->n) * 4;

        func_002EF0D0(a->frames + a->n, 0, size);
    }
    a->n = n;
}
