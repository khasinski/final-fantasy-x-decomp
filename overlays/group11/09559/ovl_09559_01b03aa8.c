/* Overlay 09559: rank 69 track selector and dispatcher (0x01B03AA8..0x01B03B9C). */
#include "common.h"

typedef struct Track {
    u8 pad0[0x3C];
    int unk3C;
} Track;

typedef struct Control {
    u8 pad0[0xB0];
    Track track0;
    Track track1;
} Control;

extern char D_01B0B4D0[];
extern char D_01B0B678[];

void func_01B03BA0(Track *, void *);
void func_01B03BF0(Track *, void *);
void func_01B03C30(Track *, void *);
void func_01B03D08(Track *, void *);
void func_01B03E40(Track *, void *);
void func_01B03F70(Track *, void *);
void func_002EF240(const char *, ...);
void func_01B01768(int, const char *, int);

Track *func_01B03AA8(Control *a0, int a1) {
    return (a1 == 0) ? &a0->track0 : &a0->track1;
}

void func_01B03AB8(Track *a0, void *a1) {
    switch (a0->unk3C) {
        case 0:
            break;
        case 1:
            func_01B03BA0(a0, a1);
            break;
        case 2:
            func_01B03BF0(a0, a1);
            break;
        case 3:
            func_01B03C30(a0, a1);
            break;
        case 4:
            func_01B03D08(a0, a1);
            break;
        case 5:
            func_01B03E40(a0, a1);
            break;
        case 6:
            func_01B03F70(a0, a1);
            break;
        default:
            func_002EF240(D_01B0B678, a0->unk3C);
            func_01B01768(14, D_01B0B4D0, 0x59C);
            break;
    }
}
