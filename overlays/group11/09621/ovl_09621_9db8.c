#include "common.h"

extern int D_01B00044;
extern int D_01B007B8;
extern u8 D_01B00CE0;
extern u8 D_01B00B98[];
extern u8 D_01B00BD0[];

extern int func_0029B830(int);
extern int func_002D0570(int);
extern int func_00294578(int);
extern void func_001CDC58(int, int);
extern void func_002B37A0(void);
extern void func_01B16F40(void *);
extern void func_01B0D000(void *);

typedef struct {
    void *node;
    u8 flags;
    u8 tag;
    u8 pad06[10];
} Msg9DB8;

int func_01B09DB8(void)
{
    Msg9DB8 m0;
    void *m1[4];

loop:
    switch (D_01B00044) {
    case 0:
        if (func_0029B830(2) == 0) {
            D_01B00044++;
            goto loop;
        }
        return 0;
    case 1:
        if (func_002D0570(2) != 0) {
            return 0;
        }
        D_01B00044++;
        goto loop;
    case 2:
        if (func_00294578(2) != 0) {
            return 0;
        }
        func_001CDC58(D_01B007B8, 0);
        D_01B00044 = 4;
        break;
    }

    if (D_01B00044 < 4) {
        return 0;
    }

    func_002B37A0();
    D_01B00CE0++;
    m1[0] = D_01B00B98;
    func_01B16F40(m1);

    m0.node = D_01B00BD0;
    m0.tag = D_01B00CE0;
    func_01B0D000(&m0);

    return 0;
}
