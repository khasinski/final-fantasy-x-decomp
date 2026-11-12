/* tu_127 0x17a1b8-0x17a9c0: low; unk_17A1B8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v2.h"

char *func_002F0458(char *s, int c);
char *func_002F0DD0(char *s, int c);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A1B8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A2A8);

int func_0017A368(int a) {
    int r = -1;
    int i;

    for (i = 0; i < 16; i++) {
        if ((a >> i) & 1) {
            r = i;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A398);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A508);

INCLUDE_ASM("build/ee_asm/game/yi/yi_17A1B8", func_0017A600);

void func_0017A800(char *path, char *dir, char *base, char *ext)
{
    char *sep;
    char *dot;
    char saved;

    sep = func_002F0DD0(path, '/');
    if (sep == 0) {
        sep = func_002F0458(path, ':');
    }
    if (sep == 0) {
        sep = path;
        if (dir != 0) {
            *dir = 0;
        }
    } else {
        sep++;
        if (dir != 0) {
            saved = *sep;
            *sep = 0;
            func_002F072C(dir, path);
            *sep = saved;
        }
    }
    dot = func_002F0DD0(sep, '.');
    if (dot == 0) {
        if (base != 0) {
            func_002F072C(base, sep);
        }
        if (ext != 0) {
            *ext = 0;
        }
    } else {
        *dot = 0;
        if (base != 0) {
            func_002F072C(base, sep);
        }
        *dot = '.';
        if (ext != 0) {
            func_002F072C(ext, dot);
        }
    }
}

void func_0017A930(char *s)
{
    while (*s != 0) {
        *s = func_002F2110(*s);
        s++;
    }
}

void func_0017A978(char *s)
{
    while (*s != 0) {
        *s = func_002F2130(*s);
        s++;
    }
}
