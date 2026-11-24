#include "common.h"

typedef struct Ovl09245Actor {
    u8 pad00[0x54];
    s32 w54;
} Ovl09245Actor;

typedef struct Ovl09245Entry {
    u8 data[0xA0];
} Ovl09245Entry;

typedef struct Ovl09245Table {
    u8 pad00[0x20];
    Ovl09245Entry entries[8];
    s32 count;
} Ovl09245Table;

typedef struct Ovl09245Task {
    u8 pad00[0x18];
    s32 w18;
    Ovl09245Actor *p1C;
    s32 w20;
    Ovl09245Table *p24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
} Ovl09245Task;

typedef struct Ovl09245Sub1000 {
    u8 pad00[0x30];
    u8 f30[0x20];
    u8 f50[0x10];
    u8 f60[0x20];
    s32 w80;
    s32 w84;
    s32 w88;
} Ovl09245Sub1000;

typedef struct Ovl09245Sub1260 {
    u8 pad00[0x30];
    u8 f30[0x20];
    float f50;
    float f54;
    float f58;
    float f5C;
    u8 f60[0x20];
    u8 f80[0x10];
} Ovl09245Sub1260;

typedef struct Ovl09245Node {
    u8 pad00[0x14C];
    u8 b14C;
} Ovl09245Node;

typedef struct Ovl09245A30 {
    u8 f00[0x18];
    u8 f18[0x20];
} Ovl09245A30;

extern u8 D_01B00790[];
extern u8 D_01B007C0[];
extern u8 D_01B00820[];
extern Ovl09245A30 D_01B00A30;
extern u8 D_01B00A68[];
extern Ovl09245Sub1000 D_01B01000;
extern Ovl09245Sub1260 D_01B01260;
extern Ovl09245Node D_01B015C0;
extern u8 D_01B01710[];
extern u8 D_01B02050[];

float func_001B63B8(s32);
float func_001B73C8(s32);
void func_01B02E70(void *);
void func_01B042C8(void *);
void func_01B05650(void *);
void func_01B05768(void *);
void func_01B05848(void *);
void func_01B05B20(void *);
void func_01B05B90(void *);
void func_01B05ED8(void *);
void func_01B08CE8(void *);
void func_01B091B8(void *);
void func_01B09E70(void *);
void func_01B0CF80(void *);
void func_01B0D388(void *);

typedef struct {
    void *a;
    u8 b;
    u8 pad[3];
} Msg5768;

#define DEF_CALL2(name) static __inline__ void call_##name(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; name(m); }
#define DEF_CALL3(name) static __inline__ void call_##name(void *a, void *b, void *c) { void *m[3]; m[0] = a; m[1] = b; m[2] = c; name(m); }
#define DEF_CALL4(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d) { void *m[4]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; name(m); }
#define DEF_CALL6(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d, void *e, void *f) { void *m[6]; m[3] = d; m[5] = f; m[0] = a; m[1] = b; m[4] = e; m[2] = c; name(m); }

DEF_CALL3(func_01B0CF80)
DEF_CALL2(func_01B0D388)
DEF_CALL2(func_01B05B20)
DEF_CALL4(func_01B042C8)
DEF_CALL2(func_01B08CE8)
DEF_CALL2(func_01B05B90)
DEF_CALL2(func_01B091B8)
DEF_CALL2(func_01B05ED8)
DEF_CALL2(func_01B05650)
DEF_CALL6(func_01B09E70)
DEF_CALL2(func_01B05848)

static __inline__ void call_func_01B05768(void *a, u8 b)
{
    Msg5768 m;
    m.b = b;
    m.a = a;
    func_01B05768(&m);
}

void func_01B03308(Ovl09245Task *a0, Ovl09245Actor *a1, Ovl09245Table *a2, s32 a3)
{
    s32 i;

    call_func_01B0CF80(a0, func_01B02E70, a0);
    call_func_01B0D388(D_01B00A30.f00, a0);

    a0->w20 = a3;
    a0->p1C = a1;
    a0->p24 = a2;

    call_func_01B05B20(a1, (void *)0x10);

    for (i = 0; i < a2->count; i++) {
        call_func_01B05768(&a2->entries[i], 0xFF);
    }

    call_func_01B042C8(D_01B02050, D_01B00A68, a2, (void *)0xFF);
    call_func_01B08CE8(D_01B01260.f30, D_01B00A30.f18);
    call_func_01B05B90(a1, &D_01B01260.f50);
    D_01B01260.f5C = 1.0f;

    call_func_01B091B8(D_01B01000.f30, D_01B00A30.f18);
    call_func_01B05ED8(a1, D_01B01000.f50);
    call_func_01B08CE8(D_01B01260.f60, D_01B00A30.f18);
    call_func_01B05650(a1, D_01B01260.f80);
    call_func_01B09E70(D_01B01710, D_01B00A30.f18, D_01B00820, D_01B01260.f30, D_01B01000.f30, D_01B01260.f60);

    call_func_01B091B8(D_01B01000.f60, D_01B00A30.f18);
    D_01B01000.w80 = 0;
    D_01B01000.w84 = 0;
    D_01B01000.w88 = 0;

    call_func_01B09E70(&D_01B015C0, D_01B00A30.f18, D_01B01710, D_01B00790, D_01B01000.f60, D_01B007C0);
    D_01B01710[-4] = 4;

    call_func_01B05848(a1, &D_01B015C0);

    a0->f2C = a0->f38 = D_01B01260.f54;
    a0->f2C -= func_001B73C8(a1->w54);
    a0->f2C += -func_001B63B8(a1->w54) * 0.2f;
    a0->f34 = 1.0f;
    a0->f30 = 0.05f;
    a0->f28 = 25.0f;
    a0->w18 = 0;
    D_01B01260.f54 -= 25.0f;
}
