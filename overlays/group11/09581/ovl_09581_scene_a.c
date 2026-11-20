/* EE battle-effect overlay 09581: byte-exact C.
 * .text 0x01B007B0..0x01B00BD4, .rodata 0x01B012F8.
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
    u8 pad70[0x10];
} TtPart;

extern int D_01B004C8[];
extern float D_01B00500[][4];
extern TtCfg *D_01B0053C;
extern TtHeap D_01B00540;
extern TtPart D_01B00570[];
extern int D_01B00694;
extern char D_01B01300[];
extern char D_01B01310[];

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
void func_002DD0B0(void *dst, void *src);
int func_002EFD78(void);

int func_01B00F88(char *fmt, ...);

int func_01B007B0(void)
{
    return 1;
}

void func_01B007B8(void)
{
    D_01B00500[0][0] = (float)((double)D_01B00500[0][0] + (double)(D_01B00500[1][0] - D_01B00500[0][0]) * 0.2);
    D_01B00500[0][1] = (float)((double)D_01B00500[0][1] + (double)(D_01B00500[1][1] - D_01B00500[0][1]) * 0.2);
    D_01B00500[0][2] = (float)((double)D_01B00500[0][2] + (double)(D_01B00500[1][2] - D_01B00500[0][2]) * 0.2);
}

void func_01B008C0(TtPart *p)
{
    float s;
    D_006A3924 = &D_01B00540;
    _pppStartPart(p, 0x1000, D_01B0053C->w10[0], 1);
    p->f40 = 0.0f;
    p->f44 = 0.0f;
    p->f48 = 0.0f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    s = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * (0.1f - 0.07f) + 0.07f;
    p->f60 = s;
    p->f64 = s;
    p->f68 = s;
    p->f6C = 1.0f;
}

int func_01B00998(int *arg)
{
    /* DEBT(PADDING): unused local matching original 0x80 stack frame. */
    float pad[16];
    int idx;
    (void)pad;
    func_01B00F88(D_01B01300);
    idx = arg - D_01B004C8;
    func_01B008C0(&D_01B00570[idx]);
    D_01B00500[idx][0] *= 10.0f;
    D_01B00500[idx][1] *= -10.0f;
    D_01B00500[idx][2] *= -10.0f;
    func_002DD0B0(&D_01B00570[idx].f40, D_01B00500[idx]);
    return 1;
}

int func_01B00A60(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00540;
    if (_pppRunPart(p, 0x30) != 0) {
        D_006A3924 = &D_01B00540;
        _pppAllFreePObject(p);
        D_006A3924 = &D_01B00540;
        _pppStartPart(p, 0x1000, D_01B0053C->w10[0], 1);
    }
    return 1;
}

int func_01B00B28(int *arg)
{
    int idx = arg - D_01B004C8;
    func_01B00A60(&D_01B00570[idx]);
    return 1;
}

int func_01B00B68(int *arg)
{
    int idx;
    func_01B00F88(D_01B01310, D_01B00694);
    idx = arg - D_01B004C8;
    D_006A3924 = &D_01B00540;
    _pppAllFreePObject(&D_01B00570[idx]);
    return 1;
}
