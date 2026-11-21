/* EE Battle-Effect Overlay: group 0x11, file 09089
 * .text: 0x01B01AC0..0x01B01BE8 (1 function).
 */
#include "common.h"

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern void *D_006A3BCC;
extern int D_01B005E0;
extern void *D_01B005E8;
extern void *D_01B005EC;
extern u8 D_01B005F8[];
extern int D_01B008B0;
extern u8 D_01B00908[];
extern u8 D_01B00A18[];
extern u8 D_01B00B28[];
extern u8 D_01B00C38[];
extern char D_01B02C30[];

extern int func_01B020A0(const char *, int);
extern int func_01B02208(void *);
extern int func_01B02360(void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(void *);

int func_01B01AC0(void)
{
    if (D_01B005E0 == 0) {
        return 0;
    }
    D_006A3924 = D_01B005F8;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B005E8;
    if (func_0014AA50(0) != 0) {
        func_01B02208(D_01B00A18);
        func_01B02208(D_01B00C38);
    }
    if (func_0014AA50(4) != 0) {
        func_01B02208(D_01B00908);
    }
    if (func_0014AA50(1) != 0) {
        func_01B02360(D_01B00A18);
    }
    if (func_0014AA50(2) != 0) {
        func_01B02208(D_01B00B28);
    }
    if (func_0014AA50(3) != 0) {
        func_01B02360(D_01B00B28);
        func_01B02360(D_01B00C38);
        func_01B020A0(D_01B02C30, D_01B008B0);
        func_001CDDD8(D_01B005EC);
        return 1;
    }
    D_01B008B0++;
    return 1;
}

int func_01B01BE8(void)
{
    return 1;
}

int func_01B01BF0(void)
{
    return 1;
}
