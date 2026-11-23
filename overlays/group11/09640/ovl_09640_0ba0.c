#include "common.h"

extern void *D_01B087F0;
extern s32 D_01B087F4;
extern u8 D_01B0E0A0[];
extern u8 D_01B64940[];

extern void func_01B01408(void);
extern void func_01B03570(void);
extern void func_01B03C58(void);
extern void func_01B046D8(void);
extern void func_002B22F8(int, int);
extern void op_oef2_set2(void *);
extern void func_01B02E40(void *, int, int);
extern void func_01B03708(void *, int, int);
extern void func_01B03718(void *, int, int);

int ovl_09640_0ba0(void *a0)
{
    D_01B087F0 = a0;
    func_01B01408();
    func_01B03570();
    func_01B03C58();
    func_01B046D8();
    func_002B22F8(13312, 2048);
    op_oef2_set2(D_01B0E0A0);
    func_01B02E40(D_01B0E0A0, 0, 1000);
    func_01B03708(D_01B0E0A0, 0, 1000);
    op_oef2_set2(D_01B64940);
    func_01B03708(D_01B64940, 0, 1000);
    op_oef2_set2(D_01B64940);
    func_01B03718(D_01B64940, 0, 0);
    D_01B087F4 = 0;
    return 0;
}
