#include "common.h"

typedef unsigned long u64;

typedef struct {
    u8 pad00[0x720];
    u8 unk720[0x5A0];
    void *unkCC0;
    u8 padCC4[0xA4];
    float unkD68;
    u8 padD6C[0x4];
    s32 unkD70;
} Work2850;

typedef struct {
    u8 pad00[0x4];
    s32 unk04;
    u8 pad08[0xD];
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 pad19[0xAB];
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
} Unk0628;

typedef struct {
    s32 unk00;
    void *unk04;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 pad0B;
    s16 unk0C;
    s16 unk0E;
    s32 unk10;
    s32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    u8 pad30[0x4];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s16 unk40;
    s16 unk42;
    s32 unk44;
    s32 unk48;
    u8 unk4C;
    u8 unk4D;
    u8 pad4E[0x22];
} DrawParam2AF8; /* size 0x70 */

extern Unk0628 D_01B00628;
extern Work2850 *D_01B0A068;
extern void *D_01B0A074;
extern void *D_01B0A078;
extern u8 D_01B0FCB0[];

extern void *func_001038F8(void);
extern void func_00110648(s32, s32);
extern u64 *func_002B49A0(void *, s32, s32);
extern void func_002B7BE8(void *, DrawParam2AF8 *, void *, void *, void *);
extern void func_002DCE38(float (*)[4], float (*)[4], float (*)[4]);
extern void func_002DD128(float (*)[4]);
extern void func_002DD318(float (*)[4], float (*)[4], float);
extern void func_01B00B28(void);
extern void func_01B00C00(void);
extern void func_01B00CE8(void *, void *, void *, float (*)[4], u64, s32);
extern void func_01B017C8(void);
extern void func_01B022E0(void);
extern void *func_01B037F0(s32);
extern float func_01B03880(s32);
extern void func_01B03EF8(s32, void *);
extern void func_01B046E0(s32, s32);
extern void func_01B04C18(s32, void *);
extern s32 func_01B04FB0(s32);
extern void func_01B05078(float (*)[4], float (*)[4]);
extern void func_01B05228(float (*)[4]);
extern void func_01B05258(float (*)[4]);
extern void *func_01B05F68(void (*)(void));
extern void func_01B06130(void *);

static inline void add_angle(float *p, float d) {
    float ang = *p + d;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *p = ang;
}

void func_01B02850(void) {
    float mat[4][4];
    Work2850 *work = D_01B0A068;
    void *p;
    u64 val;
    float ang;

    func_01B00B28();
    p = func_01B037F0(1);
    val = *func_002B49A0(D_01B0FCB0, 2, 5);
    add_angle(&work->unkD68, 0.062831856f);

    func_002DD128(mat);
    ang = func_01B03880(-1) + 3.1415927f + work->unkD68;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    func_002DD318(mat, mat, ang);
    func_01B00CE8(p, D_01B0A074, work->unk720, mat, val, 0x80);
    func_01B00C00();
}

void func_01B029D0(void) {
    Unk0628 *tbl = &D_01B00628;
    Work2850 *work;
    s32 id;

    id = func_01B04FB0(0x3019);
    tbl->unkC4 = id;
    tbl->unk15 = 0x20;
    func_00110648(id, 0);

    id = func_01B04FB0(0x301F);
    tbl->unkC8 = id;
    tbl->unk16 = 0x21;
    func_00110648(id, 0);

    id = func_01B04FB0(0x301F);
    tbl->unkCC = id;
    tbl->unk17 = 0x22;
    func_00110648(id, 0);

    id = func_01B04FB0(0x301F);
    tbl->unkD0 = id;
    tbl->unk18 = 0x23;
    func_00110648(id, 0);

    {
        register s32 five __asm__("$2") = 5;
        tbl->unk04 = five;
    }
    work = D_01B0A068;
    func_01B04C18(1, work->unk720);
    func_01B03EF8(-1, work->unk720);
    func_01B017C8();
    func_01B022E0();
    func_01B046E0(1, 1);
    work->unkD68 = 0.0f;
    work->unkCC0 = func_01B05F68(func_01B02850);
    func_01B06130(work->unkCC0);
}
