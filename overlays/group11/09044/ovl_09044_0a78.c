#include "common.h"

typedef struct HeapMgrV {
    u8 pad00[0x20];
    int w20;
    void *tbl;
    char *p28;
} HeapMgrV;

typedef struct Slot80 {
    u8 pad00[0x1E];
    u16 h1E;
    u8 pad20[0x60];
} Slot80;

typedef struct V6HeapOwner {
    u8 pad00[0xBB];
    u8 bBB;
    Slot80 *slot;
} V6HeapOwner;

extern HeapMgrV *D_006A3924;
extern void *D_01B09BB0[64];
extern int D_01B09DB0[64];
extern Slot80 D_01B09EB0[64];
extern HeapMgrV D_01B0BEB0;

extern void _pppAllFreePObject(Slot80 *s);

void func_01B00A78(int a)
{
    int i;
    int j;

    D_006A3924 = &D_01B0BEB0;
    for (i = 63; i >= 0; i--) {
        D_01B09BB0[i] = 0;
    }
    for (j = 0; j < 64; j++) {
        if (D_01B09DB0[j] != 0) {
            D_01B09DB0[j] = 0;
            D_006A3924 = &D_01B0BEB0;
            _pppAllFreePObject(&D_01B09EB0[j]);
        }
    }
}

int func_01B00B38(V6HeapOwner *o)
{
    Slot80 *s;

    if (o->bBB == 3) {
        s = o->slot;
        if (s != 0) {
            HeapMgrV *m = &D_01B0BEB0;

            D_006A3924 = m;
            _pppAllFreePObject(s);
            D_01B09DB0[s->h1E] = 0;
            o->slot = 0;
            o->bBB = 0;
        }
    }
}
