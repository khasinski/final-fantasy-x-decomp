/* EE Battle-Effect Overlay: group 0x11, file 09089
 * .text: 0x01B01858..0x01B019F4 (1 function).
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
extern u8 D_01B00550[];
extern u8 D_01B00568[];
extern u8 D_01B00580[];
extern u8 D_01B00598[];
extern u8 *D_01B005E4;
extern u8 *D_01B005E8;
extern void *D_01B005EC;
extern void *D_01B005F0;
extern TtCfg *D_01B005F4;
extern TtHeap D_01B005F8;
extern void *D_01B008B4;
extern void *D_01B008B8;
extern u8 D_01B00908[];
extern u8 D_01B00A18[];
extern u8 D_01B00B28[];
extern u8 D_01B00C38[];
extern char D_01B02C18[];
extern char D_01B02C28[];
extern u8 D_01B02D30[];
extern u8 D_01B57E90[];

extern void func_01B020A0(const char *);
extern void func_01B020D0(const char *);
extern void func_01B02158(void *, void *, int);
extern void *func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B01858(void *arg)
{
    TtCfg *c;

    func_01B020A0(D_01B02C18);
    D_01B005E4 = D_01B57E90;
    D_01B005E8 = D_01B005E4 + 0x80000;
    D_01B005F0 = D_01B02D30;
    D_01B005EC = arg;
    func_002B4980(D_01B005F0);
    func_002D02E8(D_01B005F0, 0, 0x3E8, 0x2000);
    D_01B005F4 = (TtCfg *)func_002B49A0(D_01B005F0, 8, 0);
    func_002678E0(D_01B005F4, D_01B00040);
    func_00267A68(&D_01B005F8, D_01B005F4, D_01B005E4, 0x80000);
    c = D_01B005F4;
    D_01B005F8.w20 = c->w14;
    D_01B005F8.w24 = c->w18;
    D_01B005F8.w28 = c->w1c;
    func_01B02158(D_01B00908, D_01B00550, 1);
    func_01B02158(D_01B00A18, D_01B00568, 1);
    func_01B02158(D_01B00B28, D_01B00580, 1);
    func_01B02158(D_01B00C38, D_01B00598, 2);
    D_01B008B4 = func_0013B150(1);
    if (D_01B008B4 == 0) {
        func_01B020D0(D_01B02C28);
    }
    D_01B008B8 = func_0013B150(0);
    if (D_01B008B8 == 0) {
        func_01B020D0(D_01B02C28);
    }
    return 1;
}
