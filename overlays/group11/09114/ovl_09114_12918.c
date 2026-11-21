typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Node {
    void *vtbl;          /* 0 */
    struct Node *prev;   /* 4 */
    struct Node *next;   /* 8 */
    struct Node *first;  /* 12 */
    struct Node *last;   /* 16 */
    struct Node *parent; /* 20 */
    u16 nchild;          /* 24 */
    u8 f1a;              /* 26 */
    u8 f1b;              /* 27 */
    u8 pad[52];
    int f50;             /* 80 */
    int f54;             /* 84 */
    int f58;             /* 88 */
    u16 f5c;             /* 92 */
    u16 f5e;             /* 94 */
} Node;
extern u8 g_ovl_vtbl[];
void ovl_09114_12918(Node **arg) {
    Node *a0 = arg[0];
    Node *a1 = arg[1];
    a0->vtbl = g_ovl_vtbl;
    a0->f1a = 255;
    a0->last = a0;
    a0->first = a0;
    a0->parent = a1;
    a0->f1b = 0;
    if (a1 != 0) {
        a0->prev = a1;
        a0->next = a1->last;
        if (a1->last == a1) {
            a1->first = a0;
        } else {
            a1->last->prev = a0;
        }
        a1->last = a0;
        a1->nchild++;
    }
    a0->f50 = 0;
    a0->f54 = 0;
    a0->f58 = 0;
    a0->f5c = 0;
    a0->f5e = 72;
}
