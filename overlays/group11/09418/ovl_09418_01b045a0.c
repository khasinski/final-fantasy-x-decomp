#include "common.h"

extern void *D_01B0004C;
extern u8 D_01B00060;
extern void *D_01B005C4;
extern u8 D_01B00B40;
extern u8 D_01B00B58[0x20];
extern u8 D_01B00B78;
extern u8 D_01B027A0;
extern u8 D_01B028C0;
extern u8 D_01B0F4D0;
extern void *D_01B0F4FC;
extern u8 D_01BC3480;
extern u8 D_01CC3480;

extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002944B0(void *, int, int, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_01B02E48(void);
extern void func_01B040C8(void *);
extern void func_01B04120(void *);
extern void func_01B04EE8(void *);
extern void func_01B0CFF8(void *);
extern void func_01B0D348(void *);
extern void func_01B0D400(void *);

typedef struct {
    u8 pad00[0x18];
    int f18;
    float f1C;
    float f20;
    int pad24;
    int f28;
} OvlB;

void func_01B04538(OvlB *a0) {
    struct {
        void *p00;
        void *p04;
        void *p08;
    } arg0;

    arg0.p00 = a0;
    arg0.p04 = (void *)func_01B04120;
    arg0.p08 = a0;
    func_01B0CFF8(&arg0);

    arg0.p00 = &D_01B00B40;
    arg0.p04 = a0;
    func_01B0D400(&arg0);

    a0->f18 = 0;
    a0->f1C = a0->f20 = 0.0f;
    a0->f28 = 0;
}

int func_01B045A0(void) {
    struct {
        void *p00;
        int p04;
        int pad08;
        int pad0C;
    } arg0;
    void *tmp10;

    func_01B02E48();
    D_01B0004C = &D_01CC3480;
    tmp10 = &D_01B00B40;
    func_01B0D348(&tmp10);

    arg0.p00 = D_01B00B58;
    arg0.p04 = 0;
    func_01B04EE8(&arg0);

    D_01B00B58[0x1B] = 1;

    arg0.p00 = &D_01B00B78;
    arg0.p04 = 0;
    func_01B04EE8(&arg0);

    func_002B4980(D_01B005C4);
    D_01B0F4FC = func_002B49A0(D_01B005C4, 8, 0);
    func_002678E0(D_01B0F4FC, &D_01B00060);
    func_00267A68(&D_01B0F4D0, D_01B0F4FC, &D_01BC3480, 0x100000);
    func_002D02E8(D_01B005C4, 0, 1000, 2);
    func_002944B0(D_01B005C4, 0, 1000, 2);
    func_01B040C8(&D_01B027A0);
    func_01B04538((OvlB *)&D_01B028C0);
    return 0;
}
