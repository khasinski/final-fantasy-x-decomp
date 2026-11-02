/* tu_038 0x1201b0-0x120cf8: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", func_001201B0);

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", Sg_VectorToMatrix2);

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", Sg_MatrixToQuaternion);

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", func_00120958);

INCLUDE_ASM("build/ee_asm/game/main/sg_1201B0", Sg_QuaternionSlerp);
