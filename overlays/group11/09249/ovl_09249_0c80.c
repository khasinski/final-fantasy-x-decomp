#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    Vec4 vecD0;
    u8 padE0[0x8];
    float fE8;
    u8 padEC[0x24];
    void *p110;
    u8 pad114[0x1C];
} Obj130;

typedef struct {
    Obj130 objs[3];     /* 0x000..0x38F */
    u8 pad390[0x30];
    Vec4 vec3C0;        /* 0x3C0 */
    s32 w3D0;           /* 0x3D0 */
    float f3D4;         /* 0x3D4 */
    s32 w3D8;
    s32 w3DC;
    Vec4 vec3E0;        /* 0x3E0 */
    Vec4 vec3F0;        /* 0x3F0 */
    u8 sub400[0x40];    /* 0x400 */
    u8 sub440[0x40];    /* 0x440 */
    u8 sub480[0x40];    /* 0x480 */
    u8 sub4C0[0x40];    /* 0x4C0 */
    u8 sub500[0x40];    /* 0x500 */
    s32 w540;           /* 0x540 */
    s32 w544;           /* 0x544 */
    s32 w548;           /* 0x548 */
    s32 w54C;           /* 0x54C */
    s32 w550;           /* 0x550 */
    s32 state;          /* 0x554 */
    s32 done;           /* 0x558 */
} Work62B0;

extern Work62B0 *D_01B062B0;
extern u8 D_01B062C0[];
extern u8 D_01B0BA10[];
extern u8 D_01B00518[];
extern u8 D_01B00548[];
extern u8 D_01B045B8[];
extern u8 D_01B00530[];
extern u8 D_01B06290[];

extern void func_01B01068(void);
extern void func_01B05A98(void *, float, float, s32, s32);
extern void func_01B04018(void *, void *, s32, s32, s32, void *, float);
extern void func_01B037A0(void *, void *, void *);
extern void func_01B016F8(s32, void *, s32);
extern float func_01B04B38(float, float, float, float, float);
extern s32 func_01B01540(s32);
extern void func_00110540(s32, s32, float);
extern void func_01B03438(void *, s32);
extern void func_00103208(s32);
extern void func_01B02D40(s32);
extern void func_01B011B8(void);
extern void func_01B03198(void *);

void ovl_09249_0c80(void)
{
    Work62B0 *s4 = D_01B062B0;
    s32 st;

    switch (s4->state) {
    case 0:
        {
            Obj130 *obj;

            func_01B01068();
            func_01B05A98(s4->sub400, 1.0f, 0.3f, 30, 0);
            obj = &s4->objs[2];
            func_01B04018(D_01B062C0, obj, 2, 0, 0, 0, 0.035f);
            {
                register Vec4 *d __asm__("$3") = &obj->vecD0;
                MMI_COPY_LQ_A3(d, &s4->vec3F0);
                MMI_COPY_SQ_A3(d);
            }
            obj->fC4 = s4->f3D4;
            obj->vecD0.y -= 70.0f;
            func_01B037A0(s4->sub480, D_01B0BA10, D_01B00518);
            obj->p110 = s4->sub480;

            func_01B04018(D_01B062C0, &s4->objs[0], 0, 125, 0, 0, 0.03f);
            {
                register Vec4 *d __asm__("$3") = &s4->objs[0].vecD0;
                MMI_COPY_LQ_A3(d, &s4->vec3F0);
                MMI_COPY_SQ_A3(d);
            }
            s4->objs[0].fC4 = s4->f3D4;
            s4->objs[0].fE8 = -3.0f;
            s4->objs[0].vecD0.y -= 1.5f;
            func_01B037A0(s4->sub500, D_01B0BA10, D_01B00548);
            s4->objs[0].p110 = s4->sub500;

            obj = &s4->objs[1];
            func_01B04018(D_01B062C0, obj, 1, 189, 0, D_01B045B8, 0.5f);
            func_01B016F8(0, &obj->vecD0, 0);
            obj->fC4 = s4->f3D4;
            obj->vecD0.y -= 1.0f;
            func_01B037A0(s4->sub4C0, D_01B0BA10, D_01B00530);
            obj->p110 = s4->sub4C0;

            s4->w544 = 80;
            s4->w548 = 45;
            s4->state = 1;
        }
        break;
    case 1:
        {
            s32 n = 80;
            s4->w540 = ((n - s4->w544) << 7) / n;
            if (s4->w544 > 0) {
                if (s4->w548 > 0) {
                    s4->w548--;
                } else {
                    s4->w544--;
                    s4->vec3E0.y = func_01B04B38(s4->vec3F0.y, s4->vec3F0.y, s4->vec3F0.y - 5.0f, s4->vec3F0.y - 50.0f, (float)s4->w544 / 80.0f);
                }
            } else {
                s4->w54C = 70;
                s4->state = 2;
            }
        }
        break;
    case 2:
        if (--s4->w54C <= 0) {
            func_00110540(func_01B01540(1), 24, 0.0f);
            s4->w550 = 25;
            s4->state = 3;
        }
        break;
    case 3:
        s4->w550--;
        s4->w540 = (s4->w550 << 7) / 25;
        if (s4->w550 <= 0) {
            func_01B03438(D_01B06290, 0);
            func_00103208(func_01B01540(1));
            func_01B02D40(12308);
            func_01B05A98(s4->sub440, 0.3f, 1.0f, 30, 10);
            s4->done = 1;
            s4->state = 4;
        }
        break;
    case 4:
        break;
    }

    st = s4->state;
    if (st != 0 && st != 4) {
        func_01B011B8();
    }
    MMI_COPY_LQ_A3(&s4->vec3C0, &s4->vec3E0);
    MMI_COPY_SQ_A3(&s4->vec3C0);
    func_01B03198(D_01B06290);
}
