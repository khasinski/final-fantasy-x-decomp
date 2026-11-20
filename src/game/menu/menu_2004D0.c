/* tu_224 0x2004d0-0x200c58: low; unk_2004D0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"

void func_002004D0(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_00200520(InvokedFromSelectCursor, a, b, c, d, e);
}

INCLUDE_ASM("build/ee_asm/game/menu/menu_2004D0", func_00200520);

void func_002006E0(int id, int x, int y, int z)
{
    TOMakePktBoxXYWHRGBA(x + 4, y + 4, D_00324234, D_00324236, 0, 0, 0, 0x80);
    func_001FF398(x, y, D_00324234, D_00324236, D_0032423C, D_00324240);
    func_001F3808(id, x + 15, y + 2, z);
}

void func_00200798(int text, int x, int y, int z)
{
    s16 size[2];

    _TOGetMessageWH(0, (u8 *)text, &size[0], &size[1], 0, 0); /* DEBT(CAST): message text comes as int */
    TOMakePktBoxXYWHRGBA(x + 4, y + 4, 0x1DE - size[0], D_00324236, 0, 0, 0, 0x80);
    func_001FF398(x, y, 0x1E2 - size[0], D_00324236, D_0032423C, D_00324240);
    func_001F3808(text, x + 0xF, y + 2, z);
}

void *func_00200870(void *pkt, int x, int y, int w, int h, int pos, int page, int total)
{
    int y2;
    double dx1;
    double dx2;
    int x2;
    int ix2;
    double dy1;
    double dy2;
    double step;

    x2 = x + w;
    y2 = y + h;
    ix2 = x2 - 1;
    dx1 = x + 1;
    dy1 = y;
    dx2 = ix2;
    dy2 = y2;
    if (page >= total) {
        return pkt;
    }
    step = (dy2 - dy1) / (double)total;
    dy1 += step * (double)pos;
    dy2 = dy1 + step * (double)page;
    if (pos == 0) {
        dy1 = y;
    }
    if (pos + page >= total) {
        dy2 = y2;
    }
    pkt = func_001EFCE0(pkt, x, y, x2, y2, 0x11, 0x11, 0x11, 0x80);
    return func_001EFCE0(pkt, (int)dx1, (int)dy1, (int)dx2, (int)dy2, 0xF0, 0xF0, 0xF0, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/menu_2004D0", func_00200A58);
