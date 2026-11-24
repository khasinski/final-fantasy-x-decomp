#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x4];
    s32 w04;
    u8 pad08[0xD];
    u8 b15;
    u8 pad16[0xAE];
    s32 wC4;
} Obj5E8;

typedef struct {
    u8 pad00[0x390];
    u8 sub390[0x40];
    s32 w3D0;
    float f3D4;
    s32 w3D8;
    s32 w3DC;
    Vec4 vec3E0;
    Vec4 vec3F0;
} Work62B0;

typedef struct {
    Vec4 pos;
    float vx, vy, vz;
    s32 w1C;
    s32 w20;
    float f24;
    s32 w28;
    float f2C;
    u8 sub30[0xC];
    float f3C;
    float f40;
    u8 pad44[0x8];
    s32 w4C;
    s32 w50;
    u8 pad54[0x4];
    s32 w58;
    s32 w5C;
    u8 pad60[0xB];
    u8 b6B;
} Part5D68;

extern Work62B0 *D_01B062B0;
extern Obj5E8 D_01B005E8;
extern u8 D_01B06290[];
extern u8 D_01B00560[];
extern u8 D_01B0BA10[];

extern s32 func_01B02D00(s32);
extern void func_00110648(s32, s32);
extern float func_01B015D0(s32);
extern void func_01B016F8(s32, void *, s32);
extern void func_01B02968(s32, void *);
extern void func_01B02EE8(s32, void *, void *);
extern void func_01B03150(s32, void *, void *);
extern Part5D68 *func_01B05D68(void);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B053E0(void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);

void ovl_09249_1068(void)
{
    Work62B0 *s1 = D_01B062B0;
    Obj5E8 *s0 = &D_01B005E8;
    s32 id;
    float ang;

    id = func_01B02D00(12308);
    s0->b15 = 32;
    s0->wC4 = id;
    func_00110648(id, 0);
    {
        register s32 next __asm__("$3") = s0->w04;
        s1->w3D0 = 0;
        s0->w04 = next + 1;
    }
    ang = func_01B015D0(0) + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s1->w3D8 = 0;
    s1->w3DC = 0;
    s1->f3D4 = ang;
    func_01B016F8(0, &s1->vec3F0, 0);
    s1->vec3F0.y -= 20.0f;
    MMI_COPY_LQ_A3(&s1->vec3E0, &s1->vec3F0);
    MMI_COPY_SQ_A3(&s1->vec3E0);
    s1->vec3E0.y -= 50.0f;
    func_01B02968(1, s1->sub390);
    func_01B02EE8(1, s1->sub390, &s1->w3D0);
    func_01B03150(1, D_01B06290, D_01B00560);
}

void ovl_09249_11b8(void)
{
    Work62B0 *s1 = D_01B062B0;
    Part5D68 *s0 = func_01B05D68();

    if (s0 != 0) {
        func_01B053E0(s0->sub30, func_002B49A0(D_01B0BA10, 9, 0));
        MMI_COPY_LQ_A3(&s0->pos, &s1->vec3E0);
        MMI_COPY_SQ_A3(&s0->pos);
        s0->pos.x += func_002B3DB0(4.0f);
        s0->pos.y += func_002B3DB0(4.0f);
        s0->pos.z += func_002B3DB0(4.0f);
        s0->vx = func_002B3DB0(0.001f);
        s0->vy = -func_002B3DF8(0.001f);
        s0->vz = func_002B3DB0(0.001f);
        s0->w1C = 0;
        s0->w20 = 0;
        s0->f24 = func_002B3DB0(0.005f) + (-0.01f);
        s0->w28 = 0;
        s0->f2C = 1.0f;
        {
            float sz = (func_002B3DB0(0.3f) + 0.7f) * 0.01f;
            s0->w5C = 0;
            s0->w4C = 24;
            s0->w50 = 24;
            s0->f40 = 0.5f;
            s0->w58 = 24;
            *(volatile float *)&s0->f3C = sz;
            *(volatile u8 *)&s0->b6B = 0;
        }
    }
}
