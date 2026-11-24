#include "common.h"

typedef struct {
    u8 pad00[0x260];
    u8 f260[0x20];
    u8 f280[0x96C];
    int fBEC;
    int fBF0;
    int fBF4;
    int fBF8;
    u8 padBFC[0x134];
    float fD30;
    int fD34;
    int fD38;
} Big9098;

typedef struct {
    u8 pad00[0x96C];
    int f96C;
    int f970;
    int f974;
    int f978;
} Sub280;

typedef struct {
    u8 pad00[0x14];
    int f14;
} State9078;

extern Big9098 *D_01B09098;
extern State9078 D_01B09078;
extern int D_01B004A0[];
extern int D_01B004B0[];

extern void func_01B02A30(int, void *, int);
extern float func_01B02908(int);
extern int func_001AF358(void);
extern int func_01B02EA8(int);
extern void func_01B00EE0(int);

void func_01B00D88(void)
{
    Big9098 *s2 = D_01B09098;
    Sub280 *s1 = (Sub280 *)s2->f280;
    register int id __asm__("$6");
    register int idx __asm__("$5");
    int *p;
    int res;

    func_01B02A30(-1, s2->f260, 0);
    s2->fD30 = func_01B02908(-1);
    id = func_001AF358();
    __asm__("" : "+r"(id) : : "memory");

    res = -1;
    idx = 0;
    {
        int *p0;
        register int v __asm__("$3") = D_01B004A0[0];
        p0 = D_01B004A0;
        while (v != -1) {
            if (v == id) {
                res = idx;
                break;
            }
            p0++;
            v = *p0;
            idx++;
        }
    }
    s1->f96C = res;
    if (res == -1) {
        id = func_01B02EA8(0);
        __asm__("" : "+r"(id) : : "memory");
        idx = 0;
        {
            int *p0;
            register int v __asm__("$3") = D_01B004B0[0];
            p0 = D_01B004B0;
            while (v != -1) {
                if (v == id) {
                    res = idx;
                    break;
                }
                p0++;
                v = *p0;
                idx++;
            }
        }
        if (res != -1) {
            s1->f970 = res;
            s1->f96C = -2;
        }
    }

    s1->f974 = 0;
    s1->f978 = 0;
    func_01B00EE0(-1);
    s2->fD34 = -1;
    s2->fD38 = 0;
    D_01B09078.f14 = 1;
}
