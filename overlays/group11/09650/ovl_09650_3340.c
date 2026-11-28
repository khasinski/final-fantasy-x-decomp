#include "common.h"

typedef struct {
    float f0;
    s32 f4;
    s32 f8;
    s32 fc;
} Arr5C9C;

extern u8 *D_01B0A478;
extern void func_01B02A08(void);
extern void func_01B098B0(void *, s32);
extern void func_01B09A20(void *, s32);
extern void *func_01B05EA0(void (*)(void));
extern void func_01B06068(void *);

void func_01B03340(void) {
    u8 *base = D_01B0A478;
    u8 *p = base + 0x5BE0;
    Arr5C9C *arr;
    void *h;

    *(u8 *)(p + 0x82) = 0xFF;
    *(u8 *)(p + 0x81) = 0xFF;
    *(u8 *)(p + 0x80) = 0xFF;
    *(u8 *)(p + 0x83) = 0x80;
    *(u8 *)(p + 0x84) = 0xFF;
    *(u8 *)(p + 0x85) = 0xFF;
    *(u8 *)(p + 0x86) = 0xFF;
    *(u8 *)(p + 0x87) = 0;
    *(s32 *)(p + 0x88) = 0;
    *(u8 *)(p + 0x98) = 0x48;
    *(u8 *)(p + 0x99) = 0;
    func_01B098B0(p, 0x18);

    arr = (Arr5C9C *)(base + 0x5C9C);
    arr->f0 = 0.0f;
    arr->f4 = 0x50;
    arr->f8 = 0x14;
    arr->fc = 0;
    func_01B09A20(arr, 0x5A);

    *(s32 *)(base + 0x6284) = 0xC;
    h = func_01B05EA0(func_01B02A08);
    *(void **)(base + 0x6270) = h;
    func_01B06068(h);
}
