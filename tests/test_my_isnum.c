/*
** EPITECH PROJECT, 2025
** test_my_is_prime.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_str_isnum, check_str_is_num_1)
{
    int int_obtained_1 = my_str_isnum("12345\0");
    int int_expected_1 = 1;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_str_isnum, check_str_is_num_2)
{
    int int_obtained_2 = my_str_isnum("12 45\0");
    int int_expected_2 = 0;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_str_isnum, check_str_is_num_3)
{
    int int_obtained_3 = my_str_isnum(" \0");
    int int_expected_3 = 0;

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_str_isnum, check_str_is_num_4)
{
    int int_obtained_4 = my_str_isnum("\0");
    int int_expected_4 = 1;

    cr_assert_eq(int_obtained_4, int_expected_4);
}

Test(my_str_isnum, check_str_is_num_5)
{
    int int_obtained_5 = my_str_isnum("\n\0");
    int int_expected_5 = 0;

    cr_assert_eq(int_obtained_5, int_expected_5);
}
