/*
** EPITECH PROJECT, 2025
** test_printf_basic.c
** File description:
** None
*/

#include "test.h"

Test(test_start, test_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test started");
}