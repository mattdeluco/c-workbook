#include <stdlib.h>

#include "linked_node.h"
#include "linked_list_stack.h"


struct linked_list_stack
{
    int size;
    l_node *top;
};


l_stack* stack_create()
{
    l_stack *stack = malloc(sizeof(l_stack));
    stack->top = NULL;
    stack->size = 0;

    return stack;
}


void stack_destroy(l_stack *stack)
{
    l_node *node;

    while (stack->top) {
        node = stack_pop(stack);
        linked_node_destroy(node);
    }

    free(stack);
}


int stack_size(l_stack *stack)
{
    return stack->size;
}


int stack_isEmpty(l_stack *stack)
{
    return stack->size;
}


void* stack_top(l_stack *stack)
{
    l_node *node = stack->top;
    return linked_node_element(node);
}


void* stack_pop(l_stack *stack)
{
    void *element;
    l_node *node = stack->top;
    
    element = linked_node_element(node);
    
    stack->top = linked_node_next(node);
    linked_node_destroy(node);
    node = NULL;

    stack->size--;

    return element;
}


int stack_push(l_stack *stack, void *element, size_t size)
{
    l_node *node = linked_node_create(stack->top, element, size);

    stack->top = node;

    return ++stack->size;
}


