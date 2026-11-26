#include "iopsound.h"

typedef struct {
    void *entry;
    s32 *sema_ptr;
    s32 thid;
    s32 prio;
} S_ThreadDesc; /* size 16 */

typedef struct {
    u32 attr;
    u32 option;
    void *entry;
    s32 stackSize;
    s32 initPriority;
} S_ThreadParam; /* size 20 */

typedef struct {
    u32 attr;
    u32 option;
    s32 initCount;
    s32 maxCount;
} S_SemaParam; /* size 16 */

typedef struct {
    u32 attr;
    u32 option;
    u32 status;
    void *entry;
    void *stack;
    s32 stackSize;
    u8 pad18[0x30];
} S_ThreadInfo; /* size 0x48 = 72 */

extern s32 D_06D238;
extern s32 D_06D23C;
extern s32 D_06D240;
extern s32 D_06D244;
extern s32 D_06D248;
extern s32 D_06D24C;
extern s32 D_06D250;
extern s32 D_06D254;
extern s32 D_06D258;
extern s32 D_06D25C;
extern s32 D_06D260;
extern s32 D_06D264;
extern s32 D_06D268;
extern s32 D_05A118;

extern S_ThreadDesc D_0191C4[18]; /* 0x0191c4..0x0192e4; 0x0191cc is &D_0191C4[0].thid */
extern char D_016C28[];
extern char D_016C58[];

extern s32 func_00FE3C(s32, s32);
extern void func_00EB80(s32);
extern void func_00DEE4(s32, s32);
extern void func_00E54C(s32, s32, s32);
extern void func_00E6D0(s32, s32, s32);

void func_0157C8(void) {
    while (1) {
        imp_thsemap_8(D_06D238);
        while (func_00FE3C(0, 0) | func_00FE3C(1, 0)) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(0, 0) <= 0) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(1, 0) <= 0) {
            imp_thbase_33(1000);
        }
        func_00EB80(D_06D23C);
    }
}

void func_015874(void) {
    while (1) {
        imp_thsemap_8(D_06D240);
        while (func_00FE3C(0, 0) | func_00FE3C(1, 0)) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(0, 0) <= 0) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(1, 0) <= 0) {
            imp_thbase_33(1000);
        }
        func_00DEE4(D_06D244, D_06D248);
    }
}

void func_015928(void) {
    while (1) {
        imp_thsemap_8(D_06D24C);
        while (func_00FE3C(0, 0) | func_00FE3C(1, 0)) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(0, 0) <= 0) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(1, 0) <= 0) {
            imp_thbase_33(1000);
        }
        func_00E54C(D_06D250, D_06D254, D_06D258);
    }
}

void func_0159E4(void) {
    while (1) {
        imp_thsemap_8(D_06D25C);
        while (func_00FE3C(0, 0) | func_00FE3C(1, 0)) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(0, 0) <= 0) {
            imp_thbase_33(1000);
        }
        while (imp_libsd_19(1, 0) <= 0) {
            imp_thbase_33(1000);
        }
        func_00E6D0(D_06D260, D_06D264, D_06D268);
    }
}

void func_015AA0(void) {
    S_ThreadInfo info;
    S_ThreadDesc *t;
    s32 i = 18;

    imp_sysmem_14(D_016C28);
    t = D_0191C4;
    do {
        if (imp_thbase_22(t->thid, &info) == 0) {
            imp_sysmem_14(D_016C58, t->thid, info.entry, info.stack, info.stackSize);
        }
        t++;
    } while (--i != 0);
}

