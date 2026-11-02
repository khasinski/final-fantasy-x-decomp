/* tu_117 0x16f108-0x170398: low; unk_16F108 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/g1.h"

void *func_0016F108(int text_id)
{
    int base;
    OfsTbl *table;
    if (text_id == 0) return D_00597A08;
    table = MsGetRomItem(text_id, &base);
    base += table->a[0].x;
    /* DEBT(CAST): resource lookup returns the text base as an integer address. */
    return (void *)base;
}

void *func_0016F148(int i) {
    return func_0016F108(D_0030E0C0[i].h8C[0]);
}

void *func_0016F178(int i) {
    return func_0016F108(D_0030E0C0[i].h8C[1]);
}

void *func_0016F1A8(int i) {
    return func_0016F108(D_0030E0C0[i].h8C[2]);
}

void *func_0016F1D8(int i) {
    return func_0016F108(D_0030E0C0[i].h8C[3]);
}

void *func_0016F208(int i) {
    return func_0016F108(D_0030E0C0[i].h98[0]);
}

void *func_0016F238(int i) {
    return func_0016F108(D_0030E0C0[i].h98[1]);
}

void *func_0016F268(int i) {
    return func_0016F108(D_0030E0C0[i].h98[2]);
}

void *func_0016F298(int i) {
    return func_0016F108(D_0030E0C0[i].h98[3]);
}

void *func_0016F2C8(int i) {
    return func_0016F108(D_0030E0C0[i].hA4[0]);
}

void *func_0016F2F8(int i) {
    return func_0016F108(D_0030E0C0[i].hA4[1]);
}

u8 func_0016F328(int i) {
    return D_0030E0C0[i].bA8[0];
}

u8 func_0016F348(int i) {
    return D_0030E0C0[i].bA8[1];
}

char *func_0016F368(int id) {
    if (id == 0) {
        return D_00597A08;
    }
    return (char *)func_00227768(id); /* DEBT(TYPE): func_00227768 is declared as returning int */
}

char *func_0016F398(int i) {
    return func_0016F368(D_0030E0C0[i].hAA);
}

u8 func_0016F3C8(int i) {
    return D_0030E0C0[i].bAD;
}

u8 func_0016F3E8(int i) {
    return D_0030E0C0[i].bB1;
}

char *func_0016F408(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[0]);
}

char *func_0016F438(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[1]);
}

char *func_0016F468(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[2]);
}

char *func_0016F498(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[3]);
}

char *func_0016F4C8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[4]);
}

char *func_0016F4F8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[5]);
}

char *func_0016F528(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[6]);
}

char *func_0016F558(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[7]);
}

char *func_0016F588(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[8]);
}

char *func_0016F5B8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[9]);
}

char *func_0016F5E8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[10]);
}

char *func_0016F618(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[11]);
}

char *func_0016F648(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[12]);
}

char *func_0016F678(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[13]);
}

char *func_0016F6A8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[14]);
}

char *func_0016F6D8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[15]);
}

char *func_0016F708(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[16]);
}

char *func_0016F738(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[17]);
}

char *func_0016F768(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[18]);
}

char *func_0016F798(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[19]);
}

char *func_0016F7C8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[20]);
}

char *func_0016F7F8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[21]);
}

char *func_0016F828(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[22]);
}

char *func_0016F858(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[23]);
}

char *func_0016F888(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[24]);
}

char *func_0016F8B8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[25]);
}

char *func_0016F8E8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[26]);
}

char *func_0016F918(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[27]);
}

char *func_0016F948(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[28]);
}

char *func_0016F978(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[29]);
}

char *func_0016F9A8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[30]);
}

char *func_0016F9D8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[31]);
}

char *func_0016FA08(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[32]);
}

char *func_0016FA38(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[33]);
}

char *func_0016FA68(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[34]);
}

char *func_0016FA98(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[35]);
}

char *func_0016FAC8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[36]);
}

char *func_0016FAF8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[37]);
}

char *func_0016FB28(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[38]);
}

char *func_0016FB58(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[39]);
}

char *func_0016FB88(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[40]);
}

char *func_0016FBB8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[41]);
}

char *func_0016FBE8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[42]);
}

char *func_0016FC18(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[43]);
}

char *func_0016FC48(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[44]);
}

char *func_0016FC78(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[45]);
}

char *func_0016FCA8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[46]);
}

char *func_0016FCD8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[47]);
}

char *func_0016FD08(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[48]);
}

char *func_0016FD38(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[49]);
}

char *func_0016FD68(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[50]);
}

char *func_0016FD98(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[51]);
}

char *func_0016FDC8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[52]);
}

char *func_0016FDF8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[53]);
}

char *func_0016FE28(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[54]);
}

char *func_0016FE58(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[55]);
}

char *func_0016FE88(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[56]);
}

char *func_0016FEB8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[57]);
}

char *func_0016FEE8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[58]);
}

char *func_0016FF18(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[59]);
}

char *func_0016FF48(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[60]);
}

char *func_0016FF78(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[61]);
}

char *func_0016FFA8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[62]);
}

char *func_0016FFD8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[63]);
}

char *func_00170008(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[64]);
}

char *func_00170038(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[65]);
}

char *func_00170068(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[66]);
}

char *func_00170098(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[67]);
}

char *func_001700C8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[68]);
}

char *func_001700F8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[69]);
}

char *func_00170128(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[70]);
}

char *func_00170158(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[71]);
}

char *func_00170188(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[72]);
}

char *func_001701B8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[73]);
}

char *func_001701E8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[74]);
}

char *func_00170218(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[75]);
}

char *func_00170248(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[76]);
}

char *func_00170278(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[77]);
}

char *func_001702A8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[78]);
}

char *func_001702D8(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[79]);
}

char *func_00170308(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[80]);
}

char *func_00170338(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[81]);
}

char *func_00170368(int i) {
    return func_0016F368(D_0030E0C0[i].hB2[82]);
}
