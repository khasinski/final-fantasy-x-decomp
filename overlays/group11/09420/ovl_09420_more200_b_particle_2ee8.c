/* Battle-effect overlay 09420: byte-exact C helpers and callbacks. */
#include "common.h"

typedef struct TtHeap {
    u8 pad00[0x20];
    int w20;
    void **w24;
    char *w28;
} TtHeap;

typedef struct TtPart {
    u8 pad00[0x40];
    float f40;
    float f44;
    float f48;
    float f4C;
    int w50;
    int w54;
    int w58;
    int w5C;
    float f60;
    float f64;
    float f68;
    float f6C;
} TtPart;

extern TtHeap D_01B00880;
extern int D_01B01258;
extern char D_01B04608[];

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

void pppSetMatrix(void *part);
int _pppRunPart(void *part, int n);
void _pppAllFreePObject(void *part);
void func_002DCE38(void *a, void *b, void *c);

int func_01B03858(char *fmt, ...);

int func_01B02EE8(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00880;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B02F70(TtPart *p)
{
    func_01B03858(D_01B04608, D_01B01258);
    D_006A3924 = &D_01B00880;
    _pppAllFreePObject(p);
    return 1;
}
