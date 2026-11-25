/* tu_354 0x2e06d0-0x2e2220: medium; libcdvd (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"

void func_002E06D0(u16 ms)
{
    SemaParam sema;
    int id;

    sema.maxCount = 1;
    sema.initCount = 0;
    sema.option = 0;
    id = func_002F83E0(&sema);
    func_002F8160(ms, func_002E06A8, id);
    func_002F8420(id);
    func_002F83F0(id);
}

int func_002E0738(int cb)
{
    int old;

    if (func_002E11A0(1) != 0) {
        return 0;
    }
    func_00300280();
    old = D_0078D600;
    D_0078D600 = cb;
    func_003002C8();
    return old;
}

void func_002E0790(volatile int *p)
{
    D_00566414 = *p;
    D_00566418 = D_00566414;
    if (D_00566414 == 0xB) {
        D_00566414 = 0;
        *(volatile int *)&D_005663F0 = 0;
        return;
    }
    ((int (*)(int))func_002F8410)(*(volatile int *)&D_005663E8);
    if (D_005663D4 != 0 && D_0078D600 != 0) {
        ((int (*)(int))func_002F8410)(*(volatile int *)&D_005663E0);
    } else {
        *(volatile int *)&D_005663F0 = 0;
    }
    D_00566414 = 0;
}

void func_002E0830(void *arg)
{
    while (1) {
        func_002F8420(D_005663E0);
        if (D_00566414 == -1) {
            D_005663F0 = 0;
            D_00566414 = 0;
            D_005663D4 = 0;
            D_0078D60C = 0;
            func_002F8220();
        }
        if (D_005663D0 > 0) {
            func_002FA4E0(D_00576BC8, D_0078D600, *(int *)&D_00566418);
        }
        if (D_0078D600 != 0) {
            if (D_00566418 != 0) {
                ((void (*)(int))D_0078D600)(*(int *)&D_00566418);
            }
        }
        __asm__ volatile("" : : : "memory");
        D_005663F0 = 0;
    }
}

int func_002E08F0(int prio, void *stack, int size)
{
    int ret = 1;

    if (D_005663D4 == 0) {
        D_0078D610 = func_002F82D0();
        func_002F82E0(D_0078D610, &D_0078D618);
        D_0078D648.stackSize = size;
        D_0078D648.gpReg = D_00584670;
        D_0078D648.entry = func_002E0830;
        D_0078D648.stack = stack;
        D_0078D648.initPriority = prio;
        D_005663D4 = func_002F81E0(&D_0078D648);
        func_002F8200(D_005663D4, 0);
    } else {
        func_002F8270(D_005663D4, prio);
        ret = 0;
    }
    return ret;
}

void func_002E09C8(void *data)
{
    McReadEnd *u = UNCACHED(data);
    u8 *dst;
    int i;

    if (u->size1 > 0) {
        dst = u->dest1;
        for (i = 0; i < u->size1; i++) {
            dst[i] = u->buf1[i];
        }
    }
    if (u->size2 > 0) {
        dst = u->dest2;
        for (i = 0; i < u->size2; i++) {
            dst[i] = u->buf2[i];
        }
    }
    func_002E0790(&D_00566414);
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E0A68);

extern s32 _m2c_func_002E0B00_D_005663D4 __asm__("D_005663D4");
extern s32 _m2c_func_002E0B00_D_005663E0 __asm__("D_005663E0");
extern s32 _m2c_func_002E0B00_D_005663E8 __asm__("D_005663E8");
extern s32 _m2c_func_002E0B00_D_005663EC __asm__("D_005663EC");
extern s32 _m2c_func_002E0B00_D_00566414 __asm__("D_00566414");
void func_002E0B00(void) {
    if (_m2c_func_002E0B00_D_005663D4 != 0) {
        _m2c_func_002E0B00_D_00566414 = -1;
        __asm__ volatile("" : : : "memory");
        func_002F8400(_m2c_func_002E0B00_D_005663E0);
    }
    func_002F83F0(_m2c_func_002E0B00_D_005663E8);
    __asm__ volatile("" : : : "$2");
    func_002F83F0(_m2c_func_002E0B00_D_005663EC);
    func_002F83F0(_m2c_func_002E0B00_D_005663E0);
    func_00300280();
    func_002FA8D0(0x80000012U);
    func_003002C8();
}

void *func_002E0B80(void (*func)(int), int arg)
{
    void (*old)(int);

    if (D_005663FC < 0) {
        func_002E0C30();
    }
    func_00300280();
    old = D_0078D604;
    D_0078D608 = arg;
    D_0078D604 = func;
    func_003002C8();
    return old;
}

void func_002E0BF0(void)
{
    if (D_0078D604 != 0 && D_005663E4 == 0) {
        D_0078D604(D_0078D608);
    }
}

s32 func_002E0C30(void)
{
    D_005663E4 = 1;
    func_00300280();
    func_002FA8A0(0x80000012U, func_002E0BF0, 0);
    CALL_func_003002C8_INT();
    D_005663E4 = 0;
    D_005663FC = 1;
    return 1;
}

typedef struct CdFileInfo {
    u32 lsn;
    u32 size;
    char name[16];
    u8 date[8];
    u32 flag;
} CdFileInfo;

typedef struct CdFileBuf {
    CdFileInfo info;
    char path[0x100];
    void *self;
} CdFileBuf;

extern int D_005663DC;
extern int D_005663F8;
extern int D_00566400;
extern int D_00566404;
extern int D_0056640C;
extern int D_00566410;
extern CdFileBuf D_0078D680;
extern int D_0078D7C0[];
extern int D_0078D800[];
extern int D_0078D828[];
extern int D_0078D850[];
extern int D_0078D880[];
extern int D_0078D890[];
extern char D_00576BF0[];
extern char D_00576C10[];
extern char D_00576C28[];
extern char D_00576C38[];
extern char D_00576C48[];
extern char D_00576D00[];
extern char D_00576D20[];
extern char D_00576D30[];
extern char D_00576D40[];
extern char D_00576D60[];
void func_002FAC88(int mode);
int func_002F8430(int sid);
int func_002FB2F8(void *cd, u32 sid, int mode);

int func_002E0C98(CdFileInfo *fp, const u8 *name)
{
    int i;
    int j;
    int ret;

    func_002E0A68();
    ret = func_002F8430(*(volatile int *)&D_005663E8);
    if (*(volatile int *)&D_005663E8 != ret) {
        return 0;
    }
    D_005663DC = 1;
    func_002F82E0(D_0078D610, &D_0078D618);
    if (func_002E11A0(1) != 0) {
        func_002F8400(*(volatile int *)&D_005663E8);
        return 0;
    }
    func_002FAC88(0);
    if (D_00566400 < 0) {
        while (1) {
            if (func_002FB2F8(D_0078D800, 0x80000597, 0) < 0) {
                if (D_005663D0 > 0) {
                    func_002FA4E0(D_00576BF0);
                }
                i = 0x100000;
                while (i--) {
                }
                continue;
            }
            if (D_0078D800[9] != 0) {
                D_00566400 = 0;
                break;
            }
            i = 0x100000;
            while (i--) {
            }
        }
    }
    for (j = 0; j < 0x100; j++) {
        if ((D_0078D680.path[j] = name[j]) == '\0') {
            break;
        }
    }
    if (j == 0x100) {
        D_0078D680.path[0xFF] = '\0';
    }
    D_0078D680.self = &D_0078D680;
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576C10, D_0078D680.path);
    }
    func_002FABD8(&D_0078D680, sizeof(D_0078D680));
    if (func_002FB4C8(D_0078D800, 0, 0, &D_0078D680, sizeof(D_0078D680), D_0078D7C0, 4, 0, 0) < 0) {
        func_002F8400(*(volatile int *)&D_005663E8);
        return 0;
    }
    __builtin_memcpy(fp, UNCACHED(&D_0078D680), sizeof(CdFileInfo));
    if (D_005663D0 > 0) {
        ((void (*)(const char *, ...))func_002FA4E0)(D_00576C28, fp->name);
    }
    if (D_005663D0 > 0) {
        ((void (*)(const char *, ...))func_002FA4E0)(D_00576C38, fp->size);
    }
    if (D_005663D0 > 0) {
        ((void (*)(const char *, ...))func_002FA4E0)(D_00576C48, fp->lsn);
    }
    ret = *(int *)UNCACHED(D_0078D7C0);
    func_002F8400(*(volatile int *)&D_005663E8);
    return ret;
}

extern int D_005663DC;
extern int D_005663F8;
extern char D_00576C60[];
extern char D_00576C88[];
void func_002FAC88(int mode);
int func_002F8430(int sid);
int func_002FB2F8(void *cd, u32 sid, int mode);

int func_002E0F98(int cmd)
{
    int i;
    int ret;

    func_002E0A68();
    ret = func_002F8430(*(volatile int *)&D_005663E8);
    if (*(volatile int *)&D_005663E8 != ret) {
        if (D_005663D0 > 0) {
            func_002FA4E0(D_00576C60, cmd, D_005663DC);
        }
        return 0;
    }
    D_005663DC = cmd;
    func_002F82E0(D_0078D610, &D_0078D618);
    if (func_002E11A0(1) != 0) {
        func_002F8400(*(volatile int *)&D_005663E8);
        return 0;
    }
    func_002FAC88(0);
    if (*(volatile int *)&D_005663F8 < 0) {
        while (1) {
            if (func_002FB2F8(D_00567590, 0x80000595, 0) < 0) {
                if (D_005663D0 > 0) {
                    func_002FA4E0(D_00576C88);
                }
                i = 0x100000;
                while (i--) {
                }
                continue;
            }
            if (((s32 *)D_00567590)[9] != 0) {
                break;
            }
            i = 0x100000;
            while (i--) {
            }
        }
        D_005663F8 = 0;
    }
    return 1;
}

int func_002E1108(void)
{
    int ret;

    if (func_002E0F98(2) == 0) {
        return 0;
    }
    if (func_002FB4C8(D_00567590, 0xE, 0, 0, 0, &D_00566440, 4, 0, 0) < 0) {
        func_002F8400(D_005663E8);
        return 0;
    }
    ret = *(int *)UNCACHED(&D_00566440);
    func_002F8400(D_005663E8);
    return ret;
}

int func_002E11A0(int mode)
{
    if (mode == 0) {
        if (D_005663D0 > 0) {
            func_002FA4E0(D_00576CA0);
        }
        while (D_005663F0 != 0 || func_002FB6B8(D_00567590) != 0) {
            func_002E06D0(0x3C);
        }
        return 0;
    }
    if (D_005663F0 != 0 || func_002FB6B8(D_00567590) != 0) {
        return 1;
    }
    return 0;
}

int func_002E1240(int mode)
{
    if (mode == 0) {
        if (D_005663D0 > 0) {
            func_002FA4E0(D_00576CB0);
        }
        while (func_002FB6B8(D_00567E08) != 0) {
            func_002E06D0(0x3C);
        }
        return 0;
    }
    return func_002FB6B8(D_00567E08);
}

extern int D_005663D8;
extern int D_00566408;
extern char D_00576CC0[];
extern char D_00576CE8[];

int func_002E12B0(int cmd)
{
    int i;
    int ret;

    func_002E0A68();
    ret = func_002F8430(*(volatile int *)&D_005663EC);
    if (*(volatile int *)&D_005663EC != ret) {
        if (D_005663D0 > 0) {
            func_002FA4E0(D_00576CC0, cmd, D_005663D8);
        }
        return 0;
    }
    D_005663D8 = cmd;
    func_002F82E0(D_0078D610, &D_0078D618);
    if (func_002E1240(1) != 0) {
        func_002F8400(*(volatile int *)&D_005663EC);
        return 0;
    }
    func_002FAC88(0);
    if (*(volatile int *)&D_00566408 < 0) {
        while (1) {
            if (func_002FB2F8(D_00567E08, 0x80000593, 0) < 0) {
                if (D_005663D0 > 0) {
                    func_002FA4E0(D_00576CE8);
                }
                i = 0x100000;
                while (i--) {
                }
                continue;
            }
            if (((s32 *)D_00567E08)[9] != 0) {
                break;
            }
            i = 0x100000;
            while (i--) {
            }
        }
        D_00566408 = 0;
    }
    return 1;
}

INCLUDE_ASM("build/ee_asm/sdk/libcdvd/libcdvd", func_002E1420);

int func_002E1700(int mode)
{
    int i;
    int ret;
    int *recv;

    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576D30);
    }
    func_002E0A68();
    ret = func_002F8430(*(volatile int *)&D_005663EC);
    if (*(volatile int *)&D_005663EC != ret) {
        return 6;
    }
    if (func_002E1240(1) != 0) {
        func_002F8400(*(volatile int *)&D_005663EC);
        return (mode != 8) ? 6 : -1;
    }
    func_002FAC88(0);
    if (D_00566404 < 0) {
        while (1) {
            if (func_002FB2F8(D_0078D850, 0x8000059A, 0) < 0) {
                if (D_005663D0 > 0) {
                    func_002FA4E0(D_00576D40);
                }
                i = 0x100000;
                while (i--) {
                }
                continue;
            }
            if (D_0078D850[9] != 0) {
                D_00566404 = 0;
                break;
            }
            i = 0x100000;
            while (i--) {
            }
        }
    }
    D_0078D890[0] = mode;
    func_002FABD8(D_0078D890, 4);
    recv = D_005675C0;
    if (func_002FB4C8(D_0078D850, 0, 0, D_0078D890, 4, recv, 4, 0, 0) < 0) {
        func_002F8400(*(volatile int *)&D_005663EC);
        return (mode != 8) ? 6 : -1;
    }
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576D60);
    }
    ret = *(int *)UNCACHED(recv);
    func_002F8400(*(volatile int *)&D_005663EC);
    return ret;
}

int func_002E18F8(int a)
{
    int *buf = &D_00567A00;
    int *recv;
    int r;

    if (func_002E12B0(0x22) == 0) {
        return 0;
    }
    *buf = a;
    func_002FABD8(buf, 4);
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 0x22, 0, buf, 4, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

int func_002E19C0(int lbn, int sectors, void *buf, R7CdMode *mode)
{
    R7CdRead *req = &D_005664C0;
    int size;

    if ((D_005663F4 & 1) == 0) {
        if (func_002E1108() == 6) {
            return 0;
        }
    }
    if (func_002E0F98(4) == 0) {
        return 0;
    }
    req->lbn = lbn;
    req->sectors = sectors;
    req->buf = buf;
    req->mode.trycount = mode->trycount;
    req->mode.spindlctrl = mode->spindlctrl;
    req->mode.datapattern = mode->datapattern;
    req->p10 = D_005674C0;
    req->p14 = &D_00567580;
    switch (mode->datapattern) {
    case 0:
        size = sectors * 0x800;
        break;
    case 1:
        size = sectors * 0x918;
        break;
    case 2:
        size = sectors * 0x924;
        break;
    default:
        size = sectors * 0x800;
        break;
    }
    D_00567580 = 0;
    if ((*(volatile s32 *)&D_005663F4 & 2) == 0) {
        func_002FABD8(buf, size);
    }
    func_002FABD8(D_005674C0, 0x90);
    func_002FABD8(req, sizeof(D_005664C0));
    func_002FABD8(&D_00567580, 4);
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576D78);
    }
    {
        register s32 one __asm__("$2") = 1;
        __asm__("" : "+r"(one));
        D_00566414 = one;
        __asm__ volatile("" : : : "memory");
        *(volatile s32 *)&D_005663F0 = one;
    }
    {
        register void *p74c0 __asm__("$19") = D_005674C0;
        __asm__("" : "+r"(p74c0));
        if (func_002FB4C8(D_00567590, 1, 1, req, sizeof(D_005664C0), 0, 0, func_002E09C8, p74c0) < 0) {
            D_00566414 = 0;
            __asm__ volatile("" : : : "$2");
            __asm__ volatile("" : : : "$3");
            D_005663F0 = 0;
            func_002F8400(D_005663E8);
            return 0;
        }
    }
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576D90);
    }
    return 1;
}

int func_002E1BA0(int lbn)
{
    R7CdRead *req = &D_005664C0;

    if (func_002E1108() == 6) {
        return 0;
    }
    if (func_002E0F98(9) == 0) {
        return 0;
    }
    req->lbn = lbn;
    func_002FABD8(req, 4);
    {
        *(volatile s32 *)&D_00566414 = 4;
        *(volatile s32 *)&D_005663F0 = 1;
        if (func_002FB4C8(D_00567590, 5, 1, req, 4, 0, 0, func_002E0790, &D_00566414) < 0) {
            D_00566414 = 0;
            __asm__ volatile("" : : : "$2");
            __asm__ volatile("" : : : "$3");
            D_005663F0 = 0;
            func_002F8400(D_005663E8);
            return 0;
        }
    }
    return 1;
}

/* DEBT(FAKE) */ /* DEBT(GOTO) */
s32 func_002E1C70(void) {
    if (func_002E1108() != 6) {
        if (func_002E0F98(0xA) != 0) {
            register s32 *p414 __asm__("$3");
            D_00566414 = 5;
            __asm__ volatile("" : "=r"(p414) : "0"(&D_00566414) : "$2");
            D_005663F0 = 1;
            if (func_002FB4C8(D_00567590, 6, 1, 0, 0, 0, 0, func_002E0790, p414) >= 0) {
                goto ret1;
            }
            {
                register s32 r2 __asm__("$2");
                __asm__ volatile("" : : "r"(r2) : "$3");
            }
            D_00566414 = 0;
            __asm__ volatile("" : : : "$2");
            __asm__ volatile("" : : : "$3");
            D_005663F0 = 0;
            func_002F8400(D_005663E8);
            goto block_6;
        }
block_6:
        return 0;
    }
    return 0;
ret1:
    return 1;
}

