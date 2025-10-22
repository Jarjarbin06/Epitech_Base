/*
** EPITECH PROJECT, 2025
** test_my_strcat.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_strcat, concatenate_two_string_1)
{
    char *str_input_1_1 = strdup("Hello\0     \0");
    char *str_input_2_1 = strdup("Hello\0     \0");
    char const *str_input_3_1 = " World\0";
    char *str_obtained_1 = my_strcat(str_input_1_1, str_input_3_1);
    char *str_expected_1 = strcat(str_input_2_1, str_input_3_1);

    cr_assert_str_eq(str_obtained_1, str_expected_1);
}

Test(my_strcat, concatenate_two_string_2)
{
    char *str_input_1_2 = strdup("Hello\0\0");
    char *str_input_2_2 = strdup("Hello\0\0");
    char const *str_input_3_2 = "\0";
    char *str_obtained_2 = my_strcat(str_input_1_2, str_input_3_2);
    char *str_expected_2 = strcat(str_input_2_2, str_input_3_2);

    cr_assert_str_eq(str_obtained_2, str_expected_2);
}

Test(my_strcat, concatenate_two_string_3)
{
    char *str_input_1_3 = strdup("\0\0");
    char *str_input_2_3 = strdup("\0\0");
    char const *str_input_3_3 = "\0";
    char *str_obtained_3 = my_strcat(str_input_1_3, str_input_3_3);
    char *str_expected_3 = strcat(str_input_2_3, str_input_3_3);

    cr_assert_str_eq(str_obtained_3, str_expected_3);
}
