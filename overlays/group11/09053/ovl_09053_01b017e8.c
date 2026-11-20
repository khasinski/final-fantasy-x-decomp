/* Shared 09053-family helper (TU rank 25, 224 containers): resolve actor bone/anchor position. */
#include "p8_overlay.h"

extern void *func_01B01630(int);
extern float func_01B01B10(int);
extern void func_00110220(void *, float *, float *, float *);
extern void func_00108910(void *, int, float *);
extern float func_00110180(void *);

void func_01B017E8(int actor_idx, float *pos, int mode)
{
    void *obj;
    float tmp[4];

    obj = func_01B01630(actor_idx);
    func_00110220(obj, &pos[0], &pos[1], &pos[2]);
    switch (mode) {
    case 0:
        break;
    case 1:
        func_00108910(obj, 6, tmp);
        pos[1] = tmp[1];
        break;
    case 2:
    {
        float h = func_01B01B10(actor_idx);
        func_00108910(obj, 6, tmp);
        pos[1] = tmp[1] - h * 0.5f;
        break;
    }
    case 4:
        func_00108910(obj, 0x10, pos);
        break;
    case 5:
        func_00108910(obj, 0x11, pos);
        break;
    case 6:
        func_00108910(obj, 0x10, pos);
        pos[1] = func_00110180(obj);
        break;
    case 7:
        func_00108910(obj, 0x11, pos);
        pos[1] = func_00110180(obj);
        break;
    case 3:
        pos[1] = func_00110180(obj);
        break;
    }
    pos[3] = 1.0f;
}
