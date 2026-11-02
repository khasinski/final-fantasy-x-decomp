/* tu_332 0x2cec08-0x2ceff0: medium; unk_2CEC08 (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: bitfield/size helpers and wrappers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEC08);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEC98);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CED28);

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEDD8);

void func_002CEE60(s32 a, s32 b) {
    func_002CEDD8(a, b, 0, 0x4000);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEE70);

void func_002CEEC0(s32 a, u16 b, u16 c) {
    func_002CEE70(a, b, c, 0, 0x4000);
}

void func_002CEED8(s32 a, s32 b) {
    func_002CEE60(a, b);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEEE0);

/* DEBT(CAST): explicit width views follow the existing shared interfaces. */
int func_002CEF70(W10SoundVoice *voice)
{
    int multiplier = 7;
    if (voice->header.half[0] & 8) multiplier = 14;
    return (multiplier * (s16)voice->header.half[1] + 7) * 16;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEF98);

void func_002CEFE8(void) {
    func_002CD590();
}
