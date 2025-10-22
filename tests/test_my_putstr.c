/*
** EPITECH PROJECT, 2025
** test_my_putstr.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_putstr, put_str_1)
{
    int int_obtained_1 = my_putstr("Hello World!");
    int int_expected_1 = 0;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_putstr, put_str_2)
{
    int int_obtained_2 = my_putstr(" ");
    int int_expected_2 = 0;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_putstr, put_str_3)
{
    int int_obtained_3 = my_putstr("");
    int int_expected_3 = 0;

    cr_assert_eq(int_obtained_3, int_expected_3);
}
