#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "linkedlist.h"

void *_linkedlist_add(void *head, size_t size)
{
    linkedlist_t *new = (linkedlist_t *)malloc(sizeof(linkedlist_t) + size);

    if (new == NULL) {
        fprintf(stderr, "LL malloc failed");
        exit(-1);
    }

    new->next = head;

    return &new->data;
}

void *linkedlist_next(void *head)
{
    linkedlist_t *list;

    if (head == NULL) {
        return NULL;
    }

    list = (linkedlist_t *)head;
    return list[-1].next;
}

void *linkedlist_remove(void *head)
{
    linkedlist_t *list, *n;
    void *ret;

    if (head == NULL) {
        return NULL;
    }

    list = (linkedlist_t *)head;
    n = &list[-1];
    ret = n->next;
    free(n);

    return ret;
}

void linkedlist_free(void *head)
{
    linkedlist_t *list, *n;

    if (head == NULL) {
        return;
    }

    list = (linkedlist_t *)head;
    do {
        n = &list[-1];
        list = n->next;
        free(n);
    } while (list != NULL);
}

void linkedlist_traverse(void *head, linkedlist_callback cb)
{
    linkedlist_t *tmp;
    linkedlist_t *cur = (linkedlist_t *)head;

    while (cur != NULL) {
        tmp = cur;
        cur = linkedlist_next(cur);
        cb(tmp);
    }
}
