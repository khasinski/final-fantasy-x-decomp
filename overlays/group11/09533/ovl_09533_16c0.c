#include "common.h"

typedef struct {
    int active;
    u8 pad04[0x30];
    int w34;
    u8 pad38[0x4C];
    float f84;
    u8 pad88[0x38];
} PtObj;

typedef struct {
    int count;
    PtObj *objs;
} PtPool;

extern float D_01B00660[];
extern int D_01B006B8;
extern u8 D_01B00C80;
extern void *D_01B00CB0;
extern int D_01B00DA4;
extern float D_01B00DC0[2][4];

extern void func_01B013C8(void *, void *, float *, float *);
extern int func_01B02B00(float *);
extern void func_01B031C8(void *);
extern int func_01B03360(void *, void *, int, float);
extern void func_00107428(int, int, int, float *);
extern void func_002DD998(float *, float *, float);

int func_01B016C0(PtPool *pool)
{
    float pos[4];
    float dir[4];
    int i;
    PtObj *obj;

    func_00107428(D_01B00DA4, 0, 0, pos);
    dir[0] = D_01B00DC0[0][0] - D_01B00DC0[1][0];
    dir[1] = D_01B00DC0[0][1] - D_01B00DC0[1][1];
    dir[2] = D_01B00DC0[0][2] - D_01B00DC0[1][2];
    func_01B02B00(dir);
    func_002DD998(dir, dir, -1.0f);
    func_01B013C8(pool, D_01B00CB0, pos, dir);
    func_01B013C8(pool, D_01B00CB0, pos, dir);
    func_01B013C8(pool, D_01B00CB0, pos, dir);
    func_01B013C8(pool, D_01B00CB0, pos, dir);
    func_01B013C8(pool, D_01B00CB0, pos, dir);
    obj = pool->objs;
    for (i = 0; i < pool->count; i++, obj++) {
        if (obj->active != 0) {
            obj->f84 = D_01B00660[16 - obj->w34];
        }
    }
    func_01B031C8(pool);
    {
        int prev = D_01B006B8;
        D_01B006B8 = func_01B03360(pool, &D_01B00C80, prev, 0.0f);
    }
    return 1;
}
