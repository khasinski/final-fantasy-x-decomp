#include "common.h"

extern int D_01B06060;
extern u8 D_01B060A0[];
extern int D_01B06FC0;
extern int D_01B06FC4;
extern int D_01B06FC8;
extern int D_01B06FCC;
extern int D_01B06FD0;
extern int D_01B06FD4;
extern int D_01B06FD8;
extern int D_01B06FDC;
extern int D_01B06FE0;
extern int D_01B06FE4;
extern int D_01B06FE8;
extern int D_01B07CD4;
extern u8 D_01BE4940[];
extern u8 D_01CAC030[];

extern void func_00110718(int, int);
extern void func_001CE9A8(int);
extern int func_00298E78(int *);
extern void func_002B4980(void *);

extern void func_01B00CB8(void *);
extern void func_01B01A08(int);
extern void func_01B01D10(int);
extern void func_01B04460(void *);
extern void func_01B04498(void *, int);

void func_01B047C8(void)
{
    int buf[256];
    int n = func_00298E78(buf);
    int i;
    for (i = 0; i < n; i++) {
        func_00110718(buf[i], 1);
    }
}

void func_01B04820(void)
{
    int buf[256];
    int n = func_00298E78(buf);
    int i;
    for (i = 0; i < n; i++) {
        func_00110718(buf[i], 0);
    }
}
