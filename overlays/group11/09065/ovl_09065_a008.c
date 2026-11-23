#include "p4_overlay.h"

void func_01B0A008(u_long64 *tex0, int alpha)
{
    u_long64 *pkt;
    P4Sprite *verts;
    P4Sprite *s;
    u_long64 *tail;
    int i;
    int j;
    int k;
    float y;
    float r;
    float dy;

    k = 0;
    pkt = func_002B3888(0x1000);
    y = 0.0f;
    verts = (P4Sprite *)(pkt + 14);
    for (i = 0; i < 26; i++) {
        pkt[0] = 0x700000A9;
        pkt[1] = 0;
        pkt[2] = 0x4000000000000001;
        pkt[3] = 0xEEEE;
        pkt[4] = *tex0;
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
        s = verts;
        for (j = 0; j < 16; j++, k++, y += dy) {
            r = func_002B3DB0(1.0f);
            dy = 1.0f / 256;
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
            s->st1[1] = y + dy;
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
            s->st1[1] = y + dy;
            s->st1[2] = 1.0f;
            s->xyz1[0] = 0x9000;
            s->xyz1[1] = (k + 1) * 16 + 0x7300;
            s->xyz1[2] = -2;
            s->xyz1[3] = 0;
            s++;
        }
        tail = (u_long64 *)s;
        tail[0] = 0x2000400000008001;
        tail[1] = 0xEE;
        ((u_long128 *)tail)[1] = D_006F2CE0[7];
        ((u_long128 *)tail)[2] = D_006F2CE0[9];
        func_002F8660(0);
        func_002DA610(0, 0);
        func_002DBA28(D_003F395C, (u8 *)pkt - (u8 *)0x80000000);
        func_002DA610(0, 0);
    }
    func_002B39C0(0x1000);
}
