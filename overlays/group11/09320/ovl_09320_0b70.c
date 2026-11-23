/* Shared effect wait/transition check (140 B; 09320 @ 0x01B00B70). */

#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
} OvlTask;

extern u8 D_01B00A30[];
extern u8 D_01B050E8[];
extern s32 D_01B05F9C;
extern u8 D_01B05FA0[];
extern u8 *D_01B064A4;

extern int func_01B02EC8(void *);
extern int func_01B03E28(void *, void *);

void ovl_09320_0b70(OvlTask *a0)
{
    int r = func_01B02EC8(D_01B050E8);
    if (func_01B03E28(D_01B05FA0, D_01B064A4) == 1 && r == 1 && D_01B05F9C == 1) {
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00A30;
    }
}
