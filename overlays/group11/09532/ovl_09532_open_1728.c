#include "common.h"

typedef struct {
    u8 pad00[0x10];
    float pos[4];
    float vel[4];
    int max_life;
    int life;
    int flags;
    u8 pad3c[0x34];
    float scale;
    u8 pad74[4];
    int cur_rgb[3];
    float alpha;
    u8 pad88[8];
    int c0[4];
    int c1[4];
    float s0;
    float s1;
} PartObj;

extern void func_002DD020(void *, void *, void *);

int func_01B01728(PartObj *p)
{
    if (!(p->flags & 1)) {
        if (--p->life <= 0) {
            return 0;
        }
    }
    if (p->flags & 2) {
        p->alpha = (float)p->life / (float)p->max_life;
    }
    if (p->flags & 4) {
        float t = 1.0f - (float)p->life / (float)p->max_life;
        p->alpha = ((float)p->c0[3] + (float)(p->c1[3] - p->c0[3]) * t) / 127.0f;
        p->cur_rgb[0] = (int)((float)p->c0[0] + (float)(p->c1[0] - p->c0[0]) * t);
        p->cur_rgb[1] = (int)((float)p->c0[1] + (float)(p->c1[1] - p->c0[1]) * t);
        p->cur_rgb[2] = (int)((float)p->c0[2] + (float)(p->c1[2] - p->c0[2]) * t);
        if (p->alpha < 0.0f) {
            p->alpha = 0.0f;
        }
        if (p->alpha > 1.0f) {
            p->alpha = 1.0f;
        }
    }
    if (p->flags & 8) {
        p->scale = p->s0 + (p->s1 - p->s0) * (1.0f - (float)p->life / (float)p->max_life);
    }
    func_002DD020(p->pos, p->pos, p->vel);
    return 1;
}
