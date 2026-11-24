#include "common.h"

typedef struct {
    s32 w00;
    s32 w04;
} Pair7E8;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} Ctx7E88;

typedef struct {
    u8 pad00[0xD0];
    u8 vecD0[0x10];
} Obj8000;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x50];
    float f50;
    float f54;
    float f58;
    u8 pad5C[0x4];
    float f60;
    float f64;
    float f68;
} CamObj;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj7E20;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Node3C30;

extern s32 D_01B07D10;
extern Pair7E8 D_01B007E8;
extern u8 D_01B92C00[];
extern u8 *D_01B08130;
extern u8 *D_01B08134;
extern u8 *D_01B07E80;
extern u8 D_01B0D6B0[];
extern Ctx7E88 D_01B07E88;
extern u8 D_01B00040[];
extern Obj8000 D_01B08000;
extern u8 D_01B07DD8[];
extern u8 D_01B00790[];
extern u8 D_01B07D18[];
extern u8 D_01B00720[];
extern u8 D_01B07D78[];
extern u8 D_01B00748[];
extern Obj7E20 D_01B07E20;
extern u8 D_01B00680[];
extern u8 D_01B00F08[];
extern u8 D_01B00F38[];
extern s32 D_01B07E84;

extern void func_01B01320(s32);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B03EB8(void *, void *, void *, s32);
extern void func_01B03F90(void *, void *, s32, s32, s32, s32, float);
extern void func_01B01670(s32, void *, s32);
extern void func_01B03058(s32, void *, void *);
extern void func_01B064A8(void *, void *);
extern void func_01B065C8(s32);
extern void func_01B068B0(s32);
extern CamObj *func_01B068F8(s32);
extern void func_01B07BA0(void *, void *, void *, s32);
extern Node3C30 *func_01B03C30(void *);
extern void func_01B03DF8(void *);
extern void func_01B07640(void *, s32);

s32 ovl_09347_0ce0(void)
{
    Vec4 v;
    u8 *s3 = D_01B92C00;
    u8 *s2;
    Ctx7E88 *s1;
    CamObj *cam;
    Node3C30 *n;

    D_01B08130 = s3;
    D_01B08134 = s3 + 0x40000;
    D_01B07E80 = s3 + 0x140000;
    D_01B007E8.w00 = 20;
    D_01B007E8.w04 = 0;
    func_01B01320(D_01B07D10);

    s2 = D_01B0D6B0;
    s1 = &D_01B07E88;
    s1->w2C = func_002B49A0(s2, 8, 0);
    func_01B03EB8(s1, D_01B00040, D_01B08130, 0x40000);
    func_01B03F90(s1, &D_01B08000, 1, 0, 0, 0, 0.4f);
    func_01B01670(-1, D_01B08000.vecD0, 1);
    func_01B03058(-1, D_01B07DD8, D_01B00790);
    func_01B064A8(D_01B07D18, D_01B00720);
    func_01B064A8(D_01B07D78, D_01B00748);
    func_01B065C8(1);
    func_01B01670(-1, &v, 1);
    func_01B068B0(0);
    cam = func_01B068F8(0);
    cam->f50 = -88.7f;
    cam->f54 = 5.0f;
    cam->f58 = 54.73f;
    {
        float x = v.x;
        float y = v.y;
        float z = v.z;
        cam->f60 = x;
        cam->f64 = y;
        cam->f68 = z;
    }
    func_01B07BA0(&D_01B07E20, s2, D_01B00680, 1);
    D_01B07E20.w54 = -1;
    n = func_01B03C30(D_01B00F08);
    n->b18 = 1;
    func_01B03DF8(n);
    func_01B07640(s3 + 0x160000, 512);
    n = func_01B03C30(D_01B00F38);
    n->b18 = 2;
    func_01B03DF8(n);
    D_01B07E84 = 0;
    return 0;
}
