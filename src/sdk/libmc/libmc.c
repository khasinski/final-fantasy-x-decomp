/* tu_353 0x2deef0-0x2e06d0: medium; libmc (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"

INCLUDE_ASM("build/ee_asm/sdk/libmc/libmc", func_002DEEF0);

SifClientData *func_002DF0A8(s32 **rdata, s32 **cmd)
{
    *rdata = D_0078D5C0;
    *cmd = &D_00566388;
    D_0078D5C0[15] = D_0056638C;
    return &D_0078C000;
}

int func_002DF0D8(int a)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.origin = a;
    ret = func_002FB4C8(&D_0078C000, 0x14, 1, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0x14;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002DF190(int port)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.port = port;
    ret = func_002FB4C8(&D_0078C000, 0x15, 0, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret != 0) {
        func_002F8400(D_0056638C);
        return ret;
    }
    func_002F8400(D_0056638C);
    return D_0078D5C0[0];
}

int func_002DF250(int port, int slot, int name, int flags)
{
    char *path = (char *)name; /* DEBT(TYPE): shared prototype passes the path as int */
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    if (path == 0 || *path == 0) {
        func_002F8400(D_0056638C);
        return -210;
    }
    func_002F0C10(D_0078C0B0.name, path, 0x3FF);
    D_0078C0B0.port = port;
    D_0078C0B0.flags = flags;
    D_0078C0B0.slot = slot;
    D_0078C0B0.name[0x3FF] = 0;
    ret = func_002FB4C8(&D_0078C000, 2, 1, &D_0078C0B0, 0x414, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 2;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002DF388(int port, int slot, int name)
{
    int ret = func_002DF250(port, slot, name, 0x40);

    if (ret == 0) {
        D_00566388 = 0xB;
    }
    return ret;
}

int func_002DF3C0(int fd)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.fd = fd;
    ret = func_002FB4C8(&D_0078C000, 3, 1, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 3;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002DF478(int fd, int offset, int origin)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.fd = fd;
    D_0078C080.offset = offset;
    D_0078C080.origin = origin;
    ret = func_002FB4C8(&D_0078C000, 4, 1, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 4;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

void func_002DF550(McReadEnd *p)
{
    McReadEnd *u = UNCACHED(p);
    u8 *dst;
    int i;

    if (u->size1 != 0) {
        dst = u->dest1;
        for (i = 0; i < u->size1; i++) {
            *dst++ = u->buf1[i];
        }
    }
    if (u->size2 != 0) {
        dst = u->dest2;
        for (i = 0; i < u->size2; i++) {
            *dst++ = u->buf2[i];
        }
    }
}

int func_002DF5E0(int fd, int buf, int size)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.fd = fd;
    D_0078C080.param = &D_0078C500;
    D_0078C080.buffer = (u8 *)buf; /* DEBT(TYPE): shared prototype passes the buffer as int */
    D_0078C080.size = size;
    func_002FABD8((void *)buf, size);
    func_002FABD8(&D_0078C500, 0xC0);
    ret = func_002FB4C8(&D_0078C000, 5, 1, &D_0078C080, 0x30, D_0078D5C0, 4, func_002DF550, &D_0078C500);
    if (ret == 0) {
        D_00566388 = 5;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002DF700(int fd, int buf, int size)
{
    u8 *src = (u8 *)buf; /* DEBT(TYPE): shared prototype passes the buffer as int */
    u8 *base;
    int ret;
    u32 i;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.fd = fd;
    if (size < 17) {
        D_0078C080.origin = size;
        D_0078C080.size = 0;
        D_0078C080.buffer = 0;
    } else {
        base = src - 16; /* DEBT(FAKE): keeps (src - 16) from being folded */
        D_0078C080.origin = ((u32)(src - 1) & 0xFFFFFFF0) - (u32)base;
        D_0078C080.size = size - D_0078C080.origin;
        D_0078C080.buffer = src + D_0078C080.origin;
    }
    for (i = 0; i < D_0078C080.origin; i++) {
        D_0078C080.data[i] = src[i];
    }
    func_002F8660(0);
    ret = func_002FB4C8(&D_0078C000, 6, 1, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 6;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

extern void func_002F9318(s32 sema);
void func_002DF880_(s32 a, s32 b, s32 sema) __asm__("func_002DF880");
void func_002DF880_(s32 a, s32 b, s32 sema)
{
    func_002F9318(sema);
    SYNC();
    EI();
}

void func_002DF8A8(u16 id)
{
    func_002F8160(id, func_002DF880, func_002F82D0());
    func_002F8300();
}

int func_002DF8F0(int mode, int *cmd, int *result)
{
    int ret;

    if (D_00566388 == 0) {
        return -1;
    }
    ret = func_002FB6B8(&D_0078C000);
    if (mode == 0 && ret != 0) {
        while (func_002FB6B8(&D_0078C000) != 0) {
            func_002DF8A8(0x3C);
        }
        ret = 0;
    }
    ret = ret == 0;
    if (cmd != 0) {
        *cmd = D_00566388;
    }
    if (ret != 0) {
        D_00566388 = 0;
        if (result != 0) {
            *result = D_0078D5C0[0];
        }
        func_002F8400(D_0056638C);
    }
    return ret;
}

void func_002DF9D0(u32 addr)
{
    u32 *r = (u32 *)(addr | 0x20000000);

    if (D_0078C028 != 0) {
        *D_0078C028 = r[0];
    }
    if (D_0078C02C != 0) {
        *D_0078C02C = r[1];
    }
    if (D_0078C030 != 0) {
        *D_0078C030 = r[0x24];
    }
}

int func_002DFA28(int port, int slot, u32 *type, u32 *free, u32 *format)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.port = port;
    D_0078C080.slot = slot;
    D_0078C080.param = &D_0078C500;
    if (type != 0) {
        D_0078C080.origin = 1;
    } else {
        D_0078C080.origin = 0;
    }
    if (free != 0) {
        D_0078C080.offset = 1;
    } else {
        D_0078C080.offset = 0;
    }
    if (format != 0) {
        D_0078C080.size = 1;
    } else {
        D_0078C080.size = 0;
    }
    D_0078C028 = type;
    D_0078C02C = free;
    D_0078C030 = format;
    func_002FABD8(&D_0078C500, 0xC0);
    ret = func_002FB4C8(&D_0078C000, 1, 1, &D_0078C080, 0x30, D_0078D5C0, 4, func_002DF9D0, &D_0078C500);
    if (ret == 0) {
        D_00566388 = 1;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002DFBB0(int port, int slot, const char *name, int flags, int maxent, McTblGetDir *table)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    if (name == 0 || *name == 0) {
        func_002F8400(D_0056638C);
        return -210;
    }
    D_0078C0B0.port = port;
    D_0078C0B0.slot = slot;
    D_0078C0B0.flags = flags;
    D_0078C0B0.maxent = maxent;
    D_0078C0B0.table = table;
    func_002F0C10(D_0078C0B0.name, name, 0x3FF);
    D_0078C0B0.name[0x3FF] = 0;
    if (maxent >= 0) {
        func_002FABD8(table, maxent * sizeof(McTblGetDir));
    }
    ret = func_002FB4C8(&D_0078C000, 0xD, 1, &D_0078C0B0, 0x414, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0xD;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

void func_002DFD08(char *dst)
{
    u32 n;

    if (dst != 0) {
        /* DEBT(TYPE): strlen is declared int in funcs.h, the code compares it unsigned (size_t) */
        n = (u32)func_002F0840(UNCACHED(D_0078C5C0)) < 0x400 ? func_002F0840(UNCACHED(D_0078C5C0)) : 0x3FF;
        func_002EEF1C(dst, UNCACHED(D_0078C5C0), n);
        dst[n] = 0;
    }
}

int func_002DFD90(int port, int slot, int name, int dst)
{
    char *path = (char *)name; /* DEBT(TYPE): shared prototype passes the path as int */
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    if (path == 0 || *path == 0) {
        func_002F8400(D_0056638C);
        return -210;
    }
    D_0078C0B0.port = port;
    D_0078C0B0.table = D_0078C5C0;
    D_0078C0B0.slot = slot;
    func_002F0C10(D_0078C0B0.name, path, 0x3FF);
    D_0078C0B0.name[0x3FF] = 0;
    func_002FABD8(D_0078C5C0, 0x400);
    ret = func_002FB4C8(&D_0078C000, 0xC, 1, &D_0078C0B0, 0x414, D_0078D5C0, 4, func_002DFD08, (void *)dst);
    if (ret == 0) {
        D_00566388 = 0xC;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002DFEE0(int port, int slot)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.slot = slot;
    D_0078C080.port = port;
    ret = func_002FB4C8(&D_0078C000, 0x10, 1, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0x10;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002DFFA8(int port, int slot, int name)
{
    char *path = (char *)name; /* DEBT(TYPE): shared prototype passes the path as int */
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    if (path == 0 || *path == 0) {
        func_002F8400(D_0056638C);
        return -210;
    }
    func_002F0C10(D_0078C0B0.name, path, 0x3FF);
    D_0078C0B0.port = port;
    D_0078C0B0.slot = slot;
    D_0078C0B0.name[0x3FF] = 0;
    D_0078C0B0.flags = 0;
    ret = func_002FB4C8(&D_0078C000, 0xF, 1, &D_0078C0B0, 0x414, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0xF;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002E00D0(int fd)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.fd = fd;
    ret = func_002FB4C8(&D_0078C000, 0xA, 1, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0xA;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002E0188(int port, int slot, const char *name, McTblGetDir *info, u32 flags)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    if (name == 0 || *name == 0) {
        func_002F8400(D_0056638C);
        return -210;
    }
    D_0078C0B0.port = port;
    D_0078C0B0.slot = slot;
    flags &= 7; /* DEBT(FAKE): masks the parameter in place */
    D_0078C0B0.flags = flags;
    D_0078C040 = *info;
    D_0078C0B0.table = &D_0078C040;
    func_002F0C10(D_0078C0B0.name, name, 0x3FF);
    D_0078C0B0.name[0x3FF] = 0;
    func_002F8660(0);
    ret = func_002FB4C8(&D_0078C000, 0xE, 1, &D_0078C0B0, 0x414, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0xE;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002E0360(int port, int slot, int name, int newname)
{
    char *path = (char *)name; /* DEBT(TYPE): shared prototype passes the paths as int */
    char *dst = (char *)newname;
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    if (path == 0 || *path == 0 || dst == 0) {
        func_002F8400(D_0056638C);
        return -210;
    }
    D_0078C0B0.port = port;
    D_0078C0B0.slot = slot;
    D_0078C0B0.flags = 0x10;
    func_002F0C10(D_0078C0B0.name, path, 0x3FF);
    D_0078C0B0.name[0x3FF] = 0;
    func_002F0C10(D_0078C040.name, dst, 0x20);
    D_0078C040.name[0x1F] = 0;
    D_0078C0B0.table = &D_0078C040;
    func_002F8660(0);
    ret = func_002FB4C8(&D_0078C000, 0xE, 1, &D_0078C0B0, 0x414, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0x13;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002E04C8(int port, int slot)
{
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    D_0078C080.slot = slot;
    D_0078C080.port = port;
    ret = func_002FB4C8(&D_0078C000, 0x11, 1, &D_0078C080, 0x30, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0x11;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

int func_002E0590(int port, int slot, int name)
{
    char *path = (char *)name; /* DEBT(TYPE): shared prototype passes the path as int */
    int ret;

    if (func_002F8430(D_0056638C) < 0) {
        return -200;
    }
    if (D_0078C000.serve == 0) {
        func_002F8400(D_0056638C);
        return -100;
    }
    if (path == 0 || *path == 0) {
        func_002F8400(D_0056638C);
        return -210;
    }
    D_0078C0B0.port = port;
    D_0078C0B0.slot = slot;
    func_002F0C10(D_0078C0B0.name, path, 0x3FF);
    D_0078C0B0.name[0x3FF] = 0;
    ret = func_002FB4C8(&D_0078C000, 0x12, 1, &D_0078C0B0, 0x414, D_0078D5C0, 4, 0, 0);
    if (ret == 0) {
        D_00566388 = 0x12;
    } else {
        func_002F8400(D_0056638C);
    }
    return ret;
}

void func_002E06A8_(s32 a, s32 b, s32 sema) __asm__("func_002E06A8");
void func_002E06A8_(s32 a, s32 b, s32 sema)
{
    func_002F8410(sema);
    SYNC();
    EI();
}
