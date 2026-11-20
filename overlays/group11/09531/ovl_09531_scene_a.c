/* EE battle-effect overlay 09531: byte-exact C.
 * .text 0x01B00890..0x01B00964 (1 function).
 */
#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
    int w14;
    void **w18;
    char *w1c;
} TtCfg;

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

extern int D_01B00458;
extern TtCfg *D_01B00468;
extern TtHeap D_01B00470;
extern char D_01B01500[];
extern void *D_006A3924;

void _pppStartPart(void *part, int a, int b, int c);
int func_01B01190(char *fmt, ...);

void func_01B00890(TtPart *p)
{
    func_01B01190(D_01B01500, D_01B00458);
    D_006A3924 = &D_01B00470;
    _pppStartPart(p, 0x1000, D_01B00468->w10[1], 1);
    p->f40 = -182.49248f;
    p->f44 = -15.108843f;
    p->f48 = -265.34714f;
    p->f4C = 1.0f;
    p->w50 = -0x400;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.111496f;
    p->f64 = 0.111496f;
    p->f68 = 0.111496f;
    p->f6C = 1.0f;
}
