/* tu_230 0x208448-0x209460: low; ~TOInitWindowCallBack (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"
#include "ffx/t4.h"
#include "ffx/v4.h"

s32 func_00208448(void)
{
    return D_003241C0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_208448", func_00208458);

/* Menu/window slide animation callbacks (UiWidget). Module guess: meswin.c-like (string "meswin.c" exists in the ELF). */

void TOInitWindowCallBack(MenuSlot *s)
{
    s->fn[0] = D_00323710[s->w04][0];
    s->fn[1] = D_00323710[s->w04][1];
    s->fn[2] = D_00323710[s->w04][2];
    s->fn[3] = D_00323710[s->w04][3];
    s->fn[4] = D_00323710[s->w04][4];
    s->fn[6] = D_00323710[s->w04][5];
}

int func_002085E8(void)
{
    return 0;
}

int func_002085F0(UiWidget *w)
{
    w->f06 = 0;
    w->cur[0] = w->target[0];
    w->cur[1] = w->target[1];
    w->cur[2] = w->target[0];
    w->cur[3] = w->target[3];
    return 0;
}

int func_00208618(UiWidget *w)
{
    w->f06 += 0x2AA;
    if (w->f06 >= 0x1000) {
        w->f06 = 0x1000;
    }
    w->cur[2] = w->target[0] + w->f06 * w->scale / 4096;
    if (w->cur[2] >= w->target[2]) {
        w->phase = 2;
        w->result = (s32)func_002086A8; /* DEBT(CAST): result holds the next callback */
        return 1;
    }
    return 0;
}

int func_002086A8(void)
{
    return 0;
}

int func_002086B0(UiWidget *w)
{
    w->f06 -= 0x2AA;
    if (w->f06 <= 0) {
        w->f06 = 0;
    }
    w->cur[2] = w->target[0] + w->f06 * w->scale / 4096;
    if (w->cur[2] <= w->target[0]) {
        w->phase = 4;
        w->result = (s32)func_00208730; /* DEBT(CAST): result holds the next callback */
        return 1;
    }
    return 0;
}

s32 func_00208730(MenuSlot *s)
{
    s->w00 = 0;
    s->state = 0;
    s->fn[5] = func_002085E8;
    return 1;
}

int func_00208750(UiWidget *w)
{
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001FA548(w->cur[0], w->cur[1], w->cur[2] - w->cur[0], w->cur[3] - w->cur[1]);
    func_001F1D60(w->cur[0] + 12, w->cur[1] + 4, w->cur[2] - 12, w->cur[3] - 4);
    return 0;
}

int func_002087C8(UiWidget *w)
{
    w->cur[0] = w->target[0];
    w->cur[1] = w->target[1];
    w->cur[2] = w->target[2];
    w->cur[3] = w->target[3];
    w->timer = 0;
    w->duration = 0;
    return 0;
}

int func_002087F8(UiWidget *w)
{
    w->phase = 2;
    w->result = w->onOpen;
    return 1;
}

int func_00208810(void)
{
    return 0;
}

int func_00208818(UiWidget *w)
{
    if (--w->timer <= 0) {
        w->phase = 4;
        w->result = w->onClose;
        return 1;
    }
    return 0;
}

s32 func_00208850(MenuSlot *s)
{
    s->w00 = 0;
    s->fn[5] = func_002085E8;
    return 1;
}

int func_00208868(UiWidget *w)
{
    s16 v[12]; /* DEBT(PADDING): original local is a larger struct, rect sits at +4 */

    v[2] = w->cur[0];
    v[3] = w->cur[1];
    v[4] = w->cur[2];
    v[5] = w->cur[3];
    TOMakePktScissor(v[2], v[3], v[4], v[5]);
    return 0;
}

int func_002088C8(UiWidget *w)
{
    w->target[3] += w->target[1];
    w->start[3] = 0;
    w->start[1] = 0;
    w->start[0] = w->target[0];
    w->start[2] = w->target[2];
    w->cur[0] = w->target[0];
    w->cur[1] = 0;
    w->cur[2] = w->target[2];
    w->cur[3] = 0;
    w->duration = w->timer = 6;
    w->stepY = (w->target[3] - w->target[1]) / w->duration;
    return 0;
}

int func_00208940(UiWidget *w)
{
    w->target[1] = 0;
    w->target[3] = 0x19F;
    w->start[3] = 0;
    w->start[1] = 0;
    w->start[0] = w->target[0];
    w->start[2] = w->target[2];
    w->cur[0] = w->target[0];
    w->cur[1] = 0;
    w->cur[2] = w->target[2];
    w->cur[3] = 0;
    w->duration = w->timer = 6;
    w->stepY = (w->target[3] - w->target[1]) / w->duration;
    return 0;
}

