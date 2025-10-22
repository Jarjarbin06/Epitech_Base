/*
** EPITECH PROJECT, 2025
** test_my_compute_square_root.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_compute_square_root, get_square_root_1)
{
    int int_obtained_1 = my_compute_square_root(16);
    int int_expected_1 = 4;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_compute_square_root, get_square_root_2)
{
    int int_obtained_2 = my_compute_square_root(1);
    int int_expected_2 = 1;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_compute_square_root, get_square_root_3)
{
    int int_obtained_3 = my_compute_square_root(0);
    int int_expected_3 = 0;

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_compute_square_root, get_square_root_4)
{
    int int_obtained_4 = my_compute_square_root(-1);
    int int_expected_4 = 0;

    cr_assert_eq(int_obtained_4, int_expected_4);
}
