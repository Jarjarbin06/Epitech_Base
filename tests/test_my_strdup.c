/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_str_dup, allocate_and_copy_a_str_1)
{
    char const *str_input_1 = "Hello World!";
    char *str_obtained_1 = my_strdup(str_input_1);
    char *str_expected_1 = strdup(str_input_1);

    cr_assert_str_eq(str_obtained_1, str_expected_1);
    free(str_obtained_1);
    free(str_expected_1);
}

Test(my_str_dup, allocate_and_copy_a_str_2)
{
    char const *str_input_2 = "";
    char *str_obtained_2 = my_strdup(str_input_2);
    char *str_expected_2 = strdup(str_input_2);

    cr_assert_str_eq(str_obtained_2, str_expected_2);
    free(str_obtained_2);
    free(str_expected_2);
}
