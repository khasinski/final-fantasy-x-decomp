#include "common.h"

typedef struct {
    int w00;
    int count;
} Info510;

extern Info510 D_01B00510;
extern int D_01B06C40;
extern u8 D_01B06C48[];
extern u8 D_01B07110[];
extern u8 D_01B07170[];
extern void *D_01B072E4;

extern void func_001CDDD8(int);
extern int func_01B01858(void);
extern void func_01B01DE8(void);
extern void func_01B02378(int, float *, int);
extern void func_01B03468(int, int);
extern void func_01B035E8(int, int);
extern int func_01B03E18(void *);
extern int func_01B04478(void *);
extern void func_01B04618(void *, float *);
extern int func_01B04D78(void *, void *);

void func_01B01740(void)
{
    float pos[4];
    int r0, r1, r2, r3;

    func_01B01DE8();
    func_01B02378(-1, pos, 0);
    func_01B04618(D_01B07110, pos);
    r0 = func_01B04478(D_01B07110);
    r1 = func_01B01858();
    r2 = func_01B03E18(D_01B06C48);
    r3 = func_01B04D78(D_01B07170, D_01B072E4);

    if (r3 == 1 && r1 == 1 && r2 == 1 && r0 == 1) {
        int i;
        func_01B03468(-1, 0);
        for (i = 0; i < D_01B00510.count; i++) {
            func_01B035E8(i, 0);
        }
        func_001CDDD8(D_01B06C40);
    }
}
