/* tu_109 0x165eb8-0x1691c8: medium; hddcopy (config/tu_map.tsv) */
#define func_00165F70 _hdr_func_00165F70
#define D_005661F4 _hdr_D_005661F4
#define D_0030E0BC _hdr_D_0030E0BC
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/b0.h"
#include "ffx/u1.h"
#include "ffx/v1.h"
#include "ffx/s1.h"
#include "ffx/w2.h"
#undef D_0030E0BC
#undef D_005661F4
#undef func_00165F70

extern s8 D_005661F4;
extern s8 D_0030DDFE;
extern int D_0030DE84;
extern int D_0030DE8C;
extern u8 *D_0030E0BC;
extern u8 *D_0030E0D0;
extern s8 D_005979D8;
extern int D_005979DC;
extern int D_005979E0;
extern int D_005979E4;
extern s8 *D_005979E8;
extern s8 *D_005979EC;
extern int D_005979F0;
extern s32 D_0078E4B0;
extern char D_0056BFD0[];
extern char D_0056BFE0[];
extern char D_0056BFF8[];
extern s32 *D_0057CB84 __asm__("D_0057CB80+4");
extern s32 D_0057CB88 __asm__("D_0057CB80+8");
extern s32 D_0057CB8C __asm__("D_0057CB80+12");
extern int D_0057CB94;
int func_002FD3A0(int fd, int cmd, void *arg, int arglen, void *buf, int buflen);
int hdd_ins_check(int a);
void func_00168608(int a, int b);
void func_00168760(int a, int b);
void func_0016C920(u32 *pkt, int x, int y, int w, int h);
void func_00170A90(void);
void func_00170B10(void);
void func_002DA928(void *buf, short tbp, int bw, int psm, int x, int y, int w, int h);
void func_002DAC50(void *buf, void *src);

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

int func_00165FA8(void)
{
    int i;
    u8 *cfg = TkGetFFXCofingAdrs() + 0x11;
    Rec597490 *r = D_00597490;

    for (i = 0; i < 50; i++, r++) {
        int bit = cfg[i / 8] & (1 << (i & 7));
        func_00165F30(i, bit == 0);
        r->q08 = (s64)D_0057CB84[i] << 11;
        D_0078E498.f10(i);
        r->q00 = (u32)D_0078E498.f04(0);
    }
    D_0030DE54 = 50;
    return 0;
}

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

void hdd_ins_size_check(void)
{
    char path[0x40];
    int fd;
    int old_mounted = D_0030DE81;
    int cur_size = 0;
    u32 need;

    D_0030DE8C = 0;
    if (old_mounted != 0) {
        func_00166458();
    }
    func_001660C0();
    func_002F0008(path, D_0056BFD0, func_001672C0(), D_0030DE78);
    fd = func_002FC4E0(path, 1);
    if (fd >= 0) {
        cur_size = func_002FD3A0(fd, 0x6803, 0, 0, 0, 0);
        if (cur_size < 0) {
            cur_size = 0;
        }
        func_002FDD88(fd);
        cur_size++;
    }
    func_001661A8();
    need = ((u32)((int (*)())func_001679A8)(0) >> 7) - cur_size;
    if (!func_00167B20(D_0056BEC0, need)) {
        D_0030DE8C = -1;
    }
    if (old_mounted != 0) {
        func_001663A0();
    }
}

void hdd_install_init(void)
{
    int r;

    D_005979E4 = D_005661F4;
    D_0030DE51 = 0;
    D_00597978 = 0;
    D_00597980 = 0;
    D_005661F4 = 0;
    D_0030DE90 = 0;
    r = func_00166FC0();
    switch (((r < 0) ? -r : r) & 0xF) {
    case 0:
        if (D_0030DE8C < 0) {
            D_0030DE90 = 5;
        }
        break;
    case 1:
        D_0030DE90 = 1;
        break;
    case 2:
        D_0030DE90 = 2;
        break;
    case 3:
        D_0030DE90 = 3;
        break;
    }
    D_005661F4 = D_005979E4;
}

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

