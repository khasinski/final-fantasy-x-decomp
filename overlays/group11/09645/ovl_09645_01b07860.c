#include "common.h"

typedef struct Ovl09645FlagObj {
    u8 pad00[0x1B];
    u8 b1B;
} Ovl09645FlagObj;

typedef struct Ovl09645VecObj {
    u8 pad00[0x20];
    union {
        float f[4];
        s32 w[4];
        u_long128 q;
    } v20;
} Ovl09645VecObj;

typedef struct Ovl09645Node {
    u8 pad00[0x14C];
    u8 b14C;
} Ovl09645Node;

typedef struct MsgA758 {
    void *a;
    void *b;
    s32 c;
    u8 d;
    u8 pad[3];
} MsgA758;

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern s32 D_01B00730;
extern s32 D_01B00734;
extern s32 D_01B00740;
extern u8 D_01B00750;
extern u8 D_01B00890[];
extern u8 D_01B008C0[];
extern u8 D_01B008F0[];
extern u8 D_01B00B00[];
extern u8 D_01B00B18[];
extern Ovl09645FlagObj D_01B00B30;
extern Ovl09645FlagObj D_01B00B50;
extern u8 D_01B00B70[];
extern u8 D_01B00B90[];
extern union {
    float f[4];
    u_long128 q;
} D_01B00BB0;
extern Ovl09645VecObj D_01B00DD0;
extern Ovl09645VecObj D_01B00E00;
extern u8 D_01B00E30[];
extern Ovl09645VecObj D_01B01CC0;
extern u8 D_01B01D50[];
extern u8 D_01B01F40[];
extern Ovl09645VecObj D_01B01F80;
extern Ovl09645VecObj D_01B01FB0;
extern Ovl09645VecObj D_01B01FE0;
extern Ovl09645Node D_01B02010;
extern s32 D_01B02400;
extern Ovl09645VecObj D_01B02410;
extern Ovl09645VecObj D_01B02440;
extern Ovl09645VecObj D_01B02470;
extern Ovl09645Node D_01B024A0;
extern u8 D_01B025F0[];
extern s32 D_01B02640;
extern Ovl09645VecObj D_01B02650;
extern Ovl09645VecObj D_01B02680;
extern Ovl09645VecObj D_01B026B0;
extern Ovl09645Node D_01B026E0;
extern u8 D_01B02830[];
extern u8 D_01B02C40[];
extern u8 D_01B032B0[];
extern u8 D_01B150A0[];
extern void *D_01B150CC;
extern u8 D_01C1C870[];
extern u8 D_01D1C870[];

void func_00105018(s32, s32);
void func_001134A8(s32);
void func_00118F70(s32, s32, s32, s32);
s32 func_001B4E58(s32);
void func_001B6B40(s32, void *);
void func_001B6E48(s32, float *);
void func_001B72F0(s32, void *);
void func_001D9F08(s32);
void func_002678E0(void *, void *);
void func_00267A68(void *, void *, void *, s32);
void func_00294468(void *, s32, s32);
void func_002944B0(s32, s32, s32, s32);
void func_002B4980(s32);
void *func_002B49A0(s32, s32, s32);
void func_002D02E8(s32, s32, s32, s32);
void func_002DD0B0(void *, void *);

void func_01B06240(void);
void func_01B07090(void *);
void func_01B077F0(void *);
void func_01B09928(void *);
void func_01B0A758(void *);
void func_01B0E1B0(void *);
void func_01B0E680(void *);
void func_01B0F198(void *);
void func_01B0FEF0(void *);
void func_01B10BA8(void *);
void func_01B14008(void *);

#define DEF_CALL1(name) static __inline__ void call_##name(void *a) { void *m[1]; m[0] = a; name(m); }
#define DEF_CALL2(name) static __inline__ void call_##name(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; name(m); }
#define DEF_CALL4(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d) { void *m[4]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; name(m); }
#define DEF_CALL6(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d, void *e, void *f) { void *m[6]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; m[4] = e; m[5] = f; name(m); }

