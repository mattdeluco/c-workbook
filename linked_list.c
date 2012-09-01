#include <stdlib.h>

#include "linked_list.h"


int linked_list_create(l_list **new_list)
{
    l_list *list = malloc(sizeof(l_list));

    // Sentinel nodes
    list->first = calloc(1, sizeof(l_node));
    list->last = calloc(1, sizeof(l_node));
    list->current = NULL;

    list->count = 0;

    list->first = list->last;

    *new_list = list;

    return 0;
}


