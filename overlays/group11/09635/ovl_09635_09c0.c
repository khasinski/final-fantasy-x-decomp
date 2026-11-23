/* EE Battle-Effect Overlay: group 0x11, file 09635 (unique 0x01B009C0)
 * Load base: 0x01B00000, .text: 0x01B009C0..0x01B00A70 (1 function)
 */
#include "common.h"

extern void *D_01B00000[];
extern int D_01B07500;
extern int D_01B07504;

int MsEffectMotionLevel(int eff_id);
void MsEffectReady(int eff_id, int ready);
int func_0029B830(int eff_id);
void func_01B00A70(void);
void func_01B00AC0(void);
int func_01B00AF8(void);
void func_01B00B20(void);

int func_01B009C0(void)
{
    int ready;

    if (func_0029B830(1) != 0) {
        return 0;
    }
    ready = func_01B00AF8();
    if (ready != 1) {
        return 0;
    }
    if (D_01B07504 == 0) {
        MsEffectReady(D_01B07500, 1);
        D_01B07504 = ready;
    }
    if (MsEffectMotionLevel(D_01B07500) <= 0) {
        return 0;
    }
    func_01B00B20();
    D_01B00000[3] = func_01B00A70;
    D_01B00000[4] = func_01B00AC0;
    return 0;
}
