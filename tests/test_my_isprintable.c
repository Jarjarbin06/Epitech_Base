/*
** EPITECH PROJECT, 2025
** test_my_is_prime.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_str_isprintable, check_str_is_printable_1)
{
    int int_obtained_1 = my_str_isprintable("ABC\0");
    int int_expected_1 = 1;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_str_isprintable, check_str_is_printable_2)
{
    int int_obtained_2 = my_str_isprintable("abc\n\0");
    int int_expected_2 = 0;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_str_isprintable, check_str_is_printable_3)
{
    int int_obtained_3 = my_str_isprintable("AbC \0");
    int int_expected_3 = 1;

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_str_isprintable, check_str_is_printable_4)
{
    int int_obtained_4 = my_str_isprintable("ABC-123\0");
    int int_expected_4 = 1;

    cr_assert_eq(int_obtained_4, int_expected_4);
}

Test(my_str_isprintable, check_str_is_printable_5)
{
    int int_obtained_5 = my_str_isprintable("\0");
    int int_expected_5 = 1;

    cr_assert_eq(int_obtained_5, int_expected_5);
}

Test(my_str_isprintable, check_str_is_printable_6)
{
    int int_obtained_6 = my_str_isprintable("\n\0");
    int int_expected_6 = 0;

    cr_assert_eq(int_obtained_6, int_expected_6);
}
