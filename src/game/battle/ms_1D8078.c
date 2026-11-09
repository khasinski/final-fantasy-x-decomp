/* tu_202 0x1d8078-0x1d8c28: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"

void MsNumberInit(void) {
    D_00662D1C = 0;
}

void MsNumberGetMem(void) {
    if (D_00662D1C == 0) {
        D_00662D1C = (s32)user_malloc(0xA00, 5, D_0056F6A8, -1); /* DEBT(TYPE): handle kept as int */
        MsStructClear((void *)D_00662D1C, 0xA00);
        D_00662D20 = 0;
        D_00662D24 = &D_00662D20;
    }
}

void MsNumberFreeMem(void) {
    if (D_00662D1C != 0) {
        func_0011D590(D_00662D1C, 5);
        D_00662D1C = 0;
    }
}

void func_001D8128(int a, int b, int *outa, int *outb)
{
    if (outa != 0) {
        *outa = a / 16 - 0x700;
    }
    if (outb != 0) {
        *outb = b / 16 - 0x730;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8078", MsCalcCursorPos);

int func_001D83C8(int v, u8 **out) {
    int n = 0;
    if (v >= 0) {
        do {
            D_00662D10[n++] = v % 10;
            v /= 10;
        } while (v != 0 && n < 9);
    }
    if (out != 0) {
        *out = D_00662D10;
    }
    return n;
}

void MsNumberCalcProcess(void) {
    int c1;
    BtlEvt *e;
    int total;
    BtlEvt **prev;
    int c2;

    prev = (BtlEvt **)&D_00662D20;
    c1 = 0;
    e = (BtlEvt *)D_00662D20;
    c2 = 0;
    total = 0;
    while (e != 0) {
        s8 v6;
        if (e->b5 > 0) {
            e->b5--;
        }
        v6 = ++e->b6;
        if (e->b7 < v6) {
            e->b0 = 0;
            *prev = e->next;
        } else {
            prev = &e->next;
            switch (e->b0 & 0x7F) {
            case 1:
                c1++;
            case 2:
                c2++;
                break;
            }
            total++;
        }
        e = e->next;
    }
    D_00662D24 = (s32 *)prev;
    D_003172F0.f2103 = c1;
    D_003172F0.f2104 = c2;
    D_003172F0.f2105 = total;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8078", MsNumberDrawProcess);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D8078", MsNumberRegist);

int func_001D8B98(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
    BtlEvt *e = (BtlEvt *)D_00662D1C; /* DEBT(CAST): pool handle kept as int */
    int i;
    for (i = 0; i < 0x80; i++, e++) {
        if (e->b0 == 0) {
            *D_00662D24 = (s32)e; /* DEBT(CAST): list links kept as int */
            e->b0 = p9;
            e->b1 = p8;
            e->b2 = p0;
            e->b3 = p1;
            e->b4 = p2;
            e->b5 = p1 + 1;
            e->b6 = 0;
            e->b7 = p7;
            e->h8 = p3;
            e->hA = p4;
            e->bC = p5;
            e->bD = p6;
            D_00662D24 = (s32 *)&e->next;
            e->next = 0;
            return 1;
        }
    }
    return 0;
}
