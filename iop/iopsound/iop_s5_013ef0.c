#include "iopsound.h"

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    u8 *f0c;
    s32 f10;
    s32 f14;
} S_WaveInfo; /* size 24 */

typedef s32 (*CmdFunc)(void *);

extern S_WaveInfo *D_019308;
extern CmdFunc D_0190B4[];
extern s32 D_06CE70[32];
extern s32 *D_06CEF0;

extern s32 func_009BB0(s32);
extern void func_009B74(void *);

void *func_013EF0(s32 cmd, s32 *buf) {
    *buf = D_0190B4[cmd](buf);
    return buf;
}

void func_013F30(s32 id) {
    s32 idx = func_009BB0(id);
    if (idx >= 0) {
        func_009B74(&D_019308[idx]);
    } else if (D_06CEF0 < &D_06CE70[32]) {
        s32 *p;
        for (p = D_06CE70; p < D_06CEF0; p++) {
            if (*p == id) {
                break;
            }
        }
        if (p >= D_06CEF0) {
            *D_06CEF0 = id;
            D_06CEF0++;
        }
    }
}
