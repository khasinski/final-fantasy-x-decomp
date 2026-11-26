typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern void imp_libsd_5(s32, s32);

typedef struct {
    s32 f00;
    u8 pad04[0xe4];
    u32 f0e8;
    u8 padec[0x4b];
    u8 f137;
    u8 pad138[0x04];
} S_Voice; /* size 0x13c = 316 */

typedef struct {
    S_Voice *voices;
    u8 pad04[0x36c];
    u32 f370;
    u8 pad374[0x16];
    s16 f38a;
    u8 pad38c;
    u8 count;
    u8 pad38e[2];
} S_TrackGroup; /* size 0x390 = 912 */

typedef struct {
    S_Voice *voice;
    u8 pad04[0x48];
    u32 f4c;
    u8 pad50[0x08];
    u16 ch;
    u8 pad5a[0x06];
    u16 f60;
    u16 f62;
    u8 pad64[0x04];
    u32 f68;
    u8 pad6c[0x08];
} S_HwVoice; /* size 0x74 = 116 */

extern S_TrackGroup *D_01936C;
extern S_HwVoice *D_0192F0;
extern u32 D_01931C;

extern void func_00E394(s32, s32);

s32 func_010AF4(s32 *arg) {
    u32 flags = arg[0];
    s32 mute = arg[1];
    S_Voice *v;
    S_HwVoice *hw;

    if (flags & 1) {
        S_TrackGroup *grp = D_01936C;
        do {
            if (grp->f38a != 0) {
                for (v = grp->voices + 1; v < grp->voices + grp->count; v++) {
                    if (v->f00 != 0) {
                        if (mute) {
                            v->f0e8 |= 8;
                        } else {
                            v->f0e8 &= ~8;
                        }
                        hw = D_0192F0;
                        do {
                            if (hw->voice == v) {
                                if (mute) {
                                    hw->f4c |= 8;
                                    imp_libsd_5(hw->ch | 0x0300, 0x7fff);
                                    imp_libsd_5(hw->ch | 0x0400, 0x5fff);
                                    imp_libsd_5(hw->ch | 0x0200, 0);
                                } else {
                                    hw->f4c &= ~8;
                                    imp_libsd_5(hw->ch | 0x0300, hw->f60);
                                    imp_libsd_5(hw->ch | 0x0400, hw->f62);
                                    hw->f68 |= 1;
                                }
                            }
                            hw++;
                        } while (hw < D_0192F0 + 48);
                    }
                }
            }
            if (mute) {
                grp->f370 |= 0x10;
            } else {
                grp->f370 &= ~0x10;
            }
            grp++;
        } while (grp < D_01936C + 2);
    }

    if (flags & 2) {
        for (v = D_01936C[2].voices; v < D_01936C[2].voices + 24; v++) {
            if (v->f00 != 0) {
                if (mute) {
                    v->f0e8 |= 8;
                } else {
                    v->f0e8 &= ~8;
                }
                hw = &D_0192F0[v->f137];
                if (mute) {
                    hw->f4c |= 8;
                    imp_libsd_5(hw->ch | 0x0300, 0x7fff);
                    imp_libsd_5(hw->ch | 0x0400, 0x5fff);
                    imp_libsd_5(hw->ch | 0x0200, 0);
                } else {
                    hw->f4c &= ~8;
                    imp_libsd_5(hw->ch | 0x0300, hw->f60);
                    imp_libsd_5(hw->ch | 0x0400, hw->f62);
                    hw->f68 |= 1;
                }
            }
        }
    }

    if (flags & 4) {
        func_00E394(0, mute);
        func_00E394(1, mute);
    }

    {
        u32 *flag = &D_01931C;
        *flag |= 1;
    }
    return 0;
}
