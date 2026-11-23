/* EE Battle-Effect Overlay: group 0x11, file 09396 (0x01B01030..0x01B01374)
 * .text: 2 functions (836 bytes)
 */
#include "common.h"

typedef unsigned long u64;

typedef union {
    u_long128 q;
    u64 d[2];
    u32 w[4];
} SprQword;

extern u8 *D_01B07B68;
extern u8 *D_01B07B6C;
extern u64 D_006F2CE0[];

void func_01B00F20(void *a0, float *a1);
void func_002DA610(int a0, int a1);
void func_002DA928(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void func_002F8660(int a0);
void func_002DAC50(void *a0, void *a1);
void *func_002DB6D8(int a0);
void func_002DBA28(void *a0, void *a1);
void func_01B041A8(void *a0);

void func_01B01030(u8 *a0)
{
    u8 buf[0x60];
    void *ch;
    SprQword *p;

    func_01B00F20(a0 + 0x80, (float *)(a0 + 0xD0));
    func_002DA610(0, 0);
    func_002DA928(buf, 0x1A00, 8, 10, 0, 0, 0x200, 0x1A0);
    func_002F8660(0);
    func_002DAC50(buf, D_01B07B6C);
    func_002DA610(0, 0);
    ch = func_002DB6D8(2);

    p = (SprQword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x70000002;
    p++;
    p->q = 0;
    p->d[0] = 0x1000000000008001ULL;
    p->d[1] = 0x0EULL;
    p++;
    p->d[0] = 0;
    p->d[1] = 0x3FULL;
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}

void func_01B01110(void *a0)
{
    u8 *w = D_01B07B68;
    void *ch;
    SprQword *p;
    int a;

    if (*(int *)(w + 0xC04) <= 0) {
        if (*(int *)(w + 0xC08) <= 0) {
            func_01B041A8(a0);
            return;
        }
        *(int *)(w + 0xC08) -= 1;
    } else {
        *(int *)(w + 0xC04) -= 1;
    }

    ch = func_002DB6D8(2);
    p = (SprQword *)0x70000000;
    p->q = 0;
    p->w[0] = 0x7000000D;
    p++;
    p->q = 0;
    p->d[0] = 0x1000000000008003ULL;
    p->d[1] = 0x0EULL;
    p++;
    p->d[0] = 0x0005000DULL;
    p->d[1] = 0x47ULL;
    p++;
    p->d[0] = 0x31000108ULL;
    p->d[1] = 0x4EULL;
    p++;
    p->d[0] = 0x0000008000000048ULL;
    p->d[1] = 0x42ULL;
    p++;
    p->q = 0;
    p->d[0] = 0x5022400000008001ULL;
    p->d[1] = 0x00055551ULL;
    p++;
    {
        int c = 0xFF;
        a = (*(int *)(w + 0xC08) * c) / 0x3C;
        p->w[0] = c;
        p->w[1] = c;
        p->w[2] = c;
        p->w[3] = a;
    }
    p++;
    p->w[0] = 0x6FF8; p->w[1] = 0x72F8; p->w[2] = 0x300000; p->w[3] = 0;
    p++;
    p->w[0] = 0x8FF8; p->w[1] = 0x72F8; p->w[2] = 0x300000; p->w[3] = 0;
    p++;
    p->w[0] = 0x6FF8; p->w[1] = 0x8CF8; p->w[2] = 0x300000; p->w[3] = 0;
    p++;
    p->w[0] = 0x8FF8; p->w[1] = 0x8CF8; p->w[2] = 0x300000; p->w[3] = 0;
    p++;
    p->q = 0;
    p->d[0] = 0x1000000000008002ULL;
    p->d[1] = 0x0EULL;
    p++;
    p->d[0] = D_006F2CE0[12];
    p->d[1] = 0x47ULL;
    p++;
    p->d[0] = D_006F2CE0[6];
    p->d[1] = 0x4EULL;
    func_002DBA28(ch, (void *)0xF0000000);
    func_002DA610(0, 0);
}
