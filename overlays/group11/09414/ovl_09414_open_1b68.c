#include "common.h"

extern int D_01B00448;
extern void *D_01B0044C;
extern int D_01B00458;
extern void *D_01B00464;
extern void *D_01B00468;
extern void *D_01B0046C;
extern int D_01B00730;
extern int D_01B00840;
extern int D_01B00950;
extern char D_01B02BC0[];
extern char D_01B02BD0[];
extern char D_01B02BE0[];
extern char D_01B02BF0[];

extern void *D_006A3BCC;

extern int func_01B01EB0(char *, ...);
extern void func_01B01F08(char *, ...);
extern void func_01B01F48(int, int);
extern void func_01B02880(void *);
extern int func_01B029D8(void *);
extern int func_0014AA50(int);
extern void func_001CDDD8(void *);

int func_01B01B68(void)
{
    if (D_01B00448 == 0) {
        return 0;
    }
    D_006A3BCC = D_01B00464;
    D_01B0046C = D_01B00468;
    if (func_0014AA50(0) != 0) {
        func_01B01F48(0x20, 0x1A);
        func_01B01F08(D_01B02BC0, D_01B00730);
        func_01B02880(&D_01B00730);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01F48(0x20, 0x1B);
        func_01B01F08(D_01B02BD0, D_01B00840);
        func_01B02880(&D_01B00840);
    }
    if (func_0014AA50(2) != 0) {
        func_01B01F48(0x20, 0x1C);
        func_01B01F08(D_01B02BE0, D_01B00950);
        func_01B02880(&D_01B00950);
    }
    if (func_0014AA50(3) != 0) {
        func_01B029D8(&D_01B00730);
        func_01B029D8(&D_01B00840);
        func_01B029D8(&D_01B00950);
        func_01B01EB0(D_01B02BF0);
        func_001CDDD8(D_01B0044C);
        return 1;
    }
    D_01B00458++;
    return 1;
}
