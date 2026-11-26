#include "iopsound.h"

extern s32 D_018718;
extern u8 *D_018754;
extern u8 *D_018FA8;
extern u8 *D_018FAC;
extern u8 *D_01936C;

typedef struct {
    s32 f0;
    u8 pad4[312];
} Track316;

s32 func_0105F4(s32 *arg, u32 size) {
    s32 *src;
    s32 *dst;
    u32 cnt;
    Track316 *tr;
    s32 active_cnt;
    u8 *p;
    u8 *s;

    if (size != 0) {
        cnt = size >> 5;
        dst = (s32 *)D_018FAC;
        src = arg;
        if (cnt != 0) {
            s32 *base = (s32 *)D_018FA8;
            do {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
                dst[3] = src[3];
                dst[4] = src[4];
                dst[5] = src[5];
                dst[6] = src[6];
                dst[7] = src[7];
                src += 8;
                cnt--;
                dst += 8;
                if (dst == (s32 *)((u8 *)base + 8448)) {
                    dst = base;
                }
            } while (cnt != 0);
        }
        D_018FAC = (u8 *)dst;
    }

    tr = *(Track316 **)(D_01936C + 1824);
    active_cnt = 0;
    do {
        if (tr->f0 != 0) {
            active_cnt++;
            break;
        }
        tr++;
    } while (tr < *(Track316 **)(D_01936C + 1824) + 24);

    p = D_01936C;
    arg[6] = active_cnt;
    arg[4] = (s16)(*(u16 *)(p + 906) | *(u16 *)(p + 1818));
    s = D_018754;
    arg[12] = *(s32 *)(s + 140);
    {
        s32 v = *(s32 *)(s + 28);
        s32 ret = D_018718;
        arg[13] = v;
        return ret;
    }
}
