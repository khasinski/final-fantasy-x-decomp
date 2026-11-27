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
} Sub260;

typedef struct {
    u8 pad00[0x260];
    Sub260 s260;    /* 0x260..0x340 */
    u8 pad340[0x1810];
    u8 f1B50[0x30]; /* 0x1B50 */
    Vec4 v1B80;     /* 0x1B80 */
    Vec4 v1B90;     /* 0x1B90 */
    Vec4 v1BA0;     /* 0x1BA0 */
    u8 pad1BB0[0x60];
    Vec4 v1C10;     /* 0x1C10 */
    Vec4 v1C20;     /* 0x1C20 */
    u8 pad1C30[0x1A0];
    u8 f1DD0[0x140];/* 0x1DD0 */
    float f1F10;    /* 0x1F10 */
    int w1F14;      /* 0x1F14 */
} Ovl09494Work;

extern u8 D_01B0A228[];
extern Ovl09494Work *D_01B0A310;

extern int func_00297C28(int, int, int, int, int, int, int);
extern void func_00297CE8(int);

extern int func_01B03630(int);
extern void func_01B037E8(int, void *, int);
extern float func_01B03B58(int);
extern void func_01B04A58(int, void *);
extern void func_01B04FD8(int, void *, void *);
extern int func_01B06108(void *, void *, int, int, int, int, float);
extern void func_01B06F40(void *, void *, void *);
extern void func_01B09970(void *, int, int, float, float);

void func_01B01F90(void)
{
    Ovl09494Work *w = D_01B0A310;
    w->w1F14 = func_00297C28(func_01B03630(-1), 0, 0, 0, 0, 0, 0);
}

void func_01B01FE0(void)
{
    Ovl09494Work *w = D_01B0A310;
    func_00297CE8(w->w1F14);
    w->w1F14 = -1;
}

void func_01B02018(void)
{
    Ovl09494Work *w = D_01B0A310;
    Sub260 *s = &w->s260;

    func_01B06108(D_01B0A228, s, 2, 0, 0, 0, 0.0149999997f);
    copy_vec(&s->vD0, &w->v1C10);
    s->fC4 = w->f1F10;
    s->vD0.y -= 0.5f;
    w->v1B90.x = 0.0f;
    w->v1B90.y = w->f1F10;
    w->v1B90.z = 0.0f;
    w->v1B90.w = 0.0f;
    func_01B04FD8(-1, w->f1B50, &w->v1B90);
    copy_vec(&w->v1B80, &w->v1C10);
    copy_vec(&w->v1BA0, &w->v1C10);
    func_01B04A58(-1, w->f1B50);
    func_01B09970(w->f1DD0, 30, 0, 1.0f, 0.5f);
}

void func_01B02120(void)
{
    Ovl09494Work *w = D_01B0A310;
    Vec4 rot;
    Vec4 off;

    rot.x = 0.0f;
    rot.y = w->f1F10;
    rot.z = 0.0f;
    off.x = 0.0f;
    off.y = 0.0f;
    off.z = func_01B03B58(0) + 35.0f;
    func_01B037E8(0, &w->v1C20, 0);
    func_01B06F40(&rot, &w->v1C20, &off);
    copy_vec(&w->v1BA0, &w->v1C20);
}
