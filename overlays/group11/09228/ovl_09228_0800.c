#include "common.h"

extern void *D_01B01944;
extern void *D_01B01948;
extern void *D_01B0194C;
extern void *D_01B01950;

extern void op_oef2_set2(void *);
extern void func_002D02E8(void *, int, int, int);
extern void op_oef2_sound_cue_multi(void *, int, int, int);
extern void *op_oef2_a_get(void *, int, int);

void func_01B00800(void *a0) {
    void **p0 = &D_01B01944;
    void **p1 = &D_01B01948;
    void **p2 = &D_01B0194C;
    void **p3 = &D_01B01950;

    op_oef2_set2(a0);
    func_002D02E8(a0, 0, 1000, 256);
    op_oef2_sound_cue_multi(a0, 0, 1000, 256);
    *p0 = op_oef2_a_get(a0, 6, 0);
    *p1 = op_oef2_a_get(a0, 6, 1);
    *p2 = op_oef2_a_get(a0, 6, 2);
    *p3 = op_oef2_a_get(a0, 6, 3);
}
