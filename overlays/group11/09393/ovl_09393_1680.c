/* EE Battle-Effect Overlay: group 0x11, file 09393 (shared 0x01B01680..0x01B017A0, also in 09635)
 * Load base: 0x01B00000, .text: 0x01B01680..0x01B017A0 (1 function)
 */
#include "common.h"

extern u8 D_01B00740[];

int func_002EFD78(void);
void func_01B01348(void);
u8 *func_01B04260(void *fn);
void func_01B04428(void *p);

void func_01B01680(void)
{
    int n = *(int *)(D_01B00740 + 4) - 3;
    int i;
    u8 *t;

    for (i = 0; i < n; i++) {
        t = func_01B04260(func_01B01348);
        t[0x14] = i * 10 + (func_002EFD78() % 6);
        t[0x15] = i;
        t[0x16] = i;
        t[0x17] = i;
        t[0x18] = 1;
        func_01B04428(t);

        t = func_01B04260(func_01B01348);
        t[0x14] = i * 10 + 30 + (func_002EFD78() % 6);
        t[0x15] = i;
        t[0x16] = i;
        t[0x17] = i + 3;
        t[0x18] = 1;
        func_01B04428(t);
    }
}
