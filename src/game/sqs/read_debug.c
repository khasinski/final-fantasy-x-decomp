/* tu_278 0x254a38-0x255a08: low; read_debug (config/tu_map.tsv) */
#define func_00255020 _hdr_func_00255020
#define func_00255100 _hdr_func_00255100
#define set_read_chgname _hdr_set_read_chgname
#define CDfileSize_PC _hdr_CDfileSize_PC
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#undef func_00255020
#undef func_00255100
#undef set_read_chgname
#undef CDfileSize_PC

#ifndef NULL
#define NULL ((void *)0)
#endif
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))

#define GIF_CHCR (*(volatile u32 *)0x1000A000) /* GIF DMA channel control; bit 8 = STR (transfer running) */

void func_00254A38(void)
{
    int i;

    if (D_003271BC == 0) {
        D_003271BC = 1;
        for (i = 0; i < 16; i++) {
            D_006A3190[i] = 0;
            D_006A31D0[i] = 0;
        }
    }
}

void _m2c_set_read_chgname_func_001577A8(s32 *, s8 *, s32) __asm__("func_001577A8");
extern s32 _m2c_D_00573830 __asm__("D_00573830");
s32 set_read_chgname(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_006A3190[i] == 0) {
            break;
        }
    }
    if (i == 16) {
        _m2c_set_read_chgname_func_001577A8(&_m2c_D_00573830, D_00573850, 0x50);
    }
    D_006A3190[i] = arg0;
    D_006A31D0[i] = arg1;
    return i;
}

void func_00254B68(int i)
{
    D_006A3190[i] = 0;
    D_006A31D0[i] = 0;
}

int func_00254B90(void)
{
    return ((int *)GetCD())[12]; /* DEBT(CAST): word 0x30 of the SysVt block */
}

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", func_00254BB0);

int CDfileName_PC(int a)
{
    SysVt *vt = GetCD();

    return func_00254BB0(vt->f20 + a);
}

int func_00254EB8(int i, int a)
{
    return func_00254BB0(D_0078E4C4[i] + a);
}

void *_m2c_CDfileSize_PC_GetCD(void) __asm__("GetCD");
s32 _m2c_CDfileSize_PC_func_00162ED8(s32) __asm__("func_00162ED8");
s32 _m2c_CDfileSize_PC_func_00165D90(s32, s32) __asm__("func_00165D90");
s32 _m2c_CDfileSize_PC_func_00254B90(void) __asm__("func_00254B90");
s32 _m2c_CDfileSize_PC_func_00254BB0(s32) __asm__("func_00254BB0");
s32 _m2c_CDfileSize_PC_func_002FC4E0(s32, s32) __asm__("func_002FC4E0");
void _m2c_CDfileSize_PC_func_002FC768(s32) __asm__("func_002FC768");
s32 _m2c_CDfileSize_PC_func_002FC8E8(s32, s32, s32) __asm__("func_002FC8E8");
extern s32 _m2c_D_0078E4BC __asm__("D_0078E4BC");
s32 CDfileSize_PC(s32 arg0) {
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_16;
    void *temp_18;

    temp_18 = _m2c_CDfileSize_PC_GetCD();
    var_16 = _m2c_CDfileSize_PC_func_00165D90(_m2c_D_0078E4BC, arg0);
    if (var_16 != 0) {
        return var_16;
    }
    if (D_005661F4 != 0) {
        var_16 = _m2c_CDfileSize_PC_func_00162ED8(arg0);
    } else {
        temp_17 = M2C_FIELD(temp_18, s32 *, 0x20) + arg0;
        if (_m2c_CDfileSize_PC_func_00254B90() != 0) {
            temp_2 = _m2c_CDfileSize_PC_func_00254BB0(temp_17);
            if (temp_2 != 0) {
                temp_2_2 = _m2c_CDfileSize_PC_func_002FC4E0(temp_2, 1);
                if (temp_2_2 < 0) {
                    return 0;
                }
                var_16 = _m2c_CDfileSize_PC_func_002FC8E8(temp_2_2, 0, 2);
                var_16 = ((var_16 + 0xF) / 16) * 0x10;
                _m2c_CDfileSize_PC_func_002FC768(temp_2_2);
            }
        }
    }
    return var_16;
}

int func_00254FD0(int a)
{
    return func_00163158(D_0078E4B8 + a);
}

void func_00254FF8(int n)
{
    if (n < 0) {
        func_001577A8(D_00573860, D_00573850, 0x14D);
    }
}

void _m2c_func_00255020_func_00254FF8(s32, s32) __asm__("func_00254FF8");
void _m2c_func_00255020_func_002F8660(s32) __asm__("func_002F8660");
s32 _m2c_func_00255020_func_002FC4E0(s32, s32) __asm__("func_002FC4E0");
void _m2c_func_00255020_func_002FC768(s32) __asm__("func_002FC768");
s32 _m2c_func_00255020_func_002FC8E8(s32, s32, s32) __asm__("func_002FC8E8");
void _m2c_func_00255020_func_002FCB20(s32, s32, s32) __asm__("func_002FCB20");
s32 _m2c_func_00255020_user_malloc(s32, s32, s8 *, s32) __asm__("user_malloc");
s32 func_00255020(s32 arg0, s32 *arg1) {
    s32 temp_16;
    s32 temp_18;
    s32 temp_2;
    s32 temp_3;

    temp_2 = _m2c_func_00255020_func_002FC4E0(arg0, 1);
    _m2c_func_00255020_func_00254FF8(temp_2, arg0);
    temp_16 = _m2c_func_00255020_func_002FC8E8(temp_2, 0, 2);
    _m2c_func_00255020_func_002FC8E8(temp_2, 0, 0);
    temp_3 = temp_16 + 3;
    temp_18 = _m2c_func_00255020_user_malloc((((s32)temp_3 / 4)) * 4, 0xA, D_00573850, 0x165);
    _m2c_func_00255020_func_002F8660(0);
    _m2c_func_00255020_func_002FCB20(temp_2, temp_18, temp_16);
    _m2c_func_00255020_func_002FC768(temp_2);
    _m2c_func_00255020_func_002F8660(0);
    if (arg1 != 0) {
        *arg1 = temp_16;
    }
    return temp_18;
}

