/* tu_210 0x1e1f40-0x1e2360: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

void MsSEP3Dinit(void) {
    D_00662FF0 = 0;
    MsStructClear(D_00663000, 0x200);
}

void func_001E1F58(int mode, int a, float *pos)
{
    int kind = mode & 0xFFFFFEFF;

    switch (kind) {
    case 1:
        func_001B6790(a, pos);
        break;
    case 2:
        MsGetChrTopPos(a, pos);
        break;
    case 3:
        MsGetChrCenterPos(a, pos);
        break;
    case 4:
        MsGetChrBottomPos(a, pos);
        break;
    }
}

W5Msg *func_001E1FD0(int key) {
    W5Msg *r = 0;
    Q4Node *n;
    for (n = D_00662FF0; n != 0; n = n->next) {
        if (n->key == key) {
            r = (W5Msg *)n; /* DEBT(CAST): W5Msg only models the first 8 bytes of the node */
            break;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E1F40", MsSEP3Dregist);

int MsSEP3Dprocess(void) {
    Q4Node *node = D_00662FF0;
    Q4Node **prev = &D_00662FF0;
    int n = 0;
    int h;
    int d;
    int scale;
    int r;
    int out;

    while (node != 0) {
        if (node->b3 != 0) {
            node->b3--;
            prev = &node->next;
        } else {
            h = node->key;
            if (!SndIsSepPlay(h)) {
                node->b0 = 0;
                *prev = node->next;
            } else {
                d = node->h4;
                scale = 0x100;
                if (d != 0) {
                    if (--node->h6 > 0) {
                        scale = (node->h6 << 8) / d;
                    } else {
                        scale = 0;
                        SndSepStop(h);
                    }
                }
                func_001E1F58(node->b1, node->b2, node->pos);
                prev = &node->next;
                r = op_3d_vol_pan_get((int)node->pos, scale, &out); /* DEBT(CAST): takes the position as int */
                SndSepVolumeDirect(h, out);
                SndSepPanDirect(h, r);
            }
        }
        node = node->next;
        n++;
    }
    return n;
}

int MsSEP3DfadeOut(u32 a, int val)
{
    int r = 0;
    W5Msg *m = func_001E1FD0(a);

    if (m != 0 && m->h4 == 0) {
        m->h4 = val;
        r = 1;
        m->h6 = val;
    }
    return r;
}

int MsSEP3DfadeOutAll(int v) {
    Q4Node *n;
    int cnt = 0;
    for (n = D_00662FF0; n != 0; n = n->next) {
        if (n->h4 == 0) {
            n->h4 = v;
            n->h6 = v;
            cnt++;
        }
    }
    return cnt;
}
