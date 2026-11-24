#include "common.h"

typedef struct {
    u8 pad00[0x260];
    u8 f260[0x20];
    u8 f280[0x950];
    u8 padBD0[0x160];
    float fD30;
    int fD34;
    int fD38;
} Big9248;

typedef struct {
    u8 pad00[0x950];
    float f950;
    u8 pad954[0x1C];
    int f970;
    int f974;
    int f978;
    int f97C;
} Sub280;

typedef struct {
    u8 pad00[0x14];
    int f14;
} State9228;

extern Big9248 *D_01B09248;
extern State9228 D_01B09228;
extern int D_01B004A0[];
extern int D_01B004D8[];
extern int D_01B004E8[];

extern void func_01B02BD8(int, void *, int);
extern float func_01B02AB0(int);
extern int func_001AF358(void);
extern int func_01B03050(int);
extern void func_01B03F98(void *);
extern float func_01B06410(void *, void *);
extern void func_01B01038(int);

void func_01B00E28(void)
{
    float tmp[4];
    Big9248 *s1 = D_01B09248;
    Sub280 *s0 = (Sub280 *)s1->f280;
    /* DEBT(FAKE): regalloc/scheduling barriers for exact match */
    register int id __asm__("$6");
    register int idx __asm__("$5");
    int res;
    float radius;

    func_01B02BD8(-1, s1->f260, 0);
    s1->fD30 = func_01B02AB0(-1);
    id = func_001AF358();
    __asm__("" : "+r"(id));
    res = -1;
    idx = 0;
    __asm__("" : "+r"(id) : "r"(res) : "memory");
    {
        int *p0 = D_01B004A0;
        for (; *p0 != -1; p0++, idx++) {
            if (*p0 == id) {
                res = idx;
                break;
            }
        }
    }
    s0->f970 = res;
    radius = 100.0f;
    if (res == -1 && id != 0x02050000) {
        {
            int *p0 = D_01B004D8;
            register int v __asm__("$3") = D_01B004D8[0];
            while (v != -1) {
                if (v == id) {
                    radius = 50.0f;
                    break;
                }
                p0++;
                v = *p0;
            }
        }
        id = func_01B03050(0);
        res = -1;
        __asm__("" : "+r"(id) : "r"(res) : "$4", "$5", "memory");
        idx = 0;
        __asm__("" : "+r"(id) : : "$4");
        {
            register int *p0 __asm__("$4") = D_01B004E8;
            for (; *p0 != -1; p0++, idx++) {
                if (*p0 == id) {
                    res = idx;
                    break;
                }
            }
        }
        if (res != -1) {
            s0->f974 = res;
            s0->f970 = -2;
        }
        s0->f978 = 1;
    } else {
        s0->f978 = 0;
    }

    s0->f950 = radius;
    func_01B03F98(tmp);
    if (func_01B06410(tmp, s1->f260) > s0->f950) {
        s0->f978 = 0;
    }
    s0->f97C = 0;
    func_01B01038(-1);
    s1->fD34 = -1;
    s1->fD38 = 0;
    D_01B09228.f14 = 1;
}
