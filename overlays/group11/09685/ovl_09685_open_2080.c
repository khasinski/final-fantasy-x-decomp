/* EE Battle-Effect Overlay: group 0x11, file 09685
 * .text: 0x01B02080..0x01B02250 (1 function).
 */
#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x14];
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct TtHeap {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

extern u8 D_01B00040[];
extern u8 D_01B00338[];
extern u8 D_01B00368[];
extern u8 *D_01B00458;
extern u8 *D_01B0045C;
extern u8 *D_01B00460;
extern u8 *D_01B00468;
extern void *D_01B0046C;
extern void *D_01B00470;
extern TtCfg *D_01B00474;
extern TtHeap D_01B00478;
extern u8 *D_01B00DF0;
extern void *D_01B00E74;
extern u8 D_01B00F98[];
extern u8 D_01B010A8[];
extern char D_01B044A0[];
extern char D_01B044B0[];
extern char D_01B044C0[];
extern char D_01B044D8[];
extern char D_01B044F0[];
extern u8 D_01B05770[];
extern u8 D_01B4F690[];

extern void func_01B01628(void);
extern void func_01B02910(const char *, ...);
extern void func_01B03248(void *, void *, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B2C50(int);
extern void *func_002B2E30(void *, int, int, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B02080(void *arg)
{
    TtCfg *c;

    func_01B02910(D_01B044A0);
    D_01B00458 = D_01B4F690;
    D_01B0045C = D_01B00458 + 0x80000;
    D_01B00460 = D_01B0045C + 0x80000;
    D_01B00468 = D_01B00460 + 0x80000;
    func_01B02910(D_01B044B0, D_01B00458);
    func_01B02910(D_01B044C0, D_01B0045C);
    func_01B02910(D_01B044D8, D_01B00460);
    func_01B02910(D_01B044F0, D_01B00468);
    D_01B00DF0 = D_01B00468;
    D_01B0046C = arg;
    D_01B00470 = D_01B05770;
    func_002B4980(D_01B00470);
    func_002D02E8(D_01B00470, 0, 0x3E8, 0x2000);
    D_01B00474 = (TtCfg *)func_002B49A0(D_01B00470, 8, 0);
    func_002678E0(D_01B00474, D_01B00040);
    func_00267A68(&D_01B00478, D_01B00474, D_01B00458, 0x80000);
    c = D_01B00474;
    D_01B00478.w20 = c->w14;
    D_01B00478.w24 = c->w18;
    D_01B00478.w28 = c->w1c;
    func_01B03248(D_01B00F98, D_01B00338, 2);
    func_01B03248(D_01B010A8, D_01B00368, 1);
    D_01B00E74 = func_002B2E30((void *)func_01B01628, 0, 0, 0);
    func_002B2C50(1);
    return 1;
}
