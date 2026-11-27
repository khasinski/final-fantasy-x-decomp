#include "common.h"

typedef struct ChrMin {
    int id;
    void *hnd;
} ChrMin;

typedef struct PartEnt {
    float pos[4];      /* 0x00 */
    u8 pad10[0x18];
    int a28;           /* 0x28 */
    int a2c;           /* 0x2C */
    void *cb;          /* 0x30 */
    float f34;         /* 0x34 */
    u8 pad38[8];
    s16 s40;           /* 0x40 */
    u8 pad42[2];
    int col;           /* 0x44 */
    s16 s48;           /* 0x48 */
    s16 s4a;           /* 0x4A */
} PartEnt;

int func_0010B948(void *);
float func_001ACED8(void);
int func_001ACEA0(void);
void func_00107428(void *, int, int, void *);
PartEnt *func_01B05EE8(void);
void func_01B05B50(void);

void func_01B05F20(ChrMin *c, int a1, int n, float scale)
{
    int nbones;
    PartEnt *p;
    float r;

    nbones = func_0010B948(c->hnd);
    while (--n != -1) {
        p = func_01B05EE8();
        if (p == 0) {
            break;
        }
        p->a2c = 0;
        p->cb = func_01B05B50;
        p->a28 = a1;
        p->col = 0x40808080;
        r = func_001ACED8() - 1.0f;
        p->s4a = 0;
        p->s48 = 0;
        p->f34 = scale * r;
        p->s40 = func_001ACEA0();
        r = func_001ACED8() - 1.0f;
        func_00107428(c->hnd, (int)(r * (float)nbones), 0, p);
        p->pos[3] = 1.0f;
    }
}
