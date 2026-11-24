#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

extern s32 D_01B008D4;
extern u8 D_01B006A8[];
extern u8 D_01B006D8[];
extern u8 D_01B00758[];
extern u8 D_01B007D8[];
extern u8 D_01B08408[];

extern void func_01B01BD8(s32, void *, s32);
extern void func_01B05228(void *, void *, void *);
extern void func_01B07A88(void *, void *);

void ovl_09314_1140(void)
{
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;
    void *arg;
    s32 ang;

    func_01B01BD8(-1, &v00, 3);
    switch (D_01B008D4) {
    case 1:
        arg = D_01B006A8;
        break;
    case 2:
        func_01B01BD8(0, &v10, 3);
        func_01B05228(&v20, &v00, &v10);
        func_01B01BD8(1, &v10, 3);
        func_01B05228(&v30, &v00, &v10);
        ang = (s32)((v30.y * 180.0f) / 3.1415927f - (v20.y * 180.0f) / 3.1415927f);
        ang = (ang >= 0) ? ang : -ang;
        if (ang > 180) {
            ang = 360 - ang;
        }
        if (ang > 25) {
            arg = D_01B006D8;
        } else {
            arg = D_01B00758;
        }
        break;
    case 3:
        arg = D_01B007D8;
        break;
    default:
        return;
    }
    func_01B07A88(D_01B08408, arg);
}
