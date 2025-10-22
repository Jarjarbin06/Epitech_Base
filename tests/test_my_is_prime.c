/*
** EPITECH PROJECT, 2025
** test_my_is_prime.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_is_prime, check_nbr_is_prime_1)
{
    int int_obtained_1 = my_is_prime(-1);
    int int_expected_1 = 0;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_is_prime, check_nbr_is_prime_2)
{
    int int_obtained_2 = my_is_prime(0);
    int int_expected_2 = 0;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_is_prime, check_nbr_is_prime_3)
{
    int int_obtained_3 = my_is_prime(2);
    int int_expected_3 = 1;

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_is_prime, check_nbr_is_prime_4)
{
    int int_obtained_4 = my_is_prime(199);
    int int_expected_4 = 1;

    cr_assert_eq(int_obtained_4, int_expected_4);
}

Test(my_is_prime, check_nbr_is_prime_5)
{
    int int_obtained_5 = my_is_prime(4);
    int int_expected_5 = 0;

    cr_assert_eq(int_obtained_5, int_expected_5);
}
