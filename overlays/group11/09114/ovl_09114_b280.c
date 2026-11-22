#include "common.h"

typedef struct TrackVal {
    u8 pad00[0x20];
    u32 vec20[3];
    float f2C;
} TrackVal;

typedef struct InnerObj {
    u8 pad00[0x20];
    float mtx20[4][4];  /* 0x20 */
    float mtx60[4][4];  /* 0x60 */
    float mtxA0[4][4];  /* 0xA0 */
    float mtxE0[4][4];  /* 0xE0 */
    u32 f120[3];        /* 0x120 */
    u8 pad12C[0x4];
    float vec130[3];    /* 0x130 */
    float f13C;         /* 0x13C */
    TrackVal *p140;     /* 0x140 */
    TrackVal *p144;     /* 0x144 */
    TrackVal *p148;     /* 0x148 */
    u8 pad14C[0x4];
    void *p150;         /* 0x150 */
    void *p154;         /* 0x154 */
} InnerObj;

typedef struct OuterObj {
    InnerObj *p00;
    u8 b04;
    u8 b05;
} OuterObj;

void func_01B1B6A8(OuterObj *a0);
void func_01B1B7C0(TrackVal *a0, u32 a1);
void func_01B1B820(TrackVal *a0, u32 a1);
void func_001072F8(void *a0, void *a1, float (*mtx)[4]);
void func_01B1B880(float (*mtx)[4], void *vec);
void func_002DD068(void *dst, void *src, float s);
void func_002DD0B0(void *dst, void *src);
float func_00110AF0(void *a0);
void func_002DCEC8(float *dst, float *src);
void func_002DCE38(float (*dst)[4], float (*a1)[4], float (*a2)[4]);
void func_002DCE08(float *dst, float (*a1)[4], float *a2);

void func_01B1B280(register OuterObj *a0)
{
    InnerObj *p = a0->p00;
    float mtx10[4][4];
    float mtx50[4][4];
    float vec90[4];
    float unused_a0[4];

    func_01B1B6A8(a0);
    if (!(a0->b04 & 1)) {
        return;
    }

    func_01B1B7C0(p->p140, a0->b05);
    func_01B1B820(p->p148, a0->b05);
    func_01B1B7C0(p->p144, a0->b05);
    func_001072F8(p->p150, p->p154, mtx10);
    func_01B1B880(p->mtx60, p->p148->vec20);
    func_002DD068(vec90, p->p144->vec20, p->p144->f2C * 1000.0f);
    func_002DD068(p->mtx20[0], p->mtx60[0], vec90[0]);
    func_002DD068(p->mtx20[1], p->mtx60[1], vec90[1]);
    func_002DD068(p->mtx20[2], p->mtx60[2], vec90[2]);
    func_002DD0B0(p->mtx20[3], p->p140->vec20);
    p->f120[0] = p->p148->vec20[0];
    p->f120[1] = p->p148->vec20[1];
    p->f120[2] = p->p148->vec20[2];
    func_002DD0B0(p->vec130, p->p144->vec20);
    p->f13C *= func_00110AF0(p->p150);
    func_002DCEC8(mtx50[0], mtx10[0]);
    func_002DCEC8(mtx50[1], mtx10[1]);
    func_002DCEC8(mtx50[2], mtx10[2]);
    mtx50[3][0] = mtx50[3][1] = mtx50[3][2] = 0.0f;
    mtx50[3][3] = 1.0f;
    func_002DCE38(p->mtxE0, mtx50, p->mtx60);
    func_002DCE38(p->mtxA0, mtx10, p->mtx20);
    func_002DCE08(p->mtxA0[3], mtx10, p->mtx20[3]);
}
