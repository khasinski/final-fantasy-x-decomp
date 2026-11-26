#include "iopsound.h"

extern void *memcpy(void *, const void *, u32);

extern char D_016580[];
extern char D_01658C[];
extern char *D_018FB8;

s32 func_00FF08(const char *path) {
    s32 len;
    char *p;

    imp_sysclib_19(D_018FB8, D_016580, path);
    len = imp_sysclib_27(D_018FB8);
    p = (char *)(len + (u32)D_018FB8);
    if (p[-1] != '/') {
        memcpy(p, D_01658C, 2);
    }
    return imp_sysclib_27(D_018FB8);
}
