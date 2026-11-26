#include "iopsound.h"

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
} S_122400;

extern S_122400 D_122400;
extern s32 D_019368;
extern u32 D_06D3F0[];
extern s32 D_01934C;
extern u8 *D_018FB4;

void func_01554C(void) {
    S_122400 *st = &D_122400;

    while (1) {
        u32 *dst;
        u32 *end_buf;
        u32 *blk_end;
        u32 *src;
        s32 rem_words;
        s32 buf_sz;

        imp_thsemap_8(D_019368);
        buf_sz = D_01934C;
        dst = (u32 *)((u8 *)D_06D3F0 + buf_sz);
        if (st->f00 & 1) {
            dst += (u32)buf_sz >> 2;
        }
        end_buf = dst + ((u32)buf_sz >> 2);

        if (buf_sz % 0x3000 != 0) {
            s32 n = st->f08 % 6;
            n = (n != 0) ? ((u32)(0x3000 - (n << 11)) >> 2) : 0;
            st->f04 = n;
            if (n != 0) {
                u32 *pe;
                src = (u32 *)(D_018FB4 + 0xd000);
                pe = src + n;
                do {
                    *dst++ = *src++;
                } while (src < pe);
                st->f04 = 0;
            }
        }
        blk_end = dst + 0xc00;

        src = (u32 *)(D_018FB4 + 0x8000);
        do {
            u32 *chunk_end;
            rem_words = 448;
            chunk_end = dst + 128;
            dst[0] = 0x4e1ff872;
            dst[1] = 0x38000001;
            dst += 2;
            do {
                do {
                    if (rem_words != 0) {
                        rem_words--;
                        *dst++ = *src++;
                    } else {
                        *dst++ = 0;
                    }
                } while (dst < chunk_end);
                chunk_end += 256;
                dst += 128;
            } while (rem_words != 0 && dst < end_buf);

            if (dst < end_buf) {
                u32 *z_end = (blk_end < end_buf) ? blk_end : end_buf;
                do {
                    *dst++ = 0;
                } while (dst < z_end);
            }
            if (blk_end < end_buf) {
                blk_end += 0xc00;
            }
        } while (dst < end_buf);

        if (dst < blk_end) {
            s32 left = blk_end - dst;
            st->f04 = left;
            dst = (u32 *)(D_018FB4 + 0xd000);
            blk_end = dst + left;
            if (rem_words != 0) {
                u32 *chunk_end = dst + 128;
                do {
                    do {
                        if (rem_words != 0) {
                            rem_words--;
                            *dst++ = *src++;
                        } else {
                            *dst++ = 0;
                        }
                    } while (dst < chunk_end);
                    chunk_end += 256;
                    dst += 128;
                } while (rem_words != 0);
            }
            do {
                *dst++ = 0;
            } while (dst < blk_end);
        }
        st->f00++;
    }
}
