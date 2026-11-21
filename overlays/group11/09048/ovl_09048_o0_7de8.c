/* Shared P6 -O0 helper: position node update (hash 05c5b2, 492B). */
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

extern void func_01B081E0(void *);
extern void func_01B08220(void *, void *);
extern void func_01B08278(void *, void *);
extern void func_01B082D0(void *, int, void *);
extern void func_01B08338(void *, void *);
extern void func_01B08390(void *, void *);
extern void func_01B083E8(void *, void *);
extern void func_01B08440(void *, void *);

void func_01B07DE8(register P6Iter *it)
{
    P6PosNode *obj;
    int zero;

    func_01B081E0(it);
    if ((it->done & 1) == 0) {
        return;
    }
    obj = (P6PosNode *)it->cur;
    switch (obj->mode) {
    case 0:
        func_01B08220(obj->chr, &obj->v);
        break;
    case 1:
        func_01B08278(obj->chr, &obj->v);
        break;
    case 2:
        func_01B082D0(obj->chr, obj->bone, &obj->v);
        break;
    case 3:
        func_01B08338(obj->chr, &obj->v);
        break;
    case 4:
        func_01B08390(obj->chr, &obj->v);
        break;
    case 5:
        func_01B083E8(obj->chr, &obj->v);
        break;
    case 6:
        func_01B08440(obj->chr, &obj->v);
        break;
    }
    obj->v.x += obj->off_x;
    obj->v.y += obj->off_y;
    obj->v.z += obj->off_z;
    zero = 0;
}
