/*
** EPITECH PROJECT, 2025
** test_my_is_prime.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "../include/my.h"

Test(my_str_to_word_array, put_a_string_in_an_array_1)
{
    char *str_input_1 = "Hello World\0";
    char **str_arr_obtained_1;
    char *str_arr_expected_1[] = {"Hello", "World", 0};

    str_arr_obtained_1 = my_str_to_word_array(str_input_1);
    for (int idx = 0; str_arr_obtained_1[idx] != 0; idx++)
        cr_assert_str_eq(str_arr_obtained_1[idx], str_arr_expected_1[idx]);
    free(str_arr_obtained_1);
}

Test(my_str_to_word_array, put_a_string_in_an_array_2)
{
    char *str_input_2 = "Hello-World\0";
    char **str_arr_obtained_2;
    char *str_arr_expected_2[] = {"Hello", "World", 0};

    str_arr_obtained_2 = my_str_to_word_array(str_input_2);
    for (int idx = 0; str_arr_obtained_2[idx] != 0; idx++)
        cr_assert_str_eq(str_arr_obtained_2[idx], str_arr_expected_2[idx]);
    free(str_arr_obtained_2);
}

Test(my_str_to_word_array, put_a_string_in_an_array_3)
{
    char *str_input_3 = "Hello\0";
    char **str_arr_obtained_3;
    char *str_arr_expected_3[] = {"Hello", 0};

    str_arr_obtained_3 = my_str_to_word_array(str_input_3);
    for (int idx = 0; str_arr_obtained_3[idx] != 0; idx++)
        cr_assert_str_eq(str_arr_obtained_3[idx], str_arr_expected_3[idx]);
    free(str_arr_obtained_3);
}

Test(my_str_to_word_array, put_a_string_in_an_array_4)
{
    char *str_input_4 = "\0";
    char **str_arr_obtained_4;
    char *str_arr_expected_4[] = {0};

    str_arr_obtained_4 = my_str_to_word_array(str_input_4);
    for (int idx = 0; str_arr_obtained_4[idx] != 0; idx++)
        cr_assert_str_eq(str_arr_obtained_4[idx], str_arr_expected_4[idx]);
    free(str_arr_obtained_4);
}

Test(my_str_to_word_array, put_a_string_in_an_array_5)
{
    char *str_input_5 = "Hello--World\0";
    char **str_arr_obtained_5;
    char *str_arr_expected_5[] = {"Hello", "World", 0};

    str_arr_obtained_5 = my_str_to_word_array(str_input_5);
    for (int idx = 0; str_arr_obtained_5[idx] != 0; idx++)
        cr_assert_str_eq(str_arr_obtained_5[idx], str_arr_expected_5[idx]);
    free(str_arr_obtained_5);
}
