#include "common.h"

typedef struct CamSlot {
    u8 pad[0x184];
    s32 active;
    u8 pad2[0x8];
} CamSlot;

extern s32 D_01B0B420;
extern CamSlot D_01B0B430[4];
extern char D_01B0AE30[];
extern char D_01B0AE10[];
extern void func_002EF240(char *, ...);
extern void func_01B01510(int, char *, int);

static inline CamSlot *get_slot(int i)
{
    return &D_01B0B430[i];
}

int func_01B02528(int id)
{
    int old;

    if (id >= 4) {
        func_002EF240(D_01B0AE30, id);
        func_01B01510(15, D_01B0AE10, 384);
    }
    old = D_01B0B420;
    D_01B0B420 = id;
    get_slot(old)->active = 0;
    get_slot(id)->active = 1;
    return old;
}
