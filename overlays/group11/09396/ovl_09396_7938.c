/* EE Battle-Effect Overlay: group 0x11, file 09396 (0x01B07938..0x01B07A8C)
 * Shared across 18 open containers (340B each = 6,120B total)
 */
#include "common.h"
#include "vu0.h"

void func_01B01B68(int a0, void *a1, int a2);
void func_01B02008(int a0, int a1, void *a2, void *a3);
u8 *func_01B05B40(int a0);
void func_002DCE08(void *dst, void *m, void *v);
void func_01B03238(void *a0, void *a1);
void func_002DCE38(void *dst, void *a, void *b);
void func_002DD900(void *dst, void *m, void *v, int a3);

void func_01B07938(u8 *a0)
{
    float m0[16];
    float m1[16];
    float m2[16];
    float pos[4];
    int scr[4];
    int flag = 0;

    switch (*(s16 *)(a0 + 0x124)) {
    case 0:
        break;
    case 1:
        func_01B01B68(*(int *)(a0 + 0x11C), pos, *(int *)(a0 + 0x120));
        flag = 1;
        break;
    case 2:
        func_01B02008(*(int *)(a0 + 0x11C), *(int *)(a0 + 0x120), 0, pos);
        flag = 1;
        break;
    case 3:
        func_01B02008(*(int *)(a0 + 0x11C), *(int *)(a0 + 0x120), a0 + 0xE0, pos);
        flag = 1;
        break;
    case 4: {
        u8 *p = func_01B05B40(*(int *)(a0 + 0x120));
        if (((s8 *)p)[0x146] == 0) {
            MMI_COPY_LQ_A3(pos, p + 0x60);
            MMI_COPY_SQ_A3(pos);
        } else {
            func_002DCE08(pos, p, p + 0x60);
        }
        flag = 1;
        break;
    }
    case 5:
        (*(void (**)(u8 *))(a0 + 0xF4))(a0);
        break;
    }

    if (flag == 1) {
        func_01B03238(m1, m2);
        func_002DCE38(m0, m1, m2);
        func_002DD900(scr, m0, pos, 0);
        *(int *)(a0 + 0x114) = (scr[0] >> 4) - 0x700;
        *(int *)(a0 + 0x118) = (scr[1] >> 4) - 0x730;
    }
}
