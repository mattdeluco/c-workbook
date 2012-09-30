#include "test_api.h"

typedef struct {
    int i;
} misc_obj; 


misc_obj* create_misc_obj(int i)
{
    misc_obj *m = (misc_obj*) malloc(sizeof(misc_obj));
    m->i = i;
    return m;
}


void destroy_misc_obj(misc_obj* m)
{
    free(m);
}


TEST_FN(test_stack_create)
{
    l_stack* stack = stack_create();
    assert(stack->size == 0);
    assert(stack->top == NULL);
    stack_destroy(stack);
}


TEST_FN(test_stack_size)
{
    int i;
    l_stack* stack = stack_create();
    misc_obj *m;

    for (i = 0 ; i < 10 ; i++) {
        m = create_misc_obj(i);
        stack_push(stack, m, sizeof(misc_obj));
        destroy_misc_obj(m);
        assert(stack_size(stack) == i);
    }

    assert(i == 10);

    while(!stack_isEmpty(stack)) {
        stack_pop(stack);
        assert(stack_size(stack) == --i);
    }

    assert(i == 0);
    assert(stack_size(stack) == 0);

    stack_destroy(stack);
}


API_FN(lls_init)
{
    return 0;
}


API_FN(lls_destroy)
{
    return 0;
}


API_FN(lls_start)
{
    return 0;
}


API_FN(lls_stop)
{
    return 0;
}


test_interface linked_list_stack_test_interface = {
    lls_init,
    lls_destroy,
    lls_start,
    lls_stop
};


TEST_MODULE_LOAD(lls_load)
{
}
