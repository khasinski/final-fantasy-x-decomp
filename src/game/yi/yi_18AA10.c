/* tu_136 0x18aa10-0x18b680: low; ~yiClutAlloc (config/tu_map.tsv) */
#define func_0018AAC8 _hdr_func_0018AAC8
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/v2.h"
#undef func_0018AAC8

extern s32 D_0065FD1C;
extern s32 D_0065FD20;
extern u32 D_0065FD24;
extern u32 D_0065FD2C;

void func_0018AA10(int mode)
{
    switch (mode) {
    case 2:
        D_0065FD1C = D_0065FD20 = 0xB4000;
        D_0065FD24 = 0x20;
        break;
    case 3:
        D_0065FD1C = D_0065FD20 = 0x18000;
        D_0065FD24 = 0x20;
        break;
    case 4:
        D_0065FD1C = D_0065FD20 = 0x82000;
        D_0065FD24 = 0x10;
        break;
    }
    D_0065FD28 = 0;
    D_0065FD2C = 0;
}

int func_0018AAB8(void) {
    return D_0065FD28;
}

extern s32 _m2c_func_0018AAC8_D_00312EA0[] __asm__("D_00312EA0");
extern s32 _m2c_func_0018AAC8_D_00312EB0[] __asm__("D_00312EB0");
extern s32 _m2c_func_0018AAC8_D_0065FD20 __asm__("D_0065FD20");
extern u32 _m2c_func_0018AAC8_D_0065FD24 __asm__("D_0065FD24");
extern u32 _m2c_func_0018AAC8_D_0065FD28 __asm__("D_0065FD28");
extern u32 _m2c_func_0018AAC8_D_0065FD2C __asm__("D_0065FD2C");
s32 func_0018AAC8(s32 arg0) {
    s32 *var_5;
    s32 var_6;

    if (_m2c_func_0018AAC8_D_0065FD28 >= 0x48U) {
        BREAK();
        return -1;
    }
    if (arg0 == 2) {
        var_5 = _m2c_func_0018AAC8_D_00312EA0;
    } else if (arg0 >= 2) {
        if (arg0 < 5) {
            var_5 = _m2c_func_0018AAC8_D_00312EB0;
        }
    }
    if (_m2c_func_0018AAC8_D_0065FD28 == _m2c_func_0018AAC8_D_0065FD24) {
        _m2c_func_0018AAC8_D_0065FD20 = 0xB8000;
    }
    if (_m2c_func_0018AAC8_D_0065FD28 < _m2c_func_0018AAC8_D_0065FD24) {
        var_6 = _m2c_func_0018AAC8_D_0065FD20 + var_5[_m2c_func_0018AAC8_D_0065FD2C++];
        if (_m2c_func_0018AAC8_D_0065FD2C >= 4U) {
            _m2c_func_0018AAC8_D_0065FD2C = 0;
            _m2c_func_0018AAC8_D_0065FD20 += 0x800;
        }
    } else {
        var_6 = _m2c_func_0018AAC8_D_0065FD20;
        _m2c_func_0018AAC8_D_0065FD20 += 0x100;
    }
    _m2c_func_0018AAC8_D_0065FD28 += 1;
    return var_6 / 64;
}

extern u32 _yi_D_00312EA0[] __asm__("D_00312EA0"); /* DEBT(TYPE): u32 shifts */
extern u32 _yi_D_00312EB0[] __asm__("D_00312EB0"); /* DEBT(TYPE): u32 shifts */

void func_0018ABA8(u8 *dst, int count, int mode)
{
    u8 tag[0x70];
    int addr;
    u32 *tbl;
    int sub;
    int i;

    switch (mode) {
    case 2:
        addr = 0xB4000;
        tbl = _yi_D_00312EA0;
        D_0065FD24 = 0x20;
        break;
    case 3:
        addr = 0x18000;
        tbl = _yi_D_00312EB0;
        D_0065FD24 = 0x20;
        break;
    case 4:
        addr = 0x82000;
        D_0065FD24 = 0x10;
        tbl = _yi_D_00312EB0;
        break;
    }
    sub = 0;
    for (i = 0; i < count; i++, dst += 0x400) {
        if ((u32)i == D_0065FD24) {
            addr = 0xB8000;
        }
        if ((u32)i < D_0065FD24) {
            func_002DAB10(tag, (s16)(addr / 64 + (tbl[sub++] >> 6)), 1, 0, 0, 0, 0x10, 0x10);
            func_002F8660(0);
            func_002DA610(0, 0);
            func_002DADD0(tag, dst);
            if (sub >= 4) {
                sub = 0;
                addr += 0x800;
            }
        } else {
            func_002DAB10(tag, (s16)(addr / 64), 1, 0, 0, 0, 0x10, 0x10);
            addr += 0x100;
            func_002F8660(0);
            func_002DA610(0, 0);
            func_002DADD0(tag, dst);
        }
    }
}

