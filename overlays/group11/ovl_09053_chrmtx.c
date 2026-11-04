#include "p8_overlay.h"

typedef struct P8ChrRef {
    int mode;          /* 0x00 */
    int id;            /* 0x04 */
    int slot;          /* 0x08 */
    int chr;           /* 0x0C: character handle; DEBT(TYPE): an int (a pointer type moves the store below) */
    int w10;           /* 0x10 */
    int w14;           /* 0x14 */
    u16 h18;           /* 0x18 */
    u16 h1A;           /* 0x1A */
    u16 kind;          /* 0x1C */
} P8ChrRef;

int func_01B01598(int id);
void *func_01B01630(int id);
void func_01B02F08(int id, P8Mtx *m);
int func_01B03AD0(int slot); /* DEBT(TYPE): returns a character handle */

P8Mtx *func_00106470(void);
void func_001073C0(void *chr, int v);
void Sg_LightGetColor(int i, P8Vec *v);
void Ch_TextureSetImageBase(void *chr, int a, int b);
void Ch_TextureSetClutBase(void *chr, int a, int b);
void func_002DD5A8(P8Mtx *out, P8Vec *a, P8Vec *b, P8Vec *c, P8Vec *d);

void func_01B02FD8(int id, P8Mtx *m, float *rot)
{
    func_01B02F08(id, m);
    func_002DD1C8(m, m, rot[2]);
    func_002DD270(m, m, rot[0]);
    func_002DD318(m, m, rot[1]);
}

void func_01B03038(int id, int v)
{
    func_001073C0(func_01B01630(id), v);
}

void func_01B03068(P8Mtx *dst)
{
    func_002DD0C0(dst, func_00106470());
}

void func_01B03098(P8Mtx *out)
{
    P8Mtx m;

    Sg_LightGetColor(0, &m.r[0]);
    Sg_LightGetColor(1, &m.r[1]);
    Sg_LightGetColor(2, &m.r[2]);
    Sg_LightGetColor(3, &m.r[3]);
    func_002DD998(&m.r[0], &m.r[0], 2.0f);
    func_002DD998(&m.r[1], &m.r[1], 2.0f);
    func_002DD998(&m.r[2], &m.r[2], 2.0f);
    func_002DD998(&m.r[3], &m.r[3], 2.0f);
    func_002DD5A8(out, &m.r[0], &m.r[1], &m.r[2], &m.r[3]);
}

void func_01B03178(int id, int image, int clut)
{
    void *chr = func_01B01630(id);

    Ch_TextureSetImageBase(chr, -1, image);
    Ch_TextureSetClutBase(chr, -1, clut);
}

void func_01B031D0(int id, P8ChrRef *r, int mode)
{
    r->mode = mode;
    r->id = id;
    r->slot = func_01B01598(id);
    r->chr = func_01B03AD0(r->slot);
    r->w10 = -1;
    r->w14 = 0;
    r->h18 = 1;
    r->h1A = 0;
    if (D_01B005A0.mode == 0) {
        r->kind = 0;
    } else {
        r->kind = 1;
    }
}

void func_01B03240(int id, P8ChrRef *r, int mode)
{
    func_01B031D0(-1, r, mode);
    r->kind = 2;
    r->chr = (int)func_01B01630(id); /* DEBT(CAST) */
}
