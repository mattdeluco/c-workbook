#ifndef LINKED_NODE_H
#define LINKED_NODE_H

typedef struct linked_node l_node;


/***
 * linked_node_create: Allocate a new linked node with a copy of element
 * next_node: the next node to point to
 * element: the data to copy into the node
 * size: the size of element in bytes
 */
l_node* linked_node_create(l_node *next_node, void *element, size_t size);


/***
 * linked_node_destroy: Deallocate an existing linked node
 * node: a node pointer at which there is a node to deallocate
 */
void linked_node_destroy(l_node* node);


/***
 * linked_node_next: returns the given node's next node
 * node: the node whose next node is desired
 */
l_node* linked_node_next(l_node *node);


/***
 * linked_node_hasNext: indicates if a node follows this node
 * node: the node being checked for a following node
 */
int linked_node_hasNext(l_node *node);


/**
 * linked_node_element: returns the element in node
 * node: the node containing the element
 */
void* linked_node_element(l_node *node);


/***
 * linked_node_setElement: copies an element into node, destroying the previous
 *      data held in node.
 * node: the node whose element is to be set
 * element: the element whose data is to be copied into node
 * size: the size of element in bytes
 */
void linked_node_setElement(l_node *node, void *element, size_t size);

#endif // LINKED_NODE_H
