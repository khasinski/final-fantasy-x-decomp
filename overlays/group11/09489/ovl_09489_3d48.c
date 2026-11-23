#include "common.h"

extern void func_01B02DF0(void);
extern void func_01B0D9C0(void *);
extern void func_01B04B50(void *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_01B03CF0(void *);
extern int func_001BB3F0(void *, int, void *, void *, void *);
extern void func_001E4C80(int, int);
extern void func_0029A878(void);

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern void *D_01B00708;
extern void *D_01B00724;
extern u8 D_01B00730;
extern u8 D_01B00AE0[];
extern u8 D_01B00AF8[];
extern u8 D_01B00B18[];
extern u8 D_01B015C0[];
extern u8 D_01B0EA60[];
extern void *D_01B0EA8C;
extern u8 D_01BCBF80[];
extern u8 D_01CCBF80[];

int func_01B03D48(void)
{
    void *msg[2];
    void *msg2;
    int out;
    void *p;
    int r;

    func_01B02DF0();
    D_01B0004C = D_01CCBF80;
    msg2 = D_01B00AE0;
    func_01B0D9C0(&msg2);
    msg[0] = D_01B00AF8;
    msg[1] = 0;
    func_01B04B50(msg);
    D_01B00AF8[0x1B] = 1;
    msg[0] = D_01B00B18;
    msg[1] = 0;
    func_01B04B50(msg);
    func_002B4980(D_01B00708);
    p = func_002B49A0(D_01B00708, 8, 0);
    D_01B0EA8C = p;
    func_002678E0(p, D_01B00050);
    func_00267A68(D_01B0EA60, D_01B0EA8C, D_01BCBF80, 0x100000);
    func_002D02E8(D_01B00708, 0, 1000, 2);
    func_002944B0(D_01B00708, 0, 1000, 2);
    func_01B03CF0(D_01B015C0);
    r = func_001BB3F0(D_01B00724, D_01B00730, &out, &out, &out);
    func_001E4C80(0, (r - 1) * 85 + 292);
    func_0029A878();
    return 0;
}
