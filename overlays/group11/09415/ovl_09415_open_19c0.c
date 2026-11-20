#include "common.h"

extern int D_01B00578;
extern void *D_01B0057C;
extern int D_01B00594;
extern void *D_01B005A0;
extern void *D_01B005A4;
extern void *D_01B005A8;
extern u8 D_01B005B8;
extern int D_01B00AF0;
extern char D_01B029C8[];
extern char D_01B029D8[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern void *D_006A3BCC;

extern int func_01B01CA8(char *, ...);
extern void func_01B01D00(char *, ...);
extern void func_01B01D40(int, int);
extern void func_01B02678(void *);
extern int func_01B027D0(void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(void *);

int func_01B019C0(void)
{
    if (D_01B00578 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B005B8;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B005A0;
    D_01B005A8 = D_01B005A4;
    if (func_0014AA50(0) != 0) {
        func_01B01D40(0x20, 0x1A);
        func_01B01D00(D_01B029C8, D_01B00AF0);
        func_01B02678(&D_01B00AF0);
    }
    if (func_0014AA50(1) != 0) {
        func_01B027D0(&D_01B00AF0);
        func_01B01CA8(D_01B029D8);
        func_001CDDD8(D_01B0057C);
        return 1;
    }
    D_01B00594++;
    return 1;
}
