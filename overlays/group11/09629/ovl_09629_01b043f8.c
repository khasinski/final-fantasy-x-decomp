#include "common.h"

extern void *D_01B0004C;
extern u8 D_01CE8030[];
extern u8 D_01BE8030[];
extern u8 D_01B00A20[];
extern u8 D_01B00A38[];
extern u8 D_01B00A58[];
extern void *D_01B00618;
extern void *D_01B0E49C;
extern u8 D_01B00050[];
extern u8 D_01B0E470[];
extern u8 D_01B00B40[];

extern void func_01B028F0(void);
extern void func_01B0D3A0(void *);
extern void func_01B051E8(void *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_00269918(int);
extern void func_01B04398(void *);

static __inline__ void call_d3a0(void *a) { void *m[1]; m[0] = a; func_01B0D3A0(m); }
static __inline__ void call_51e8(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; func_01B051E8(m); }

int func_01B043F8(void)
{
    void *v0;

    func_01B028F0();
    D_01B0004C = D_01CE8030;
    call_d3a0(D_01B00A20);
    call_51e8(D_01B00A38, 0);
    D_01B00A38[0x1B] = 1;
    call_51e8(D_01B00A58, 0);
    func_002B4980(D_01B00618);
    v0 = func_002B49A0(D_01B00618, 8, 0);
    D_01B0E49C = v0;
    func_002678E0(v0, D_01B00050);
    func_00267A68(D_01B0E470, D_01B0E49C, D_01BE8030, 0x00100000);
    func_002D02E8(D_01B00618, 0, 1000, 2);
    func_002944B0(D_01B00618, 0, 1000, 2);
    func_00269918(21);
    func_00269918(22);
    func_00269918(31);
    func_00269918(32);
    func_00269918(33);
    func_00269918(34);
    func_00269918(35);
    func_00269918(36);
    func_00269918(37);
    func_00269918(38);
    func_01B04398(D_01B00B40);
    return 0;
}
