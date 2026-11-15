#include "common.h"

typedef struct HBlk {
    struct HBlk *next;
    struct HBlk *prev;
    int used;
    int pad;
} HBlk;

typedef struct HHead {
    HBlk *cur;
    HBlk *first;
    HBlk *last;
    int used;
} HHead;

typedef struct HeapCfg {
    u8 pad0[0x10];
    void **p10;
    int w14;
    void *tbl;
    char *p1C;
} HeapCfg;

typedef struct HeapMgrV {
    HHead main;
    HHead sub;
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
    u8 pad00[0x1A];
    u16 h1A;
    u8 pad1C[2];
    u8 b1E;
    u8 pad1F[0x9C];
    u8 bBB;
    Slot80 *slot;
    u8 padC0[0x10];
    union {
        HeapCfg *cfg;
    } u;
    u8 bD4;
} V6HeapOwner;

typedef struct OvlR6Obj {
    u8 pad00[0x0C];
    void *p0C;
    u8 pad10[0x40];
    void *vt50;
    int w54;
    int w58;
    u8 pad5C[0x44];
    int wA0;
    int wA4;
    u8 *pA8;
    int wAC;
    int wB0;
} OvlR6Obj;

typedef struct Oef2Res {
    u8 pad00[0x50];
    u16 h50;
} Oef2Res;

typedef struct W10Dual {
    u8 pad0[0x10];
    s8 mirror;
    s8 b11;
} W10Dual;

typedef struct HandlePool {
    int cur;
    Oef2Res *ovl;
} HandlePool;

typedef struct HwRegs2008250 {
    u8 pad00[0x40];
    u16 h40;
    u8 pad42[0x66];
    Oef2Res *wA8;
} HwRegs2008250;

extern int D_003F3944;
extern OvlR6Obj *D_0054D5E8[];
extern u16 D_00551C98;
extern u16 D_00551CA0;
extern u8 D_004F3FD0[];
extern u8 D_004F4010[];
extern HeapMgrV *D_006A3924;
extern HandlePool D_00703E20;
extern W10Dual D_00764990;
extern s8 D_007649A0;
extern HwRegs2008250 D_2008250;

extern u8 D_01B00000[];
extern void *D_01B005F8[];
extern char *D_01B00650[];
extern char D_01B0A538[];
extern char D_01B0A568[];
extern void *D_01B0A580[64];
extern void *D_01B0A680[64];
extern int D_01B0A780[64];
extern Slot80 D_01B0A880[64];
extern HeapMgrV D_01B0C880;

void func_00120108(char *fmt, ...);
void func_001A9EE0(void *a);
void func_001AACA0(void *a);
void _pppAllFreePObject(Slot80 *s);
void _pppStartPart(Slot80 *s, int a, void *b, int c);
int _pppInitData(void *c, void *d);
void pppInitEnv(HeapMgrV *m, int a, int b, int c);
int _pppRunPart(Slot80 *s, int b);
int func_00293CD8(u8 *p);
void func_00293D48(HeapMgrV *a, int b);
void func_00294CD8(int a, int b);
OvlR6Obj *opu_init(int a, void *b, Oef2Res *c, void *d, int e, int f, int g);
void opu_test_data_read(int a);
void func_002AC750(int a);
void func_002B22F8(int a, int b);
void op_oef2_set2(Oef2Res *a);
void *op_oef2_a_get(Oef2Res *a, int b, int c);
void func_002EA328(int a) __attribute__((noreturn));
void *func_002EF0D0(void *dst, int val, int size);
void func_206C3B8(int a);
void func_206C3F8(int a, int b, int c);

void func_01B00E80(int a);

void func_01B00828(OvlR6Obj *o);
void func_01B00950(void);
void func_01B009A0(void);
void func_01B009A8(void);
void func_01B00A58(void);
void func_01B00B58(void);
void func_01B00B60(void);
void func_01B00BC8(V6HeapOwner *o);
int func_01B00D60(V6HeapOwner *o);
void func_01B00E00(void);
void func_01B00E40(void);
void func_01B00E80(int a);
int func_01B00F40(V6HeapOwner *o);
void func_01B00FB8(Oef2Res *res);
void func_01B01060(OvlR6Obj *o);
void func_01B010C8(char *base, u16 *offs);
void func_01B011E0(void);
int func_01B011E8(void *target);
void func_01B01268(int a);
int func_01B01340(V6HeapOwner *o);
int func_01B01340(V6HeapOwner *o)
{
    HeapCfg *c;
    int i;

    c = o->u.cfg;
    D_01B0C880.w20 = c->w14;
    D_01B0C880.tbl = c->tbl;
    D_01B0C880.p28 = c->p1C;
    D_006A3924 = &D_01B0C880;
    i = func_01B011E8(o->u.cfg);
    if (i >= 0 && D_01B0A580[i] == 0) {
        D_01B0A580[i] = o->u.cfg;
        return _pppInitData(o->u.cfg, D_01B005F8[i]);
    }
}
