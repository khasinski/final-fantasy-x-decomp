/* tu_280 0x255ea4-0x256098: high; unk_255EA4 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"

#define GIF_CHCR (*(volatile u32 *)0x1000A000) /* GIF DMA channel control; bit 8 = STR (transfer running) */

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_255EA4", func_00255EA4);

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_255EA4", func_00255EC8);

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_255EA4", func_00256074);
