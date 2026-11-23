/* EE Battle-Effect Overlay: group 0x11, file 09635 (unique 0x01B018E8..0x01B01A84)
 * Load base: 0x01B00000, .text: 0x01B018E8..0x01B01A84 (2 functions, 6 chunks in map)
 */
#include "common.h"

void Ch_OptposGet(void *chr, int optpos, float *dst);
float Ch_GetJimen(void *chr);
void Ch_GetPos(void *chr, float *x, float *y, float *z);

void *func_01B017A0(int a0);
void func_01B018B8(float a0);
float func_01B01C80(int a0);

void func_01B018E8(float a0)
{
    register float c __asm__("$f1") = 4.712389f;
    float f = c - a0;

    if (f > 3.1415927f) {
        f -= 6.2831855f;
    } else if (f < -3.1415927f) {
        f += 6.2831855f;
    }
    func_01B018B8(f);
}

void func_01B01958(int a0, float *a1, int a2)
{
    float tmp[4];
    void *chr;
    float h;

    chr = func_01B017A0(a0);
    Ch_GetPos(chr, &a1[0], &a1[1], &a1[2]);
    switch (a2) {
    case 0:
        break;
    case 1:
        Ch_OptposGet(chr, 6, tmp);
        a1[1] = tmp[1];
        break;
    case 2:
        h = func_01B01C80(a0);
        Ch_OptposGet(chr, 6, tmp);
        a1[1] = tmp[1] - h * 0.5f;
        break;
    case 3:
        a1[1] = Ch_GetJimen(chr);
        break;
    case 4:
        Ch_OptposGet(chr, 0x10, a1);
        break;
    case 5:
        Ch_OptposGet(chr, 0x11, a1);
        break;
    case 6:
        Ch_OptposGet(chr, 0x10, a1);
        a1[1] = Ch_GetJimen(chr);
        break;
    case 7:
        Ch_OptposGet(chr, 0x11, a1);
        a1[1] = Ch_GetJimen(chr);
        break;
    }
    a1[3] = 1.0f;
}
