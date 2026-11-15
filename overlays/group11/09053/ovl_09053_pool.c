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

extern PoolNode D_01B07B28[1023];
extern u16 D_01B0AB1C;
extern u16 D_01B0AB1E;

PoolNode *func_01B04AF8(void);
void func_01B04BA8(PoolNode *node);
PoolNode *func_01B04BC0(PoolList *list, void *val);

void func_01B046F8(void)
{
    int i;
    PoolNode *p = D_01B07B28;

    for (i = 0; i < 1023; i++, p++) {
        p->val = 0;
    }
    D_01B0AB1E = 0;
    D_01B0AB1C = 1023;
}

int func_01B04740(void)
{
    return D_01B0AB1C;
}

void func_01B04750(PoolList *list)
{
    list->cur = 0;
    list->tail = 0;
    list->head = 0;
    list->count = 0;
}

int func_01B04768(PoolList *list, void *val)
{
    PoolNode *node = func_01B04AF8();

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

int func_01B047E8(PoolList *list, void *val)
{
    PoolNode *node = func_01B04AF8();

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

int func_01B04868(PoolList *list)
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
    func_01B04BA8(node);
    list->count--;
    return 1;
}

int func_01B048D8(PoolList *list)
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
    func_01B04BA8(node);
    list->count--;
    return 1;
}

int func_01B04948(PoolList *list, void *val)
{
    PoolNode *node = func_01B04BC0(list, val);

    if (node == 0) {
        return 0;
    }
    if (node == list->head) {
        return func_01B04868(list);
    }
    if (node == list->tail) {
        return func_01B048D8(list);
    }
    if (list->cur == node) {
        list->cur = node->next;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    func_01B04BA8(node);
    list->count--;
    return 1;
}

void func_01B049E8(PoolList *list)
{
    PoolNode *node = list->head;
    PoolNode *next;

    if (node == 0) {
        return;
    }
    for (next = node->next; next != 0; node = next, next = next->next) {
        func_01B04BA8(node);
    }
    func_01B04750(list);
}

void func_01B04A58(PoolList *list)
{
    if (list->cur != 0) {
        list->cur = list->cur->prev;
    }
}

void func_01B04A78(PoolList *list)
{
    if (list->cur != 0) {
        list->cur = list->cur->next;
    }
}

void *func_01B04A98(PoolList *list)
{
    PoolNode *node = list->head;

    if (node == 0) {
        return 0;
    }
    return node->val;
}

void *func_01B04AB8(PoolList *list)
{
    if (list->tail == 0) {
        return 0;
    }
    return list->tail->val;
}

void *func_01B04AD8(PoolList *list)
{
    if (list->cur == 0) {
        return 0;
    }
    return list->cur->val;
}

PoolNode *func_01B04AF8(void)
{
    int idx;
    PoolNode *node;

    if (D_01B0AB1C == 0) {
        return 0;
    }
    idx = D_01B0AB1E;
    while ((node = &D_01B07B28[idx])->val != 0) {
        idx = (idx + 2) % 1023;
    }
    D_01B0AB1E = (D_01B0AB1E + 1) % 1023;
    D_01B0AB1C--;
    return node;
}

void func_01B04BA8(PoolNode *node)
{
    node->val = 0;
    D_01B0AB1C++;
}

PoolNode *func_01B04BC0(PoolList *list, void *val)
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