DEF_CALL1(func_01B14008)
DEF_CALL2(func_01B09928)
DEF_CALL2(func_01B0E1B0)
DEF_CALL4(func_01B0E680)
DEF_CALL4(func_01B0F198)
DEF_CALL2(func_01B0FEF0)
static __inline__ void call_func_01B0E1B0_store(void *a, void *b, s32 *dst, s32 val)
{
    void *m[2];
    __asm__("" : "=r"(val), "=m"(m[1]) : "0"(val), "r"(a));
    m[1] = b;
    __asm__("" : "=r"(val), "=m"(m[0]) : "0"(val), "m"(m[1]) : "$4");
    m[0] = a;
    __asm__("" : "+r"(val) : "m"(m[0]));
    *dst = val;
    func_01B0E1B0(m);
}

static __inline__ void call_func_01B10BA8_a(void *a, void *b, void *c, void *d, void *e, void *f)
{
    void *m[6];
    register void *a0_tmp __asm__("$4") = a;
    m[0] = a0_tmp;
    m[4] = e;
    m[1] = b;
    m[2] = c;
    m[3] = d;
    m[5] = f;
    func_01B10BA8(m);
}

static __inline__ void call_func_01B10BA8_c(void *a, void *b, void *c, void *d, void *e, void *f)
{
    void *m[6];
    register void **a0_sp __asm__("$4") = m;
    __asm__("" : "+r"(a0_sp));
    m[3] = d;
    m[4] = e;
    m[0] = a;
    m[1] = b;
    m[2] = c;
    m[5] = f;
    func_01B10BA8(a0_sp);
}

static __inline__ void call_func_01B0A758(void *a, void *b, s32 c, u8 d)
{
    MsgA758 m;
    m.b = b;
    m.d = d;
    m.c = c;
    m.a = a;
    func_01B0A758(&m);
}

DEF_CALL6(func_01B10BA8)

