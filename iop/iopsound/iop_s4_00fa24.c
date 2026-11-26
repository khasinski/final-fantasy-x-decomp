#include "iopsound.h"

s32 func_00FA24(const char *path, void *buf, s32 offset, s32 size) {
    s32 fd = imp_ioman_4(path, 0x8005);

    if (fd >= 0) {
        imp_ioman_8(fd, offset, 0);
        imp_ioman_6(fd, buf, size);
        imp_ioman_5(fd);
    }
    return size;
}

s32 func_00FAA0(const char *path, u8 *buf, s32 size) {
    s32 total = 0;
    s32 fd = imp_ioman_4(path, 0x0602);
    s32 chunk;

    if (fd >= 0) {
        while (size != 0) {
            if (size <= 0x8000) {
                chunk = size;
            } else {
                chunk = 0x8000;
            }
            imp_ioman_7(fd, buf, chunk);
            size -= chunk;
            buf += chunk;
            total += chunk;
        }
        imp_ioman_5(fd);
    }
    return total;
}

s32 func_00FB48(const char *str, char ch) {
    s32 len = imp_sysclib_27(str);

    if (len != 0) {
        len--;
        while (str[len] != ch) {
            len--;
            if (len == 0) {
                break;
            }
        }
    }
    return len;
}

s32 func_00FBC8(s32 x) {
    return x;
}
