/* Shared projectile launch/init (204 B, 8 open containers; 09304 @ 0x01B056A8). */

#include "common.h"

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    float posD0[4];
    u8 padE0[0x280];
    float tgt360[4];
    float vel370[4];
    u8 pad380[0x0C];
    float speed38C;
} ProjObj;

typedef struct {
    u8 pad00[0x14];
    void *p14;
} TaskObj;

extern void func_01B049A0(float *, float *, float *);
extern void func_002DD128(float *);
extern void func_002DD270(float *, float *, float);
extern void func_002DD318(float *, float *, float);
extern void func_002DCE08(float *, float *, float *);
extern TaskObj *func_01B03910(void *);
extern void func_01B03AD8(TaskObj *);
extern void fn_5778(void);

void ovl_09304_56a8(ProjObj *o, int mode, float speed)
{
    float mat[16];
    float ang[4];
    TaskObj *t;

    o->vel370[0] = 0.0f;
    o->vel370[1] = 0.0f;
    o->vel370[2] = -speed;
    o->vel370[3] = 0.0f;
    func_01B049A0(ang, o->posD0, o->tgt360);
    func_002DD128(mat);
    func_002DD270(mat, mat, ang[0]);
    func_002DD318(mat, mat, ang[1]);
    func_002DCE08(o->vel370, mat, o->vel370);
    if (mode == 1) {
        o->fC0 = ang[0];
        o->fC4 = ang[1];
    }
    o->speed38C = speed;
    t = func_01B03910((void *)fn_5778);
    t->p14 = o;
    func_01B03AD8(t);
}
