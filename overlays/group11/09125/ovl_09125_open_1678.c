/* EE Battle-Effect Overlay: group 0x11, file 09125
 * .text: 0x01B01678..0x01B01854 (2 functions).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x10];
    u32 flags;          /* 0x10 */
} TaskRoot;

extern int D_01B00044;
extern void *D_01B00048;
extern void *D_01B0004C;
extern int D_01B00464;
extern u8 D_01B00620[];
extern TaskRoot D_01B00830;
extern u8 D_01B00844;
extern P6Node D_01B00848;
extern P6Node D_01B00868;
extern u8 D_01B0B000[];

extern void *D_006A3924;

extern void func_01B011E8(void);
extern void func_01B01E20(void *);
extern void func_01B06B88(void *);
extern void func_01B0A0B8(void *);

extern int func_001CDAF8(int);
extern void func_001CDC58(int, int);
extern void func_001CDDD8(int);
extern int func_00294578(int);
extern int func_0029B830(int);
extern int func_002D0570(int);

int func_01B01678(void)
{
    while (1) {
        switch (D_01B00044) {
        case 0:
            if (func_0029B830(2) == 0) {
                D_01B00044++;
                break;
            }
            return 0;
        case 1:
            if (func_002D0570(2) == 0) {
                D_01B00044++;
                break;
            }
            return 0;
        case 2:
            if (func_00294578(2) != 0) {
                return 0;
            }
            func_001CDC58(D_01B00464, 1);
            D_01B00044++;
            break;
        case 3:
            if (func_001CDAF8(D_01B00464) > 0) {
                D_01B00044++;
            }
            return 0;
        default:
            return 0;
        }
    }
}

int func_01B01758(void)
{
    P6Iter it;
    void *root_msg[1];

    if (D_01B00044 >= 4) {
        D_006A3924 = D_01B0B000;
        D_01B00048 = D_01B0004C;
        func_01B011E8();
        D_01B00844++;
        root_msg[0] = &D_01B00830;
        func_01B0A0B8(root_msg);
        it.cur = (P6Node *)D_01B00620;
        it.mark = D_01B00844;
        func_01B06B88(&it);
        it.cur = &D_01B00848;
        it.mark = D_01B00844;
        func_01B01E20(&it);
        it.cur = &D_01B00868;
        it.mark = D_01B00844;
        func_01B01E20(&it);
        if ((D_01B00830.flags & 1) != 0 && D_01B00868.count == 0) {
            func_001CDDD8(D_01B00464);
            return 0;
        }
    }
    return 0;
}
