#include "iopsound.h"

extern void func_00C938(s32, s32);
extern s32 func_00D818(s32, void *);

extern u8 *D_018754;
extern s32 D_018F88[];
extern s32 D_06D2B0[];

typedef struct {
    u8 *f0;
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[112 - 40];
} StreamCh;

typedef struct {
    s32 spu_l;
    s32 spu_r;
    s32 size;
    s32 end_flag;
    void *cb;
} DmaSlot;

s32 func_00DAC4(void) {
    s32 mask = 0;
    s32 cur;
    s32 loop;
    StreamCh *s;
    DmaSlot *slot;
    s32 *half;
    s32 *st;

    if (((StreamCh *)D_018754)[0].f1C != 0) {
        cur = imp_libsd_10(0x226c);
        loop = imp_libsd_10(0x216c);
        if (loop != 0x5030) {
            if (cur >= loop && (u32)cur < (u32)(loop + 0x7e0)) {
                mask = 1;
            }
        } else if (cur >= loop && cur < loop + 0x20) {
            mask = 1;
        }
    }

    s = (StreamCh *)D_018754;
    if (s[1].f1C != 0) {
        cur = imp_libsd_10((u16)(((u16)s[1].f24 << 1) | 0x2241));
        s = (StreamCh *)D_018754;
        loop = imp_libsd_10((u16)(((u16)s[1].f24 << 1) | 0x2141));
        if (loop != 0x5030) {
            if (cur >= loop && (u32)cur < (u32)(loop + 0x7e0)) {
                mask |= 2;
            }
        } else if (cur >= loop && cur < loop + 0x20) {
            mask |= 2;
        }
    }

    half = D_018F88;
    D_06D2B0[0] = mask;
    slot = (DmaSlot *)(D_06D2B0 + 1);
    loop = 0;
    do {
        if ((mask & 1) && slot->cb == (void *)func_00DAC4) {
            switch (*half) {
            case 0:
                slot->spu_l = loop + 0x5100;
                slot->spu_r = loop + 0x5900;
                slot->size = 0x1000;
                break;
            case 1:
                slot->spu_l = loop + 0x6100;
                slot->spu_r = loop + 0x6900;
                slot->size = 0x1000;
                break;
            case 16:
                slot->spu_l = loop + 0x5100;
                slot->spu_r = loop + 0x5100;
                slot->size = 0x800;
                break;
            case 17:
                slot->spu_l = loop + 0x6100;
                slot->spu_r = loop + 0x6100;
                slot->size = 0x800;
                break;
            }
            *half ^= 1;
        }
        half++;
        slot++;
        loop += 0x1af00;
        mask >>= 1;
    } while (mask != 0);

    st = D_06D2B0;
    if (st[0] & 1) {
        void *cb = ((DmaSlot *)(st + 1))->cb;
        if (cb == (void *)func_00C938) {
            func_00C938(1, 0);
        } else if (cb == (void *)func_00DAC4) {
            func_00D818(0, (DmaSlot *)(st + 1));
        }
        st = D_06D2B0;
    }
    if (st[0] & 2) {
        void *cb = ((DmaSlot *)(st + 1))[1].cb;
        if (cb == (void *)func_00C938) {
            func_00C938(2, 0);
        } else if (cb == (void *)func_00DAC4) {
            func_00D818(1, &((DmaSlot *)(st + 1))[1]);
        }
    }
    return mask;
}
