#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} Env18D8;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task18D8;

extern u8 D_01BFBCC0[];
extern u8 D_01B0EDE0[];
extern u8 D_01B00040[];
extern u8 D_01B095A0[];
extern u8 D_01B00810[];
extern u8 D_01B09600[];
extern u8 D_01B009C0[];
extern u8 D_01B01A20[];
extern u8 D_01B01AF0[];
extern Env18D8 D_01B09558;
extern void *D_01B09598;
extern void *D_01B0959C;
extern void *D_01B096A0;
extern void *D_01B096A4;
extern s32 D_01B096A8;

extern void *op_oef2_a_get(void *, int, int);
extern void func_01B05258(void *, void *, void *, int);
extern void func_01B01B58(void);
extern void func_01B01C50(void);
extern void func_01B088C0(void *, void *);
extern void func_01B04840(int);
extern void func_01B09470(void *, int);
extern Task18D8 *func_01B04FD0(void *);
extern void func_01B05198(Task18D8 *);
extern void func_01B08ED8(void *, int);

int func_01B018D8(void) {
    u8 *p = D_01BFBCC0;
    Env18D8 *env = &D_01B09558;
    Task18D8 *t;

    D_01B09598 = 0;
    D_01B0959C = p + 0x40000;
    D_01B096A4 = p + 0x140000;
    D_01B096A0 = p + 0x1D1400;
    env->w2C = op_oef2_a_get(D_01B0EDE0, 8, 0);
    func_01B05258(env, D_01B00040, p, 0x40000);
    func_01B01B58();
    func_01B01C50();
    func_01B088C0(D_01B095A0, D_01B00810);
    func_01B088C0(D_01B09600, D_01B009C0);
    func_01B04840(1);
    D_01B096A8 = -1;
    func_01B09470(p + 0x1D0000, 16);
    t = func_01B04FD0(D_01B01A20);
    t->b18 = 1;
    func_01B05198(t);
    func_01B08ED8(p + 0x1B0000, 1024);
    t = func_01B04FD0(D_01B01AF0);
    t->b18 = 2;
    func_01B05198(t);
    return 0;
}
