/* tu_267 0x2414f0-0x2416c0: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

void TkMenuSetDummyControlerFlag(int v) {
    D_0069A7EC = v;
}

int TkMenuGetDummyControlerFlag(void) {
    return D_0069A7EC;
}

int TkMenuGetDummyControler(void) {
    return D_0069A7D8[0];
}

int TkMenuGetDummyControlerR(void) {
    return D_0069A7D8[0];
}

int TkMenuGetDummyControlerT(void) {
    return D_0069A7D8[0];
}

int TOMenuGetDummyAnalogControler(int i) {
    switch (i) {
    case 2:
        return D_0069A7E0[0];
    case 3:
        return D_0069A7E0[2];
    case 0:
        return D_0069A7E8[0];
    case 1:
        return D_0069A7E8[2];
    }
    return 0x80;
}

void func_002415B8(int v) {
    D_0069A7DC = v;
}

void func_002415C8(int i, u8 v) {
    switch (i) {
    case 2:
        D_0069A7E0[1] = v;
        break;
    case 3:
        D_0069A7E0[3] = v;
        break;
    case 0:
        D_0069A7E8[1] = v;
        break;
    case 1:
        D_0069A7E8[3] = v;
        break;
    }
}

void func_00241630(void) { func_002D6630(); }

void TkMenuFlushDummyControler(void) {
    D_0069A7D8[0] = D_0069A7D8[1];
    D_0069A7D8[1] = 0;
    D_0069A7E0[0] = D_0069A7E0[1];
    D_0069A7E0[1] = 0x80;
    D_0069A7E0[2] = D_0069A7E0[3];
    D_0069A7E0[3] = 0x80;
    D_0069A7E8[0] = D_0069A7E8[1];
    D_0069A7E8[1] = 0x80;
    D_0069A7E8[2] = D_0069A7E8[3];
    D_0069A7E8[3] = 0x80;
}

void func_00241698(void) {
}

void TkMenuInitDummyControler(void) {
    D_0069A7D8[0] = 0;
    D_0069A7D8[1] = 0;
    D_0069A7EC = 0;
}
