/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_compute_power_rec, get_nbr_to_power_of_p_1)
{
    int int_obtained_1 = my_compute_power_rec(4, 2);
    int int_expected_1 = 16;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_compute_power_rec, get_nbr_to_power_of_p_2)
{
    int int_obtained_2 = my_compute_power_rec(4, 0);
    int int_expected_2 = 1;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_compute_power_rec, get_nbr_to_power_of_p_3)
{
    int int_obtained_3 = my_compute_power_rec(2, 8);
    int int_expected_3 = 256;

    cr_assert_eq(int_obtained_3, int_expected_3);
}
