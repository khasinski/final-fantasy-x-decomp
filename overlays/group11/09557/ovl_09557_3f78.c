#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int w18;
    u8 pad1C[0x34];
    int w50;
} Obj3F78;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
} Msg3;

typedef struct {
    void *p0;
    void *p4;
} Msg2;

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;
} NodeA28;

extern int D_01B0004C;
extern u8 D_01B00050[];
extern int D_01B00640;
extern u8 D_01B00A10[];
extern NodeA28 D_01B00A28;
extern u8 D_01B00A48[];
extern u8 D_01B00A68[];
extern u8 D_01B00B70[];
extern u8 D_01B10530[];
extern int D_01B1055C;
extern u8 D_01BADF80[];
extern u8 D_01CADF80[];

extern void func_002678E0(int, void *);
extern void func_00267A68(void *, int, void *, int);
extern void func_002944B0(int, int, int, int);
extern void func_002B4980(int);
extern int func_002B49A0(int, int, int);
extern void func_002D02E8(int, int, int, int);

extern void func_01B02860(void);
extern void func_01B03760(void);
extern void func_01B043A8(void *);
extern void func_01B04410(void *);
extern void func_01B04630(void *);
extern void func_01B04E18(void *);
extern void func_01B0F148(void *);
extern void func_01B0F498(void *);
extern void func_01B0F550(void *);

void func_01B03F78(Obj3F78 *o)
{
    Msg3 m;
    m.p0 = o;
    m.p4 = (void *)func_01B03760;
    m.p8 = o;
    func_01B0F148(&m);
    m.p0 = D_01B00A10;
    m.p4 = o;
    func_01B0F550(&m);
    o->w50 = 0;
    o->w18 = 0;
}

int func_01B03FD8(void)
{
    Msg2 m;
    void *p;

    func_01B02860();
    D_01B0004C = (int)D_01CADF80;
    p = D_01B00A10;
    func_01B0F498(&p);
    m.p0 = &D_01B00A28;
    m.p4 = 0;
    func_01B04E18(&m);
    D_01B00A28.b1B = 1;
    m.p0 = D_01B00A48;
    m.p4 = 0;
    func_01B04E18(&m);
    m.p0 = D_01B00A68;
    m.p4 = &D_01B00A28;
    func_01B043A8(&m);
    func_002B4980(D_01B00640);
    D_01B1055C = func_002B49A0(D_01B00640, 8, 0);
    func_002678E0(D_01B1055C, D_01B00050);
    func_00267A68(D_01B10530, D_01B1055C, D_01BADF80, 0x100000);
    func_002D02E8(D_01B00640, 0, 1000, 2);
    func_002944B0(D_01B00640, 0, 1000, 2);
    func_01B03F78((Obj3F78 *)D_01B00B70);
    return 0;
}

int func_01B04108(void)
{
    void *p0;
    void *p1;

    p0 = D_01B00A68;
    func_01B04630(&p0);
    p1 = D_01B00A68;
    func_01B04410(&p1);
    return 0;
}
