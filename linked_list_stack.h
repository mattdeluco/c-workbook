#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include "linked_node.h"

typedef struct linked_list_stack l_stack;


/***
 * stack_create: returns a newly allocated stack
 */
l_stack* stack_create();


/***
 * stack_destroy: frees all elements within the stack and the stack itself.
 */
void stack_destroy(l_stack *stack);


/***
 * stack_size: returns the size of the stack
 */
int stack_size(l_stack *stack);


/***
 * stack_isEmpty: returns 0 if the stack contains no elements
 */
int stack_isEmpty(l_stack *stack);


/***
 * stack_top: returns the element on top of the stack
 */
void* stack_top(l_stack *stack);


/***
 * stack_pop: removes and returns the element on top of the stack
 */
void* stack_pop(l_stack *stack);


/***
 * stack_push: copies a new element on top of the stack
 */
int stack_push(l_stack *stack, void *element, size_t size);


#endif // LINKED_LIST_STACK_H
