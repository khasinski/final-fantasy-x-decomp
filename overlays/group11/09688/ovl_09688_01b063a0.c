#include "common.h"

typedef struct S63A0Slot {
    s32 s00;
    s32 s04;
    u8 b08[0x20];
} S63A0Slot; /* size 0x28 */

typedef struct S63A0Work {
    u8 pad00[0xEAD4];
    S63A0Slot slots[4]; /* 0xEAD4..0xEB74 */
    S63A0Slot *cur_slot; /* 0xEB74 */
    s32 num_slots;       /* 0xEB78 */
    s32 slot_idx;        /* 0xEB7C */
    s32 state;           /* 0xEB80 */
    s32 done;            /* 0xEB84 */
} S63A0Work;

extern S63A0Work *D_01B0DCA8;
extern s32 D_01B0DC24;
extern u8 D_01B0DBE0[];
extern void *D_01B0DBD8;
extern s32 D_01B0100C;

extern s32 func_01B070D8(s32 a0);
extern s32 func_01B09D28(void *a0, s32 a1);
extern void func_01B06710(void);
extern void func_001CDDD8(void *a0);
extern u8 *func_001E4680(void *a0, s32 *a1, s32 a2, s32 *a3);

void func_01B063A0(void)
{
    S63A0Work *w = D_01B0DCA8;

    if (func_01B09D28(D_01B0DBE0, D_01B0DC24) == 1 && w->done == 1) {
        func_01B06710();
        func_001CDDD8(D_01B0DBD8);
    }
}

void func_01B06418(void)
{
    s32 sp00;
    s32 sp04;
    S63A0Work *w = D_01B0DCA8;
    s32 max_idx = D_01B0100C;
    S63A0Slot *slot = w->slots;
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *buf = func_001E4680(D_01B0DBD8, &sp00, i, &sp04);
        if (sp04 != 0) {
            s32 j;
            slot->s00 = sp04;
            slot->s04 = sp00;
            for (j = 0; j < sp00; j++) {
                s32 k;
                for (k = 0; k < max_idx; k++) {
                    if (buf[j] == func_01B070D8(k)) {
                        slot->b08[j] = k;
                        break;
                    }
                }
            }
            count++;
            slot++;
        }
    }

    w->num_slots = count;
}
