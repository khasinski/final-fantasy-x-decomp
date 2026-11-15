#include "common.h"
typedef struct TtPart { u8 data[0x80]; } TtPart;
extern void *D_006A3924;
extern u8 D_006A3930[],D_006A3970[],D_006A39B0[],D_006A3A70[],D_006A3AB0[];
void pppSetMatrix(void *);
int _pppRunPart(void *,int);
void _pppAllFreePObject(void *);
void func_002DCE38(void *,void *,void *);
extern u8 D_01B00478[];
extern int D_01B00458;
int func_01B01EB0(char *,...);
extern char D_01B02AB0[];
extern char D_01B02B20[];
extern TtPart D_01B004B0;
extern char D_01B02B48[];
extern TtPart D_01B00530;
extern char D_01B02B78[];
extern TtPart D_01B006B0;

int func_01B016A0(void)
{
    D_006A3924 = D_01B00478;
    _pppAllFreePObject(&D_01B00530);
    func_01B01EB0(D_01B02B48,D_01B00458);
    return 1;
}
