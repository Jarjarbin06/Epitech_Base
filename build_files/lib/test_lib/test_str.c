/*
** EPITECH PROJECT, 2025
** test_printf_basic.c
** File description:
** None
*/

#include "test.h"

// test_start //
Test(test_start, test_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test start\n");
}

// my_getnbr //
Test(my_getnbr, test_my_getnbr_num)
{
    cr_assert_eq(my_getnbr("123"), 123);
}

Test(my_getnbr, test_my_getnbr_alpha)
{
    cr_assert_eq(my_getnbr("abc"), 0);
}

Test(my_getnbr, test_my_getnbr_num_alpha)
{
    cr_assert_eq(my_getnbr("123abc"), 123);
}

Test(my_getnbr, test_my_getnbr_alpha_num)
{
    cr_assert_eq(my_getnbr("abc123"), 0);
}

// my_put_nbr //
Test(my_put_nbr, test_my_put_nbr_positive, .init = redirect_all_std)
{
    my_put_nbr(123);
    cr_assert_stdout_eq_str("123");
}

Test(my_put_nbr, test_my_put_nbr_null, .init = redirect_all_std)
{
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, test_my_put_nbr_negative, .init = redirect_all_std)
{
    my_put_nbr(-123);
    cr_assert_stdout_eq_str("-123");
}

// my_putchar //

Test(my_putchar, test_my_putchar, .init = redirect_all_std)
{
    my_putchar('0');
    cr_assert_stdout_eq_str("0");
}
