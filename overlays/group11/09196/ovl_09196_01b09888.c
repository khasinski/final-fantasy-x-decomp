#include "common.h"

typedef struct Ovl09196FlagObj {
    u8 pad00[0x1B];
    u8 b1B;
} Ovl09196FlagObj;

typedef struct Ovl09196VecObj {
    u8 pad00[0x20];
    union {
        float f[4];
        s32 w[4];
        u_long128 q;
    } v20;
} Ovl09196VecObj;

typedef struct Ovl09196Node {
    u8 pad00[0x14C];
    u8 b14C;
} Ovl09196Node;

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
extern Ovl09196FlagObj D_01B00B30;
extern Ovl09196FlagObj D_01B00B50;
extern u8 D_01B00B70[];
extern u8 D_01B00B90[];
extern union {
    float f[4];
    u_long128 q;
} D_01B00BC0;
extern Ovl09196VecObj D_01B00DE0;
extern Ovl09196VecObj D_01B00E10;
extern u8 D_01B00E40[];
extern Ovl09196VecObj D_01B01CD0;
extern u8 D_01B01D60[];
extern u8 D_01B01F50[];
extern Ovl09196VecObj D_01B01F90;
extern Ovl09196VecObj D_01B01FC0;
extern Ovl09196VecObj D_01B01FF0;
extern Ovl09196Node D_01B02020;
extern s32 D_01B02410;
extern Ovl09196VecObj D_01B02420;
extern Ovl09196VecObj D_01B02450;
extern Ovl09196VecObj D_01B02480;
extern Ovl09196Node D_01B024B0;
extern u8 D_01B02600[];
extern s32 D_01B02650;
extern Ovl09196VecObj D_01B02660;
extern Ovl09196VecObj D_01B02690;
extern Ovl09196VecObj D_01B026C0;
extern Ovl09196Node D_01B026F0;
extern u8 D_01B02C50[];
extern u8 D_01B032C0[];
extern u8 D_01B196F0[];
extern void *D_01B1971C;
extern u8 D_01C4B540[];
extern u8 D_01D4B540[];

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

void func_01B06360(void);
void func_01B079D0(void *);
void func_01B09818(void *);
void func_01B0C9E8(void *);
void func_01B11270(void *);
void func_01B11740(void *);
void func_01B12258(void *);
void func_01B13678(void *);
void func_01B14AC8(void *);
void func_01B18650(void *);

#define DEF_CALL1(name) static __inline__ void call_##name(void *a) { void *m[1]; m[0] = a; name(m); }
#define DEF_CALL2(name) static __inline__ void call_##name(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; name(m); }
#define DEF_CALL4(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d) { void *m[4]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; name(m); }
#define DEF_CALL6(name) static __inline__ void call_##name(void *a, void *b, void *c, void *d, void *e, void *f) { void *m[6]; m[0] = a; m[1] = b; m[2] = c; m[3] = d; m[4] = e; m[5] = f; name(m); }

DEF_CALL1(func_01B18650)
DEF_CALL2(func_01B0C9E8)
DEF_CALL2(func_01B11270)
DEF_CALL4(func_01B11740)
DEF_CALL4(func_01B12258)
DEF_CALL2(func_01B13678)
static __inline__ void call_func_01B11270_store(void *a, void *b, s32 *dst, s32 val)
{
    void *m[2];
    __asm__("" : "=r"(val), "=m"(m[1]) : "0"(val), "r"(a));
    m[1] = b;
    __asm__("" : "=r"(val), "=m"(m[0]) : "0"(val), "m"(m[1]) : "$4");
    m[0] = a;
    __asm__("" : "+r"(val) : "m"(m[0]));
    *dst = val;
    func_01B11270(m);
}

static __inline__ void call_func_01B14AC8_a(void *a, void *b, void *c, void *d, void *e, void *f)
{
    void *m[6];
    register void *a0_tmp __asm__("$4") = a;
    m[0] = a0_tmp;
    m[4] = e;
    m[1] = b;
    m[2] = c;
    m[3] = d;
    m[5] = f;
    func_01B14AC8(m);
}

static __inline__ void call_func_01B14AC8_c(void *a, void *b, void *c, void *d, void *e, void *f)
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
    func_01B14AC8(a0_sp);
}

DEF_CALL6(func_01B14AC8)

