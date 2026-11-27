#include "common.h"

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0C;
    u8 f10[0x10];
    u8 f20[0x80];
} Elem3900;

extern int D_01B00A78;
extern u8 *D_01B00A7C;
extern int D_01B007A0;
extern int D_01B032C0;
extern int D_01B032C4;

extern void func_001BB930(int, int, int *, int, int, int, int, int);
extern void *func_001B4E58(int);
extern void func_00108910(void *, int, void *);
extern void func_01B03778(void *, void *);

int func_01B03900(Elem3900 *p)
{
    int flag;
    int i;

    D_01B032C0 = D_01B00A78;
    D_01B032C4 = 1;
    i = 0;
    if (D_01B032C0 > 0) {
        register int n __asm__("$3");
        do {
            int id = D_01B00A7C[i];
            int a = D_01B007A0;
            p->f00 = id;
            func_001BB930(a, id, &flag, 0, 0, 0, 0, 0);
            p->f08 = 0x23;
            p->f04 = flag & 1;
            func_00108910(func_001B4E58(p->f00), 0x10, p->f10);
            func_01B03778(p->f20, p->f10);
            i++;
            p++;
            n = D_01B032C0;
        } while (i < n);
    }
    return 1;
}
