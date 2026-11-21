/* Shared debug GIF/DMA line & box drawing helpers (Sub-family A: 9541, 9685, 9710, 9713, 9734, 9525, 9418).
 * .text in 9541: 0x01B01958..0x01B01F98 (9 functions).
 */
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

typedef struct ClipVert {
    s32 x, y, z, w;
    float f10;
    u8 clipped;
    u8 pad15[0xB];
} __attribute__((aligned(16))) ClipVert;

extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern u64 D_006F2CE0[];
extern int D_01B005C8;
extern float D_01B005D0[3];
extern DbgPkt *D_01B03460[2];

extern void *func_002B3888(int);
extern void func_002B39C0(int);
extern int func_002DA610(int, int);
extern void func_002DBA28(void *, void *);
extern void func_002DBF78(void *, int, int);
extern void func_002DCE08(float *, void *, float *);
extern void func_002DCE38(float *, void *, void *);
extern void func_002DCFD8(float *, float *);
extern int func_002DD9B0(float *);

void func_01B01958(void *p)
{
    while (func_002DA610(1, 0) & 0x10) {}
    func_002DBF78((void *)0x1000A000, 0, 0);
    func_002DBA28((void *)0x1000A000, (void *)((u32)p | 0x80000000));
}

void func_01B019B8(void)
{
    D_01B03460[0] = (DbgPkt *)func_002B3888(0x90);
    D_01B03460[1] = (DbgPkt *)func_002B3888(0x90);
}

void func_01B019F8(void)
{
    func_002B39C0(0x90);
    func_002B39C0(0x90);
}

void func_01B01A18(u32 x0, u32 y0, u32 z0, u32 x1, u32 y1, u32 z1, u64 rgba)
{
    DbgPkt *pkt;

    D_01B005C8 ^= 1;
    pkt = D_01B03460[D_01B005C8];
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
    func_01B01958(pkt);
}

void func_01B01B28(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba)
{
    DbgPkt *pkt;

    D_01B005C8 ^= 1;
    pkt = D_01B03460[D_01B005C8];
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
    func_01B01958(pkt);
}

void func_01B01C30(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba)
{
    func_01B019B8();
    func_01B01B28((x0 << 4) + 0x8000, (y0 << 4) + 0x8000, (x1 << 4) + 0x8000, (y1 << 4) + 0x8000, rgba);
    func_01B019F8();
}

void func_01B01CB0(s32 *dst, float *src)
{
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2    $vf8, 0(%1)\n\t"
        "vftoi4.xy $vf7, $vf8\n\t"
        "vftoi0.zw $vf7, $vf8\n\t"
        "sqc2    $vf7, 0(%0)\n\t"
        ".set reorder\n\t"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

void func_01B01CC8(void *mtx, float *p0, float *p1, u64 rgba)
{
    float cur[4];
    float step[4];
    float proj[4];
    ClipVert vcur;
    ClipVert vprev;
    int i;

    step[0] = (p1[0] - p0[0]) * 0.125f;
    step[1] = (p1[1] - p0[1]) * 0.125f;
    step[2] = (p1[2] - p0[2]) * 0.125f;
    cur[0] = p0[0];
    cur[1] = p0[1];
    cur[2] = p0[2];
    cur[3] = 1.0f;
    func_01B019B8();
    i = 9;
    do {
        /* DEBT(FAKE): pin proj[3] to $f12 to match original ee-gcc float reg allocation */
        register float w __asm__("$f12");
        func_002DCE08(proj, mtx, cur);
        w = proj[3];
        if (w > 0.0f) {
            func_002DCFD8(proj, proj);
            if (func_002DD9B0(proj) == 0) {
                func_01B01CB0(&vcur.x, proj);
                vcur.f10 = proj[3];
                vcur.clipped = 0;
            } else {
                vcur.clipped = 1;
            }
        } else {
            vcur.clipped = 1;
        }
        if (i != 9 && vcur.clipped == 0 && vprev.clipped == 0) {
            func_01B01A18(vprev.x, vprev.y, vprev.z, vcur.x, vcur.y, vcur.z, rgba);
        }
        i--;
        vprev = vcur;
        cur[0] += step[0];
        cur[1] += step[1];
        cur[2] += step[2];
    } while (i != 0);
    func_01B019F8();
}

void func_01B01E78(void)
{
    float pts[6][4];
    float mtx[16];

    pts[0][0] = pts[1][0] = pts[2][0] = pts[3][0] = pts[4][0] = pts[5][0] = D_01B005D0[0];
    pts[0][1] = pts[1][1] = pts[2][1] = pts[3][1] = pts[4][1] = pts[5][1] = D_01B005D0[1];
    pts[0][2] = pts[1][2] = pts[2][2] = pts[3][2] = pts[4][2] = pts[5][2] = D_01B005D0[2];
    pts[0][0] -= 50.0f;
    pts[1][0] += 50.0f;
    pts[2][1] -= 50.0f;
    pts[3][1] += 50.0f;
    pts[4][2] -= 50.0f;
    pts[5][2] += 50.0f;
    func_002DCE38(mtx, D_006A3A70, D_006A3970);
    func_01B01CC8(mtx, pts[0], pts[1], 0x3F800000FF8080FFULL);
    func_01B01CC8(mtx, pts[2], pts[3], 0x3F800000FF80FF80ULL);
    func_01B01CC8(mtx, pts[4], pts[5], 0x3F800000FF80FFFFULL);
}
