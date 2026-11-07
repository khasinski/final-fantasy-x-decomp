/* tu_036 0x11f8d0-0x11fc58: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/g0.h"

s32 Sg_CaptureGetGuiHide(void)
{
    s32 r = 0;

    if (D_00307FE0 != 0) {
        r = D_00580B08 != 0;
    }
    return r;
}

void Sg_CaptureEnable(void)
{
    D_00307FE0 = 1;
    D_00580B08 = 1 - (D_00580B05 & 1);
    D_00307FE4 = 3;
    D_00307FE8 = 0;
    D_00307FEC = 0;
    D_00580B10[0] = D_02004A28;
    D_00580B10[1] = D_02004A2C;
    D_00580B10[2] = D_02004A1C;
    D_00580B10[3] = D_02004A20;
    D_00580B10[4] = D_02004A24;
}

void func_0011F990(int a, int b)
{
    if (b != 0) {
        D_00307FE8 = a;
        D_00307FE0 = b;
        D_00580B08 = 1;
        D_00307FE4 = 3;
        D_00307FEC = 0;
        D_00307FF0 = 0;
        D_00580B10[0] = D_02004A28;
        D_00580B10[1] = D_02004A2C;
        D_00580B10[2] = D_02004A1C;
        D_00580B10[3] = D_02004A20;
        D_00580B10[4] = D_02004A24;
    }
}

void func_0011FA30(int v)
{
    D_00307FE8 = v;
    D_00307FE0 = 1;
    D_00580B08 = 1;
    D_00307FEC = 1;
    D_00307FF0 = 0;
    D_00580B10[0] = D_02004A28;
    D_00580B10[1] = D_02004A2C;
    D_00580B10[2] = D_02004A1C;
    D_00580B10[3] = D_02004A20;
    D_00580B10[4] = D_02004A24;
}

void func_0011FAA8(void)
{
    D_00307FE0 = 0;
}

extern s32 _m2c_Sg_Capture_D_00307FF4 __asm__("D_00307FF4");
extern s32 _m2c_Sg_Capture_D_00569E48 __asm__("D_00569E48");
extern s32 _m2c_Sg_Capture_D_00569E70 __asm__("D_00569E70");
extern s32 _m2c_Sg_Capture_D_00569EA0 __asm__("D_00569EA0");
extern s32 _m2c_Sg_Capture_D_00569EE0 __asm__("D_00569EE0");
/* DEBT(CAST) */
s32 Sg_Capture(void) {
    u8 sp10[0x200];

    if (D_00307FE0 == 0) {
        return 0;
    }
    if (Sg_GetUserName() != 0) {
        if (_m2c_Sg_Capture_D_00307FF4 != 0) {
            func_002F0008(sp10, &_m2c_Sg_Capture_D_00569E48, Sg_GetUserName());
            func_202CF08(sp10, sp10);
            func_002F0008(sp10, &_m2c_Sg_Capture_D_00569E70, Sg_GetUserName());
            func_202CF08(sp10, sp10);
            _m2c_Sg_Capture_D_00307FF4 = 0;
        }
        func_002F0008(sp10, &_m2c_Sg_Capture_D_00569EA0, Sg_GetUserName(), D_00307FE8, (*(s8 *)((u8 *)(D_00580B10) + (0))), (*(s8 *)((u8 *)(D_00580B10) + (1))), (*(s8 *)((u8 *)(D_00580B10) + (2))), (*(s8 *)((u8 *)(D_00580B10) + (3))), (s32) (*(s8 *)((u8 *)(D_00580B10) + (4))), D_00307FF0);
    } else {
        func_002F0008(sp10, &_m2c_Sg_Capture_D_00569EE0, D_00307FE8, (s32) (*(s8 *)((u8 *)(D_00580B10) + (0))), (*(s8 *)((u8 *)(D_00580B10) + (1))), (*(s8 *)((u8 *)(D_00580B10) + (2))), (*(s8 *)((u8 *)(D_00580B10) + (3))), (*(s8 *)((u8 *)(D_00580B10) + (4))), D_00307FF0);
    }
    if (D_00307FEC != 0) {
        Sg_CaptureToFile(sp10);
    __asm__ volatile("" : : : "$3");
        D_00307FF0 += 1;
    } else if (D_00307FE4 == 0) {
        Sg_CaptureToFile(sp10);
    __asm__ volatile("" : : : "$3");
        D_00307FF0 += 1;
        D_00307FE0 -= 1;
    } else {
        D_00307FE4 -= 1;
    }
    return 1;
}
