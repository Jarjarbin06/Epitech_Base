/*
** EPITECH PROJECT, 2025
** test_my_strncat.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_strncat, concatenate_two_string_1)
{
    char *str_input_1_1 = strdup("Hello\0     \0");
    char *str_input_2_1 = strdup("Hello\0     \0");
    char const *str_input_3_1 = " World\0";
    char *str_obtained_1 = my_strncat(str_input_1_1, str_input_3_1, 6);
    char *str_expected_1 = strncat(str_input_2_1, str_input_3_1, 6);

    cr_assert_str_eq(str_obtained_1, str_expected_1);
}

Test(my_strncat, concatenate_two_string_2)
{
    char *str_input_1_2 = strdup("Hello\0\0");
    char *str_input_2_2 = strdup("Hello\0\0");
    char const *str_input_3_2 = " World\0";
    char *str_obtained_2 = my_strncat(str_input_1_2, str_input_3_2, 3);
    char *str_expected_2 = strncat(str_input_2_2, str_input_3_2, 3);

    cr_assert_str_eq(str_obtained_2, str_expected_2);
}

Test(my_strncat, concatenate_two_string_3)
{
    char *str_input_1_3 = strdup("Hello\0\0");
    char *str_input_2_3 = strdup("Hello\0\0");
    char const *str_input_3_3 = "\0";
    char *str_obtained_3 = my_strncat(str_input_1_3, str_input_3_3, 0);
    char *str_expected_3 = strncat(str_input_2_3, str_input_3_3, 0);

    cr_assert_str_eq(str_obtained_3, str_expected_3);
}

Test(my_strncat, concatenate_two_string_4)
{
    char *str_input_1_4 = strdup("Hello\0     \0");
    char *str_input_2_4 = strdup("Hello\0     \0");
    char const *str_input_3_4 = " World\0";
    char *str_obtained_4 = my_strncat(str_input_1_4, str_input_3_4, 10);
    char *str_expected_4 = strncat(str_input_2_4, str_input_3_4, 10);

    cr_assert_str_eq(str_obtained_4, str_expected_4);
}
