#include "common.h"

extern float D_01B00850;
extern float D_01B00854;
extern u8 *D_01B0088C;
extern u8 *D_01B00890;
extern void *D_01B00A60;
extern void *D_01B00A64;
extern u8 D_01B00A70[];
extern u8 D_01B00AB0[];
extern int D_01B00B28;
extern u8 D_01B00B40[];
extern char D_01B04A10[];

extern void func_002DD0B0(void *, void *);
extern void func_01B01218(void *, void *, void *);
extern void func_01B014A0(void *, void *, void *);
extern void func_01B02DF8(void *);
extern int func_01B030D0(void *);
extern u8 *func_01B02F90(void *, void *, u8 *, float);
extern void func_01B02808(char *, ...);
extern void func_002DA610(int, int);

int func_01B017E8(void)
{
    float pos[4];
    int i;

    func_002DD0B0(pos, D_01B00B40);
    D_01B00850 = (D_01B00850 < 1.0f) ? 1.0f : ((D_01B00850 > 50.0f) ? 50.0f : D_01B00850);
    D_01B00854 = (D_01B00854 < 1.0f) ? 1.0f : ((D_01B00854 > 50.0f) ? 50.0f : D_01B00854);

    for (i = 0; i < (int)D_01B00850; i++) {
        func_01B01218(D_01B00AB0, D_01B00A60, pos);
    }
    for (i = 0; i < (int)D_01B00854; i++) {
        func_01B014A0(D_01B00AB0, D_01B00A64, pos);
    }
    func_01B02DF8(D_01B00AB0);
    D_01B00B28 = func_01B030D0(D_01B00AB0);
    {
        u8 *p = D_01B00890;
        p = func_01B02F90(D_01B00AB0, D_01B00A70, p, 0.0f);
        D_01B00890 = p;
        if (p >= D_01B0088C + 0x100000) {
            func_01B02808(D_01B04A10);
        }
    }
    func_002DA610(0, 0);
    return 1;
}
