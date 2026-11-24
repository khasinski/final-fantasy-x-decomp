typedef unsigned char u8;
typedef unsigned short u16;

typedef struct OvlNode {
    void *vtbl;
    struct OvlNode *next;
    struct OvlNode *prev;
    struct OvlNode *head;
    struct OvlNode *tail;
    struct OvlNode *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u8 pad1C[0x04];
    float m20[16];
    float m60[16];
    u8 padA0[0x10];
    float fB0;
    float fB4;
    float fB8;
    float fBC;
    u8 padC0[0x20];
    float mE0[16];
    float f120;
    float f124;
    float f128;
    void *p12C;
    float v130[4];
    void *p140;
    void *p144;
    void *p148;
    u8 b14C;
    u8 pad14D[0x03];
    float f150;
    void *p154;
} OvlNode;

typedef struct {
    OvlNode *node;
    OvlNode *parent;
    void *p08;
    void *p0C;
    void *p10;
} OvlInitArgs;

extern u8 g_data_0830[];
extern u8 g_data_0840[];
extern u8 g_data_0870[];
extern u8 g_vtbl_19b0[];

extern void func_002DD128(void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DD0B0(void *, void *);

void ovl_09526_2a90(OvlInitArgs *args)
{
    OvlNode *n;
    OvlNode *p;

    n = args->node;
    p = args->parent;
    n->b1A = 0xFF;
    n->tail = n;
    n->head = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->next = p;
        n->prev = p->tail;
        if (p->tail == p) {
            p->head = n;
        } else {
            p->tail->next = n;
        }
        p->tail = n;
        p->count++;
    }
    {
        void *p10 = args->p10;
        void *p08 = args->p08;
        void *p0C;
        n->p154 = p10;
        p0C = args->p0C;
        n->b14C = 0;
        n->fB0 = 0.0f;
        n->fB8 = 0.0f;
        n->fBC = 0.0f;
        n->f128 = 0.0f;
        n->f124 = 0.0f;
        n->f120 = 0.0f;
        n->p140 = p08;
        n->p148 = g_data_0840;
        n->p144 = p0C;
        n->p12C = g_data_0870;
        n->f150 = 1.0f;
        n->fB4 = 1.0f;
    }
    func_002DD128(n->m60);
    func_002DD0C0(n->mE0, n->m60);
    func_002DD0C0(n->m20, n->m60);
    func_002DD0B0(n->v130, g_data_0830);
    args->node->vtbl = g_vtbl_19b0;
}