int func_002089A8(UiWidget *w)
{
    w->cur[3] += w->stepY;
    if (--w->timer <= 0) {
        w->timer = w->duration;
        w->phase = 2;
        w->result = w->onOpen;
        return 1;
    }
    return 0;
}

int func_002089F8(void)
{
    return 0;
}

int func_00208A00(UiWidget *w)
{
    w->cur[3] -= w->stepY;
    if (--w->timer <= 0) {
        w->phase = 4;
        w->result = w->onClose;
        return 1;
    }
    return 0;
}

s32 func_00208A48(MenuSlot *s)
{
    s->w00 = 0;
    s->fn[5] = func_002085E8;
    return 1;
}

int func_00208A60(UiWidget *w)
{
    UiFrame f;

    f.box.x0 = w->cur[0];
    f.box.y0 = w->cur[1];
    f.box.x1 = w->cur[2];
    f.box.y1 = w->cur[3];
    f.col = *(UiRgba *)w->col; /* DEBT(CAST): UiWidget keeps the colour as an array */
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001FA548(f.box.x0, f.box.y0, f.box.x1 - f.box.x0, f.box.y1 - f.box.y0);
    func_001F1D60(f.box.x0 + 12, f.box.y0 + 4, f.box.x1 - 12, f.box.y1 - 4);
    return 0;
}

int func_00208B40(UiWidget *w)
{
    w->target[1] += w->target[3] - 0x19F;
    w->start[3] = 0x19F;
    w->start[1] = 0x19F;
    w->start[0] = w->target[0];
    w->start[2] = w->target[2];
    w->cur[0] = w->target[0];
    w->cur[1] = 0x19F;
    w->cur[2] = w->target[2];
    w->cur[3] = 0x19F;
    w->duration = w->timer = 6;
    w->stepY = (w->target[3] - w->target[1]) / w->duration;
    return 0;
}

int func_00208BC0(UiWidget *w)
{
    w->target[3] = 0x19F;
    w->target[1] = 0;
    w->start[3] = 0x19F;
    w->start[1] = 0x19F;
    w->start[0] = w->target[0];
    w->start[2] = w->target[2];
    w->cur[0] = w->target[0];
    w->cur[1] = 0x19F;
    w->cur[2] = w->target[2];
    w->cur[3] = 0x19F;
    w->duration = w->timer = 6;
    w->stepY = (w->target[3] - w->target[1]) / w->duration;
    return 0;
}

int func_00208C28(UiWidget *w)
{
    w->cur[1] -= w->stepY;
    if (--w->timer <= 0) {
        w->timer = w->duration;
        w->phase = 2;
        w->result = w->onOpen;
        return 1;
    }
    return 0;
}

int func_00208C78(void)
{
    return 0;
}

int func_00208C80(UiWidget *w)
{
    w->cur[1] += w->stepY;
    if (--w->timer <= 0) {
        w->phase = 4;
        w->result = w->onClose;
        return 1;
    }
    return 0;
}

s32 func_00208CC8(MenuSlot *s)
{
    s->w00 = 0;
    s->fn[5] = func_002085E8;
    return 1;
}

int func_00208CE0(UiWidget *w)
{
    UiFrame f;

    f.box.x0 = w->cur[0];
    f.box.y0 = w->cur[1];
    f.box.x1 = w->cur[2];
    f.box.y1 = w->cur[3];
    f.col = *(UiRgba *)w->col; /* DEBT(CAST): UiWidget keeps the colour as an array */
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001FA548(f.box.x0, f.box.y0, f.box.x1 - f.box.x0, f.box.y1 - f.box.y0);
    func_001F1D60(f.box.x0 + 12, f.box.y0 + 4, f.box.x1 - 12, f.box.y1 - 4);
    return 0;
}

int func_00208DC0(UiWidget *w)
{
    w->target[2] += w->target[0];
    w->start[2] = 0;
    w->start[0] = 0;
    w->start[1] = w->target[1];
    w->start[3] = w->target[3];
    w->cur[0] = 0;
    w->cur[1] = w->target[1];
    w->cur[2] = 0;
    w->cur[3] = w->target[3];
    w->duration = w->timer = 6;
    w->stepX = (w->target[2] - w->target[0]) / w->duration;
    return 0;
}

int func_00208E38(UiWidget *w)
{
    w->target[0] = 0;
    w->target[2] = 0x1FF;
    w->start[2] = 0;
    w->start[0] = 0;
    w->start[1] = w->target[1];
    w->start[3] = w->target[3];
    w->cur[0] = 0;
    w->cur[1] = w->target[1];
    w->cur[2] = 0;
    w->cur[3] = w->target[3];
    w->duration = w->timer = 6;
    w->stepX = (w->target[2] - w->target[0]) / w->duration;
    return 0;
}

