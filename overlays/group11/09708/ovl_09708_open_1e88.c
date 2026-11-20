#include "common.h"

extern int D_01B0065C;
extern void *D_01B00664;
extern void *D_01B00668;
extern u8 D_01B00678;
extern int D_01B00C30;
extern u8 D_01B00C40;
extern u8 D_01B00D50;
extern char D_01B028F8[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern void *D_006A3BCC;

extern int func_01B02430(char *, ...);
extern void func_01B02598(void *);
extern int func_01B026F0(void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(void *);

int func_01B01E88(void)
{
    if (D_01B0065C == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00678;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B00664;
    if (func_0014AA50(0) != 0) {
        func_01B02598(&D_01B00C40);
    }
    if (func_0014AA50(2) != 0) {
        func_01B02598(&D_01B00D50);
    }
    if (func_0014AA50(1) != 0) {
        func_01B026F0(&D_01B00C40);
        func_01B026F0(&D_01B00D50);
        func_01B02430(D_01B028F8, D_01B00C30);
        func_001CDDD8(D_01B00668);
        return 1;
    }
    D_01B00C30++;
    return 1;
}
