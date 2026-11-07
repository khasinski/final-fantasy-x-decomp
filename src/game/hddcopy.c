/* tu_109 0x165eb8-0x1691c8: medium; hddcopy (config/tu_map.tsv) */
#define func_00165F70 _hdr_func_00165F70
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/b0.h"
#include "ffx/u1.h"
#include "ffx/v1.h"
#include "ffx/s1.h"
#include "ffx/w2.h"
#undef func_00165F70

void TkyiAssert(const char *msg)
{
    if (D_0030DE58 == 0) {
        func_00125558(msg);
    }
}

int get_hdd_err(void) {
    return D_0030DE50;
}

void func_00165EE8(s8 v) {
    D_0030DE50 = v;
}

void func_00165EF8(void) {
    int i;

    for (i = 0; i < 51; i++) {
        D_00597490[i].q00 = 0;
        D_00597490[i].q08 = 0;
        D_00597490[i].b10 = 1;
    }
}

void func_00165F30(int i, int v) {
    Rec597490 *r = &D_00597490[i];

    r->b10 = v;
}

int hdd_rmode_get(int i) {
    Rec597490 *r = &D_00597490[i];

    return r->b10;
}

s64 func_00165F70(s32 arg0) {
    s64 m1 = -1;
    s64 v = D_00597490[arg0].q08;
    s64 v2 = v + 0x7FF;
    __asm__("" : "+r"(m1));
    if (m1 < v) {
        v2 = v;
    }
    return (v2 << 21) >> 32;
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00165FA8);

void func_001660B0(void) {
    func_00168B88();
}

void func_001660B8(void) {
}

void func_001660C0(void)
{
    int i;
    int k;

    D_0030DE68[0] = -0x62;
    D_0030DE68[1] = -0x63;
    D_0030DE68[2] = -0x57;
    D_0030DE68[3] = -0x69;
    D_0030DE68[4] = -0x66;
    D_0030DE68[5] = -0x60;
    D_0030DE68[6] = -0x66;
    D_0030DE68[7] = -0x58;
    D_0030DE78[0] = -0x5F;
    D_0030DE78[1] = -0x6B;
    D_0030DE78[2] = -0x59;
    D_0030DE78[3] = -0x61;
    D_0030DE78[4] = -0x5E;
    D_0030DE78[5] = -0x63;
    D_0030DE78[6] = -0x59;
    D_0030DE78[7] = 0x6B;
    for (i = 0; i < 8; i++) {
        k = i + 0x33;
        D_0030DE68[i] -= k;
        D_0030DE78[i] -= k;
    }
}

void func_001661A8(void)
{
    D_0030DE68[0] = 'f';
    D_0030DE68[1] = 'f';
    D_0030DE68[2] = 'x';
    D_0030DE68[3] = 'p';
    D_0030DE68[4] = 'a';
    D_0030DE68[5] = 's';
    D_0030DE68[6] = 's';
    D_0030DE68[7] = 'f';
    D_0030DE78[0] = 'f';
    D_0030DE78[1] = 'f';
    D_0030DE78[2] = 'x';
    D_0030DE78[3] = 'p';
    D_0030DE78[4] = 'a';
    D_0030DE78[5] = 's';
    D_0030DE78[6] = 's';
    D_0030DE78[7] = 'r';
}

char *get_hdd_name(int a) {
    func_002F0008(D_00597958, D_0056BD60, a);
    return D_00597958;
}

int func_00166258(int i)
{
    return func_00163188(i) - (int)D_00597490[i].q00;
}

void func_00166298(int v)
{
    char buf[16];
    char *p = buf;
    int mode = (u16)v;
    int i;

    for (i = 9; i >= 0; i--) {
        if ((mode >> i) & 1) {
            if (i == 9) {
                *p++ = 's';
            } else if (i % 3 == 2) {
                *p++ = 'r';
            } else if (i % 3 == 1) {
                *p++ = 'w';
            } else if (i % 3 == 0) {
                *p++ = 'x';
            }
        } else {
            *p++ = '-';
        }
    }
    *p = 0;
}

void func_00166358(u16 *p) {
    func_00166298(*p);
}

void func_00166360(int a) {
    u16 buf[0x20];

    if (func_002FE048(a, buf) >= 0) {
        func_00166358(buf);
    }
}

int func_00166390(void) {
    return D_0030DE81;
}

int func_001663A0(void)
{
    char path[0x80];

    if (D_0030DE81 == 0) {
        func_001660C0();
        func_002F0008(path, D_0056BD70, func_001672C0(), D_0030DE68);
        func_001661A8();
        TkyiAssert(D_0056BD80);
        if (func_002FE7D0(D_0056BD90, path, 0, 0, 0) < 0) {
            TkyiAssert(D_0056BD98);
            return 1;
        }
        TkyiAssert(D_0056BDB0);
        D_0030DE81 = 1;
    }
    return 0;
}

int func_00166458(void)
{
    int r;

    if (D_0030DE81 != 0) {
        TkyiAssert(D_0056BDC8);
        r = func_002FEA40((int)D_0056BD90); /* DEBT(CAST): funcs.h types the device name as int */
        if (r == 0) {
            TkyiAssert(D_0056BDD8);
            D_0030DE81 = 0;
            return 0;
        }
        TkyiAssert(D_0056BDF0);
        return r;
    }
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_001664D8);

