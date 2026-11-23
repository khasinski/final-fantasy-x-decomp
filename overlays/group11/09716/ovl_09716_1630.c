#include "common.h"

typedef struct {
    u8 pad000[0x260];
    int w260;           /* 0x260 */
    float f264;         /* 0x264 */
    int w268;           /* 0x268 */
    int w26C;           /* 0x26C */
    u8 sub270[0x340];   /* 0x270 */
    int w5B0;           /* 0x5B0 */
    u8 pad5B4[0x1C];
    int w5D0;           /* 0x5D0 */
} Obj9716;

extern int D_01B07E00;
extern u8 D_01B07E08[];
extern int D_01B07E4C;
extern u8 D_01B07E50[];
extern u8 D_01B07EB0[];
extern int D_01B07EC4;
extern Obj9716 *D_01B07ED0;

extern int func_01B07AB0(void *);
extern int func_01B03D30(void *);
extern void func_01B048D0(void *);
extern int func_01B04C90(void *, int);
extern void func_01B01778(void);
extern void func_001CDDD8(int);
extern float func_01B02168(int);
extern void func_01B02290(int, void *, int);

void func_01B01630(void *a0)
{
    Obj9716 *s1 = D_01B07ED0;
    int s0 = func_01B07AB0(D_01B07E50);
    func_01B03D30(D_01B07EB0);
    if (s0 == 1) {
        s1->w5D0 = 1;
        func_01B048D0(a0);
    }
}

void func_01B016A8(void)
{
    Obj9716 *s0 = D_01B07ED0;
    if (func_01B04C90(D_01B07E08, D_01B07E4C) == 1 && s0->w5D0 == 1) {
        func_01B01778();
        func_001CDDD8(D_01B07E00);
    }
}

void func_01B01718(void)
{
    Obj9716 *s0 = D_01B07ED0;
    s0->w260 = 0;
    s0->f264 = func_01B02168(-1);
    s0->w268 = 0;
    s0->w26C = 0;
    func_01B02290(-1, s0->sub270, 3);
    s0->w5B0 = 0;
    s0->w5D0 = 0;
    D_01B07EC4 = 1;
}
