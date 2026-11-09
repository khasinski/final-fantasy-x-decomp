/* tu_076 0x143910-0x143bd0: low; unk_143910 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r1.h"

int func_00143910(int id, int b, int a) {
    Ent3D8 *e;
    int i;

    AtelGetBasicWork(id);
    e = D_0058E3D8->ent;
    for (i = 0; i < 4; i++, e++) {
        if (e->w0 == a && e->w4 == b) {
            return i;
        }
    }
    return -1;
}

int func_00143988(int id, int off) {
    char *p = func_0013CC00(AtelGetBasicWork(id), off);
    Ent3D8 *e = D_0058E3D8->ent;
    int i;

    for (i = 0; i < 4; i++, e++) {
        if (e->w0 >= 0 && e->w8 == (int)p) {
            return i;
        }
    }
    return -1;
}

void func_00143A00(int id, int slot, int a, int b, int c) {
    Actor *work;
    int prev;
    char *p;
    int max = 3;

    if (slot < 0) {
        slot = 0;
    }
    if (slot > max) {
        slot = max;
    }
    work = AtelGetBasicWork(id);
    prev = D_0058E3D8->ent[slot].w0;
    D_0058E3D8->ent[slot].w0 = c;
    D_0058E3D8->ent[slot].w4 = b;
    D_0058E3D8->ent[slot].bF = 0;
    if (c >= 0) {
        p = func_0013CC00(work, a);
        D_0058E3D8->ent[slot].w8 = (int)p;
        D_0058E3D8->ent[slot].bE = *p;
        *p = 0x40;
    } else if (prev >= 0) {
        p = (char *)D_0058E3D8->ent[slot].w8;
        *p = D_0058E3D8->ent[slot].bE;
    }
}

void func_00143AE8(int id, int slot) {
    func_00143A00(id, slot, 0, 0, -1);
}

int func_00143AF8(void) {
    int i;

    for (i = 0; i < 4; i++) {
        if (D_0058E3D8->ent[i].w0 < 0) {
            return i;
        }
    }
    return -1;
}

int func_00143B30(int id, int off) {
    int i = 0;
    char *p = func_0013CC00(AtelGetBasicWork(id), off);
    Ent3D8 *e;

    e = D_0058E3D8->ent;
    do {
        if (e->w0 >= 0 && e->w8 == (int)p) {
            func_00143AE8(id, i);
        }
        i++;
        e++;
    } while (i < 4);
    return -1;
}
