/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_strcapitalize, capitalize_a_string_1)
{
    char str_input_1[] = "hello world\0";
    char *str_obtained_1 = my_strcapitalize(str_input_1);
    char str_expected_1[] = "Hello World\0";

    cr_assert_str_eq(str_obtained_1, str_expected_1);
}

Test(my_strcapitalize, capitalize_a_string_2)
{
    char str_input_2[] = "HELLO WORLD\0";
    char *str_obtained_2 = my_strcapitalize(str_input_2);
    char str_expected_2[] = "Hello World\0";

    cr_assert_str_eq(str_obtained_2, str_expected_2);
}

Test(my_strcapitalize, capitalize_a_string_3)
{
    char str_input_3[] = "h\0";
    char *str_obtained_3 = my_strcapitalize(str_input_3);
    char str_expected_3[] = "H\0";

    cr_assert_str_eq(str_obtained_3, str_expected_3);
}

Test(my_strcapitalize, capitalize_a_string_4)
{
    char str_input_4[] = "\0";
    char *str_obtained_4 = my_strcapitalize(str_input_4);
    char str_expected_4[] = "\0";

    cr_assert_str_eq(str_obtained_4, str_expected_4);
}

Test(my_strcapitalize, capitalize_a_string_5)
{
    char str_input_5[] = "123ABC\0";
    char *str_obtained_5 = my_strcapitalize(str_input_5);
    char str_expected_5[] = "123abc\0";

    cr_assert_str_eq(str_obtained_5, str_expected_5);
}

Test(my_strcapitalize, capitalize_a_string_6)
{
    char str_input_6[] = "123-ABC\0";
    char *str_obtained_6 = my_strcapitalize(str_input_6);
    char str_expected_6[] = "123-Abc\0";

    cr_assert_str_eq(str_obtained_6, str_expected_6);
}
