/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"
#include "../include/my_macro_abs.h"

Test(my_macro_abs, get_absolute_nbr_1)
{
    int int_obtained_1 = my_macro_abs(1);
    int int_expected_1 = 1;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_macro_abs, get_absolute_nbr_2)
{
    int int_obtained_2 = my_macro_abs(0);
    int int_expected_2 = 0;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_macro_abs, get_absolute_nbr_3)
{
    int int_obtained_3 = my_macro_abs(-1);
    int int_expected_3 = 1;

    cr_assert_eq(int_obtained_3, int_expected_3);
}
