#include <stdlib.h>
#include <string.h>

#include "linked_node.h"


struct linked_node
{
    l_node *next;
    void *element;
};


l_node* linked_node_create(l_node *next_node, void *element, size_t size)
{
    l_node *node = malloc(sizeof(l_node));

    if (!node)
        return NULL;

    linked_node_setElement(node, element, size);

    node->next = next_node;
    
    return node;
}


void* linked_node_destroy(l_node* node)
{
    l_node *next = linked_node_next(node);
    free(node->element);
    free(node);
    return next;
}


l_node* linked_node_next(l_node *node)
{
    if (linked_node_hasNext(node)) {
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


void linked_node_setElement(l_node *node, void *new_element, size_t size)
{
    if (node->element) free(node->element);

    node->element = malloc(size);
    memcpy(node->element, new_element, size);
}
