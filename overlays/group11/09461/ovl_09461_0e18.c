#include "common.h"
#include "vu0.h"

typedef union {
    float v[4];
    u_long128 q;
} Vec128;

typedef struct {
    u8 pad00[0x10];
    Vec128 vec10;
    float vec20[4];
    float vec30[4];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    u8 b44;
    u8 b45;
    u8 b46;
    u8 b47;
    float f48;
    u8 pad4C[4];
    float f50;
    float f54;
    float f58;
    float f5C;
    float f60;
    u32 w64;
    s32 w68;
    u32 w6C;
    s32 w70;
    u32 w74;
    s32 w78;
    u32 w7C;
} Part80;

extern s32 D_01B06D58;
extern s32 D_01B06D5C;
extern s32 D_01B06D60;
extern s32 D_01B06D54;
extern u8 D_01B0D3E0;
extern u8 D_01B06D78;

extern void func_1B021D8(s32, s32, s32, float *);
extern float func_1B01C10(s32);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_002DD128(float (*)[4]);
extern void func_002DD270(float (*)[4], float (*)[4], float);
extern void func_002DD318(float (*)[4], float (*)[4], float);
extern Part80 *func_1B01440(void);
extern void *func_002B49A0(void *, s32, s32);
extern void **func_1B04BE8(void *, s32);
extern void func_002DCE08(float *, float (*)[4], float *);
extern void func_1B05A20(Part80 *, void *);
extern s32 func_002EFD78(void);

static inline void *call_2b49a0(void *a0, s32 a1, s32 a2)
{
    return func_002B49A0(a0, a1, a2);
}

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void ovl_09461_0e18(void)
{
    float mat[4][4];
    Vec128 vec40;
    s32 cnt;
    float t;
    float spread;
    register float rx __asm__("$f22");
    float ry;
    float ang;
    s32 d54;
    s32 i;

    if (D_01B06D58 > 0) {
        D_01B06D58--;
        return;
    }
    if (D_01B06D5C <= 0) {
        return;
    }
    D_01B06D5C--;
    if (D_01B06D60 > 0) {
        D_01B06D60--;
    }
    cnt = D_01B06D60;
    t = (float)cnt / 60.0f;
    spread = (1.0f - t) * 0.7853981852531433f + t * 0.3141592741012573f;
    func_1B021D8(-1, 11, 0, vec40.v);
    rx = 0.0f;
    ry = func_1B01C10(-1);
    rx = (func_002B3DB0(0.15707963705062866f) + func_002B3DF8(0.15707963705062866f)) + rx;
    ry += func_002B3DB0(spread);
    if (rx > 3.1415927410125732f) {
        rx -= 6.2831854820251465f;
    } else if (rx < -3.1415927410125732f) {
        rx += 6.2831854820251465f;
    }
    ang = ry + 3.1415927410125732f;
    if (ang > 3.1415927410125732f) {
        ang -= 6.2831854820251465f;
    } else if (ang < -3.1415927410125732f) {
        ang += 6.2831854820251465f;
    }
    ry = ang;

    func_002DD128(mat);
    func_002DD270(mat, mat, rx);
    func_002DD318(mat, mat, ry);

    d54 = D_01B06D54;

    for (i = 0; i < 2; i++) {
        {
            Part80 *p1 = func_1B01440();
            register void *s1 __asm__("$17");
            float sc;
            if (p1 == 0) {
                return;
            }
            s1 = call_2b49a0(&D_01B0D3E0, 9, 0);
            copy_vec(p1->vec10.v, vec40.v);
            p1->vec20[0] = 0.0f;
            p1->vec20[1] = 0.0f;
            p1->vec20[2] = func_002B3DB0(1.5f) + 6.0f;
            p1->vec20[3] = 0.0f;
            func_002DCE08(p1->vec20, mat, p1->vec20);
            p1->vec20[3] = func_002B3DB0(3.1415927410125732f);
            p1->vec30[0] = 0.0f;
            p1->vec30[1] = 0.0f;
            p1->vec30[2] = 0.0f;
            p1->vec30[3] = 1.0f;
            p1->f48 = (float)d54;
            func_1B05A20(p1, s1);
            p1->b42 = 0x60;
            p1->b43 = (func_002EFD78() % 0x41) + 0x20;
            p1->b47 = 0;
            p1->w68 = 8;
            sc = (func_002B3DF8(1.0f) + 1.0f) * 0.30000001192092896f;
            p1->w64 = 0;
            p1->f54 = 0.10000000149011612f;
            p1->f58 = 1.0f;
            p1->w70 = 10;
            p1->w74 = 0;
            p1->f5C = -5.0f;
            p1->f50 = sc;
            p1->f60 = sc * -18.0f;
        }

        {
            Part80 *p2 = func_1B01440();
            register void *s1 __asm__("$17");
            float sc;
            if (p2 == 0) {
                return;
            }
            s1 = *func_1B04BE8(&D_01B06D78, 1);
            copy_vec(p2->vec10.v, vec40.v);
            p2->vec20[0] = 0.0f;
            p2->vec20[1] = 0.0f;
            p2->vec20[2] = func_002B3DB0(1.0f) + 4.800000190734863f;
            p2->vec20[3] = 0.0f;
            func_002DCE08(p2->vec20, mat, p2->vec20);
            p2->vec20[3] = func_002B3DB0(3.1415927410125732f);
            p2->vec30[0] = 0.0f;
            p2->vec30[1] = 0.0f;
            p2->vec30[2] = 0.0f;
            p2->vec30[3] = 1.0f;
            p2->f48 = (float)d54;
            func_1B05A20(p2, s1);
            p2->b47 = 0;
            p2->w68 = 8;
            sc = (func_002B3DF8(1.0f) + 1.0f) * 0.699999988079071f;
            p2->f54 = 0.10000000149011612f;
            p2->w70 = 10;
            p2->f5C = -5.0f;
            p2->w64 = 0;
            p2->f50 = sc;
            p2->f58 = 1.0f;
            p2->w74 = 0;
            p2->f60 = sc * -10.0f;
        }
    }

    {
        Part80 *p3 = func_1B01440();
        register void *s1 __asm__("$17");
        float sc;
        if (p3 == 0) {
            return;
        }
        s1 = *func_1B04BE8(&D_01B06D78, 2);
        copy_vec(p3->vec10.v, vec40.v);
        p3->vec20[0] = 0.0f;
        p3->vec20[1] = 0.0f;
        p3->vec20[2] = func_002B3DB0(1.0f) + 16.799999237060547f;
        p3->vec20[3] = 0.0f;
        func_002DCE08(p3->vec20, mat, p3->vec20);
        p3->vec20[3] = func_002B3DB0(3.1415927410125732f);
        p3->f48 = (float)d54;
        p3->vec30[0] = 0.0f;
        p3->vec30[2] = 0.0f;
        p3->vec30[3] = 1.0f;
        p3->vec30[1] = 0.20000000298023224f;
        func_1B05A20(p3, s1);
        p3->w68 = 8;
        p3->b47 = 0;
        sc = (func_002B3DF8(0.5f) + 1.0f) * 0.009999999776482582f;
        p3->w78 = 1;
        p3->f60 = 1000.0f;
        p3->f5C = 0.0f;
        p3->w64 = 0;
        p3->f50 = sc;
    }
}
