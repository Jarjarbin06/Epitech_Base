/*
** EPITECH PROJECT, 2025
** test_my_is_prime.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_sort_int_array, sort_array_of_int_1)
{
    int int_arr_obtained_1[] = {7, 65, 3, 9, 76, 4, 786, 765, 63, 28, 0};
    int int_arr_expected_1[] = {0, 3, 4, 7, 9, 28, 63, 65, 76, 765, 786};

    my_sort_int_array(int_arr_obtained_1, 11);
    for (int idx = 0; idx < 11; idx++)
        cr_assert_eq(int_arr_obtained_1[idx], int_arr_expected_1[idx]);
}

Test(my_sort_int_array, sort_array_of_int_2)
{
    int int_arr_obtained_2[] = {0, 3, 4, 7, 9, 28, 63, 65, 76, 765, 786};
    int int_arr_expected_2[] = {0, 3, 4, 7, 9, 28, 63, 65, 76, 765, 786};

    my_sort_int_array(int_arr_obtained_2, 11);
    for (int idx = 0; idx < 11; idx++)
        cr_assert_eq(int_arr_obtained_2[idx], int_arr_expected_2[idx]);
}

Test(my_sort_int_array, sort_array_of_int_3)
{
    int int_arr_obtained_3[] = {0};
    int int_arr_expected_3[] = {0};

    my_sort_int_array(int_arr_obtained_3, 1);
    for (int idx = 0; idx < 1; idx++)
        cr_assert_eq(int_arr_obtained_3[idx], int_arr_expected_3[idx]);
}

Test(my_sort_int_array, sort_array_of_int_4)
{
    int int_arr_obtained_4[] = {};
    int int_arr_expected_4[] = {};

    my_sort_int_array(int_arr_obtained_4, 0);
    for (int idx = 0; idx < 0; idx++)
        cr_assert_eq(int_arr_obtained_4[idx], int_arr_expected_4[idx]);
}
