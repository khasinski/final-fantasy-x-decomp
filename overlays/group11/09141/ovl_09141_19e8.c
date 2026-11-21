/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared by 8 P6 overlays)
 * .text: 0x01B019E8..0x01B01BC4 (1 function, 476B).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;             /* 0x1B */
} Ovl9141S0;

typedef struct {
    u8 pad00[0x30];
    u8 b30;             /* 0x30 */
} Ovl9141S3;

typedef struct {
    u8 pad00[0x34];
    u8 b34;             /* 0x34 */
} Ovl9141S2;

typedef struct {
    u8 pad00[0x40];
    u8 b40;             /* 0x40 */
} Ovl9141S1;

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern void *D_01B004D8;
extern u8 D_01B004F0;
extern u8 D_01B00690[];
extern u8 D_01B008A0[];
extern Ovl9141S0 D_01B008B8;
extern u8 D_01B008D8[];
extern Ovl9141S3 D_01B00900;
extern Ovl9141S2 D_01B00940;
extern Ovl9141S1 D_01B00980;
extern u8 D_01B009D0[];
extern u8 D_01B00CF0[];
extern u8 D_01B0D800[];
extern void *D_01B0D82C;
extern u8 D_01BBD370[];
extern u8 D_01DBD370[];

extern void func_01B014E0(void);
extern void func_01B0C760(void *);
extern void func_01B02308(void *);
extern void func_01B07060(void *);
extern void func_01B08398(void *);
extern void func_01B07708(void *);
extern void func_01B09300(void *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_00294468(void *, int, int);
extern void func_01B01778(void *);

static __inline__ void call_c760(void *a0)
{
    void *m[1];
    m[0] = a0;
    func_01B0C760(m);
}

static __inline__ void call_9300(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
    void *m[6];
    m[0] = a0;
    m[1] = a1;
    m[2] = a2;
    m[3] = a3;
    m[4] = a4;
    m[5] = a5;
    func_01B09300(m);
}

int func_01B019E8(void)
{
    void *m0[2];
    u8 b;

    func_01B014E0();
    D_01B0004C = D_01DBD370;

    call_c760(D_01B008A0);

    m0[0] = &D_01B008B8;
    m0[1] = 0;
    func_01B02308(m0);
    D_01B008B8.b1B = 1;

    m0[0] = D_01B008D8;
    m0[1] = 0;
    func_01B02308(m0);

    m0[0] = &D_01B00900;
    m0[1] = &D_01B008B8;
    func_01B07060(m0);

    m0[0] = &D_01B00940;
    m0[1] = &D_01B008B8;
    func_01B08398(m0);

    m0[0] = &D_01B00980;
    m0[1] = &D_01B008B8;
    func_01B07708(m0);

    b = D_01B004F0;
    D_01B00900.b30 = b;
    D_01B00940.b34 = b;
    D_01B00980.b40 = b;

    call_9300(D_01B009D0, &D_01B008B8, D_01B00690, &D_01B00900, &D_01B00940, &D_01B00980);

    func_002B4980(D_01B004D8);
    D_01B0D82C = func_002B49A0(D_01B004D8, 8, 0);
    func_002678E0(D_01B0D82C, D_01B00050);
    func_00267A68(D_01B0D800, D_01B0D82C, D_01BBD370, 0x200000);
    func_002D02E8(D_01B004D8, 0, 1000, 2);
    func_002944B0(D_01B004D8, 0, 1000, 2);
    func_00294468(func_002B49A0(D_01B004D8, 6, 1), 0, 2);
    func_01B01778(D_01B00CF0);
    return 0;
}
