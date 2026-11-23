/* Overlay 09559: rank 672 resource table init (0x01B045B0..0x01B04610). */
#include "common.h"

extern u8 D_01D189F0[];
extern u8 D_01CCF360[];

void func_002B4980(void *);
int func_002D02E8(void *, int, int, int);

void func_01B045B0(void) {
    u8 *p;
    p = D_01D189F0;
    func_002B4980(p);
    func_002D02E8(p, 0, 10, 256);
    p = D_01CCF360;
    func_002B4980(p);
    func_002D02E8(p, 0, 10, 256);
}
