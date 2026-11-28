#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

extern u8 D_01B00040[];
extern u8 D_01B00810[];
extern u8 D_01B00B28[];
extern u8 D_01B00EA8[];
extern u8 *D_01B010B4;
extern u8 D_01B0A2F8[];
extern s32 D_01B0A338;
extern u8 *D_01B0A33C;
extern u8 D_01B0A340[];
extern u8 D_01B0A3A0[];
extern u8 D_01B0A400[];
extern u8 D_01B0A420[];
extern u8 D_01B0A440[];
extern u8 D_01B0A460[];
extern u8 *D_01B0A480;
extern u8 *D_01B0A484;
extern u8 *D_01B0A488;
extern s32 D_01B0A48C;
extern u8 D_01B0FA30[];
extern u8 D_01C028C0[];

extern void *func_001B4E58(s32);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B05FF8(void *, void *, void *, s32);
extern void func_01B01F28(void);
extern void func_01B01F98(void);
extern void func_01B020F0(void);
extern void func_01B09660(void *, void *);
extern void func_01B055E0(s32);
extern void func_01B0A210(void *, s32);
extern u8 *func_01B05D70(void *);
extern void func_01B05F38(void *);
extern void func_01B09C78(void *, s32);
extern void func_01B01EC0(void);

extern void func_01B01DB8(void);

typedef struct {
    u8 pad[0x2C];
    void *unk2C;
} Tbl1C28;

s32 func_01B01C28(void) {
    u8 *base = D_01C028C0;
    u8 *ea8 = D_01B00EA8;
    Tbl1C28 *t;
    u8 *p;

    D_01B0A338 = 0;
    D_01B0A33C = base + 0x40000;
    D_01B0A484 = base + 0x140000;
    {
        register u8 *p18 __asm__("$6") = base + 0x180000;
        register u8 *p1d __asm__("$5") = base + 0x1D1400;
        D_01B0A488 = p18;
        D_01B0A480 = p1d;
    }

    ea8[0x15] = 0x1E;
    *(void **)(ea8 + 0xBC) = func_001B4E58(0x1E);
    *(s32 *)(ea8 + 0x4) = 2;

    t = (Tbl1C28 *)D_01B0A2F8;
    t->unk2C = func_002B49A0(D_01B0FA30, 8, 0);
    func_01B05FF8(t, D_01B00040, base, 0x40000);

    func_01B01F28();
    func_01B01F98();
    func_01B020F0();

    func_01B09660(D_01B0A340, D_01B00810);
    func_01B09660(D_01B0A3A0, D_01B00B28);
    func_01B055E0(1);

    D_01B0A48C = -1;
    func_01B0A210(base + 0x1D0000, 0x10);

    p = func_01B05D70((void *)func_01B01DB8);
    p[0x18] = 1;
    func_01B05F38(p);

    func_01B09C78(base + 0x1B0000, 0x400);

    p = func_01B05D70((void *)func_01B01EC0);
    p[0x18] = 2;
    func_01B05F38(p);

    return 0;
}
