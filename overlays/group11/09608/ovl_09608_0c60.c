#include "common.h"

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    u8 pad18[0x08];
} Obj4568;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
} OvlTask;

extern s32 D_01B00040[];
extern u8 D_01B008B8[];
extern Obj4568 D_01B04568[];
extern s32 D_01B045C8[];
extern OvlMgr D_01B045D8;
extern u8 *D_01B04AE4;

extern void func_01B01E18(int, int);
extern int func_01B02BF0(void *);
extern int func_01B03B50(void *, void *);

void ovl_09608_0c60(OvlTask *a0)
{
    int i;
    int r0, r1, r2;

    for (i = 0; i < 3; i++) {
        if (D_01B045C8[i] > 0) {
            if (--D_01B045C8[i] <= 0) {
                func_01B01E18(D_01B00040[i], 0);
            }
        }
    }
    r0 = func_01B02BF0(&D_01B04568[0]);
    r1 = func_01B02BF0(&D_01B04568[1]);
    r2 = func_01B02BF0(&D_01B04568[2]);
    if (func_01B03B50(&D_01B045D8, D_01B04AE4) == 1 && r0 == 1 && r1 == 1 && r2 == 1 &&
        D_01B045C8[0] <= 0 && D_01B045C8[1] <= 0 && D_01B045C8[2] <= 0) {
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B008B8;
    }
}
