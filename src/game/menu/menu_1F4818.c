/* tu_220 0x1f4818-0x1f5060: low; unk_1F4818 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"

void *func_001F4818(void *list, int x, int y, int w, int c, int d)
{
    OfsTbl *t;

    list = func_001FDDD8(list, 0xDA, x, y, 0, 0, c, c);
    t = (OfsTbl *)func_001FD6F0(0x12); /* DEBT(CAST): prototype says int */
    return func_001FDDD8(list, 0xDB, x + t->b[0].x, y, w - t->b[0].x, 0, c, d);
}

void *func_001F48C8(void *list, int x, int y, int w, int c0, int c1)
{
    TexRect *t;

    list = func_001FDDD8(list, 0xDA, x, y, 0, 0, c0, c0);
    t = TEX_RECT0(0x12);
    list = func_001FDDD8(list, 0xDB, x + t->w, y, w - t->w, 0, c0, c1);
    c0 = 0x80000000;
    return func_001FDDD8(list, 0xD7, x + 0x61, y, 0, 0, c0, c0);
}

void *func_001F4998(void *list, int x, int y, int w, int c0, int c1)
{
    TexRect *t;

    list = func_001FDDD8(list, 0xDA, x, y, 0, 0, c0, c0);
    t = TEX_RECT0(0x12);
    list = func_001FDDD8(list, 0xDB, x + t->w, y, w - t->w, 0, c0, c1);
    c0 = 0x80000000;
    return func_001FDDD8(list, 0x10B, x + 0x61, y, 0, 0, c0, c0);
}

void *func_001F4A68(void *list, int x, int y, int w, int c0, int c1)
{
    TexRect *t;

    list = func_001FDDD8(list, 0xDA, x, y, 0, 0, c0, c0);
    t = TEX_RECT0(0x12);
    list = func_001FDDD8(list, 0xDB, x + t->w, y, w - t->w, 0, c0, c1);
    c0 = 0x80000000;
    return func_001FDDD8(list, 0x10A, x + 0x61, y, 0, 0, c0, c0);
}

void func_001F4B38(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F4818(InvokedFromSelectCursor, a, b, 0xd1, c, d);
    func_001EFA30();
}

void func_001F4B80(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F48C8(InvokedFromSelectCursor, a, b, 0xd1, c, d);
    func_001EFA30();
}

void func_001F4BC8(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F4998(InvokedFromSelectCursor, a, b, 0xd1, c, d);
    func_001EFA30();
}

void func_001F4C10(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F4A68(InvokedFromSelectCursor, a, b, 0xd1, c, d);
    func_001EFA30();
}

void *func_001F4C58(void *list, int a, int b, int sel)
{
    switch (sel) {
    case 0:
        list = func_001F4818(list, a, b, 0xD1, D_003241D8, D_003241DC);
        break;
    case 1:
        list = func_001F48C8(list, a, b, 0xD1, D_003241D8, D_003241DC);
        break;
    case 2:
        list = func_001F4998(list, a, b, 0xD1, D_003241D8, D_003241DC);
        break;
    case 3:
        list = func_001F4A68(list, a, b, 0xD1, D_003241D8, D_003241DC);
        break;
    case 8:
        list = func_001F4818(list, a, b, 0xD1, D_003241E0, D_003241E4);
        break;
    case 9:
        list = func_001F48C8(list, a, b, 0xD1, D_003241E0, D_003241E4);
        break;
    case 10:
        list = func_001F4998(list, a, b, 0xD1, D_003241E0, D_003241E4);
        break;
    case 11:
        list = func_001F4A68(list, a, b, 0xD1, D_003241E0, D_003241E4);
        break;
    case 16:
        list = func_001F4818(list, a, b, 0xD1, D_003241E8, D_003241EC);
        break;
    case 17:
        list = func_001F48C8(list, a, b, 0xD1, D_003241E8, D_003241EC);
        break;
    case 18:
        list = func_001F4998(list, a, b, 0xD1, D_003241E8, D_003241EC);
        break;
    case 19:
        list = func_001F4A68(list, a, b, 0xD1, D_003241E8, D_003241EC);
        break;
    case 24:
        list = func_001F4818(list, a, b, 0xD1, D_003241F0, D_003241F4);
        break;
    case 25:
        list = func_001F48C8(list, a, b, 0xD1, D_003241F0, D_003241F4);
        break;
    case 26:
        list = func_001F4998(list, a, b, 0xD1, D_003241F0, D_003241F4);
        break;
    case 27:
        list = func_001F4A68(list, a, b, 0xD1, D_003241F0, D_003241F4);
        break;
    }
    return list;
}

void func_001F4EB0(int a, int b, int sel)
{
    switch (sel) {
    case 0:
        func_001F4B38(a, b, D_003241D8, D_003241DC);
        break;
    case 1:
        func_001F4B80(a, b, D_003241D8, D_003241DC);
        break;
    case 2:
        func_001F4BC8(a, b, D_003241D8, D_003241DC);
        break;
    case 3:
        func_001F4C10(a, b, D_003241D8, D_003241DC);
        break;
    case 8:
        func_001F4B38(a, b, D_003241E0, D_003241E4);
        break;
    case 9:
        func_001F4B80(a, b, D_003241E0, D_003241E4);
        break;
    case 10:
        func_001F4BC8(a, b, D_003241E0, D_003241E4);
        break;
    case 11:
        func_001F4C10(a, b, D_003241E0, D_003241E4);
        break;
    case 16:
        func_001F4B38(a, b, D_003241E8, D_003241EC);
        break;
    case 17:
        func_001F4B80(a, b, D_003241E8, D_003241EC);
        break;
    case 18:
        func_001F4BC8(a, b, D_003241E8, D_003241EC);
        break;
    case 19:
        func_001F4C10(a, b, D_003241E8, D_003241EC);
        break;
    case 24:
        func_001F4B38(a, b, D_003241F0, D_003241F4);
        break;
    case 25:
        func_001F4B80(a, b, D_003241F0, D_003241F4);
        break;
    case 26:
        func_001F4BC8(a, b, D_003241F0, D_003241F4);
        break;
    case 27:
        func_001F4C10(a, b, D_003241F0, D_003241F4);
        break;
    }
}