int func_0018ADB8(R2Sys460 *o, int count, int mode) /* DEBT(TYPE): falls off end (non-void keeps $v0 live for bnezl) */
{
    u8 tag[0x70];
    int addr;
    u32 *tbl;
    int sub;
    int i;

    switch (mode) {
    case 2:
        addr = 0xB4000;
        tbl = _yi_D_00312EA0;
        D_0065FD24 = 0x20;
        break;
    case 3:
        addr = 0x18000;
        tbl = _yi_D_00312EB0;
        D_0065FD24 = 0x20;
        break;
    case 4:
        addr = 0x82000;
        D_0065FD24 = 0x10;
        tbl = _yi_D_00312EB0;
        break;
    }
    sub = 0;
    for (i = 0; i < count; i++) {
        if ((u32)i == D_0065FD24) {
            addr = 0xB8000;
        }
        if ((u32)i < D_0065FD24) {
            func_002DAB10(tag, (s16)(addr / 64 + (tbl[sub++] >> 6)), 1, 0, 0, 0, 0x10, 0x10);
            func_002F8660(0);
            func_002DA610(0, 0);
            func_002DADD0(tag, o->rec[i].q);
            if (sub >= 4) {
                sub = 0;
                addr += 0x800;
            }
        } else {
            func_002DAB10(tag, (s16)(addr / 64), 1, 0, 0, 0, 0x10, 0x10);
            addr += 0x100;
            func_002F8660(0);
            func_002DA610(0, 0);
            func_002DADD0(tag, o->rec[i].q);
        }
    }
}

void func_0018AFE8(u8 *dst, int count, int mode)
{
    u8 tag[0x60];
    int addr;
    u32 *tbl;
    int sub;
    int i;

    switch (mode) {
    case 2:
        addr = 0xB4000;
        tbl = _yi_D_00312EA0;
        D_0065FD24 = 0x20;
        break;
    case 3:
        addr = 0x18000;
        tbl = _yi_D_00312EB0;
        D_0065FD24 = 0x20;
        break;
    case 4:
        addr = 0x82000;
        D_0065FD24 = 0x10;
        tbl = _yi_D_00312EB0;
        break;
    }
    sub = 0;
    for (i = 0; i < count; i++, dst += 0x400) {
        if ((u32)i == D_0065FD24) {
            addr = 0xB8000;
        }
        if ((u32)i < D_0065FD24) {
            func_002DA928(tag, (s16)(addr / 64 + (tbl[sub++] >> 6)), 1, 0, 0, 0, 0x10, 0x10);
            func_002F8660(0);
            func_002DA610(0, 0);
            func_002DAC50(tag, dst);
            if (sub >= 4) {
                sub = 0;
                addr += 0x800;
            }
        } else {
            func_002DA928(tag, (s16)(addr / 64), 1, 0, 0, 0, 0x10, 0x10);
            addr += 0x100;
            func_002F8660(0);
            func_002DA610(0, 0);
            func_002DAC50(tag, dst);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_18AA10", yiClutAlloc_makepacket);

void func_0018B558(R2Sys460 *o, R2Quad *src, int idx) {
    R2Quad *d = o->rec[idx].q;
    int i;

    for (i = 0; i < 64; i++) {
        d[i].a = src[i].a;
        d[i].b = src[i].b;
        d[i].c = src[i].c;
        d[i].d = src[i].d;
    }
}

void func_0018B5A8(R2Sys460 *o, R2Quad *src, int idx, int sub) {
    R2Quad *d = &o->rec[idx].q[(sub / 2) * 8 + (sub % 2) * 2];

    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
    src++;
    d++;
    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
    src++;
    d += 3;
    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
    src++;
    d++;
    d->a = src->a;
    d->b = src->b;
    d->c = src->c;
    d->d = src->d;
}
