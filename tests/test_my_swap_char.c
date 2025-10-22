/*
** EPITECH PROJECT, 2025
** test_my_swap.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_swap_char, swap_var_values_1)
{
    char str_obtained_1_1 = '5';
    char str_obtained_2_1 = '0';
    char str_expected_1_1 = '0';
    char str_expected_2_1 = '5';

    cr_assert_eq(str_obtained_1_1, '5');
    cr_assert_eq(str_obtained_2_1, '0');
    my_swap_char(&str_obtained_1_1, &str_obtained_2_1);
    cr_assert_eq(str_obtained_1_1, '0');
    cr_assert_eq(str_obtained_2_1, '5');
}
