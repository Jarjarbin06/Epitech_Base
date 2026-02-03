/*
** EPITECH PROJECT, 2025
** test_lib - test_twodlist.c
** File description:
** None
*/

#include "test.h"

// test_start //
Test(test_start, test_twodlist_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test start\n");
}

Test(twodlist_exist, test_twodlist_exist)
{
    twodlist_exist();
    cr_assert(1);
}

