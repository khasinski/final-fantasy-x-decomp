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
extern PartObjFull D_01B0BFF0;
extern PartObjFull D_01B0C070;
extern PartObjFull D_01B0C0F0;
extern PartObjFull D_01B0C170[3];
extern PartObjFull D_01B0C2F0;
extern PartObjFull D_01B0C370;
extern PartObjFull D_01B0C3F0;
extern PartObjFull D_01B0C470;
extern PartObjFull D_01B0C4F0;
extern PartObjFull D_01B0C570[3];
extern PartObjFull D_01B0C6F0;
extern PartObjFull D_01B0C770;
extern PartObjFull D_01B0C7F0;
extern OefHeapMgr D_01B0C8F0;
extern int D_01B0C9A0;
extern int D_01B0C9A4;
extern int D_01B0C9A8;
extern s16 D_01B0C9D8;
extern s16 D_01B0C9DC;
extern s16 D_01B0C9E6;
extern s16 D_01B0C9E8;
extern s16 D_01B0C9EA;
extern int D_01B0CA58;
extern void *D_01B1D37C;
extern u8 D_01D985C0[];

void func_002B2730(int);
void func_01B06CB8(void);
void func_01B044C8(void *);
void func_00103788(int);
void func_01B04560(int, int, int, u8, u8, u8);
void func_01B04650(int, int, int, int, u8, u8, u8, int);
void func_01B05C70(void);

int func_01B0A548(void)
{
    register u_long128 _s0 __asm__("$16");
    if (D_01B00A24 == 0) {
        return 0;
    }
    if (D_01B0CA58 == 0) {
        __asm__ volatile("");
        return 0;
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    {
        register void *mgr __asm__("$2") = &D_01B0C8F0;
        D_006A3924 = mgr;
    }
    if (D_01B0C070.enabled != 0) {
        func_002B2730(0);
        func_01B06CB8();
    }
    D_006A3BCC = D_01D985C0;
    func_01B044C8(&D_01B0BFF0);
    func_01B044C8(&D_01B0C070);
    func_01B044C8(&D_01B0C0F0);
    func_01B044C8(&D_01B0C170[0]);
    func_01B044C8(&D_01B0C170[1]);
    func_01B044C8(&D_01B0C170[2]);
    func_01B044C8(&D_01B0C2F0);
    func_01B044C8(&D_01B0C370);
    func_01B044C8(&D_01B0C3F0);
    func_01B044C8(&D_01B0C470);
    func_01B044C8(&D_01B0C4F0);
    func_01B044C8(&D_01B0C570[0]);
    func_01B044C8(&D_01B0C570[1]);
    func_01B044C8(&D_01B0C570[2]);
    func_01B044C8(&D_01B0C6F0);
    func_01B044C8(&D_01B0C770);
    func_01B044C8(&D_01B0C7F0);
    if (D_01B0C070.enabled != 0) {
        func_00103788(1);
    }
    switch (D_01B0C9A8) {
    case 0:
        if (D_01B0C9D8 <= 20) {
            func_01B04560(D_01B0C9D8, 0, 20, 0, 0, 0);
        }
        break;
    case 1:
        if ((D_01B0C070.cnt >> 12) >= (D_01B0C070.dur >> 12) - 65) {
            func_01B04560(D_01B0C070.cnt >> 12, (D_01B0C070.dur >> 12) - 65, 20, 0, 0, 0);
        }
        break;
    case 3:
        if (D_01B0C9DC < 40) {
            func_01B04560(40 - D_01B0C9DC, 0, 40, 0, 0, 0);
        }
        break;
    case 16:
        func_01B04650(D_01B0C9E6, 20, 4, 15, 64, 64, 64, 72);
        func_01B04650(D_01B0C9E6, 274, 4, 15, 64, 64, 64, 72);
        break;
    case 21:
        if (D_01B0C9E8 < 40) {
            func_01B04560(40 - D_01B0C9E8, 0, 40, 0, 0, 0);
        }
        func_01B04650(D_01B0C9E8, 85, 4, 15, 255, 255, 255, 68);
        if (D_01B0C9E8 > 175) {
            int t = D_01B0C9E8 - 175;
            if (t <= 60) {
                func_01B04560(t, 0, 60, 255, 255, 255);
            }
        }
        break;
    case 23:
        if (D_01B0C9EA < 30) {
            func_01B04560(30 - D_01B0C9EA, 0, 30, 255, 255, 255);
        }
        break;
    }
    func_01B05C70();
    if (D_006A3BC4 == 0) {
        D_01B0C9A8 = D_01B0C9A4;
        D_01B0C9A0++;
    }
    {
        register void *tmp __asm__("$4") = D_006A3BCC;
        register int ret __asm__("$2") = 0;
        D_01B1D37C = tmp;
        __asm__ volatile("" : "=r"(_s0));
        return ret;
    }
}
