#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[6];
    s16 s76;
    u8 pad78[8];
} PppObj;

extern float D_01B00748;
extern float D_01B00758;
extern float D_01B0075C;
extern TtCfg *D_01B007B0;
extern u8 D_01B007B8;
extern float D_01B00A00[4];
extern int D_01B00AA4;

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern void func_00267530(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0B0(void *, void *);

int func_01B03C48(PppObj *p)
{
    float s;

    func_002DD0B0(p->pos, D_01B00A00);
    {
        float y = D_01B0075C;
        s = D_01B00748 * D_01B00758;
        p->pos[1] += y;
        p->scale[2] = p->scale[1] = p->scale[0] = s;
        p->scale[3] = 1.0f;
    }
    func_002675B0(p);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    {
        void *h = &D_01B007B8;
        D_006A3924 = h;
    }
    if (func_00267FA0(p, 0x30) != 0) {
        {
            void *h = &D_01B007B8;
            D_006A3924 = h;
        }
        func_00267530(p);
        {
            void *h = &D_01B007B8;
            D_006A3924 = h;
        }
        func_00267658(p, 0x1000, D_01B007B0->w10[2], 1);
    }
    if (D_01B00AA4 != 0) {
        p->s76 -= 0x88;
        if (p->s76 <= 0) {
            return 0;
        }
    }
    return 1;
}
