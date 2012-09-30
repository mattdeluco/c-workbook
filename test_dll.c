#include <assert.h>
#include <stdio.h>
#include "doubly_linked_list.h"

#define LIST_LENGTH 5

typedef int (*test_fn_t)(dll_td*, size_t);
#define TEST_FN(name) static int name(dll_td* list, size_t size)
#define TEST(title, name) test_loop(title, name)

typedef struct obj obj_td;
struct obj {
    int i;
    void* data;
};

static obj_td* objs[LIST_LENGTH];

static dll_td* create_list(size_t size)
{
    unsigned int i;
    dll_td* list = dll_create();

    for (i = 0 ; i < size ; i++) {
        objs[i] = malloc(sizeof(obj_td));
        objs[i]->i = i;
        objs[i]->data = &objs[(i+1) % size];
        dll_append(list, objs[i]);
        assert(dll_length(list) == i+1);
    }

    return list;
}

static void destroy_list(dll_td* list, int size)
{
    int i;

    dll_destroy(list);

    for (i = 0 ; i < size ; i++)
        free(objs[i]);

}

static void display_list(dll_td* list)
{
    obj_td* x;
    dll_iter_td* iter = dll_iterator(list);

    while (dll_iter_has_next(iter)) {
        x = (obj_td*) dll_iter_next(iter);
        printf("  i: %d, data: %d\n", x->i, (*(obj_td**) x->data)->i);
    }

    dll_iter_destroy(iter);
}

TEST_FN(test_empty)
{
    if (size == 0)
        assert(dll_empty(list));

    assert(dll_length(list) == size);

    printf("    length: %zu\n", dll_length(list));

    return 0;
}

TEST_FN(test_iter_next)
{
    obj_td* x;
    dll_iter_td* iter = dll_iterator(list);

    while (dll_iter_has_next(iter)) {
        x = (obj_td*) dll_iter_next(iter);
        printf("    i: %d, data: %d\n", x->i, (*(obj_td**) x->data)->i);
    }

    dll_iter_destroy(iter);

    return 0;
}

TEST_FN(test_remove)
{
    obj_td* x;
    size_t i, len = dll_length(list);

    for (i = 0 ; i < size ; i++) {
        x = dll_remove(list, objs[i]);
        assert(x == objs[i]);
        printf("    Removed objs[%zu] - i: %d, data: %d\n", i, x->i, (*(obj_td**) x->data)->i);
        x = dll_remove(list, objs[i]);
        assert(x == NULL);
        assert(dll_length(list) == --len);
    }

    return 0;
}

static int test_loop(const char* title, test_fn_t fn)
{
    size_t j;
    int result;
    dll_td* list;

    printf("\n%s\n", title);

    for (j = 0; j < LIST_LENGTH+1 ; j++) {
        printf("  Iteration: %zu, # objects: %zu\n", j+1, j);
        list = create_list(j);
        result = fn(list, j);
        destroy_list(list, j);
    }

    return 0;

}

int main()
{

    TEST("Iterator Next", test_iter_next);
    TEST("DLL Remove", test_remove);
    TEST("DLL Empty and Length", test_empty);

    return 0;
}
