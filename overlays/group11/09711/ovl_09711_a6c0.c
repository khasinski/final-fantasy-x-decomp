#include "oef_overlay.h"

typedef struct PartObjFull {
    int f00;           /* 0x00 */
    int dur;           /* 0x04 */
    int cnt;           /* 0x08 */
    u8 pad0C[0x12];
    u16 enabled;       /* 0x1E */
    u8 pad20[0x60];
} PartObjFull;         /* 0x80 */

extern int D_01B00A24;
extern PartObjFull D_01B0C120;
extern PartObjFull D_01B0C1A0;
extern PartObjFull D_01B0C220;
extern PartObjFull D_01B0C2A0[3];
extern PartObjFull D_01B0C420;
extern PartObjFull D_01B0C4A0;
extern PartObjFull D_01B0C520;
extern PartObjFull D_01B0C5A0;
extern PartObjFull D_01B0C620;
extern PartObjFull D_01B0C6A0[3];
extern PartObjFull D_01B0C820;
extern PartObjFull D_01B0C8A0;
extern PartObjFull D_01B0C920;
extern OefHeapMgr D_01B0CA20;
extern int D_01B0CAD0;
extern int D_01B0CAD4;
extern int D_01B0CAD8;
extern s16 D_01B0CB0C;
extern s16 D_01B0CB16;
extern s16 D_01B0CB18;
extern s16 D_01B0CB1A;
extern int D_01B0CB88;
extern void *D_01B1D4AC;
extern u8 D_01D986F0[];

void func_002B2730(int);
void func_01B06CB8(void);
void func_01B044C8(void *);
void func_00103788(int);
void func_01B04560(int, int, int, u8, u8, u8);
void func_01B04650(int, int, int, int, u8, u8, u8, int);
void func_01B05C70(void);

int func_01B0A6C0(void)
{
    register u_long128 _s0 __asm__("$16");
    if (D_01B00A24 == 0) {
        return 0;
    }
    if (D_01B0CB88 == 0) {
        __asm__ volatile("");
        return 0;
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    {
        register void *mgr __asm__("$2") = &D_01B0CA20;
        D_006A3924 = mgr;
    }
    if (D_01B0C1A0.enabled != 0) {
        func_002B2730(0);
        func_01B06CB8();
    }
    D_006A3BCC = D_01D986F0;
    func_01B044C8(&D_01B0C120);
    func_01B044C8(&D_01B0C1A0);
    func_01B044C8(&D_01B0C220);
    func_01B044C8(&D_01B0C2A0[0]);
    func_01B044C8(&D_01B0C2A0[1]);
    func_01B044C8(&D_01B0C2A0[2]);
    func_01B044C8(&D_01B0C420);
    func_01B044C8(&D_01B0C4A0);
    func_01B044C8(&D_01B0C520);
    func_01B044C8(&D_01B0C5A0);
    func_01B044C8(&D_01B0C620);
    func_01B044C8(&D_01B0C6A0[0]);
    func_01B044C8(&D_01B0C6A0[1]);
    func_01B044C8(&D_01B0C6A0[2]);
    func_01B044C8(&D_01B0C820);
    func_01B044C8(&D_01B0C8A0);
    func_01B044C8(&D_01B0C920);
    if (D_01B0C1A0.enabled != 0) {
        func_00103788(1);
    }
    switch (D_01B0CAD8) {
    case 1:
        if ((D_01B0C1A0.cnt >> 12) >= (D_01B0C1A0.dur >> 12) - 65) {
            func_01B04560(D_01B0C1A0.cnt >> 12, (D_01B0C1A0.dur >> 12) - 65, 20, 0, 0, 0);
        }
        break;
    case 3:
        if (D_01B0CB0C < 40) {
            func_01B04560(40 - D_01B0CB0C, 0, 40, 0, 0, 0);
        }
        break;
    case 16:
        func_01B04650(D_01B0CB16, 20, 4, 15, 64, 64, 64, 72);
        func_01B04650(D_01B0CB16, 274, 4, 15, 64, 64, 64, 72);
        break;
    case 21:
        func_01B04650(D_01B0CB18, 55, 4, 15, 255, 255, 255, 68);
        if (D_01B0CB18 > 145) {
            int t = D_01B0CB18 - 145;
            if (t <= 60) {
                func_01B04560(t, 0, 60, 255, 255, 255);
            }
        }
        break;
    case 23:
        if (D_01B0CB1A < 30) {
            func_01B04560(30 - D_01B0CB1A, 0, 30, 255, 255, 255);
        }
        break;
    }
    func_01B05C70();
    if (D_006A3BC4 == 0) {
        D_01B0CAD8 = D_01B0CAD4;
        D_01B0CAD0++;
    }
    {
        register void *tmp __asm__("$4") = D_006A3BCC;
        register int ret __asm__("$2") = 0;
        D_01B1D4AC = tmp;
        __asm__ volatile("" : "=r"(_s0));
        return ret;
    }
}
