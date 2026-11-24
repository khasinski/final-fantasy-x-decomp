typedef unsigned char u8;
typedef unsigned short u16;

typedef struct OvlNode OvlNode;
struct OvlNode {
    void *vtbl;
    OvlNode *p04;
    OvlNode *p08;
    OvlNode *p0C;
    OvlNode *p10;
    OvlNode *p14;
    u16 h18;
    u8 b1A;
    u8 b1B;
    u8 pad1C[4];
    u8 arr20[8][0xA0];
    void *p520;
    int w524;
    u8 *p528;
    int w52C;
    int w530;
    u8 b534;
};

typedef struct {
    OvlNode *p00;
    OvlNode *p04;
    int w08;
    int w0C;
    u8 b10;
} Ovl2eb0Args;

typedef struct {
    void *p00;
    void *p04;
    int w08;
    u8 b0C;
} Ovl4ab8Args;

extern u8 D_01B01838[];
extern u8 *func_001E53D0(int, int *);
extern u8 *func_001E55F0(int, int *);
extern void func_01B04AB8(Ovl4ab8Args *);

void ovl_09190_2eb0(Ovl2eb0Args *args)
{
    Ovl4ab8Args sub;
    OvlNode *node = args->p00;
    OvlNode *parent = args->p04;
    u8 *p;
    int i;

    node->vtbl = D_01B01838;
    node->b1A = 0xFF;
    node->p10 = node;
    node->p0C = node;
    node->p14 = parent;
    node->b1B = 0;
    if (parent != 0) {
        node->p04 = parent;
        node->p08 = parent->p10;
        if (parent->p10 == parent) {
            parent->p0C = node;
        } else {
            parent->p10->p04 = node;
        }
        parent->p10 = node;
        parent->h18++;
    }

    node->w52C = args->w0C;
    {
        int w08 = args->w08;
        node->w530 = w08;
        node->b534 = args->b10;
        p = func_001E53D0(w08, &node->w524);
    }
    node->p528 = func_001E55F0(node->w530, &node->w524);

    for (i = 0; i < node->w524; i++) {
        sub.w08 = node->p528[i];
        sub.p04 = args->p04;
        sub.b0C = 0;
        sub.p00 = (u8 *)((int)node + i * 0xA0) + 0x20;
        func_01B04AB8(&sub);
        __asm__("" : "+r"(i));
        if (*p == node->p528[i]) {
            node->p520 = (u8 *)node + (i * 0xA0 + 0x20);
        }
    }
}
