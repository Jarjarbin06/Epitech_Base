/*
** EPITECH PROJECT, 2025
** test_function.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_find_prime_sup, find_first_superior_prime_1)
{
    int int_obtained_1 = my_find_prime_sup(1);
    int int_expected_1 = 2;

    cr_assert_eq(int_obtained_1, int_expected_1);
}

Test(my_find_prime_sup, find_first_superior_prime_2)
{
    int int_obtained_2 = my_find_prime_sup(0);
    int int_expected_2 = 2;

    cr_assert_eq(int_obtained_2, int_expected_2);
}

Test(my_find_prime_sup, find_first_superior_prime_3)
{
    int int_obtained_3 = my_find_prime_sup(-1);
    int int_expected_3 = 2;

    cr_assert_eq(int_obtained_3, int_expected_3);
}

Test(my_find_prime_sup, find_first_superior_prime_4)
{
    int int_obtained_4 = my_find_prime_sup(20);
    int int_expected_4 = 23;

    cr_assert_eq(int_obtained_4, int_expected_4);
}
