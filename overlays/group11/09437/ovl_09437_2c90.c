#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

typedef struct {
    u8 pad00[0x60];
    float f60;
    float f64;
    float f68;
    float f6C;
    s16 h70;
    s16 h72;
    s16 h74;
    s16 h76;
    u8 pad78[0x08];
    float m80[16];
    float fC0;
    float fC4;
    u8 padC8[0x08];
    Vec4 vD0;
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x10];
    int w118;
    u8 pad11C[0x04];
    int w120;
    u8 pad124[0x02];
    u8 b126;
    u8 pad127[0x09];
} SubObj;

typedef struct {
    u8 pad00[0x5F0];
    SubObj s5F0;    /* 0x5F0 */
    u8 pad720[0x130];
    SubObj s850;    /* 0x850 */
    u8 pad980[0x11D0];
    u8 f1B50[0x40]; /* 0x1B50 */
    Vec4 v1B90;     /* 0x1B90 */
    Vec4 v1BA0;     /* 0x1BA0 */
    u8 f1BB0[0x30]; /* 0x1BB0 */
    Vec4 v1BE0;     /* 0x1BE0 */
    Vec4 v1BF0;     /* 0x1BF0 */
    Vec4 v1C00;     /* 0x1C00 */
    Vec4 v1C10;     /* 0x1C10 */
    Vec4 v1C20;     /* 0x1C20 */
    Vec4 v1C30;     /* 0x1C30 */
    Vec4 v1C40;     /* 0x1C40 */
    u8 pad1C50[0x2C0];
    float f1F10;    /* 0x1F10 */
    int w1F14;      /* 0x1F14 */
    int w1F18;      /* 0x1F18 */
    int w1F1C;      /* 0x1F1C */
    int w1F20;      /* 0x1F20 */
} Ovl09494Work;

extern u8 D_01B0A228[];
extern Ovl09494Work *D_01B0A310;
extern int D_01B0A328;

extern void func_001072C0(int, int, int);
extern void func_00110310(int, float);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DCF48(void *, void *);

extern int func_01B03630(int);
extern void func_01B03918(int, void *);
extern void func_01B03CE8(int, int, void *);
extern void func_01B04A58(int, void *);
extern void func_01B04EB8(void *, void *);
extern void func_01B04FD8(int, void *, void *);
extern int func_01B06108(void *, void *, int, int, int, int, float);
extern void func_01B06578(void *, void *);
extern float func_01B08320(void);

void func_01B028B8(SubObj *o);
void func_01B02A88(SubObj *o);

void func_01B02A88(SubObj *o)
{
    func_01B03CE8(1, 6, &o->vD0);
    o->p104 = 0;
}
