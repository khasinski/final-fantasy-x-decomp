#include "common.h"

typedef struct {
    void *p00;
    int w04;
} Call41F0;

typedef struct {
    void *p00;
} CallCE18;

extern u8 D_01C17FD0[];
extern u8 D_01B009A0[];
extern u8 D_01B009B8[];
extern u8 D_01B009D8[];
extern u8 D_01B00050[];
extern u8 D_01B0DEC0[];
extern u8 D_01B97FD0[];
extern u8 D_01B01460[];
extern void *D_01B0004C;
extern void *D_01B009F4;
extern void *D_01B00578;
extern void *D_01B0DEEC;

extern void func_01B01AB8(void);
extern void func_01B0CE18(CallCE18 *);
extern void func_01B041F0(Call41F0 *);
extern void op_oef2_set2(void *);
extern void *op_oef2_a_get(void *, int, int);
extern void _pppInitData(void *, void *);
extern void pppInitEnv(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void op_oef2_sound_cue_multi(void *, int, int, int);
extern void func_01B02208(void *);

int func_01B02270(void) {
    Call41F0 c0;
    CallCE18 c1;
    u8 *p;

    func_01B01AB8();
    p = D_01C17FD0;
    D_01B009F4 = p;
    D_01B0004C = p + 0x80000;
    c1.p00 = D_01B009A0;
    func_01B0CE18(&c1);
    c0.p00 = D_01B009B8;
    c0.w04 = 0;
    func_01B041F0(&c0);
    D_01B009B8[27] = 1;
    c0.p00 = D_01B009D8;
    c0.w04 = 0;
    func_01B041F0(&c0);
    op_oef2_set2(D_01B00578);
    D_01B0DEEC = op_oef2_a_get(D_01B00578, 8, 0);
    _pppInitData(D_01B0DEEC, D_01B00050);
    pppInitEnv(D_01B0DEC0, D_01B0DEEC, D_01B97FD0, 0x80000);
    func_002D02E8(D_01B00578, 0, 1000, 2);
    op_oef2_sound_cue_multi(D_01B00578, 0, 1000, 2);
    func_01B02208(D_01B01460);
    return 0;
}
