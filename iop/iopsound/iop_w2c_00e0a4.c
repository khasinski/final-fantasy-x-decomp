typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern void imp_libsd_5(u16, u16);

typedef struct {
    u8 pad00[0x14];
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[0x50 - 0x28];
    s32 f50;
    u8 pad54[0x5C - 0x54];
    s32 f5C;
    u8 pad60[0x70 - 0x60];
} StreamCh;

extern StreamCh *D_018754;
extern s32 D_018714;
extern s16 D_018E70;
extern s16 D_018D70[256];

void func_00E0A4(StreamCh *s) {
    s32 vol = 128;
    s32 v;
    u16 l;

    if (s->f1C == 0) {
        return;
    }
    v = (s != D_018754);
    v |= (s->f24 << 1);
    if (s->f14 != 0) {
        vol = s->f14;
    }
    vol *= (s->f50 >> 12);
    vol >>= 7;
    if (D_018714 & 4) {
        l = (u32)(vol * D_018E70) >> 8;
        imp_libsd_5(v, l);
        imp_libsd_5(v | 0x100, l);
        v += 2;
        imp_libsd_5(v, l);
        imp_libsd_5(v | 0x100, l);
    } else if (s->f18 & 1) {
        imp_libsd_5(v, vol);
        imp_libsd_5(v | 0x100, 0);
        v += 2;
        imp_libsd_5(v, 0);
        imp_libsd_5(v | 0x100, vol);
    } else {
        u32 pan = (s->f5C >> 12) & 0xff;
        u16 r;
        l = (u32)(vol * D_018D70[pan]) >> 8;
        r = (u32)(vol * D_018D70[pan ^ 0xff]) >> 8;
        imp_libsd_5(v, l);
        imp_libsd_5(v | 0x100, r);
        v += 2;
        imp_libsd_5(v, l);
        imp_libsd_5(v | 0x100, r);
    }
}
