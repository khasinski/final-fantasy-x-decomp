typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
#define NULL ((void *)0)

extern void imp_libsd_5(u16, u16);
extern s32 imp_sysmem_14();
extern s32 imp_thbase_33(s32);

extern s32 D_018F80;
extern s32 D_018F90;
extern s32 D_018F94;
extern s32 D_019300[2];
extern s32 D_01934C;
extern volatile s32 D_019350;
extern s32 D_06D2A0;
extern u8 D_06D3F0[];

extern char D_016538[];
extern char D_016444[];
extern char D_016458[];
extern char D_016460[];

extern s32 func_00FD60(s32, s32, void *, s32, void *);
extern void func_00FDF4(s32, void *, s32);
extern void func_00E930(void);
extern void func_00F0D4(s32);
extern void func_00E858(void);
extern void func_00F038(s32);

s32 func_00EB80(s32 mode) {
    s32 buf;
    s32 start;
    s32 retry;
    s32 ret;

    if (D_019350 & 3) {
        imp_sysmem_14(D_016538, D_016444, D_016458, D_016460);
        return -1;
    }

    D_019350 |= 12;
    func_00FD60(0, 2, NULL, 0, NULL);
    func_00FD60(1, 2, NULL, 0, NULL);
    func_00FDF4(0, NULL, 0);
    func_00FDF4(1, NULL, 0);
    D_018F94 = mode;

    if (mode & 2) {
        func_00FDF4(0, (void *)func_00E930, 0);
        {
            s32 val = D_019300[0];
            D_018F80 = val >> 24;
            D_019300[0] = val & 0x00ffffff;
            buf = (s32)(D_06D3F0 + D_01934C);
            start = D_019300[0];
        }
        if (start == 0) {
            start = buf;
        }
        retry = 4;
        do {
            ret = func_00FD60(0, 16, (void *)buf, D_01934C * 2, (void *)start);
            if (ret < 0) {
                imp_thbase_33(1000);
            }
            retry--;
        } while (ret < 0 && retry != 0);
        if (ret < 0) {
            func_00F0D4(25);
        }
    }

    if (mode & 1) {
        if ((mode & 2) == 0) {
            func_00FDF4(1, (void *)func_00E930, 0);
            D_018F80 = ((s8 *)&D_019300[1])[3];
        }
        D_019300[1] &= 0x00ffffff;
        buf = (s32)D_06D3F0;
        start = D_019300[1];
        if (start == 0) {
            start = buf;
        }
        retry = 4;
        do {
            ret = func_00FD60(1, 19, (void *)buf, D_01934C, (void *)start);
            if (ret < 0) {
                imp_thbase_33(1000);
            }
            retry--;
        } while (ret < 0 && retry != 0);
        if (ret < 0) {
            func_00F0D4(25);
        } else {
            buf = D_06D2A0 >> 12;
            imp_libsd_5(0x0f81, buf);
            imp_libsd_5(0x1081, buf);
        }
    }

    D_018F90 |= 1;
    func_00E858();
    func_00F038(23);
    return 0;
}
