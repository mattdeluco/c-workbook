#ifndef TEST_API_H
#define TEST_API_H

typedef int (*test_fn)(void*, size_t);
#define TEST_FN(name) static int name(void* obj, size_t size)
#define TEST(test_fn_str, test_fn) test_loop(test_fn_str, test_fn)

typedef int (*test_api_fn)(void*);
#define API_FN(name) static int name(void* obj)

typedef struct {
    int (*test_init)(void*);
    int (*test_start)(void*);
    int (*test_stop)(void*);
    int (*test_destroy)(void*);
} test_interface;

#define TEST_MODULE_LOAD(name) int name(test_interface** module_interface)
#define TEST_MODULE_LOAD_FUNCTION(name) int load_module(TEST_MODULE_LOAD(name))

#endif // TEST_API_H
