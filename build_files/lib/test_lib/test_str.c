/*
** EPITECH PROJECT, 2025
** test_lib - test_str.c
** File description:
** None
*/

#include "test.h"

// test_start //
Test(test_start, test_str_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test start\n");
}

Test(str_exist, test_str_exist)
{
    str_exist();
    cr_assert(1);
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
    char str[] = "Hello World";

    cr_assert(my_revstr(str));
    cr_assert_str_eq(str, "dlroW olleH");
}

Test(my_revstr, test_my_revstr_empty)
{
    char str[] = "";

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

// my_strcat //
Test(my_strcat, my_strcat_valid)
{
    cr_assert_str_eq(my_strcat("Hello ", "World"), "Hello World");
}

Test(my_strcat, my_strcat_empty_1)
{
    cr_assert_str_eq(my_strcat("", "World"), "World");
}

Test(my_strcat, my_strcat_empty_2)
{
    cr_assert_str_eq(my_strcat("Hello ", ""), "Hello ");
}

Test(my_strcat, my_strcat_empty_3)
{
    cr_assert_str_eq(my_strcat("", ""), "");
}

Test(my_strcat, my_strcat_invalid_1)
{
    cr_assert(!my_strcat(NULL, "World"));
}

Test(my_strcat, my_strcat_invalid_2)
{
    cr_assert(!my_strcat("Hello ", NULL));
}

Test(my_strcat, my_strcat_invalid_3)
{
    cr_assert(!my_strcat(NULL, NULL));
}

// my_strcmp //
Test(my_strcmp, my_strcmp_true)
{
    cr_assert_eq(my_strcmp("Hello World", "Hello World"), 0);
}

Test(my_strcmp, my_strcmp_shorter)
{
    cr_assert_eq(my_strcmp("Hello World", "Hello Worl"), 1);
}

Test(my_strcmp, my_strcmp_longer)
{
    cr_assert_eq(my_strcmp("Hello Worl", "Hello World"), -1);
}

Test(my_strcmp, my_strcmp_different)
{
    cr_assert_eq(my_strcmp("Hello World", "Hallo World"), 1);
}

Test(my_strcmp, my_strcmp_invalid_1)
{
    cr_assert_eq(my_strcmp(NULL, "Hello World"), 1);
}

Test(my_strcmp, my_strcmp_invalid_2)
{
    cr_assert_eq(my_strcmp("Hello World", NULL), 1);
}

Test(my_strcmp, my_strcmp_invalid_3)
{
    cr_assert_eq(my_strcmp(NULL, NULL), 1);
}

// my_strcpy //
Test(my_strcpy, my_strcpy_valid)
{
    char *dest = (char *)malloc(sizeof(char) * 12);

    dest = my_strcpy(dest, "Hello World");
    cr_assert_str_eq(dest, "Hello World");
    free(dest);
}

Test(my_strcpy, my_strcpy_empty)
{
    char *dest = (char *)malloc(sizeof(char) * 1);

    dest = my_strcpy(dest, "");
    cr_assert_str_eq(dest, "");
    free(dest);
}

Test(my_strcpy, my_strcpy_invalid_1)
{
    char *dest = (char *)malloc(sizeof(char) * 1);

    dest = my_strcpy(dest, NULL);
    cr_assert(!dest);
}

Test(my_strcpy, my_strcpy_invalid_2)
{
    char *dest = NULL;

    dest = my_strcpy(dest, "Hello World");
    cr_assert(!dest);
}

// my_strdup //
Test(my_strdup, my_strdup_valid)
{
    char *dest = my_strdup("Hello World");

    cr_assert_str_eq(dest, "Hello World");
    free(dest);
}

Test(my_strdup, my_strdup_empty)
{
    char *dest = my_strdup("");

    cr_assert_str_eq(dest, "");
    free(dest);
}

Test(my_strdup, my_strdup_invalid)
{
    char *dest = my_strdup(NULL);

    cr_assert(!dest);
}

// my_strlen //
Test(my_strlen, my_strlen_valid)
{
    cr_assert_eq(my_strlen("Hello World"), 11);
}

Test(my_strlen, my_strlen_empty)
{
    cr_assert_eq(my_strlen(""), 0);
}

Test(my_strlen, my_strlen_invalid)
{
    cr_assert_eq(my_strlen(NULL), 0);
}

// my_strlowcase //
Test(my_strlowcase, my_strlowcase_valid)
{
    char str[] = "Hello World+-123";

    cr_assert_str_eq(my_strlowcase(str), "hello world+-123");
}

Test(my_strlowcase, my_strlowcase_no_action)
{
    char str[] = "hello world+-123";

    cr_assert_str_eq(my_strlowcase(str), "hello world+-123");
}

Test(my_strlowcase, my_strlowcase_full_action)
{
    char str[] = "HELLO WORLD+-123";

    cr_assert_str_eq(my_strlowcase(str), "hello world+-123");
}

Test(my_strlowcase, my_strlowcase_invalid)
{
    cr_assert(!my_strlowcase(NULL));
}

// my_strstr //
Test(my_strstr, my_strstr_beggining)
{
    cr_assert_str_eq(my_strstr("Hello World", "Hello"), "Hello World");
}

Test(my_strstr, my_strstr_end)
{
    cr_assert_str_eq(my_strstr("Hello World", "World"), "World");
}

Test(my_strstr, my_strstr_not_found)
{
    cr_assert_str_eq(my_strstr("Hello World", "z"), "Hello World");
}

Test(my_strstr, my_strstr_invalid_1)
{
    cr_assert(!my_strstr("Hello World", NULL));
}

Test(my_strstr, my_strstr_invalid_2)
{
    cr_assert(!my_strstr(NULL, "Hello World"));
}

Test(my_strstr, my_strstr_invalid_3)
{
    cr_assert(!my_strstr(NULL, NULL));
}

// my_strupcase //
Test(my_strupcase, my_strupcase_valid)
{
    char str[] = "Hello World+-123";

    cr_assert_str_eq(my_strupcase(str), "HELLO WORLD+-123");
}

Test(my_strupcase, my_strupcase_no_action)
{
    char str[] = "HELLO WORLD+-123";

    cr_assert_str_eq(my_strupcase(str), "HELLO WORLD+-123");
}

Test(my_strupcase, my_strupcase_full_action)
{
    char str[] = "hello world+-123";

    cr_assert_str_eq(my_strupcase(str), "HELLO WORLD+-123");
}

Test(my_strupcase, my_strupcase_invalid)
{
    cr_assert(!my_strupcase(NULL));
}

// my_swap_char //
Test(my_swap_char, my_swap_char_valid)
{
    char c_1 = 'a';
    char c_2 = 'b';

    cr_assert_eq(c_1, 'a');
    cr_assert_eq(c_2, 'b');
    my_swap_char(&c_1, &c_2);
    cr_assert_eq(c_1, 'b');
    cr_assert_eq(c_2, 'a');
}

Test(my_swap_char, my_swap_char_invalid_1)
{
    char c_2 = 'b';

    cr_assert_eq(c_2, 'b');
    my_swap_char(NULL, &c_2);
    cr_assert_eq(c_2, 'b');
}

Test(my_swap_char, my_swap_char_invalid_2)
{
    char c_1 = 'a';

    cr_assert_eq(c_1, 'a');
    my_swap_char(&c_1, NULL);
    cr_assert_eq(c_1, 'a');
}

Test(my_swap_char, my_swap_char_invalid_3)
{
    my_swap_char(NULL, NULL);
    cr_assert(1);
}
