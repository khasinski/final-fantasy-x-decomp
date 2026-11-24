#include "common.h"

typedef struct {
    s32 w00;
    s32 count;
} Hdr628;

typedef struct {
    s32 w00;
    s32 w04;
    s32 w08;
} Item81F0;

typedef struct {
    float x, y, z, w;
} Vec4;

extern Hdr628 D_01B00628;
extern Item81F0 D_01B081F0[];

extern s32 func_01B01578(s32);
extern void func_01B02B28(s32, s32);
extern void func_01B01398(void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_01B01350(void *);
extern void func_01B04E18(void *, void *, void *);
extern void func_01B017C8(s32, void *, s32);

s32 ovl_09424_11a0(s32 a0);

void ovl_09424_10d0(void)
{
    Item81F0 *s1 = D_01B081F0;
    s32 i;

    for (i = 0; i < D_01B00628.count; i++, s1++) {
        if (s1->w00 > 0) {
            s1->w00--;
        } else if (s1->w08 == 0) {
            if (ovl_09424_11a0(i) == 1) {
                s1->w08 = 1;
            }
        } else if (s1->w04 > 0) {
            s1->w04--;
            if (s1->w04 == 0) {
                func_01B02B28(func_01B01578(i), 0);
            }
        }
    }
}

s32 ovl_09424_11a0(s32 a0)
{
    float m00[16];
    Vec4 v40;
    Vec4 v50;
    Vec4 v60;
    Vec4 v70;
    double d;

    func_01B01398(m00);
    v50.x = 0.0f;
    v50.y = 0.0f;
    v50.z = -1000.0f;
    v50.w = 1.0f;
    func_002DCE08(&v50, m00, &v50);
    func_01B01350(&v40);
    func_01B04E18(&v60, &v40, &v50);
    func_01B017C8(a0, &v50, 0);
    func_01B04E18(&v70, &v40, &v50);
    d = (double)(v60.y - v70.y);
    if (d < 0.0) {
        d = 0.0 - d;
    }
    return d < 0.6283185482025146;
}
