typedef struct {
    int pad[3];
    int count;
} Ovl9076Child;

typedef struct Ovl9076Node {
    struct Ovl9076Node *prev;
    struct Ovl9076Node *next;
    Ovl9076Child *child;
} Ovl9076Node;

extern void fn_ovl_3648(Ovl9076Node *n);
extern Ovl9076Node *g_ovl_head_6090;
extern Ovl9076Node *g_ovl_tail_6094;
extern Ovl9076Node *g_ovl_free_6098;
extern Ovl9076Node *g_ovl_cur_609c;
extern unsigned short g_cnt;

void ovl_09076_3480(Ovl9076Node *s0) {
    while (s0->child->count != 0) {
        fn_ovl_3648(s0);
    }
    if (s0->prev != 0) {
        s0->prev->next = s0->next;
    }
    if (s0->next != 0) {
        s0->next->prev = s0->prev;
    }
    if (g_ovl_head_6090 == s0) {
        g_ovl_head_6090 = s0->next;
    }
    if (g_ovl_tail_6094 == s0) {
        g_ovl_tail_6094 = s0->prev;
    }
    if (g_ovl_cur_609c == s0) {
        g_ovl_cur_609c = s0->next;
    }
    if (g_ovl_free_6098 != 0) {
        s0->next = g_ovl_free_6098;
        s0->prev = g_ovl_free_6098->prev;
        g_ovl_free_6098->prev = s0;
    } else {
        s0->next = s0;
        s0->prev = s0;
    }
    g_ovl_free_6098 = s0;
    g_cnt++;
    if (g_cnt == 256) {
        g_ovl_head_6090 = 0;
    }
}
