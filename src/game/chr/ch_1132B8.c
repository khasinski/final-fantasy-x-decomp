/* tu_019 0x1132b8-0x113938: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#define Ch_RomReadEventMGRP _hide_Ch_RomReadEventMGRP
#include "ffx/r0.h"
#undef Ch_RomReadEventMGRP
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

extern void *D_0057F5E8[];
extern char D_00569748[];
extern u8 D_00569750[];
extern char D_005697C0[];
extern s16 D_003038C0[];
extern s8 D_003038D0[];

void Ch_RomDataReadInit(void)
{
    char unused[0x20];
    int i;
    void **p;
    int size;
    void *buf;

    D_0078E498.f10(0x14);
    i = 0;
    p = D_0057F5E8;
    do {
        size = D_0078E498.f14(i);
        buf = user_malloc(size, 6, D_00569748, 0x19);
        *p = buf;
        func_0011BB08(buf, D_00569750, i);
        D_0078E498.f00(i, *p, 0, 0);
        i++;
        p++;
    } while (i < 7);
    D_0078E498.f08(0);
}

extern int (*D_0078E4A8)(int);

int func_001133A8(int id)
{
    int num = id & 0xFFF;
    int kind = (id >> 12) & 0xF;
    int idx = 0;
    int found = 0;
    s16 *tbl;
    int i;
    s16 *p;

    if (kind >= 8) {
        return -1;
    }
    tbl = (s16 *)D_0057F5E8[kind];
    i = 0;
    if (*tbl > 0) {
        do {
            if (tbl[i + 1] == num) {
                found = 1;
                break;
            }
            i++;
            idx += D_003038D0[0xF];
        } while (i < *tbl);
    }
    if (!found) {
        return -1;
    }
    D_0078E4A8(D_003038C0[kind]);
    return idx;
}

void Ch_RomReadChrCB(U0Args *p)
{
    Cache_Entry_NotYet(p->w14, p->wC, 0);
}

s32 func_00113480(void)
{
    return D_0078E4A0();
}

extern char D_00569760[];
extern char D_005697A8[];
void *func_0011D4B8(int size, int kind, const char *file, int line);
void Cache_Entry(int kind, int id, void *ptr);
char *ch_create_name(int id);
int ch_create_chrname(int id);

typedef struct ChReadReq {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    void *w10;
    s32 w14;
    s32 w18;
    s32 w1C;
} ChReadReq;

s32 Ch_DataRead(s32 id)
{
    ChReadReq req;
    char buf[0x40];
    s32 idx;
    s32 size;
    void *mem;
    char *sec;

    if ((u32)Cache_CheckYet(1, id) < 2) {
        return 0;
    }
    idx = func_001133A8(id);
    if (idx < 0 || (size = D_0078E498.f14(idx)) == 0) {
        return -1;
    }
    mem = func_0011D4B8(((size + 0x8F) & 0xFFFFFF80) - 0x10, 6, D_00569748, 0x60);
    func_002F0008(buf, D_00569760, ch_create_section(id), ch_create_name(id));
    func_0011BB08(mem, (u8 *)buf, -1);
    req.w14 = 1;
    req.wC = id;
    req.w10 = mem;
    D_0078E498.f00(idx, mem, Ch_RomReadChrCB, &req);
    Cache_Entry(1, id, mem);
    Cache_Entry_NotYet(1, id, 1);
    return 0;
}

s32 Ch_DataReadSync(s32 h)
{
    s32 value0;

    value0 = Cache_CheckYet(1, h);
    if (value0 == 2)
    {
        yiAssert(0, D_00569770, D_00569788, ch_create_name(h));
    }
    return value0;
}

s32 Ch_MgrpRead(int id, int grp)
{
    ChReadReq req;
    char buf[0x40];
    int key = (grp << 16) | id;
    int idx;
    int size;
    void *mem;

    if ((u32)Cache_CheckYet(2, key) < 2) {
        return 0;
    }
    idx = func_001133A8(id);
    if (idx < 0) {
        return -1;
    }
    idx = idx + grp + 1;
    size = D_0078E498.f14(idx);
    if (size == 0) {
        return -1;
    }
    if (size == 0x10) {
        return -1;
    }
    mem = func_0011D4B8(((size + 0x8F) & 0xFFFFFF80) - 0x10, 6, D_00569748, 0x8B);
    func_002F0008(buf, D_005697A8, ch_create_chrname(id), grp);
    func_0011BB08(mem, (u8 *)buf, -1);
    func_0011CFB8((int)mem, 3);
    req.w14 = 2;
    req.wC = key;
    req.w10 = mem;
    D_0078E498.f00(idx, mem, Ch_RomReadChrCB, &req);
    Cache_Entry(2, key, mem);
    Cache_Entry_NotYet(2, key, 1);
    return 0;
}

void func_00113810(V0Pair *p)
{
    func_00104F28(p->b, p->a);
}

s32 func_00113820(s32 a)
{
    return D_0078E518(0xC, a);
}

int Ch_RomReadEventMGRP(int file, int x)
{
    char buf[0x40];
    struct {
        u8 pad[0xC];
        int wC;
        int w10;
        u8 pad14[0xC];
    } req;
    int size;
    int mem;

    D_0078E498.f10(0xC);
    size = D_0078E498.f14(file);
    if (size == 0) {
        return 0;
    }
    if (size == 0x10) {
        return 0;
    }
    func_0011C348(0x40);
    mem = (int)user_malloc(size, 6, D_00569748, 0xB0);
    func_002F0008(buf, D_005697C0, x);
    func_0011BB08((void *)mem, (u8 *)buf, -1);
    func_0011CFB8(mem, 3);
    req.wC = x;
    req.w10 = mem;
    D_0078E498.f00(file, mem, func_00113810, &req);
    return mem;
}
