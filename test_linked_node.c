#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linked_node.h"


int main(int argc, char** argv)
{
    int i, j, *element;
    int *sample_container;
    int sample_sizes[4] = { 0, 1, 2, 5 };
    l_node *head = NULL, *list = NULL, *node = NULL;

    srand(time(NULL));

    for (i = 0; i < 4; i++) {

        sample_container = malloc(sizeof(int) * sample_sizes[i]);
        printf("sample_container: %d\n", sample_sizes[i]);

        for (j = 0; j < sample_sizes[i]; j++) {
            sample_container[j] = rand();

            list = linked_node_insert(list, sample_container + j, sizeof(*sample_container));

            assert(sample_container[j] == *(int*)linked_node_element(list));
            printf("    %d: %d\n", j, sample_container[j]);
        }

        head = list;

        printf("  List iteration:\n");
        node = head;
        while (node) {
            j--;
            element = (int*) linked_node_element(node);
            assert(sample_container[j] == *element);

            printf("    %d: %d\n", j, *element);

            node = linked_node_destroy(node);
        }

        head = NULL;
        list = NULL;
        free(sample_container);

    }

    return 0;
}


