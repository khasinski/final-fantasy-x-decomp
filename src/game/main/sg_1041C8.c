/* tu_002 0x1041c8-0x104528: low; ~Sg (config/tu_map.tsv) */
#define func_00104358 _hdr_func_00104358
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_00104358

s32 func_001041C8(int i, int v)
{
    RegEntry *e = &D_00303558[i];

    switch (e->kind) {
    case 1:
        D_0057D690[e->off] = v;
        break;
    case 2:
        D_0057D690[e->off] = v;
        D_0057D690[e->off + 1] = v >> 8;
        break;
    }
    return D_0057DA90 = 1;
}

void func_00104248(int idx, char *str)
{
    if ((u32)func_002F0840(str) < D_00303558[idx].kind) {
        func_002F072C((char *)D_0057D690 + D_00303558[idx].off, str);
        D_0057DA90 = 1;
    }
}

u8 *func_001042C0(s32 idx)
{
    return D_0057D690 + D_00303558[idx].off;
}

int func_001042E8(int i, int def)
{
    RegEntry *e = &D_00303558[i];

    switch (e->kind) {
    case 1:
        return D_0057D690[D_00303558[i].off];
    case 2:
        return (D_0057D690[e->off + 1] << 8) | D_0057D690[e->off];
    default:
        return def;
    }
}

s32 _m2c_func_00104358_func_002DA610(s32, s32) __asm__("func_002DA610");
s32 _m2c_func_00104358_func_002DAC50(void *, u8 *) __asm__("func_002DAC50");
s32 _m2c_func_00104358_func_002ED0E0(u8 *, s32) __asm__("func_002ED0E0");
s32 _m2c_func_00104358_func_002F8660(s32) __asm__("func_002F8660");
/* DEBT(CAST) */
void func_00104358(void) {
    u8 sp[0x60];
    if (((*(u8 *)((u8 *)(D_0057D690) + (0))) != 0x29) || ((*(u8 *)((u8 *)(D_0057D690) + (1))) != 0xFF)) {
        _m2c_func_00104358_func_002ED0E0(D_0057D690, 0x400);
        (*(u8 *)((u8 *)(D_0057D690) + (0))) = 0x29;
        (*(u8 *)((u8 *)(D_0057D690) + (1))) = 0xFFU;
    }
    func_002DA928(sp, 0x2EFC, 1, 0, 0, 0, 0x10, 0x10);
    _m2c_func_00104358_func_002F8660(0);
    _m2c_func_00104358_func_002DAC50(sp, D_0057D690);
    _m2c_func_00104358_func_002DA610(0, 0);
}

void Sg_LoadVramResource(void)
{
    u8 ctx[0x70];
    u32 i;
    s32 off = 2;

    for (i = 0; i < 20; i++) {
        D_00303558[i].off = off;
        off += D_00303558[i].kind;
    }
    func_002DAB10(ctx, 0x2EFC, 1, 0, 0, 0, 0x10, 0x10);
    func_002F8660(0);
    func_002DADD0(ctx, (int)D_0057D690);
    func_002DA610(0, 0);
    func_002F8660(0);
    if (D_0057D690[0] != 0x29 || D_0057D690[1] != 0xFF) {
        func_00104358();
    }
}

void func_001044D8(void)
{
    if (D_0057DA90 != 0) {
        D_0057DA94 = 30;
    }
    D_0057DA90 = 0;
    if (D_0057DA94 != 0) {
        D_0057DA94--;
        if (D_0057DA94 == 0) {
            func_00104358();
        }
    }
}

void func_00104518(int a)
{
    func_001041C8(9, 1 - a);
}
