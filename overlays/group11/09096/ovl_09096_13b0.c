#include "common.h"

typedef struct {
    u8 pad00[0x54];
    int w54;
} Obj54E0;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task13B0;

extern int D_01B001E8;
extern int D_01B00040[];
extern int D_01B00060[];
extern u8 D_01B00088[];
extern u8 D_01B054A8[];
extern u8 D_01B054D0[];
extern Obj54E0 D_01B054E0;
extern void *D_01B05540;
extern int D_01B05544;
extern int D_01B05548;
extern int D_01B0554C;
extern int D_01B05550;
extern u8 D_01B0B5D0[];
extern u8 D_01B0B780[];

extern int func_01B016B0(void);
extern void func_01B01D58(int, void *, int);
extern void func_01B016D0(void);
extern void func_01B02DF0(int, int);
extern void func_01B05338(Obj54E0 *, void *, int *, int);
extern void func_01B03740(int, void *, void *);
extern Task13B0 *func_01B04318(void (*)(void));
extern void func_01B044E0(Task13B0 *);
extern void func_01B01668(void);
extern void func_01B014E0(void);

int ovl_09096_13b0(void)
{
    int flag;
    int idx;
    int val;
    Task13B0 *t;

    D_01B05540 = D_01B0B780;
    flag = (D_01B001E8 >> 11) & 1;
    D_01B05550 = flag;
    idx = func_01B016B0();
    D_01B05544 = 0;
    val = D_01B00040[idx];
    D_01B05548 = val;
    if (flag == 1) {
        func_01B01D58(0, D_01B054D0, 0);
        func_01B016D0();
        func_01B02DF0(0, 1);
        D_01B00060[1] = D_01B05548;
        func_01B05338(&D_01B054E0, D_01B0B5D0, D_01B00060, 1);
        D_01B054E0.w54 = 0;
    } else {
        D_01B05548 = val + 0xF;
    }
    D_01B0554C = 0;
    func_01B03740(-1, D_01B054A8, D_01B00088);
    t = func_01B04318(func_01B01668);
    t->b18 = 1;
    func_01B044E0(t);
    func_01B044E0(func_01B04318(func_01B014E0));
    return 0;
}