int func_00208EA0(UiWidget *w)
{
    w->cur[2] += w->stepX;
    if (--w->timer <= 0) {
        w->timer = w->duration;
        w->phase = 2;
        w->result = w->onOpen;
        return 1;
    }
    return 0;
}

int func_00208EF0(void)
{
    return 0;
}

int func_00208EF8(UiWidget *w)
{
    w->cur[2] -= w->stepX;
    if (--w->timer <= 0) {
        w->phase = 4;
        w->result = w->onClose;
        return 1;
    }
    return 0;
}

s32 func_00208F40(MenuSlot *s)
{
    s->w00 = 0;
    s->fn[5] = func_002085E8;
    return 1;
}

int func_00208F58(UiWidget *w)
{
    UiFrame f;

    f.box.x0 = w->cur[0];
    f.box.y0 = w->cur[1];
    f.box.x1 = w->cur[2];
    f.box.y1 = w->cur[3];
    f.col = *(UiRgba *)w->col; /* DEBT(CAST): UiWidget keeps the colour as an array */
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001FA548(f.box.x0, f.box.y0, f.box.x1 - f.box.x0, f.box.y1 - f.box.y0);
    func_001F1D60(f.box.x0 + 12, f.box.y0 + 4, f.box.x1 - 12, f.box.y1 - 4);
    return 0;
}

int func_00209038(UiWidget *w)
{
    w->target[0] += w->target[2] - 0x1FF;
    w->start[2] = 0x1FF;
    w->start[0] = 0x1FF;
    w->start[1] = w->target[1];
    w->start[3] = w->target[3];
    w->cur[0] = 0x1FF;
    w->cur[1] = w->target[1];
    w->cur[2] = 0x1FF;
    w->cur[3] = w->target[3];
    w->duration = w->timer = 6;
    w->stepX = (w->target[2] - w->target[0]) / w->duration;
    return 0;
}

int func_002090B8(UiWidget *w)
{
    w->target[2] = 0x1FF;
    w->target[0] = 0;
    w->start[2] = 0x1FF;
    w->start[0] = 0x1FF;
    w->start[1] = w->target[1];
    w->start[3] = w->target[3];
    w->cur[0] = 0x1FF;
    w->cur[1] = w->target[1];
    w->cur[2] = 0x1FF;
    w->cur[3] = w->target[3];
    w->duration = w->timer = 6;
    w->stepX = (w->target[2] - w->target[0]) / w->duration;
    return 0;
}

int func_00209120(UiWidget *w)
{
    w->cur[0] -= w->stepX;
    if (--w->timer <= 0) {
        w->timer = w->duration;
        w->phase = 2;
        w->result = w->onOpen;
        return 1;
    }
    return 0;
}

int func_00209170(void)
{
    return 0;
}

int func_00209178(UiWidget *w)
{
    w->cur[0] += w->stepX;
    if (--w->timer <= 0) {
        w->phase = 4;
        w->result = w->onClose;
        return 1;
    }
    return 0;
}

s32 func_002091C0(MenuSlot *s)
{
    s->w00 = 0;
    s->fn[5] = func_002085E8;
    return 1;
}

int func_002091D8(UiWidget *w)
{
    UiFrame f;

    f.box.x0 = w->cur[0];
    f.box.y0 = w->cur[1];
    f.box.x1 = w->cur[2];
    f.box.y1 = w->cur[3];
    f.col = *(UiRgba *)w->col; /* DEBT(CAST): UiWidget keeps the colour as an array */
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    func_001FA548(f.box.x0, f.box.y0, f.box.x1 - f.box.x0, f.box.y1 - f.box.y0);
    func_001F1D60(f.box.x0 + 12, f.box.y0 + 4, f.box.x1 - 12, f.box.y1 - 4);
    return 0;
}

int func_002092B8(UiWidget *w)
{
    w->cur[1] = 8;
    w->cur[2] = 0x1FF;
    w->cur[3] = 0x1C;
    w->cur[0] = 0;
    w->col[0] = 0x80;
    w->col[1] = 0x80;
    w->col[2] = 0x80;
    w->col[3] = 0x80;
    return 0;
}

s32 func_002092F0(MenuSlot *s)
{
    s->state = 2;
    s->fn[5] = func_002086A8;
    return 1;
}

int func_00209310(void)
{
    return 0;
}

s32 func_00209318(MenuSlot *s)
{
    s->state = 4;
    s->fn[5] = func_00208730;
    return 1;
}

s32 func_00209338(MenuSlot *s)
{
    s->w00 = 0;
    s->state = 0;
    s->fn[5] = func_002085E8;
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_208448", _TODrawWindowHelp);

void *func_00209450(void)
{
    return &D_00570358;
}
