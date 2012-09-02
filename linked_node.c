#include <stdlib.h>

#include "linked_node.h"


struct linked_node
{
    l_node *next;
    void *element;
};


int linked_node_create(l_node **new_node,  l_node *next_node, void *element)
{
    l_node *node = malloc(sizeof(l_node));

    if (!node) {
        *new_node = NULL;
        return 1;
    }

    node->next = next_node;
    node->element = element;

    *new_node = node;

    return 0;
}


int linked_node_destroy(l_node* node)
{
    free(node);
    return 0;
}


int linked_node_next(l_node **node)
{
    if (linked_node_hasnext(*node)) {
        *node = (*node)->next;
    }

    *node = NULL;

    return 0;
}


int linked_node_hasnext(l_node *node)
{
    return node->next ? 1 : 0;
}


int linked_node_element(l_node *node, void **element)
{
    *element = node->element;
    return 0;
}


int linked_node_setElement(l_node *node, void *element)
{
    node->element = element;
    return 0;
}
