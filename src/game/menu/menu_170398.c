/* tu_118 0x170398-0x1709e0: low; unk_170398 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/g1.h"

char *func_00170398(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[83]);
}

char *func_001703C8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[84]);
}

char *func_001703F8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[85]);
}

char *func_00170428(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[86]);
}

char *func_00170458(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[87]);
}

char *func_00170488(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[88]);
}

char *func_001704B8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[89]);
}

char *func_001704E8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[90]);
}

char *func_00170518(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[91]);
}

char *func_00170548(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[92]);
}

char *func_00170578(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[93]);
}

char *func_001705A8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[94]);
}

char *func_001705D8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[95]);
}

char *func_00170608(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[96]);
}

char *func_00170638(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[97]);
}

char *func_00170668(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[98]);
}

char *func_00170698(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[99]);
}

char *func_001706C8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[100]);
}

char *func_001706F8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[101]);
}

char *func_00170728(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[102]);
}

char *func_00170758(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[103]);
}

char *func_00170788(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[104]);
}

char *func_001707B8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[105]);
}

char *func_001707E8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[106]);
}

char *func_00170818(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[107]);
}

char *func_00170848(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[108]);
}

char *func_00170878(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[109]);
}

char *func_001708A8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[110]);
}

char *func_001708D8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[111]);
}

int func_00170908(void) {
    return func_00165F70();
}

void func_00170928(int i, int v) {
    ((u8 *)MsGetSaveEventFlag())[i] = v;
}

void func_00170960(int i, int v) {
    u8 *p = (u8 *)MsGetSaveEventFlag() + i / 8;
    int mask = 1 << (i & 7);

    *p &= ~mask;
    if (v != 0) {
        *p |= mask;
    }
}

void func_001709D0(int i, int v) {
    func_00165F30(i, v);
}

void func_001709D8(int cost) {
    MsPayGIL(cost);
}
