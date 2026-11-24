typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x10];
    void *p10;
} OvlSubTask;

typedef struct {
    u8 pad00[0x08];
    OvlSubTask *p08;
    u8 pad0C[0x08];
    int w14;
} OvlTask;

typedef struct {
    u8 pad00[0x04];
    int count;
} OvlHdr;

typedef struct {
    u8 pad00[0xB0];
    u16 hB0;
    u8 padB2[0x0E];
} OvlEntryC0;

typedef struct {
    u8 pad00[0xA0];
    int wA0;
    int wA4;
} OvlArg;

typedef struct {
    u8 pad00[0x10];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    u8 pad34[0x04];
    int w38;
    int w3C;
    int w40;
    u8 pad44[0x03];
    u8 b47;
    u8 pad48[0x03];
    u8 b4B;
} OvlPart;

extern OvlHdr g_04d8;
extern OvlEntryC0 g_6a40[];
extern u8 g_6a18[];
extern int g_7f84;
extern u8 g_7ba8[];
extern void fn_08e0(void);

extern int func_01B03278(void *);
extern int func_01B041D8(void *, int);
extern OvlPart *func_01B05BC8(void);
extern void func_001B6790(int, void *);
extern void **func_01B04688(void *, int);
extern void func_01B054C0(void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);

void ovl_09294_0c78(OvlTask *task)
{
    int ok;
    int i;
    int r0;
    int r1;

    ok = 1;
    for (i = 0; i < g_04d8.count + 1; i++) {
        if (!(((OvlEntryC0 *)(i * sizeof(OvlEntryC0) + (u8 *)g_6a40))->hB0 & 0x8000)) {
            ok = 0;
            break;
        }
    }
    r0 = func_01B03278(g_6a18);
    r1 = func_01B041D8(g_7ba8, g_7f84);
    if (r1 == 1 && ok == 1 && r0 == 1) {
        OvlSubTask *sub = task->p08;
        *(volatile int *)&task->w14 = 3;
        *(void * volatile *)&sub->p10 = (void *)fn_08e0;
    }
}

void ovl_09294_0da0(OvlArg *arg)
{
    float pos[4];
    OvlPart *p;

    if (arg->wA4 & 1) {
        return;
    }
    p = func_01B05BC8();
    if (p == 0) {
        return;
    }
    func_001B6790(arg->wA0, pos);
    func_01B054C0(p, *func_01B04688(g_7ba8, 3));
    p->f10 = pos[0];
    p->f14 = pos[1] - 4.0f;
    p->f18 = pos[2];
    p->f1C = 1.0f;
    p->f20 = 0.0f;
    p->f28 = 0.0f;
    p->f24 = -0.2f;
    p->f2C = func_002B3DB0(3.1415927f);
    p->f30 = (func_002B3DF8(0.4f) + 1.0f) * 0.3f;
    p->w38 = 16;
    p->w3C = 8;
    p->w40 = -8;
    p->b47 = 64;
    p->b4B = 0;
}
