#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    s32 unk0;
    s32 count;
} Cnt2258;

extern u8 *D_01B09358;
extern Cnt2258 D_01B008F8;

extern void func_002DD128(float *);
extern void func_002DD1C8(float *, float *, float);
extern void func_002DD270(float *, float *, float);
extern void func_002DD318(float *, float *, float);
extern void func_002DCE38(void *, void *, float *);
extern void func_01B03E98(s32, s32);
extern s32 func_01B029D8(s32);
extern void func_01B03F88(s32, s32);

typedef struct {
    float mat00[12];
    float vec30[4];
    float mat40[12];
    float vec70[4];
    float unk80;
    float unk84;
    float unk88;
    float unk8C;
    float unk90;
    float unk94;
    float unk98;
    float unk9C;
    float unkA0;
    float unkA4;
    float unkA8;
    float unkAC;
    float unkB0;
    float unkB4;
    float unkB8;
    float unkBC;
    float unkC0;
    float unkC4;
    float unkC8;
    float unkCC;
    s32 unkD0;
    s32 unkD4;
    s32 unkD8;
    s32 unkDC;
} Item2258;

static inline float lerp_ang(float a, float b, float t) {
    float r = a * (1.0f - t) + b * t;
    if (r > 3.1415927f) {
        r -= 6.2831855f;
    } else if (r < -3.1415927f) {
        r += 6.2831855f;
    }
    return r;
}

void func_01B02258(void) {
    float mat[16];
    Item2258 *it = (Item2258 *)(D_01B09358 + 0x4D20);
    s32 i;

    for (i = 0; i < D_01B008F8.count; i++, it++) {
        if (it->unkD0 > 0) {
            it->unkD0--;
            if (it->unkDC == 1) {
                float t;

                it->unkB4 += it->unkC4;
                it->vec30[1] += it->unkB4;
                if (it->vec30[1] > it->unkA4) {
                    it->vec30[1] = it->unkA4;
                }

                t = (float)it->unkD0 / (float)it->unkD4;
                it->unk80 = lerp_ang(it->unk90, 0.0f, t);
                it->unk84 = lerp_ang(it->unk94, 0.0f, t);
                it->unk88 = lerp_ang(it->unk98, 0.0f, t);

                if (it->unkD8 == 1) {
                    func_002DD128(mat);
                    func_002DD1C8(mat, mat, it->unk88);
                    func_002DD270(mat, mat, it->unk80);
                    func_002DD318(mat, mat, it->unk84);
                    func_002DCE38(it->mat40, it->mat00, mat);
                }
                copy_vec(it->vec70, it->vec30);
            }
            if (it->unkD0 == 0) {
                func_01B03E98(i, 0);
                func_01B03F88(func_01B029D8(i), 0);
            }
        }
    }
}
