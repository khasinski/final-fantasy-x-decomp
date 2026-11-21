/* EE Battle-Effect Overlay: group 0x11, file 09089
 * .text: 0x01B01008..0x01B01058 (destroy callback, 1 function).
 * Also covers identical destroy callbacks at 0x01B011E8, 0x01B014E0, 0x01B01808.
 */
#include "common.h"

extern void *D_006A3924;
extern u8 D_01B005F8[];
extern int D_01B008B0;
extern char D_01B02B78[];

extern int func_01B020A0(const char *, int);
extern void func_00267530(void *);

int func_01B01008(void *o)
{
    func_01B020A0(D_01B02B78, D_01B008B0);
    D_006A3924 = D_01B005F8;
    func_00267530(o);
    return 1;
}
