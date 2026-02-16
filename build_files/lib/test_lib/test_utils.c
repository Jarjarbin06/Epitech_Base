/*
** EPITECH PROJECT, 2025
** test_lib - test_str.c
** File description:
** None
*/

#include "test.h"

// test_start //
Test(test_start, test_utils_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test start\n");
}

#ifdef _UTILS_P_BASE
Test(utils_exist, test_utils_exist)
{
    utils_exist();
    cr_assert(1);
}
#endif

// alloc_any.c //
Test(malloc_any, test_utils_malloc_any)
{
    void *alloc_var = malloc_any(1);
    cr_assert(alloc_var);
    free(alloc_var);
}

Test(free_any, test_utils_free_any_valid)
{
    void *alloc_var = malloc_any(1);
    cr_assert(alloc_var);
    alloc_var = free_any(alloc_var);
    cr_assert(!alloc_var);
}

Test(free_any, test_utils_free_any_invalid)
{
    void *alloc_var = NULL;
    cr_assert(!alloc_var);
    alloc_var = free_any(alloc_var);
    cr_assert(!alloc_var);
}
