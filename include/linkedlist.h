#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

/* LinkedList structure */
typedef struct LinkedList {
    struct LinkedList *next;
    void *data[0];
} linkedlist_t;

typedef void (*linkedlist_callback)(void *);

void *_linkedlist_add(void *head, size_t size);
void *linkedlist_next(void *head);
void *linkedlist_remove(void *head);
void linkedlist_free(void *head);
void linkedlist_traverse(void *head, linkedlist_callback cb);

#define linkedlist_add(_l) _linkedlist_add(_l, sizeof(*_l))

#endif /* __LINKEDLIST_H__ */
