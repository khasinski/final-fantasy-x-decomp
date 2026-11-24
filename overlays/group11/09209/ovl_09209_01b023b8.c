#include "common.h"
#include "vu0.h"

typedef struct Ovl09209Obj {
    float mtx[16];      /* 0x00 */
    u8 pad40[0x106];
    u8 b146;            /* 0x146 */
} Ovl09209Obj;

typedef struct Ovl09209Work {
    u8 pad00[0x9D0];
    u8 q9D0[0x30];      /* 0x9D0 */
    u8 padA00[0x5878];
    float f6278;        /* 0x6278 */
} Ovl09209Work;

typedef struct Ovl09209E48 {
    int w00;
    int count;          /* 0x04 */
} Ovl09209E48;

extern Ovl09209E48 D_01B00E48;
extern Ovl09209Work *D_01B0BD58;

void func_002DD128(void *a0);
void func_002DD318(void *a0, void *a1, float a2);

void func_01B05750(int a0, int a1);
void func_01B05968(int a0, int a1);
void func_01B05EA8(int a0, float f0, float f1, float f2, int a1);
void func_01B09080(int a0);
void func_01B091C0(void);
Ovl09209Obj *func_01B093B0(int a0);

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B023B8(void)
{
    Ovl09209Work *w = D_01B0BD58;
    Ovl09209Obj *obj;

    func_01B09080(0);
    obj = func_01B093B0(0);
    obj->b146 = 1;
    func_002DD128(obj->mtx);
    func_002DD318(obj->mtx, obj->mtx, w->f6278);
    copy_vec(&obj->mtx[12], w->q9D0);
}

void func_01B02428(void)
{
    int i;

    func_01B05968(-1, 1);
    for (i = 0; i < D_01B00E48.count; i++) {
        func_01B05EA8(i, 1.0f, 1.0f, 1.0f, 1);
        func_01B05750(i, -1);
    }
    func_01B091C0();
}
