/* EE Battle-Effect Overlay: group 0x11, file 09439 (0x01B01450..0x01B015E8)
 * Shared across 5 open containers: 9438, 9439, 9440, 9441, 9494
 * .text: 3 functions (404 bytes)
 */
#include "common.h"

extern int D_01B081A8;
extern int D_01B081AC;
extern int D_01B081B0;
extern int D_01B081B4;
extern int D_01B081B8;
extern int D_01B080D0;

void func_01B00FF8(void);
int func_002B2E10(void *fn, int a1, int a2, int a3);
int func_01B01ED0(int a0);
void func_001E33E0(int a0, int a1);
int func_001E34E0(int a0);
void func_0011ABA8(int a0);
void func_002B2F18(int a0);
int func_001BBCF8(int a0, int a1);

void func_01B01450(void)
{
    D_01B081AC = 10;
    D_01B081B0 = 0;
    D_01B081B8 = 0;
    D_01B081A8 = func_002B2E10(func_01B00FF8, 0, 0, 0);
}

void func_01B014A0(u8 *a0)
{
    int ch = func_01B01ED0(-1);

    switch (D_01B081B0) {
    case 0:
        if (--D_01B081AC <= 0) {
            func_001E33E0(ch, 0);
            D_01B081B0 = 1;
        }
        break;
    case 1:
        if (func_001E34E0(ch) >= 0) {
            D_01B081AC = 0;
            D_01B081B0 = 2;
        }
        break;
    case 2:
        if (++D_01B081AC >= 10) {
            D_01B081B0 = 3;
            a0[0x56] = 1;
        }
        break;
    }
}

void func_01B01588(void)
{
    func_0011ABA8(0);
    func_002B2F18(D_01B081A8);
    D_01B081A8 = -1;
    D_01B081B4 = func_001BBCF8(D_01B080D0, func_01B01ED0(0));
}
