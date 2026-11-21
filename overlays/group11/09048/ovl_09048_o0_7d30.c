/* Shared P6 -O0 helper: position node init (hash 6c451b, 140B). */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x20];
    struct { float x, y, z, w; } v; /* 0x20 */
    float off_x;            /* 0x30 */
    float off_y;            /* 0x34 */
    float off_z;            /* 0x38 */
    void *chr;              /* 0x3C */
    int bone;               /* 0x40 */
    u8 mode;                /* 0x44 */
} P6PosNode;

typedef struct {
    P6PosNode *obj;         /* 0x00 */
    void *parent;           /* 0x04 */
    void *chr;              /* 0x08 */
} P6PosInitArg;

extern void func_01B080A8(void *);

void func_01B07D30(register P6PosInitArg *arg)
{
    func_01B080A8(arg);
    arg->obj->v.w = 1.0f;
    arg->obj->chr = arg->chr;
    arg->obj->mode = 1;
    arg->obj->bone = 6;
    arg->obj->off_x = 0.0f;
    arg->obj->off_y = 0.0f;
    arg->obj->off_z = 0.0f;
}
