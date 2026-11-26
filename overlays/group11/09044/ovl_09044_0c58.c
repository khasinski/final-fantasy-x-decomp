#include "common.h"

typedef struct HeapMgrV {
    u8 pad00[0x20];
    int w20;
} HeapMgrV;

typedef struct OvlR6Obj {
    u8 pad00[0xA0];
    int wA0;
    int wA4;
} OvlR6Obj;

extern s8 D_007649A0;
extern char *D_01B00260[];
extern HeapMgrV D_01B0BEB0;

extern void pppInitEnv(HeapMgrV *m, int a, int b, int c);
extern void func_00293D48(HeapMgrV *a, int b);

void func_01B00C58(OvlR6Obj *o)
{
    HeapMgrV *m = &D_01B0BEB0;

    if (m->w20 == 0) {
        pppInitEnv(m, 0, o->wA0, o->wA4);
        if (D_007649A0 != 0) {
            func_00293D48(m, 0x8003);
        }
    }
}

void func_01B00CC0(char *base, u16 *offs)
{
    char **dst = D_01B00260;

    if (offs[2] != 0) {
        dst[2] = base + (offs[2] + 0xA0);
    }
    if (offs[3] != 0) {
        dst[3] = base + (offs[3] + 0xA0);
    }
    if (offs[4] != 0) {
        dst[4] = base + (offs[4] + 0xA0);
    }
    if (offs[5] != 0) {
        dst[5] = base + (offs[5] + 0xA0);
    }
    if (offs[6] != 0) {
        dst[6] = base + (offs[6] + 0xA0);
    }
    if (offs[7] != 0) {
        dst[7] = base + (offs[7] + 0xA0);
    }
    if (offs[8] != 0) {
        dst[8] = base + (offs[8] + 0xA0);
    }
    if (offs[9] != 0) {
        dst[9] = base + (offs[9] + 0xA0);
    }
    if (offs[10] != 0) {
        dst[10] = base + (offs[10] + 0xA0);
    }
    if (offs[11] != 0) {
        dst[11] = base + (offs[11] + 0xA0);
    }
    if (offs[12] != 0) {
        dst[12] = base + (offs[12] + 0xA0);
    }
    if (offs[13] != 0) {
        dst[13] = base + (offs[13] + 0xA0);
    }
    if (offs[14] != 0) {
        dst[14] = base + (offs[14] + 0xA0);
    }
}
