/* tu_114 0x16e478-0x16e8c8: low; unk_16E478 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/g1.h"

int func_0016E478(int chr) {
    return MsGetSaveCommand(chr, 0x30CC);
}

int func_0016E498(int chr) {
    return MsGetSaveCommand(chr, 0x30CD);
}

int func_0016E4B8(int chr) {
    return MsGetSaveCommand(chr, 0x30CE);
}

int func_0016E4D8(int chr) {
    return MsGetSaveCommand(chr, 0x30CF);
}

int func_0016E4F8(int chr) {
    return MsGetSaveCommand(chr, 0x30D0);
}

int func_0016E518(int chr) {
    return MsGetSaveCommand(chr, 0x30D1);
}

int func_0016E538(int chr) {
    return MsGetSaveCommand(chr, 0x30D2);
}

int func_0016E558(int chr) {
    return MsGetSaveCommand(chr, 0x30D3);
}

int func_0016E578(int chr) {
    return MsGetSaveCommand(chr, 0x30D4);
}

int func_0016E598(int chr) {
    return MsGetSaveCommand(chr, 0x30D5);
}

int func_0016E5B8(int chr) {
    return MsGetSaveCommand(chr, 0x30D6);
}

int func_0016E5D8(int chr) {
    return MsGetSaveCommand(chr, 0x30D7);
}

int func_0016E5F8(int chr) {
    return MsGetSaveCommand(chr, 0x30D8);
}

int func_0016E618(int chr) {
    return MsGetSaveCommand(chr, 0x30D9);
}

int func_0016E638(int chr) {
    return MsGetSaveCommand(chr, 0x30DA);
}

int func_0016E658(int chr) {
    return MsGetSaveCommand(chr, 0x30DB);
}

int func_0016E678(int chr) {
    return MsGetSaveCommand(chr, 0x30DC);
}

int func_0016E698(int chr) {
    return MsGetSaveCommand(chr, 0x30DD);
}

int func_0016E6B8(int chr) {
    return MsGetSaveCommand(chr, 0x30DE);
}

int func_0016E6D8(int chr) {
    return MsGetSaveCommand(chr, 0x30DF);
}

int func_0016E6F8(int chr) {
    return MsGetSaveCommand(chr, 0x30E0);
}

int func_0016E718(int chr) {
    return MsGetSaveCommand(chr, 0x30E1);
}

int func_0016E738(int chr) {
    return MsGetSaveCommand(chr, 0x30E2);
}

int func_0016E758(int chr) {
    return MsGetSaveCommand(chr, 0x30E3);
}

int func_0016E778(int chr) {
    return MsGetSaveCommand(chr, 0x30E4);
}

int func_0016E798(int chr) {
    return MsGetSaveCommand(chr, 0x30E5);
}

int func_0016E7B8(int chr) {
    return MsGetSaveCommand(chr, 0x30E6);
}

int func_0016E7D8(int chr) {
    return MsGetSaveCommand(chr, 0x30E7);
}

int func_0016E7F8(int chr) {
    return MsGetSaveCommand(chr, 0x30E8);
}

int func_0016E818(int chr) {
    return MsGetSaveCommand(chr, 0x30E9);
}

int func_0016E838(int chr) {
    return MsGetSaveCommand(chr, 0x30EA);
}

s32 func_0016E858(int i) {
    return D_0030E0C0[i].w194;
}

s32 func_0016E878(int i) {
    s32 v = MsGetGIL() - D_0030E0C0[i].w194;

    if (v < 0) {
        v = 0;
    }
    return v;
}
