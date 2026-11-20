/* EE battle-effect overlay 09299: byte-exact C.
 * .text 0x01B00A20..0x01B00F58 (9 functions).
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

extern TtCfg *D_01B00744;
extern TtHeap D_01B00748;
extern int D_01B00900;
extern void *D_01B00904;
extern char D_01B01A70[];
extern char D_01B01A88[];
extern char D_01B01AA0[];
extern char D_01B01AB8[];
extern char D_01B01AD0[];
extern char D_01B01AE0[];

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

void _pppStartPart(void *part, int a, int b, int c);
void pppSetMatrix(void *part);
int _pppRunPart(void *part, int n);
void _pppAllFreePObject(void *part);
void func_002DCE38(void *a, void *b, void *c);
int func_0014AA50(int a);
void func_00107428(void *a, int b, int c, void *d);

int func_01B016D8(char *fmt, ...);

int func_01B00A20(TtPart *p)
{
    func_01B016D8(D_01B01A70, D_01B00900);
    D_006A3924 = &D_01B00748;
    _pppStartPart(p, 0x1000, D_01B00744->w10[0], 1);
    p->f40 = -2.0f;
    p->f44 = -1.0f;
    p->f48 = -67.0f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0x71C;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.105997f;
    p->f64 = 0.105997f;
    p->f68 = 0.105997f;
    p->f6C = 1.0f;
    return 1;
}

int func_01B00AF0(TtPart *p)
{
    if (func_0014AA50(2) != 0) {
        p->f40 = 7.0f;
        p->f44 = 3.0f;
        p->f48 = -61.0f;
        p->f4C = 1.0f;
    }
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00748;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00BB8(TtPart *p)
{
    func_01B016D8(D_01B01A88, D_01B00900);
    D_006A3924 = &D_01B00748;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00C08(TtPart *p)
{
    func_01B016D8(D_01B01AA0, D_01B00900);
    D_006A3924 = &D_01B00748;
    _pppStartPart(p, 0x1000, D_01B00744->w10[0], 1);
    p->f40 = 7.0f;
    p->f44 = 3.0f;
    p->f48 = -61.0f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0x71C;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.105997f;
    p->f64 = 0.105997f;
    p->f68 = 0.105997f;
    p->f6C = 1.0f;
    return 1;
}

int func_01B00CD8(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00748;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00D60(TtPart *p)
{
    func_01B016D8(D_01B01AB8, D_01B00900);
    D_006A3924 = &D_01B00748;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00DB0(TtPart *p)
{
    func_01B016D8(D_01B01AD0, D_01B00900);
    D_006A3924 = &D_01B00748;
    _pppStartPart(p, 0x1000, D_01B00744->w10[1], 1);
    p->f40 = 0.0f;
    p->f44 = 0.0f;
    p->f48 = 0.0f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0x1554;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.0134f;
    p->f64 = 0.0134f;
    p->f68 = 0.0134f;
    p->f6C = 1.0f;
    return 1;
}

int func_01B00E68(TtPart *p)
{
    func_00107428(D_01B00904, 0x20, 0, &p->f40);
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00748;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00F08(TtPart *p)
{
    func_01B016D8(D_01B01AE0, D_01B00900);
    D_006A3924 = &D_01B00748;
    _pppAllFreePObject(p);
    return 1;
}
