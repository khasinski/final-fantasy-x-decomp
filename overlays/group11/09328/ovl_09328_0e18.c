#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x10];
    s32 fn10;
} SubTask;

typedef struct {
    u8 pad00[0x8];
    SubTask *sub08;
    u8 pad0C[0x8];
    s32 state14;
} Task0E18;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0xD0];
    Vec4 vecD0;
    u8 padE0[0x40];
    s32 w120;
} Obj6418;

typedef struct {
    u8 pad00[0x10];
    Vec4 pos;
    u8 pad20[0x240];
    Vec4 pos260;
    float vx;
    float vy;
    float vz;
    float vw;
    void *cb280;
    void *cb284;
    u8 pad288[0xC];
    s32 w294;
    u16 flags298;
    u8 pad29A[0x6];
} Work2A0;

extern u8 D_01B064B8[];
extern u8 D_01B064E0[];
extern u8 D_01B06528[];
extern void *D_01B0656C;
extern u8 D_01B00880[];
extern u8 D_01B04650[];

extern s32 func_01B03210(void *);
extern void func_01B01770(s32, void *, s32);
extern void func_01B03A10(void *, void *);
extern s32 func_01B03870(void *);
extern s32 func_01B04170(void *, void *);
extern Obj6418 *func_01B06418(void);
extern void func_01B04090(void *, void *, s32, s32, s32, void *, float);
extern void func_01B011C0(void *);
extern void func_002DD0B0(void *, void *);
extern s32 func_01B01520(s32);

void ovl_09328_0e18(Task0E18 *s2)
{
    Vec4 v;
    s32 s1 = func_01B03210(D_01B064B8);
    s32 s0;
    s32 r;

    func_01B01770(-1, &v, 0);
    func_01B03A10(D_01B064E0, &v);
    s0 = func_01B03870(D_01B064E0);
    r = func_01B04170(D_01B06528, D_01B0656C);
    if (r == 1 && s1 == 1 && s0 == 1) {
        s2->state14 = 3;
        s2->sub08->fn10 = (s32)D_01B00880;
    }
}

void ovl_09328_0ed8(Work2A0 *s0)
{
    if (s0->pos.x > -55.0f && s0->pos.x < 55.0f && s0->pos.z > -91.0f && s0->pos.y >= 0.0f) {
        Obj6418 *obj;

        s0->flags298 |= 2;
        if (s0->vy != 0.0f) {
            float t = 1.0f - (-(s0->pos.y - s0->vy) / s0->vy);
            s0->pos.x -= s0->vx * t;
            s0->pos.z -= s0->vz * t;
        }
        s0->pos.y = 0.0f;
        __asm__ volatile("" : : : "memory");
        {
            u_long128 *dst = (u_long128 *)&s0->pos260;
            u_long128 *src = (u_long128 *)&s0->pos;
            register u_long128 _t __asm__("$7");
            __asm__("" : "+r"(dst), "+r"(src));
            _t = *src;
            *dst = _t;
            obj = func_01B06418();
            if (obj != 0) {
                func_01B04090(D_01B06528, obj, 0, 0, 0, 0, 0.12f);
                {
                    register u_long128 *d2 __asm__("$3") = (u_long128 *)&obj->vecD0;
                    __asm__("" : "+r"(d2));
                    _t = *dst;
                    *d2 = _t;
                }
            }
        }
        s0->cb280 = 0;
        func_01B011C0(s0);
    }
}

void ovl_09328_1040(Work2A0 *s1)
{
    Obj6418 *s0 = func_01B06418();

    if (s0 != 0) {
        func_01B04090(D_01B06528, s0, 0, 0, 0, D_01B04650, 0.12f);
        func_002DD0B0(&s0->vecD0, &s1->pos260);
        s0->w120 = func_01B01520(s1->w294);
        func_01B011C0(s1);
    }
}
