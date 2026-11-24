#include "common.h"

typedef struct {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
} Entry10;

typedef struct {
    s32 w00;
    s32 w04;
    u8 pad08[0xFC];
    s32 w104;
} Work0620;

extern Work0620 D_01B00620;
extern Entry10 D_01B006D4[];
extern s32 func_001ACEA0(void);

s32 ovl_09088_1418(s8 *out)
{
    s32 cnt[8];
    s8 pool[0x100];
    register s32 total __asm__("$21") = D_01B00620.w104;
    s32 n_targets = D_01B00620.w04;
    s32 j;
    s32 i;

    if (n_targets >= 2) {
        for (i = 0; i < n_targets; i++) {
            register Entry10 *src __asm__("$3") = &D_01B006D4[i];
            register s32 off __asm__("$4") = i * 4;
            register s32 *dst __asm__("$5") = (s32 *)((u8 *)cnt + off);
            register s32 val __asm__("$6") = src->w0C;
            __asm__("" : "+r"(src), "+r"(off), "+r"(dst));
            *dst = val;
        }

        for (i = 0; i < total; i++) {
            s32 n = 0;
            s8 pick;
            for (j = 0; j < n_targets; j++) {
                s32 k;
                for (k = 0; k < cnt[j]; k++) {
                    pool[n++] = j;
                }
            }
            pick = pool[func_001ACEA0() % n];
            out[i] = pick;
            cnt[pick]--;
        }
    } else {
        for (i = 0; i < total; i++) {
            out[i] = 0;
        }
    }

    return total;
}
