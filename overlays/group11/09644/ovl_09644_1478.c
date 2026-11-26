#include "common.h"

extern u8 D_01B08948[];
extern u8 D_01B08A50[];

extern void func_00103208(void *);
extern void func_00118098(int, int);
extern void *func_01B01C48(int);
extern void func_01B02AC8(int, int);
extern void func_01B02CC0(int);
extern void func_01B03070(int, int);
extern void func_01B03448(int);
extern void func_01B03B40(void *, int);
extern void func_01B04BF0(void *);
extern void func_01B06298(void);

void ovl_09644_1478(void)
{
    func_00103208(func_01B01C48(2));
    func_01B03448(0x3016);
    func_01B03070(0, 0);
    func_01B03070(-1, 0);
    func_01B03070(1, 0);
    func_01B03B40(D_01B08A50, 0);
    func_01B02AC8(0, 1);
    func_01B02CC0(1);
    func_01B02AC8(-1, 1);
    func_00118098(0, 0);
    func_00118098(1, 0);
    func_01B06298();
    func_01B04BF0(D_01B08948);
}