s32 func_01B09888(void)
{
    float f38;

    func_01B06360();
    D_01B0004C = D_01D4B540;
    func_002B4980(D_01B00730);
    func_002B4980(D_01B00734);
    D_01B1971C = func_002B49A0(D_01B00730, 8, 0);
    func_002678E0(D_01B1971C, D_01B00050);
    func_00267A68(D_01B196F0, D_01B1971C, D_01C4B540, 0x100000);
    func_002D02E8(D_01B00730, 0, 0xB, 2);
    func_002944B0(D_01B00734, 0, 0x3E8, 2);
    func_00294468(func_002B49A0(D_01B00734, 6, 6), 0, 2);
    func_00294468(func_002B49A0(D_01B00734, 6, 7), 1, 2);

    {
        register void *v1 __asm__("$3") = D_01B00B00;
        __asm__("" : "+r"(v1));
        call_func_01B18650(v1);
    }
    call_func_01B18650(D_01B00B18);

    call_func_01B0C9E8(&D_01B00B30, 0);
    D_01B00B30.b1B = 1;
    call_func_01B0C9E8(&D_01B00B50, 0);
    D_01B00B50.b1B = 1;
    call_func_01B0C9E8(D_01B00B70, 0);
    call_func_01B0C9E8(D_01B00B90, 0);

    func_001B72F0(D_01B00740, &D_01B00BC0);
    D_01B00BC0.f[3] = 1.0f;

    call_func_01B11270(&D_01B00DE0, &D_01B00B30);
    func_002DD0B0(D_01B00DE0.v20.f, &D_01B00BC0);
    D_01B00DE0.v20.f[1] -= 600.0f;

    call_func_01B11270(&D_01B00E10, &D_01B00B30);
    func_002DD0B0(D_01B00E10.v20.f, &D_01B00BC0);

    call_func_01B14AC8_a(D_01B00E40, &D_01B00B30, D_01B008F0, &D_01B00E10, D_01B008C0, D_01B00890);

    D_01B02410 = func_001B4E58(D_01B00740);

    call_func_01B11270(&D_01B02450, &D_01B00B30);
    D_01B02450.v20.q = D_01B00BC0.q;

    call_func_01B11270(&D_01B02420, &D_01B00B30);
    func_001B6B40(D_01B00740, D_01B02420.v20.f);
    D_01B02420.v20.f[3] = 0.001f;

    call_func_01B13678(&D_01B02480, &D_01B00B30);
    D_01B02480.v20.w[0] = 0;
    func_001B6E48(D_01B00740, &f38);
    D_01B02480.v20.w[2] = 0;
    D_01B02480.v20.w[1] = (s32)((4.712389f - f38) * 32768.0f / 3.1415927f);

    call_func_01B14AC8(&D_01B024B0, &D_01B00B30, D_01B008F0, &D_01B02450, &D_01B02480, &D_01B02420);
    D_01B024B0.b14C = 1;

    call_func_01B11740(D_01B02600, &D_01B00B30, (void *)D_01B02410, (void *)0x6B);

    call_func_01B13678(&D_01B01CD0, &D_01B00B30);
    {
        register s32 y __asm__("$2") = D_01B02480.v20.w[1];
        register s32 z __asm__("$5") = D_01B02480.v20.w[2];
        register s32 x __asm__("$3");
        __asm__("" : "+r"(y), "+r"(z));
        x = D_01B02480.v20.w[0];
        __asm__("" : "+r"(y), "+r"(z) : "r"(x));
        D_01B01CD0.v20.w[1] = y;
        D_01B01CD0.v20.w[0] = x;
        D_01B01CD0.v20.w[2] = z;
    }
    call_func_01B14AC8_c(D_01B01D60, &D_01B00B30, D_01B008F0, &D_01B00E10, &D_01B01CD0, D_01B00890);

    call_func_01B11270_store(&D_01B02690, &D_01B00B30, &D_01B02650, func_001B4E58(D_01B00750));
    D_01B02690.v20.f[3] = 1.0f;
    D_01B02690.v20.w[0] = 0;
    D_01B02690.v20.w[1] = 0;
    D_01B02690.v20.w[2] = 0;

    call_func_01B11270(&D_01B02660, &D_01B00B30);
    func_001B6B40(D_01B00750, D_01B02660.v20.f);
    D_01B02660.v20.f[3] = 0.001f;

    call_func_01B13678(&D_01B026C0, &D_01B00B30);
    D_01B026C0.v20.w[0] = 0;
    D_01B026C0.v20.w[1] = 0;
    D_01B026C0.v20.w[2] = 0;

    call_func_01B14AC8(&D_01B026F0, &D_01B00B30, D_01B01D60, &D_01B02690, &D_01B026C0, &D_01B02660);
    D_01B026F0.b14C = 1;

    func_00105018(0x300F, 1);
    func_001134A8(0x300F);

    call_func_01B13678(&D_01B01FF0, &D_01B00B30);
    D_01B01FF0.v20.w[0] = 0;
    D_01B01FF0.v20.w[1] = 0;
    D_01B01FF0.v20.w[2] = 0;

    call_func_01B11270(&D_01B01FC0, &D_01B00B30);
    func_002DD0B0(D_01B01FC0.v20.f, D_01B02420.v20.f);
    D_01B01FC0.v20.f[3] *= 4.0f;

    call_func_01B11270(&D_01B01F90, &D_01B00B30);
    D_01B01F90.v20.w[0] = 0;
    D_01B01F90.v20.w[2] = 0;
    D_01B01F90.v20.f[1] = D_01B02420.v20.f[1] * -350.0f;
    D_01B01F90.v20.w[3] = 0;

    call_func_01B12258(D_01B01F50, &D_01B00B30, &D_01B01F90, &D_01B00DE0);

    call_func_01B14AC8(&D_01B02020, &D_01B00B30, D_01B008F0, D_01B01F50, &D_01B01FF0, &D_01B01FC0);
    D_01B02020.b14C = 1;

    func_00105018(0x3010, 1);
    func_001134A8(0x3010);
    func_001D9F08(1);
    func_00118F70(1, 0, 0, 0);
    func_01B09818(D_01B032C0);
    func_01B079D0(D_01B02C50);
    return 0;
}
