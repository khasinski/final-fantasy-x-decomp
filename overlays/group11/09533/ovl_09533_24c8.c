#include "common.h"

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    s32 w18;
    s32 w1C;
} OefData;

typedef struct {
    u8 pad00[0x20];
    s32 w20;
    s32 w24;
    s32 w28;
} PppEnv;

typedef struct {
    s16 h00;
    s16 h02;
    u8 pad04[0x2C];
} ObjC80;

extern u8 D_01B00040[];
extern u8 D_01B00540[];
extern u8 D_01B005A0[];
extern u8 D_01B005D0[];
extern u8 D_01B00600[];
extern u8 D_01B00630[];
extern u8 *D_01B006AC;
extern u8 *D_01B006B0;
extern u8 *D_01B006B4;
extern u8 *D_01B006BC;
extern s32 D_01B006C0;
extern u8 *D_01B006C4;
extern OefData *D_01B006C8;
extern PppEnv D_01B006D0;
extern ObjC80 D_01B00C80;
extern void *D_01B00CB8[2];
extern void *D_01B00DA0;
extern void *D_01B00DA4;
extern void *D_01B00DA8;
extern void *D_01B00DAC;
extern void *D_01B00DB0;
extern void *D_01B00DB4;
extern void *D_01B00DB8;
extern u8 D_01B00E68[];
extern u8 D_01B00F78[];
extern u8 D_01B01088[];
extern u8 D_01B01198[];
extern u8 D_01B012A8[];
extern u8 D_01B03888[];
extern u8 D_01B03898[];
extern u8 D_01B038A8[];
extern u8 D_01B038B8[];
extern u8 D_01B038C8[];
extern u8 D_01B038D8[];
extern u8 D_01B038E8[];
extern u8 D_01B038F8[];
extern u8 D_01B03AB0[];
extern u8 D_01B769F0[];

extern int func_01B02BC0(void *, ...);
extern int func_01B02BF0(void *, ...);
extern void func_01B034E0(void *, void *, s32);
extern void op_oef2_set2(void *);
extern void func_002D02E8(void *, s32, s32, s32);
extern OefData *op_oef2_a_get(void *, s32, s32);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, s32);
extern void *func_002EF0D0(void *, s32, s32);
extern void *func_0013B150(s32);

int func_01B024C8(s32 a0)
{
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    OefData *oef;
    s32 w14, w18, w1c;

    func_01B02BC0(D_01B03888);
    D_01B006C0 = a0;
    D_01B006C4 = D_01B03AB0;

    p0 = D_01B769F0;
    p1 = p0 + 0x80000;
    p2 = p1 + 0x80000;
    p3 = p2 + 0x80000;
    D_01B00CB8[0] = p3;
    D_01B00CB8[1] = p3 + 0x4B00;
    D_01B006B0 = p1;
    D_01B006B4 = p2;
    D_01B006BC = p3;
    D_01B006AC = p0;

    op_oef2_set2(D_01B03AB0);
    func_002D02E8(D_01B006C4, 0, 1000, 0x2000);
    D_01B006C8 = op_oef2_a_get(D_01B006C4, 8, 0);
    func_002678E0(D_01B006C8, D_01B00040);
    func_00267A68(&D_01B006D0, D_01B006C8, D_01B006AC, 0x80000);

    oef = D_01B006C8;
    w14 = oef->w14;
    w18 = oef->w18;
    w1c = oef->w1C;
    D_01B006D0.w20 = w14;
    D_01B006D0.w24 = w18;
    D_01B006D0.w28 = w1c;

    func_002EF0D0(&D_01B00C80, 0, 0x30);
    D_01B00C80.h02 = 0x80;

    func_01B034E0(D_01B00E68, D_01B00540, 4);
    func_01B034E0(D_01B00F78, D_01B005A0, 2);
    func_01B034E0(D_01B01088, D_01B005D0, 2);
    func_01B034E0(D_01B01198, D_01B00600, 2);
    func_01B034E0(D_01B012A8, D_01B00630, 2);

    if ((D_01B00DA0 = func_0013B150(0)) == 0) {
        func_01B02BF0(D_01B03898);
    }
    if ((D_01B00DA8 = func_0013B150(0x15)) == 0) {
        func_01B02BF0(D_01B038A8);
    }
    if ((D_01B00DAC = func_0013B150(0x16)) == 0) {
        func_01B02BF0(D_01B038B8);
    }
    if ((D_01B00DB8 = func_0013B150(0x14)) == 0) {
        func_01B02BF0(D_01B038C8);
    }
    if ((D_01B00DB0 = func_0013B150(0x18)) == 0) {
        func_01B02BF0(D_01B038D8);
    }
    if ((D_01B00DB4 = func_0013B150(0x19)) == 0) {
        func_01B02BF0(D_01B038E8);
    }
    if ((D_01B00DA4 = func_0013B150(0x17)) == 0) {
        func_01B02BF0(D_01B038F8);
    }
    return 1;
}
