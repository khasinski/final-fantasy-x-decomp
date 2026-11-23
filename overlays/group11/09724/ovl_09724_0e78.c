/* Shared 09724/09484 callback pair (140 B + 132 B). */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x5C];
    void *w5C;
    u8 pad60[0x1DC];
    void *w23C;
} OvlGfx;

typedef struct {
    u8 pad00[0x20];
    OvlGfx *p20;
} OvlSys;

typedef struct {
    u8 pad00[0x06];
    u16 h06;
} OvlSub;

typedef struct {
    u8 pad00[0x50];
    u8 s50[0xC0];
    OvlSub sub110;
    u8 pad118[0x18];
    OvlSub sub130;
} OvlCbObj;

extern OvlSys *D_006A3924;
extern float g_ovl_ang;
extern u8 g_ovl_res[];

extern void *func_002B49A0(void *, int, int);
extern void fn_ovl_4770(float, float);
extern void fn_ovl_4868(void *, void *, long, int, int);

void ovl_09724_0e78(OvlCbObj *a0)
{
    void *p50;
    OvlSub *sub;
    OvlGfx *gfx;
    long *p;

    fn_ovl_4770(0.94f, g_ovl_ang);
    p50 = a0->s50;
    sub = &a0->sub110;
    gfx = D_006A3924->p20;
    p = (long *)func_002B49A0(g_ovl_res, 2, 0);
    fn_ovl_4868(gfx->w5C, p50, *p, (short)sub->h06 >> 7, 1);
}

void ovl_09724_0f08(OvlCbObj *a0)
{
    void *p50;
    OvlSub *sub;
    OvlGfx *gfx;
    long *p;

    fn_ovl_4770(0.0f, g_ovl_ang);
    p50 = a0->s50;
    sub = &a0->sub130;
    gfx = D_006A3924->p20;
    p = (long *)func_002B49A0(g_ovl_res, 2, 0);
    fn_ovl_4868(gfx->w23C, p50, *p, (short)sub->h06 >> 7, 1);
}
