#include <stdlib.h>

#include "linked_node.h"


struct linked_node
{
    l_node *next;
    void *element;
};


l_node* linked_node_create(l_node *next_node, void *element)
{
    l_node *node = malloc(sizeof(l_node));

    if (!node)
        return NULL;

    node->next = next_node;
    node->element = element;

    return node;
}


void linked_node_destroy(l_node* node)
{
    free(node);
}


l_node* linked_node_next(l_node *node)
{
    if (linked_node_hasnext(node)) {
        return node->next;
    }

    return NULL;
}


int linked_node_hasNext(l_node *node)
{
    return node->next ? 1 : 0;
}


void* linked_node_element(l_node *node)
{
    return node->element;
}


void linked_node_setElement(l_node *node, void *element)
{
    node->element = element;
}
