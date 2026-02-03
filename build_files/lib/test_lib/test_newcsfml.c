/*
** EPITECH PROJECT, 2025
** test_lib - test_newcsfml.c
** File description:
** None
*/

#include "test.h"

// test_start //
Test(test_start, test_newcsfml_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test start\n");
}

Test(newcsfml_exist, test_newcsfml_exist)
{
    newcsfml_exist();
    cr_assert(1);
}

