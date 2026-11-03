/* WIP (package p4, TU rank 15 func_01B0A008, file09065, 0x2E0 B x 129 containers; its neighbours
 * func_01B09F78 / func_01B0A2E8 are matched as ovl_09065_sprites_cmd.c / _wave.c).
 * Build with P4_CFLAGS. Remaining diff (9 blocks): in the second sprite the original keeps
 * `li a1,0x9000` / `sw a1,64(s0)` late and stores st0[0] early; tail block picks v1 for the
 * D_006F2CE0 address (this C: a1). Statement order of the sprite fields has no effect. */
#include "p4_overlay.h"

void func_01B0A008(u_long64 *tex, int alpha)
{
    u_long64 *pkt;
    P4Sprite *s;
    u_long64 *tail;
    int i;
    int j;
    int k;
    float y;
    float y1;
    float r;

    k = 0;
    pkt = func_002B3888(0x1000);
    y = 0.0f;
    for (i = 0; i < 26; i++) {
        pkt[0] = 0x700000A9;
        pkt[1] = 0;
        pkt[2] = 0x4000000000000001;
        pkt[3] = 0xEEEE;
        pkt[4] = *tex;
        pkt[5] = 6;
        pkt[6] = 1;
        pkt[7] = 0x14;
        pkt[8] = 0;
        pkt[9] = 8;
        ((s32 *)pkt)[20] = alpha;
        ((s32 *)pkt)[21] = 0x80;
        pkt[11] = 0x42;
        pkt[12] = 0x502B400000000020;
        pkt[13] = 0x42412;
        s = (P4Sprite *)(pkt + 14);
        for (j = 0; j < 16; j++) {
            y1 = y + 1.0f / 256;
            r = func_002B3DB0(1.0f);
            s->st0[0] = r;
            s->st0[1] = y;
            s->st0[2] = 1.0f;
            s->rgba[0] = 0x60;
            s->rgba[1] = 0x60;
            s->rgba[2] = 0x60;
            s->rgba[3] = 0x80;
            s->xyz0[0] = 0x7000;
            s->xyz0[1] = k * 16 + 0x7300;
            s->xyz0[2] = -2;
            s->xyz0[3] = 0;
            s->st1[0] = r + 1.0f;
            s->st1[1] = y1;
            s->st1[2] = 1.0f;
            s->xyz1[0] = 0x8000;
            s->xyz1[1] = (k + 1) * 16 + 0x7300;
            s->xyz1[2] = -2;
            s->xyz1[3] = 0;
            s++;
            r = func_002B3DB0(1.0f);
            s->st0[0] = r;
            s->st0[1] = y;
            s->st0[2] = 1.0f;
            s->rgba[0] = 0x60;
            s->rgba[1] = 0x60;
            s->rgba[2] = 0x60;
            s->rgba[3] = 0x80;
            s->xyz0[0] = 0x8000;
            s->xyz0[1] = k * 16 + 0x7300;
            s->xyz0[2] = -2;
            s->xyz0[3] = 0;
            s->st1[0] = r + 1.0f;
            s->st1[1] = y1;
            s->st1[2] = 1.0f;
            s->xyz1[0] = 0x9000;
            s->xyz1[1] = (k + 1) * 16 + 0x7300;
            s->xyz1[2] = -2;
            s->xyz1[3] = 0;
            s++;
            k++;
            y = y1;
        }
        tail = (u_long64 *)s;
        tail[0] = 0x2000400000008001;
        ((u_long128 *)tail)[1] = D_006F2CE0[7];
        tail[1] = 0xEE;
        ((u_long128 *)tail)[2] = D_006F2CE0[9];
        func_002F8660(0);
        func_002DA610(0, 0);
        func_002DBA28(D_003F395C, (u8 *)pkt - (u8 *)0x80000000);
        func_002DA610(0, 0);
    }
    func_002B39C0(0x1000);
}
