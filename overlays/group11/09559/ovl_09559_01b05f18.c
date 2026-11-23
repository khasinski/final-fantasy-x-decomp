/* Overlay 09559: rank 39 pool80 animation & physics callbacks (0x01B05F18..0x01B06034). */
#include "common.h"

typedef struct AnimHdr {
    u8 pad0[6];
    s16 frames;
} AnimHdr;

typedef struct Pool80 {
    float pos[4];
    float vel[3];
    float acc[3];
    AnimHdr *active;
    int flag2C;
    void *cb;
    float scale;
    float scaleVel;
    float scaleAcc;
    s16 unk40;
    s16 pad42;
    u32 color;
    s16 unk48;
    s16 unk4A;
    u8 pad4C[4];
} Pool80;

void func_01B05F18(Pool80 *p, s16 *a1) {
    p->unk48 += 0x200;
    if (p->unk48 >= a1[1]) {
        p->unk48 -= a1[1];
        p->unk4A++;
        if (p->unk4A >= p->active->frames) {
            p->active = 0;
        }
    }
}

void func_01B05F78(Pool80 *p) {
    p->scale += p->scaleVel;
    if (p->scale < 0.002) {
        p->active = 0;
    } else {
        p->scaleVel += p->scaleAcc;
        p->pos[0] += p->vel[0];
        p->pos[1] += p->vel[1];
        p->pos[2] += p->vel[2];
        p->vel[0] += p->acc[0];
        p->vel[1] += p->acc[1];
        p->vel[2] += p->acc[2];
    }
}
