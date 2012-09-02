#ifndef LINKED_NODE_H
#define LINKED_NODE_H

typedef struct linked_node l_node;


/***
 * linked_node_create: Allocate a new linked node
 * new_node: a node pointer at which to allocate a new node
 * next_node: the next node to point to
 * element: the data the node contains
 */
l_node* linked_node_create(l_node *next_node, void *element);


/***
 * linked_node_destroy: Deallocate an existing linked node
 * node: a node pointer at which there is a node to deallocate
 */
void linked_node_destroy(l_node* node);


/***
 * linked_node_next: sets node to the next node
 * node: the node to be set
 */
l_node* linked_node_next(l_node *node);


/***
 * linked_node_hasnext: indicates if a node follows this node
 * node: the node being checked for a following node
 */
int linked_node_hasNext(l_node *node);


/**
 * linked_node_element: returns the element in node
 * node: the node containing the element
 * element: a pointer to an element pointer
 */
void* linked_node_element(l_node *node);


/***
 * linked_node_setElement: sets the element in the given node
 * node: the node whose element is to be set
 * element: the element to be set in the node
 */
void linked_node_setElement(l_node *node, void *element);

#endif // LINKED_NODE_H
