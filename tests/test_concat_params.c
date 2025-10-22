/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(concat_params, concatenate_string_list_into_string_1)
{
    char *params_1[] = {"Arg1", "Arg2", "Arg3", "Arg4", 0};
    char *str_obtained_1 = concat_params(4, params_1);
    char *str_expected_1 = "Arg1\nArg2\nArg3\nArg4\0";

    cr_assert_str_eq(str_obtained_1, str_expected_1);
}

Test(concat_params, concatenate_string_list_into_string_2)
{
    char *params_2[] = {"Hello World", 0};
    char *str_obtained_2 = concat_params(1, params_2);
    char *str_expected_2 = "Hello World\0";

    cr_assert_str_eq(str_obtained_2, str_expected_2);
}

Test(concat_params, concatenate_string_list_into_string_3)
{
    char *params_3[] = {0};
    char *str_obtained_3 = concat_params(0, params_3);
    char *str_expected_3 = "";

    cr_assert_str_eq(str_obtained_3, str_expected_3);
}
