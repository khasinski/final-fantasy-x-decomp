#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
} Mgr6528;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float posD0[4];
} Obj6418;

typedef struct {
    u8 pad00[0x10];
    float v10[4];
    u8 pad20[0x240];
    float v260[4];
    u8 pad270[0x10];
    void *p280;
    void *p284;
    u8 pad288[0x8];
    s32 w290;
    s32 w294;
    u8 pad298[0x8];
} Entry2A0;

typedef struct {
    u8 pad00[0x1E4];
    s32 w1E4;
} Data478;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task;

extern u8 D_01B71CC0[];
extern u8 *D_01B06568;
extern u8 *D_01B0656C;
extern u8 *D_01B06520;
extern Mgr6528 D_01B06528;
extern u8 D_01B0B8E0[];
extern u8 D_01B00040[];
extern float D_01B003D8[];
extern Data478 D_01B00478;
extern u8 D_01B064E0[];
extern u8 D_01B003F0[];
extern u8 D_01B064B8[];
extern u8 D_01B00420[];

extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B03FB8(void *, void *, void *, s32);
extern void func_01B063C8(void *, s32);
extern float func_01B01648(s32);
extern void func_002DD128(void *);
extern void func_01B01770(s32, void *, s32);
extern void func_01B04EC8(void *, void *, void *);
extern Obj6418 *func_01B06418(void);
extern void func_01B04090(void *, void *, s32, s32, s32, s32, float);
extern float func_002B3DF8(float);
extern float func_002B3DB0(float);
extern void func_002DD318(void *, void *, float);
extern void func_002DCE08(void *, void *, void *);
extern void func_01B010D8(void *);
extern void func_01B02B60(void *);
extern s32 func_002EFD78(void);
extern void func_01B03818(void *, void *, void *);
extern void func_01B03158(s32, void *, void *);
extern Task *func_01B03D30(void *);
extern void func_01B03EF8(Task *);
extern void func_01B05AC8(void *, s32);
extern void func_01B00DE8(void);
extern void func_01B00E18(void);
extern void func_01B00ED8(void);
extern void func_01B01040(void);

s32 ovl_09328_08a0(void)
{
    float m00[16];
    float m40[16];
    float v80[4];
    float v90[4];
    float vA0[4];
    float vB0[4];
    s8 arrC0[16];
    u8 *p = D_01B71CC0;
    Entry2A0 *s1;
    float fs0f;
    float fs0;
    s32 s2;
    s32 s3 = 20;
    s32 s4 = 0;
    Obj6418 *s0;
    Task *t;
    Mgr6528 *mgr;

    D_01B06568 = p;
    D_01B0656C = p + 0x40000;
    D_01B06520 = p + 0x140000;
    mgr = &D_01B06528;
    mgr->w2C = func_002B49A0(D_01B0B8E0, 8, 0);
    func_01B03FB8(mgr, D_01B00040, D_01B06568, 0x40000);
    func_01B063C8(p + 0x164980, 0x80);

    s1 = (Entry2A0 *)(p + 0x160A80);
    v80[0] = 0.0f;
    v80[1] = 0.0f;
    v80[2] = -150.0f;
    v80[3] = 1.0f;

    fs0f = func_01B01648(-1);
    fs0 = fs0f - 0.7853982f;
    if (fs0 > 3.1415927f) {
        fs0 -= 6.2831855f;
    } else if (fs0 < -3.1415927f) {
        fs0 += 6.2831855f;
    }

    func_002DD128(m40);
    vA0[0] = 0.0f;
    vA0[1] = fs0f;
    vA0[2] = 0.0f;
    vA0[3] = 0.0f;
    vB0[0] = 0.0f;
    vB0[1] = 0.0f;
    vB0[2] = -13.0f;
    vB0[3] = 1.0f;

    func_01B01770(-1, v90, 0);
    v90[1] -= 41.0f;
    func_01B04EC8(vA0, v90, vB0);

    for (s2 = 0; s2 < 14; s2++) {
        float ang;
        s0 = func_01B06418();
        if (s0 == 0) {
            break;
        }
        func_01B04090(mgr, s0, 1, s3, 0, 0, 0.12f);
        copy_vec(s0->posD0, v90);
        s0->fC4 = fs0f;
        s0->posD0[1] += D_01B003D8[s4];
        copy_vec(s1->v10, s0->posD0);
        v80[1] = 60.0f - func_002B3DF8(50.0f);
        ang = fs0 + func_002B3DF8(1.5707964f);
        if (ang > 3.1415927f) {
            ang -= 6.2831855f;
        } else if (ang < -3.1415927f) {
            ang += 6.2831855f;
        }
        func_002DD318(m00, m40, ang);
        s4++;
        func_002DCE08(s1->v260, m00, v80);
        s1->w290 = s3;
        s1->w294 = s2;
        s1->p284 = 0;
        s1->p280 = (void *)func_01B00ED8;
        func_01B010D8(s1);
        s3 += 3;
        s1++;
        if (s4 >= 5) {
            s4 = 0;
        }
    }

    func_01B02B60(arrC0);
    s3 = 23;
    s1 = (Entry2A0 *)(p + 0x162F40);
    for (s2 = 0; s2 < D_01B00478.w1E4; s2++) {
        s32 id = arrC0[s2];
        copy_vec(s1->v10, v90);
        s1->v10[1] += D_01B003D8[func_002EFD78() % 5];
        func_01B01770(id, s1->v260, 1);
        s1->v260[0] += func_002B3DB0(1.0f);
        s1->v260[1] += func_002B3DB0(4.0f);
        s1->v260[2] += func_002B3DB0(1.0f);
        s1->w290 = s3;
        s1->w294 = id;
        s1->p280 = 0;
        s1->p284 = (void *)func_01B01040;
        func_01B010D8(s1);
        s1++;
        s3 += 2 + func_002EFD78() % 3;
    }

    func_01B03818(D_01B064E0, D_01B0B8E0, D_01B003F0);
    func_01B03158(-1, D_01B064B8, D_01B00420);
    t = func_01B03D30((void *)func_01B00DE8);
    t->b18 = 1;
    func_01B03EF8(t);
    func_01B05AC8(p + 0x160000, 0x18);
    t = func_01B03D30((void *)func_01B00E18);
    t->b18 = 2;
    func_01B03EF8(t);
    return 0;
}
