/*
** EPITECH PROJECT, 2025
** test_strcmp.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_strcmp, compare_two_strings_1)
{
    char *str_input_1_1 = "Hello";
    char *str_input_2_1 = "Hello";
    int int_obtained_1 = (my_strcmp(str_input_1_1, str_input_2_1) == 0);
    int int_expected_1 = (strcmp(str_input_1_1, str_input_2_1) == 0);

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_strcmp, compare_two_strings_2)
{
    char *str_input_1_2 = "Hello";
    char *str_input_2_2 = "Helloo";
    int int_obtained_2 = (my_strcmp(str_input_1_2, str_input_2_2) < 0);
    int int_expected_2 = (strcmp(str_input_1_2, str_input_2_2) < 0);

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_strcmp, compare_two_strings_3)
{
    char *str_input_1_3 = "Helloo";
    char *str_input_2_3 = "Hello";
    int int_obtained_3 = (my_strcmp(str_input_1_3, str_input_2_3) > 0);
    int int_expected_3 = (strcmp(str_input_1_3, str_input_2_3) > 0);

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_strcmp, compare_two_strings_4)
{
    char *str_input_1_4 = "Hello";
    char *str_input_2_4 = "Helle";
    int int_obtained_4 = (my_strcmp(str_input_1_4, str_input_2_4) > 0);
    int int_expected_4 = (strcmp(str_input_1_4, str_input_2_4) > 0);

    cr_assert_eq(int_obtained_4, int_expected_4);
}
