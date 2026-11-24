#include "common.h"

typedef struct Ovl09307Work {
    u8 pad00[0x18];
    s32 w18;
} Ovl09307Work;

typedef struct Ovl09307Entry {
    u8 pad00[0x54];
    s32 key;
    u8 pad58[0x48];
} Ovl09307Entry;

typedef struct Ovl09307Table {
    u8 pad00[0x20];
    Ovl09307Entry entries[8];
    s32 count;
} Ovl09307Table;

extern Ovl09307Entry *D_01B00694;
extern s32 D_01B00698;
extern s32 D_01B0069C;
extern u8 D_01B00A60[];
extern u8 D_01B00A78[];
extern Ovl09307Table D_01B00AC0;

s32 func_001B5560(s32);
void func_01B027F8(void *);
void func_01B04010(void *);
void func_01B0F188(void *);
void func_01B0F590(void *);

typedef struct {
    void *a;
    void *b;
    s32 c;
    s32 d;
    u8 e;
    u8 pad[3];
} Msg4010;

static __inline__ void call_01B0F188(void *a, void *b, void *c)
{
    void *m[3];
    m[0] = a;
    m[1] = b;
    m[2] = c;
    func_01B0F188(m);
}

static __inline__ void call_01B0F590(void *a, void *b)
{
    void *m[2];
    m[0] = a;
    m[1] = b;
    func_01B0F590(m);
}

static __inline__ void call_01B04010(void *a, void *b, s32 c, s32 d, u8 e)
{
    Msg4010 m;
    m.b = b;
    m.c = c;
    m.e = e;
    m.a = a;
    m.d = d;
    func_01B04010(&m);
}

void func_01B02E58(Ovl09307Work *a0)
{
    Ovl09307Table *tbl = &D_01B00AC0;
    s32 key;
    s32 n;
    s32 i;

    call_01B0F188(a0, func_01B027F8, a0);
    call_01B0F590(D_01B00A60, a0);
    call_01B04010(tbl, D_01B00A78, D_01B00698, 0, 1);

    key = func_001B5560(D_01B0069C);
    n = tbl->count;
    for (i = 0; i < n; i++) {
        if (tbl->entries[i].key == key) {
            D_01B00694 = &tbl->entries[i];
            break;
        }
    }
    a0->w18 = 0;
}
