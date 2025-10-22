/*
** EPITECH PROJECT, 2025
** test_my_swap.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_swap, swap_var_values_1)
{
    int int_obtained_1_1 = 5;
    int int_obtained_2_1 = 0;
    int int_expected_1_1 = 0;
    int int_expected_2_1 = 5;

    cr_assert_eq(int_obtained_1_1, 5);
    cr_assert_eq(int_obtained_2_1, 0);
    my_swap(&int_obtained_1_1, &int_obtained_2_1);
    cr_assert_eq(int_obtained_1_1, 0);
    cr_assert_eq(int_obtained_2_1, 5);
}

Test(my_swap, swap_var_values_2)
{
    int int_obtained_1_2 = 5;
    int int_obtained_2_2 = 0;
    int int_expected_1_2 = 0;
    int int_expected_2_2 = 5;

    cr_assert_eq(int_obtained_1_2, 5);
    cr_assert_eq(int_obtained_2_2, 0);
    my_swap(&int_obtained_1_2, &int_obtained_2_2);
    cr_assert_eq(int_obtained_1_2, 0);
    cr_assert_eq(int_obtained_2_2, 5);
}

Test(my_swap, swap_var_values_3)
{
    int int_obtained_1_3 = -1;
    int int_obtained_2_3 = 1;
    int int_expected_1_3 = 1;
    int int_expected_2_3 = -1;

    cr_assert_eq(int_obtained_1_3, -1);
    cr_assert_eq(int_obtained_2_3, 1);
    my_swap(&int_obtained_1_3, &int_obtained_2_3);
    cr_assert_eq(int_obtained_1_3, 1);
    cr_assert_eq(int_obtained_2_3, -1);
}
