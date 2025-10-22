/*
** EPITECH PROJECT, 2025
** test_my_is_prime.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_str_isalpha, check_str_is_alpha_1)
{
    int int_obtained_1 = my_str_isalpha("Hello\0");
    int int_expected_1 = 1;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_str_isalpha, check_str_is_alpha_2)
{
    int int_obtained_2 = my_str_isalpha("Hello World\0");
    int int_expected_2 = 0;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_str_isalpha, check_str_is_alpha_3)
{
    int int_obtained_3 = my_str_isalpha(" \0");
    int int_expected_3 = 0;

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_str_isalpha, check_str_is_alpha_4)
{
    int int_obtained_4 = my_str_isalpha("\0");
    int int_expected_4 = 1;

    cr_assert_eq(int_obtained_4, int_expected_4);
}

Test(my_str_isalpha, check_str_is_alpha_5)
{
    int int_obtained_5 = my_str_isalpha("\n\0");
    int int_expected_5 = 0;

    cr_assert_eq(int_obtained_5, int_expected_5);
}
