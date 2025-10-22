/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_getnbr, get_nbr_from_str_1)
{
    int int_obtained_1 = my_getnbr("42");
    int int_expected_1 = 42;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_getnbr, get_nbr_from_str_2)
{
    int int_obtained_2 = my_getnbr("-42");
    int int_expected_2 = -42;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_getnbr, get_nbr_from_str_3)
{
    int int_obtained_3 = my_getnbr("There are no numbers");
    int int_expected_3 = 0;

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_getnbr, get_nbr_from_str_4)
{
    int int_obtained_4 = my_getnbr("---+---+---42");
    int int_expected_4 = -42;

    cr_assert_eq(int_obtained_4, int_expected_4);
}
