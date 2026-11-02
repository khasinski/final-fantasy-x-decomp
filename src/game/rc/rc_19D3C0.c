/* tu_164 0x19d3c0-0x19d458: low; unk_19D3C0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

void func_0019D3C0(void)
{
    func_2023C10();
}

void func_0019D3C8(void)
{
    W3Obj50 a;
    W3Obj20 b;
    W3Obj20 d;
    Vec4 c;
    W3ObjBig e;

    rcdtTm2Init(&a);
    rcdtTm2Fini(&a);
    func_0019E150(&b);
    func_0019E160(&b);
    rcbgIDLoad();
    rcVec3fNormalize(&c);
    rcVec3fLength(&c);
    func_0018F310(&d);
    rcbgPSimInit(0);
    rcefMainProcRunAfter(&e);
    func_001A2698(0, 0, 0, 0);
}

void func_0019D450(void)
{
}
