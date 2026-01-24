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

// my_putstr //
Test(my_putstr, test_my_putstr_basic, .init = redirect_all_std)
{
    cr_assert(!my_putstr("Hello World"));
    cr_assert_stdout_eq_str("Hello World");
}

Test(my_putstr, test_my_putstr_empty, .init = redirect_all_std)
{
    cr_assert(!my_putstr(""));
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, test_my_putstr_invalid, .init = redirect_all_std)
{
    cr_assert(my_putstr(NULL));
    cr_assert_stdout_eq_str("");
}

// my_revstr //
Test(my_revstr, test_my_revstr_basic)
{
    char str[12] = "Hello World";
    cr_assert(my_revstr(str));
    cr_assert_str_eq(str, "dlroW olleH");
}

Test(my_revstr, test_my_revstr_empty)
{
    char str[12] = "";
    cr_assert(my_revstr(str));
    cr_assert_str_eq(str, "");
}

Test(my_revstr, test_my_revstr_invalid)
{
    cr_assert(!my_revstr(NULL));
}

// my_str_isalpha //
Test(my_str_isalpha, my_str_isalpha_valid)
{
    cr_assert(my_str_isalpha("abcABC"));
}

Test(my_str_isalpha, my_str_isalpha_invalid_1)
{
    cr_assert(!my_str_isalpha("123abc"));
}

Test(my_str_isalpha, my_str_isalpha_invalid_2)
{
    cr_assert(my_str_isalpha(""));
}

// my_str_islower //
Test(my_str_islower, my_str_islower_valid)
{
    cr_assert(my_str_islower("abc"));
}

Test(my_str_islower, my_str_islower_invalid_1)
{
    cr_assert(!my_str_islower("abcABC"));
}

Test(my_str_islower, my_str_islower_invalid_2)
{
    cr_assert(!my_str_islower("123abc"));
}

Test(my_str_islower, my_str_islower_invalid_3)
{
    cr_assert(my_str_islower(""));
}

// my_str_isnum //
Test(my_str_isnum, my_str_isnum_valid)
{
    cr_assert(my_str_isnum("123"));
}

Test(my_str_isnum, my_str_isnum_invalid_1)
{
    cr_assert(!my_str_isnum("123abc"));
}

Test(my_str_isnum, my_str_isnum_invalid_2)
{
    cr_assert(my_str_isnum(""));
}

// my_str_isprintable //
Test(my_str_isprintable, my_str_isprintable_valid)
{
    cr_assert(my_str_isprintable("+-123abc"));
}

Test(my_str_isprintable, my_str_isprintable_invalid_1)
{
    cr_assert(!my_str_isprintable("\n"));
}

Test(my_str_isprintable, my_str_isprintable_invalid_2)
{
    cr_assert(my_str_isprintable(""));
}

// my_str_isupper //
Test(my_str_isupper, my_str_isupper_valid)
{
    cr_assert(my_str_isupper("ABC"));
}

Test(my_str_isupper, my_str_isupper_invalid_1)
{
    cr_assert(!my_str_isupper("abcABC"));
}

Test(my_str_isupper, my_str_isupper_invalid_2)
{
    cr_assert(!my_str_isupper("123abc"));
}

Test(my_str_isupper, my_str_isupper_invalid_3)
{
    cr_assert(my_str_isupper(""));
}

//my_str_to_word_array //

// my_strcapitalize //
Test(my_strcapitalize, my_strcapitalize_valid)
{
    char str[] = "hello world+-123";
    cr_assert_str_eq(my_strcapitalize(str), "Hello World+-123");
}

Test(my_strcapitalize, my_strcapitalize_no_action)
{
    char str[] = "Hello World+-123";
    cr_assert_str_eq(my_strcapitalize(str), "Hello World+-123");
}

Test(my_strcapitalize, my_strcapitalize_full_action)
{
    char str[] = "hELLO wORLD+-123";
    cr_assert_str_eq(my_strcapitalize(str), "Hello World+-123");
}

Test(my_strcapitalize, my_strcapitalize_invalid)
{
    cr_assert(!my_strcapitalize(NULL));
}
