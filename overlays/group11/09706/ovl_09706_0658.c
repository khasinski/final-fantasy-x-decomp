#include "common.h"
extern u8 D_01B01650[];
extern u8 D_01B01730[];
extern u8 D_01B00538[];
extern void *D_01B00408, *D_01B0040C, *D_01B00410, *D_01B0041C;
extern int D_01B00648;
extern void *D_006A3BCC;
extern void func_002DAB10(void *, int, int, int, int, int, int, int);
extern void func_002F8660(int);
extern void func_002DADD0(void *, void *);
extern void func_002D02E8(void *, int, int, int);
extern void func_002D05F0(int);
extern void func_002D0698(int);
extern void func_002D0750(int);
extern void func_002B2730(int);
extern void func_01B01440(void *);
extern void func_002DA928(void *, int, int, int, int, int, int, int);
extern void func_002DA610(int, int);
extern void func_002DAC50(void *, void *);

void func_01B00658(void) {
    func_002DAB10(D_01B01650, 0x2E00, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DADD0(D_01B01650, D_01B0040C);
    func_002DAB10(D_01B01650 + 0x70, 0x3200, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DADD0(D_01B01650 + 0x70, D_01B00410);
    { /* DEBT(FAKE): pin v1 for D_01B00648 comparison */ register int c __asm__("$3") = D_01B00648; if (c >= 302) {
        func_002D02E8(D_01B0041C, 0, 1000, 0x2000);
    } else {
        func_002D02E8(D_01B0041C, 0, 14, 0x2000);
    } }
    func_002D05F0(0x2000);
    func_002D0698(0x2000);
    func_002D0750(0x2000);
    func_002B2730(0);
    D_006A3BCC = D_01B00408;
    func_01B01440(D_01B00538);
    func_002DA928(D_01B01730, 0x2E00, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(D_01B01730, D_01B0040C);
    func_002DA928(D_01B01730 + 0x60, 0x3200, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(D_01B01730 + 0x60, D_01B00410);
    func_002DA610(0, 0);
    D_01B00648++;
}
