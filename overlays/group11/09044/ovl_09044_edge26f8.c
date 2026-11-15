#include "p3_overlay.h"

void func_01B026F8(P3Edge *ed, float *pos)
{
    P3EdgePart *p = ed->part;
    float x = pos[0] + 2048.0f;
    float y = pos[1] + 2048.0f;
    int i;

    ed->w00 = 0;
    for (i = 0; i < 0x200; i++) {
        p->x1 = (x - 256.0f) + i;
        p->y1 = y - 208.0f;
        p->w18 = 0;
        p->u = i * (1.0f / 512);
        p->v = 0;
        p++;
    }
    for (i = 0; i < 0x1A0; i++) {
        p->x1 = x + 256.0f;
        p->y1 = (y - 208.0f) + i;
        p->w18 = 0;
        p->u = 1.0f;
        p->v = i * (1.0f / 512);
        p++;
    }
    for (i = 0x1FF; i >= 0; i--) {
        p->x1 = (x - 256.0f) + i;
        p->y1 = y + 208.0f;
        p->w18 = 0;
        p->u = i * (1.0f / 512);
        p->v = 0.8125f;
        p++;
    }
    for (i = 0x19F; i >= 0; i--) {
        p->x1 = x - 256.0f;
        p->w18 = 0;
        p->y1 = (y - 208.0f) + i;
        p++;
        p->v = i * (1.0f / 512);
        p->u = 0;
    }
    p = ed->part;
    for (i = 0; i < 0x740; i++) {
        p->x = x;
        p->y = y;
        p->w08 = 0;
        p->dx = (x - 1792.0f) * (1.0f / 512);
        p->dy = (y - 1840.0f) * (1.0f / 512);
        p->col0 = 0x80808080;
        p->col1 = 0x80808080;
        p->w40 = 0;
        p->w44 = 0;
        p->t0 = 0;
        func_002B3DF8(0.001f);
        p->dt0 = 0.01f;
        p->t1 = 0;
        p->dt1 = 0;
        p++;
    }
}
