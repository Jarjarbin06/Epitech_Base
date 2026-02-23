/*
** EPITECH PROJECT, 2025
** test_lib - test_llist.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "test.h"

// test_start //
Test(test_start, test_llist_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test start\n");
}

Test(llist_exist, test_llist_exist)
{
    llist_exist();
    cr_assert(1);
}
