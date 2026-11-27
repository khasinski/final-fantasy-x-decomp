#include "common.h"

extern s32 D_01B0004C;
extern s32 D_01B00960;
extern s32 D_01B00B84;
extern u8 D_01B00050[];
extern u8 D_01B009C0[];
extern u8 D_01B00B20[];
extern u8 D_01B00F40[];
extern u8 D_01B00F58[];
extern u8 D_01B00F70[];
extern u8 D_01B00F90[];
extern u8 D_01B00FB0[];
extern u8 D_01B00FD0[];
extern u8 D_01B0ACA8[];
extern u8 D_01B0ACF0[];
extern u8 D_01B0B5E8[];
extern u8 D_01B1A040[];
extern void *D_01B1A06C;
extern u8 D_01B1A070[];
extern void *D_01B1B0C0;
extern u8 D_01C072E0[];
extern u8 D_01D072E0[];

extern void func_01B0B460(void);
extern void func_01B18F80(void *);
extern void func_01B0EC00(void *);
extern void func_002B4980(s32);
extern void *func_002B49A0(s32, s32, s32);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, s32);
extern void func_002D02E8(s32, s32, s32, s32);
extern void func_002944B0(s32, s32, s32, s32);
extern void func_00294468(void *, s32, s32);
extern void func_001B57F0(s32, s32);
extern void func_001B5810(s32, s32);
extern void func_01B0CD58(void *);
extern void func_01B0C290(void *);

typedef struct {
    void *p0;
    void *p4;
} Msg2;

s32 func_01B0CDB8(void) {
    Msg2 msg;
    void *sp10;
    void *sp14;
    s32 i;
    u8 *p;

    func_01B0B460();
    D_01B1B0C0 = D_01D072E0;
    D_01B0004C = (s32)(D_01D072E0 + 0x5190);

    sp10 = D_01B00F40;
    func_01B18F80(&sp10);
    sp14 = D_01B00F58;
    func_01B18F80(&sp14);

    msg.p0 = D_01B00F70;
    msg.p4 = 0;
    func_01B0EC00(&msg);
    D_01B00F70[0x1B] = 1;

    msg.p0 = D_01B00F90;
    msg.p4 = 0;
    func_01B0EC00(&msg);
    D_01B00F90[0x1B] = 1;

    msg.p0 = D_01B00FB0;
    msg.p4 = 0;
    func_01B0EC00(&msg);

    msg.p0 = D_01B00FD0;
    msg.p4 = 0;
    func_01B0EC00(&msg);

    func_002B4980(D_01B00960);
    D_01B1A06C = func_002B49A0(D_01B00960, 8, 0);
    func_002678E0(D_01B1A06C, D_01B00050);
    func_00267A68(D_01B1A040, D_01B1A06C, D_01C072E0, 0x100000);

    for (i = 0x56; i >= 0; i--) {
        void **tbl = (void **)D_01B009C0;
        D_01B1A070[i * 0x30 + 0x22] = 0;
        tbl[D_01B00B20[i]] = D_01B0B5E8;
    }

    func_002D02E8(D_01B00960, 0, 9, 2);
    func_002944B0(D_01B00960, 0, 0x3E8, 2);
    func_00294468(func_002B49A0(D_01B00960, 6, 2), 0, 2);
    func_001B57F0(D_01B00B84, 1);
    func_001B5810(D_01B00B84, 0);
    func_01B0CD58(D_01B0ACF0);
    func_01B0C290(D_01B0ACA8);

    return 0;
}
