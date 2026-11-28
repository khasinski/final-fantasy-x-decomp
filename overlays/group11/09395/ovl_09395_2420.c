#include "common.h"

typedef struct {
    u8 raw[0x80];
} Slot2420;

extern void *D_006A3924;
extern u8 D_01B009D8[];
extern Slot2420 D_01B00C90[];
extern s32 D_01B00F58;
extern s32 D_01B00F60[];

extern void func_00267530(void *);

s32 func_01B02420(Slot2420 *a0) {
    s32 idx = a0 - D_01B00C90;

    if (idx > D_01B00F58 - 1) {
        return 1;
    }
    if (D_01B00F60[idx] == 0) {
        return 1;
    }
    D_006A3924 = D_01B009D8;
    func_00267530(a0);
    return 1;
}
