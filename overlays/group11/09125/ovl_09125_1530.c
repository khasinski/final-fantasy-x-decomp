/* EE Battle-Effect Overlay: group 0x11, file 09125 (shared by 9120..9125)
 * .text: 0x01B01530..0x01B01664 (1 function, 308B).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;             /* 0x1B */
} Ovl9125S0;

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern void *D_01B00460;
extern u8 D_01B00830[];
extern Ovl9125S0 D_01B00848;
extern u8 D_01B00868[];
extern u8 D_01B009A0[];
extern u8 D_01B0B000[];
extern void *D_01B0B02C;
extern u8 D_01B69B80[];
extern u8 D_01C69B80[];

extern void func_01B01110(void);
extern void func_01B09F60(void *);
extern void func_01B01DA8(void *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_00294468(void *, int, int);
extern void func_01B01318(void *);

static __inline__ void call_9f60(void *a0)
{
    void *m[1];
    m[0] = a0;
    func_01B09F60(m);
}

int func_01B01530(void)
{
    void *m0[2];

    func_01B01110();
    D_01B0004C = D_01C69B80;

    call_9f60(D_01B00830);

    m0[0] = &D_01B00848;
    m0[1] = 0;
    func_01B01DA8(m0);
    D_01B00848.b1B = 1;

    m0[0] = D_01B00868;
    m0[1] = 0;
    func_01B01DA8(m0);

    func_002B4980(D_01B00460);
    D_01B0B02C = func_002B49A0(D_01B00460, 8, 0);
    func_002678E0(D_01B0B02C, D_01B00050);
    func_00267A68(D_01B0B000, D_01B0B02C, D_01B69B80, 0x100000);
    func_002D02E8(D_01B00460, 0, 1000, 2);
    func_002944B0(D_01B00460, 0, 1000, 2);
    func_00294468(func_002B49A0(D_01B00460, 6, 1), 0, 2);
    func_01B01318(D_01B009A0);
    return 0;
}
