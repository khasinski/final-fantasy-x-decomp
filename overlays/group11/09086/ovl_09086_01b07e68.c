#include "common.h"

typedef struct Ovl09086FlagObj {
    u8 pad00[0x1B];
    u8 b1B;
} Ovl09086FlagObj;

typedef struct Ovl09086VecObj {
    u8 pad00[0x20];
    union {
        float f[4];
        s32 w[4];
        u_long128 q;
    } v20;
} Ovl09086VecObj;

typedef struct Ovl09086Node {
    u8 pad00[0x14C];
    u8 b14C;
} Ovl09086Node;

typedef struct Ovl09086Actor {
    u8 pad00[0x58];
    void *p58;
} Ovl09086Actor;

typedef struct MsgBB48 {
    void *a;
    void *b;
    s32 c;
    u8 d;
    u8 pad[3];
} MsgBB48;

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern s32 D_01B00730;
extern s32 D_01B00734;
extern u8 D_01B00890[];
extern u8 D_01B008C0[];
extern u8 D_01B008F0[];
extern u8 D_01B00B00[];
extern Ovl09086FlagObj D_01B00B20;
extern u8 D_01B00B40[];
extern union {
    float f[4];
    u_long128 q;
} D_01B00B60;
extern Ovl09086VecObj D_01B00D80;
extern Ovl09086VecObj D_01B00DB0;
extern u8 D_01B00DE0[];
extern Ovl09086VecObj D_01B01C70;
extern u8 D_01B01D00[];
extern u8 D_01B01EF0[];
extern Ovl09086VecObj D_01B01F30;
extern Ovl09086VecObj D_01B01F60;
extern Ovl09086VecObj D_01B01F90;
extern Ovl09086Node D_01B01FC0;
extern Ovl09086VecObj D_01B02110;
extern Ovl09086VecObj D_01B02140;
extern Ovl09086VecObj D_01B02170;
extern Ovl09086Node D_01B021A0;
extern u8 D_01B022F0[];
extern Ovl09086Actor D_01B02440;
extern u8 D_01B027A0[];
extern u8 D_01B05330[];
extern u8 D_01B17380[];
extern void *D_01B173AC;
extern u8 D_01C1E680[];
extern u8 D_01D1E680[];

void func_002678E0(void *, void *);
void func_00267A68(void *, void *, void *, s32);
void func_002944B0(s32, s32, s32, s32);
void func_002B4980(s32);
void *func_002B49A0(s32, s32, s32);
void func_002D02E8(s32, s32, s32, s32);
void func_002DD0B0(void *, void *);

void func_01B05E08(void);
void func_01B06A10(void *);
void func_01B07DF8(void *);
void func_01B0AD18(void *);
void func_01B0B250(void *);
void func_01B0B330(void *);
void func_01B0B790(void *);
void func_01B0BAD8(void *);
void func_01B0BB48(void *);
void func_01B0F5A0(void *);
void func_01B0FA70(void *);
void func_01B10588(void *);
void func_01B11310(void *);
void func_01B12760(void *);
void func_01B162E8(void *);

#define DEF_CALL1(name) static __inline__ void call_##name(void *a) { void *m[1]; m[0] = a; name(m); }
#define DEF_CALL2(name) static __inline__ void call_##name(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; name(m); }
#define DEF_CALL4(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d) { void *m[4]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; name(m); }
#define DEF_CALL6(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d, void *e, void *f) { void *m[6]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; m[4] = e; m[5] = f; name(m); }

DEF_CALL1(func_01B162E8)
DEF_CALL2(func_01B0AD18)
DEF_CALL2(func_01B0B250)
DEF_CALL2(func_01B0B330)
DEF_CALL2(func_01B0B790)
DEF_CALL2(func_01B0BAD8)
DEF_CALL2(func_01B0F5A0)
DEF_CALL4(func_01B0FA70)
DEF_CALL4(func_01B10588)
DEF_CALL2(func_01B11310)
DEF_CALL6(func_01B12760)
static __inline__ void call_func_01B12760_a(void *a, void *b, void *c, void *d, void *e, void *f, float *pf)
{
    void *m[6];
    register void *r_a __asm__("$3") = a;
    m[0] = r_a;
    *pf = 1.0f;
    m[1] = b;
    m[2] = c;
    m[3] = d;
    m[4] = e;
    m[5] = f;
    func_01B12760(m);
}

