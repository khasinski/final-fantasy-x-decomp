#include "common.h"

typedef struct Node8660 Node8660;
struct Node8660 {
    u8 pad00[0x14];
    Node8660 *parent; /* 0x14 */
    u8 pad18[0x08];   /* 0x18 */
    float vx;         /* 0x20 */
    float vy;         /* 0x24 */
    float vz;         /* 0x28 */
    float vw;         /* 0x2C */
    float f30;        /* 0x30 */
    float f34;        /* 0x34 */
    float f38;        /* 0x38 */
    float f3C;        /* 0x3C */
    float f40;        /* 0x40 */
    u16 h44;          /* 0x44 */
    u16 h46;          /* 0x46 */
    u16 h48;          /* 0x48 */
};

typedef struct {
    Node8660 *node;
    u8 flags;
} Msg8660;

extern void func_01B08BD8(Msg8660 *);
extern void func_002DD020(void *, void *, void *);
extern void func_01B089B8(void *, void *, float);
extern void func_01B08A60(void *, void *, void *);
extern void func_002DD0B0(void *, void *);

void func_01B08660(register Msg8660 *s0)
{
    func_01B08BD8(s0);
    if (!(s0->flags & 1)) {
        return;
    }
    {
        Node8660 *n = s0->node;
        Node8660 *p = n->parent;
        float v10[4];
        float v20[4];
        float t30;
        float f34;
        float f38;
        float f3C;

        func_002DD020(v10, &p->vx, &n->vx);
        f38 = v10[1] - n->f3C;
        if (0.0f < f38) {
            f34 = n->f30;
            f3C = f38 * -f34;
            t30 = f38 / n->vy;
            n->vy = n->vy * -f34;
            func_01B089B8(v20, &n->vx, t30);
            func_01B08A60(v10, &n->vx, v20);
            f34 = n->f34;
            v10[0] = v10[0] + (p->vx + v20[0] * f34);
            v10[1] = v10[1] + n->f3C;
            v10[2] = v10[2] + (p->vz + v20[2] * f34);
            n->vx = n->vx * f34;
            n->vz = n->vz * f34;
            n->h44++;
        }
        func_002DD0B0(&p->vx, v10);
        n->vy = n->vy + n->f38;
        n->h46++;
        if ((float)(n->h46 + 1) >= n->f40) {
            n->h48 = 1;
        }
    }
}
