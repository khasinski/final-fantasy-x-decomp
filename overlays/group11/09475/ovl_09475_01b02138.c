#include "common.h"

extern void *D_01B0A070;

extern void *func_001038F8(void);
extern void func_01B018B8(void);
extern s32 func_01B01A10(void *, void *, void *, float *, float *);
extern s32 func_01B01D80(void *, void *, float *, float *, void *, float, s32, s32, s32);

s32 func_01B02138(void *a0, void *a1, void *a2) {
    float v0[4];
    float v1[4];
    void *p;
    void *buf;
    s32 ret;

    func_01B018B8();
    p = D_01B0A070;
    buf = func_001038F8();
    ret = func_01B01A10(p, a1, buf, v0, v1);
    if (ret < 3) {
        return ret;
    }
    ret = func_01B01D80(a0, a2, v0, v1, buf, 10.0f, 1, 1, 1);
    if (ret >= 3) {
        return ret;
    }
    ret = func_01B01D80(a0, a2, v0, v1, buf, 10.0f, 0, 1, 1);
    if (ret >= 3) {
        return ret;
    }
    ret = func_01B01D80(a0, a2, v0, v1, buf, 10.0f, 0, 0, 1);
    if (ret >= 3) {
        return ret;
    }
    ret = func_01B01D80(a0, a2, v0, v1, buf, 1000.0f, 0, 0, 1);
    if (ret >= 3) {
        return ret;
    }
    return func_01B01D80(a0, a2, v0, v1, buf, 1000.0f, 0, 0, 0);
}
