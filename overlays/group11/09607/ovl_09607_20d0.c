#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x2A30];
    Vec4 v2B10;
    Vec4 v2B20;
    u8 pad2B30[0x30];
    Vec4 v2B60;
    Vec4 v2B70;
    u8 pad2B80[0xCF0];
    u8 f3870[0x384];
    float f3BF4;
} Work9607;

extern u8 D_01B0BB70[];
extern Work9607 *D_01B0BC98;

extern void func_00118098(int, int);
extern void func_01B072F0(void *, void *, int, int, int, int, float);
extern void func_01B0AEF8(void *, int, int, float, float);

void func_01B020D0(void)
{
    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    func_01B0AEF8(D_01B0BC98->f3870, 0x1E, 0, 1.0f, 0.5f);
}

void func_01B02120(void)
{
    Work9607 *w = D_01B0BC98;
    w->v2B60.x = 0.0f;
    w->v2B60.y = -6.0f;
    w->v2B60.z = 0.0f;
    w->v2B60.w = 0.0f;
    w->v2B70.x = 0.0f;
    w->v2B70.y = 0.1f;
    w->v2B70.z = 0.0f;
    w->v2B70.w = 0.0f;
}

void func_01B02160(void)
{
    Work9607 *w = D_01B0BC98;
    w->v2B60.y += w->v2B70.y;
    w->v2B10.y += w->v2B60.y;
}

void func_01B02188(void)
{
    Work9607 *w = D_01B0BC98;
    w->v2B10.y = w->v2B20.y - 60.0f;
    w->v2B60.y = -2.0f;
    w->v2B70.y = 0.06666660f;
    w->v2B60.z = 0.0f;
    w->v2B60.w = 0.0f;
    w->v2B70.x = 0.0f;
    w->v2B70.z = 0.0f;
    w->v2B70.w = 0.0f;
    w->v2B60.x = 0.0f;
}

void func_01B021E0(void)
{
    Work9607 *w = D_01B0BC98;
    func_01B072F0(D_01B0BB70, w, 0, 0, 0, 0, 0.12f);
    copy_vec(&w->vD0, &w->v2B20);
    w->fC4 = w->f3BF4;
    w->vD0.y -= 1.0f;
}
