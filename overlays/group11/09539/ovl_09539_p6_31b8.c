/* EE Battle-Effect Overlay: group 0x11, file 09539 (shared by 41 P6 overlays)
 * .text: 0x01B031B8..0x01B03274 (1 function, 188B).
 */
#include "p6_overlay.h"

extern int D_01B00044;
extern int D_01B00568;

extern int func_0029B830(int);
extern int func_002D0570(int);
extern int func_00294578(int);
extern void func_001CDC58(int, int);

int func_01B031B8(void)
{
    for (;;) {
        switch (D_01B00044) {
        case 0:
            if (func_0029B830(2) == 0) {
                D_01B00044++;
                continue;
            }
            return 0;
        case 1:
            if (func_002D0570(2) == 0) {
                D_01B00044++;
                continue;
            }
            return 0;
        case 2:
            if (func_00294578(2) == 0) {
                func_001CDC58(D_01B00568, 0);
                D_01B00044 = 4;
            }
            return 0;
        default:
            return 0;
        }
    }
}
