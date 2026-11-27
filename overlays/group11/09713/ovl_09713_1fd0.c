#include "common.h"

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Tri3;

typedef struct {
    u8 pad00[0x14];
    Tri3 s14;
} Obj8A0;

typedef struct {
    u8 pad00[0x20];
    Tri3 s20;
} Obj8A8;

extern u8 D_01B00040[];
extern u8 D_01B007A0[];
extern u8 *D_01B00884;
extern u8 *D_01B00888;
extern u8 *D_01B0088C;
extern u8 *D_01B00894;
extern void *D_01B00898;
extern void *D_01B0089C;
extern Obj8A0 *D_01B008A0;
extern Obj8A8 D_01B008A8;
extern u8 *D_01B00AA0;
extern u8 D_01B00BB0[];
extern char D_01B04AD8[];
extern char D_01B04AE8[];
extern char D_01B04AF8[];
extern char D_01B04B10[];
extern char D_01B04B28[];
extern char D_01B04B40[];
extern u8 D_01B05E30[];
extern u8 D_01B75560[];

extern void func_01B027D8(char *, ...);
extern void func_002B4980(void *);
extern void func_002D02E8(void *, int, int, int);
extern Obj8A0 *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_01B03110(void *, void *, int);

int func_01B01FD0(void *a0)
{
    func_01B027D8(D_01B04AD8);
    D_01B00884 = D_01B75560;
    D_01B00888 = D_01B00884 + 0x100000;
    D_01B0088C = D_01B00888 + 0x100000;
    D_01B00894 = D_01B0088C + 0x100000;
    D_01B00AA0 = D_01B00894;
    func_01B027D8(D_01B04AE8, D_01B00884);
    func_01B027D8(D_01B04AF8, D_01B00888);
    func_01B027D8(D_01B04B10, D_01B0088C);
    func_01B027D8(D_01B04B28, D_01B00894);
    {
        register u8 *aa0 __asm__("$3") = D_01B00AA0;
        func_01B027D8(D_01B04B40, aa0 + 0x17700);
    }
    D_01B00898 = a0;
    {
        register u8 *p __asm__("$3") = D_01B05E30;
        D_01B0089C = p;
        func_002B4980(p);
    }
    func_002D02E8(D_01B0089C, 0, 1000, 0x2000);
    D_01B008A0 = func_002B49A0(D_01B0089C, 8, 0);
    func_002678E0(D_01B008A0, D_01B00040);
    func_00267A68(&D_01B008A8, D_01B008A0, D_01B00884, 0x100000);
    {
        Obj8A0 *p = D_01B008A0;
        register u32 c __asm__("$8") = p->s14.c;
        register u32 a __asm__("$7") = p->s14.a;
        register u32 b __asm__("$3");
        __asm__("" : "+r"(c), "+r"(a) : : "memory");
        b = p->s14.b;
        D_01B008A8.s20.c = c;
        D_01B008A8.s20.a = a;
        __asm__("" : "+r"(b) : : "memory");
        D_01B008A8.s20.b = b;
    }
    func_01B03110(D_01B00BB0, D_01B007A0, 5);
    return 1;
}
