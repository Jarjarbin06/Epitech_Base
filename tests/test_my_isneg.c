/*
** EPITECH PROJECT, 2025
** test_my_isneg.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_isneg, check_if_negative_1)
{
    int int_obtained = my_isneg(1);
    int int_expected = 0;

    cr_assert_eq(int_obtained, int_expected);
}

Test(my_isneg, check_if_negative_2)
{
    int int_obtained = my_isneg(0);
    int int_expected = 0;

    cr_assert_eq(int_obtained, int_expected);
}

Test(my_isneg, check_if_negative_3)
{
    int int_obtained = my_isneg(-1);
    int int_expected = 0;

    cr_assert_eq(int_obtained, int_expected);
}
