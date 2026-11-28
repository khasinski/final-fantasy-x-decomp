#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    s32 unk0;
    s32 count;
} Cnt24C8;

extern u8 *D_01B09358;
extern u8 D_01B09290[];
extern u8 D_01B10360[];
extern u8 D_01B00770[];
extern u8 D_01B00788[];
extern Cnt24C8 D_01B008F8;

extern void func_01B05548(void *, void *, s32, s32, s32, s32, float);
extern void func_01B04CD0(void *, void *, void *);
extern void func_01B08BF8(void *, s32);
extern void func_01B08D68(void *, s32);
extern void func_01B03178(s32, void *);
extern void func_01B03E98(s32, void *);
extern s32 func_002EFD78(void);
extern s32 func_01B03600(s32);
extern void func_002DD0C0(void *, void *);
extern float func_002B3DB0(float);
extern float func_01B02F98(s32);
extern float func_01B02F50(s32);
extern u8 *func_01B051E8(void *);
extern void func_01B053B0(void *);
extern void func_01B02258(void);
extern void func_01B09048(void *, s32, s32, float, float);
extern void func_00297CE8(s32);

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
    float unkA0[4];
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
} Item24C8;

void func_01B024C8(void) {
    u8 *s = D_01B09358;
    s32 idx;
    void *tbl;
    u8 *obj;
    u8 *p;
    u8 *s1;
    Item24C8 *it;
    s32 i;
    u8 *task;

    if (*(s32 *)(s + 0x54C0) != 0) {
        idx = 3;
        tbl = D_01B00770;
    } else {
        idx = 10;
        tbl = D_01B00788;
    }

    obj = s + idx * 0x130;
    func_01B05548(D_01B09290, obj, idx, 0, 0, 0, 0.3f);
    *(float *)(obj + 0xC4) = *(float *)(s + 0xFB4);
    copy_vec(obj + 0xD0, s + 0xFC0);
    *(float *)(obj + 0xD4) -= 0.5f;
    func_01B04CD0(s + 0x5460, D_01B10360, tbl);
    *(void **)(obj + 0x110) = s + 0x5460;

    p = s + 0x1090;
    p[0x83] = 0x80;
    p[0x82] = 0x80;
    p[0x81] = 0x80;
    p[0x80] = 0x80;
    p[0x84] = 0x80;
    p[0x85] = 0x80;
    p[0x86] = 0x80;
    p[0x87] = 0;
    *(s32 *)(p + 0x88) = 0;
    p[0x98] = 0x48;
    p[0x99] = 0;
    func_01B08BF8(p, 0x14);

    s1 = s + 0x1130;
    func_01B08D68(s1, 50);
    *(u16 *)(s1 + 0x2C) |= 3;
    *(float *)(s1 + 0x08) = 0.2f;
    *(float *)(s1 + 0x10) = 3.0f;
    *(float *)(s1 + 0x14) = 1.5f;
    *(float *)(s1 + 0x0C) = 0.0f;
    *(float *)(s1 + 0x18) = 0.0f;
    *(float *)(s1 + 0x04) = 0.0f;

    it = (Item24C8 *)(s + 0x4D20);
    for (i = 0; i < D_01B008F8.count; i++, it++) {
        s32 dur;
        float half_neg;
        s32 st;

        func_01B03178(i, it->mat40);
        copy_vec(it->unkA0, it->vec70);
        func_01B03E98(i, it->mat40);

        dur = func_002EFD78() % 6 + 45;
        it->unkD4 = dur;
        it->unkD0 = dur;
        half_neg = (float)dur * -0.5f;
        st = func_01B03600(i);
        it->unkDC = st;
        if (st == 1) {
            float r1;
            float r2;

            it->unkB4 = -4.0f;
            it->unkC4 = -4.0f / half_neg;
            func_002DD0C0(it->mat00, it->mat40);
            it->unk80 = 0.0f;
            it->unk84 = 0.0f;
            it->unk88 = 0.0f;
            if ((func_002EFD78() & 1) == 0) {
                it->unk90 = 6.2831855f;
            } else {
                it->unk90 = -6.2831855f;
            }
            it->unk94 = func_002B3DB0(0.31415927f);
            it->unk98 = func_002B3DB0(1.5707964f);
            r1 = func_01B02F98(i);
            r2 = func_01B02F50(i);
            if (r1 <= 13.0f && r2 <= 26.0f) {
                it->unkD8 = 1;
            } else {
                it->unkD8 = 0;
            }
        } else {
            it->unkD0 = 4;
        }
    }

    task = func_01B051E8((void *)func_01B02258);
    task[0x18] = 1;
    func_01B053B0(task);
    func_01B09048(s + 0x11E0, 30, 50, 0.5f, 1.0f);
    *(float *)(s + 0x11E0) = 0.6f;
    func_00297CE8(*(s32 *)(s + 0x54BC));
    *(s32 *)(s + 0x54BC) = -1;
}
