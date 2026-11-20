/* EE battle-effect overlay 09531: byte-exact C.
 * .text 0x01B00F40..0x01B010BC (1 function).
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

extern int D_01B00448;
extern int D_01B0044C;
extern void *D_01B00450;
extern int D_01B00458;
extern u8 *D_01B00464;
extern u8 D_01B00470[];
extern float D_01B005A0[][4];
extern TtRing D_01B00640;
extern TtRing D_01B00750;
extern char D_01B01588[];
extern char D_01B01598[];
extern char D_01B015A8[];

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern int D_006A3BCC;

void func_001AACA0(void *m);
void func_001A9EE0(void *m);
void func_00107428(void *a, int b, int c, void *d);
int func_0014AA50(int a);
void MsEffectTerminate(int id);

int func_01B01190(char *fmt, ...);
int func_01B011E8(char *fmt, ...);
void func_01B01228(int a, int b);
int func_01B012E0(TtRing *r);
int func_01B01438(TtRing *r);

int func_01B00F40(void)
{
    int i;
    if (D_01B00448 == 0) {
        return 0;
    }
    D_006A3924 = D_01B00470;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00464;
    for (i = 8; i >= 0; i--) {
        D_01B005A0[i + 1][0] = D_01B005A0[i][0];
        D_01B005A0[i + 1][1] = D_01B005A0[i][1];
        D_01B005A0[i + 1][2] = D_01B005A0[i][2];
    }
    func_00107428(D_01B00450, 0, 0, D_01B005A0);
    if (func_0014AA50(0) != 0) {
        func_01B01228(0x20, 0x1A);
        func_01B011E8(D_01B01588, D_01B00750.frame);
        func_01B012E0(&D_01B00750);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01228(0x20, 0x1B);
        func_01B011E8(D_01B01598, D_01B00640.frame);
        func_01B012E0(&D_01B00640);
    }
    if (func_0014AA50(2) != 0) {
        func_01B01438(&D_01B00750);
        func_01B01438(&D_01B00640);
        func_01B01190(D_01B015A8);
        MsEffectTerminate(D_01B0044C);
        return 1;
    }
    D_01B00458++;
    return 1;
}
