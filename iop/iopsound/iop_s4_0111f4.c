#include "iopsound.h"

extern void func_008AC4(s32);
extern void func_008D48(s32, s32);
extern s32 func_009BB0(s32);
extern s32 func_00C054(s32);
extern void func_00F0D4(s32);
extern void func_00F120(s32);

extern char D_0165B0[];
extern char D_0165F0[];
extern char D_016604[];
extern char D_01660C[];
extern char D_016614[];

extern u8 *D_019338;
extern u8 *D_01936C;
extern u8 *D_019374;

s32 func_0111F4(s32 id) {
    s32 idx;
    s32 ret;
    u8 *hdr;

    func_00F120(8);
    func_00F120(0);
    idx = func_00C054(id);
    if (idx < 0) {
        imp_sysmem_14(D_0165B0, D_0165F0, D_016604, id, D_01660C);
        func_00F0D4(8);
        return -1;
    }
    hdr = *(u8 **)(D_019338 + idx * 24 + 12);
    ret = func_009BB0(*(s16 *)(hdr + 6));
    if (ret < 0) {
        imp_sysmem_14(D_016614, D_0165F0, D_016604, id, D_01660C);
        func_00F0D4(0);
    }
    return ret;
}

s32 func_0112EC(s32 *arg) {
    u8 *p = D_019374;
    u8 *q;

    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }
    p += 912;
    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }
    q = D_01936C;
    if (*arg == *(s32 *)(q + 884)) {
        return -1;
    }
    if (*arg == *(s32 *)(q + 1796)) {
        return -1;
    }
    if (func_0111F4(*arg) < 0) {
        return -1;
    }
    func_008D48(*arg, 0);
    return 0;
}

s32 func_0113AC(s32 *arg) {
    func_008AC4(*arg);
    return 0;
}

s32 func_0113D0(s32 *arg) {
    u8 *p = D_019374;
    u8 *q;

    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }
    p += 912;
    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }
    q = D_01936C;
    if (*arg == *(s32 *)(q + 884)) {
        return -1;
    }
    if (*arg == *(s32 *)(q + 1796)) {
        return -1;
    }
    if (func_0111F4(*arg) < 0) {
        return -1;
    }
    func_008D48(arg[0], arg[1]);
    return 0;
}

s32 func_011494(s32 *arg) {
    u8 *p = D_019374;
    u8 *q;
    s32 *a;
    s32 *b;

    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }
    p += 912;
    if (*(s32 *)(p + 884) == *arg) {
        *(s32 *)(p + 880) &= ~0x20000;
    }
    q = D_01936C;
    if (*arg == *(s32 *)(q + 884)) {
        return -1;
    }
    if (*arg == *(s32 *)(q + 1796)) {
        return -1;
    }
    if (func_0111F4(*arg) < 0) {
        return -1;
    }
    a = (s32 *)D_01936C;
    b = (s32 *)(D_01936C + 912);
    do {
        s32 tmp = *a;
        *a = *b;
        *b = tmp;
        a++;
        b++;
    } while ((u8 *)a < D_01936C + 912);
    func_008D48(*arg, 0);
    return 0;
}
