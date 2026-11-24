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

extern float D_01B00738[];
extern int D_01B007D0;
extern u8 D_01B00FA0;
extern void *D_01B00FD0;
extern int D_01B01054;
extern int D_01B01060;
extern int D_01B01170;
extern char D_01B04078[];

extern void func_01B01658(void *, void *, float *);
extern void func_01B018D0(void *, void *, float *);
extern void func_01B03438(char *);
extern void func_01B03A10(void *);
extern int func_01B03BA8(void *, void *, int, float);
extern void func_00107428(int, int, int, float *);
extern int func_0014AA50(int);

int func_01B01C68(PtPool *pool)
{
    float pos[4];
    int i;
    PtObj *obj;

    func_00107428(D_01B01054, 1, 0, pos);
    if (D_01B01060 < 0x50) {
        for (i = 0; i < 12; i++) {
            func_01B01658(pool, D_01B00FD0, pos);
        }
    }
    if (func_0014AA50(1) != 0 && D_01B01170 < 0x19) {
        for (i = 0; i < 15; i++) {
            func_01B018D0(pool, D_01B00FD0, pos);
        }
    }
    obj = pool->objs;
    for (i = 0; i < pool->count; i++, obj++) {
        if (obj->active != 0) {
            int idx = 32 - obj->w34;
            obj->f84 = D_01B00738[idx];
            if (idx >= 32) {
                func_01B03438(D_01B04078);
            } else if (idx < 0) {
                func_01B03438(D_01B04078);
            }
        }
    }
    func_01B03A10(pool);
    {
        int prev = D_01B007D0;
        D_01B007D0 = func_01B03BA8(pool, &D_01B00FA0, prev, 50.0f);
    }
    return func_0014AA50(2) == 0;
}
