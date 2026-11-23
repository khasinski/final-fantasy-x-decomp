#include "common.h"

extern void *D_01B00724;
extern void func_001C5E90(void *, void *, int);
extern void func_01B09520(void *);
extern void func_01B09428(void *);
extern void func_01B0A658(void *);
extern void func_01B0A5B0(void *);
extern void func_01B0BFA8(void *);
extern void func_01B0BEA0(void *);
extern void func_01B0D718(void *);

typedef struct {
    u8 pad000[0x108];
    int flags108;       /* 0x108 */
    u8 pad10C[0x14];
    u8 sub120[0x30];    /* 0x120 */
    u8 sub150[0x30];    /* 0x150 */
    u8 sub180[0x158];   /* 0x180 */
    int timer2D8;       /* 0x2D8 */
    int state2DC;       /* 0x2DC */
    u8 *p2E0;           /* 0x2E0 */
    u8 sub2E4[4];       /* 0x2E4 */
} Work2F78;

typedef struct {
    void *owner;        /* 0x00 */
    Work2F78 *w;        /* 0x04 */
} Arg2F78;

void func_01B02F78(Arg2F78 *a)
{
    Work2F78 *w = a->w;
    void *m0;
    void *m1;
    void *m2;
    void *m3;
    void *m4;
    void *m5;
    void *m6;
    void *m7;
    void *m8;
    int i;

    switch (w->state2DC) {
    case 0:
        if (w->timer2D8 < 90) {
            break;
        }
        for (i = 0; i < *(int *)(w->p2E0 + 0x520); i++) {
            func_001C5E90(D_01B00724, *(void **)(w->p2E0 + i * 0xA0 + 0x74), 0x20);
        }
        w->state2DC++;
        break;
    case 1:
        if (w->flags108 & 4) {
            m0 = w->sub120;
            func_01B09520(&m0);
            m1 = w->sub120;
            func_01B09428(&m1);
            m2 = w->sub150;
            func_01B09520(&m2);
            m3 = w->sub150;
            func_01B09428(&m3);
            m4 = w->sub180;
            func_01B0A658(&m4);
            m5 = w->sub180;
            func_01B0A5B0(&m5);
            m6 = w->sub2E4;
            func_01B0BFA8(&m6);
            m7 = w->sub2E4;
            func_01B0BEA0(&m7);
            m8 = a->owner;
            func_01B0D718(&m8);
            w->state2DC = 0xFF;
        }
        break;
    }
    w->timer2D8++;
}
