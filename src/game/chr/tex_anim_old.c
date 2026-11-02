/* tu_107 0x161aa0-0x162618: high; tex_anim_old (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#include "ffx/g1.h"

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", func_00161AA0);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", func_00161B00);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim_old/rodata", jtbl_0056B9C0);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", chr_texanim_main_sub_old);
INCLUDE_RODATA("build/ee_asm/game/chr/tex_anim_old/rodata", jtbl_0056B9E0);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", chr_texanim_draw_sub_old);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", func_00162488);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", func_00162500);

INCLUDE_ASM("build/ee_asm/game/chr/tex_anim_old", func_001625B0);
