#include "common.h"

typedef struct PoolNode {
    struct PoolNode *prev;
    struct PoolNode *next;
    struct PoolNode *val;
} PoolNode;

typedef struct PoolList {
    PoolNode n;
    int count;
} PoolList;

#define head n.prev
#define tail n.next
#define cur  n.val

extern PoolNode D_01B049F8[1023];
extern u16 D_01B079EC;
extern u16 D_01B079EE;

PoolNode *func_01B029D0(void);
void func_01B02A60(PoolNode *node);
PoolNode *func_01B02A78(PoolList *list, void *val);

void func_01B025D0(void)
{
    int i;
    PoolNode *p = D_01B049F8;

    for (i = 0; i < 1023; i++, p++) {
        p->val = 0;
    }
    D_01B079EE = 0;
    D_01B079EC = 1023;
}

int func_01B02618(void)
{
    return D_01B079EC;
}

void func_01B02628(PoolList *list)
{
    list->cur = 0;
    list->tail = 0;
    list->head = 0;
    list->count = 0;
}

int func_01B02640(PoolList *list, void *val)
{
    PoolNode *node = func_01B029D0();

    if (node == 0) {
        return 0;
    }
    if (list->head == 0) {
        node->next = 0;
        node->prev = 0;
        list->tail = node;
        list->head = node;
    } else {
        node->prev = 0;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    node->val = (PoolNode *)val;
    list->count++;
    return 1;
}

int func_01B026C0(PoolList *list, void *val)
{
    PoolNode *node = func_01B029D0();

    if (node == 0) {
        return 0;
    }
    if (list->tail == 0) {
        node->next = 0;
        node->prev = 0;
        list->tail = node;
        list->head = node;
    } else {
        node->prev = list->tail;
        node->next = 0;
        list->tail->next = node;
        list->tail = node;
    }
    node->val = (PoolNode *)val;
    list->count++;
    return 1;
}

int func_01B02740(PoolList *list)
{
    PoolNode *node = list->head;

    if (node == 0) {
        return 0;
    }
    list->head = node->next;
    if (list->head == 0) {
        list->tail = 0;
    } else {
        list->head->prev = 0;
    }
    if (list->cur == node) {
        list->cur = node->next;
    }
    func_01B02A60(node);
    list->count--;
    return 1;
}

int func_01B027B0(PoolList *list)
{
    PoolNode *node = list->tail;

    if (node == 0) {
        return 0;
    }
    list->tail = node->prev;
    if (list->tail == 0) {
        list->head = 0;
    } else {
        list->tail->next = 0;
    }
    if (list->cur == node) {
        list->cur = node->next;
    }
    func_01B02A60(node);
    list->count--;
    return 1;
}

int func_01B02820(PoolList *list, void *val)
{
    PoolNode *node = func_01B02A78(list, val);

    if (node == 0) {
        return 0;
    }
    if (node == list->head) {
        return func_01B02740(list);
    }
    if (node == list->tail) {
        return func_01B027B0(list);
    }
    if (list->cur == node) {
        list->cur = node->next;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    func_01B02A60(node);
    list->count--;
    return 1;
}

void func_01B028C0(PoolList *list)
{
    PoolNode *node = list->head;
    PoolNode *next;

    if (node == 0) {
        return;
    }
    for (next = node->next; next != 0; node = next, next = next->next) {
        func_01B02A60(node);
    }
    func_01B02628(list);
}

void func_01B02930(PoolList *list)
{
    if (list->cur != 0) {
        list->cur = list->cur->prev;
    }
}

void func_01B02950(PoolList *list)
{
    if (list->cur != 0) {
        list->cur = list->cur->next;
    }
}

void *func_01B02970(PoolList *list)
{
    PoolNode *node = list->head;

    if (node == 0) {
        return 0;
    }
    return node->val;
}

void *func_01B02990(PoolList *list)
{
    if (list->tail == 0) {
        return 0;
    }
    return list->tail->val;
}

void *func_01B029B0(PoolList *list)
{
    if (list->cur == 0) {
        return 0;
    }
    return list->cur->val;
}

PoolNode *func_01B029D0(void)
{
    int idx;
    PoolNode *node;

    if (D_01B079EC == 0) {
        return 0;
    }
    idx = D_01B079EE;
    while ((node = &D_01B049F8[idx])->val != 0) {
        idx = (idx + 2) % 1023;
    }
    D_01B079EC--;
    return node;
}

void func_01B02A60(PoolNode *node)
{
    node->val = 0;
    D_01B079EC++;
}

PoolNode *func_01B02A78(PoolList *list, void *val)
{
    PoolNode *node = list->head;

    while (node != 0) {
        if (node->val == (PoolNode *)val) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
