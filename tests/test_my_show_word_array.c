/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_show_word_array, show_an_array_1)
{
    char const *str_input_1[] = {"Hello", "World", 0};
    int int_obtained_1 = my_show_word_array(str_input_1);
    int int_expected_1 = 0;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_show_word_array, show_an_array_2)
{
    char const *str_input_2[] = {"Hello", 0};
    int int_obtained_2 = my_show_word_array(str_input_2);
    int int_expected_2 = 0;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_show_word_array, show_an_array_3)
{
    char const *str_input_3[] = {0};
    int int_obtained_3 = my_show_word_array(str_input_3);
    int int_expected_3 = 0;

    cr_assert_eq(int_obtained_3, int_expected_3);
}
