#include "oef_overlay.h"

extern OefHeapMgr D_01B0CA20;
extern void **D_01B1D4D0;

void func_002B2A80(void *p, int a, int b, int c);

void func_01B043B8(OefPartObj *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B0CA20;
    _pppStartPart(o, 0x1000, D_01B1D4D0[id], 1);
    o->rotation[0] = (int)rx;
    o->rotation[1] = (int)ry;
    o->position[0] = x;
    o->rotation[2] = (int)rz;
    o->position[1] = y;
    o->position[2] = z;
    o->scale[0] = sx;
    o->scale[1] = sy;
    o->scale[2] = sz;
    o->position[3] = 1.0f;
    o->enabled = 1;
    o->flag5C = 1;
    o->scale[3] = 1.0f;
}

void func_01B044C8(OefPartObj *o)
{
    if (o->enabled != 0) {
        pppSetMatrix(o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B0CA20;
        if (_pppRunPart(o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

void func_01B04560(int cur, int start, int fin, u8 r, u8 g, u8 b)
{
    int t = cur - start;
    u8 alpha;
    unsigned long long col;
    register unsigned long long *p __asm__("$14");

    if (t > 0) {
        p = (unsigned long long *)D_006A3BCC;
        D_006A3BCC = (u8 *)p + 0x60;
        if (t >= fin) {
            alpha = 128;
        } else {
            alpha = (t << 7) / fin;
        }
        col = (((unsigned long long)alpha << 24) | (((unsigned long long)b << 16) | ((unsigned long long)g << 8))) | (unsigned long long)r;
        ((unsigned long long *)p)[2] = 0x4023400000008001ULL;
        ((unsigned long long *)p)[3] = 21998;
        ((unsigned long long *)p)[4] = 0x44;
        ((unsigned long long *)p)[5] = 0x42;
        ((unsigned long long *)p)[6] = col;
        ((unsigned long long *)p)[7] = 1;
        ((int *)p)[16] = 0x7000;
        ((int *)p)[17] = 0x7300;
        ((int *)p)[20] = 0x9000;
        ((int *)p)[21] = 0x8d00;
        ((int *)p)[18] = 0xffff00;
        ((int *)p)[22] = 0xffff00;
        ((int *)p)[19] = 0;
        ((int *)p)[23] = 0;
        func_002B2A80(p, 6, 1, 0);
    }
}

void func_01B04650(int cur, int start, int fin, int fout, u8 r, u8 g, u8 b, int prio)
{
    int t = cur - start;
    register int total __asm__("$8");
    u8 alpha;
    register int pr __asm__("$24") = prio;
    register int rr __asm__("$11") = r;
    unsigned long long col;
    register unsigned long long *p __asm__("$15");

    if (t > 0) {
        total = fin + fout;
        if (t < total) {
            p = (unsigned long long *)D_006A3BCC;
            D_006A3BCC = (u8 *)p + 0x60;
            if (t <= fin) {
                alpha = (t << 7) / fin;
            } else {
                t = total - t;
                alpha = (t << 7) / fout;
            }
            col = (((unsigned long long)alpha << 24) | (((unsigned long long)b << 16) | ((unsigned long long)g << 8))) | (unsigned long long)rr;
            ((unsigned long long *)p)[2] = 0x4023400000008001ULL;
            ((unsigned long long *)p)[3] = 21998;
            ((unsigned long long *)p)[4] = pr;
            ((unsigned long long *)p)[5] = 66;
            ((unsigned long long *)p)[6] = col;
            ((unsigned long long *)p)[7] = 1;
            ((int *)p)[16] = 0x7000;
            ((int *)p)[17] = 0x7300;
            ((int *)p)[20] = 0x9000;
            ((int *)p)[21] = 0x8d00;
            ((int *)p)[18] = 0xffff00;
            ((int *)p)[22] = 0xffff00;
            ((int *)p)[19] = 0;
            ((int *)p)[23] = 0;
            func_002B2A80(p, 6, 1, 0);
        }
    }
}
