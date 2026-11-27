#include "common.h"

extern int D_01B00044;
extern int D_01B00048;
extern int D_01B0004C;
extern u8 D_01B00F6C;
extern int D_01B00B80;
extern u8 D_01B00F40[];
extern u8 D_01B00F90[];
extern u8 D_01B00FD0[];
extern u8 D_01B1A040[];
extern int D_01B1B0C0;
extern int D_01B1B0C4;
extern int D_01B0ACA0;
extern void *D_006A3924;

extern int func_0029B830(int);
extern int func_002D0570(int);
extern int func_00294578(int);
extern void func_001CDC58(int, int);
extern int func_001CDAF8(int);
extern void func_002B37A0(void);
extern void func_01B190D8(void *);
extern void func_01B0EC78(void *);

typedef struct {
    void *node;
    u8 flags;
    u8 tag;
    u8 pad06[10];
} MsgD010;

int func_01B0D010(void)
{
    MsgD010 m0;
    void *m1[4];

loop:
    switch (D_01B00044) {
    case 0:
        if (func_0029B830(2) == 0) {
            D_01B00044++;
            goto loop;
        }
        return 0;
    case 1:
        if (func_002D0570(2) == 0) {
            D_01B00044++;
            goto loop;
        }
        return 0;
    case 2:
        if (func_00294578(2) != 0) {
            return 0;
        }
        func_001CDC58(D_01B00B80, 1);
        D_01B00044++;
        goto loop;
    case 3:
        if (func_001CDAF8(D_01B00B80) <= 0) {
            return 0;
        }
        D_01B00044++;
        break;
    }

    if (D_01B00044 < 4) {
        return 0;
    }

    func_002B37A0();
    {
        register int v4c __asm__("$9") = D_01B0004C;
        register int vfbd0 __asm__("$10") = D_01B1B0C0;
        register u32 t __asm__("$6") = D_01B00F6C;
        D_006A3924 = D_01B1A040;
        D_01B00048 = v4c;
        D_01B00F6C = t + 1;
        D_01B0ACA0 = 0;
        D_01B1B0C4 = vfbd0;
    }
    m1[0] = D_01B00F40;
    func_01B190D8(m1);
    m0.node = D_01B00F90;
    m0.tag = D_01B00F6C;
    func_01B0EC78(&m0);
    m0.node = D_01B00FD0;
    m0.tag = D_01B00F6C;
    func_01B0EC78(&m0);
    return 0;
}
