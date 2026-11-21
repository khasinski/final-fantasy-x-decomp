/* EE Battle-Effect Overlay: group 0x11, file 09127 (shared by 9127, 9130, 9131)
 * .text: 0x01B01770..0x01B019E4 (1 function, 628B).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x20];
    u8 b20[0x100];      /* 0x20 */
    u8 b150[0x20];      /* 0x120 */
    float f170;         /* 0x140 */
    float f174;         /* 0x144 */
    float f178;         /* 0x148 */
    float f17C;         /* 0x14C */
    u8 b120[0x20];      /* 0x150 */
    u8 b140[0x10];      /* 0x170 */
    u8 b180[0x150];     /* 0x180 */
    float f2D0;         /* 0x2D0 */
    u16 h2D4;           /* 0x2D4 */
} Ovl9127Eff;

typedef struct {
    void *p0;
    void *p1;
    u32 w2;
    u8 b3;
} Ovl9127Msg3138;

typedef struct {
    u8 pad00[0x30];
    float f30, f34, f38;
    u8 pad3C[0x24];
    float f60, f64, f68, f6C;
} Ovl9127ObjC30;

extern void *D_01B004D8;
extern u8 D_01B004F0;
extern u8 D_01B00600[];
extern u8 D_01B00690[];
extern u8 D_01B008A0[];
extern u8 D_01B008B8[];
extern u8 D_01B008D8[];
extern u8 D_01B00940[];
extern u8 D_01B009D0[];
extern u8 D_01B00B20[];
extern u8 D_01B00B90[];
extern Ovl9127ObjC30 D_01B00C30;
extern u8 D_01B0D800[];
extern void *D_01B0D82C;

extern void func_01B01668(void *);
extern void func_01B0C410(void *);
extern void func_01B0C818(void *);
extern void func_01B03138(void *);
extern void func_01B06B90(void *);
extern void func_01B02E98(void *);
extern void func_01B09300(void *);
extern void func_01B0B460(void *);
extern void func_01B0ABF0(void *);
extern void func_01B0ABB8(void *);
extern void func_01B05ED8(void *);
extern void func_01B06008(void *);

void func_01B01770(Ovl9127Eff *eff)
{
    /* DEBT(PADDING): P6 message buffer with overlapping 16(sp) sub-message for 9300 */
    void *m0[10];
    void **m16;

    m0[0] = eff;
    m0[1] = (void *)func_01B01668;
    m0[2] = eff;
    func_01B0C410(m0);

    m0[0] = D_01B008A0;
    m0[1] = eff;
    func_01B0C818(m0);

    eff->f2D0 = 0.0f;
    eff->h2D4 = 0;

    ((Ovl9127Msg3138 *)m0)->p0 = D_01B00B90;
    ((Ovl9127Msg3138 *)m0)->p1 = D_01B008B8;
    ((Ovl9127Msg3138 *)m0)->w2 = D_01B004F0;
    ((Ovl9127Msg3138 *)m0)->b3 = 0;
    func_01B03138(m0);

    m0[0] = eff->b120;
    m0[1] = D_01B008B8;
    func_01B06B90(m0);

    m0[0] = D_01B00B90;
    m0[1] = eff->b140;
    m0[2] = 0;
    func_01B02E98(m0);

    m0[0] = eff->b150;
    m0[1] = D_01B008B8;
    func_01B06B90(m0);

    {
        /* DEBT(FAKE): pin m16/D_01B00690/D_01B00940 to v1/v0/a1 */
        /* DEBT(ORDER): volatile stores preserve sw/swc1 interleaving for 9300 message */
        register float f10 __asm__("$f0") = 1.0f;
        register void *p690 __asm__("$2") = D_01B00690;
        register void **p16 __asm__("$3") = m0 + 4;
        register void *p940 __asm__("$5") = D_01B00940;
        m0[4] = eff->b180;
        *(volatile float *)&eff->f17C = f10;
        p16[2] = p690;
        *(void *volatile *)&m0[7] = eff->b120;
        *(void *volatile *)&p16[4] = p940;
        *(void *volatile *)&m0[9] = eff->b150;
        *(volatile float *)&eff->f170 = f10;
        *(volatile float *)&eff->f174 = f10;
        *(volatile float *)&eff->f178 = f10;
        p16[1] = D_01B008B8;
        m16 = p16;
    }
    func_01B09300(m16);

    m0[0] = eff->b20;
    m0[1] = D_01B008D8;
    m0[2] = eff->b180;
    m0[3] = D_01B0D82C;
    m0[4] = D_01B0D800;
    m0[5] = (void *)3;
    func_01B0B460(m0);

    m0[0] = D_01B00B20;
    m0[1] = D_01B008B8;
    m0[2] = D_01B009D0;
    m0[3] = D_01B00600;
    m0[4] = D_01B004D8;
    m0[5] = 0;
    func_01B0ABF0(m0);

    m0[0] = D_01B00B20;
    m0[1] = 0;
    func_01B0ABB8(m0);

    m0[0] = D_01B00B20 + 0x38;
    m0[1] = D_01B008B8;
    m0[2] = D_01B009D0;
    m0[3] = D_01B00600;
    m0[4] = D_01B004D8;
    m0[5] = (void *)1;
    func_01B0ABF0(m0);

    m0[0] = D_01B00B20 + 0x38;
    m0[1] = 0;
    func_01B0ABB8(m0);

    m0[0] = &D_01B00C30;
    m0[1] = D_01B008D8;
    func_01B05ED8(m0);

    {
        float half = 0.5f;
        D_01B00C30.f60 = D_01B00C30.f64 = D_01B00C30.f68 = D_01B00C30.f6C = half;
        D_01B00C30.f34 = D_01B00C30.f38 = half;
        D_01B00C30.f30 = half;
    }
    m0[0] = &D_01B00C30;
    ((float *)m0)[2] = 0.1f;
    m0[1] = 0;
    func_01B06008(m0);
}
