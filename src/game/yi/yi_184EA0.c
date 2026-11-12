/* tu_133 0x184ea0-0x187260: low; ~yiPacketConvToOMD (config/tu_map.tsv) */
#include "common.h"
#include "ffx/v2.h"

typedef struct S2DmaCtl { u8 f0 : 1; u8 f1 : 1; u8 f2 : 2; u8 f4 : 2; u8 f6 : 1; u8 f7 : 1; } S2DmaCtl;
void Sg_MFIFOSync(void);
int func_002DA610(int a, int b); /* DEBT(TYPE): asm reads (int a); C callers c_2203B8.c:36 pass 2 */
u32 *func_002DB6D8(int a0);
extern void func_002DBB00(S2DmaCtl *ch, int a, int b);
void func_002DBF78(int a, int b, int c);
void func_002F8660();
void func_00184EA0(s32 arg0, s32 arg1) {
    s32 temp_2;

    Sg_MFIFOSync();
    func_002DA610(0, 0);
    temp_2 = func_002DB6D8(2);
    func_002DBF78(temp_2, 0, 0x100);
    *(volatile u8 *)(temp_2) |= 1;
    *(volatile u8 *)(temp_2) |= 0x40;
    *(volatile u8 *)(temp_2) &= 0x7F;
    *(u8 *)(temp_2) &= 0xF3;
    func_002F8660(0);
    func_002DBB00((S2DmaCtl *) temp_2, arg0, arg1);
    func_002DA610(0, 0);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", func_00184F50);

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", func_00185408);

typedef struct YiMesh1854D8 {
    s32 w00;
    s32 w04;
    s32 v_ofs;
    s32 w0C;
    u16 h10;
    s16 v_cnt;
} YiMesh1854D8;

extern float D_0056CF64;
extern float D_0056CF68;

int func_001854D8(YiMesh1854D8 *m, float *min, float *max)
{
    int i;
    int j;
    float *v;

    v = (float *)((u8 *)m + m->v_ofs);
    for (i = 0; i < 3; i++) {
        min[i] = D_0056CF64;
        max[i] = D_0056CF68;
    }
    min[3] = 1.0f;
    max[3] = 1.0f;
    for (i = 0; i < m->v_cnt; i++) {
        for (j = 0; j < 3; j++) {
            if (min[j] > v[j]) {
                min[j] = v[j];
            }
            if (max[j] < v[j]) {
                max[j] = v[j];
            }
        }
        v += 4;
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", func_001855C0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", yiPacketConvToOMD_DRAWACC);

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", yiGui_setfogparam_proc);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_184EA0/rodata", jtbl_0056CFF0);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_184EA0/rodata", jtbl_0056D040);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_184EA0/rodata", jtbl_0056D0A0);

INCLUDE_ASM("build/ee_asm/game/yi/yi_184EA0", func_00186C00);
