#include "common.h"
typedef struct TtPart { u8 data[0x80]; } TtPart;
extern void *D_006A3924;
extern u8 D_006A3930[],D_006A3970[],D_006A39B0[],D_006A3A70[],D_006A3AB0[];
void pppSetMatrix(void *);
int _pppRunPart(void *,int);
void _pppAllFreePObject(void *);
void func_002DCE38(void *,void *,void *);
extern u8 D_01B005B8[];
extern int D_01B00594;
int func_01B01CA8(char *,...);
extern char D_01B028B0[];
extern char D_01B02910[];
extern char D_01B02940[];

int func_01B00DA0(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B005B8;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00E28(TtPart *p)
{
    D_006A3924 = D_01B005B8;
    _pppAllFreePObject(p);
    func_01B01CA8(D_01B028B0,D_01B00594);
    return 1;
}
