#include "iopsound.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    u8 unk08[0x18];
    s32 ptr0;
    s32 rem0;
    s32 ptr1;
    s32 rem1;
} DmaState;

extern DmaState D_06D270;
extern u8 D_017700[];

extern void func_00FDF4(s32, s32, void *);
extern void func_00FC2C(s32, s32, void *, s32, s32);

s32 func_0086F8(s32 ch) {
    s32 size;
    s32 addr;
    s32 rem;

    if (ch == 0) {
        {
            DmaState *p = &D_06D270;
            size = p->rem0;
            addr = p->ptr0;
        }
        if (size > 4096) {
            size = 4096;
        } else {
            if ((size & 0x30) != 0) {
                s32 tmp = addr - 64;
                addr = tmp + (size & 0x30);
                tmp = size + 64;
                size = tmp - (size & 0x30);
            }
        }
        {
            DmaState *p = &D_06D270;
            p->ptr0 += 4096;
            p->rem0 -= 4096;
            if (p->rem0 <= 0) {
                func_00FDF4(0, 0, NULL);
            }
        }
        func_00FC2C(0, 0, D_017700, addr, size);
    } else {
        {
            DmaState *p = &D_06D270;
            size = p->rem1;
            addr = p->ptr1;
        }
        if (size > 4096) {
            size = 4096;
        } else {
            if ((size & 0x30) != 0) {
                s32 tmp = addr - 64;
                addr = tmp + (size & 0x30);
                tmp = size + 64;
                size = tmp - (size & 0x30);
            }
        }
        {
            DmaState *p = &D_06D270;
            p->ptr1 += 4096;
            p->rem1 -= 4096;
            if (p->rem1 <= 0) {
                func_00FDF4(1, p->unk00, p->unk08);
            }
        }
        func_00FC2C(1, 0, D_017700, addr, size);
    }
    return size;
}
