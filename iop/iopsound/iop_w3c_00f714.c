#include "iopsound.h"

typedef struct {
    u8 trycount;
    u8 spindlctrl;
    u8 datapattern;
    u8 pad;
} S_CdRMode;

extern volatile s32 D_05A144;
extern S_CdRMode D_0193B0;
extern u8 D_122470;
extern u8 D_122570;

extern s32 func_00F520(void);
extern s32 func_00F66C(void);
extern void func_00F0D4(s32);

s32 func_00F714(void *file, u8 *buf, s32 offset, s32 size) {
    s32 ret = 0;
    s32 fd;
    s32 ok;

    while (D_05A144 != 0) {
        imp_thbase_33(1000);
    }
    D_05A144 = 1;

    if (((s8 *)file)[4] == 0) {
        s32 sectors;
        u8 retry_flag;
        S_CdRMode *rmode;

        offset /= 2048;
        offset += *(s32 *)file;
        sectors = (size + 2047) / 2048;
        retry_flag = 1;
        rmode = &D_0193B0;
        fd = 0;
        do {
            s32 timeout;
            s32 cd_err;

            fd = 0;
            timeout = 1000;
            cd_err = 0;
            do {
                ok = 0;
                if (imp_cdvdman_13(1) == 2) {
                    rmode->spindlctrl = retry_flag;
                    ok = imp_cdvdman_6(offset, sectors, buf, rmode);
                    if (ok != 0) {
                        ok = 2000;
                        while (imp_cdvdman_11(1) != 0) {
                            imp_thbase_33(1000);
                            if (--ok == 0) {
                                break;
                            }
                        }
                    }
                    if (ok == 0) {
                        imp_cdvdman_39();
                    }
                    cd_err = func_00F520();
                    if (cd_err != 0) {
                        break;
                    }
                    retry_flag = 0;
                } else {
                    if (--timeout == 0) {
                        fd = 1;
                        break;
                    }
                    imp_thbase_33(1000);
                }
            } while (ok == 0);
            if (cd_err != 0) {
                fd |= 1;
            }
            do {
                if (fd != 0) {
                    fd &= 1;
                    fd |= func_00F66C();
                }
            } while ((fd & 0x10) != 0);
        } while (fd != 0);
    } else {
        do {
            fd = imp_ioman_4(file, 1);
            if (fd >= 0) {
                ok = imp_ioman_8(fd, 0, 2);

                imp_ioman_8(fd, offset, 0);
                if (size == 0) {
                    if (offset < ok) {
                        size = ok - offset;
                    }
                } else {
                    if (ok < size + offset) {
                        size = ok - offset;
                    }
                }
                size += 511;
                size &= ~511;
                while (size > 0) {
                    ok = (size > 0x8000) ? 0x8000 : size;

                    if (imp_ioman_6(fd, buf, ok) == -5) {
                        func_00F0D4(31);
                        ret = 1;
                        D_122470 = 0;
                        D_122570 = 0;
                        break;
                    }
                    size -= ok;
                    buf += ok;
                }
                imp_ioman_5(fd);
            } else if (fd == -5) {
                func_00F0D4(31);
                ret = 1;
                D_122470 = 0;
                D_122570 = 0;
                break;
            }
        } while (fd < 0 && fd != -2 && fd != -5);
    }

    D_05A144 = 0;
    return ret;
}
