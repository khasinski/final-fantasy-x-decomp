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

extern int D_01B00450;
extern int D_01B00458;
extern TtCfg *D_01B00474;
extern u8 D_01B00478;
extern PppObj D_01B006B0;
extern float D_01B00BE0[4];
extern char D_01B02B60[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern int func_01B01EB0(char *, ...);
extern void func_00107428(int, int, int, void *);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

int func_01B016E8(void)
{
    func_01B01EB0(D_01B02B60, D_01B00458);
    D_006A3924 = &D_01B00478;
    func_00267658(&D_01B006B0, 0x1000, D_01B00474->w10[1], 1);
    D_01B006B0.pos[0] = 0.0f;
    D_01B006B0.pos[1] = 0.0f;
    D_01B006B0.pos[2] = 0.0f;
    D_01B006B0.pos[3] = 1.0f;
    D_01B006B0.rot[0] = 0;
    D_01B006B0.rot[1] = 0;
    D_01B006B0.rot[2] = 0;
    D_01B006B0.rot[3] = 1;
    D_01B006B0.scale[2] = D_01B006B0.scale[1] = D_01B006B0.scale[0] = 0.125f;
    D_01B006B0.scale[3] = 1.0f;
    return 1;
}

int func_01B01798(void)
{
    D_006A3924 = &D_01B00478;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    func_00107428(D_01B00450, 0xB, 0, D_01B00BE0);
    D_01B006B0.pos[0] = D_01B00BE0[0];
    D_01B006B0.pos[1] = D_01B00BE0[1];
    D_01B006B0.pos[2] = D_01B00BE0[2];
    func_002675B0(&D_01B006B0);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B00478;
    return func_00267FA0(&D_01B006B0, 0x30) == 0;
}
