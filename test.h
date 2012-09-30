typedef int (*test_fn_t)(void*, size_t);
#define TEST_FN(name) static int name(void* obj, size_t size)
#define TEST(title, name) test_loop(title, name)

typedef int (*test_api_fn)(void*);
#define API_FN(name) static int name(void* obj)

typedef struct {
    int (*test_init)(void*);
    int (*test_start)(void*);
    int (*test_stop)(void*);
    int (*test_destroy)(void*);
} test_interface;
