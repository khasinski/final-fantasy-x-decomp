#include "common.h"

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

extern float D_01B00954;
extern u8 D_01B009D8;
extern PppObj D_01B00B10[];
extern s32 D_01B00F58;
extern s32 D_01B00F60[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern void func_002675B0(void *);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

int func_01B025A8(PppObj *p)
{
    int idx = p - D_01B00B10;
    float s;

    if (D_01B00F58 - 1 < idx) {
        return 0;
    }
    if (D_01B00F60[idx] == 0) {
        return 0;
    }
    s = D_01B00954;
    p->scale[3] = 1.0f;
    p->scale[2] = p->scale[1] = p->scale[0] = s;
    func_002675B0(p);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    {
        void *h = &D_01B009D8;
        *(volatile void **)&D_006A3924 = h;
    }
    return func_00267FA0(p, 0x30) == 0;
}
