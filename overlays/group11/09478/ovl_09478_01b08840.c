#include "common.h"

extern u8 *D_01B102F0;
extern u8 D_01B102B0[];

extern void func_01B0B3B0(void *);
extern void func_01B09FE0(int, int);
extern void func_01B0AAB0(void *, int);
extern void func_01B09A38(int, int);
extern void func_01B09B78(int);
extern void func_01B09C30(int);
extern void func_001CE9A8(int);
extern void func_01B0D768(void);

void func_01B08840(void)
{
    u8 *s0 = D_01B102F0;
    void *p = *(void **)(s0 + 0x1B04);

    if (p != 0) {
        func_01B0B3B0(p);
        *(void **)(s0 + 0x1B04) = 0;
    }
    func_01B09FE0(-1, 0);
    func_01B0AAB0(D_01B102B0, 0);
    func_01B09A38(-1, 1);
    func_01B09B78(1);
    func_01B09C30(1);
    func_001CE9A8(0);
    func_01B0D768();
    *(int *)(s0 + 0x1B28) = 1;
}
