/* 09097 wait/finish task (224 B, 09097 @ 0x01B007D8). */

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

extern u8 g_53f8[];
extern int g_54c0;
extern int g_54bc;
extern u16 g_5448;

extern int fn_29d0(void *);
extern int fn_4cf8(void);
extern int fn_0b50(void);
extern int func_001E1EF0(void);
extern void fn_1958(int, int);
extern void fn_0520(void);

void ovl_09097_07d8(OvlTask *t)
{
    int done1;
    int done2;

    if (fn_29d0(g_53f8) != 1) {
        return;
    }
    done1 = 0;
    if (g_54c0 == 1) {
        if (g_5448 & 0x8000) {
            if (fn_4cf8() == 0) {
                done1 = 1;
            }
        }
    } else {
        done1 = 1;
    }
    if (done1 == 1) {
        done2 = 1;
        if (fn_0b50() == 0) {
            if (g_54bc == 0) {
                done2 = 0;
            }
            if (func_001E1EF0() != 0) {
                done2 = 0;
            }
        }
        if (done2 == 1) {
            fn_1958(0, -1);
            t->w14 = 3;
            t->p08->p10 = (s32)fn_0520;
        }
    }
}