s32 func_01B07860(void)
{
    float f38;

    func_01B06240();
    D_01B0004C = D_01D1C870;
    func_002B4980(D_01B00730);
    func_002B4980(D_01B00734);
    D_01B150CC = func_002B49A0(D_01B00730, 8, 0);
    func_002678E0(D_01B150CC, D_01B00050);
    func_00267A68(D_01B150A0, D_01B150CC, D_01C1C870, 0x100000);
    func_002D02E8(D_01B00730, 0, 0xB, 2);
    func_002944B0(D_01B00734, 0, 0x3E8, 2);
    func_00294468(func_002B49A0(D_01B00734, 6, 1), 0, 2);
    func_00294468(func_002B49A0(D_01B00734, 6, 2), 1, 2);

    {
        register void *v1 __asm__("$3") = D_01B00B00;
        __asm__("" : "+r"(v1));
        call_func_01B14008(v1);
    }
    call_func_01B14008(D_01B00B18);

    call_func_01B09928(&D_01B00B30, 0);
    D_01B00B30.b1B = 1;
    call_func_01B09928(&D_01B00B50, 0);
    D_01B00B50.b1B = 1;
    call_func_01B09928(D_01B00B70, 0);
    call_func_01B09928(D_01B00B90, 0);

    func_001B72F0(D_01B00740, &D_01B00BB0);
    D_01B00BB0.f[3] = 1.0f;

    call_func_01B0E1B0(&D_01B00DD0, &D_01B00B30);
    func_002DD0B0(D_01B00DD0.v20.f, &D_01B00BB0);
    D_01B00DD0.v20.f[1] -= 600.0f;

    call_func_01B0E1B0(&D_01B00E00, &D_01B00B30);
    func_002DD0B0(D_01B00E00.v20.f, &D_01B00BB0);

    call_func_01B10BA8_a(D_01B00E30, &D_01B00B30, D_01B008F0, &D_01B00E00, D_01B008C0, D_01B00890);

    D_01B02400 = func_001B4E58(D_01B00740);

    call_func_01B0E1B0(&D_01B02440, &D_01B00B30);
    D_01B02440.v20.q = D_01B00BB0.q;

    call_func_01B0E1B0(&D_01B02410, &D_01B00B30);
    func_001B6B40(D_01B00740, D_01B02410.v20.f);
    D_01B02410.v20.f[3] = 0.001f;

    call_func_01B0FEF0(&D_01B02470, &D_01B00B30);
    D_01B02470.v20.w[0] = 0;
    func_001B6E48(D_01B00740, &f38);
    D_01B02470.v20.w[2] = 0;
    D_01B02470.v20.w[1] = (s32)((4.712389f - f38) * 32768.0f / 3.1415927f);

    call_func_01B10BA8(&D_01B024A0, &D_01B00B30, D_01B008F0, &D_01B02440, &D_01B02470, &D_01B02410);
    D_01B024A0.b14C = 1;

    call_func_01B0E680(D_01B025F0, &D_01B00B30, (void *)D_01B02400, (void *)0x6B);

    call_func_01B0FEF0(&D_01B01CC0, &D_01B00B30);
    {
        register s32 y __asm__("$2") = D_01B02470.v20.w[1];
        register s32 z __asm__("$5") = D_01B02470.v20.w[2];
        register s32 x __asm__("$3");
        __asm__("" : "+r"(y), "+r"(z));
        x = D_01B02470.v20.w[0];
        __asm__("" : "+r"(y), "+r"(z) : "r"(x));
        D_01B01CC0.v20.w[1] = y;
        D_01B01CC0.v20.w[0] = x;
        D_01B01CC0.v20.w[2] = z;
    }
    call_func_01B10BA8_c(D_01B01D50, &D_01B00B30, D_01B008F0, &D_01B00E00, &D_01B01CC0, D_01B00890);

    call_func_01B0E1B0_store(&D_01B02680, &D_01B00B30, &D_01B02640, func_001B4E58(D_01B00750));
    D_01B02680.v20.f[3] = 1.0f;
    D_01B02680.v20.w[0] = 0;
    D_01B02680.v20.w[1] = 0;
    D_01B02680.v20.w[2] = 0;

    call_func_01B0E1B0(&D_01B02650, &D_01B00B30);
    func_001B6B40(D_01B00750, D_01B02650.v20.f);
    D_01B02650.v20.f[3] = 0.001f;

    call_func_01B0FEF0(&D_01B026B0, &D_01B00B30);
    D_01B026B0.v20.w[0] = 0;
    D_01B026B0.v20.w[1] = 0;
    D_01B026B0.v20.w[2] = 0;

    call_func_01B10BA8(&D_01B026E0, &D_01B00B30, D_01B01D50, &D_01B02680, &D_01B026B0, &D_01B02650);
    D_01B026E0.b14C = 1;

    func_00105018(0x300F, 1);
    func_001134A8(0x300F);

    call_func_01B0FEF0(&D_01B01FE0, &D_01B00B30);
    D_01B01FE0.v20.w[0] = 0;
    D_01B01FE0.v20.w[1] = 0;
    D_01B01FE0.v20.w[2] = 0;

    call_func_01B0E1B0(&D_01B01FB0, &D_01B00B30);
    func_002DD0B0(D_01B01FB0.v20.f, D_01B02410.v20.f);
    D_01B01FB0.v20.f[3] *= 4.0f;

    call_func_01B0E1B0(&D_01B01F80, &D_01B00B30);
    D_01B01F80.v20.w[0] = 0;
    D_01B01F80.v20.w[2] = 0;
    D_01B01F80.v20.f[1] = D_01B02410.v20.f[1] * -350.0f;
    D_01B01F80.v20.w[3] = 0;

    call_func_01B0F198(D_01B01F40, &D_01B00B30, &D_01B01F80, &D_01B00DD0);

    call_func_01B10BA8(&D_01B02010, &D_01B00B30, D_01B008F0, D_01B01F40, &D_01B01FE0, &D_01B01FB0);
    D_01B02010.b14C = 1;

    func_001D9F08(1);
    func_00118F70(1, 0, 0, 0);
    call_func_01B0A758(D_01B02830, &D_01B00B30, D_01B00750, 0);
    func_01B077F0(D_01B032B0);
    func_01B07090(D_01B02C40);
    return 0;
}
