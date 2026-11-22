/* tu_035 0x11ee40-0x11f8d0: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

void func_0011EE40(s32 v)
{
    D_00307FA0 = v;
}

s32 Sg_PcReadGetLen(void)
{
    return D_00580B00;
}

extern char D_00569D78[];
extern char D_00569D88[];
extern char D_00569D98[];
extern char D_00569DC0[];
extern char D_00569DD0[];
extern char D_00569DE8[];
int func_002FC8E8(int fd, int offset, int whence);
int func_002FCB20(int fd, void *buf, int len);
void *func_0011D4B8(s32 size, s32 heap, const char *file, s32 line);

void *Sg_PcReadL(char *filename, void *buf, int offset, int len)
{
    char path[0x80];
    int fd = 0;

    if (ffx_debugmode == 0 || (func_002F0008(path, D_00569D78, filename), (fd = func_002FC4E0(path, 1)) < 0)) {
        if (D_00307FA0 != 0) {
            D_00307FA0 = 1;
            return 0;
        }
        yiAssert(0, D_00569D88, D_00569D98, filename, offset, len);
    }
    func_002FC8E8(fd, offset, 0);
    func_002FCB20(fd, buf, len);
    func_002FC768(fd);
    D_00307FA0 = 1;
    return buf;
}

s32 _Sg_PcRead(s32 filename, s32 mode)
{
    char path[0x80];
    int fd;
    s32 buf;

    func_002F0008(path, D_00569D78, filename);
    fd = func_002FC4E0(path, 1);
    if (fd < 0) {
        if (D_00307FA0 != 0) {
            D_00307FA0 = 1;
            return 0;
        }
        yiAssert(0, D_00569DC0, D_00569DD0, filename);
    }
    D_00580B00 = func_002FC8E8(fd, 0, 2);
    buf = 0;
    func_002FC8E8(fd, 0, 0);
    switch (mode) {
    case 2:
        buf = (s32)func_0011D4B8(D_00580B00, 6, D_00569DE8, 0x93);
        break;
    case 1:
        buf = (s32)func_0011D420(D_00580B00, 6, D_00569DE8, 0x94);
        break;
    case 0:
        buf = (s32)user_malloc(D_00580B00, 6, D_00569DE8, 0x95);
        break;
    }
    func_002FCB20(fd, (void *)buf, D_00580B00);
    func_002FC768(fd);
    D_00307FA0 = 1;
    return buf;
}

s32 Sg_PcRead(s32 a)
{
    s32 r = _Sg_PcRead(a, 0);

    Sg_MemSetCurrentAddr(r);
    return r;
}

s32 Sg_PcReadD(s32 a)
{
    s32 r = _Sg_PcRead(a, 1);

    Sg_MemSetCurrentAddr(r);
    return r;
}

s32 Sg_PcReadH(s32 a)
{
    s32 r = _Sg_PcRead(a, 2);

    Sg_MemSetCurrentAddr(r);
    return r;
}

void Sg_PcWrite(int *data, int bytes, int index)
{
    char path[0x100];
    int fd;
    if (ffx_debugmode != 0) {
        func_002F0008(path, D_00569DF0, D_00569DF8, index);
        fd = func_002FC4E0(path, 0x602);
        if (fd < 0) {
            yiAssert(0, D_00569E00, D_00569E10, index);
            return;
        }
        func_002FCD90(fd, data, bytes);
        func_002FC768(fd);
    }
}

void func_0011F248(s8 v)
{
    D_00307FDE = v;
}

void func_0011F258(s8 v)
{
    D_00580B04 = v;
}

s8 Sg_CaptureGetSelect(void)
{
    return D_00580B04;
}

void func_0011F278(s8 v)
{
    D_00580B05 = v;
}

s8 func_0011F288(void)
{
    return D_00580B05;
}

void func_0011F298(s8 v)
{
    D_00307FDF = v;
}

s8 func_0011F2A8(void)
{
    return D_00307FDF;
}

extern char D_00569E30[];
extern u8 D_00307FA8[];
extern u8 D_005809B0[];
extern u8 D_00580A90[];
void func_002DAB10(void *, int, int, int, int, int, int, int);
void func_002F8660(int);
void func_202CF08(char *, ...);
void *user_malloc(int, int, const char *, int);

void Sg_CaptureToFile(char *name)
{
    char path[0x100];
    int fd;
    u8 *buf1;
    u8 *buf2;
    u8 *out;
    u8 *dst;
    u8 *src;
    int tbp1;
    int tbp2;
    int bytes;
    int y;
    int x;

    if (D_00307F2C & 1) {
        tbp1 = 0;
        tbp2 = 0xD00;
    } else {
        tbp2 = 0;
        tbp1 = 0xD00;
    }
    func_002F0008(path, D_00569DF0, D_00569DF8, name);
    fd = func_002FC4E0(path, 0x602);
    buf1 = (u8 *)func_0011D420(0xD0000, 6, D_00569DE8, 0x103);
    buf2 = (u8 *)func_0011D420(0xD0000, 6, D_00569DE8, 0x104);
    out = (u8 *)func_0011D420(0x138000, 6, D_00569DE8, 0x105);
    func_002DAB10(D_005809B0, tbp1, 8, 0, 0, 0, 0x200, 0x1A0);
    func_002DAB10(D_005809B0 + 0x70, tbp2, 8, 0, 0, 0, 0x200, 0x1A0);
    func_002F8660(0);
    func_002DADD0(D_005809B0, buf1);
    func_002DADD0(D_005809B0 + 0x70, buf2);
    func_002DA610(0, 0);
    {
        s8 *hdr = (s8 *)D_00307FA8;

        hdr[0x16] = -0x60;
        hdr[0x17] = 1;
        func_002FCD90(fd, hdr, 0x36);
    }
    bytes = 0;
    dst = out;
    if (D_00307FDE != 0) {
        if (D_00307FDF != 0) {
            for (y = 0x19F; y >= 0; y--) {
                src = buf1 + (y << 11);
                if (y != 0) {
                    for (x = 0x1FF; x >= 0; x--) {
                        dst[2] = (src[0] + src[0x800]) >> 1;
                        dst[1] = (src[1] + src[0x801]) >> 1;
                        dst[0] = (src[2] + src[0x802]) >> 1;
                        src += 4;
                        dst += 3;
                    }
                    bytes += 0x600;
                } else {
                    for (x = 0; x < 0x200; x++) {
                        dst[2] = src[0];
                        dst[1] = src[1];
                        dst[0] = src[2];
                        src += 4;
                        dst += 3;
                    }
                    bytes += 0x600;
                }
            }
        } else {
            for (y = 0x19F; y >= 0; y--) {
                src = buf1 + (y << 11);
                src++;
                for (x = 0x1FF; x >= 0; x--) {
                    dst[2] = src[-1];
                    dst[1] = src[0];
                    dst[0] = src[1];
                    src += 4;
                    dst += 3;
                }
                bytes += 0x600;
            }
        }
    } else {
        for (y = 0x19E; y >= 0; y -= 2) {
            src = buf1 + (y << 11);
            src++;
            for (x = 0x1FF; x >= 0; x--) {
                u8 c;

                c = src[-1];
                dst[2] = c;
                dst[0x602] = c;
                c = src[0];
                dst[1] = c;
                dst[0x601] = c;
                c = src[1];
                dst[0] = c;
                dst[0x600] = c;
                src += 4;
                dst += 3;
            }
            dst += 0x600;
            bytes += 0xC00;
        }
    }
    func_002FCD90(fd, out, bytes);
    func_002FC768(fd);
    func_002F0008(path, D_00569E30, name);
    func_202CF08(path, out);
    func_0011D590(buf2, 6);
    func_0011D590(buf1, 6);
    func_0011D590(out, 6);
}

void func_0011F658(char *name)
{
    char path[0x100];
    int fd;
    u8 *buf1;
    u8 *buf2;
    u8 *line;
    /* DEBT(FAKE): register pins align inner-loop pointer allocation. */
    register u8 *dst __asm__("$5");
    u8 *src;
    int y;
    int x;

    func_002F0008(path, D_00569DF0, D_00569DF8, name);
    fd = func_002FC4E0(path, 0x602);
    buf1 = (u8 *)user_malloc(0xD0000, 6, D_00569DE8, 0x19D);
    buf2 = (u8 *)user_malloc(0xD0000, 6, D_00569DE8, 0x19E);
    line = (u8 *)user_malloc(0xC00, 6, D_00569DE8, 0x19F);
    func_002DAB10(D_00580A90, 0x1A00, 8, 0x30, 0, 0, 0x200, 0x1A0);
    func_002F8660(0);
    func_002DADD0(D_00580A90, buf1);
    func_002DA610(0, 0);
    func_002DAB10(D_00580A90, 0x1A00, 8, 0x30, 0, 0, 0x200, 0x1A0);
    func_002F8660(0);
    func_002DADD0(D_00580A90, buf2);
    func_002DA610(0, 0);
    func_002FCD90(fd, D_00307FA8, 0x36);
    for (y = 0x1A0; y >= 0; y--) {
        dst = line;
        src = buf1 + (y << 11) + 1;
        for (x = 0; x < 0x200; x++) {
            /* DEBT(FAKE): register pin aligns z temporary to $a0. */
            register int t __asm__("$4") = src[-1];
            int z = (t | (src[0] << 8) | (src[1] << 16)) >> 10;
            src += 4;
            dst[0] = z;
            dst[1] = z;
            dst[2] = z;
            dst += 3;
        }
        src = buf2 + (y << 11) + 1;
        for (x = 0; x < 0x200; x++) {
            /* DEBT(FAKE): register pin aligns z temporary to $a0. */
            register int t __asm__("$4") = src[-1];
            int z = (t | (src[0] << 8) | (src[1] << 16)) >> 10;
            src += 4;
            dst[0] = z;
            dst[1] = z;
            dst[2] = z;
            dst += 3;
        }
        func_002FCD90(fd, line, 0xC00);
    }
    func_002FC768(fd);
    func_002F0008(path, D_00569E30, name);
    func_202CF08(path, line);
    func_0011D590(line, 6);
    func_0011D590(buf2, 6);
    func_0011D590(buf1, 6);
}
