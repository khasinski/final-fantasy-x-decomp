/* tu_259 0x234910-0x234a30: low; unk_234910 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

void func_00234910(void) {
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    func_00225B00();
}

void func_00234948(void) {
}

void func_00234950(int a, int b)
{
    char *name;

    if (b == 11) {
        name = (char *)MsGetSaveChrName(11); /* DEBT(CAST): name buffer of party slot 11 */
        if (func_0020B850() == 0 && func_001BD360() == 0) {
            func_0014D610(TOMenuGetNameMes(D_00325B18[11].id), name);
        } else {
            func_002F072C(name, (char *)TOMenuGetNameMes(D_00325B60[11].id)); /* DEBT(CAST): returns a string address */
        }
    }
    func_002346D8(0, b);
    func_00227480(D_00572218);
    func_00227480(D_00572220);
}

void func_00234A00(void) {
    func_00227490((int)&D_00572218); /* DEBT(CAST): address passed as int */
    func_00227490((int)&D_00572220);
}

void func_00234A28(void) {
}