int func_00167E30(void)
{
    int err = 0;
    int i;
    int fd;
    s64 size;
    s64 end;

    TkyiAssert(D_0056BFE0);
    for (i = 0; i < D_0030DE54; i++) {
        size = D_00597490[i].q08;
        if (size != 0 && hdd_rmode_get(i) != 0) {
            fd = func_002FC4E0(get_hdd_name(i), 1);
            if (fd < 0) {
                err++;
            } else {
                end = func_002FEA60(fd, 0, 2);
                func_002FC768(fd);
                if (size != end) {
                    err++;
                }
            }
        }
    }
    TkyiAssert(D_0056BFF8);
    return err;
}

int get_hdd_inst_info(void) {
    if (D_0030DE50 != 0) {
        return 2;
    }
    return D_0030DE94;
}

int hdd_install_check(int a)
{
    int ret = 0;
    int r;

    D_0030DE8C = 0;
    D_0030DE94 = 0;
    r = func_00166FC0();
    r = (r < 0) ? -r : r;
    r &= 0xF;
    switch (r) {
    case 0:
        if (func_001663A0() != 0) {
            D_005661F4 = 0;
        } else if (func_00167E30() != 0) {
            D_0030DE94 = 2;
            D_005661F4 = 0;
            func_00166458();
        } else {
            ret = hdd_ins_check(a);
            D_0030DE94 = 1;
            if (D_0030DDFE != 0 && D_0078E4B0 == 1) {
                D_005661F4 = 1;
                TkRefreshHDDMode();
            }
        }
        if (D_0030DE54 == 0) {
            ret = 0;
            func_00166458();
            D_005661F4 = 0;
        }
        break;
    case 1:
    case 2:
    case 3:
        D_005661F4 = 0;
        break;
    }
    return ret;
}

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

void func_00168608(int idx, int tbp)
{
    u8 buf[0x60];
    u8 *pal;
    u8 *src;
    int y;
    int x;

    pal = D_0030E0D0 + (idx << 10);
    src = D_0030E0D0 + (idx * 0x24C1 + 0x10400);
    func_002EF0D0(D_0030E0BC, 0, 0x4000);
    for (y = 0; y < 0x61; y++) {
        for (x = 0; x < 0x61; x++) {
            D_0030E0BC[(y << 7) + x] = *src++;
        }
    }
    func_002DA928(buf, tbp, 1, 0, 0, 0, 0x10, 0x10);
    func_002F8660(0);
    func_002DAC50(buf, pal);
    func_002DA610(0, 0);
    func_002DA928(buf, tbp + 4, 2, 0x13, 0, 0, 0x80, 0x80);
    func_002F8660(0);
    func_002DAC50(buf, D_0030E0BC);
    func_002DA610(0, 0);
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168760);

void func_00168968(void)
{
    int pct;

    if (D_00597978 == 0) {
        pct = 0;
    } else {
        pct = func_002E9C38(D_00597980 << 6, D_00597978);
    }
    if (pct != D_0057CB94) {
        D_0057CB94 = pct;
        func_00168608(pct, D_0030E094);
    }
    func_00170A90();
}

void func_001689C8(void)
{
    int pct;

    if (D_00597978 == 0) {
        pct = 0;
    } else {
        pct = func_002E9C38(D_00597980 << 6, D_00597978);
    }
    if (D_0057CB88 == pct) {
        D_0057CB88 += 14;
        func_00168760(D_0057CB8C, D_0030E094 + 0x44);
        D_0057CB8C++;
        if (D_0057CB8C >= 5) {
            D_0057CB88 = 9999;
        }
    }
    func_00170B10();
}

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168A60);

INCLUDE_ASM("build/ee_asm/game/hddcopy", func_00168B88);