INCLUDE_ASM("build/ee_asm/game/hddcopy", hd_file_read_th);

void func_001667B8(char *path, u8 *buf, int size, s64 offset)
{
    int i = 0;

    D_00597988[0] = path[0];
    while (path[i] != 0) {
        i++;
        D_00597988[i] = path[i];
    }
    D_005979C8 = buf;
    D_005979CC = size;
    D_005979D0 = offset;
    while (D_0030DE34 != 0) {
        func_0017135C(1);
    }
    D_0030DE34 = 3;
    TkSignalSemaBGThread();
    while (D_0030DE34 != 0) {
        func_0017135C(1);
    }
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", hd_file_read_th_main);

int hd_file_read_no_wait(int unused, char *buf, int size, int i, int fd)
{
    if (D_00597490[i].q08 == 0) {
        return 0;
    }
    func_002FCB20(fd, buf, size);
    return 0;
}

int movie_hdd_file_open(int i, u64 sector) {
    int fd;
    int busy;
    char *path;
    s64 offset;

    if (D_00597490[i].q08 == 0) {
        return -1;
    }
    path = get_hdd_name(i);
    offset = (sector - D_00597490[i].q00) << 11;
    fd = func_002FC4E0(path, 0x8001);
    if (fd < 0) {
        BREAK();
        return -1;
    }
    if ((int)func_002FEA60(fd, offset, 0) < 0) {
        BREAK();
        return -1;
    }
    while (func_002FD050(fd, 1, &busy), busy != 0) {
        func_0017135C(1);
    }
    return fd;
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00166AB0);

INCLUDE_ASM("build/ee_asm/game/hddcopy", hdd_ins_check);

int func_00166FC0(void)
{
    int r;

    TkyiAssert(D_0056BEA8);
    r = func_002FEC98(D_0056BEC0, 0x4807, 0, 0, 0, 0);
    TkyiAssert(D_0056BEC8);
    return r;
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00167020);

char *func_001672C0(void)
{
    switch (FFXGetLang()) {
    case 1:
        return D_0056BF00;
    case 2:
        return D_0056BF18;
    case 3:
        return D_0056BF30;
    case 4:
        return D_0056BF48;
    case 5:
        return D_0056BF60;
    case 6:
        return D_0056BF78;
    case 0:
    default:
        return D_0056BF90;
    }
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00167358);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00167488);

int func_00167920(void)
{
    u32 total = 0;
    int n = D_0030DE54;
    int i;

    for (i = 0; i < n; i++) {
        if (hdd_rmode_get(i)) {
            total += (u32)D_00597490[i].q08;
        }
    }
    return ((total >> 20) + 0xFF & 0x1F80) + 0x80;
}

int func_001679A8(void)
{
    u32 total = 0;
    int n = D_0030DE54;
    int i;

    for (i = 0; i < n; i++) {
        if (hdd_rmode_get(i)) {
            total += (u32)D_00597490[i].q08;
        }
    }
    return ((total >> 20) + 0xFF & 0x1F80) + 0x100;
}

int func_00167A30(char *path, int mode)
{
    DirEnt ent;
    int n = 0;
    int fd;

    fd = func_002FDCC0(path);
    if (fd < 0) {
        return 0;
    }
    while (func_002FDEF0(fd, &ent) > 0) {
        if (ent.w0 == 0 && ent.size == mode) {
            n++;
        }
    }
    func_002FDD88(fd);
    return n;
}

int func_00167AB8(char *path)
{
    DirEnt ent;
    int total = 0;
    int fd;

    fd = func_002FDCC0(path);
    if (fd < 0) {
        return 0;
    }
    while (func_002FDEF0(fd, &ent) > 0) {
        total += ent.size;
    }
    func_002FDD88(fd);
    return total;
}

int func_00167B20(char *dev, u32 need)
{
    u32 st[4];

    if (func_002FEC98(dev, 0x480A, 0, 0, st, 4) != 0) {
        return 0;
    }
    return (st[0] >> 18) >= need;
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", hdd_ins_size_check);

INCLUDE_ASM("build/ee_asm/game/hddcopy", hdd_install_init);

int func_00167D50(void) {
    return D_0030DE90;
}

void hdd_install_end(void) {
    func_00162CD8(0);
    func_0016BC80(0);
    func_00162DE0();
}

int func_00167D88(void) {
    return D_0030DE90;
}

int func_00167D98(void)
{
    int pct;

    if (D_00597978 == 0) {
        return 0;
    }
    pct = func_002E9C38(D_00597980 * 100, D_00597978);
    if (pct >= 100) {
        pct = 100;
    }
    return pct;
}

void hdd_format_sub(void) {
    if (func_002FD910(D_0056BEC0, 0, 0, 0) < 0) {
        BREAK();
    }
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00167E30);

int get_hdd_inst_info(void) {
    if (D_0030DE50 != 0) {
        return 2;
    }
    return D_0030DE94;
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", hdd_install_check);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168090);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168328);

INCLUDE_ASM("build/ee_asm/game/hddcopy", hdd_inst_start_sub);

int func_001685C8(void) {
    int v = D_0030DE51;

    if (v == 2) {
        return 1;
    }
    if (v == -1) {
        return 2;
    }
    return v == -2 ? 3 : 0;
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168608);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168760);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168968);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_001689C8);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168A60);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168B88);
