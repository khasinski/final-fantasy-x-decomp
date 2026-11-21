/* Shared P6 -O2 init helper (hash cf2484, 276B). */
#include "p6_overlay.h"

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern void *D_01B004D8;
extern u8 D_01B008A0[];
extern P6Node D_01B008B8;
extern P6Node D_01B008D8;
extern u8 D_01B02580[];
extern u8 D_01B0CC90[];
extern void *D_01B0CCBC;
extern u8 D_01B4DB70[];
extern u8 D_01C4DB70[];

extern void func_01B02A60(void);
extern void func_01B02F38(void *);
extern void func_01B03A40(void *);
extern void func_01B0BBF8(void *);

extern void _pppInitData(void *, void *);
extern void pppInitEnv(void *, void *, void *, int);
extern void func_002944B0(void *, int, int, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B02FA0(void)
{
    void *msg[2];
    void *root_msg[1];
    void *p;

    func_01B02A60();
    D_01B0004C = D_01C4DB70;
    root_msg[0] = D_01B008A0;
    func_01B0BBF8(root_msg);

    msg[0] = &D_01B008B8;
    msg[1] = 0;
    func_01B03A40(msg);
    D_01B008B8.b1B = 1;

    msg[0] = &D_01B008D8;
    msg[1] = 0;
    func_01B03A40(msg);

    func_002B4980(D_01B004D8);
    p = func_002B49A0(D_01B004D8, 8, 0);
    D_01B0CCBC = p;
    _pppInitData(p, D_01B00050);
    pppInitEnv(D_01B0CC90, D_01B0CCBC, D_01B4DB70, 0x100000);
    func_002D02E8(D_01B004D8, 0, 1000, 2);
    func_002944B0(D_01B004D8, 0, 1000, 2);
    func_01B02F38(D_01B02580);
    return 0;
}
