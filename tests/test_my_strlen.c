/*
** EPITECH PROJECT, 2025
** test_my_strlen.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_strlen, get_str_len_1)
{
    int int_obtained_1_1 = my_strlen("Hello World!\0");
    int int_expected_1_1 = strlen("Hello World!\0");

    cr_assert_eq(int_obtained_1_1, int_expected_1_1);
}

Test(my_strlen, get_str_len_2)
{
    int int_obtained_2 = my_strlen("H\0");
    int int_expected_2 = strlen("H\0");

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_strlen, get_str_len_3)
{
    int int_obtained_3= my_strlen("\0");
    int int_expected_3 = strlen("\0");

    cr_assert_eq(int_obtained_3, int_expected_3);
}
