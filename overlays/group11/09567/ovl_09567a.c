/* EE Battle-Effect Overlay: group 0x11, file 09567
 * Load base: 0x01B00000, .text: 0x01B01148..0x01B01D04
 *
 * Particle scene shell ("tt_scene"): ppp part start/run/free, a small timed-callback ring
 * (24-byte entries, 8-byte slots) and debug-print stubs.
 */
#include "common.h"

typedef struct TtEnt {
    int start;
    int len;
    void (*on_start)(int);
    int (*on_run)(int);
    void (*on_end)(int);
    int arg;
} TtEnt;

typedef struct TtRing {
    int frame;
    int n;
    int active;
    struct {
        int on;
        int pad;
    } slot[32];
    TtEnt *tbl;
} TtRing;

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
    u8 pad70[16];
} TtPart;

extern int D_01B0078C;
extern int D_01B00790;
extern int D_01B00794;
extern u8 *D_01B00798;
extern u8 *D_01B0079C;
extern int D_01B007A0;
extern int *D_01B007A4;
extern TtCfg *D_01B007A8;
extern TtHeap D_01B007B0;
extern TtPart D_01B00860[];
extern TtPart D_01B00860[];
extern void *D_01B00DE4;
extern void *D_01B00DE0;
extern char D_01B01D10[];
extern char D_01B01D68[];
void func_00107428(void *, int, int, void *);
extern int D_01B00760[];
extern float D_01B00478[];
extern double D_01B01D20;
extern char D_01B01D28[];
int func_002EFD78(void);
double func_002EBC70(double,double);
double func_002EBBB0(double,double);
void Sg_PLightAllocate(int);
void Sg_PLightDefine(int,int,int,int,int,float,float,float,float);
void func_0010DC38(void *, int);
void func_0010D720(void);
extern char D_01B01D58[];
void *func_0013B150(int);
extern int D_01B00DE8;
extern TtRing D_01B00DF0;
extern TtEnt D_01B00610[];
extern u8 D_01B00040[];
extern u8 D_01B01DD0[];
extern u8 D_01B240D0[];
extern char D_01B01D30[];
extern char D_01B01D48[];
extern char D_01B01D78[];
extern char D_01B01D80[];
extern char D_01B01DA0[];
extern char D_01B01DB0[];

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern int D_006A3BCC;

void _pppStartPart(void *part, int a, int b, int c);
void pppSetMatrix(void *part);
int _pppRunPart(void *part, int n);
void _pppAllFreePObject(void *part);
void _pppInitData(void *a, void *b);
void pppInitEnv(void *heap, void *cfg, void *base, int size);
void op_oef2_set2(void *tbl);
void func_002D02E8(void *a, int b, int c, int d);
int *op_oef2_a_get(void *tbl, int a, int b);
void func_002DCE38(void *a, void *b, void *c);
int Sg_GetCurExecFrames(void);
int func_0029B830(int a);
int MsEffectReady(int id, int flag);
int MsEffectMotionLevel(int id);
void MsEffectTerminate(int id);
void func_001AACA0(void *m);
void func_001A9EE0(void *m);
int func_0014AA50(int a);
void *func_002EF0D0(void *p, int v, int n);
double func_002ED038(float f);
double func_002E9290(double d);
float func_002EC440(double d);

int func_01B019A0(char *fmt, ...);
void func_01B019D0(char *fmt, ...);
int func_01B019F8(char *fmt, ...);
void func_01B01A38(int a, int b);
void func_01B01A40(TtRing *r, TtEnt *tbl, int n);
int func_01B01AF0(TtRing *r);
int func_01B01C48(TtRing *r);

int func_01B01148(TtPart *p)
{
    int index = p - D_01B00860;
    func_00107428(D_01B00DE4, D_01B00760[index], 0, &p->f40);
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B007B0;
    return _pppRunPart(p, 0x30) == 0;
}
int func_01B01208(TtPart *p)
{
    func_01B019A0(D_01B01D10, D_01B00DE8);
    D_006A3924 = &D_01B007B0;
    _pppAllFreePObject(p);
    return 1;
}
