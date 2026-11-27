#include "common.h"

typedef unsigned long u64;

typedef struct DbgPkt {
    u_long128 dma;
    u64 q10;
    u64 q18;
    u64 q20;
    u64 q28;
    u64 q30;
    u64 q38;
    u64 q40;
    u64 q48;
    u32 w50;
    u32 w54;
    u32 w58;
    u32 w5c;
    u32 w60;
    u32 w64;
    u32 w68;
    u32 w6c;
    u64 q70;
    u64 q78;
    u64 q80;
    u64 q88;
} DbgPkt;

extern u64 D_006F2CE0[];
extern int D_01B00BE8;
extern DbgPkt *D_01B04A00[2];

extern void func_01B02F88(void *);

void func_01B03048(u32 x0, u32 y0, u32 z0, u32 x1, u32 y1, u32 z1, u64 rgba)
{
    DbgPkt *pkt;

    D_01B00BE8 ^= 1;
    pkt = D_01B04A00[D_01B00BE8];
    pkt->dma = (u_long128)0x70000008ULL;
    pkt->q10 = 0x1000000000000002ULL;
    pkt->q18 = 0xEULL;
    pkt->q20 = rgba;
    pkt->q28 = 0x1ULL;
    pkt->q30 = 0x31000108ULL;
    pkt->q38 = 0x4EULL;
    pkt->q40 = 0x2000C00000000001ULL;
    pkt->q48 = 0x55ULL;
    pkt->w50 = x0;
    pkt->w54 = y0;
    pkt->w58 = z0;
    pkt->w5c = 0;
    pkt->w60 = x1;
    pkt->w64 = y1;
    pkt->w68 = z1;
    pkt->w6c = 0;
    pkt->q70 = 0x1000000000008001ULL;
    pkt->q78 = 0xEULL;
    pkt->q80 = D_006F2CE0[6];
    pkt->q88 = D_006F2CE0[7];
    func_01B02F88(pkt);
}

void func_01B03158(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba)
{
    DbgPkt *pkt;

    D_01B00BE8 ^= 1;
    pkt = D_01B04A00[D_01B00BE8];
    pkt->dma = (u_long128)0x70000008ULL;
    pkt->q10 = 0x1000000000000002ULL;
    pkt->q18 = 0xEULL;
    pkt->q20 = rgba;
    pkt->q28 = 0x1ULL;
    pkt->q30 = 0x31000108ULL;
    pkt->q38 = 0x4EULL;
    pkt->q40 = 0x2000C00000000001ULL;
    pkt->q48 = 0x55ULL;
    pkt->w50 = x0;
    pkt->w54 = y0;
    pkt->w58 = 0xFFFF00;
    pkt->w5c = 0;
    pkt->w60 = x1;
    pkt->w64 = y1;
    pkt->w68 = 0xFFFF00;
    pkt->w6c = 0;
    pkt->q70 = 0x1000000000008001ULL;
    pkt->q78 = 0xEULL;
    pkt->q80 = D_006F2CE0[6];
    pkt->q88 = D_006F2CE0[7];
    func_01B02F88(pkt);
}
