/*
** EPITECH PROJECT, 2025
** test_strncmp.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_strncmp, compare_two_strings_1)
{
    char *str_input_1_1 = "Hello";
    char *str_input_2_1 = "Hello";
    int int_obtained_1 = (my_strncmp(str_input_1_1, str_input_2_1, 5) == 0);
    int int_expected_1 = (strncmp(str_input_1_1, str_input_2_1, 5) == 0);

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_strncmp, compare_two_strings_2)
{
    char *str_input_1_2 = "Hello";
    char *str_input_2_2 = "Helloo";
    int int_obtained_2 = (my_strncmp(str_input_1_2, str_input_2_2, 5) < 0);
    int int_expected_2 = (strncmp(str_input_1_2, str_input_2_2, 5) < 0);

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_strncmp, compare_two_strings_3)
{
    char *str_input_1_3 = "Helloo";
    char *str_input_2_3 = "Hello";
    int int_obtained_3 = (my_strncmp(str_input_1_3, str_input_2_3, 5) > 0);
    int int_expected_3 = (strncmp(str_input_1_3, str_input_2_3, 5) > 0);

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_strncmp, compare_two_strings_4)
{
    char *str_input_1_4 = "Hello";
    char *str_input_2_4 = "Helle";
    int int_obtained_4 = (my_strncmp(str_input_1_4, str_input_2_4, 5) > 0);
    int int_expected_4 = (strncmp(str_input_1_4, str_input_2_4, 5) > 0);

    cr_assert_eq(int_obtained_4, int_expected_4);
}

Test(my_strncmp, compare_two_string_5)
{
    char *str_input_1_5 = "Hello";
    char *str_input_2_5 = "Hello";
    int int_obtained_5 = (my_strncmp(str_input_1_5, str_input_2_5, 3) == 0);
    int int_expected_5 = (strncmp(str_input_1_5, str_input_2_5, 3) == 0);

    cr_assert_eq(int_obtained_5, int_expected_5);
}

Test(my_strncmp, compare_two_string_6)
{
    char *str_input_1_6 = "Hello";
    char *str_input_2_6 = "Hello";
    int int_obtained_6 = (my_strncmp(str_input_1_6, str_input_2_6, 10) == 0);
    int int_expected_6 = (strncmp(str_input_1_6, str_input_2_6, 10) == 0);

    cr_assert_eq(int_obtained_6, int_expected_6);
}