/* DEBT(FAKE) */ /* DEBT(GOTO) */
s32 func_002E1D20(void) {
    if (func_002E1108() != 6) {
        if (func_002E0F98(0xC) != 0) {
            register s32 *p414 __asm__("$3");
            D_00566414 = 7;
            __asm__ volatile("" : "=r"(p414) : "0"(&D_00566414) : "$2");
            D_005663F0 = 1;
            if (func_002FB4C8(D_00567590, 8, 1, 0, 0, 0, 0, func_002E0790, p414) >= 0) {
                goto ret1;
            }
            {
                register s32 r2 __asm__("$2");
                __asm__ volatile("" : : "r"(r2) : "$3");
            }
            D_00566414 = 0;
            __asm__ volatile("" : : : "$2");
            __asm__ volatile("" : : : "$3");
            D_005663F0 = 0;
            func_002F8400(D_005663E8);
            goto block_6;
        }
block_6:
        return 0;
    }
    return 0;
ret1:
    return 1;
}

int func_002E1DD0(void)
{
    int *recv;
    int r;

    if (func_002E12B0(1) == 0) {
        return 0;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 3, 0, 0, 0, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

int func_002E1E68(void)
{
    int *recv;
    int r;

    if (func_002E12B0(3) == 0) {
        return -1;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 4, 0, 0, 0, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return -1;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

int func_002E1F00(void)
{
    int *recv;
    int r;

    if (func_002E12B0(2) == 0) {
        return -1;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 0xC, 0, 0, 0, recv, 4, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return -1;
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    if (D_005663D0 >= 2) {
        func_002FA4E0(D_00576DA0);
    }
    return r;
}

int func_002E1FB8(void)
{
    int *recv;
    int r;

    if (func_002E12B0(0x1E) == 0) {
        return 0;
    }
    D_00566414 = 8;
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 0x16, 0, 0, 0, recv, 4, 0, 0) < 0) {
        func_002F8400(*(volatile int *)&D_005663EC);
        D_00566414 = 0;
        return 0;
    }
    D_00566414 = 0;
    r = *(int *)UNCACHED(recv);
    func_002F8400(*(volatile int *)&D_005663EC);
    return r;
}

int func_002E2070(int *out)
{
    int *recv;
    int r;

    if (func_002E12B0(0x21) == 0) {
        return 0;
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 0x21, 0, 0, 0, recv, 8, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    *out = *(int *)UNCACHED(recv + 1);
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}

int func_002E2128(R7Pair *out)
{
    int *recv;
    int r;

    if (func_002E12B0(0xF) == 0) {
        return 0;
    }
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576DB0);
    }
    recv = D_005675C0;
    if (func_002FB4C8(D_00567E08, 1, 0, 0, 0, recv, 0x10, 0, 0) < 0) {
        func_002F8400(D_005663EC);
        return 0;
    }
    *out = *(R7Pair *)UNCACHED(recv + 1);
    if (D_005663D0 > 0) {
        func_002FA4E0(D_00576DD0);
    }
    r = *(int *)UNCACHED(recv);
    func_002F8400(D_005663EC);
    return r;
}
