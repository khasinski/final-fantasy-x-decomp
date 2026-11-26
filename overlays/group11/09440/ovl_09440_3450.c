/* EE Battle-Effect Overlay: group 0x11, file 09440 (0x01B03450..0x01B034CC)
 * .text: 1 function (124 bytes)
 */
#include "common.h"

extern u8 *D_01B0A2C0;
extern int D_01B0A2D8;

void func_01B02D18(void);
void func_01B02280(void);
void func_01B09A18(void *a0, int a1, int a2, float f0, float f1);

void func_01B03450(void)
{
    u8 *w = D_01B0A2C0;

    if (D_01B0A2D8 == 0) {
        func_01B02D18();
        return;
    }
    func_01B02280();
    func_01B09A18(w + 0xEA0, 0x1E, 0x6E, 0.6f, 1.0f);
    *(float *)(w + 0xEA0) = 0.7f;
}
