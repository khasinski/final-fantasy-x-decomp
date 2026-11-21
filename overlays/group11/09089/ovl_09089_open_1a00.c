/* EE Battle-Effect Overlay: group 0x11, file 09089
 * .text: 0x01B01A00..0x01B01ABC (2 functions).
 */
#include "common.h"

extern int D_01B005D8;
extern int D_01B005DC;
extern int D_01B005E0;
extern void *D_01B005EC;

extern int func_00116068(void);
extern int func_001CDAF8(void *);
extern void func_001CDC58(void *, int);
extern int func_0029B830(int);

int func_01B01A00(void)
{
    return 1;
}

int func_01B01A08(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B005D8 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B005D8++;
    }
    if (D_01B005DC == 0) {
        D_01B005DC = 1;
        func_001CDC58(D_01B005EC, 0);
    }
    if (D_01B005E0 == 0) {
        if (func_001CDAF8(D_01B005EC) > 0) {
            return ++D_01B005E0;
        }
        return 1;
    }
    return D_01B005E0;
}
