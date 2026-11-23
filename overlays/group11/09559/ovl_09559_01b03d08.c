/* Overlay 09559: rank 268 track curve evaluator (0x01B03D08..0x01B03E40). */
#include "common.h"

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Track {
    u8 pad0[0x20];
    Vec3 *unk20;
    void *unk24;
    float *unk28;
    float unk2C;
    float unk30;
    int unk34;
    int unk38;
    int unk3C;
} Track;

float func_01B01A98(float, float, float, float, float, float);
float func_01B01B00(float, float *, int, int);

void func_01B03D08(Track *a0, float *a1) {
    Vec3 *p = a0->unk20;
    if (--a0->unk34 != 0) {
        float *q;
        float t;
        a0->unk2C += a0->unk30;
        q = a0->unk28;
        t = func_01B01A98(q[0], q[1], q[2], q[3], q[4], a0->unk2C);
        if (t >= (float)a0->unk38) {
            t = (float)a0->unk38 - 1e-6;
        }
        a1[0] = func_01B01B00(t, &p->x, a0->unk38, 3);
        a1[1] = func_01B01B00(t, &p->y, a0->unk38, 3);
        a1[2] = func_01B01B00(t, &p->z, a0->unk38, 3);
    } else {
        a0->unk3C = 0;
        p += a0->unk38 - 1;
        a1[0] = p->x;
        a1[1] = p->y;
        a1[2] = p->z;
    }
}
