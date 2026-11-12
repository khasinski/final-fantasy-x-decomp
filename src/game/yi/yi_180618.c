/* tu_131 0x180618-0x180b70: low; unk_180618 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"

typedef struct YiSub180618 {
    u32 w00;
    u32 imgIdx;
    u8 pad_08[0x118];
} YiSub180618;

typedef struct YiObj180618 {
    u8 pad_00[0x20];
    YiSub180618 *subs;
    u32 count;
} YiObj180618;

typedef struct YiImgRec180618 {
    u32 flags;
    char name[0x104];
    u32 bp;
    u16 psm;
    u16 tbw;
    u32 w110;
    u8 pad_114[0x34];
    u32 *clutData;
    u8 pad_14C[0x2C];
} YiImgRec180618;

typedef struct YiSys180618 {
    u8 pad_00000[0x683B4];
    u32 n683B4;
    YiObj180618 *objs683B8[1];
    u8 pad_683BC[0x9E7D0 - 0x683BC];
    u32 n9E7D0;
    YiImgRec180618 *imgs9E7D4;
} YiSys180618;

INCLUDE_ASM("build/ee_asm/game/yi/yi_180618", func_00180618);

int func_001806E0(YiSys180618 *s)
{
    u32 i;
    int j;
    int n;
    u32 *clut;

    for (i = 0; i < s->n9E7D0; i++) {
        switch (s->imgs9E7D4[i].psm) {
        case 0x14:
            n = 0x10;
            break;
        case 0x13:
            n = 0x100;
            break;
        default:
            n = 0;
            break;
        }
        clut = s->imgs9E7D4[i].clutData;
        for (j = 0; j < n; j++, clut++) {
            if ((*clut >> 24) >= 0x80) {
                *clut = (*clut & 0x00FFFFFF) | 0x7F000000;
            }
        }
    }
}

int func_001807A8(char *name) {
    char path[0x100];
    int fd;
    int n;

    n = 2;
    __builtin_memcpy(path, D_0056CD10, 7); /* strcpy(path, "host0:") with the literal kept in rodata */
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

extern char D_0030ECF8[][0x80];
extern char D_0056CD28[];
extern char D_0056CD60[];
extern char D_0056CD88[];
extern char D_0056CD98[];
extern char D_0056CDA8[];
extern char D_0056CDB8[];
extern char D_0065FC18[];
void func_002EA328(int a) __attribute__((noreturn));

char *func_00180968(u32 group, int idx)
{
    int hdr[2];
    int fd;

    if (group >= 2) {
        func_002EF240(D_0056CD28);
        func_002EA328(0);
    }
    D_0065FC18[0] = 0;
    fd = func_001807A8(D_0030ECF8[group]);
    func_001808C8(fd, 0, 0);
    func_001808C8(fd, idx * 8, 0);
    func_00180818(fd, (char *)hdr, 8);
    func_001808C8(fd, hdr[0], 0);
    func_00180818(fd, D_0065FC18, hdr[1]);
    func_00180950(fd);
    func_002EF240(D_0056CD60);
    func_002EF240(D_0056CD88, hdr[0]);
    func_002EF240(D_0056CD98, idx);
    func_002EF240(D_0056CDA8, hdr[1]);
    func_002EF240(D_0056CDB8, D_0065FC18);
    return D_0065FC18;
}

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
