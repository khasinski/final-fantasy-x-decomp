/* 09109 wait/finish task (176 B, 09109 @ 0x01B00738). */

#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} OvlTaskSub;

typedef struct {
    u8 pad00[0x08];
    OvlTaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
} OvlTask;

extern u8 g_52d8[];
extern int g_539c;
extern u16 g_5328;

extern int fn_28b8(void *);
extern int fn_4be0(void);
extern void fn_1840(int, int);
extern void fn_0508(void);

void ovl_09109_0738(OvlTask *t)
{
    int done;

    if (fn_28b8(g_52d8) != 1) {
        return;
    }
    done = 0;
    if (g_539c == 1) {
        if (g_5328 & 0x8000) {
            if (fn_4be0() == 0) {
                done = 1;
            }
        }
    } else {
        done = 1;
    }
    if (done == 1) {
        fn_1840(0, -1);
        t->w14 = 3;
        t->p08->p10 = (s32)fn_0508;
    }
}