static __inline__ void call_func_01B0BB48(void *a, void *b, s32 c, u8 d)
{
    MsgBB48 m;
    m.c = c;
    m.a = a;
    m.b = b;
    m.d = d;
    func_01B0BB48(&m);
}

s32 ovl_09086_01b07e68(void)
{
    func_01B05E08();
    D_01B0004C = D_01D1E680;
    func_002B4980(D_01B00730);
    func_002B4980(D_01B00734);
    D_01B173AC = func_002B49A0(D_01B00730, 8, 0);
    func_002678E0(D_01B173AC, D_01B00050);
    func_00267A68(D_01B17380, D_01B173AC, D_01C1E680, 0x100000);
    func_002D02E8(D_01B00730, 0, 0xB, 2);
    func_002944B0(D_01B00734, 0, 0x3E8, 2);

    {
        register void *v1 __asm__("$3") = D_01B00B00;
        __asm__("" : "+r"(v1));
        call_func_01B162E8(v1);
    }

    call_func_01B0AD18(&D_01B00B20, 0);
    D_01B00B20.b1B = 1;
    call_func_01B0AD18(D_01B00B40, 0);

    call_func_01B0BB48(&D_01B02440, &D_01B00B20, 0x14, 1);
    call_func_01B0B790(&D_01B02440, &D_01B00B60);
    D_01B00B60.f[3] = 1.0f;

    call_func_01B0F5A0(&D_01B00D80, &D_01B00B20);
    func_002DD0B0(D_01B00D80.v20.f, &D_01B00B60);
    D_01B00D80.v20.f[1] -= 600.0f;

    call_func_01B0F5A0(&D_01B00DB0, &D_01B00B20);
    call_func_01B0B790(&D_01B02440, D_01B00DB0.v20.f);
    call_func_01B12760_a(D_01B00DE0, &D_01B00B20, D_01B008F0, &D_01B00DB0, D_01B008C0, D_01B00890, &D_01B00DB0.v20.f[3]);

    call_func_01B0B330(&D_01B02440, 0);

    call_func_01B0F5A0(&D_01B02140, &D_01B00B20);
    D_01B02140.v20.q = D_01B00B60.q;

    call_func_01B0F5A0(&D_01B02110, &D_01B00B20);
    call_func_01B0B250(&D_01B02440, D_01B02110.v20.f);

    call_func_01B11310(&D_01B02170, &D_01B00B20);
    call_func_01B0BAD8(&D_01B02440, D_01B02170.v20.f);

    call_func_01B12760(&D_01B021A0, &D_01B00B20, D_01B008F0, &D_01B02140, &D_01B02170, &D_01B02110);
    D_01B021A0.b14C = 1;

    call_func_01B0FA70(D_01B022F0, &D_01B00B20, D_01B02440.p58, (void *)0x6B);

    call_func_01B11310(&D_01B01C70, &D_01B00B20);
    D_01B01C70.v20.w[0] = D_01B02170.v20.w[0];
    D_01B01C70.v20.w[1] = D_01B02170.v20.w[1];
    D_01B01C70.v20.w[2] = D_01B02170.v20.w[2];

    call_func_01B12760(D_01B01D00, &D_01B00B20, D_01B008F0, &D_01B00DB0, &D_01B01C70, D_01B00890);

    call_func_01B11310(&D_01B01F90, &D_01B00B20);
    D_01B01F90.v20.w[0] = 0;
    D_01B01F90.v20.w[1] = 0;
    D_01B01F90.v20.w[2] = 0;

    call_func_01B0F5A0(&D_01B01F60, &D_01B00B20);
    func_002DD0B0(D_01B01F60.v20.f, D_01B02110.v20.f);

    call_func_01B0F5A0(&D_01B01F30, &D_01B00B20);
    D_01B01F30.v20.w[0] = 0;
    D_01B01F30.v20.w[2] = 0;
    D_01B01F30.v20.f[1] = D_01B02110.v20.f[1] * -350.0f;
    D_01B01F30.v20.w[3] = 0;

    call_func_01B10588(D_01B01EF0, &D_01B00B20, &D_01B01F30, &D_01B00D80);

    call_func_01B12760(&D_01B01FC0, &D_01B00B20, D_01B008F0, D_01B01EF0, &D_01B01F90, &D_01B01F60);
    D_01B01FC0.b14C = 1;

    func_01B06A10(D_01B05330);
    func_01B07DF8(D_01B027A0);
    return 0;
}
