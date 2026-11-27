#include "common.h"

extern int D_53C;
extern void *D_544;
extern void *D_548;
extern void *D_54C;
extern void *D_554;
extern u8 D_560;
extern int D_850;
extern u8 D_878;
extern char D_STR[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern void *D_006A3BCC;

extern int func_DBG(char *, ...);
extern void func_2820(void *);
extern int func_2978(void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(void *);

int func_01B02248(void)
{
    if (D_53C == 0) {
        return 0;
    }
    D_006A3924 = &D_560;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_544;
    D_54C = D_548;
    if (func_0014AA50(0) != 0) {
        func_2820(&D_878);
    }
    if (func_0014AA50(1) != 0) {
        func_2978(&D_878);
        func_DBG(D_STR, D_850);
        func_001CDDD8(D_554);
        return 1;
    }
    D_850++;
    return 1;
}
