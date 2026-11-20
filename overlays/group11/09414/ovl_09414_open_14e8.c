#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

extern int D_01B00458;
extern TtCfg *D_01B00474;
extern u8 D_01B00478;
extern PppObj D_01B00530;
extern float D_01B00BD0[4];
extern char D_01B02B38[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern int func_01B01EB0(char *, ...);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

int func_01B014E8(void)
{
    func_01B01EB0(D_01B02B38, D_01B00458);
    D_006A3924 = &D_01B00478;
    func_00267658(&D_01B00530, 0x1000, D_01B00474->w10[0], 1);
    {
        /* DEBT(FAKE): pin float constants and chain dependencies to match ee-gcc scheduling */
        register float f1 __asm__("$f1");
        register float f0 __asm__("$f0");
        register float f3 __asm__("$f3");
        register float f2 __asm__("$f2");
        register float f4 __asm__("$f4");
        register float *bd0 __asm__("$3");
        register int one __asm__("$4");
        int ret;

        f1 = 1.0f;
        __asm__("" : "+f"(f1));
        bd0 = D_01B00BD0;
        f0 = 0.3125f;
        __asm__("" : "+f"(f0) : "f"(f1));
        __asm__("" : "+r"(bd0) : "f"(f0));
        f3 = -154.371979f;
        __asm__("" : "+f"(f3) : "r"(bd0));
        one = 1;
        __asm__("" : "+r"(one) : "f"(f3));
        bd0[3] = f1;
        ret = 1;
        f2 = 16.6666718f;
        __asm__("" : "+f"(f2), "+r"(ret) : "r"(one), "m"(bd0[3]));
        D_01B00530.pos[2] = f3;
        D_01B00530.scale[2] = f0;
        __asm__("" : "+f"(f2), "+f"(f1), "+f"(f0) : "m"(D_01B00530.pos[2]), "m"(D_01B00530.scale[2]) : "$f4");
        f4 = -40.2568626f;
        __asm__("" : "+f"(f4) : "f"(f2), "m"(D_01B00530.pos[2]), "m"(D_01B00530.scale[2]));
        D_01B00BD0[0] = f2;
        __asm__("" : "+f"(f2) : "m"(D_01B00BD0[0]));
        D_01B00530.pos[0] = f2;
        __asm__("" : "+f"(f4) : "m"(D_01B00530.pos[0]));
        D_01B00530.pos[1] = f4;
        __asm__("" : "+f"(f1), "+f"(f0) : "m"(D_01B00530.pos[1]), "m"(D_01B00530.pos[0]));
        D_01B00530.pos[3] = f1;
        D_01B00530.scale[0] = f0;
        __asm__("" : "+f"(f0), "+f"(f1) : "m"(D_01B00530.pos[3]), "m"(D_01B00530.scale[0]));
        D_01B00530.scale[1] = f0;
        D_01B00530.scale[3] = f1;
        __asm__("" : "+r"(one) : "m"(D_01B00530.scale[1]), "m"(D_01B00530.scale[3]));
        D_01B00530.rot[3] = one;
        __asm__("" : "+m"(D_01B00530.rot[3]));
        D_01B00530.rot[0] = 0;
        D_01B00530.rot[1] = 0;
        D_01B00530.rot[2] = 0;
        __asm__("" : "+f"(f3), "+f"(f4) : "m"(D_01B00530.rot[0]), "m"(D_01B00530.rot[1]), "m"(D_01B00530.rot[2]));
        bd0[2] = f3;
        bd0[1] = f4;
        return ret;
    }
}

int func_01B015D8(void)
{
    D_006A3924 = &D_01B00478;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    func_002675B0(&D_01B00530);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B00478;
    func_00267FA0(&D_01B00530, 0x30);
    return 1;
}
