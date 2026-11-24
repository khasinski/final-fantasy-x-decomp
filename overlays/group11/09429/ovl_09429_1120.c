#include "vu0.h"

typedef struct {
    u8 pad00[0x10];
    void *p10;
} OvlSubTask;

typedef struct {
    u8 pad00[0x08];
    OvlSubTask *p08;
    u8 pad0C[0x08];
    int w14;
} OvlTask;

typedef struct {
    u8 pad00[0x18];
    u16 h18;
} OvlObj18;

typedef struct {
    u8 pad00[0x2C];
    u16 h2C;
} OvlObj2C;

typedef struct {
    u8 pad00[0x80];
    float m80[16];
    float fC0;
    float fC4;
    float fC8;
    u8 padCC[0x04];
    float pos[4];
    u8 padE0[0x40];
    int idx120;
} OvlObj;

extern u8 g_68a8[];
extern u8 g_68e0[];
extern int g_6924;
extern int g_68c8;
extern int g_68cc;
extern int g_68d0;
extern OvlObj18 *g_68d4;
extern OvlObj2C *g_68d8;
extern int g_0688[];
extern void fn_0b50(void);

extern int func_01B032F0(void *);
extern int func_01B04250(void *, int);
extern void func_01B01E98(void *);
extern float func_01B01CA0(int);
extern void func_01B01850(int, void *, int);
extern void func_01B04EA0(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern OvlObj *func_01B05F98(void);
extern float func_002B3DB0(float);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_01B04170(void *, void *, int, int, int, int, float);
extern void func_01B01E10(int, int, void *);
extern void func_002DD1C8(void *, void *, float);

void ovl_09429_1120(OvlTask *task)
{
    int r0;
    int r1;

    r0 = func_01B032F0(g_68a8);
    r1 = func_01B04250(g_68e0, g_6924);
    if (r1 == 1 && r0 == 1 && g_68d0 <= 0 && (g_68d8->h2C & 0x8000) && (g_68d4->h18 & 0x8000)) {
        *(volatile int *)&task->w14 = 3;
        *(void * volatile *)&task->p08->p10 = (void *)fn_0b50;
    }
}

void ovl_09429_11d8(void)
{
    float m0[16];
    float m1[16];
    float v80[4];
    float v90[4];
    float vA0[4];
    float vB0[4];
    float vC0[4];
    int i;
    OvlObj *obj;

    if (g_68cc > 0) {
        g_68cc--;
        return;
    }
    if (g_68d0 <= 0) {
        return;
    }
    g_68d0--;
    if (++g_68c8 < 4) {
        return;
    }
    g_68c8 = 0;

    func_01B01E98(vA0);
    vA0[1] = func_01B01CA0(0) - 12.0f;
    vB0[0] = 0.0f;
    vB0[1] = 0.0f;
    vB0[3] = 1.0f;
    func_01B01850(-1, v80, 0);
    v80[1] = vA0[1];
    func_01B04EA0(v90, vA0, v80);
    func_002DD128(m1);
    m1[10] = 0.5f;
    func_002DD318(m1, m1, v90[1]);

    for (i = 0; i < 3; i++) {
        obj = func_01B05F98();
        if (obj == 0) {
            continue;
        }
        vB0[2] = func_002B3DB0(58.0f);
        func_002DD128(m0);
        func_002DD318(m0, m0, func_002B3DB0(3.1415927f));
        func_002DCE38(m0, m1, m0);
        func_002DCE08(vC0, m0, vB0);
        func_01B04170(g_68e0, obj, 0, 0, 0, 0, 0.2f);
        obj->fC0 = func_002B3DB0(0.17453294f);
        obj->fC4 = func_002B3DB0(6.2831855f);
        obj->fC8 = func_002B3DB0(0.17453294f);
        obj->pos[0] = vA0[0] + vC0[0];
        obj->pos[1] = vA0[1] + vC0[1];
        obj->pos[2] = vA0[2] + vC0[2];
    }
}

void ovl_09429_1400(OvlObj *obj)
{
    float m0[16];
    float m1[16];

    func_01B01E10(-1, g_0688[obj->idx120], m0);
    func_002DD128(m1);
    func_002DD1C8(m1, m1, 1.5707964f);
    func_002DCE38(obj->m80, m0, m1);
    MMI_COPY_LQ_A3(obj->pos, &m0[12]);
    MMI_COPY_SQ_A3(obj->pos);
}
