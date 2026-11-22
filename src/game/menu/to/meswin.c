/* tu_232 0x20cc98-0x20d058: low; meswin (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"

void *TODVDFileReadAuto(const char *name, int id)
{
    SysVt *vt = GetCD();
    int size;
    void *buf;

    vt->f10(name);
    size = vt->f14(id);
    if (size == 0) {
        return 0;
    }
    buf = user_malloc(size, 2, D_00570A38, 0xC67);
    if (buf == 0) {
        return 0;
    }
    func_0020CC20(name, id, buf);
    return buf;
}

void func_0020CD30(int a, int b, int c)
{
    D_0068F420 = GetCD();
    D_0068F420->f10(a);
    if (D_0068F420->f14(b) != 0) {
        D_0068F420->f0(b, c, 0, 0);
    }
}

int func_0020CDB8(void)
{
    return D_0068F420->f8(1);
}

void func_0020CDE0(int id, int dbp, int dpsm, int dsax, int dsay, int rrw, int rrh)
{
    void *dma = func_002DB6D8(2);
    SysVt *vt = GetCD();
    int size;
    Qword *pkt;
    int dbw;
    int qwc;

    vt->f10(0x12);
    size = vt->f14(id);
    pkt = (Qword *)user_malloc(size + 0x70, 2, D_00570A38, 0xCD5);
    if (pkt == 0) {
        return;
    }
    dbw = rrw / 64;
    if (dbw == 0) {
        dbw = 1;
    }
    qwc = size / 16;
    pkt[0].ul128 = 0;
    pkt[0].ui32[0] = (qwc + 6) | 0x70000000;
    pkt[1].ul64[0] = 0x1000000000000004UL;
    pkt[1].ul64[1] = 0xE;
    pkt[2].ul64[0] = ((u64)dbp << 32) | ((u64)dbw << 48) | ((u64)dpsm << 56);
    pkt[2].ul64[1] = 0x50;
    pkt[3].ul64[0] = ((u64)dsax << 32) | ((u64)dsay << 48);
    pkt[3].ul64[1] = 0x51;
    pkt[4].ul64[0] = (u64)rrw | ((u64)rrh << 32);
    pkt[4].ul64[1] = 0x52;
    pkt[5].ul64[0] = 0;
    pkt[5].ul64[1] = 0x53;
    pkt[6].ul64[0] = (qwc | 0x8000) | 0x0800000000000000UL;
    pkt[6].ul64[1] = 0x54;
    vt->f0(id, &pkt[7], 0, 0);
    vt->f8(0);
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DBA28(dma, pkt);
    func_002DA610(0, 0);
    func_0011D590(pkt, 2);
}

int func_0020D000(int a)
{
    D_0078E498.f10(0x12);
    return D_0078E498.f14(a);
}

void *func_0020D048(void)
{
    return &D_00570A48;
}
