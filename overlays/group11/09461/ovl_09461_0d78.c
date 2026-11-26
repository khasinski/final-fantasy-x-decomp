#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} Sub0D78;

typedef struct {
    u8 pad00[0x8];
    Sub0D78 *p08;
    u8 pad0C[0x8];
    s32 w14;
} Arg0D78;

extern void func_1B00E18(void);
extern s32 func_1B04738(void *, void *);
extern s32 func_1B037D8(void *);

extern u8 D_01B06D78;
extern void *D_01B07024;
extern u8 D_01B06328;
extern s32 D_01B06D74;
extern s32 D_01B06D3C;
extern u8 D_01B00930;

void ovl_09461_0d78(Arg0D78 *s1)
{
    s32 s0;

    func_1B00E18();
    s0 = func_1B04738(&D_01B06D78, D_01B07024);
    if (func_1B037D8(&D_01B06328) == 1 && s0 == 1 && D_01B06D74 == 0 && D_01B06D3C <= 0) {
        s1->w14 = 3;
        s1->p08->p10 = (s32)&D_01B00930;
    }
}
