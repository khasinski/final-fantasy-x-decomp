/* EE Battle-Effect Overlay: group 0x11, file 09685
 * .text: 0x01B02260..0x01B02458 (2 functions).
 */
#include "common.h"

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern void *D_006A3BCC;
extern int D_01B0044C;
extern int D_01B00450;
extern int D_01B00454;
extern void *D_01B0045C;
extern void *D_01B00460;
extern void *D_01B00464;
extern void *D_01B0046C;
extern u8 D_01B00478[];
extern int D_01B00E70;
extern void *D_01B00E74;
extern u8 D_01B00F98[];
extern u8 D_01B010A8[];
extern char D_01B04508[];
extern char D_01B04530[];

extern int func_01B02910(const char *, ...);
extern int func_01B032F8(void *);
extern int func_01B03450(void *);
extern int func_00116068(void);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern int func_001CDAF8(void *);
extern void func_001CDC58(void *, int);
extern void func_001CDDD8(void *);
extern int func_0029B830(int);
extern void func_002B2C50(int);
extern void func_002B2F20(void *);

int func_01B02260(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B0044C == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B0044C++;
    }
    if (D_01B00450 == 0) {
        D_01B00450 = 1;
        func_001CDC58(D_01B0046C, 0);
    }
    if (D_01B00454 == 0) {
        if (func_001CDAF8(D_01B0046C) > 0) {
            return ++D_01B00454;
        }
        return 1;
    }
    return D_01B00454;
}

int func_01B02318(void)
{
    if (D_01B00454 == 0) {
        return 0;
    }
    D_006A3924 = D_01B00478;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B0045C;
    D_01B00464 = D_01B00460;
    if (func_0014AA50(0xD) != 0) {
        func_01B03450(D_01B00F98);
        func_002B2F20(D_01B00E74);
        func_002B2C50(0);
        func_01B02910(D_01B04508);
        func_01B02910(D_01B04530, D_01B00E70);
        func_001CDDD8(D_01B0046C);
        return 1;
    }
    if (func_0014AA50(0xB) != 0) {
        func_01B032F8(D_01B010A8);
    }
    if (func_0014AA50(0xC) != 0) {
        func_01B03450(D_01B00F98);
        func_01B03450(D_01B010A8);
        func_002B2F20(D_01B00E74);
        func_002B2C50(0);
        func_01B02910(D_01B04530, D_01B00E70);
        func_001CDDD8(D_01B0046C);
        return 1;
    }
    D_01B00E70++;
    return 1;
}
