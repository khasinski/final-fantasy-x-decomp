typedef unsigned short u16;
typedef struct Ovl9386Node Ovl9386Node;
struct Ovl9386Node {
    void *p00;
    Ovl9386Node *prev;
    Ovl9386Node *next;
    void *p0c;
    Ovl9386Node *head;
    Ovl9386Node *parent;
    u16 count;
};
typedef struct {
    Ovl9386Node *list;
    Ovl9386Node *node;
} Ovl9386Msg;

void ovl_09386_3fb0(Ovl9386Msg *msg) {
    Ovl9386Node *list = msg->list;
    Ovl9386Node *node = msg->node;
    node->prev = list;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    node->parent = list;
    list->count++;
}
