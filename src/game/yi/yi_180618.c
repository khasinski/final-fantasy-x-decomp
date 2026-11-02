/* tu_131 0x180618-0x180b70: low; unk_180618 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

INCLUDE_ASM("build/ee_asm/game/yi/yi_180618", func_00180618);

INCLUDE_ASM("build/ee_asm/game/yi/yi_180618", func_001806E0);

int func_001807A8(char *name) {
    char path[0x100];
    int fd;
    int n;

    n = 2;
    __builtin_memcpy(path, D_0056CD10, 7); /* DEBT(FAKE): strcpy(path, "host0:") with the literal kept in rodata */
    func_002F032C(path, name);
    func_002F8660(0);
    do {
        fd = func_002FC4E0(path, 1);
        if (fd >= 0) {
            break;
        }
    } while (--n > 0);
    return fd;
}

int func_00180818(int fd, char *buf, int size) {
    int n;

    while (size > 0) {
        n = func_002FCB20(fd, buf, size > 0x40000 ? 0x40000 : size);
        if (n < 0) {
            func_002FC768(fd);
            func_002EF240(D_0056CD18);
            return -1;
        }
        size -= n;
        buf += n;
    }
    func_002F8660(0);
}

int func_001808C8(int a, int b, int c) {
    return func_002FC8E8(a, b, c);
}

int func_001808E8(int a) {
    int x = func_001808C8(a, 0, 1);
    int y = func_001808C8(a, 0, 2);

    func_001808C8(a, x, 0);
    return y;
}

void func_00180950(int a) {
    if (a >= 0) {
        func_002FC768(a);
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_180618", func_00180968);

/* TkReadMapFile */
void func_00180A88(u32 group, int idx, char *buf) {
    char *name = func_00180968(group, idx);
    int fd;
    int size;

    func_002EF240(D_0056CDC8, name);
    fd = func_001807A8(name);
    size = func_001808E8(fd);
    func_001808C8(fd, 0, 0);
    func_00180818(fd, buf, size);
    func_00180950(fd);
}

int func_00180B10(u32 group, int idx) {
    int h;
    int size;

    h = func_001807A8(func_00180968(group, idx));
    if (h >= 0) {
        size = func_001808E8(h);
        func_00180950(h);
    } else {
        size = -1;
    }
    return size;
}
