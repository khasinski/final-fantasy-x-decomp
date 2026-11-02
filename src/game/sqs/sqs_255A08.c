/* tu_279 0x255a08-0x255ea4: low; unk_255A08 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"

#define GIF_CHCR (*(volatile u32 *)0x1000A000) /* GIF DMA channel control; bit 8 = STR (transfer running) */

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_255A08", func_00255A08);

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_255A08", func_00255B80);

INCLUDE_ASM("build/ee_asm/game/sqs/sqs_255A08", func_00255CF8);
