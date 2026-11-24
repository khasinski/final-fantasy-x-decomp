typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x20];
    float f20;
    u8 pad24[0x08];
    float f2C;
    u8 pad30[0x10];
    int w40;
    int w44;
    u8 pad48[0x0C];
    int w54;
    u32 w58;
    u32 w5C;
    int active;
    u16 flags;
    u8 pad66[0x0A];
} OvlPart;

extern OvlPart *g_b5fc;
extern int g_b600;
extern int g_b604;
extern int g_b608;
extern void fn_6290(void);

extern void *func_01B03E10(void *);
extern void func_01B03FD8(void *);

void *ovl_09429_6148(OvlPart *pool, int count)
{
    int i;
    void *t;

    g_b5fc = pool;
    for (i = 0; i < count; i++, pool++) {
        pool->active = 0;
    }
    g_b600 = 0;
    g_b604 = count;
    g_b608 = 0;
    t = func_01B03E10(fn_6290);
    func_01B03FD8(t);
    return t;
}
