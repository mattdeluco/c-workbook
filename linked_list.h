#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list l_list;
typedef struct linked_list_node l_node;

struct linked_list
{
    int count;
    l_node *first;
    l_node *last;
    l_node *current;
};

struct linked_list_node
{
    void *next;
    void *element;
};

/*
 * API:
 * create
 * destroy
 * next
 * hasNext
 * peek
 * getElement
 * setElement
 * size
 */

int linked_list_create(l_list **new_list);
/*
int linked_list_destroy(l_list** list);
int linked_list_next(l_list** list, void **element);
int linked_list_hasnext(l_list** list);
int linked_list_peek(l_list** list, void **element);
*/

#endif // LINKED_LIST_H