void _m2c_func_00255100_func_00254FF8(s32, s32) __asm__("func_00254FF8");
void _m2c_func_00255100_func_002F8660(s32) __asm__("func_002F8660");
s32 _m2c_func_00255100_func_002FC4E0(s32, s32) __asm__("func_002FC4E0");
void _m2c_func_00255100_func_002FC768(s32) __asm__("func_002FC768");
s32 _m2c_func_00255100_func_002FC8E8(s32, s32, s32) __asm__("func_002FC8E8");
void _m2c_func_00255100_func_002FCB20(s32, s32, s32) __asm__("func_002FCB20");
s32 _m2c_func_00255100_func_002D9758(void) __asm__("FFXIsPC");
s32 _m2c_func_00255100_user_malloc(s32, s32, s8 *, s32) __asm__("user_malloc");
s32 _m2c_func_00255100_func_0011D420(s32, s32, s8 *, s32) __asm__("func_0011D420");
extern s8 _m2c_D_005661F0 __asm__("ffx_debugmode");
s32 func_00255100(s32 arg0, s32 *arg1) {
    s32 temp_17;
    s32 temp_2;
    s32 var_2;

    temp_2 = _m2c_func_00255100_func_002FC4E0(arg0, 1);
    _m2c_func_00255100_func_00254FF8(temp_2, arg0);
    temp_17 = _m2c_func_00255100_func_002FC8E8(temp_2, 0, 2);
    _m2c_func_00255100_func_002FC8E8(temp_2, 0, 0);
    if ((_m2c_func_00255100_func_002D9758() == 1) && (_m2c_D_005661F0 == 0)) {
        var_2 = _m2c_func_00255100_user_malloc(((temp_17 + 3) / 4) * 4, 0xA, D_00573850, 0x188);
    } else {
        var_2 = _m2c_func_00255100_func_0011D420(((temp_17 + 3) / 4) * 4, 0xA, D_00573850, 0x18A);
    }
    _m2c_func_00255100_func_002F8660(0);
    _m2c_func_00255100_func_002FCB20(temp_2, var_2, temp_17);
    _m2c_func_00255100_func_002FC768(temp_2);
    _m2c_func_00255100_func_002F8660(0);
    if (arg1 != NULL) {
        *arg1 = temp_17;
    }
    return var_2;
}

INCLUDE_ASM("build/ee_asm/game/sqs/read_debug", func_00255238);

void PcFileTblSet(int a)
{
    if (D_0078E498.f30 != 0) {
        func_0011D590(D_0078E498.f30, 10);
    }
    D_0078E498.f30 = func_00255100(a, 0);
}

void pc_fat_index_filename_set(void)
{
    u8 language[3]; /* two-letter code and the terminating NUL */
    CALL_MsSetCountryName_INT(language);
    /* DEBT(ORDER): independent configuration writes retain original scheduling. */
    if (D_005661F4 == 0)
    {
        D_00327080.language[0] = language[0];
        D_00327080.language[1] = language[1];
        D_003270B0.language[0] = language[0];
        D_003270B0.language[1] = language[1];
        D_003270E0.language[0] = language[0];
        D_003270E0.language[1] = language[1];
        D_0078E498.f28 = func_00255020(&D_00327080, 0);
        D_0078E498.f2C = func_00255020(&D_003270B0, 0);
        /* DEBT(CAST): loader API uses an integer address/handle view. */
        D_0078E498.f30 = func_00255100((s32) &D_003270E0, 0);
        return;
    }
    D_00327110.b1A = language[0];
    D_00327110.b1B = language[1];
    D_00327138.b1A = language[0];
    D_00327138.b1B = language[1];
    D_0078E498.f28 = func_00255020(&D_00327110, 0);
    D_0078E498.f2C = func_00255020(&D_00327138, 0);
    D_0078E498.f30 = 0;
}

void func_002558E0(void)
{
    u8 buf[2];

    MsSetCountryName(buf);
    D_00327160.b1A = buf[0];
    D_00327160.b1B = buf[1];
    func_00255020(&D_00327160, 0);
}

void func_00255920(void)
{
    u8 buf[2];

    MsSetCountryName(buf);
    D_00327190.b1A = buf[0];
    D_00327190.b1B = buf[1];
    func_00255020(&D_00327190, 0);
}

int func_00255960(void)
{
    return func_00164648();
}

int func_00255980(void)
{
    return -1;
}

int func_00255988(void)
{
    return -1;
}

void PcReadFunc_set(void)
{
    T6_VT->f14 = (int (*)())CDfileSize_PC;
    T6_VT->f58 = (int (*)())CDfileName_PC;
    T6_VT->f54 = (int (*)())func_00255020;
    T6_VT->f68 = (int (*)())func_00255238;
    T6_VT->f60 = (int (*)())PcFileTblSet;
    T6_VT->f78 = (int (*)())func_00255960;
    T6_VT->f88 = (int (*)())func_00255980;
    T6_VT->f8C = (int (*)())func_00255988;
    T6_VT->f04 = (int (*)())func_00254FD0;
}
